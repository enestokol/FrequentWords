#include<iostream>
#include<string>
#include<cstdlib>
#include"HashTableBuilder.h"
using namespace std;

HashTableBuilder::HashTableBuilder() {
	for (int i = 0; i < HTSize; i++)
	{
		HashTable[i] = new word;
		HashTable[i]->_word = "";
		HashTable[i]->count = 1;
		HashTable[i]->next = NULL;
	}
}

void HashTableBuilder::FindWordAndAdd(string _word){
	int index = Hash(_word);
	bool foundWord = false;
	word* Ptr = HashTable[index];
	while (Ptr != NULL) {

		if (Ptr->_word == _word) {
			foundWord = true;
			break;
		}
		Ptr = Ptr->next;
	}
	if (foundWord)
		Ptr->count += 1;
	else
		AddWord(_word);
}

void HashTableBuilder::ScanInLinkedListAddBSF(int index){
	word* Ptr = HashTable[index];
	if (Ptr->_word == "") {
		return;
	}
	else {
		while (Ptr != NULL) {
			BST->insert(Ptr->_word, Ptr->count);
			Ptr = Ptr->next;
		}
	}
}

int HashTableBuilder::NumOfWordsIndx(int index){
	int count = 0;
	if (HashTable[index]->_word == "") {
		return count;
	}
	else
	{
		count++;
		word* Ptr = HashTable[index];
		while (Ptr->next != NULL) {
			count++;
			Ptr = Ptr->next;
		}
	}
	return count;
}

void HashTableBuilder::AddWord(string _word){
	int index = Hash(_word);
	if (HashTable[index]->_word == "") {
		HashTable[index]->_word = _word;
	}
	else
	{
		word* Ptr = HashTable[index];
		word* n = new word;
		n->_word = _word;
		n->count = 1;
		n->next = NULL;
		while (Ptr->next != NULL)
		{
			Ptr = Ptr->next;
		}
		Ptr->next = n;
	}
}


int HashTableBuilder::Hash(string key) {
	int hash = 0;
	unsigned int h = 0;
	unsigned int o = 31415;
	const unsigned int t = 27183;
	for (size_t i = 0; i < key.length(); i++)
	{
		h = (o * h + key[i]) % HTSize;
		o = o * t % (HTSize - 1);

	}
	return h;
}


