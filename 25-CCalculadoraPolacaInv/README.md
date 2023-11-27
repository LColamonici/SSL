# TP 25: Calculadora con notacion polaca inversa


* Luca Colamonici
* K2051


6)\
    b- En caso de cambiar algun archivo .h, solamente haria falta volver a compilar el archivo que lo incluye, porque durante el preprocesamiento ya se incluiria el contenido modificado del archivo .h
    \
    c- Seria util que se mostrara el lexema que produce un error, asi el origen del problema es mas claro y no se tiene que buscar el error en toda la expresion
    - I: Seria mejor tener un tercer componente en Token de tipo char* donde se guarde el lexema para poder ver los caracteres que lo formaron 