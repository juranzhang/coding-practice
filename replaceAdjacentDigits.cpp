/*
You are given an integer X. You must choose two adjacent digits and replace them with the larger of these two digits.

For example, from the integer X = 233614, you can obtain:
33614 (by replacing 23 with 3);
23614 (by replacing 33 with 3 or 36 with 6);
23364 (by replacing 61 with 6 or 14 with 4);

You want to find the smallest number that can be obtained from X by replacing two adjacent digits with the larger of the two. In the above example, the smallest such number is 23364.

Write a function:

class Solution {public int solution (int X);}
that, given a positive integer X, returns the smallest number that can be obtained from X by replacing two adjacent digits with the larger of the two.

For example, given X = 233614, the function should return 23364, as explained above.

Assume that:

X is an integer within the range [10..1,000,000,000].
In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.
*/

#include <iostream>
using namespace std;

class Solution{
	public:
		int solution(int x){
			int prev_dig = x%10;
			int next_dig = 0;
			int remaining = x/10;
			int mul = 1;
			int prev_num = 0;
			int cur_num = prev_dig;
			while(remaining>0){
				next_dig = remaining%10;
				int bigger_dig = next_dig;
				if(prev_dig > next_dig){
					bigger_dig = prev_dig;
				}
				int replace1 = bigger_dig * mul + prev_num;
				int replace2 = cur_num + next_dig * mul;

				cur_num = replace2;
				if(replace1<replace2){
					cur_num = replace1;
				}
				prev_num = prev_num + prev_dig * mul;
				prev_dig = next_dig;
				mul = mul*10;
				remaining = remaining / 10;
			}
			return cur_num;
		}
};

int main(){
	cout<<"Please input an integer number:"<<endl;
	int x;
	cin>>x;
	Solution res;
	int output = res.solution(x);
	cout<<"The smallest number is "<<output<<endl;
	return 0;
}

