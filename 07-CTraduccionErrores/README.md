# TP7: Fases de traduccion y errores

Luca Colamonici 
K2051

* 1
    b) se preprocesa hello2.c con el comando :
    ``` 
    gcc -E hello2.c -o hello2.i
    ```
    La funcion del preprocesamiento es definir de forma explicita todo el codigo que viene en los #include, ademas de eliminar los comentarios
    \
    c) En la primera línea se declara (pero no se define) la función printf. Esta función devuelve un numero entero y recibe como argumentos una cadena de caracteres y un numero indefinido de argumentos adicionales de tipo tambien indefinido
    \
    e) Como el preprocesamiento modificaprincipalmente la inclusión de headers y los comentarios (cosas que hello3.c no tiene), los archivos son casi identicos excepto por la adicion de 4 lineas:
        \# 0 "hello3.c"
        \# 0 "\<built-in>"
        \# 0 "\<command-line>"
        \# 1 "hello3.c"   

     
* 2
    a) se compila hello3c con el comando:
    ```
    gcc -S hello3.c -o hello3.s
    ```
    lo que arroja un warning y un error:
    ```
    warning: implicit declaration of function 'prontf'; did you mean 'printf'? 
    error: expected declaration or statement at end of input
    ```

    b) correccion: se agrega la llave de cierre de main() 
    
    \
    c) El objetivo del codigo en lenguaje ensamblador es el mismo que el del codigo en c (declarar una variable i y ejecutar la función prontf), pero expresado en comandos que puede entender un procesador 

    \
    d) Se ensambla hello4.s con:
    ```
    gcc -c hello4.s -o hello4.o
    ```

* 3
    c) Para que el programa vincule, hubo que arreglar el error lexico del nombre de la función printf (mal escrito prontf). Solucionando esto, el programa ejecutable devuelve:
    ```
    La respuesta es [valor distinto de 42]
    ```
    Esto es porque en el llamado a la función, aparece un %d pero nunca se especifica de donde sacar ese valor entero

* 4
    b)
        i - el codigo arroja un warning relacionado con la declaracion implicita de printf (al no incluir stdio.h, la funcion todavía no esta declarada)
        \
        ii - un prototipo es la declaracion de una funcion sin su definición. Se pueden generar de forma directa, usando typedef, dentro de un enum{}, usando punteros a funciones, dentro de una estructura, dentro de otra función o en un macro
        \
        iii - Una declaración implicita es el llamado a una funcion sin un prototipo declarado previamente