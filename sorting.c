#include  <stdio.h>
#include "sorting.h"
#include <stdbool.h>
#include <math.h>
void swap(long *xp, long *yp);
void Save_Seq1 (char *Filename, int N);
void Save_Seq2 (char *Filename, int N);
int getGap(int gap);
int cmpfunc(const void * a, const void * b);

//save_seq need to be called by anything?

void Save_Seq1 (char *Filename, int N)
{
  FILE * pFile;
  pFile = fopen (Filename,"w");
  int *arr = malloc(sizeof(int) * N);
  int ix= 0;
  int pow2, pow3 = 1;
  while(pow3 <= N)
  {
      pow2 = pow3;
      while(pow2 <= N)
      {
        arr[ix] = pow2;
        pow2 = pow2 * 2;
        ix++;
      }
      pow3 = pow3 * 3;
  }
  arr[ix] = '\0';
  qsort(arr, ix, sizeof(int), cmpfunc);
  for(ix=0;arr[ix]!='\0';ix++)
  {
    fprintf(pFile, "%d\n", arr[ix]);
  }
  fclose(pFile);
}

void Save_Seq2 (char *Filename, int N)
{
  FILE * pFile;
  pFile = fopen (Filename,"w");
  int arr[N], i = 0;
  int gap = N;
  while (gap != 1)
  {
      gap = getGap(gap);
      arr[i] = gap;
      i++;
  }
  arr[i] = '\0';
  qsort(arr, i, sizeof(int), cmpfunc);
  for(i = 0;arr[i] != '\0';i++)
  {
    fprintf(pFile, "%d\n", arr[i]);
  }
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
  qsort(arr, ix, sizeof(int), cmpfunc);
  int gap, i;
  for (gap = arr[ix-1]; gap > 0; gap = arr[ix-1])
  {
      for (i = gap; i < Size; i += 1)
      {
          long temp = Array[i]; 
          *NMove+=1;
          int j;         
          for (j = i; j >= gap && Array[j - gap] > temp; j -= gap)
          {
              Array[j] = Array[j - gap];
              *NMove+=1;
              *NComp+=1;
          }
          if(j >= gap)
          {
            *NComp+=1;
          }
          Array[j] = temp;
          *NMove+=1;
      }
      ix--;
  }
  free(arr);
  return;
}
int getGap(int gap)
{
    gap = (gap*10)/13;
    if (gap < 1)
        return 1;
    else if((gap == 10) || (gap == 9))
    {
      return 11;
    }
    return gap;
}
void Improved_Bubble_Sort(long *Array, int Size, double *NComp, double *NMove)
{
    int gap = Size;
    bool s = true;
    while (gap != 1 || s == true)
    {
        gap = getGap(gap);
        s = false;
        for (int i=0; i<Size-gap; i++)
        {
            *NComp+=1;
            if (Array[i] > Array[i+gap])
            {
                swap(&Array[i], &Array[i+gap]);
                *NMove+=3;
                s = true;
            }
        }
    }
}
void swap(long *xp, long *yp)
{
    *xp ^= *yp;
    *yp ^= *xp;
    *xp ^= *yp;
}

