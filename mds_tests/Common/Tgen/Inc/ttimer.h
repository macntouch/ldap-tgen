#ifndef ttimer_h
#define ttimer_h

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>


//������������������������������������������������������������������������������
// DATA
//������������������������������������������������������������������������������

//timelist
typedef struct elem {
   struct elem		*next;
   void				*ctx;
} elem;


extern	elem*				*tTimerCircularTable;
extern	pthread_mutex_t *   tTimerMutex;


//������������������������������������������������������������������������������
// INIT
//������������������������������������������������������������������������������
int		tTimerInit(int tableSize);
void	tTimerClose();
void	tTimerTopTU();
int		tTimerGetMaxSleepTime();


//������������������������������������������������������������������������������   
// TIMER HANDLING
//������������������������������������������������������������������������������
void*	tTimerGetUserToResume();
int		tTimerSetUserToSleep(void* aCtx, int nbTimeUnit);


#endif
