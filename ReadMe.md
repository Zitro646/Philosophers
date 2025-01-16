# Filósofos: Una Cena Mortal

Este proyecto es una simulación del conocido problema de los "Filósofos comensales", en el que los filósofos se sientan a una mesa, piensan, comen y duermen. El objetivo es simular su comportamiento mientras se evita el *deadlock* (bloqueo) y se asegura que no mueran de hambre. Utilizamos hilos y mutex para resolver el problema de manera eficiente.

![Texto alternativo](/readme/Philos.png)


## Requisitos


**Crear un programa que simule a los filósofos utilizando hilos y mutex**


### Reglas Generales
- **No se permiten variables globales**.
- Tu programa deben aceptar los siguientes argumentos:

- `number_of_philosophers`: Número de filósofos y también el número de tenedores en la mesa.
- `time_to_die`: Tiempo en milisegundos después del cual un filósofo muere si no ha comido.
- `time_to_eat`: Tiempo en milisegundos que un filósofo pasa comiendo. Necesita dos tenedores para comer.
- `time_to_sleep`: Tiempo en milisegundos que un filósofo pasa durmiendo.
- `number_of_times_each_philosopher_must_eat`: (Opcional) Si se especifica, la simulación termina cuando todos los filósofos hayan comido el número de veces indicado. Si no se especifica, la simulación termina cuando un filósofo muere.

### Reglas para los Filósofos
- Los filósofos se numeran del 1 al `number_of_philosophers`.
- El filósofo 1 se sienta junto al filósofo `number_of_philosophers`, y los demás filósofos se sientan entre los filósofos adyacentes.
- Cada filósofo tiene dos tenedores: uno a su izquierda y otro a su derecha.
- El programa debe mostrar mensajes de registro sobre los cambios de estado de cada filósofo.

### Formato de Registro
Los cambios de estado de los filósofos deben mostrarse de la siguiente manera:
- `timestamp_in_ms X has taken a fork`
- `timestamp_in_ms X is eating`
- `timestamp_in_ms X is sleeping`
- `timestamp_in_ms X is thinking`
- `timestamp_in_ms X died`

Donde `timestamp_in_ms` es el timestamp actual en milisegundos, y `X` el número del filósofo.

### Evitar el *Deadlock*
- El programa debe evitar los *deadlocks*, asegurando que ningún filósofo se quede bloqueado esperando tenedores indefinidamente.

### Otras Restricciones
- Un mensaje anunciando la muerte de un filósofo no debe mostrarse más de 10 ms después de su muerte real.
- Se deben evitar las condiciones de carrera (*data races*) en el programa.

---

## Informacion para el proyecto

![Texto alternativo](/readme/requisites.png)

## Detalles de la Simulación

Cada filósofo será un hilo separado. Los tenedores entre cada filósofo estarán protegidos mediante mutexes para asegurar que dos filósofos no intenten usar el mismo tenedor al mismo tiempo. El programa simula a los filósofos mientras alternan entre pensar, comer y dormir. Los filósofos deben evitar morir de hambre y garantizar que el sistema no se quede bloqueado.

Cada filósofo intentará comer si ambos tenedores están disponibles. Después de comer, dormirá por un tiempo especificado y continuará el ciclo.

---

## Cómo Compilar y Ejecutar

1. **Compilar**: Usa el `Makefile` proporcionado para compilar el proyecto.
2. **Ejecutar**: Ejecuta el programa `philo` con los argumentos requeridos. Por ejemplo:
 ```bash
 ./philo 5 800 200 200 5
 ```

##  Visualizacion
Hay una herramienta en github que te ayuda a visualizar como interactuan los philosofos y tal pueda ayudar
- https://nafuka11.github.io/philosophers-visualizer/

![Texto alternativo](/readme/Visualizer.png)
