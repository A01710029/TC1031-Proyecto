# TC1031-Proyecto

## Archivo de Tiendas Starbucks
Este proyecto se basa en el sistema de evaluación utilizado por Starbucks para sus distintas tiendas dentro de la República Mexicana, en el que se considera el número de ventas por mes, el número de ganancia generada por mes, el Índice de Conexión (un decimal entre 1 y 10 que representa la calidad de servicio al cliente) y el Índice de Inocuidad y Calidad Alsea, o ICA (un porcentaje completo entre 1 y 100 que representa la calidad de limpieza y seguridad). 

El programa permite, a través de un menú, imprimir las tiendas guardadas, imprimir las tiendas basado en su número de ventas, número de ganancia, índice de conexión e índice de ICA, agregar más tiendas y generar un reporte general de todas las tiendas. 

## SICT0301: Evalúa los componentes

### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
El Shell Sort tiene una complejidad de tiempo promedio de O(nlog n), ya que tiene dos ciclos, pero el ciclo exterior sirve como el límite del ciclo interior. Además, la brecha que se analiza se reduce a la mitad cada vez que corre el algoritmo. Shell Sort tiene una complejidad de espacio de O(1).

### Hace un análisis de complejidad correcto y completo para todas las estructuras de datos y cada uno de sus usos en el programa.
Las listas doblemente ligadas (Doubly-Linked Lists) tienen una complejidad promedio tanto de tiempo como de memoria de O(n). Al tener apuntadores tanto para el elemento anterior y posterior para cada elemento de la lista, es particularmente flexible para reordenar la lista al poder mover nodos en ambas direcciones. Pero, se debe notar que al tener dos apuntadores por cada nodo, se requiere una mayor cantidad de memoria.

### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
TBD

## SICT0302: Toma decisiones

### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Decidí utilizar un Shell Sort para este programa ya que es relativamente rápido y casi no ocupa espacio en la memoria. Los objetos que se están manipulando en este programa contienen varios datos y se está utilizando una estructura de datos relativamente intensiva en memoria, así que el uso de memoria en el algoritmo de ordenamiento es importante. También, existe la posibilidad de grandes variaciones entre los objetos, por lo que se prefiere un método de ordenamiento que puede hacer movimientos a largas distancias. Además, no es probable que el programa encuentre el peor caso, ya que la lista empieza desordenada. Este algoritmo se implementa en el archivo reporte.h en las funciones tiendasPorVentas() en las líneas 244 a 265, tiendasPorGanancia() en las líneas 276 a 297, tiendasPorConexion() en las líneas 308 a 329 y tiendasPorICA() en las líneas 340 a 361.

### Selecciona una estructura de datos adecuada al problema y lo usa correctamente.
Decidí utilizar una lista doblemente ligada (Doubly-Linked List) ya que permite recorrer la lista de manera flexible, ágil y en ambas direcciones, al igual que agregar y eliminar elementos con rapidez y facilidad, lo que es particularmente útil reordenar la lista sin perder su integridad. Además, entre las distintas estructuras de datos existentes, se distinguen las listas doblemente ligadas al no imponer una jerarquía entre objetos, lo cual no podría ser posible de manera racional en el contexto de este programa ya que las tiendas no tienen una característica con mayor importancia que las otras que se podría utilizar para priorirzar las tiendas. Se puede apreciar la implementación de esta estructura en el archivo dlist.h, el cual tiene la clase y las funciones auxiliares para su uso en el programa.

## SICT0303: Implementa acciones científicas

### Implementa mecanismos para consultar información de las estructuras correctos.
Estos mecanismos se implementaron en las siguientes funciones:
1) buscarTiendasEstado() en reporte.h en las líneas 374 a 392.
2) buscarTiendasPorMeta() en reporte.h en las líneas 407 a 445.

### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
Este mecanismo se implementó en la función cargarArchivo() en reporte.h en las líneas 79 a 99. 

### Implementa mecanismos de escritura de archivos para guardar los datos de las estructuras de manera correcta.
Este mecanismo se implementó en la función guardarArchivo() en reporte.h en las líneas 111 a 130 y su versión sobrecargada, para crear archivos de listas sorteadas, en las líneas 144 a 163. Además, se agregó en main.cpp la funcionalidad de generar un reporte cada vez que se sortean las tiendas por cualquier característica en las líneas 83, 90, 97 y 104, además de generar un reporte general de todas las tiendas, en la línea 138.
