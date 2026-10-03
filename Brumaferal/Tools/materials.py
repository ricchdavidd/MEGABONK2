import unreal, os, random, struct, zlib
tools=unreal.AssetToolsHelpers.get_asset_tools()
noise_path=os.path.join(unreal.Paths.project_dir(),'Tools','facet_noise.png')
rng=random.Random(831)
rows=[]
for y in range(32):
    row=bytearray([0])
    for x in range(32):
        v=rng.choice([185,205,220,235,250,250,250])
        row.extend([v,v,v])
    rows.append(bytes(row))
def chunk(name,data):
    return struct.pack('!I',len(data))+name+data+struct.pack('!I',zlib.crc32(name+data)&0xffffffff)
with open(noise_path,'wb') as out:
    out.write(b'\x89PNG\r\n\x1a\n'+chunk(b'IHDR',struct.pack('!2I5B',32,32,8,2,0,0,0))+chunk(b'IDAT',zlib.compress(b''.join(rows)))+chunk(b'IEND',b''))
texture=unreal.load_asset('/Game/Art/facet_noise')
if not texture:
    task=unreal.AssetImportTask()
    task.set_editor_property('filename',noise_path)
    task.set_editor_property('destination_path','/Game/Art')
    task.set_editor_property('automated',True)
    task.set_editor_property('save',True)
    tools.import_asset_tasks([task])
    texture=unreal.load_asset('/Game/Art/facet_noise')
texture.set_editor_property('filter',unreal.TextureFilter.TF_NEAREST)
unreal.EditorAssetLibrary.save_loaded_asset(texture)
for name, unlit in [('M_Facet',False),('M_Glow',True)]:
    path='/Game/Art/'+name
    mat=unreal.load_asset(path)
    if not mat:
        mat=tools.create_asset(name,'/Game/Art',unreal.Material,unreal.MaterialFactoryNew())
    unreal.MaterialEditingLibrary.delete_all_material_expressions(mat)
    color=unreal.MaterialEditingLibrary.create_material_expression(mat,unreal.MaterialExpressionVertexColor)
    if unlit:
        mat.set_editor_property('shading_model',unreal.MaterialShadingModel.MSM_UNLIT)
        assert unreal.MaterialEditingLibrary.connect_material_property(color,'',unreal.MaterialProperty.MP_EMISSIVE_COLOR), name
    else:
        mat.set_editor_property('shading_model',unreal.MaterialShadingModel.MSM_DEFAULT_LIT)
        position=unreal.MaterialEditingLibrary.create_material_expression(mat,unreal.MaterialExpressionWorldPosition)
        scale=unreal.MaterialEditingLibrary.create_material_expression(mat,unreal.MaterialExpressionMultiply)
        scale.set_editor_property('const_b',0.002)
        assert unreal.MaterialEditingLibrary.connect_material_expressions(position,'',scale,'A')
        uv=unreal.MaterialEditingLibrary.create_material_expression(mat,unreal.MaterialExpressionComponentMask)
        uv.set_editor_property('r',True)
        uv.set_editor_property('g',True)
        uv.set_editor_property('b',False)
        uv.set_editor_property('a',False)
        assert unreal.MaterialEditingLibrary.connect_material_expressions(scale,'',uv,'')
        sample=unreal.MaterialEditingLibrary.create_material_expression(mat,unreal.MaterialExpressionTextureSample)
        sample.set_editor_property('texture',texture)
        assert unreal.MaterialEditingLibrary.connect_material_expressions(uv,'',sample,'UVs')
        pigment=unreal.MaterialEditingLibrary.create_material_expression(mat,unreal.MaterialExpressionMultiply)
        assert unreal.MaterialEditingLibrary.connect_material_expressions(color,'',pigment,'A')
        assert unreal.MaterialEditingLibrary.connect_material_expressions(sample,'',pigment,'B')
        assert unreal.MaterialEditingLibrary.connect_material_property(pigment,'',unreal.MaterialProperty.MP_BASE_COLOR), name
        ambient=unreal.MaterialEditingLibrary.create_material_expression(mat,unreal.MaterialExpressionMultiply)
        ambient.set_editor_property('const_b',0.45)
        assert unreal.MaterialEditingLibrary.connect_material_expressions(pigment,'',ambient,'A')
        assert unreal.MaterialEditingLibrary.connect_material_property(ambient,'',unreal.MaterialProperty.MP_EMISSIVE_COLOR)
        rough=unreal.MaterialEditingLibrary.create_material_expression(mat,unreal.MaterialExpressionConstant)
        rough.set_editor_property('r',0.9)
        assert unreal.MaterialEditingLibrary.connect_material_property(rough,'',unreal.MaterialProperty.MP_ROUGHNESS)
    unreal.MaterialEditingLibrary.recompile_material(mat)
    unreal.EditorAssetLibrary.save_loaded_asset(mat)
unreal.log('BRUMA_MATERIALS_READY')
