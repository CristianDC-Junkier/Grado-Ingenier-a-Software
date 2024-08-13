.model small 
.data

Blanco db 0Fh  ;para escribir en azul en el modo grafico
Verde db 02h ;para escribir en verde en el modo grafico
Comparador db 00h ;para reescribir el verde
;para contar instrucciones 1=64000 (320*200) usaremos dx

.code

mov ax,seg Blanco 
mov ds,ax    ;inicializo el segmento de datos
mov dx,0000h

JMP Comienzo ;4 instrucciones 1  vez en todo el programa
Reinicio: ;3 instrucciones cada bucle 
mov si, 0000h

INC dx
Mov Comparador,00h

Comienzo: ;5 instrucciones cada bucle
mov al,13h   ;interrupcion para usar el modo grafico
mov ah,0
int 10h

mov ax, 0A000h  ;se coloca el 0 delante para que no compile mal
mov es, ax    ;inicializar el segmento extra
;para cuando salte el bucle

BucVer:
;bucle verde  (3 instrucciones por bucle * 20800 + 4)*2 porque se repite arriba y abajo de la bandera  +4 por las 2 de arriba y el CMP y JZ o INC
mov cx,05140h        ;05140h=20800 decimal
mov bl,Verde
Ver:
mov es:[si],bl
inc si ;incremento en 1
LOOP Ver

CMP Comparador,0001h ;comparo para saber si es la segunda vez que escribe en verde
JZ Reinicio ;salto al principio para borrar la pantalla
INC Comparador

;bucle blanco 3 instrucciones por bucle * 22400 + 3
mov cx,05780h     ;05780h=22400 en decimal
mov bl,Blanco
Blanc:
mov es:[si],bl
INC si ;incremento en 1
LOOP Blanc

JMP BucVer ;Salto al Verde
; N= Numero de veces que se repite las pantallas
; En total= N * (3 * 22400 + 3 + 6 * 20800 + 8 +5) +4 => total = N * 192016 + 5
mov ah,4ch ;devolver a el so el control 
int 21h
end