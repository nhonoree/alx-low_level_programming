section .data
	msg db 'Hello, Holberton',0xa

section .text
	global _start

_start:
	; Write message
	mov rax, 1          ; sys_write
	mov rdi, 1          ; file descriptor (stdout)
	mov rsi, msg        ; pointer to message
	mov rdx, 18         ; message length
	syscall

	; Exit
	mov rax, 60         ; sys_exit
	xor rdi, rdi        ; exit code 0
	syscall
