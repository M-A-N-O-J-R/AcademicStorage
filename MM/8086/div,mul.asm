MOV BX,0800H
MOV DS,BX
MOV SI,010H
MOV [SI],200
MOV AL,[SI]
INC SI
MOV [SI],04
MOV BL,[SI]
MUL BL   
MOV CX,AX
MOV SI,50
MOV [SI],203
MOV AX,[SI]
INC SI
MOV [SI],4
MOV BL,[SI]
DIV BL