# TC1031-Proyecto

## Archivo de Tiendas Starbucks
Este proyecto se basa en el sistema de evaluación utilizado por Starbucks para sus distintas tiendas dentro de la República Mexicana, en el que se considera el número de ventas por mes, el número de ganancia generada por mes, el Índice de Conexión (un decimal entre 1 y 10 que representa la calidad de servicio al cliente) y el índice de Inocuidad y Calidad Alsea, o ICA (un porcentaje completo entre 1 y 100 que representa la calidad de limpieza y seguridad). 

El programa permite imprimir las tiendas guardadas, imprimir las tiendas basado en su número de ventas y agregar más tiendas. 

## SICT0301: Evalúa los componentes

### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
El Shell Sort tiene una complejidad de tiempo promedio de O(nlog n), ya que tiene dos ciclos, pero el ciclo exterior sirve como el límite del ciclo interior. Además, la brecha que se analiza se reduce a la mitad cada vez que corre el algoritmo. Shell Sort tiene una complejidad de espacio de O(1).

### Hace un análisis de complejidad correcto y completo todas las estructuras de datos y cada uno de sus usos en el programa.
Las listas doblemente ligadas (Doubly-Linked Lists) tienen una complejidad promedio de O(n). 

### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
TBD

## SICT0302: Toma decisiones

### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Decidí utilizar un Shell Sort para este programa ya que es relativamente rápido y casi no ocupa espacio en la memoria. Los objetos que se están manipulando en este programa contienen varios datos, así que el uso de memoria es importante. También, existe la posibilidad de grandes variaciones entre los objetos, por lo que se prefiere un método de ordenamiento que puede hacer movimientos a largas distancias. Además, no es probable que el programa encuentre el peor caso, ya que la lista empieza desordenada. La función en donde se puede ver este algoritmo es en el archivo reporte.h en las líneas 76 a 87.

### Selecciona una estructura de datos adecuada al problema y lo usa correctamente.
Decidí utilizar una lista doblemente ligada (Doubly-Linked List) ya que permite recorrer la lista de manera ágil y en ambas direcciones, al igual que agregar y eliminar elementos con rapidez y facilidad.  

## SICT0303: Implementa acciones científicas

### Implementa mecanismos para consultar información de las estructras correctos.
Estos mecanismos se implementaron en las siguientes funciones:

### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
Este mecanismo se implementó en la función cargarArchivo() en reporte.h en las líneas 57 a 77. 

### Implementa mecanismos de escritura de archivos para guardar los datos de las estructuras de manera correcta.
TBD
