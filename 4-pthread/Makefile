CC:=gcc

create_test: create_test.c
	-$(CC) -o $@ $^ -pthread
	-./$@
	-rm ./$@

terminate_test: terminate_test.c
	-$(CC) -o $@ $^ -pthread
	-./$@
	-rm ./$@

pthread_detach_test: pthread_detach_test.c
	-$(CC) -o $@ $^ -pthread
	-./$@
	-rm ./$@


pthread_cancel_deferred_test: pthread_cancel_deferred_test.c
	-$(CC) -o $@ $^ -pthread
	-./$@
	-rm ./$@

race_condition_test: race_condition_test.c
	-$(CC) -o $@ $^ -pthread
	-./$@
	-rm ./$@
rwlock_test_writer_unlock: rwlock_test_writer_unlock.c
	-$(CC) -o $@ $^ -pthread
	-./$@
	-rm ./$@
rwlock_test: rwlock_test.c
	-$(CC) -o $@ $^ -pthread
	-./$@
	-rm ./$@
rwlock_rw_alternate: rwlock_rw_alternate.c
	-$(CC) -o $@ $^ -pthread
	-./$@
	-rm ./$@

