#define  _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/types.h>

int main(int argc, char* argv[]){
  uint32_t iteraciones;
  
  struct rusage r_usage;
  
  if(argc != 2){
    fprintf(stderr, "Uso: %s <iteraciones> \n", argv[0]);
    exit(EXIT_FAILURE);
  }
  
  iteraciones = atoi(argv[1]);

  printf("PID: %d\n", getpid());
  int total = 0;

  for(size_t i=0; i<iteraciones;i++){
	//system("sleep 1");
	sleep(1);
	//total += i;
	  ;
  }
    

  getrusage(RUSAGE_SELF,&r_usage);
  
  printf("Cambios de contexto\n");
  printf("Ctxt Voluntarios      = %ld\n", r_usage.ru_nvcsw);
  printf("Ctxt No Voluntarios   = %ld\n", r_usage.ru_nivcsw); 

  return(EXIT_SUCCESS);
}
