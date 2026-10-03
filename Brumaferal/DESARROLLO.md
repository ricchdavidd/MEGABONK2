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
