#include "header.h"

//Constructor
compress::compress() {
	
	//Initializing variables
	numWords[0] = 0;
	numWords[1] = 0;
	numWords[2] = 0;
	wordCounter[0] = 0;
	wordCounter[1] = 0;
	wordCounter[2] = 0;
	inputFileOptions[0] = "input1.txt";
	inputFileOptions[1] = "input2.txt";
	inputFileOptions[2] = "input3.txt";
	outputFileOptions[0] = "output1.txt";
	outputFileOptions[1] = "output2.txt";
	outputFileOptions[2] = "output3.txt";
	punctuationMarks = "!.,\"?;:()";
}

	void compress::readFiles() {
		std::ifstream inputFile;
		try {
			//Iterate over each of the three files
			for (int i = 0; i < 3; i++) {
				inputFile.open(inputFileOptions[i]);
				//Error Checking
				if (!inputFile.is_open()) {
					throw std::runtime_error("Failed to open input file: " + inputFileOptions[i]);
				}
				while (inputFile >> iterateTXT) {
					//Removes punctuation from words
					for (char punctuation : punctuationMarks) {
						iterateTXT.erase(remove(iterateTXT.begin(), iterateTXT.end(), punctuation), iterateTXT.end());
					}
					//Stores each word in an array
					outputTXT[i][numWords[i]] = iterateTXT;
					numWords[i]++;
					//Values stored in 2D array so that the set of unique words
					//and unique numbers for each input file is stored separately
					if (linearSearch(uniqueWords, numWords[i], iterateTXT, i) < 0) {
						uniqueWords[i][wordCounter[i]] = iterateTXT;
						uniqueNum[i][wordCounter[i]] = wordCounter[i] + 1;
						std::cout << uniqueWords[i][wordCounter[i]] + " ";
						wordCounter[i]++;
					}
					//Checks if there are any more words in the file, closes the file if finished
					if (inputFile.eof()) {
						inputFile.clear();
						inputFile.close();
					}
				}
				
			}
		}
		//Evaluates error message
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;

		}
	}

	void compress::writeFiles() {
		std::ofstream outputFile;
		try {
			//Iterates over each of the three files
			for (int i = 0; i < 3; i++) {
				outputFile.open(outputFileOptions[i]);
				//Error Checking
				if (!outputFile.is_open()) {
					throw std::runtime_error("Failed to open output file: " + outputFileOptions[i]);
				}
				//Print list of unique words
				for (int j = 0; j < wordCounter[i]; j++) {
					outputFile << uniqueNum[i][j] << ": " << uniqueWords[i][j] << std::endl;
				}
				//Loops based on the number of words in each text file
				//To write unique numbers in place of words to output files
				for (int j = numWords[i]; j > 0; j--) {
					iterateTXT = outputTXT[i][numWords[i] - j];
					int identifier = linearSearch(uniqueWords, numWords[i], iterateTXT, i);
					outputFile << uniqueNum[i][identifier] << " ";
				}
				outputFile.close();
			}
		}
		//Evaluates error message
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;

		}
	}

	int compress::linearSearch(std::string arr[][3000], int wordCount, std::string value, int k) {
		int index = 0;
		int position = -1;
		bool found = false;
		while (!found && index < wordCount) {
			if (arr[k][index] == value) {
				found = true;
				position = index;
			}
			index++;
		}
		return position;
	}