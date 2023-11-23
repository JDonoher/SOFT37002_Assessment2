#include <string>
#include <iostream>
#include <vector>

struct HashNode {

	//A brick will act like a node, it will contain both strings that represent each symbol on its north and south side
	std::string northSymbol;
	std::string southSymbol;

	//The brick will also have a pointer pointing potentially to another brick in the wall (this happens when there is a collision in the hash table)
	HashNode* next;

	HashNode(std::string n, std::string s) : northSymbol(n), southSymbol(s), next(nullptr) {}
};
class HashTable {
	
	private:
		const int hashingValue;
		HashNode** HTable;
		int performHashing(std::string);

	public:
		HashTable(int);
		void insert(std::string, std::string);
		HashNode* lookupViaKey(std::string);
		HashNode* lookupViaValue(std::string);
};
