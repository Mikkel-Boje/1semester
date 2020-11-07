#include <stdio.h> 
#include <stdlib.h> 

void Merge(int L[], int start, int slut, int midt);
void MergeSort(int L[], int start, int slut);
void printList(int L[], int size);

int main(void){ 
  int L[] = { 5, 3, 8, 1, 6, 10, 7, 2, 4, 9 }; 
  int L_size = sizeof(L) / sizeof(L[0]); 
  	
  printf("Givet listen \n"); 
  printList(L, L_size); 
  
  MergeSort(L, 0, L_size - 1); 
  
  printf("Er den sorterede liste \n"); 
  printList(L, L_size); 
  return 0; 
} 

void Merge(int L[], int start, int slut, int midt){
  /* Start med at kopiere de to dellister ind i to nye lister L1 og L2, så vi ikke sletter nogle elementer fra L når vi begynder at flette elementerne derind */
  L1[5]
  L2[5]
  L1[] = L[]
  /* Herefter skal vi kopiere elementer fra L1 og L2 ind på pladserne i L mellem start og slut men i sorteret rækkefølge */
	
}

void MergeSort(int L[], int start, int slut){

  if(start < slut)
  {
      int m;
      m = (start + slut) / 2;
      MergeSort(L, start, m); 
      MergeSort(L, m + 1, slut);
      for (int i = 0; i < slut; i++)
      {
          L = Merge(L, start, slut, m);
      }
  }
}

void printList(int L[], int size){ 
  int i; 
  for (i = 0; i < size; i++) 
    printf("%d ", L[i]); 
  printf("\n"); 
} 