#include  <stdio.h>
#include "sorting.h"
void printArray(long arr[], int n);
void swap(long *xp, long *yp);
void Save_Seq1 (char *Filename, int N);
void Save_Seq2 (char *Filename, int N);

void Shell_Insertion_Sort(long *Array, int Size, double *NComp, double *NMove)
{
    int gap, i;
    for (gap = Size/2; gap > 0; gap /= 2)
    {

        for (i = gap; i < Size; i += 1)
        {
            long temp = Array[i];

            int j;            
            for (j = i; j >= gap && Array[j - gap] > temp; j -= gap)
            {
                Array[j] = Array[j - gap];
                NMove++;
                NComp++;
            }
             
            Array[j] = temp;
        }
    }
    return;
}
void Improved_Bubble_Sort (long *Array, int Size, double *NComp, double *NMove)
{
   int i, j;
   for (i = 0; i < Size-1; i++)      
  {
       for (j = 0; j < Size-i-1; j++) 
       {
           if (Array[j] > Array[j+1])
           {
              swap(&Array[j], &Array[j+1]);
              NMove++;
           }
           NComp++;
       }
  }
}
void swap(long *xp, long *yp)
{
    long temp = *xp;
    *xp = *yp;
    *yp = temp;
}

 
void printArray(long arr[], int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("%ld ", arr[i]);
    }
    printf("\n");
}
 
