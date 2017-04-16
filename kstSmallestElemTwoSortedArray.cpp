/*
  Given two sorted array of integers of size N and M.
  Find the k st smallest element of the union of these arrays.
*/

#include <iostream>
using namespace std;

class Solution{
  public:
    int solution(int[] a, int [] b,int k){
      int i = k/2;
      int j = k - i;
      int step = k/4;
      while (step > 0){
        if (a[i-1] > b[j-1]){
          i -= step;
          j += step;
        }
        else{
          i += step;
          j -= step;
        }
        step /= 2;
      }

      if (a[i-1] > b[j-1]){
        return a[i-1];
      }
      else{
        return b[j-1];
      }

    }
}
