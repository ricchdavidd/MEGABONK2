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
