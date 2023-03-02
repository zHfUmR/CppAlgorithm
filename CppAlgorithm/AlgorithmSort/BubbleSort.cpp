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

void printArr(int *arr, int length) {
  for (int i = 0; i < length; i++) {
    /* code */
    cout << arr[i] << endl;
  }
}

void swapArray(int *arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
 
/*
    异或操作 ：
    1. 0 ^ N = N; N ^ N = 0;
    2.异或满足交换律和结合律；
    3.多个数异或操作，异或先后顺序不影响结果

    a = a ^ b;// a = a ^ b
    b = a ^ b;// b = a ^ b ^ b ==> b = a
    a = a ^ b;// a = a ^ b ^ a ==> a = b

    前提：a和b在内存里是两块独立的区域，值可以一样，a和b指向的内存地址不能相同；
 */
void swap(int *arr, int i, int j) {
  arr[i] = arr[i] ^ arr[j];
  arr[j] = arr[i] ^ arr[j];
  arr[i] = arr[i] ^ arr[j];
}


void bubbleSortArr(int *arr, int len) {
  if (arr == NULL || len < 2) {
    return;
  }
  for (int e = len - 1; e > 0; e--) {
    for (int i = 0; i < e; i++) {
      if (arr[i] > arr[i + 1]) {
        swap(arr, i, i + 1);
        // swapArray(arr, i, i + 1);
      }
    }
  }
}

/*
        冒泡排序 优化一
    */
void BubbleSort1(int *arr, int length)
{
    int i, j, temp;
    bool status = true;
    for (i = 0; (i < length) && (status != false); i++)
    {
        /* code */
        status = false;
        for (j = length - 1; j > i; j--)
        {
            /* code */
            if (*(arr + j) > *(arr + j - 1))
            {
                /* code */
                temp = *(arr + j - 1);
                *(arr + j - 1) = *(arr + j);
                *(arr + j) = temp;
                status = true;
            }
        }
    }
    for (i = 0; i < length; i++)
    {
        /* code */
        cout << *(arr + i) << endl;
    }
}

int main() {
  int arr[] = {3, 5, 1, 8, 6, 5, 9, 2};
  bubbleSortArr(arr, getArrayLength(arr));
  printArr(arr, getArrayLength(arr));
}