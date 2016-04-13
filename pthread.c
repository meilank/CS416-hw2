#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "pthread.h"

// Implement your pthreads library here.


int 
pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void*), void *arg)
{
	//malloc stack to pass to clone

	void *stack = (void*) malloc(4096);
	
	thread->pid = clone(start_routine, arg, stack);
	return 0;
}

int
pthread_join(pthread_t thread, void **retval)
{
	void **stack = (void**) malloc(sizeof(void*));

	return join(thread.pid, stack, retval);
}

int
pthread_exit(void *retval)
{
	texit(retval);
	return 0;
}
