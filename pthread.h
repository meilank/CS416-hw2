#include "spinlock.h"

#ifndef XV6_PTHREAD
#define XV6_PTHREAD

// Define all functions and types for pthreads here.
// This can be included in both kernel and user code.

typedef struct {
	int pid;
	void *stack;
} pthread_t;

typedef struct {
	int kern;
} pthread_attr_t;

typedef struct {
	int id;
} pthread_mutex_t;

typedef struct {
	int id;
} pthread_mutexattr_t; 

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void*), void *arg);

int pthread_join(pthread_t thread, void **retval);

int pthread_exit(void *retval);

int pthread_mutex_destroy(pthread_mutex_t *mutex);

int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);

int pthread_mutex_lock(pthread_mutex_t *mutex);

int pthread_mutex_unlock(pthread_mutex_t *mutex);


#endif