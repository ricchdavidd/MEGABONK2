# Documentos originales íntegros


## Brumaferal/DESARROLLO.md

# Brumaferal — primera entrega en desarrollo

Proyecto independiente de Riftbound. Una zona original de bosque y ruinas, un vigía con máscara y bastón, enemigos de espinas y progresión por cristales.

## Criterios de esta entrega

- Arranque directo en una escena iluminada y reconocible.
- Movimiento relativo a la cámara, salto, impulso, órbita y distancia ajustable.
- Terreno con pendientes y puntos de referencia; recompensas que incentiven recorrerlo.
- Combate automático, tres elecciones de mejora, cofres y tres santuarios.
- Enemigos básicos, variante resistente y variante de carga con aviso.
- Final de partida y reinicio.
- Compilación, prueba de movimiento/progresión y revisión visual de la ventana real.

## Dirección visual

Verdes jade y musgo, piedra gris verdosa, recompensas ámbar y turquesa. Personaje de máscara marfil, poncho jade y bastón. Geometría facetada y textura pixelada de 32 × 32 originales generadas mediante código; no se usan recursos de MEGABONK. La animación actual es procedural, no esquelética.

## Alcance pendiente

Seis clases, sinergias, reanimación, menú de conexión, pruebas de seis clientes, guardado persistente, audio, ajustes completos, arte adicional y paquete independiente. La arquitectura inicial replica personaje, enemigos y estado; eso no equivale a cooperativo validado.

La prueba automática BrumaAudit comprueba desplazamiento real del personaje, suelo, experiencia, selección de mejora y rechazo de una mejora sin puntos. No sustituye la evaluación humana de la sensación de juego.


## Brumaferal/LEEME.md

# Brumaferal

Primera entrega jugable de un nuevo proyecto original de supervivencia en tercera persona.

Abre **Jugar.cmd**, espera a que aparezca el bosque y pulsa **Enter**.

| Control | Acción |
| --- | --- |
| WASD | Moverse respecto a la cámara |
| Ratón | Girar la cámara |
| Rueda | Acercar o alejar la cámara |
| Espacio | Saltar |
| Shift izquierdo | Impulso evasivo |
| E | Pulso; cerca de cofre o santuario, interactuar |
| 1, 2, 3 | Elegir mejora cuando haya puntos |
| Escape | Pausar o continuar en solitario |
| Enter | Empezar o reiniciar tras terminar |

Recoge los cristales azules que dejan los enemigos. Dan experiencia y ámbar. Cada cofre cuesta diez unidades de ámbar y otorga una mejora. Activa los tres santuarios para invocar al guardián; también aparece al transcurrir cuatro minutos. Derrótalo para ganar.

La primera clase es el Vigía. Dispara automáticamente a enemigos cercanos con línea de visión. Brote múltiple aumenta los objetivos simultáneos; aura daña alrededor del personaje; fuerza aumenta el daño y recupera vida.

## Estado real

Esta entrega permite jugar en solitario. No es aún el producto completo. El arte es geometría facetada original; la animación de carrera es procedural. Los efectos de combate son provisionales. No hay todavía audio, guardado persistente, menú multijugador ni seis clases implementadas. Usa Unreal instalado para ejecutar y todavía no es un paquete distribuible independiente.

El proyecto anterior se conserva intacto en Riftbound.


## Brumaferal/VALIDACION.md

# Verificación de la primera entrega

## Comprobado

- Compilación Development Editor para Unreal Engine 5.8.2.
- Generación y guardado de materiales originales: ejecución del script sin errores.
- Prueba de integración `BrumaAudit`: suelo, desplazamiento superior a 600 unidades, cámara a más de 400 unidades del personaje y salto observado de 194,7 unidades sobre el terreno.
- Experiencia, selección de mejora y rechazo de una mejora sin puntos.
- Recogida de cristal, pago y recompensa de cofre, activación de santuario.
- Transición a victoria al derrotar al guardián y reinicio del estado de partida.
- Prueba renderizada `BrumaVisualAudit`: recorrido automático, salto, generación de un grupo adicional de 55 enemigos y capturas del bosque y combate. Esta prueba conserva la vida del personaje y asigna poderes para inspeccionar el combate; esas ayudas no se activan en el inicio normal.

## Revisiones visuales y correcciones

