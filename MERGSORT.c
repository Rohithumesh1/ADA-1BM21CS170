#include <stdio.h>
#include<time.h>
#define max 10000000

int a[max];
int b[max];

void merging(int low, int mid, int high) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   }

   while(l1 <= mid)
      b[i++] = a[l1++];

   while(l2 <= high)
      b[i++] = a[l2++];

   for(i = low; i <= high; i++)
      a[i] = b[i];
}

void sort(int low, int high) {
   int mid;

   if(low < high) {
      mid = (low + high) / 2;
      sort(low, mid);
      sort(mid+1, high);
      merging(low, mid, high);
   } else {
      return;
   }
}

int main() {
   int i,n;
   clock_t start, end;

  printf("Enter the number of elements: ");
  scanf("%d",&n);

  printf("Enter the numbers\n");
  for(i=0; i<n; i++){
    a[i] = rand();
  }
   start = clock();
   sort(0, n-1);
    end = clock();

   printf("\nList after sorting\n");

   for(i = 0; i <n; i++)
      printf("%d ", a[i]);


   printf("Time taken to sort: %lf", (double)(end-start)/CLOCKS_PER_SEC);
   return 0;
}
