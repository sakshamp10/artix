output: code.o
	gcc -m64 -no-pie code.o -o code
code.o: code.asm
	yasm -f elf64 code.asm