Se corrigieron orientación de caras, conexión al extremo del brazo de cámara, respuesta de colisión de enemigos con la cámara, desplazamiento accidental de cristales al animarlos y conexiones de los materiales. Se eliminaron triángulos degenerados en puntas de geometría.

## Límites de la validación

La prueba automatizada no demuestra que la sensación de control satisfaga al usuario. Falta una sesión humana de evaluación del movimiento, cámara y equilibrio. No se ha validado multijugador ni una partida larga completa bajo condiciones reales. El guardián tiene un patrón básico de área, no un diseño de múltiples fases terminado.

Las capturas se guardan en `Saved/Screenshots/Forest.png` y `Combat.png`. Los resultados técnicos están en `Tools/audit.log`, `Tools/visual-audit.log` y `Tools/build.log`.

Equipo detectado por Unreal: Ryzen 7 7700X, NVIDIA GeForce RTX 4070 Ti SUPER. Las mediciones renderizadas son muestras cortas a 1440 × 900 y no garantizan el rendimiento final con seis jugadores.

Última prueba visual corregida: 3.155 muestras, media 3,17 ms y percentil 95 de 4,12 ms. No aparecen fallos de compilación de materiales ni avisos de triángulos degenerados en esa ejecución. Se inspeccionaron ambas capturas con el bosque visible, colores, textura pixelada, personaje, enemigos y recompensas.


## Riftbound/README.md

# Riftbound — título de trabajo

Juego original de supervivencia cooperativa para **1 a 6 jugadores**, en Unreal Engine 5.8.2. Proyecto en desarrollo; todavía no es un producto terminado.

## Sistemas implementados en código

- Seis clases con vida, velocidad, alcance, cadencia y habilidades diferentes.
- Movimiento de tercera persona y salto, ataque automático y habilidades manuales.
- Anfitrión autoritativo: daño, enemigos, mejoras, reanimación y estado de partida.
- Sala previa, selección de clase y límite de seis conexiones.
- Arena generada, hordas escaladas por tiempo y jugadores, jefe final.
- Partidas de diez minutos; vence al jefe durante el último minuto.
- Experiencia compartida, niveles y elección de mejoras sin pausar.
- Caída y reanimación; derrota al caer todo el grupo.
- Guardado local de partidas, victorias y mejor número de bajas.

## Controles

WASD mover, ratón cámara, espacio saltar, E habilidad, R reanimar a un aliado cercano. En la sala, 1–6 selecciona clase y Enter inicia como anfitrión. F1/F2/F3 gastan mejoras en daño/cadencia/vida. Enter reinicia después de victoria o derrota.

## Ejecutar y conectar

Para jugar individualmente con el motor instalado: doble clic en **JugarSolo.cmd**. Para alojar una partida: **CrearPartida.cmd**. Ambos usan el editor como ejecutor del juego; aún no existe un paquete independiente. Esperar a que Unreal termine de preparar recursos la primera vez.

Abrir Riftbound.uproject con Unreal 5.8. Para pruebas multijugador usar Play > Number of Players (hasta 6), Net Mode > Play As Listen Server. El anfitrión inicia con Enter después de que todos seleccionen clase.

La conexión implementada es la red IP de Unreal. Para dos equipos se necesita lanzar el juego con `/Engine/Maps/Entry?listen` en el anfitrión y conectar el cliente a su IP mediante `open IP:7777` en la consola. Requiere conectividad entre equipos; no se han cambiado reglas de firewall ni puertos. No hay todavía invitaciones de Steam, relay ni matchmaking.

## Trabajo pendiente hacia el juego completo

1. Validación jugable y de red entre equipos, latencia y desconexiones. La prueba local de un anfitrión y cinco clientes ya pasó; ver VALIDACION.md.
2. Menús interactivos de crear/unirse, ajustes, perfiles y selección de clase.
3. Arte original de personajes, animación, escenarios, VFX y audio. Las formas actuales son primitivas de Unreal.
4. Más enemigos, ataques telegrafiados, navegación y biomas.
5. Armas, objetos, sinergias, recompensas y progresión persistente visible.
6. Reanimación con tiempo de interacción, equilibrio de clases, accesibilidad y mandos.
7. Steam: invitaciones, transporte, logros, guardado en nube y distribución.
8. Pruebas de rendimiento, empaquetado, QA y versión publicable.

Los archivos de MEGABONK no se usan como código ni como recursos de este proyecto.


