# 7.3. Tareas
_1. La primera tarea es investigar las funcionalidades y opciones que su
implementación, es decir su compilador, presenta para limitar el inicio y fin de
las fases de traducción.
2. La siguiente tarea es poner en práctica lo que se investigó. Para eso se debe
transcribir al readme.md cada comando ejecutado y su resultado o error
correspondiente a la siguiente secuencia de pasos. También en readme.md se
vuelcan las conclusiones y se resuelven los puntos solicitados. Para claridad,
mantener en readme.md la misma numeración de la secuencia de pasos._
# 7.3.1. Secuencia de Pasos
_Se parte de un archivo fuente que es corregido y refinado en sucesivos pasos.
Es importante no saltearse pasos para mantener la correlación, ya que el estado dejado por el paso anterior es necesario para el siguiente._
## 1. Preprocesador
_a. Escribir hello2.c, que es una variante de hello.c:_
```
#include <stdio.h>
int/*medio*/main(void){
int i=42;
 prontf("La respuesta es %d\n");
```
_b. Preprocesar hello2.c, no compilar, y generar hello2.i. Analizar su contenido. ¿Qué conclusiones saca?_
**Rta:**
se preprocesa hello2.c con el comando:
 
```gcc -E hello2.c -o hello2.i```

La funcion del preprocesamiento es definir de forma explicita todo el codigo que viene en los #include, ademas de eliminar los comentarios


_c. Escribir hello3.c, una nueva variante:_
```
int printf(const char * restrict s, ...);
int main(void){
int i=42;
 prontf("La respuesta es %d\n");
 ```
_d. Investigar e indicar la semántica de la primera línea._
**Rta:**
En la primera línea se declara (pero no se define) la función printf. Esta función devuelve un numero entero y recibe como argumentos una cadena de caracteres y un numero indefinido de argumentos adicionales de tipo tambien indefinido

_e. Preprocesar hello3.c, no compilar, y generar hello3.i. Buscar diferencias entre hello3.c y hello3.i._
**Rta:**
Como el preprocesamiento modifica principalmente la inclusión de headers y los comentarios (cosas que hello3.c no tiene), los archivos son casi identicos excepto por la adicion de 4 lineas:
        \# 0 "hello3.c"
        \# 0 "\<built-in>"
        \# 0 "\<command-line>"
        \# 1 "hello3.c"   

## 2. Compilación
_a. Compilar el resultado y generar hello3.s, no ensamblar._
**Rta:**
se compila hello3c con el comando:
    ```gcc -S hello3.c -o hello3.s```
    lo que arroja un warning y un error:
    ```
    warning: implicit declaration of function 'prontf'; did you mean 'printf'? 
    error: expected declaration or statement at end of input
    ```

_b. Corregir solo los errores, no los warnings, en el nuevo archivo hello4.c y empezar de nuevo, generar hello4.s, no ensamblar._
_correccion hecha:_ se agrega la llave de cierre de main() 

_c. Leer hello4.s, investigar sobre lenguaje ensamblador, e indicar de forma sintética cual es el objetivo de ese código._
**Rta:**
El objetivo del codigo en lenguaje ensamblador es el mismo que el del codigo en c (declarar una variable i y ejecutar la función prontf), pero expresado en comandos aptos para un procesador 

_d. Ensamblar hello4.s en hello4.o, no vincular._

Se ensambla hello4.s con:
    ```gcc -c hello4.s -o hello4.o```

## 3. Vinculación
_a. Vincular hello4.o con la biblioteca estándar y generar el ejecutable._
_b. Corregir en hello5.c y generar el ejecutable. Solo corregir lo necesario_
para que vincule.
_c. Ejecutar y analizar el resultado._
**Rta:**
Para que el programa vincule, hubo que arreglar el error lexico del nombre de la función printf (mal escrito prontf). Solucionando esto, el programa ejecutable devuelve:
    ```La respuesta es [valor distinto de 42]```
    Esto es porque en el llamado a la función, aparece un %d pero nunca se especifica de donde sacar ese valor entero

## 4. Corrección de Bug
_a. Corregir en hello6.c y empezar de nuevo; verificar que funciona como se espera._
**Rta:**
Se corrige el error agregando la variable "i" como segundo parametro en printf. Luego se preprocesa, compila, ensambla y ejecuta hello6 con el comando:
    ```gcc hello6.c -o hello6.exe```

