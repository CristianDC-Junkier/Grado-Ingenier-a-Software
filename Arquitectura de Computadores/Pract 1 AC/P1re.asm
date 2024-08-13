.MODEL SMALL
.CODE 

org 100h

Programa_Int:
JMP Reside
;;;;; Declaración de variables
contador db 00h
valores db 00h,00h,00h
Rutina_Servicio PROC
CLI
; Salvar el contenido de los registros implicados en la rutina
PUSH AX
PUSH CX
PUSH DI
push BX
PUSH SI
PUSH DX

mov di,0000h
mov si,0000h

INC contador		;inc incrementa en 1
CMP contador,18h 
JB final

mov al,dh
CMP dx,0999h
JBE x
mov bh,10h
div bh
mov valores[1],ah
mov valores[0],al 
jmp y
x:
CMP dx,0099h
JBE nodivide
mov bh,10h
div bh       ; en ah almacena el resto de la division en al el cociente
mov cl,al
mov valores[1],ah
mov ax,0000h
mov al,cl   
y:
mov al,dl
mov ah,00h
CMP al,09h
JBE nodivide2
div bh
mov valores[2],al
mov valores[3],ah
 
JMP Divide

nodivide:
mov valores[2],al

nodivide2:
mov valores[3],al 

Divide:

mov al,03h   ;interrupcion para usar el modo texto
mov ah,0
int 10h
MOV AX, 0B800h
MOV ES, AX
MOV AH, 00001111b ; carácter impreso en pantalla con fondo negro y texto blanco
mov ah,valores[0]
add ah,48
mov es:[di],ah
mov ah,valores[1]
add ah,48
mov es:[di+2],ah
mov ah,valores[2]
add ah,48
mov es:[di+4],ah
mov ah,valores[3]
add ah,48
mov es:[di+6],ah
;FIN

MOV ah,00h  ;Pausa hasta que pulses una tecla
int 16h

final:
POP DX
POP AX
POP BX
POP CX
POP DI
POP SI
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