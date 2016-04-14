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

int
pthread_mutex_init(void)
{
	return mutex_init();
}

int
pthread_mutex_destroy(int mutex_id)
{
	return mutex_destroy(mutex_id);
}

int 
pthread_mutex_lock(int mutex_id)
{
	return mutex_lock(mutex_id);
}

int
pthread_mutex_unlock(int mutex_id)
{
	return mutex_lock(mutex_id);
}
