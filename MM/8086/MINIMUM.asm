MOV AX,0800H
MOV DS,AX
MOV SI,00H
MOV CX,0BH
MOV AX,00H
MOV AL,0FFH
DOUBLE:DEC CX
CMP CX,00H
JZ FINAL
SINGLE: MOV BL,[SI]
CMP BL,AL
INC SI
JNC DOUBLE
MOV AL,BL
LOOP SINGLE
FINAL: MOV DI,050H
MOV [DI],AL
HLT

