default:
	gcc void.c -o void -Wall -Wextra -lm

run: default
	./void

clean:
	rm void