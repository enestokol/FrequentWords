#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "CSVParser.h"
#include <string.h>

using namespace std;

CSVParser::CSVParser() {
}

string CSVParser::stripText(string& text) {
	string tempText;
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] == ' ' || text[i] == 0x27 || text[i] > '/' && text[i] < ':' || text[i] > '@' && text[i] < '[' || text[i] > '`' && text[i] < '{')
		{
			if (text[i] <= 'Z' && text[i] >= 'A')
				text[i] += 32;
			tempText += text[i];
		}
	}
	return tempText;
}

void CSVParser::splitIntoWordsAndAdd(string& n){
	string word = "";
	char* text = (char*)n.c_str();
	char* fText = NULL;
	char* remainingText = NULL;
	char  key[] = "\"  ";
	fText = strtok_s(text, key, &remainingText);
	while (fText != NULL)
	{
		word = fText;
		hashTable->FindWordAndAdd(word);
		fText = strtok_s(NULL, key, &remainingText);
	}
}
void CSVParser::StartParse(){
	ifstream data("training.1600000.processed.noemoticon.csv");
	string key = "\",\"";
	string line;

	while (getline(data, line))
	{
		string text = line.substr(line.rfind(key) + 2);
		splitIntoWordsAndAdd(stripText(text));
	}
}
