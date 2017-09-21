
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:

	vector<int> productExceptSelf(vector<int>& nums) {

		int size = nums.size();
		if (size == 1)
			return nums;
		
		vector<int> left(size, 1);
		for (int i = 1; i < nums.size(); i++)
			left[i] = left[i - 1] * nums[i-1];

		vector<int> right(size, 1);
		for (int i = size - 2; i >= 0; i--)
			right[i] = right[i + 1] * nums[i + 1];

		vector<int> final(size, 1);
		for (int i = 0; i < size; i++)
			final[i] = left[i] * right[i];

		return final;
	}
};


int main(int argc, const char * argv[]) {


	Solution temp;

	vector<int> intNums = { 2,3,4,5,6 };

	for (auto i : temp.productExceptSelf(intNums))
		cout << i << endl;

	return 0;
}

