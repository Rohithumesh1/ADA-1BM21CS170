#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int a[], int low, int high) {

  int pivot = a[high];
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (a[j] <= pivot) {
            i++;

      swap(&a[i], &a[j]);
    }
  }


  swap(&a[i + 1], &a[high]);

  return (i + 1);
}

void quickSort(int a[], int low, int high) {
  if (low < high) {
        int pivot = partition(a, low, high);
        quickSort(a, low, pivot - 1);
        quickSort(a, pivot + 1, high);
  }
}


int main() {
  int i,n,start,end;
  int a[100000];
  double sortTime;

  printf("Enter the number of elements:");
  scanf("%d",&n);


  for(i=0; i<n; i++){
    a[i] = rand();
  }
    start = clock();

  quickSort(a, 0, n- 1);

  end = clock();
  printf("Sorted :-\n");
    for(i=0;i<n;i++)
    {
         printf("%d) %d \n", i+1,a[i]);
    }
    printf("\n");

    sortTime = (double)(end-start)/(CLOCKS_PER_SEC);
    printf("\nTotal time taken %lfs\n", sortTime);

  return 0;
}
