#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define N_THREADS 100
int n = 0;

void *task(void *arg) {
  int i,j;

  for (i=0; i<100; i++)
    for (j=0; j<100; j++)
      n++;
  return NULL;
}

int main() {
  pthread_t t[N_THREADS];
  int i;

  for (i=0; i<N_THREADS; i++)
    if ( pthread_create(&(t[i]), NULL, task, NULL) != 0 ) {
      printf("pthread_create() error, i=%d\n",i);
      exit(-1);
    }

  for (i=0; i<N_THREADS; i++)
    pthread_join(t[i],NULL);

  printf("n=%d\n", n);
}
