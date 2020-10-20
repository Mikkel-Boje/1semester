#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>   /* Nødvendig for tidtagning */

#define N 8000

void LinSearch(int array[], int n, int x, int print);
void BinSearch(int array[], int n, int x, int print);

int main(void){
  int x;
  char filename[20];
  FILE *myFile;
  int array[N];
  int k;
  int runs = 1000000;
  int i;

  sprintf(filename, "List%d.txt", N);
  printf("Indtast tallet du søger efter\n");
  scanf("%d", &x);

  myFile = fopen(filename, "r");

  /* indlæs fil ind i array */
  for (k = 0; k < N; k++){
    fscanf(myFile, "%d", &array[k]);
  }
  fclose(myFile);
        
  printf("Listestørrelsen er %d\n", N);
        
  /* Start tiden */
  double startTime = clock();
        

  for (i = 0; i < runs; i++){
    BinSearch(array, N, x, 0);
  }
        
  /* Slut tiden og print den */
  double endTime = clock();
  double duration = (endTime - startTime) / CLOCKS_PER_SEC;
  printf("BinSearch brugte: %.7fs\n", duration);


        
  /* Start tiden */
  startTime = clock();
        
  for (i = 0; i < runs; i++){
    LinSearch(array, N, x, 0);
  }
        
  /* Slut tiden og print den */
  endTime = clock();
  duration = (endTime - startTime) / CLOCKS_PER_SEC;
  printf("LinSearch brugte: %.7fs\n", duration);
        
  /* Køres en gang for at printe resultat */
  LinSearch(array, N, x, 1);
  BinSearch(array, N, x, 1);
  return 0;
}

void LinSearch(int array[], int n, int x, int print){
  int i;
  int j;

  j = n;

  while(i <= j && x != array[i]) 
  {
    i += 1;
  }

  if (print == 1){
    if (x == array[i]){
      printf("%d er på position %d\n",x,i+1);
    }
    else {
      printf("%d er ikke i listen \n",x);
    }
  }
}

void BinSearch(int array[], int n, int x, int print){
  int i;
  int j;
  int m;

  j = n;
  
  while(i < j)
  { 
    m = floor((i + j) / 2);

    if(x > array[m])
    {
      i = m + 1;
    }
    else
    {
      j = m;
    }
  }

  if (print == 1){
      if (x == array[i]){
         printf("%d er på position %d\n",x,i+1);
      }
      else {
         printf("%d er ikke i listen \n",x);
      }
  }
}


