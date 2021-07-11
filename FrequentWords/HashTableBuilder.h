#pragma once
#include<iostream>
#include<string>
#include<cstdlib>
#include "BinarySearchTree.h"
using namespace std;

struct word {
	string _word;
	int count;
	word* next;
};

class HashTableBuilder {
private:
	static const int HTSize = 250007;
	//int *HTable; 
	//int *indexStatusList; 
	//int length;
	word* HashTable[HTSize];
public:
	HashTableBuilder();
	BinarySearchTree* BST;
	int Hash(string ); 
	void AddWord(string ); 
	int NumOfWordsIndx(int ); 
	void ScanInLinkedListAddBSF(int ); 
	void FindWordAndAdd(string ); 
	//~hashT();
	//void print() const;
	//void remove(int hashIndex, const int& rec);
	//void retrieve(int hashIndex, int& rec) const;
	//bool isItemAtEqual(int hashIndex, const int& rec) const;
	//void search(int& hashIndex, const int& rec, bool& found) const;
};