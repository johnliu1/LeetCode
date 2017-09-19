#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		
		unordered_map<string, vector<string>> map;
		//create a map, key is sorted string, value is a string vector of all possible combination
		for (vector<string>::iterator iter = strs.begin(); iter != strs.end(); iter++)
		{
			string val(*iter);
			std::sort(val.begin(), val.end());
			map[val].push_back(*iter);
		}
		//transfer the format of map to vector<vector<string>> 
		vector<vector<string>> collection;
		for (auto m : map)
			collection.push_back(m.second);

		return collection;
	}
};


int main()
{
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };

	Solution temp;
	vector<vector<string>> hello = temp.groupAnagrams(strs);
	for (auto m : hello)
	{
		std::cout << std::endl;
		for (auto a : m)
			std::cout << a<<" ";
	}
}