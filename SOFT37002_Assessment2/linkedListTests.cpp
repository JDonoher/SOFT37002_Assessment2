#pragma
#include <boost/test/unit_test.hpp>
#include <string>
#include "singlyLinkedList.h"


BOOST_AUTO_TEST_SUITE(ListContstructor) 
	BOOST_AUTO_TEST_CASE(ValidTableConstructor)
	{
		//Arrange
		HashTable* northTestTable = new HashTable(1);
		HashTable* southTestTable = new HashTable(1);

		//Act
		ResultList resultList(northTestTable, southTestTable);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(ListInsertAtFrontTests)
	BOOST_AUTO_TEST_CASE(SingleInsert)
	{
		//Arrange
		HashTable* northTestTable = new HashTable(1);
		HashTable* southTestTable = new HashTable(1);
		ResultList resultList(northTestTable, southTestTable);

		//Act
		resultList.insertAtFront(new QueueNode("North", "South", nullptr));
	}
	BOOST_AUTO_TEST_CASE(SingleInsertAndShow)
	{
		//Arrange
		HashTable* northTestTable = new HashTable(1);
		HashTable* southTestTable = new HashTable(1);
		ResultList resultList(northTestTable, southTestTable);
		std::ostringstream outBuffer;
		std::streambuf* coutConsumer = std::cout.rdbuf(outBuffer.rdbuf());

		//Act
		resultList.insertAtFront(new QueueNode("North", "South", nullptr));
		resultList.show();
		std::cout.rdbuf(coutConsumer);


		//Assert
		BOOST_CHECK_EQUAL(outBuffer.str(), "North");
	}
	BOOST_AUTO_TEST_CASE(MultipleInserts)
	{	
		//Arrange
		HashTable* northTestTable = new HashTable(1);
		HashTable* southTestTable = new HashTable(1);
		ResultList resultList(northTestTable, southTestTable);

		//Act
		resultList.insertAtFront(new QueueNode("North1", "South1", nullptr));
		resultList.insertAtFront(new QueueNode("North2", "South2", nullptr));
		resultList.insertAtFront(new QueueNode("North3", "South3", nullptr));
		resultList.insertAtFront(new QueueNode("North4", "South4", nullptr));
		resultList.insertAtFront(new QueueNode("North5", "South5", nullptr));
		resultList.insertAtFront(new QueueNode("North6", "South6", nullptr));
	}
	BOOST_AUTO_TEST_CASE(MultipleInsertsAndShow)
	{
		//Arrange
		HashTable* northTestTable = new HashTable(1);
		HashTable* southTestTable = new HashTable(1);
		ResultList resultList(northTestTable, southTestTable);
		std::ostringstream outBuffer;
		std::streambuf* coutConsumer = std::cout.rdbuf(outBuffer.rdbuf());

		//Act
		resultList.insertAtFront(new QueueNode("North1", "South1", nullptr));
		resultList.insertAtFront(new QueueNode("North2", "South2", nullptr));
		resultList.insertAtFront(new QueueNode("North3", "South3", nullptr));
		resultList.insertAtFront(new QueueNode("North4", "South4", nullptr));
		resultList.insertAtFront(new QueueNode("North5", "South5", nullptr));
		resultList.insertAtFront(new QueueNode("North6", "South6", nullptr));
		resultList.show();
		std::cout.rdbuf(coutConsumer);
		std::string expectedOutput = "North6\nNorth5\nNorth4\nNorth3\nNorth2\nNorth1";

		//Assert
		BOOST_CHECK_EQUAL(outBuffer.str(), expectedOutput);
	}

BOOST_AUTO_TEST_SUITE_END()
/////////////////////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_SUITE(ListInsertAtBackTests)
	BOOST_AUTO_TEST_CASE(SingleInsertAtEnd)
	{
		//Arrange
		HashTable* northTestTable = new HashTable(1);
		HashTable* southTestTable = new HashTable(1);
		ResultList resultList(northTestTable, southTestTable);

		//Act
		resultList.insertAtEnd(new QueueNode("North", "South", nullptr));
	}
	BOOST_AUTO_TEST_CASE(SingleInsertAtEndAndShow)
	{
		//Arrange
		HashTable* northTestTable = new HashTable(1);
		HashTable* southTestTable = new HashTable(1);
		ResultList resultList(northTestTable, southTestTable);
		std::ostringstream outBuffer;
		std::streambuf* coutConsumer = std::cout.rdbuf(outBuffer.rdbuf());

		//Act
		resultList.insertAtEnd(new QueueNode("North", "South", nullptr));
		resultList.show();
		std::cout.rdbuf(coutConsumer);

		//Assert
		BOOST_CHECK_EQUAL(outBuffer.str(), "North");
	}
	BOOST_AUTO_TEST_CASE(MultipleInsertsAtEnd)
	{
		//Arrange
		HashTable* northTestTable = new HashTable(1);
		HashTable* southTestTable = new HashTable(1);
		ResultList resultList(northTestTable, southTestTable);

		//Act
		resultList.insertAtEnd(new QueueNode("North1", "South1", nullptr));
		resultList.insertAtEnd(new QueueNode("North2", "South2", nullptr));
		resultList.insertAtEnd(new QueueNode("North3", "South3", nullptr));
		resultList.insertAtEnd(new QueueNode("North4", "South4", nullptr));
		resultList.insertAtEnd(new QueueNode("North5", "South5", nullptr));
		resultList.insertAtEnd(new QueueNode("North6", "South6", nullptr));
	}
	BOOST_AUTO_TEST_CASE(MultipleInsertsAtEndAndShow)
	{
		//Arrange
		HashTable* northTestTable = new HashTable(1);
		HashTable* southTestTable = new HashTable(1);
		ResultList resultList(northTestTable, southTestTable);
		std::ostringstream outBuffer;
		std::streambuf* coutConsumer = std::cout.rdbuf(outBuffer.rdbuf());

		//Act
		resultList.insertAtEnd(new QueueNode("North1", "South1", nullptr));
		resultList.insertAtEnd(new QueueNode("North2", "South2", nullptr));
		resultList.insertAtEnd(new QueueNode("North3", "South3", nullptr));
		resultList.insertAtEnd(new QueueNode("North4", "South4", nullptr));
		resultList.insertAtEnd(new QueueNode("North5", "South5", nullptr));
		resultList.insertAtEnd(new QueueNode("North6", "South6", nullptr));
		resultList.show();
		std::cout.rdbuf(coutConsumer);
		std::string expectedOutput = "North1\nNorth2\nNorth3\nNorth4\nNorth5\nNorth6";

		//Assert

	}
BOOST_AUTO_TEST_SUITE_END()
/////////////////////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_SUITE(ListInsertFrontThenBackTests)
	BOOST_AUTO_TEST_CASE(SingleInsertFrontAndBack)
	{
		//Arrange
		HashTable* northTestTable = new HashTable(1);
		HashTable* southTestTable = new HashTable(1);
		ResultList resultList(northTestTable, southTestTable);

		//Act
		resultList.insertAtFront(new QueueNode("North 1", "South 1", nullptr));
		resultList.insertAtEnd(new QueueNode("North 2", "South 2", nullptr));
	}
	BOOST_AUTO_TEST_CASE(SingleInsertFrontThenBackAndShow)
	{
		//Arrange
		HashTable* northTestTable = new HashTable(1);
		HashTable* southTestTable = new HashTable(1);
		ResultList resultList(northTestTable, southTestTable);
		std::ostringstream outBuffer;
		std::streambuf* coutConsumer = std::cout.rdbuf(outBuffer.rdbuf());
		std::string expectedString = "North 1\nNorth 2";

		//Act
		resultList.insertAtFront(new QueueNode("North 1", "South 1", nullptr));
		resultList.insertAtEnd(new QueueNode("North 2", "South 2", nullptr));
		resultList.show();
		std::cout.rdbuf(coutConsumer);

		//Assert
		BOOST_CHECK_EQUAL(outBuffer.str(), expectedString);
	}
	BOOST_AUTO_TEST_CASE(SingleInsertBackThenFront)
	{
		//Arrange
		HashTable* northTestTable = new HashTable(1);
		HashTable* southTestTable = new HashTable(1);
		ResultList resultList(northTestTable, southTestTable);

		//Act
		resultList.insertAtEnd(new QueueNode("North 2", "South 2", nullptr));
		resultList.insertAtFront(new QueueNode("North 1", "South 1", nullptr));
	}
	BOOST_AUTO_TEST_CASE(SingleInsertBackThenAndShow)
	{
		//Arrange
		HashTable* northTestTable = new HashTable(1);
		HashTable* southTestTable = new HashTable(1);
		ResultList resultList(northTestTable, southTestTable);
		std::ostringstream outBuffer;
		std::streambuf* coutConsumer = std::cout.rdbuf(outBuffer.rdbuf());
		std::string expectedString = "North 1\nNorth 2";

		//Act
		resultList.insertAtEnd(new QueueNode("North 2", "South 2", nullptr));
		resultList.insertAtFront(new QueueNode("North 1", "South 1", nullptr));
		resultList.show();
		std::cout.rdbuf(coutConsumer);

		//Assert
		BOOST_CHECK_EQUAL(outBuffer.str(), expectedString);
	}
	BOOST_AUTO_TEST_CASE(MultipleInserts)
	{
		//Arrange
		HashTable* northTestTable = new HashTable(1);
		HashTable* southTestTable = new HashTable(1);
		ResultList resultList(northTestTable, southTestTable);

		//Act
		resultList.insertAtFront(new QueueNode("North1", "South1", nullptr));
		resultList.insertAtEnd(new QueueNode("North2", "South2", nullptr));
		resultList.insertAtFront(new QueueNode("North3", "South3", nullptr));
		resultList.insertAtEnd(new QueueNode("North4", "South4", nullptr));
		resultList.insertAtFront(new QueueNode("North5", "South5", nullptr));
		resultList.insertAtEnd(new QueueNode("North6", "South6", nullptr));
		resultList.insertAtFront(new QueueNode("North7", "South7", nullptr));
		resultList.insertAtEnd(new QueueNode("North8", "South8", nullptr));
		resultList.insertAtFront(new QueueNode("North9", "South9", nullptr));
		resultList.insertAtEnd(new QueueNode("North10", "South10", nullptr));
		resultList.insertAtFront(new QueueNode("North11", "South11", nullptr));
		resultList.insertAtEnd(new QueueNode("North12", "South12", nullptr));
	}
	BOOST_AUTO_TEST_CASE(MultipleInsertsAndShow)
	{
		//Arrange
		HashTable* northTestTable = new HashTable(1);
		HashTable* southTestTable = new HashTable(1);
		ResultList resultList(northTestTable, southTestTable);
		std::ostringstream outBuffer;
		std::streambuf* coutConsumer = std::cout.rdbuf(outBuffer.rdbuf());
		std::string expectedString = "North11\nNorth9\nNorth7\nNorth5\nNorth3\nNorth1\nNorth2\nNorth4\nNorth6\nNorth8\nNorth10\nNorth12";

		//Act
		resultList.insertAtFront(new QueueNode("North1", "South1", nullptr));
		resultList.insertAtEnd(new QueueNode("North2", "South2", nullptr));
		resultList.insertAtFront(new QueueNode("North3", "South3", nullptr));
		resultList.insertAtEnd(new QueueNode("North4", "South4", nullptr));
		resultList.insertAtFront(new QueueNode("North5", "South5", nullptr));
		resultList.insertAtEnd(new QueueNode("North6", "South6", nullptr));
		resultList.insertAtFront(new QueueNode("North7", "South7", nullptr));
		resultList.insertAtEnd(new QueueNode("North8", "South8", nullptr));
		resultList.insertAtFront(new QueueNode("North9", "South9", nullptr));
		resultList.insertAtEnd(new QueueNode("North10", "South10", nullptr));
		resultList.insertAtFront(new QueueNode("North11", "South11", nullptr));
		resultList.insertAtEnd(new QueueNode("North12", "South12", nullptr));
		resultList.show();
		std::cout.rdbuf(coutConsumer);

		//Assert
		BOOST_CHECK_EQUAL(outBuffer.str(), expectedString);
	}
BOOST_AUTO_TEST_SUITE_END()
/////////////////////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_SUITE(ListGenerateResultTests)
	BOOST_AUTO_TEST_CASE(GenerateSingleResult)
	{
		//Arrange
		HashTable* northTestTable = new HashTable(1);
		HashTable* southTestTable = new HashTable(1);
		ResultList resultList(northTestTable, southTestTable);

		//Act
		northTestTable->insert("North", "South");
		southTestTable->insert("South", "North");
		resultList.generateSequence("North", "South");
	}
	BOOST_AUTO_TEST_CASE(GenerateSingleResultShow)
	{
		//Arrange
		HashTable* northTestTable = new HashTable(1);
		HashTable* southTestTable = new HashTable(1);
		ResultList resultList(northTestTable, southTestTable);
		std::ostringstream outBuffer;
		std::streambuf* coutConsumer = std::cout.rdbuf(outBuffer.rdbuf());
		std::string expectedString = "North";

		//Act
		northTestTable->insert("North", "South");
		southTestTable->insert("South", "North");
		resultList.generateSequence("North", "South");
		resultList.show();
		std::cout.rdbuf(coutConsumer);
		//Assert
		BOOST_CHECK_EQUAL(outBuffer.str(), expectedString);
	}
	BOOST_AUTO_TEST_CASE(GenerateWithInvalidBrickShow)
	{
		//Arrange
		HashTable* northTestTable = new HashTable(1);
		HashTable* southTestTable = new HashTable(1);
		ResultList resultList(northTestTable, southTestTable);
		std::ostringstream outBuffer;
		std::streambuf* coutConsumer = std::cout.rdbuf(outBuffer.rdbuf());
		std::string expectedString = "Empty list, starting brick not in list or file empty.\n";

		//Act
		northTestTable->insert("North", "South");
		southTestTable->insert("South", "North");
		resultList.generateSequence("abc", "xyc");
		resultList.show();
		std::cout.rdbuf(coutConsumer);
		//Assert
		BOOST_CHECK_EQUAL(outBuffer.str(), expectedString);
	}
	BOOST_AUTO_TEST_CASE(GenerateWithMultipleInserts)
	{
		//Arrange
		HashTable* northTestTable = new HashTable(1);
		HashTable* southTestTable = new HashTable(1);
		ResultList resultList(northTestTable, southTestTable);

		//Act
		northTestTable->insert("Symbol 1", "Symbol 2");
		northTestTable->insert("Symbol 2", "Symbol 3");
		northTestTable->insert("Symbol 3", "Symbol 4");
		northTestTable->insert("Symbol 4", "Symbol 5");
		northTestTable->insert("Symbol 5", "Symbol 6");
		northTestTable->insert("Symbol 6", "Symbol 7");
		northTestTable->insert("Symbol 7", "Symbol 8");
		northTestTable->insert("Symbol 8", "Symbol 9");
		northTestTable->insert("Symbol 9", "Symbol 10");


		southTestTable->insert("Symbol 2", "Symbol 1");
		southTestTable->insert("Symbol 3", "Symbol 2");
		southTestTable->insert("Symbol 4", "Symbol 3");
		southTestTable->insert("Symbol 5", "Symbol 4");
		southTestTable->insert("Symbol 6", "Symbol 5");
		southTestTable->insert("Symbol 7", "Symbol 6");
		southTestTable->insert("Symbol 8", "Symbol 7");
		southTestTable->insert("Symbol 9", "Symbol 8");
		southTestTable->insert("Symbol 10", "Symbol 9");

		resultList.generateSequence("Symbol 6", "Symbol 7");
	}
	BOOST_AUTO_TEST_CASE(GenerateWithMultipleInsertsAndShow)
	{
		//Arrange
		HashTable* northTestTable = new HashTable(1);
		HashTable* southTestTable = new HashTable(1);
		ResultList resultList(northTestTable, southTestTable);
		std::ostringstream outBuffer;
		std::streambuf* coutConsumer = std::cout.rdbuf(outBuffer.rdbuf());
		std::string expectedResultForTestTable = "Symbol 1\nSymbol 2\nSymbol 3\nSymbol 4\nSymbol 5\nSymbol 6\nSymbol 7\nSymbol 8\nSymbol 9\nSymbol 10";

		//Act
		northTestTable->insert("Symbol 1", "Symbol 2");
		northTestTable->insert("Symbol 2", "Symbol 3");
		northTestTable->insert("Symbol 3", "Symbol 4");
		northTestTable->insert("Symbol 4", "Symbol 5");
		northTestTable->insert("Symbol 5", "Symbol 6");
		northTestTable->insert("Symbol 6", "Symbol 7");
		northTestTable->insert("Symbol 7", "Symbol 8");
		northTestTable->insert("Symbol 8", "Symbol 9");
		northTestTable->insert("Symbol 9", "Symbol 10");


		southTestTable->insert("Symbol 2", "Symbol 1");
		southTestTable->insert("Symbol 3", "Symbol 2");
		southTestTable->insert("Symbol 4", "Symbol 3");
		southTestTable->insert("Symbol 5", "Symbol 4");
		southTestTable->insert("Symbol 6", "Symbol 5");
		southTestTable->insert("Symbol 7", "Symbol 6");
		southTestTable->insert("Symbol 8", "Symbol 7");
		southTestTable->insert("Symbol 9", "Symbol 8");
		southTestTable->insert("Symbol 10", "Symbol 9");
		resultList.generateSequence("Symbol 6", "Symbol 7");
		resultList.show();
		std::cout.rdbuf(coutConsumer);

		//Assert
		BOOST_CHECK_EQUAL(outBuffer.str(), expectedResultForTestTable);
	}
	BOOST_AUTO_TEST_CASE(LargeDataSetInsertion)
	{
		//Arrange
		int tableSize = 100000;
		HashTable northTestTable(tableSize);
		HashTable southTestTable(tableSize);
		ResultList resultList(&northTestTable, &southTestTable);
		std::string north;
		std::string south;

		//Act
		for (int i = 0; i <= tableSize; i++) {
			std::ostringstream northStream;
			std::ostringstream southStream;
			northStream << "North " << i;
			southStream << "South " << (i + 1);
			north = northStream.str();
			south = southStream.str();
			northTestTable.insert(north, south);
			southTestTable.insert(south, north);
		}
		resultList.generateSequence("North 505", "South 506");
	}
	BOOST_AUTO_TEST_CASE(LargeDataSetInsertionAndShow)
	{
		//Arrange
		int tableSize = 100000;
		HashTable northTestTable(tableSize);
		HashTable southTestTable(tableSize);
		ResultList resultList(&northTestTable, &southTestTable);
		std::string north;
		std::string south;

		//Act
		for (int i = 0; i <= tableSize; i++) {
			std::ostringstream northStream;
			std::ostringstream southStream;
			northStream << "North " << i;
			southStream << "South " << (i + 1);
			north = northStream.str();
			south = southStream.str();
			northTestTable.insert(north, south);
			southTestTable.insert(south, north);
		}
		resultList.generateSequence("North 505", "South 506");
	}
BOOST_AUTO_TEST_SUITE_END()
