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
