#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include "CSVParser.h"
#include"HashTableBuilder.h"
#include <time.h>
#include <locale.h>
using namespace std;

int main()
{
	clock_t tStart = clock();

	HashTableBuilder hTable;
	BinarySearchTree BST;
	BST.counter = 10;
	hTable.BST = &BST;
	CSVParser a;
	a.hashTable = &hTable;
	a.StartParse();
	for (int i = 0; i < 250007; i++) {
		hTable.ScanInLinkedListAddBSF(i);
	}
	hTable.BST->stopWordsFileParse();
	hTable.BST->print_inorder();
	
	printf("Total Runtime: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

	system("pause");
	return 0;
}

