MOV AX,800H
MOV DS,AX
MOV SI,00H
MOV CX,08H
MOV AX,00H
L1: MOV BL, [SI]
ADD AL,BL
INC SI
LOOP L1
ADD AL,[SI]
DAA
MOV [050H],AL
HLT