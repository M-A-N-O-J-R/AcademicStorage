MOV AX,0800h
MOV DS,AX
MOV SI,010H
MOV AX,[SI]
MOV SI,020H
MOV BX,[SI]
ADD AX,BX
MOV DI,050H
MOV [DI],AX
MOV SI,012H
MOV AX,[SI]
MOV SI,022H
MOV BX,[SI]
ADC AX,BX
MOV DI,052H
MOV [DI],AX
HLT