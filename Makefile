default:
	gcc void.c -o void -Wall -Wextra

run: default
	./void

clean:
	rm void