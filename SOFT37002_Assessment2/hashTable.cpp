#include "hashTable.h"

int HashTable::performHashing(std::string key) {
	//Need to convert the string into an int, do this by using ASCII value of each char in string with an arbitry multiplier, for uniqueness
	 long long unsigned int stringValue = 0;
	 for (char character : key) {
		 stringValue = (stringValue * 11) + character;
	 }
	 return (stringValue % hashingValue);
}

HashTable::HashTable(int h = 100) : hashingValue(h)
{
	if (hashingValue <= 0) {
		throw std::invalid_argument("Hashing value must be greater than 0!");
	}
	//Set the hashing value and size of map to provided number. Ideally this would be the size of the input
	HTable = new HashNode*[hashingValue];
	for (int i = 0; i < hashingValue; i++) {
		HTable[i] = nullptr;
	}
}


void HashTable::insert(std::string northSymbol, std::string southSymbol) {
	//Turn the key into a hash value, this will be the index for the table. For this problem the north symbol for each brick will act as the key. 
	long long unsigned int keyHash = performHashing(northSymbol);
	HashNode* newBrick = new HashNode(northSymbol, southSymbol);
	//We now have two cases, the index isint occupied, so enter the new brick at the empty bucket, or the index is already occupied (collision)
	//In the event of a collision the new node needs to be added to the list
	if (HTable[keyHash] == nullptr) {
		HTable[keyHash] = newBrick;
	} else {
		//Account for overwrite
		if (HTable[keyHash]->northSymbol == newBrick->northSymbol) {
			HTable[keyHash]->southSymbol = southSymbol;
		}
		else {
			newBrick->next = HTable[keyHash];
			HTable[keyHash] = newBrick;
		}
	}
}

HashNode* HashTable::lookupViaKey(std::string northSymbol) {
	//Turn the key into a hash value, this will be the index for the table. For this problem the north symbol for each brick will act as the key. 
	long long unsigned int keyHash = performHashing(northSymbol);
	//Look for brick at the index of the hashing value of the north symbols name
	try {
		HashNode* currentBrick = HTable[keyHash];
		while (currentBrick != nullptr) {
			if (currentBrick->northSymbol == northSymbol) {
				break;
			}
			currentBrick = currentBrick->next;
		}
		return currentBrick;
	}
	catch (const std::exception& e){
		return nullptr;
	}
}

HashNode* HashTable::lookupViaValue(std::string s)
{
	for (int i = 0; i < hashingValue; i++) {
		HashNode* currentBrick = HTable[i];
		//Have to search through each bucket
		while (currentBrick != nullptr) {
			if (currentBrick->southSymbol == s) {
				return currentBrick;
			}
			currentBrick = currentBrick->next;
		}
	}
	return nullptr;
}

