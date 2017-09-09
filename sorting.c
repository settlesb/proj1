#include  <stdio.h>
#include "sorting.h"
#include <stdbool.h>
#include <math.h>
void swap(long *xp, long *yp);
void Save_Seq1 (char *Filename, int N);
void Save_Seq2 (char *Filename, int N);
int getNextGap(int gap);
int cmpfunc(const void * a, const void * b);

//handle bad file input??
//turnin within ecegrid account, or specifically in git cloned repo??
//gap sequence??
//save function/sequence

void Save_Seq1 (char *Filename, int N)
{
  FILE * pFile;
  pFile = fopen (Filename,"w");
  fprintf(pFile, "");
  fclose(pFile);
}

void Save_Seq2 (char *Filename, int N)
{
  FILE * pFile;
  pFile = fopen (Filename,"w");
  fprintf(pFile, "");
  fclose(pFile);
}

long *Load_File(char *Filename, int *Size)
{
  FILE * pFile;
  pFile = fopen (Filename,"r");
  fscanf(pFile, "%d\n", Size);
  int i = 0;
  long * arr = malloc(sizeof(long) * *Size);
  while(fscanf(pFile, "%ld\n", &arr[i]) == 1)
  {
    i++;
  }
  fclose(pFile);
  return arr;
}
int Save_File(char *Filename, long *Array, int Size)
{
  int i;
  FILE * pFile;
  pFile = fopen (Filename,"w");
  fprintf(pFile, "%d\n", Size);
  for(i = 0;i<Size;i++)
  {
    fprintf(pFile, "%ld\n", Array[i]);
  }
  fclose(pFile);
  return i;
}
int cmpfunc(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
void Shell_Insertion_Sort(long *Array, int Size, double *NComp, double *NMove)
{
  int *arr = malloc(sizeof(int) * Size);
  int ix= 0;
  int pow2, pow3 = 1;
  while(pow3 <= Size)
  {
      pow2 = pow3;
      while(pow2 <= Size)
      {
        arr[ix] = pow2;
        pow2 = pow2 * 2;
        ix++;
      }
      pow3 = pow3 * 3;
  }
  arr[ix] = '\0';
  qsort(arr, ix, sizeof(int), cmpfunc);

  int gap, i;
  for (gap = arr[ix-1]; gap > 0; gap = arr[ix-1])
  {
      for (i = gap; i < Size; i += 1)
      {
          long temp = Array[i];

          int j;            
          for (j = i; j >= gap && Array[j - gap] > temp; j -= gap)
          {
              Array[j] = Array[j - gap];
              *NMove+=1;
              *NComp+=1;
          }
          Array[j] = temp;
      }
      ix--;
  }
  free(arr);
  return;
}
int getNextGap(int gap)
{
    gap = (gap*10)/13;
    if (gap < 1)
        return 1;
    return gap;
}
void Improved_Bubble_Sort(long *Array, int Size, double *NComp, double *NMove)
{
    int gap = Size;
    bool swapped = true;
    while (gap != 1 || swapped == true)
    {
        gap = getNextGap(gap);
        swapped = false;
        for (int i=0; i<Size-gap; i++)
        {
            *NComp+=1;
            if (Array[i] > Array[i+gap])
            {
                swap(&Array[i], &Array[i+gap]);
                *NMove+=1;
                swapped = true;
            }
        }
    }
}
void swap(long *xp, long *yp)
{
    long temp = *xp;
    *xp = *yp;
    *yp = temp;
}

