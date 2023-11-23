#include "singlyLinkedList.h"
#include <fstream>
#include <sstream>
#include <chrono>
#include <utility>
#include <iostream>
#include <map>

int main(int argc, char* argv[]) {
	std::cout << "Program name: " << argv[0] << std::endl;
	HashTable northTable = HashTable(100000);
	HashTable southTable = HashTable(100000);
	std::string filePath;
	std::string firstBrickNorth{};
	std::string firstBrickSouth{};
	// Read file, but taking the first line in the file as the starting point for the algorithm
	std::string line;
	if (argc > 1) {
		filePath = argv[1];
	}
	if (filePath.empty()) {
		std::cout << "No file has been provided!\nPlease provide a path as a command line argument." << std::endl;
	}
	if (!filePath.empty()) {
		std::cout << "Reading file from provided path: " << filePath << std::endl;
		std::ifstream file(filePath);
		if (file.is_open()) {
			// Use an istringstream to split the line at the comma
			// Read the first line and create a pair of strings
			if (std::getline(file, line)) {
				std::stringstream ss(line);
				if (std::getline(ss, firstBrickNorth, ',') && std::getline(ss, firstBrickSouth)) {
					// Insert the first key-value pair into the table
					northTable.insert(firstBrickNorth, firstBrickSouth);
					southTable.insert(firstBrickNorth, firstBrickSouth);
				}
			}
			while (std::getline(file, line)) {
				std::string firstPart, secondPart;
				std::istringstream iss(line);
				// Read the two strings separated by a comma
				if (std::getline(iss, firstPart, ',') && std::getline(iss, secondPart)) {
					northTable.insert(firstPart, secondPart);
					southTable.insert(secondPart, firstPart);
				}
				else {
					// Handle the case where the line doesn't contain a comma
					std::cerr << "Error: Line does not contain a comma: " << line << std::endl;
				}
			}
		}

		
		//return 0;
	}
	ResultList results = ResultList(&northTable, &southTable);
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	results.generateSequence(firstBrickNorth, firstBrickSouth);
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::chrono::nanoseconds timeTaken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	std::cout << "Time taken : " << timeTaken.count() << std::endl;

	//results.show();
}