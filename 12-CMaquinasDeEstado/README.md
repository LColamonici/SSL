# 1. Árboles de Expresión
**a.** Estudiar el programa del ejemplo las sección 1.5.4 Conteo de Palabras
de [KR1988].
**b.** Dibujar el árbol de expresión para la inicialización de los contadores: nl
= nw = nc = 0.
![punto 1b](.\TP12_1b.jpeg)
**c.** Dibujar el árbol de expresión para la expresión de control del segundo if:
c == ' ' || c == '\n' || c == '\t'.
![punto 1c](.\TP12_1c.jpg)
# 2. Máquina de Estado:
**a.** Describir en lenguaje dot [DOT] y dentro del archivo histograma.gv la
máquina de estado que resuelve el problema planteado.
![punto 1b](.\histograma.jpeg)
(archivo .gv incluido en el repositorio)

**b.** Formalizar la máquina de estados como una n-upla, basarse en el
Capítulo #1 del Volumen #3 de [MUCH2012].
# 3. Implementaciones de Máquinas de Estado:
Las implementaciones varían en los conceptos que utilizan para representaar
los estados y las transiciones.
**a.** Implementación #1: Una variable para el estado actual.
i. Escribir el programa histograma-1-enum-switch.c que siga la
Implementación #1, variante enum y switch.
Esta implementación es la regularización de la implementación de la
sección 1.5.4 de [KR1988]. Los estados son valores de una variable y
las transiciones son la selección estructurada y la actualización de esa
variable. Esta versión es menos eficiente que la versión de [KR1988],
pero su regularidad permite la automatización de la construcción del
programa que implementa la máquina de estados. Además de la
regularidad, esta versión debe:

• Utilizar typedef y enum en vez de define, de tal modo que la
variable estado se pueda declarar de la siguiente manera: State
s = Out;
• Utilizar switch en vez de if.
ii. Responder en readme.md: Indicar ventajas y desventajas de la versión
de [KR1988] y de esta implementción.

**Respuesta:**
RESPECTO AL CODIGO ORIGINAL
 * Ventajas: el switch hace mas facil entender el alcance de cada condicional, el uso de enum permite agregar facilmente mas estados si hace falta
 * Desventajas: la estructura del switch complica la legibilidad del codigo al tener varios casos en los que se hace lo mismo

**b.** Implementación #2: Sentencias goto (sí, el infame goto)
i. Leer la sección 3.8 Goto and labels de [KR1988]
ii. Leer Go To Statement Considered Harmful de [DIJ1968].
iii. Leer "GOTO Considered Harmful" Considered Harmful de [RUB1987].
iv. Responder en readme.md: ¿Tiene alguna aplicación go to hoy en día?
¿Algún lenguaje moderno lo utiliza?

**Respuesta:**
goto no tiene una aplicación que le sea exclusiva. Como se menciona en "Goto and labels" de [KR1988], "codigo escrito con un goto siempre puede escribirse sin uno". Sin embargo, tambien se aclara que hay casos particulares donde el uso del Goto puede ahorrar tests repetidos y variables extra.
Goto aún se puede encontrar en algunos de los lenguajes mas modernos como golang.

v. Escribir el programa histograma-2-goto.c que siga la
Implementación #2.
En esta implementación los estados son etiquetas y las transiciones
son la selección estructurada y el salto incondicional con la sentencia
goto.
**c.** Implementación #3: Funciones Recursivas
i. Leer la sección 4.10 Recursividad de [KR1988].
ii. Responder en readme.md: ¿Es necesario que las funciones accedan
a contadores? Si es así, ¿cómo hacerlo?
**Respuesta:**
No es necesario que una función recursiva acceda a un contador. Lo unico estrictamente necesario es comprobar si se cumple alguna condición de corte que termine con los llamados recursivos a la funcion. Sin embargo, en el caso de histograma-3-rec.c, sí se accede a varios contadores para guardar la cantidad de caracteres, palabras y lineas que se ingresaron.

Leer la sección 1.10 Variables Externas y Alcance y 4.3 Variables
Externas de [KR1988].
iii. Escribir el programa, histograma-3-rec.c que siga la implementación
#3.
En esta implementación los estados son funciones recursivas y las
transiciones son la selección estructurada y la invocación recursiva.
**d.** Implementación #X:
Es posible diseñar más implementaciones. Por ejemplo, una basada
en una tabla que defina las transiciones de la máquina. En ese caso,
el programa usaría la tabla para lograr el comportamiento deseado. El
objetivo de este punto es diseñar una implementación diferente a las
implementaciones #1, #2, y #3.
i. Diseñar una nueva implementación e indicar en Readme.md cómo esa
implementación representa los estados y cómo las transiciones.
ii. Escribir el programa, histograma-x.c que siga la nueva
implementación.
# 4. Escribir un único programa de prueba para las cuatro implementaciones.
# 5. (Opcional)
Construir una tabla comparativa a modo de benchmark que
muestre el tiempo de procesamiento para cada una de las cuatro
implementaciones, para tres archivos diferentes de tamaños diferentes, el
primero en el orden de los kilobytes, el segundo en el orden de los megabytes,
y el tercero en el orden de los gigabytes.
Eficiencia del uso del Tiempo:
La tabla tiene en las filas las cuatro implementación, en las columnas los tres
archivos, y en la intersección la duración para una implementación para un
archivo.