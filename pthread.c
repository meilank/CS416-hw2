#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "pthread.h"

// Implement your pthreads library here.

#define STACKSIZE 4096

int 
pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void*), void *arg)
{
	//malloc stack to pass to clone

	void *stack = (void*) malloc(STACKSIZE);
	
	thread->pid = clone(start_routine, arg, stack);
	return 0;
}

int
pthread_join(pthread_t thread, void **retval)
{
	int ret = join(thread.pid, (void*)&thread.stack, retval);

	if (ret < 0)
	{
		return -1;
	}

	free(thread.stack);
	return ret;
}

int
pthread_exit(void *retval)
{
	texit(retval);
	return 0;
}

int 
pthread_mutex_destroy(pthread_mutex_t *mutex)
{
	return mutex_destroy(mutex->id);
}

int 
pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr)
{
	if ((mutex->id = mutex_init()) < 0)
	{
		return -1;
	}
	return 0;
}

int 
pthread_mutex_lock(pthread_mutex_t *mutex)
{
	return mutex_lock(mutex->id);
}

int 
pthread_mutex_unlock(pthread_mutex_t *mutex)
{
	return mutex_unlock(mutex->id);
}