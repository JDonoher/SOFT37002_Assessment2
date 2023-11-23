#include <exception>
#include "hashTable.h"

struct QueueNode
{
    std::string northSymbol;
    std::string southSymbol;
    QueueNode* next;

    QueueNode(HashNode*, QueueNode*);
    QueueNode(std::string, std::string, QueueNode*);
};

struct ListEmptyException : public std::exception {
    const char* what() const throw () {
        return "The List is empty";
    }
};


class ResultList
{
private:
    HashTable* northTable{};
    HashTable* southTable{};
    QueueNode* head{};
    QueueNode* tail{};
    int size{};
    void searchEast(std::string);
    void searchWest(std::string);

public:
    ResultList(HashTable*, HashTable*);
    void insertAtFront(QueueNode*);
    void insertAtEnd(QueueNode*);
    void show();
    void generateSequence(std::string, std::string);
    ~ResultList();
};