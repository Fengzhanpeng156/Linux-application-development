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

rwlock_write_hungry: rwlock_write_hungry.c
	-$(CC) -o $@ $^ -pthread
	-./$@
	-rm ./$@

rwlock_hungry_solved: rwlock_hungry_solved.c
	-$(CC) -o $@ $^ -pthread
	-./$@
	-rm ./$@

condition_var: condition_var.c
	-$(CC) -o $@ $^ -pthread
	-./$@
	-rm ./$@
condition_var_copy: condition_var_copy.c
	-$(CC) -o $@ $^ -pthread
	-./$@
	-rm ./$@

unnamed_sem_bin_process_condition: unnamed_sem_bin_process_condition.c
	-$(CC) -o $@ $^ -pthread -lrt
	-./$@
	-rm ./$@

unnamed_sem_bin_process:unnamed_sem_bin_process.c
	-$(CC) -o $@ $^ -pthread -lrt
	-./$@
	-rm ./$@
unnamed_sem_count_thread: unnamed_sem_count_thread.c
	-$(CC) -o $@ $^ -pthread -lrt
	-./$@
	-rm ./$@

named_sem_bin: named_sem_bin.c
	-$(CC) -o $@ $^ -pthread -lrt
	-./$@
	-rm ./$@

named_sem_count: named_sem_count.c
	-$(CC) -o $@ $^ -pthread -lrt
	-./$@
	-rm ./$@

