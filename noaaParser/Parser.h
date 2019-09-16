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

	public:
		Parser() {};
		void parseFile(string filename);
		string trim(string& line, int& whitespaceCount);
};

