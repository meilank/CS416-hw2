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
	int taken; //0 if yes, 1 if no
	int id;
	int destroy;
} pthread_mutex_t;

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void*), void *arg);

int pthread_join(pthread_t thread, void **retval);

int pthread_exit(void *retval);

int pthread_mutex_init(void);

int pthread_mutex_destroy(int mutex_id);

int pthread_mutex_lock(int mutex_id);

int pthread_mutex_unlock(int mutex_id);

#endif