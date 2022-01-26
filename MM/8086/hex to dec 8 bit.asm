org 100h

.data
result db 00h
d db 010h


.code
mov ax,@data
mov ds,ax
mov bl,d
mov al,0f0h
and al,bl
mov cl,04h
ror al,cl
mov cl,al
mov al,0ah
mul cl
mov cl,al
mov al,00fh
and al,bl
add al,cl
mov [result],al
mov dh,result
hlt
end