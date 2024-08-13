.MODEL SMALL
.CODE 

org 100h

Programa_Int:
JMP Reside
;;;;; Declaración de variables
contador db 0
Array db '00:00'		;array de caracteres ascii

Rutina_Servicio PROC
CLI
; Salvar el contenido de los registros implicados en la rutina
PUSH AX
PUSH DI
PUSH SI

INC contador		;inc incrementa en 1

CMP contador,18

JB final		;si no es igual a 18 , salta al final 

MOV contador,0		;resetear el contador 

MOV AX, 0B800h
MOV ES, AX
MOV AH , 00001111b  		;para poner el estilo del texto, fondo,etc

MOV SI,0			;contador para el array
MOV DI,148			;para colocarnos al final de la primera linea

;bucle

BSTR:

MOV AL , array[SI]
MOV ES:[DI] , AX

ADD DI,2
INC SI

CMP SI , 4
JBE BSTR


;controlar el reloj(si tiene que pasarde 9 a 10 etc)

CMP array[4], '9'		;unidades llegan a 9
JNE IncrementoUnidades			
MOV array[4] , '0'
INC array[3]

CMP array[3] , '6'
JNE final
MOV array[3] , '0'
INC array[1]

CMP array [1] , '9'
JNE final
MOV array[1] , '0'
INC array[0]

CMP array[0], '6'
JNE final
MOV array [0] , '0'
JMP final

IncrementoUnidades:
INC array[4]

final:

POP AX
POP SI
POP DI
; Recupera el valor de los registros implicados en la rutina
STI
IRET
ENDP
Reside: ;etiqueta para determinar la dirección siguiente a la última de la rutina
;que debe quedar residente

MOV DX, offset Rutina_Servicio
MOV AX, 0
MOV ES, AX
MOV SI, 1Ch*4
CLI
MOV ES:[SI], DX
MOV ES:[SI+2], CS
STI
MOV DX, offset Reside
INT 27h

END Programa_Int