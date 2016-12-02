make: turtleshell.c
	gcc -c -g utils.c
	gcc -c -g turtleshell.c
	gcc -g utils.o turtleshell.o -o shelly

run: make
	./shelly

clean:
	rm -rf *~
	rm -rf *.out
