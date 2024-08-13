.MODEL SMALL
.STACK 100h;no es necesario 
.DATA;En el segmento de datos 

cadena db 5,0,0,0,0,0,0; 1ero contador 4 pos para almacenar y retorno de carro
peso db 8,4,2,1; pesos de los bits de la cadena 2^3 ej

.CODE;En el segmento de código

MOV AX, SEG cadena;Inicialización del registro ;segmento de datos
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
MOV al,cadena[2]
mul peso[0]
mov bl,al
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
mov cl,al
add cl,48
mov ch,ah
add ch 48 

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

END;Fin del archivo a traducir


;CMP compara contador con el valor que tu le pongas y si es cierto je fin salta  
;cmp cont,0
;je fin   je=  jump equal (salta si es igual) hasta fin