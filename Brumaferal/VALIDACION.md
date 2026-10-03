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
