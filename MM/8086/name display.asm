org 100h

.data
msg db "hello world!",24h

.code
mov ax,@data
mov ds,ax
mov dx,offset msg
mov ah,9h
int 21h 