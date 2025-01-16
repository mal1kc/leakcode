#include <stdio.h>

void duplicateZeros(int *arr, int arrSize) {
  int i = 0;
  int j = 0;
  int tempArr[arrSize];
  for (i = 0; i < arrSize; i++)
    tempArr[i] = arr[i];
  for (i = 0; i < arrSize; i++) {
    arr[i] = tempArr[j];
    if (arr[i] == 0 && i < arrSize - 1) {
      arr[i + 1] = 0;
      i++;
    }
    j++;
  }
}
int main(int argc, char *argv[]) {

  int arr[] = {1, 0, 2, 3, 0, 4, 5, 0};
  int arrSize = sizeof(arr) / sizeof(arr[0]);
  duplicateZeros(arr, arrSize);
  int i = 0;
  for (i = 0; i < arrSize; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}
