#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include "Data_Block.h"
#include "Data_Record.h"
#include "Header.h"


using namespace std;

class Parser
{
	private:
		vector<Data_Block> data;
		bool printFile;

	public:
		Parser() {};
		Parser(bool printFileIn) { printFile = printFileIn; };
		void parseFile(ifstream& is);
		string trim(string& line, int& whitespaceCount);
};

