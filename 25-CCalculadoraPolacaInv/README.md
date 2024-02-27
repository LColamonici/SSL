# TP 25: Calculadora con notacion polaca inversa


* Luca Colamonici
* K2051


1. Estudiar la implementación de las sección 4.3 de [KR1988].
2. Construir los siguientes componentes, con las siguientes entidades públicas:
3. Leer Gramáticas y BNF de [MUCH2012].
4. Diseñar una gramática para la calculadora RPN y presentarla en BNF en
Readne.md.

<digito> ::= 1|2|3|4|5|6|7|8|9|0

<numeroEntero> ::= <digito> | <digito><numeroEntero>

<numero> ::= <numeroEntero> | <numeroEntero>'.'<numeroEntero>
                            |'-'<numeroEntero>
                            |'-'<numeroEntero>'.'<numeroEntero>

<operador> ::= +|-|*|/

<expresion> ::= <numero> | <expresion> <expresion> <operador>


1. Diagramar en Dot las dependencias entre los componentes e interfaces.
2. Definir formalmente y con digrafo en Dot la máquina de estados que
implementa GetNextToken, utilizar estados finales para diferentes para cada
clase de tokens.
3. Escribir un archivo expresiones.txt para probar la calculadora.
4. Construir el programa Calculator.
5. Ejecutar Calculator < expresiones.txt.
6. Responder:
a. ¿Es necesario modificar StackModule.h? ¿Por qué?
b. ¿Es necesario recompilar la implementación de Stack? ¿Por qué?
c. ¿Es necesario que Calculator muestre el lexema que originó el error
léxico? Justifique su decisión.
i. Si decide hacerlo, ¿de qué forma debería exponerse el lexema?
Algunas opciones:
• Tercer componente lexeme en Token¿De qué tipo de dato es
aplicable?
• Cambiar el tipo de val para que sea un union que pueda
representar el valor para Number y valor LexError.
ii. Implemente la solución según su decisión.
