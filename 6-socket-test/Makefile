CC:=gcc

num_endianess_convert: num_endianess_convert.c
	$(CC) -o $@ $<
	-./$@
	-rm ./$@

single_conn_server: single_conn_server.c
	-$(CC) -o $@ $^ -lpthread
single_conn_client: single_conn_client.c
	-$(CC) -o $@ $^ -lpthread