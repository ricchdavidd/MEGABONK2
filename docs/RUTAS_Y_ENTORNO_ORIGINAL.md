# Rutas y entorno del PC original

> **Importante:** este repositorio contiene **todo el estado del proyecto tal como estaba en el PC del autor** (Ricardo David, usuario de Windows `BALAMRUSH`). Eso incluye binarios compilados, intermedios de compilación, cachés, configuraciones generadas, registros, capturas y partidas guardadas. Se subió así a propósito, para que el equipo tenga el contexto completo.
>
> Muchos de esos archivos llevan **rutas absolutas de ese PC**. **Son rutas de otra máquina, no tienen que existir en la tuya** y no hay que crearlas.

## Rutas que vas a encontrar

| Ruta en los archivos | Qué era | Dónde aparece |
|---|---|---|
| `C:\Users\BALAMRUSH\.codex\.chatgpt-projects\g-p-6abf85231014819196482d9baf409458\Brumaferal` (y `\Riftbound`) | **Ubicación original** de los proyectos, cuando se crearon con ChatGPT/Codex (2–3 oct 2026) | `Intermediate/`, `Saved/Logs/`, `Brumaferal/Tools/*.log`, `Documentacion/` |
| `C:\Users\BALAMRUSH\OneDrive\Documentos\PROJECTS\MEGABONK2` | Ubicación **posterior** (desde el 8 oct 2026), desde donde se subió este repositorio | Registros recientes y documentación |
| `C:\Users\BALAMRUSH\.codex\attachments\...` | Adjuntos de las conversaciones (por ejemplo, el prompt maestro) | `Documentacion/` (la copia está en `Documentacion/contexto/adjuntos/`) |
| `C:\Users\BALAMRUSH\AppData\Local\...` | Logs de UnrealBuildTool y cachés de usuario de Unreal | `Intermediate/`, registros de compilación |
| `C:\Users\BALAMRUSH\AppData\LocalLow\Ved\Megabonk` | Carpeta de datos esperada del juego de referencia MEGABONK | `Documentacion/` (análisis de la instalación) |
| `C:\Program Files (x86)\Steam\steamapps\common\Megabonk` | Instalación de MEGABONK que se analizó en modo de solo lectura | `Documentacion/` |
| `C:\Program Files\Epic Games\UE_5.8` | Instalación de Unreal Engine 5.8.2 | `Jugar.cmd`, `JugarSolo.cmd`, `CrearPartida.cmd`, `Launch.ps1`, `Intermediate/`, registros |
| `C:\Program Files\Microsoft Visual Studio\18\Community\VC\Tools\MSVC\14.51.36231` | Compilador usado: VS 2026 Community, MSVC 14.51 | `Intermediate/`, `Tools/build.log` |
| `C:\Program Files (x86)\Windows Kits\10` | Windows SDK 10.0.26100.0 | `Intermediate/` |

## Entorno original

| Elemento | Valor |
|---|---|
| Sistema | Windows 11 x64 |
| CPU / GPU | AMD Ryzen 7 7700X (8 núcleos / 16 hilos) / NVIDIA RTX 4070 Ti SUPER |
| Motor | Unreal Engine 5.8.2 en `C:\Program Files\Epic Games\UE_5.8` |
| Compilador | Visual Studio 2026 Community, MSVC 14.51.36260 |
| SDK | Windows 10.0.26100.0 |
| Resolución de pruebas | 1440 × 900, DX11 |

## Qué significa para ti

- **El código fuente (`Source/`), la configuración (`Config/`) y los recursos (`Content/`) no dependen de esas rutas.** Funcionan en cualquier ubicación.
- **Los lanzadores `.cmd` buscan el proyecto en su propia carpeta** (`%~dp0`), pero buscan Unreal en `C:\Program Files\Epic Games\UE_5.8`. Si tu motor está en otra ruta, edita la ruta en tu copia local, sin hacer commit.
- **`Binaries/`** tiene las DLL compiladas en ese PC. Pueden cargar directamente si tu Unreal es exactamente la versión 5.8.2. Si Unreal pide recompilar, acepta: necesitas Visual Studio con C++.
- **`Intermediate/` y `DerivedDataCache/`** son cachés con rutas del PC original. Si dan errores raros al compilar, puedes borrarlos en tu copia local y Unreal los regenerará. **No hagas commit de ese borrado** sin acordarlo con el equipo.
- **Faltan los `.pch`** (`Intermediate/.../SharedPCH...h.pch`, unos 2,6 GB cada uno). Superan el límite de GitHub incluso con Git LFS, así que son los **únicos archivos excluidos**. Se regeneran solos en la primera compilación.
- **`Saved/`** contiene logs, configuración del editor, capturas y `RiftboundProfile.sav` (partida guardada de Riftbound). Son evidencia histórica: los logs registran pruebas hechas en el PC original, no en el tuyo.
- **`MANIFIESTO.json`** lista los SHA-256 de todos los archivos de la exportación original. Sirve para comprobar que nada cambió.

## Archivos grandes (Git LFS)

Los archivos de más de 50 MB (`*.pdb`, el `.obj` del PCH compartido y `CachedAssetRegistry/*.bin`) se suben con **Git LFS**. Después de clonar:

```powershell
git lfs install
git lfs pull
```

Si clonas sin LFS, esos archivos quedan como pequeños punteros de texto. No afecta a jugar ni a compilar: Unreal los regenera.