## 5. Remoción de prototipo
_a. Escribir hello7.c, una nueva variante:_
```
int main(void){
 int i=42;
 printf("La respuesta es %d\n", i);
}
```
_b. Explicar porqué funciona; para eso, considerar las siguientes preguntas:_

_i. ¿Arroja error o warning?_
**Rta:**
el codigo arroja un warning relacionado con la declaracion implicita de printf (al no incluir stdio.h, la funcion todavía no esta declarada)

_ii. ¿Qué es un prototipo y de qué maneras se puede generar?_
**Rta:**
un prototipo es la declaracion de una funcion sin su definición. Se pueden generar de forma directa, usando typedef, dentro de un enum{}, usando punteros a funciones, dentro de una estructura, dentro de otra función o en un macro

_iii. ¿Qué es una declaración implícita de una función?_
**Rta:**
Una declaración implicita es el llamado a una funcion sin un prototipo declarado previamente

_iv. ¿Qué indica la especificación?_
**Rta:**
Como la funcion se declara implicitamente durante el llamado a la misma (al no haber incluido ```stdio.h```), la especificacion de la funcion es la siguiente:
        - no se sabe el tipo de dato que devuelve, pero se asume que es un entero
        - los argumentos que recibe son una cadena de tipo ```const char*``` y un numero de tipo ```int```

_v. ¿Cómo se comportan las principales implementaciones?_
**Rta:**
Para la función printf (como se la define en stdio.h), hay 2 implementaciones principales:
        - recibe solamente una cadena de caracteres y la envía al stream de salida
        - recibe una cadena de caracteres y una serie de argumentos adicionales que determinan valores en lugares especificos de la primera cadena. Luego, manda la cadena resultante por el stream de salida

_vi. ¿Qué es una función built-in?_
**Rta:**
Una funcion built-in es una función que viene integrada en el lenguaje de programación, por lo que no hace falta incluir una librería o un archivo externo para usarla

vii.¿Conjeture la razón por la cual gcc se comporta como se comporta?
¿Va realmente contra la especificación?
## 6. Compilación Separada: Contratos y Módulos
_a. Escribir studio1.c (sí, studio1, no stdio) y hello8.c.
La unidad de traducción studio1.c tiene una implementación de la función prontf, que es solo un wrappwer1 de la función estándar printf:_
```
void prontf(const char* s, int i){
 printf("La respuesta es %d\n", i);
}
```
La unidad de traducción hello8.c, muy similar a hello4.c, invoca a
prontf, pero no incluye ningún header.
```
int main(void){
int i=42;
 prontf("La respuesta es %d\n", i);
}
```
_b. Investigar como en su entorno de desarrollo puede generar un programa ejecutable que se base en las dos unidades de traducción (i.e., archivos fuente, archivos con extensión .c).
Luego generar ese ejecutable y probarlo._
**Rta:**
Para unir las funcionalidades de hello8.c y studio1.c en un solo ejecutable, se usa el comando
    ```gcc hello8.c studio1.c -o hello8.exe``` 

_c. Responder ¿qué ocurre si eliminamos o agregamos argumentos a la
invocación de prontf? Justifique._
**Rta:**
Si se eliminan o agregan argumentos, la funcion invocada sería distinta de la declarada y no estaría definida (prontf solo esta definida para recibir una cadena y un entero)

_d. Revisitar el punto anterior, esta vez utilizando un contrato de interfaz en
un archivo header._
_i. Escribir el contrato en studio.h._
```
#ifndef _STUDIO_H_INCULDED_
#define _STUDIO_H_INCULDED_
void prontf(const char*, int);
#endif
```
_ii. Escribir hello9.c, un cliente que sí incluye el contrato._
```
#include "studio.h" // Interfaz que importa
int main(void){
int i=42;
 prontf("La respuesta es %d\n", i);
}
```
_iii. Escribir studio2.c, el proveedor que sí incluye el contrato._
```
#include "studio.h" // Interfaz que exporta
#include <stdio.h> // Interfaz que importa
void prontf(const char* s, int i){
 printf("La respuesta es %d\n", i);
}
```
_iv. Responder: ¿Qué ventaja da incluir el contrato en los clientes y en el proveedor._
**Rta:**
La ventaja principal es que permite mayor modularización e independencia del proveedor. Un contrato funciona siempre que el proveedor cumpla con la interfaz del contrato. Por lo tanto, se puede usar cualquier proveedor (que cumpla el requisito) sin tener que hacer modificaciones en el cliente o el contrato 