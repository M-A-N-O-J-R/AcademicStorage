MOV AX,0800H
MOV CX,05H
MOV DS,AX
MOV ES,AX
MOV SI,010H
MOV DI,020H
L1: MOVSB
LOOP L1
HLT