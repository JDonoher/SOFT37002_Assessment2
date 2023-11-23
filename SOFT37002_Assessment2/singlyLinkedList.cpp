#include <iostream>
#include "singlyLinkedList.h"

using namespace std;

QueueNode::QueueNode(HashNode* h, QueueNode* p) {
	northSymbol = h->northSymbol;
	southSymbol = h->southSymbol;
	next = p;
}

QueueNode::QueueNode(std::string north, std::string south, QueueNode* n = nullptr)
{
	northSymbol = north;
	southSymbol = south;
	next = n;
}

ResultList::ResultList(HashTable* northT, HashTable* southT) {
	northTable = northT;
	southTable = southT;
	head = nullptr;
	tail = nullptr;
	size = 0;
}

ResultList::~ResultList() {
	QueueNode* c = head;
	while (c != nullptr) {
		head = head->next;
		delete c;
		c = head;
	}
	head = nullptr;
}

void ResultList::insertAtFront(QueueNode* b) {
	b->next = head;
	head = b;
	if (!tail) {
		tail = head;
	}
}

void ResultList::insertAtEnd(QueueNode* b) {
	if (!head) {
		head = b;
		tail = b;
		return;
	}
	tail->next = b;
	tail = b;
}

void ResultList::show() {
	if (head == nullptr) {
		std::cout << "Empty list, starting brick not in list or file empty." <<std::endl;
	}
	else {
		QueueNode* p = head;
		while (p != nullptr) {
			cout << p->northSymbol;
			if (p->next != nullptr)
				cout << "\n";
			p = p->next;
		}
	}
}

void ResultList::generateSequence(std::string startingNorth, std::string startingSouth) {
	searchEast(startingNorth);
	//Accounting for last brick
	if (head != tail) {
		QueueNode* node = new QueueNode(tail->southSymbol, "No symbol!!");
		tail->next = node;
		tail = node;
	}
	searchWest(startingNorth);
}


void ResultList::searchEast(std::string currentSymbol)
{
	HashNode* currentBrick = northTable->lookupViaKey(currentSymbol);
	while (currentBrick != nullptr) {
		QueueNode* newNode = new QueueNode(currentBrick, nullptr);
		insertAtEnd(newNode);
		currentBrick = northTable->lookupViaKey(newNode->southSymbol);
	}
	delete currentBrick;
}

void ResultList::searchWest(std::string currentSymbol)
{
	HashNode*  currentBrick = southTable->lookupViaKey(currentSymbol);
	while (currentBrick != nullptr) {
		QueueNode* newNode = new QueueNode(currentBrick, nullptr);
		std::string tmp = newNode->northSymbol;
		newNode->northSymbol = newNode->southSymbol;
		newNode->southSymbol = tmp;
		if (newNode->northSymbol != head->northSymbol) {
			insertAtFront(newNode);
		}
		currentBrick = southTable->lookupViaKey(newNode->northSymbol);
	}
	delete currentBrick;
}