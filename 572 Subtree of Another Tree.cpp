
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

private:
	string _s = "";
	string _t = "";

	void preorder(TreeNode* s, string& str) {
		if (s == NULL)
		{
			str += "N";
			return;
		}
		string str_temp = "," + std::to_string(s->val);
		str += str_temp;
		preorder(s->left, str);
		preorder(s->right, str);
	}

public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		_s = "";
		_t = "";
		preorder(s, _s);
		preorder(t, _t);

		if (_s.find(_t) == string::npos)
			return 0;
		else
			return 1;

	}
	void print(TreeNode *s)
	{
		_s = "";
		preorder(s, _s);
		cout << _s << endl;
	}
};


int main(int argc, const char * argv[]) {
	TreeNode *node1 = new TreeNode(2);
	node1->left = new TreeNode(1);
	node1->right = new TreeNode(3);
	node1->left->left = new TreeNode(4);

	Solution temp;
	temp.print(node1);
	TreeNode *node2 = new TreeNode(1);
	node2->left = new TreeNode(4);
	temp.print(node2);

	cout << temp.isSubtree(node1, node2);

	return 0;
}

