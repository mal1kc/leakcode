#include <stdio.h>

void mergeSortedArrays_v0(int *arr1, int arr1Size, int m, int *arr2,
                          int arr2Size, int n) {
  int i = arr1Size;
  m--;
  n--;
  for (i = arr1Size - 1; i >= 0; i--) {
    if (n >= 0 && (m < 0 || arr2[n] >= arr1[m])) {
      arr1[i] = arr2[n];
      n--;
    } else {
      arr1[i] = arr1[m];
      m--;
    }
  }
}

void mergeSortedArrays_v1(int *arr1, int arr1Size, int m, int *arr2,
                          int arr2Size, int n) {
  int i = 0, j = 0, k;
  while (j < n) {
    if (arr1[i] > arr2[j] || (arr1[i] == 0 && i >= m)) {
      k = arr1Size - 1;
      while (k > i) {
        arr1[k] = arr1[k - 1];
        k--;
      }
      arr1[i] = arr2[j];
      m++, j++;
    }
    i++;
  }
}
int main(int argc, char *argv[]) {

  int arr1[] = {1, 2, 3, 0, 0, 0};
  int arr2[] = {2, 5, 6};
  int arr1Size = sizeof(arr1) / sizeof(arr1[0]);
  int arr2Size = sizeof(arr2) / sizeof(arr2[0]);
  int m = arr1Size - arr2Size;
  int n = arr2Size;

  printf("call mergeSortedArrays(arr1, %d, %d, arr2, %d, %d)\n", arr1Size, m,
         arr2Size, n);
  mergeSortedArrays_v0(arr1, arr1Size, m, arr2, arr2Size, n);
  for (int i = 0; i < arr1Size; i++) {
    printf("%d ", arr1[i]);
  }

  int arr3[] = {1};
  int arr4[] = {};

  int arr3Size = sizeof(arr3) / sizeof(arr3[0]);
  int arr4Size = sizeof(arr4) / sizeof(arr4[0]);

  m = arr3Size - arr4Size;
  n = arr4Size;

  printf("\ncall mergeSortedArrays(arr3, %d, %d, arr4, %d, %d)\n", arr3Size, m,
         arr4Size, n);
  mergeSortedArrays_v0(arr3, arr3Size, m, arr4, arr4Size, n);
  for (int i = 0; i < arr3Size; i++) {
    printf("%d ", arr3[i]);
  }

  int arr5[] = {0};
  int arr6[] = {1};

  int arr5Size = sizeof(arr5) / sizeof(arr5[0]);
  int arr6Size = sizeof(arr6) / sizeof(arr6[0]);

  m = 0;
  n = 1;

  printf("\ncall mergeSortedArrays(arr5, %d, %d, arr6, %d, %d)\n", arr5Size, m,
         arr6Size, n);
  mergeSortedArrays_v0(arr5, arr5Size, m, arr6, arr6Size, n);
  for (int i = 0; i < arr5Size; i++) {
    printf("%d ", arr5[i]);
  }

  printf("\n");
  return 0;
}
