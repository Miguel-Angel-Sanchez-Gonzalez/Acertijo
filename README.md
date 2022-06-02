# Acertijo
El presente es el proyecto final para la acreditación de la materia de Graficación.

## Ejecución del juego 
Para la ejecución correcta el juego primero se debe configurar OpenGL en DEV-C++.

### Programas y herramientas necesarios:

- El entorno de desarrollo integrado DEV-C++.
- La API gráfica 3D estándar del sector [OpenGL](https://www.opengl.org/).

### Configurar OpenGL en DEV-C++:

Antes de la ejecución de programa es necesario seguir una serie de pasos para poder configurar DEV C++ con OpenGL, con el siguiente video contaremos con una guía rápida de configuración
[video](https://www.youtube.com/watch?v=UOna-_g_wBM&t=769s).

## Controles e Instrucciones del juego
El juego consta de instrucciones y controles fáciles de entender, es por ello que a continuación se especifican cada una de ellas.

### Instrucciones:

1. El juego comienza con el personaje en el centro del escenario, la primera instrucción que recibe es revisar la consola de ejecución, donde se le asignara un acertijo que debe resolver.
2. Tras resolver el acertijo el jugador tendrá tres oportunidades para seleccionar una de las diez cajas que se encuentran esparcidas en el escenario.
3. Para seleccionar una caja basta con posicionarse enfrente de ella y presionar la tecla 'M', automáticamente se descontará una oportunidad y se mostrara en pantalla si es la caja correcta
o en su defecto el número de oportunidades restantes. 
4. El juego termina cuando el jugador selecciona la caja correcta, cuando el jugador gasta sus tres oportunidades sin adivinar la caja del acertijo o cuando el tiempo se termina.   

### Controles:

- La tecla 'W' le permite al jugador moverse hacia delante.
- La tecla 'A' le permite al jugador rotar 30° hacia la izquierda.
- La tecla 'D' le permite al jugador rotar 30° hacia la derecha.
- La tecla 'M' le permite al jugador seleccionar una caja siempre y cuando este último se posicione enfrente de ella.

## Variables a considerar
A continuación, se presentan algunos de las variables más importantes del juego contenidos en el archivo "Texturas.cpp", estos deben considerarse si se desea aumentar o disminuir la 
dificultad.

- La variable "reloj" controla el tiempo en que el jugador tendrá oportunidad de resolver el acertijo y encontrar la caja correcta, para mayor dificultad basta con disminuir el valor de 
este parámetro o en su defecto si se desea un tiempo extra se deberá aumentar.

- La variable "oportunidades" como su nombre lo indica son el número de oportunidades que el jugador tendrá para seleccionar la caja correcta, por defecto su valor es de tres oportunidades. 

- La variable "random" contiene un numero entre 0 y 10 que cambia en cada ejecución del juego, esta controla el acertijo asignado para el jugador, si se desea asignar uno de los acertijos
de manera fija, es decir, que en todas las ejecuciones sea el mismo basta con darle un valor constante contenido en el rango de 0 a 10.

## Integrantes

Proyecto elaborado por los estudiantes:

- [Ramírez Beltrán Berenice](https://github.com/BereBernal)
- [Ramos Lira Estefania](https://github.com/Estefania-Ramos-Lira)
- [Sánchez González Miguel Ángel](https://github.com/Miguel-Angel-Sanchez-Gonzalez)
