.MODEL SMALL
.CODE 

org 100h

Programa_Int:
JMP Reside
;;;;; Declaración de variables

contador db 0
valores db 0,0,0,0

Rutina_Servicio PROC
CLI
; Salvar el contenido de los registros implicados en la rutina
PUSH AX ;5 Ins + 3
PUSH CX
PUSH DI
push BX
push dx
PUSH SI  

INC contador		;3 ins
CMP contador,91h ;91 = 5 s
JB final

mov al,13h   ;interrupcion para usar el modo grafico
mov ah,0     ;8 inst fijas
int 10h

mov ax, 0A000h  ;se coloca el 0 delante para que no compile mal
mov es, ax    ;inicializar el segmento extra

mov si, 0000h
mov contador,0h
mov cx,dx

color: ;9 inst cada bucle
CMP contador,14h; 14h=20
JE rojo
INC contador
mov bl,01
mov es:[si],bl
INC si ;incremento en 1inc si
mov bl,02
mov es:[si],bl
INC si ;incremento en 1inc si
JMP ini
Rojo: ; 7 veces *7 inst
mov bl,36
mov es:[si],bl
INC si ;incremento en 1
mov es:[si],bl
INC si ;incremento en 1
mov contador,0h
add cx,1h
Ini:
LOOP color

MOV ah,00h  ;Pausa hasta que pulses una tecla
int 16h
;N nos sale 144
;Programa residente 91*(13)+(13+8)*1+9*144+7*7=2549 inst en 5 segundos
;Recogiendo el calculo anterior N = 192016 * 144 + 5
;MIPS = (144 * 192016 + 5 + 2549)/5*10^6
;MIPS (27650314)/(5s*10^6)=5,53 Mips
;a 3000 ciclos en el programa.

final:

POP AX ;5 ins
POP BX
POP CX
POP DI
pop dx
POP SI; Recupera el valor de los registros implicados en la rutina
STI
IRET
ENDP
Reside: 
;etiqueta para determinar la dirección siguiente a la última de la rutina que debe quedar residente
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