#include <string>
#include <iostream>
#include <fstream>
#include "HashTableBuilder.h"
using namespace std;

class CSVParser {
public:
	CSVParser();
	void StartParse();
	HashTableBuilder* hashTable;
	string innerText;
private:
	string stripText(string&);
	void splitIntoWordsAndAdd(string&);

};

