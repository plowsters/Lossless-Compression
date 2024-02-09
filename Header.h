#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <fstream>
#include <string>

class compress {
public:
	compress();
	//Total word count for each input file
	int numWords[3];
	//Total # of unique words
	int wordCounter[3];
	//Displays which input/output files are available for compression
	std::string inputFileOptions[3];
	std::string outputFileOptions[3];
	//Stores a single string and iterates over entire input file
	std::string iterateTXT;
	//Stores punctuation to be removed from strings
	std::string punctuationMarks;
	//Stores every word from input files to be compressed later
	std::string outputTXT[3][3000];
	//Stores each unique word along with an identifying number
	std::string uniqueWords[3][3000];
	int uniqueNum[3][3000];
	
	/*
	The function readFiles opens and reads 3 "input.txt" files
	and stores the number of words in an array numWords[].

	Parameters:
	None

	Returns:
	None
	*/
	void readFiles();

	/*
	The function writeFiles creates 3 "output.txt" files
	and writes a series of unique numbers corresponding to
	the words from the previous input files.

	Parameters:
	None

	Returns:
	None
	*/
	void writeFiles();

	/*
	The function linearSearch searches the array of unique words
	to determine the position of a given word.

	Parameters:
	std::string arr[][3000] -- Array of unique words
	int wordCount -- # of total words in array
	std::string value -- the word that is being searched for
	int k -- The input file currently in use (0,1, or 2)

	Returns:
	Position of word in arr[k][position]
	*/
	int linearSearch(std::string arr[][3000], int wordCount, std::string value, int k);
};
#endif