MOV BL,09H
MOV AX,0800H
MOV DS,AX
MOV AX,00H
MOV SI,00H
MOV CX,0BH
MOV DX,00H
SINGLE: DEC CX
CMP CX,00H
JE FINAL
MAINER: MOV AL,[SI]
INC SI
CMP AL,BL
JNZ SINGLE
INC DX
LOOP MAINER
FINAL: HLT