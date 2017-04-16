/*
  Given two sorted array of integers of size N and M.
  Find the k st smallest element of the union of these arrays.
  Baidu Search Engine
*/

#include <iostream>
using namespace std;

class Solution{
  public:
    int solution(int[] N, int [] M,int k){
      int i = k/2;
      int j = k - i;
      int step = k/4;
      while (step > 0){
        if (N[i-1] > M[j-1]){
          i -= step;
          j += step;
        }
        else{
          i += step;
          j -= step;
        }
        step /= 2;
      }

      if (N[i-1] > M[j-1]){
        return N[i-1];
      }
      else{
        return M[j-1];
      }

    }
}
