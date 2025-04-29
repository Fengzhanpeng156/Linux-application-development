CC:=gcc

create_test: create_test.c
	-$(CC) -o $@ $^ -pthread
	-./$@
	-rm ./$@