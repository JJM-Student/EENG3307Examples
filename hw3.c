#include <stdio.h>
#include <stdlib.h>

int allocate_memory(double ** buf, long N)   /* Returns a 0 on success, 1 on failed */
{
   if (N>1000000)
     {
        printf("Tried to hog up too much memory!\n");
     }
   else
   {
     * buf=(double *)malloc(N*sizeof(double));   
   if (*buf==NULL)
     {  
        printf("Allocation failed\n");
     }
      else
      {
      return 0;  /* Only returned for N<=1000000 and *buf != NULL */
      }
      return 1;   /* Defaults to returning a failed 1 for N>1000000 or Allocation failed - could later distinguish these! */
   }
   
}
void gen_random_numbers(double *buf,long N)
{
   long i;
   for (i=0;i<N;i++)
      buf[i]=(double)rand()/RAND_MAX; 
}
double compute_average(double *buf,long N)
{
   double sum=0;
   int i;
   for (i=0;i<N;i++)
      sum+=buf[i];

   return(sum/N);
}
int main(int argc, char *argv[])
{
   double *buffer,average;
   long N;
   
   if (argc <2)
     {
        printf("You didn't give me enough parameters....deuces!\n");
        exit(0);
     }
   N=atoi(argv[1]);
   if (allocate_memory(&buffer, N) == 0)     /* Updated code here so that following steps only run on successful allocation */
   {
   gen_random_numbers(buffer,N);
   average=compute_average(buffer,N);
   printf("The average we have been waiting on is %f\n",average);
   }
   return(0);
}

