mov ax,0800h
mov ds,ax
mov si,00h
mov ax,00h
mov cx,0ah
outer:mov dx,cx
mov cx,0ah
double: dec cx
cmp cx,00h
jz triple
single: mov bl,[si]
mov al,[si+1]
cmp al,bl
inc si
jnc double
mov [si-1],al
mov [si],bl
loop single
triple:mov si,00h
mov cx,dx
loop outer
hlt