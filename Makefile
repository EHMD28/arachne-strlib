tests: tests.c src/arachne.c
	$(CC) -o tests.out tests.c src/arachne.c -fsanitize=address
	