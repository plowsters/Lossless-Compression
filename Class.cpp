#include <fstream>
#include <iostream>
#include <string>

class compress {

//Public variables and functions
public:
	//Tracks # of words in file
	int numWords[3] = { 0,0,0 };
	
	//List of files available for compression
	std::string fileOptions[3] = {
			"input1.txt",
			"input2.txt",
			"input3.txt"
	};

	//stores a single word in the filestream at a time
	std::string iterateTXT;

	//2D array that stores [unique string][number value]
	std::string **outputTXT;
	std::string *outputTXT = new std::string[2];

	void allocateMemory(std::string** outputTXT) {
		for (int i = 0; i < 2; i++) {
			std::string outputTXT[i] = new std::string[1000];
		}
	}
	

	/*
	The function readFiles opens and reads 3 "input.txt" files
	and stores the number of words in an array numWords[].

	Parameters:
	None

	Returns:
	None
	*/
	void readFiles() {
		std::ifstream inputFile;

		//Note: After making compressFile(), come back and reassign 
		//fileOptions using dynamically allocated array of user input 
		//for filenames.

		//Iterate over each of the three files
		for (int i = 0; i < 3; i++) {
			inputFile.open(fileOptions[i]);
			while (inputFile.is_open()) {
				inputFile >> iterateTXT;
				numWords[i]++;
				if (inputFile.eof()) {
					inputFile.clear();
					inputFile.close();
				}
			}

		}
	}


	//Inc: fix 2D array parameter in func
	bool binarySearch(std::string outputTXT, int numWordsArr[], std::string value, int k) {
		int first = 0,
			last = numWordsArr[k] - 1,
			middle,
			position = -1;
		bool found = false;

		while (!found && first <= last) {
			middle = (first + last) / 2;
			if (outputTXT[k][middle] == value) {
				found = true;
				position = middle;
			}
			else if (outputTXT[k][middle] > value) {
				last = middle - 1;
			}
			else {
				first = middle + 1;
			}
		}
		return found;
	}

	//Inc: call uniqueNumBinarySearch using correct parameters,
	//	if binarySearch == false,
	//		assign uniqueNum_n to outputTXT[1][n] and uniqueWord_n to outputTXT[2][n]
	void numAssign() {
		std::ifstream inputFile;
		for (int i = 0; i < 3; i++)
			inputFile.open(fileOptions[i]);
		while (inputFile.is_open()) {
			inputFile >> iterateTXT;
			if (binarySearch(std::string outputTXT[j][], int numWords[j], std::string iterateTXT, int j ) == false) {

			}
		}
	}
	//Keep track of unique words (assign a number)
	// Create output file with numbers in order of input file
	//Ignore punctuation and newlines

	//Must use file I/O
	//Must use Exception Handling (try, throw, catch)
	//Must have at least 3 different test input files (.txt)
	//Must create a header file, a class source code file, and a main source code file (3 files)
	//Do not use vectors or include libraries such as algorithm.h or vector.h
	//Must use inline and block comments (// and /* */)
	//Function comments go above function declaration

};

int main() {
	compress compressor;
	compressor.readFiles();
}