test: main.o
	gcc -o test.exe main.o -Wall -Wextra -Werror

main.o: main.c
	gcc -c main.c

debug: main.c
	gcc main.c -g 

clean:
	rm main.o 
	rm test.exe