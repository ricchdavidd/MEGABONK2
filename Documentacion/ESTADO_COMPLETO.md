# Brumaferal y Riftbound — entrega de contexto y estado

Fecha de preparación: 8 de octubre de 2026, zona America/Tijuana.

## Qué contiene esta entrega

Esta es una copia del estado local de los dos proyectos del espacio «Creacion Videojuego». Brumaferal es el proyecto vigente; Riftbound se conserva como antecedente. Se incluyen todos los archivos encontrados bajo ambas carpetas, incluidos archivos ocultos, repositorio Git donde existe, código fuente, recursos, configuraciones, scripts, módulos compilados, símbolos de depuración, intermedios, cachés, registros, capturas y partidas guardadas. No se han filtrado los archivos por .gitignore.

El ZIP es un respaldo de desarrollo, no un instalador ni una versión independiente lista para Steam. Unreal Engine, Visual Studio, Windows SDK y la instalación comercial de MEGABONK están fuera del proyecto y no se incluyen. Tampoco se incluye el estado de memoria de la ventana de juego que estaba abierta. Los registros pueden continuar cambiando mientras se exportan: el manifiesto identifica cualquier archivo cuyo tamaño o fecha cambió durante su lectura.

El inventario y los SHA-256 de los bytes realmente archivados se encuentran en MANIFIESTO.json. La verificación comprueba todos los archivos descomprimidos en memoria contra ese manifiesto. Las carpetas vacías también se conservan.

## Alcance y límites del contexto conversacional

Se recuperaron todas las páginas que la herramienta de historial devolvió de estos tres chats:

- «Crear videojuego en Steam»: 6abf85fc-3710-83e8-9851-a6ea516c71ba.
- «Analiza la instalación del juego»: 01a0fc33-ca5e-7973-9ccc-2707906632d2. Incluye análisis, desarrollo inicial, comentarios del usuario, demostración de referencia, prompts y creación de Brumaferal.
- «Ejecuta el videojuego en modo prueba»: 01a11e2b-61c0-7852-84fb-9095a28e0bba. Incluye reapertura y solicitud de esta exportación.

Los JSON conservan exactamente la respuesta recuperada, y CONTEXTO_CONVERSACIONES.md presenta los mensajes recuperados en orden cronológico dentro de cada chat. Se preservan los mensajes incluso cuando contienen afirmaciones posteriormente corregidas. El prompt adjunto original se copia por separado en contexto/adjuntos.

Esto no garantiza un volcado íntegro de la base de datos de ChatGPT: la herramienta expone historial y salidas acotadas, con un máximo solicitado de 20.000 caracteres por elemento. Puede omitir contenido antiguo o imágenes, y las referencias a capturas no equivalen a disponer del archivo de imagen. Por ejemplo, la respuesta actual del chat de origen no devuelve algunos turnos antiguos que sí aparecen citados en las vistas previas incorporadas a los otros chats. Esas vistas previas se conservan, pero no se inventan mensajes faltantes. Las capturas presentes en los proyectos sí están incluidas. El turno de exportación se captura hasta el momento de recuperación; la respuesta final con el enlace al ZIP ocurre después de crear el archivo.

## Objetivo del usuario y decisiones de diseño

El usuario desea un juego original similar en sensación a MEGABONK, con movimiento fluido, cámara amplia, saltos, terreno con desniveles, hordas, ataques automáticos, experiencia recogible, elecciones de mejoras y una presentación retro 3D coherente. El objetivo es un juego completo, desarrollado en entregas jugables, no presentar una base técnica como producto terminado.

La primera interpretación fue «el jugador más seis amigos» (siete); el usuario corrigió el alcance a un máximo de seis jugadores en total, con opción individual y distintas clases. La especificación posterior usa ese límite de seis.

Riftbound fue rechazado por su aspecto y experiencia demasiado básicos. Se decidió conservarlo y crear Brumaferal por separado, con identidad visual propia. No corresponde trasladar automáticamente a Brumaferal las funciones ni pruebas de Riftbound.