## Riftbound/REFERENCIAS-MEGABONK.md

# Referencias para corregir la dirección del juego

## Objetivo del usuario

Capturar mucho mejor la cámara, movimiento, presentación y combate de MEGABONK, con código y recursos originales y cooperativo de 1 a 6 jugadores. La arena con primitivas no satisface la referencia visual solicitada.

## Fuentes localizadas

- [Página oficial: capturas, tráiler y descripción](https://store.steampowered.com/app/3405340/Megabonk/).
- [Tráiler de lanzamiento publicado por GameTrailers](https://www.youtube.com/watch?v=1SqCw7InwkU).
- [Partida de Sir Oofie en Forest, publicada por Baziklet](https://www.youtube.com/watch?v=KKXEIOuNLGY). La descripción sitúa T1 en 00:00, T2 en 14:49, T3 en 27:33 y jefe en 39:07. Son marcas del autor, todavía no verificadas viendo el video.
- [Partida Forest T1 sin comentarios, SilentQuest](https://www.youtube.com/watch?v=tHHDpaAr-1c).
- [Captura de combate en bosque, PC Gamer](https://www.pcgamer.com/games/roguelike/a-slot-machine-for-gags-disguised-as-a-vampire-survivors-like-is-taking-over-steam-and-im-just-as-addicted-to-pulling-the-lever-as-the-other-90k-people-playing-it/).

Los videos están localizados, no analizados todavía. No presentar sus descripciones como observaciones directas de una partida.

## Observado directamente en la instalación

El 2 de octubre de 2026 se abrió el juego con autorización del usuario. La ventana muestra versión **1.0.69**.

- Fondo del menú con bosque 3D de geometría sencilla, vegetación verde, árboles de copas angulares, niebla azul y portal luminoso.
- Paneles oscuros verdosos con marcos ornamentales y tipografía de aspecto pixelado.
- Ajustes separados en Game, Video, Controls, Audio, Effects y Other.
- FOV ajustable y opción Camera Distance. Se observaron FOV 103 y luego 120 mientras había interacción manual; no asumir que son los valores predeterminados.
- Controles incluyen sensibilidad, suavizado de cámara, agacharse, apuntar, rotar cámara con flechas y elegir mejoras con teclas numéricas.

La herramienta rechazó inicialmente pulsaciones por detectar entrada manual concurrente. Después de que el usuario cediera los controles, se inició y controló una partida con pulsaciones discretas.

## Partida observada y controlada

- Fox, Forest Tier 1. Se eligió personaje y mapa desde la interfaz.
- Se enviaron avance, salto y desplazamiento lateral con salto. La API disponible no expone mantener una tecla durante un tiempo: esto limita la prueba de movimiento continuo y no permite medir aceleración o velocidad con precisión.
- El bastón disparó automáticamente sin pulsar ataque. Se observaron proyectiles luminosos, impactos, cifras de daño y gemas azules en el suelo.
- El personaje ocupa aproximadamente el 15–18% de la altura de pantalla, centrado horizontalmente y por debajo del centro vertical en este encuadre. Es una estimación visual con el FOV configurado a 120, no un valor universal del juego.
- El HUD tiene experiencia a lo largo del borde superior, vida y armas arriba a la izquierda, tiempo restante arriba al centro, nivel y minimapa arriba a la derecha, y objetivo a la izquierda.
- El bosque tiene pendientes, rocas, árboles angulares, ruinas de piedra, niebla azul y cielo muy visible. El relieve y las distancias no se parecen a una arena plana cerrada.
- En nivel 2 aparecieron tres ofertas: Size Tome, Damage Tome y mejora del Firestaff. Se seleccionó la tercera mediante la tecla 3 y se confirmó Firestaff nivel 2 en el HUD. La oferta indicaba proyectiles 1 → 2 y velocidad de proyectil 0.5 → 0.6.
- Durante la selección se mantuvo el tiempo de partida en 0:33; la pantalla presenta inventario a la izquierda, ofertas centrales y estadísticas a la derecha.
- La partida quedó **pausada en 0:53**, nivel 2, 46 bajas y 83/102 de vida. Esto es una prueba breve de inicio de partida, no una partida completa ni validación de jefes o contenido avanzado.

## Correcciones prioritarias para Riftbound

### Continuación de la prueba

Se reanudó la misma partida y terminó en derrota. La pantalla final confirmó **1:23 de supervivencia, nivel 3, 82 bajas y +2 de plata**. Desglose visible: Firestaff nivel 2, 965 de daño y 13 DPS; Chunkers nivel 1, 300 de daño y 5 DPS. No se encontró el portal ni se combatió al jefe.

Limitación comprobada: las pulsaciones breves y la demora entre observaciones dejan al personaje prácticamente quieto durante largos intervalos. Esta interfaz no permite un control continuo suficientemente eficaz para prometer completar el juego. La derrota no equivale a haber completado el bosque ni a haber estudiado todo el contenido.

1. Sustituir el suelo plano por un entorno con relieve, rutas, vegetación y ruinas originales.
2. Construir un personaje animado y ajustar cámara/escala con comparación visual antes de añadir clases.
3. Sustituir líneas de depuración por proyectiles, impactos y señales de daño legibles.
4. Añadir experiencia física recogible, monedas y puntos de interés.
5. Rediseñar el HUD y la elección entre tres mejoras; definir explícitamente cómo funciona esa elección en cooperativo sin pausar a otros cinco jugadores.
6. Comprobar ritmo y movimiento mediante pruebas continuas; la prueba automatizada por pulsaciones no basta para afirmar que se siente igual.

## Próximas observaciones necesarias

1. Cámara real: encuadre del personaje, altura, distancia, FOV y giro.
2. Movimiento: aceleración, frenado, salto, control aéreo, pendientes y agacharse.
3. Combate: alcance aparente, selección de objetivos, cadencia, efectos y reacción de enemigos.
4. HUD: jerarquía, escala, posiciones y legibilidad durante combate.
5. Mundo: tamaño relativo de árboles, relieve, caminos, obstáculos y puntos de interés.
6. Progresión: recogida de experiencia, frecuencia de niveles, opciones y pausas.
7. Ritmo: densidad de enemigos y presión durante los primeros minutos.

Antes de ampliar contenido, validar visualmente una escena original con cámara, terreno, personaje y HUD comparables en estructura a la referencia. Las pruebas de compilación y de red no sustituyen esa revisión.


## Riftbound/VALIDACION.md

# Estado comprobado

Fecha: 2 de octubre de 2026. Motor local: Unreal Engine 5.8.2. Windows x64.

## Compilación

RiftboundEditor Development: **correcta**. Visual Studio 2026 / MSVC 14.51. El motor avisa que este compilador es más reciente que su versión preferida. Hay advertencias de conversión double/float y de API del motor; no impidieron compilar.

## Ejecución individual

Prueba automática con UnrealEditor-Cmd, sin renderizado: **PASS**.

- Un personaje sobre la arena, cuatro enemigos generados.
- Experiencia, subida de nivel y gasto de mejora.
- Impide gastar una mejora sin puntos.
- Bloquea el cambio de clase durante una partida.
- Daño, caída, restauración del personaje.
- Victoria mediante evento de muerte del jefe y reinicio de partida.

Esta prueba fuerza el evento del jefe; no equivale a completar diez minutos de combate real.

## Seis conexiones

Un anfitrión y cinco clientes independientes conectados a loopback: **PASS**.

- El anfitrión detectó seis personajes y nueve enemigos.
- Cada uno de los cinco clientes confirmó seis personajes y seis jugadores.
- Cada cliente verificó colisión con el suelo recibido por red.
- Los clientes recibieron el inicio de la partida.
- El anfitrión pasó las mismas comprobaciones de reglas de juego.

Registros: Saved/Logs/Smoke.log, NetworkHost.log y NetworkClient1.log a NetworkClient5.log. Los mensajes de pérdida de conexión al final corresponden al cierre intencional del anfitrión de pruebas. El script cierra únicamente los procesos que creó.

## Aún sin verificar

- Presentación visual, controles manuales, sonido y experiencia de juego.
- Combate completo de diez minutos, equilibrio y ritmo.
- Red entre equipos, Internet, latencia y pérdida de paquetes.
- Rechazo real de un séptimo cliente (el límite existe en código).
- Persistencia de resultados mediante una partida con HUD renderizado.
- Rendimiento con cien enemigos y seis jugadores activos.
- Empaquetado independiente del editor y publicación.

El proyecto es una implementación inicial compilada y probada a nivel funcional; no se presenta como juego completo ni como versión lista para publicar.
