from pathlib import Path
from datetime import datetime, timezone
import json, hashlib, zipfile, shutil

root = Path(__file__).resolve().parent.parent
out = root / 'Exportacion'
attachment = Path('C:/Users/BALAMRUSH/.codex/attachments/2891075e-3303-49e7-b6ab-80f3d3cd0d43/Texto pegado.txt')
(out/'contexto'/'adjuntos').mkdir(parents=True, exist_ok=True)
shutil.copy2(attachment, out/'contexto'/'adjuntos'/'Prompt_original_Brumaferal.txt')

transcript=['# Contexto conversacional recuperado\n', 'Consulte ESTADO_COMPLETO.md para los límites de recuperación. Se preservan mensajes históricos, incluidas sus correcciones posteriores.\n']
for ident in ['6abf85fc-3710-83e8-9851-a6ea516c71ba','01a0fc33-ca5e-7973-9ccc-2707906632d2','01a11e2b-61c0-7852-84fb-9095a28e0bba']:
    pages=json.loads((out/'contexto'/f'{ident}.json').read_text(encoding='utf-8'))
    transcript.append('\n## '+pages[0]['thread']['title']+'\n\nID: '+ident+'\n')
    turns=[t for p in pages for t in p.get('turns',[])]
    for t in reversed(turns):
        transcript.append('\n### Turno '+t['id']+'\n')
        for item in t.get('items',[]):
            if item.get('type')=='userMessage':
                transcript.append('\n**Usuario**\n\n'+'\n'.join(x.get('text', '[Contenido no textual: '+x.get('type','desconocido')+']') for x in item.get('content',[])))
            elif item.get('type')=='agentMessage':
                transcript.append('\n**Asistente ('+item.get('phase','mensaje')+')**\n\n'+item.get('text',''))
    transcript.append('\nLas salidas técnicas recuperadas permanecen en el JSON asociado.\n')
(out/'CONTEXTO_CONVERSACIONES.md').write_text('\n'.join(transcript),encoding='utf-8')

docs=['# Documentos originales íntegros\n']
code=['# Código, configuración y scripts actuales\n', 'Anexo automático de los archivos originales. No implica que todas las funciones estén verificadas.\n']
for project in ['Brumaferal','Riftbound']:
    for p in sorted((root/project).rglob('*')):
        if not p.is_file(): continue
        rel=p.relative_to(root).as_posix()
        parts=p.relative_to(root/project).parts
        if p.suffix.lower()=='.md' and '.git' not in parts:
            docs.extend(['\n## '+rel+'\n',p.read_text(encoding='utf-8-sig',errors='replace')])
        if (parts[0] in ['Source','Config'] or len(parts)==1 or (parts[0]=='Tools' and p.suffix=='.py')) and p.suffix.lower() in ['.h','.cpp','.cs','.ini','.json','.uproject','.ps1','.cmd','.py']:
            code.extend(['\n## '+rel+'\n','````text\n'+p.read_text(encoding='utf-8-sig',errors='replace')+'\n````'])
(out/'DOCUMENTACION_ORIGINAL.md').write_text('\n'.join(docs),encoding='utf-8')
(out/'FUENTES_Y_CONFIGURACION.md').write_text('\n'.join(code),encoding='utf-8')

zip_path=root/'Videojuego_Contexto_y_Archivos_2026-10-08.zip'
if zip_path.exists(): raise RuntimeError('El ZIP ya existe; no se sobrescribe.')
files=[]; dirs=[]
for folder in ['Brumaferal','Riftbound','sources']:
    base=root/folder
    dirs.append((base,folder+'/'))
    for p in sorted(base.rglob('*')):
        pair=(p,p.relative_to(root).as_posix())
        if p.is_symlink(): raise RuntimeError('Enlace requiere revisión: '+str(p))
        if p.is_file(): files.append(pair)
        elif p.is_dir(): dirs.append((p,pair[1]+'/'))