La demostración del usuario en MEGABONK fue una referencia para diseñar el juego. El usuario aclaró que no era un entrenamiento del asistente para jugar. La observación fue mediante capturas sucesivas, no una grabación continua ni medición precisa de cada movimiento. El asistente reconoció limitaciones para controlar el juego de forma fluida y no demostró una partida profesional ni completa.

Se observaron cámara alejada, personaje pequeño pero legible, desniveles, plataformas, roca, árboles, ruinas, recompensas, cofres, revólver, aura y elecciones de mejoras. Los hitos aproximados de nivel 5 y 195 bajas a dos minutos, y nivel 10 y más de 300 bajas a tres minutos, pertenecen a una partida concreta; no son parámetros obligatorios del diseño. Tampoco se midieron con precisión velocidades, altura del salto, cadencias o rutas.

El ciclo deseado es explorar, atraer/esquivar enemigos, eliminar grupos, recoger recursos, elegir mejoras y afrontar encuentros más exigentes. Prioridades acordadas: movimiento/cámara, presentación visual, combate, exploración/progresión, cooperativo/clases y finalmente contenido/metaprogresión/acabado. El prompt íntegro adjunto contiene los criterios de aceptación y el plan de entregas.

## Historia del trabajo realizado

1. Se inspeccionó la instalación local de MEGABONK en modo de lectura. El historial reporta Unity 2023.2.22f1, Windows x64, IL2CPP, Steam AppID 3405340, build 21750826 y unas 69 entradas de archivo/523 MB. Se identificaron ejecutables, datos de Unity, Addressables, traducciones y dependencias. Esta exportación conserva esas conclusiones históricas; no ha vuelto a auditar esa instalación ni copia sus recursos.
2. Se implementó Riftbound en Unreal Engine 5.8.2, con seis clases, combate automático, sala, hordas, jefe, progresión, reanimación y estructura de red autoritativa.
3. Se compiló Riftbound y se ejecutaron pruebas funcionales sin renderizado y una prueba local con anfitrión y cinco clientes. Se documentaron límites, incluidos falta de validación visual inicial, Internet y empaquetado.
4. Se abrió Riftbound para el usuario. Su respuesta indicó que no correspondía a lo esperado. Se investigaron referencias y se observaron capturas de MEGABONK en funcionamiento; el documento REFERENCIAS-MEGABONK.md conserva referencias y límites.
5. Se redactó y refinó el prompt de desarrollo, incorporando lo observado y la prioridad de verificar apariencia y sensación antes de ampliar sistemas.
6. Se creó Brumaferal en una carpeta separada: bosque de ruinas con pendientes, rutas, tres santuarios, personaje Vigía, cámara orbital, movimiento, salto, impulso evasivo, enemigos, cristales, cofres, mejoras y guardián.
7. Se generó geometría facetada original y materiales con textura de baja resolución. Se implementó una interfaz de juego con salud, nivel, experiencia, tiempo, bajas, ámbar, objetivos y radar.
8. Se corrigieron caras de geometría invertidas, conexión de cámara al extremo del brazo, colisión de enemigos con la cámara, deriva de posición de cristales, triángulos degenerados y conexiones del material que no compilaban.
9. Se ejecutaron pruebas de integración y una auditoría renderizada; se guardaron Forest.png, Combat.png y registros. Se dejó abierta una ejecución normal sin ayudas de auditoría.
10. El 8 de octubre, en este chat, se localizaron ambos proyectos. La DLL de Riftbound era del 2 de octubre a las 04:18; la de Brumaferal, del 3 de octubre a las 02:58, horas locales. Se eligió Brumaferal por ser la entrega más reciente.
11. El primer intento de apertura desde el entorno restringido no persistió. El segundo abrió Unreal en modo -game con ventana de 1440 × 900. Se verificó un proceso activo que respondía y cuyo título era «Brumaferal (64-bit Development PCD3D_SM5)». El registro confirmó inicialización de la cámara. No se modificó el código ni se recompiló para esa apertura, ni se realizó una partida completa nueva.
12. Esta solicitud produce el respaldo y la documentación; no añade funciones al juego ni cambia su diseño.

