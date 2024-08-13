.model small

.STACK 100h
;no es necesario 
.data ;En el segmento de datos

cadena db 5,0,0,0,0,0,0; 1ero contador 4 pos para almacenar y retorno de carro
peso db 2,4,2,1; pesos de los bits de la cadena 2^3 con signo y para el signo del complemento a 2
peso2 db 8,4,2,1;pesos complemeto a 2 


.code ;En el segmento de código
;comienzo BNS

MOV AX, seg cadena ;Inicialización del registro ;segmento de datos
MOV DS, AX

MOV dx, offset cadena;capturar datos de cadena
MOV ah, 0ah
int 21h

;Restar 48 para quitar el codigo acsi
sub cadena[2],48
sub cadena[3],48
sub cadena[4],48
sub cadena[5],48 

;Mult el peso por la posicion
Mov cl,43
Mov al,cadena[2]
mul peso[0]
add cl,al
MOV al,cadena[3]
mul peso[1]
add bl,al
MOV al,cadena[4]
mul peso[2]
add bl,al
MOV al,cadena[5]
mul peso[3]
add bl,al       ;bl contendra la suma de todos los PESOSxPOS (en decimal)

mov ax,bx
mov bl,10

div bl           ; en ah almacena el resto de la division y en al el cociente
mov ch,ah
add ch,48 

mov al,03h
mov ah,00h
int 10h

mov ax,0b800h         ;Modo texto
mov es, ax            ;inicializacion segmento extra
mov di,0
  
;Imprimir por pantalla
mov ah,00001111b       ; caracter impreso en pantalla con fondo negro y texto blanco
mov al,cl
mov es:[di],ax
mov al,ch
mov es:[di+2],ax
 
;se queda esperando a que la pulsacion de una tecla para continuar
mov ah,00h
int 16h


;FIN BNS

;borra pantalla
mov al,03h
mov ah,00h
int 10h




;Comienzo complemento
 
MOV dx, offset cadena
MOV ah, 0ah
int 21h
;Restar 48 para quitar el codigo acsi
sub cadena[2],48
sub cadena[3],48
sub cadena[4],48
sub cadena[5],48

                      ;coloca para imprimir si es negativo o positivo
Mov cl,43    
Mov al,cadena[2]
mul peso[0]
add cl,al 


CMP cadena[2],1    ;comparacion para saber si es negativo o positivo
JE positivo
;positivo

;multiplico por los pesos
Mov al,cadena[2]
mul peso[0]
add bl,al
MOV al,cadena[3]
mul peso[1]
add bl,al
MOV al,cadena[4]
mul peso[2]
add bl,al
MOV al,cadena[5]
mul peso[3]
add bl,al
  
JMP negativo
positivo:    
;negativo
;Cambio el numero restandole a 1111   para el complemento a 1
Mov al,1
sub al,cadena[2]
Mov cadena[2],al
Mov al,1
sub al,cadena[3]
Mov cadena[3],al
Mov al,1
sub al,cadena[4]
Mov cadena[4],al
Mov al,1
sub al,cadena[5]
Mov cadena[5],al 

Mov al,cadena[2]
mul peso[0]
add cl,al
MOV al,cadena[3]
mul peso[1]
add bl,al
MOV al,cadena[4]
mul peso[2]
add bl,al
MOV al,cadena[5]
mul peso[3]
add bl,al
add bl,1     ;sumo 1 para el complemento a 2

negativo:                   



mov ax,bx
mov bl,10

div bl
mov ch,ah
add ch,48 

          ; en ah almacena el resto de la division

mov al,03h
mov ah,00h
int 10h

mov ax,0b800h
mov es, ax
mov di,0
  
;Imprimir por pantalla
mov ah,00001111b
mov al,cl
mov es:[di],ax
mov al,ch
mov es:[di+2],ax
 
;se queda esperando a que la pulsacion de una tecla para continuar
mov ah,00h
int 16h


MOV AH, 4Ch;Interrupción software para ;devolver el control al S.O.
INT 21h

END;
