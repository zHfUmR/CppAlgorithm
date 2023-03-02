#include <algorithm>
#include <ctime>
#include <iostream>
using namespace std;

template <class T>
int getArrayLength(T &array) {
  return (sizeof(array) / sizeof(array[0]));
}
/*
    异或操作 ：
    1. 0 ^ N = N; N ^ N = 0; - 相同为0，不同为1，无进位相加
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
/*
    一个数组，一种数出现奇数次，其余偶数次
 */
void printOddTimesNum1(int *arr, int len) {
  int eor = 0;
  for (int i = 0; i < len; i++) {
    /* code */
    eor ^= arr[i];
  }
  cout << eor << endl;
}

/*
    一个数组，两种数a，b出现奇数次，其余偶数次,a != b,
    eor ^ [] ==> eor = a ^ b ==> eor的某一位上不等于0, eor != 0
    a的某一位和b的某一位上一定不相同，根据这个分类数组，第一类：某一位为1的数
   ，第二类：某一位为0的数 eor' 只让异或数组中某一位不是1的数 eor' = a | b
 */
void printOddTimesNum2(int *arr, int len) {
  int eor = 0;
  for (int i = 0; i < len; i++) {
    /* code */
    eor ^= arr[i];
  }
  /*
    eor = a ^ b
    eor != 0
    eor 必然有一个位置上是1
   */
  int rightOne = eor & (~eor + 1);  // 提取最右的1
  /*
    eg :
    eor     1010111100
    ~eor    0101000011
    ~eor+1  0101000100
    &eor    0000000100
   */

  int onlyOne = 0;  // eor'
  for (int i = 0; i < len; i++) {
    if ((arr[i] & rightOne) == 0) {  //==rightOne
      onlyOne ^= arr[i];
    }
  }
  cout << "onlyOne = " << onlyOne << " "
       << "eor ^ onlyOne = " << (eor ^ onlyOne) << endl;
}

int main() {
  int arr1[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4};
  printOddTimesNum1(arr1, getArrayLength(arr1));
  int arr2[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5};
  printOddTimesNum2(arr2, getArrayLength(arr2));
}
