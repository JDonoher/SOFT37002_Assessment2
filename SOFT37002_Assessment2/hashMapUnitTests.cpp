#include "hashTable.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(HashTableConstructorTests)
	BOOST_AUTO_TEST_CASE(SingleBucketConstructor)
	{
		HashTable table(1);
	}
	BOOST_AUTO_TEST_CASE(MultipleBucketsConstructor) 
	{
		HashTable table(100);
	}
	BOOST_AUTO_TEST_CASE(InvalidHashValueConstructor)
	{
		BOOST_CHECK_THROW(HashTable table(0), std::invalid_argument);
	}
BOOST_AUTO_TEST_SUITE_END()

///////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(HashTableInsertAndLookupTests)
	BOOST_AUTO_TEST_CASE(InsertSingleBrick)
	{
		HashTable table(1);
		table.insert("A", "B");
	}
	BOOST_AUTO_TEST_CASE(InsertSingleBrickWithLookup) 
	{
		//Arrange
		HashTable table(1);
		table.insert("A", "B");

		//Act
		HashNode* node = table.lookupViaKey("A");

		//Assert
		BOOST_CHECK_EQUAL(node->northSymbol, "A");
		BOOST_CHECK_EQUAL(node->southSymbol, "B");
	}
	BOOST_AUTO_TEST_CASE(InsertMultipleBricks)
	{
		//Arrange
		HashTable table(5);
		table.insert("A", "B");
		table.insert("C", "D");
		table.insert("E", "F");
		table.insert("G", "H");
		table.insert("I", "J");

		//Act
		HashNode* node1 = table.lookupViaKey("A");
		HashNode* node2 = table.lookupViaKey("C");
		HashNode* node3 = table.lookupViaKey("E");
		HashNode* node4 = table.lookupViaKey("G");
		HashNode* node5 = table.lookupViaKey("I");
	}
	BOOST_AUTO_TEST_CASE(InsertMultipleBricksWithLookup) {

		//Arrange
		HashTable table(5);
		table.insert("A", "B");
		table.insert("C", "D");
		table.insert("E", "F");
		table.insert("G", "H");
		table.insert("I", "J");

		//Act
		HashNode* node1 = table.lookupViaKey("A");
		HashNode* node2 = table.lookupViaKey("C");
		HashNode* node3 = table.lookupViaKey("E");
		HashNode* node4 = table.lookupViaKey("G");
		HashNode* node5 = table.lookupViaKey("I");

		//Assert
		BOOST_CHECK_EQUAL(node1->northSymbol, "A");
		BOOST_CHECK_EQUAL(node1->southSymbol, "B");
		BOOST_CHECK_EQUAL(node2->northSymbol, "C");
		BOOST_CHECK_EQUAL(node2->southSymbol, "D");
		BOOST_CHECK_EQUAL(node3->northSymbol, "E");
		BOOST_CHECK_EQUAL(node3->southSymbol, "F");
		BOOST_CHECK_EQUAL(node4->northSymbol, "G");
		BOOST_CHECK_EQUAL(node4->southSymbol, "H");
		BOOST_CHECK_EQUAL(node5->northSymbol, "I");
		BOOST_CHECK_EQUAL(node5->southSymbol, "J");
	}
	BOOST_AUTO_TEST_CASE(CollisonHandling) 
	{
		//Arrange
		HashTable table(1);
		table.insert("A", "B");
		table.insert("C", "D"); //This north symbol will cause a collision

		//Act //This will cause a collison
		HashNode* node1 = table.lookupViaKey("A");
		HashNode* node2 = table.lookupViaKey("C");

		//Assert
		BOOST_CHECK_EQUAL(node1->northSymbol, "A");
		BOOST_CHECK_EQUAL(node1->southSymbol, "B");
		BOOST_CHECK_EQUAL(node2->northSymbol, "C");
		BOOST_CHECK_EQUAL(node2->southSymbol, "D");
	}
	BOOST_AUTO_TEST_CASE(Overwrite)
	{
		HashTable table(1);
		table.insert("A", "B");
		table.insert("A", "C");
	}
	BOOST_AUTO_TEST_CASE(OverwirteAndLookup)
	{
		//Arrange
		HashTable table(1);
		table.insert("A", "B");
		table.insert("A", "C");

		//Act
		HashNode* node = table.lookupViaKey("A");

		//Assert
		BOOST_CHECK_EQUAL(node->northSymbol, "A");
		BOOST_CHECK_EQUAL(node->southSymbol, "C");
		BOOST_CHECK_NE(node->southSymbol, "B");
		BOOST_CHECK_EQUAL(table.lookupViaValue("B"), nullptr);
		
	}
	BOOST_AUTO_TEST_CASE(EmptyLookup)
	{
		//Arrange
		HashTable table(1);

		//Act & Assert
		BOOST_CHECK_THROW(table.lookupViaKey("A"), std::invalid_argument);
	}
	BOOST_AUTO_TEST_CASE(LookupAbsentBrick)
	{
		//Arrange
		HashTable table(1);
		table.insert("A", "B");

		//Act
		HashNode* n = table.lookupViaKey("C");

		//Asert
		BOOST_CHECK_EQUAL(n, nullptr);
	}
	BOOST_AUTO_TEST_CASE(LargeDataSetInsertion)
	{
		//Arrange
		int tableSize = 100000;
		std::string north;
		std::string south;

		//Act
		HashTable table(100000);
		for(int i = 0; i <= tableSize; i++) {
			table.insert(north, south);
			//Had to use streams to digest as boost wasnt liking updaitng stringd
			std::ostringstream northStream;
			std::ostringstream southStream;
			northStream << "North " << i;
			southStream << "South " << (i + 1);
			north = northStream.str();
			south = southStream.str();
			table.insert(north, south);
		}
	}
	BOOST_AUTO_TEST_CASE(LargeDataSetInsertionAndLookup)
	{
		//Arrange
		long long unsigned int tableSize = 1000;
		std::string north;
		std::string south;
		HashTable table(tableSize);

		//Act
		for (int i = 0; i < tableSize; i++) {
			std::ostringstream northStream;
			std::ostringstream southStream;
			northStream << "North " << i;
			southStream << "South " << (i + 1);
			north = northStream.str();
			south = southStream.str();
			table.insert(north, south);
		}
		HashNode* n = table.lookupViaKey("North 509");
		//std::cout <<"Node found"<< n->northSymbol << n->southSymbol << std::endl;
		
		//Assert
		BOOST_CHECK_EQUAL(n->northSymbol, "North 509");
		BOOST_CHECK_EQUAL(n->southSymbol, "South 510");
	}

BOOST_AUTO_TEST_SUITE_END()