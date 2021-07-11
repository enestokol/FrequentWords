#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct treeNode{
	treeNode* llink; //left
	treeNode* rlink; //right
	string data;
	int count;
};

class BinarySearchTree{
private:
	treeNode* root;
public:
	BinarySearchTree();
	//~BinaryTree();
	int counter;
	bool isEmpty();
	//int max(int, int);
	//treeNode* getRoot();
	//int height(treeNode* p);
	//int nodeCount(treeNode* p);
	void print_inorder();
	void print(treeNode* p);
	void insert(string &, int&);
	bool printWithoutStopWords(treeNode* p);
	void stopWordsFileParse();
};
