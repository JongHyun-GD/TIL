#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

typedef struct s_node
{
	int		left;
	int		right;
}			Node;

int N;
vector<Node> tree;

void preorder(int root)
{
	cout << (char)('A' + root);
	if (tree[root].left != -1)
		preorder(tree[root].left);
	if (tree[root].right != -1)
		preorder(tree[root].right);
}

void inorder(int root)
{
	if (tree[root].left != -1)
		inorder(tree[root].left);
	cout << (char)('A' + root);
	if (tree[root].right != -1)
		inorder(tree[root].right);
}

void postorder(int root)
{
	if (tree[root].left != -1)
		postorder(tree[root].left);
	if (tree[root].right != -1)
		postorder(tree[root].right);
	cout << (char)('A' + root);
}

int	main(void)
{
	cin.tie(0);
	char c, l, r;
	int i, root, left, right;
	tree = vector<Node>(26);
	cin >> N;
	for (i=0;i<N;++i)
	{
		cin >> c >> l >> r;
		root = c - 'A';
		left = l != '.' ? l - 'A' : -1;
		right = r != '.' ? r - 'A' : -1;
		tree[root].left = left;
		tree[root].right = right;
	}
	preorder(0);
	cout << "\n";
	inorder(0);
	cout << "\n";
	postorder(0);
	cout << "\n";
	return (0);
}
