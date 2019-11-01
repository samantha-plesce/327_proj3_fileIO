/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include <vector>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace KP_FileIO;
using namespace std;

//trys to open filename, and return its contents in contents
	//it will strip out only \n's (char return\line feed)
	//returns:
	//SUCCESS all worked, contents string contains all in the file
	//COULD_NOT_OPEN_FILE_TO_READ contents string is cleared
int getFileContents(const std::string &filename, std::string &contents)
{
	ifstream file;
	file.open(filename.c_str(), ios::in);
	if (!file.is_open())
		return COULD_NOT_OPEN_FILE_TO_READ;

	string line;
	while (!file.eof()){
		getline(file, line);
		contents += line;
	}
	file.close();
	if (contents.empty())
		return COULD_NOT_OPEN_FILE_TO_READ;

	return SUCCESS;
}

//trys to open filename, and serialize  myEntryVector contents to it
	//returns:
	//SUCCESS all worked, filename contains myEntryVector strings
	//COULD_NOT_OPEN_FILE_TO_WRITE
int writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector)
{
	int i = 0;
	fstream file;
	file.open(filename, ios::out);

	if (!file.is_open())
		return COULD_NOT_OPEN_FILE_TO_WRITE;

	while (i < myEntryVector.size()){
		file << myEntryVector[i];
	}
	if (myEntryVector.empty())
		return COULD_NOT_OPEN_FILE_TO_WRITE;


	file.close();
	return SUCCESS;
}


