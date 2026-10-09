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
