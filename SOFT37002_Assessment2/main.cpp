#include "singlyLinkedList.h"
#include <fstream>
#include <sstream>

int main(int argc, char* argv[]) {
	std::cout << "Program name: " << argv[0] << std::endl;
	HashTable northTable(100000);
	HashTable southTable(100000);
	std::string filePath;
	std::string firstBrickNorth;
	std::string firstBrickSouth;
	// Read file, but taking the first line in the file as the starting point for the algorithm
	std::string line;
	if (argc > 1) {
		filePath = argv[1];
	}
	if(filePath.empty()){
		std::cout << "No file has been provided!\nPlease provide a path as a command line argument." << std::endl;
	}
	if (!filePath.empty()) {
		std::cout << "Reading file from provided path: " << filePath << std::endl;
		std::ifstream file(filePath);
		if (file.is_open()) {
			std::cout << "File open" << std::endl;
			// Use an istringstream to split the line at the comma
			// Read the first line and create a pair of strings
			if (std::getline(file, line)) {
				std::stringstream stringStream(line);
				if (std::getline(stringStream, firstBrickNorth, ',') && std::getline(stringStream, firstBrickSouth)) {
					// Insert the first key-value pair into the table
					std::cout << "First brick: " << firstBrickNorth << " Second brick: " << firstBrickSouth << std::endl;
					northTable.insert(firstBrickNorth, firstBrickSouth);
					southTable.insert(firstBrickSouth, firstBrickNorth);
				}
			}
			std::cout << "##### Loading bricks into maps #####" << std::endl;
			while (std::getline(file, line)) {
				std::string firstPart, secondPart;
				std::istringstream inStream(line);
				// Read the two strings separated by a comma
				if (std::getline(inStream, firstPart, ',') && std::getline(inStream, secondPart)) {
					northTable.insert(firstPart, secondPart);
					southTable.insert(secondPart, firstPart);
				}
				else {
					// Handle the case where the line doesn't contain a comma
					std::cerr << "Error: Line does not contain a comma: " << line << std::endl;
				}
			}
		}

		ResultList results = ResultList(&northTable, &southTable);
		results.generateSequence(firstBrickNorth, firstBrickSouth);
		results.show();
	}
 }