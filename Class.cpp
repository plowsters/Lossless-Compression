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

	//string of punctuation marks used to remove punctuation from
	//iterateTXT before storing in array
	std::string punctuationMarks = "!.,\"?;:()";

	//unique strings are stored in outputTXT, their number
	//assignment is stored in uniqueNum
	std::string outputTXT[5000];
	int uniqueNum[5000];
	

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


	//searches array for a matching string
	bool linearSearch(std::string arr[], int numWordsArr[], std::string value, int k) {
		int index = 0;
		bool found = false;

		while (!found && index < numWordsArr[k]) {
			if (arr[index] == value) {
				found = true;
			}
			index++;
		}
		return found;
	}

	//Inc: call linearSearch using correct parameters,
	//	if linearSearch == false,
	//		assign uniqueNum_n to outputTXT[1][n] and uniqueWord_n to outputTXT[2][n]
	void numAssign() {
		std::ifstream inputFile;
		int wordCounter = 0;
		for (int i = 0; i < 3; i++) {
			inputFile.open(fileOptions[i]);
			while (inputFile.is_open()) {
				inputFile >> iterateTXT;
				for (char punctuation : punctuationMarks) {
					iterateTXT.erase(remove(iterateTXT.begin(), iterateTXT.end(), punctuation), iterateTXT.end());
				}
				if (linearSearch(outputTXT, numWords, iterateTXT, i) == false) {
					outputTXT[wordCounter] = iterateTXT;
					uniqueNum[wordCounter] = wordCounter + 1;
					std::cout << outputTXT[wordCounter] + " ";
					wordCounter++;
				}
				if (inputFile.eof()) {
					inputFile.clear();
					inputFile.close();
				}
			}
		}
		int r = 0;;
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
	compress cmp;
	cmp.readFiles();
	cmp.numAssign();
	return 0;
}