## Estado actual de Brumaferal

Es una primera entrega jugable individual. Tiene principio, progreso, objetivo, victoria, derrota y reinicio básicos, pero no constituye el producto final. Usa Unreal instalado para ejecutar un módulo Development Editor; no hay paquete autónomo de distribución.

### Arquitectura y archivos principales

| Archivo o carpeta | Responsabilidad |
|---|---|
| Brumaferal.uproject | Asociación Unreal 5.8, módulo Runtime Brumaferal, plugins ProceduralMeshComponent y PythonScriptPlugin |
| Source/Brumaferal/Grove.h | Declaraciones del estado, mundo, recompensa, héroe, enemigo, modo e interfaz |
| Source/Brumaferal/Grove.cpp | Registro del módulo, estado replicado, IA, daño de enemigos, oleadas, reglas, auditorías y HUD |
| Source/Brumaferal/GroveHero.cpp | Movimiento, cámara, arte del personaje, entradas, habilidades, progresión y combate |
| Source/Brumaferal/GroveWorld.cpp | Terreno, vegetación, ruinas, cielo, iluminación y recompensas |
| Source/Brumaferal/Facet.h | Construcción de triángulos, cajas, conos y cristales, normales planas, materiales |
| Source/*Target.cs y Brumaferal.Build.cs | Objetivos Game/Editor y dependencias de compilación |
| Content/Art | M_Facet, M_Glow y textura facet_noise en formato Unreal |
| Tools/materials.py y facet_noise.png | Generación de materiales y textura original |
| Config | Mapa, modo, renderizado, entrada y configuración del proyecto |
| Binaries/Win64 | DLL, PDB, archivo modules y descriptor del objetivo compilado |
| Saved y Tools/*.log | Configuración generada, registros de ejecución/pruebas y capturas |
| Intermediate y DerivedDataCache | Productos intermedios y cachés conservados por completitud |
| .git | Historial local de Brumaferal, conservado tal cual |

El mapa inicial es /Engine/Maps/Entry y el modo es /Script/Brumaferal.GroveMode. El mundo jugable se construye en tiempo de ejecución; no debe confundirse la ausencia de un mapa propio .umap con falta del escenario.

Las dependencias de módulo son Core, CoreUObject, Engine, InputCore y ProceduralMeshComponent. La configuración usa DX11, sin ray tracing, desenfoque de movimiento ni autoexposición; no usa iluminación global dinámica ni reflejos avanzados según sus ajustes actuales. Las configuraciones originales se incluyen completas.

### Movimiento, cámara y personaje

Vigía de máscara marfil, poncho jade y bastón ámbar; geometría original procedural y animación de piernas procedural, no un personaje con animaciones esqueléticas terminadas. Movimiento relativo a la orientación horizontal de cámara; el motor gestiona CharacterMovement.

Valores actuales del código, en unidades Unreal donde corresponde: velocidad 760, aceleración 5400, frenado 4200, fricción 7, impulso vertical de salto 820, gravedad 1,9, control aéreo 0,8, giro 900 grados/s, escalón 48 y pendiente caminable 48 grados. Cápsula de radio 28 y semialtura 78. Memoria de salto 0,13 s y tolerancia de borde 0,11 s.

Cámara: brazo inicial 1050, rango por rueda 650–1350 con pasos de 90, FOV 85, desplazamiento vertical 75, suavizado de brazo 8 y camera lag 14. Rotación inicial pitch -29/yaw 18. Factores de entrada de giro 0,65 y vertical 0,6. Colisión de cámara con escenario; enemigos ignoran el canal de cámara. No hay todavía menú de sensibilidad/accesibilidad completo.

### Reglas, economía y combate

- Fases: 0 inicio, 1 partida, 2 victoria, 3 derrota. Enter inicia o reinicia. La derrota se produce cuando no queda ningún héroe vivo.
- Estado inicial: vida 100, nivel 1, experiencia 0, ámbar 0, una descarga, sin aura, poder 1. Reiniciar concede 2 s de invulnerabilidad.
- Ataque automático: cada 0,55 s, alcance 1350, objetivos ordenados por distancia, comprobación de línea de visión, daño 19 × poder. Los efectos actuales son líneas/esferas de depuración; no son proyectiles físicos finales.
- Brote múltiple aumenta objetivos hasta cinco; después incrementa poder en 0,3. Aura sube hasta nivel ocho, radio 220 + 35 × nivel, daño (5 + 3 × nivel) × poder cada 0,8 s. Fuerza aumenta poder en 0,25 y cura hasta 30, con límite de vida 100.
- Subida de nivel: coste de experiencia nivel × 9; concede una elección y cura 12. Las elecciones disponibles no pausan automáticamente la partida.
- Cada cristal concede 3 XP y 1 ámbar; se atrae a un héroe vivo dentro de 360 unidades, a velocidad 850, y se recoge por debajo de 90. El código actual concede la recompensa al recolector, no implementa un reparto cooperativo compartido completo.
- Se colocan 20 cofres con distribución determinista de semilla 719. Cuestan 10 ámbar, conceden una elección y curan 15.
- Hay tres santuarios en posiciones fijas. Cada uno añade un santuario activado, 15 XP y hasta 25 de curación. E interactúa dentro de 240 unidades y prioriza una recompensa cercana antes de lanzar el pulso.
- Pulso: enfriamiento 8 s, invulnerabilidad 0,4 s, radio 650, daño 42 × poder, empuje horizontal 700 y vertical 240.
- Impulso evasivo: enfriamiento 2,3 s, velocidad de lanzamiento horizontal 1550 y vertical 180, invulnerabilidad 0,42 s. Usa dirección de movimiento o, estando quieto, orientación frontal.
- Tras daño aceptado hay 0,65 s de invulnerabilidad. Fuera de límites laterales ±6250 o por debajo de -700, el héroe se recoloca al centro.
- Enemigos: básico, variante de carga, resistente y guardián. No hay todavía el conjunto completo de enemigos solicitado en el prompt, especialmente atacante a distancia y élite desarrollado.
- Velocidades de variantes: 290/340/210/260. Resistente 95 de vida; normales 28; guardián 1600, multiplicados por 1 + 0,35 × (jugadores vivos - 1). Daño de contacto normal 8, resistente 16; carga 15; área de guardián 24. Avisos de carga 0,65 s y guardián 1,1 s.
- IA de persecución del héroe vivo más cercano, desvío local ante obstáculos y separación entre enemigos. No es una navegación avanzada verificada en todos los lugares.
- Oleadas: inicialmente cada 2 s; después max(0,28, 1 - tiempo × 0,002) / raíz(jugadores vivos), con límite ordinario de 80 enemigos y excepción para el jefe. Variantes aparecen después de 40 s.
- Guardián: se invoca al activar tres santuarios o superar 240 s. Su muerte produce victoria. Tiene un patrón básico de área; no es un jefe con fases completas.

### Interfaz y controles

HUD dibujado con Canvas: salud, nivel, barra de XP, tiempo, bajas, contador de santuarios, ámbar, instrucciones, radar relativo a cámara, tres opciones de mejora, invitación de interacción, inicio, pausa y resultados. No es un sistema de menús final.

| Entrada | Acción |
|---|---|
| Enter | Empezar/reiniciar |
| WASD | Movimiento relativo a cámara |
| Ratón | Girar cámara |
| Rueda | Distancia de cámara |
| Espacio | Salto |
| Shift izquierdo | Impulso evasivo |
| E | Pulso o interacción con cofre/santuario |
| 1 / 2 / 3 | Brote / aura / fuerza y curación |
| Escape | Pausa/continuación solo en Standalone |

### Red: implementado no equivale a validado

Existe replicación de estado, héroe, enemigos y recompensas; llamadas de habilidad autoritativas y efectos multicast; PreLogin comprueba el límite de seis. Eso es una base técnica. Brumaferal todavía no tiene cooperativo completo validado, menú de conexión, seis clases, sinergias, reanimación, manejo completo de desconexiones ni integración Steam. La prueba con seis conexiones pertenece a Riftbound.

## Pruebas y evidencia disponible

Brumaferal: compilación Development Editor registrada como correcta para Unreal 5.8.2. Tools/audit.log contiene BRUMA_AUDIT PASS y confirma suelo, desplazamiento superior a 600 unidades, cámara a más de 400, salto observado de 194,7, nivel/XP, compra de mejora, rechazo sin puntos, recogida, cofre, santuario, victoria forzada y reinicio.

Tools/visual-audit.log contiene 3155 muestras, media 3,17 ms y percentil 95 de 4,12 ms. La auditoría renderizada usa recorrido automático, salto, 55 enemigos extra, tres descargas, aura y vida fijada a 100. Esas ayudas se activan solo con BrumaVisualAudit. No representan una partida humana normal ni garantizan rendimiento sostenido con seis personas. Sus capturas están en Saved/Screenshots/Forest.png y Combat.png.

El equipo consignado en la validación histórica es Ryzen 7 7700X y RTX 4070 Ti SUPER, a 1440 × 900. Esta exportación no repite esa medición. No se debe interpretar el salto de la auditoría como una medición exacta de la altura libre de los pies: la prueba usa posición del actor respecto al terreno.

Los registros antiguos preservan fallos y avisos de iteraciones anteriores; no todos describen un fallo actual. Se observaron avisos históricos de SpawnActor por colisión. El código de aparición diferida utiliza el actor devuelto sin comprobación explícita de nulidad en algunos puntos: conviene revisar esa robustez, sin afirmar que se haya reproducido un fallo ahora. También deben revisarse selección de aura al máximo y consumo de elección, reparto de recursos, congestión y navegación bajo carga.

No se ha probado aquí una partida larga completa, una derrota manual, guardado/carga persistente de Brumaferal, mando completo, siete conexiones para comprobar rechazo, red entre equipos, latencia/pérdida, instalación en otro PC ni un paquete Shipping. El último lanzamiento solo confirma arranque y ventana respondiendo.

## Riftbound: antecedente conservado

Incluye seis clases con estadísticas/habilidades diferentes, movimiento, salto, combate automático, habilidad, reanimación cercana, lobby, límite de seis, arena generada, hordas, jefe en el último minuto de una partida de diez minutos, experiencia compartida, mejoras y guardado local de estadísticas. Clases con 1–6; Enter inicia; WASD/ratón/espacio controlan; E habilidad; R reanimación; F1/F2/F3 daño/cadencia/vida.

Lanzadores JugarSolo.cmd, CrearPartida.cmd y Launch.ps1 (Solo/Host/Join por IP). Red IP nativa de Unreal, sin matchmaking, relay ni invitaciones Steam. Test-Network.ps1 y registros NetworkHost/NetworkClient1–5 preservan la prueba loopback. RiftboundProfile.sav conserva el estado local existente.

Su VALIDACION.md registra compilación con Visual Studio 2026/MSVC 14.51 y avisos de compilador más nuevo que el preferido; conversiones double/float y APIs sin impedir compilación. La prueba individual y de seis conexiones pasó, incluida colisión de suelo en clientes e inicio replicado. Fuerza la muerte del jefe; no demuestra diez minutos de combate real. Arte básico, sonido, menús, red real, persistencia visual, rendimiento sostenido y empaquetado siguen sin validar o incompletos según sus documentos.

## Pendientes priorizados para continuar Brumaferal

1. Jugar y evaluar movimiento/cámara: bordes, pendientes, paredes, aterrizajes, giro, comodidad, lectura de terreno y control durante combate. Ajustar con evidencia del usuario.
2. Completar feedback: impactos, animaciones, proyectiles/efectos de producción, audio, señales de daño, claridad de enemigos y recompensas. Sustituir efectos de depuración antes de distribuir.
3. Equilibrar partida completa: progresión, elecciones con cambios perceptibles, cofres, santuarios, dificultad, tiempos y final. Evitar gastar puntos en mejoras que ya alcanzaron su máximo.
4. Mejorar IA y aparición: comprobaciones de fallos de spawn, navegación, obstáculos, separación y coste de bucles de búsqueda entre enemigos. Añadir enemigos a distancia/élites y jefe con patrones, respuesta y fases.
5. Desarrollar y probar cooperativo hasta seis: clases propias, sinergias, recompensas compartidas/individuales explícitas, caída/reanimación, elección sin pausa global, desconexiones, salida del anfitrión, latencia, pérdida y séptimo cliente.
6. Persistencia real en Brumaferal: perfiles, desbloqueos, resultados, guardado/carga y recuperación; no confundir el .sav de Riftbound con esta función.
7. Menús y opciones: inicio, crear/unirse, ajustes gráficos, sensibilidad, controles reasignables, mando, accesibilidad, volumen y reducción de efectos.
8. Contenido y arquitectura: más armas, objetos y combinaciones; datos ajustables; separar responsabilidades actualmente concentradas en Grove.cpp. Más zonas solo después de validar la base.
9. QA y rendimiento: sesiones largas, densidad de enemigos representativa, seis jugadores, estabilidad, tirones, memoria y pruebas en otros equipos. Guardar evidencia reproducible.
10. Distribución: build independiente Game/Shipping, cocinado de recursos procedurales/materiales, prueba sin editor, instalador o paquete, metadatos y pruebas de Steam. Steam no está integrado ni publicado.

## Cómo restaurar y ejecutar

Extraer el ZIP por completo a una ruta local. Conservar juntas las carpetas de cada proyecto. No ejecutar desde dentro del explorador de archivos comprimidos.

Para la configuración de este equipo, abrir Brumaferal/Jugar.cmd: lanza C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe con Brumaferal.uproject, /Engine/Maps/Entry, -game, -windowed, -ResX=1440 y -ResY=900. Pulsar Enter al aparecer el bosque.

En otro equipo se necesita una instalación compatible de Unreal 5.8 (la compilación registrada es 5.8.2). El lanzador contiene una ruta absoluta al motor: si está instalado en otra ubicación, ajustar la copia del lanzador o abrir el .uproject con ese motor. Los binarios son de Windows x64 y pueden requerir recompilar por diferencias de versión. Los productos intermedios pueden contener rutas del equipo original; el código y los recursos son la base para reconstruirlos.

Para compilar se necesitan las herramientas C++ y SDK compatibles con el motor. El objetivo es BrumaferalEditor Win64 Development. Las dependencias exactas del estado actual se preservan en los .Build.cs, .Target.cs, .target y registros de compilación. Esta exportación no instala dependencias ni verifica portabilidad en otra máquina.

## Documentación íntegra y detalle técnico

DOCUMENTACION_ORIGINAL.md reúne íntegramente los documentos originales del proyecto. FUENTES_Y_CONFIGURACION.md reúne el código, scripts y ajustes de texto relevantes con sus rutas, sin sustituir los originales incluidos en el ZIP. Estos anexos, el prompt adjunto, la transcripción y los JSON permiten consultar detalles que no sería fiable reducir a una explicación narrativa. Para valores y comportamiento exactos manda el código archivado; para lo realmente probado mandan los registros y los límites aquí descritos.

No se han modificado los archivos originales del juego para esta exportación. sources/ se trata como referencia de solo lectura; estaba vacío en la inspección. El respaldo conserva la estructura disponible sin inventar recursos que no existen.