files.append((root/'AGENTS.md','AGENTS.md'))
for p in sorted(out.rglob('*')):
    if p.is_file(): files.append((p,'Documentacion/'+p.relative_to(out).as_posix()))
manifest={'captura_inicio_utc':datetime.now(timezone.utc).isoformat(),'archivos':[],'carpetas':[n for _,n in dirs], 'nota':'SHA-256 de bytes archivados. Los registros de una aplicación abierta pueden cambiar durante la captura.'}
total=sum(p.stat().st_size for p,_ in files)
print(json.dumps({'fase':'inicio','archivos':len(files),'bytes':total}),flush=True)
done=0
with zipfile.ZipFile(zip_path,'w',compression=zipfile.ZIP_DEFLATED,compresslevel=5,allowZip64=True) as z:
    for p,n in dirs: z.writestr(n,b'')
    for idx,(p,n) in enumerate(files):
        before=p.stat(); h=hashlib.sha256(); count=0
        info=zipfile.ZipInfo.from_file(p,n);info.compress_type=zipfile.ZIP_DEFLATED;info._compresslevel=5
        with p.open('rb') as src,z.open(info,'w',force_zip64=True) as dst:
            remaining=before.st_size
            while remaining:
                chunk=src.read(min(4*1024*1024,remaining))
                if not chunk: raise RuntimeError('Archivo se redujo durante lectura: '+n)
                dst.write(chunk);h.update(chunk);count+=len(chunk);remaining-=len(chunk)
        after=p.stat()
        manifest['archivos'].append({'ruta':n,'bytes':count,'sha256':h.hexdigest(),'modificacion_utc':datetime.fromtimestamp(before.st_mtime,timezone.utc).isoformat(),'cambio_durante_lectura':before.st_size!=after.st_size or before.st_mtime_ns!=after.st_mtime_ns})
        done+=count
        if idx%20==0 or count>100*1024*1024: print(json.dumps({'fase':'compresion','archivo':n,'completados':idx+1,'total':len(files),'bytes_leidos':done}),flush=True)
    manifest['captura_fin_utc']=datetime.now(timezone.utc).isoformat()
    payload=json.dumps(manifest,ensure_ascii=False,indent=2)
    z.writestr('MANIFIESTO.json',payload.encode('utf-8'))
(out/'MANIFIESTO.json').write_text(payload,encoding='utf-8')
print(json.dumps({'fase':'verificando','zip_bytes':zip_path.stat().st_size}),flush=True)
with zipfile.ZipFile(zip_path) as z:
    names=z.namelist()
    assert len(names)==len(set(names)), 'Entradas duplicadas'
    for idx,item in enumerate(manifest['archivos']):
        h=hashlib.sha256();count=0
        with z.open(item['ruta']) as f:
            while chunk:=f.read(4*1024*1024): h.update(chunk);count+=len(chunk)
        assert count==item['bytes'] and h.hexdigest()==item['sha256'],item['ruta']
        if idx%60==0: print(json.dumps({'fase':'verificando','completados':idx+1,'total':len(files)}),flush=True)
    assert json.loads(z.read('MANIFIESTO.json'))==manifest
h=hashlib.sha256()
with zip_path.open('rb') as f:
    while chunk:=f.read(4*1024*1024): h.update(chunk)
checksum=h.hexdigest()
zip_path.with_suffix('.zip.sha256').write_text(checksum+'  '+zip_path.name+'\n',encoding='utf-8')
result={'resultado':'VERIFICADO','zip':str(zip_path),'zip_bytes':zip_path.stat().st_size,'archivos':len(files),'carpetas':len(dirs),'bytes_originales':total,'sha256':checksum,'cambiaron_durante_lectura':[x['ruta'] for x in manifest['archivos'] if x['cambio_durante_lectura']]}
(out/'VERIFICACION.json').write_text(json.dumps(result,ensure_ascii=False,indent=2),encoding='utf-8')
print(json.dumps(result,ensure_ascii=False),flush=True)
