#include<bits/stdc++.h>
using namespace std;
int PreIn2Post(string Preorder, string Inorder)
{
	int length = Preorder.length();
	if (length == 0)return 0;
	char Root = Preorder[0];
	int i = 0;
	for (; i < length; i++)
	{
		if (Root == Inorder[i])
			break;
	}
	PreIn2Post(Preorder.substr(1, i), Inorder.substr(0, i));
	PreIn2Post(Preorder.substr(i + 1, length), Inorder.substr(i + 1, length));
	cout << Root;
	return 0;
}
int main()
{
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0)
			break;
		string Preorder, Inorder;
		cin >> Preorder >> Inorder;
		PreIn2Post(Preorder, Inorder);
		cout << endl;
	}
	return 0;
}
