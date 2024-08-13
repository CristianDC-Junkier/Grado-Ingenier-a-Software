.model small

.STACK 100h
;no es necesario 
.data ;En el segmento de datos
;comienzo BNS

cadena db 5,0,0,0,0,0,0; 1ero contador 4 pos para almacenar y retorno de carro
cadena2 db 5,0,0,0,0,0,0;Cadena complemento a 2
peso db 2,4,2,1; pesos de los bits de la cadena 2^3 con signo
peso2 db 2,4,2,1;pesos complemeto a 2

.code ;En el segmento de código

MOV AX, seg cadena ;Inicialización del registro ;segmento de datos
MOV DS, AX

MOV dx, offset cadena
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


;FIN BNS
;borra pantalla
mov al,03h
mov ah,00h
int 10h




;Comienzo complemento
 
MOV dx, offset cadena2
MOV ah, 0ah
int 21h
;Restar 48 para quitar el codigo acsi
sub cadena2[2],48
sub cadena2[3],48
sub cadena2[4],48
sub cadena2[5],48 

;Mult el peso por la posicion 
Mov al,1
sub al,cadena2[2]
mul peso2[0]
mov bl,al
MOV al,cadena2[3]
mul peso2[1]
add bl,al
MOV al,cadena2[4]
mul peso2[2]
add bl,al
MOV al,cadena2[5]
mul peso2[3]
add bl,al       ;bl contendra la suma de todos los PESOSxPOS (en decimal) 


mov ax,bx
mov bl,10

div bl           ; en ah almacena el resto de la division y en al el cociente
mov cl,al
add cl,48
mov ch,ah
add ch,48 

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



