#include "Parser.h"

void Parser::parseFile(ifstream& is)
{
	ofstream os;

	if (printFile) {
		os.open("outfile.txt");
	}

	string line;
	
	getline(is, line);

	// parse each block (Header and Data Records)
	while (line.length() >= 71 && line[0] == '#') {
		Header header(line);
		getline(is, line);

		vector<Data_Record> drVec(header.getNum_levels());

		for (int i = 0; i < header.getNum_levels(); i++) {
			drVec[i] = Data_Record(line);
			getline(is, line);
		}

		Data_Block db(header, drVec);

		data.push_back(db);
		
		if (printFile) {
			db.fileOut(os);
			//db.coutData_Block();
		}
	}

	os.close();
	
}

string Parser::trim(string& line, int& whitespaceCount)
{
	whitespaceCount = 0;
	
	int index = 0;
	char* charTmp = new char[line.length() + 1]; // Note: this 10000 is too arbitrary
	int charCount = 0;

	// skip white space
	while (isspace(line[index])) {
		index++;
		whitespaceCount++;
	}

	while (!isspace(line[index]) && index < line.length()) {
		charTmp[charCount] = line[index];
		index++;
		charCount++;
	}

	// Terminate char array
	charTmp[charCount] = '\0';

	line.erase(0,index);
	
	string output(charTmp);

	delete[] charTmp;
	
	return output;
}
