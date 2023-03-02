#include <algorithm>
#include <ctime>
#include <iostream>
using namespace std;

// 随机数种子
//  srand((unsigned int)time(NULL));
//  int numRand = rand()%100 + 1;//0-99
//  int num = 0;

template <class T>
int getArrayLength(T &array) {
  return (sizeof(array) / sizeof(array[0]));
}

void swapArray(int *arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void selectionSort(int *arr, int length) {
  if (arr == NULL || length < 2) {
    return;
  }
  for (int i = 0; i < length - 1; i++)  // i ~ N-1
  {
    int minIndex = i;
    for (int j = i + 1; j < length; j++)  // i ~ N-1上找最小值的下标
    {
      minIndex = arr[j] < arr[minIndex] ? j : minIndex;
    }
    swapArray(arr, i, minIndex);  // swap
  }
}

void printArr(int *arr, int length) {
  for (int i = 0; i < length; i++) {
    /* code */
    cout << arr[i] << endl;
  }
}

// for test
void comparator(int *arr, int length) { 
    sort(arr, arr + length);
}

int main() {
  int arr[] = {3, 5, 1, 8, 6, 5, 9, 2};
  selectionSort(arr, getArrayLength(arr));
  printArr(arr, getArrayLength(arr));
//   comparator(arr,getArrayLength(arr));
//   printArr(arr, getArrayLength(arr));
}