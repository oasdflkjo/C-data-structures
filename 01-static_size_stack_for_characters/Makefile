test: stack.o
	gcc -o test.exe stack.o -Wall -Wextra -Werror

stack.o: stack.c
	gcc -c stack.c

debug: stack.c
	gcc stack.c -g 

clean:
	rm stack.o 
	rm test.exe