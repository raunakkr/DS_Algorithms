  /*calculate program execute time */
#include <time.h>
#include <stdio.h>
 
int main(int argc, char *argv[]) {
int i=0;
   time_t start, stop;
   clock_t ticks; long count;
 
   time(&start);
   // Do stuff

   
   while(i<5000)
   {
	printf("Work work %d\n", i);
        i++;
        ticks = clock();
 
   }
 
   time(&stop);
 
   printf("Used %0.2f seconds of CPU time. \n", (double)ticks/CLOCKS_PER_SEC);
   printf("Finished in about %.0f seconds. \n", difftime(stop, start));
   return 0;
}