#include <stdio.h> 
#include <stdlib.h> 

void Merge(int L[], int l, int r, int m);
void MergeSort(int L[], int l, int r);
void printList(int L[], int size);

int main(void)
{ 
  int L[] = { 5, 3, 8, 1, 6, 10, 7, 2, 4, 9 }; 
  int L_size = sizeof(L) / sizeof(L[0]); 
  	
  printf("Givet listen \n"); 
  printList(L, L_size); 
  
  MergeSort(L, 0, L_size - 1); 
  
  printf("Er den sorterede liste \n"); 
  printList(L, L_size); 
  return 0; 
} 

void MergeSort(int L[], int l, int r)
{
  if(l < r)
  {
      int m;
      m = l + (r - l) / 2;

      MergeSort(L, l, m); 
      MergeSort(L, m + 1, r);
      Merge(L, l, r, m);
  }
}

void Merge(int L[], int l, int r, int m)
{
  int L1_lenght = m - l + 1;
  int L2_lenght = r - m;
  int L1[L1_lenght], L2[L2_lenght];
  int i = 0, j = 0, k = l;

  for (i = 0; i < L1_lenght; i++)
  {
      L1[i] = L[l + i];
  }
  
  for (j = 0; j < L2_lenght; j++)
  {
      L2[j] = L[m + j + 1];
  }
  
  i = 0, j = 0;

  while(i < L1_lenght && j < L2_lenght)
  {
      if(L1[i] <= L2[j])
      {
          L[k] = L1[i];
          i++;
      }
      else
      {
          L[k] = L2[j];
          j++;
      } 
    k++; 
  }

  while(i < L1_lenght)
  {
      L[k] = L1[i];
      i++;
      k++;
  }
  
  while (j < L2_lenght)
  {
      L[k] = L2[j];
      j++;
      k++;
  }   
}

void printList(int L[], int size)
{ 
  int i; 
  for (i = 0; i < size; i++) 
    printf("%d ", L[i]); 
  printf("\n"); 
} 