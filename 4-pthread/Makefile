CC:=gcc

create_test: create_test.c
	-$(CC) -o $@ $^ -pthread
	-./$@
	-rm ./$@

terminate_test: terminate_test.c
	-$(CC) -o $@ $^ -pthread
	-./$@
	-rm ./$@