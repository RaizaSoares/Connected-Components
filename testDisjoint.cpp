//#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "disjOther.h"

TEST_CASE("Test a simple find")
{
   DisjSets ds(1);

   REQUIRE(ds.find(0) == 0);
}

//	int find(int x);
//	void unionSets( int root1, int root2);

TEST_CASE("Second test for find (indirectly tests unions as well")
{
   DisjSets ds(10);

   ds.unionSets(1,2);
   ds.unionSets(1,3);
   ds.unionSets(1,4);
   ds.unionSets(1,5);

   for (long int I = 1 ; I < 5 ; I++)
      REQUIRE(ds.find(1) == ds.find(I));
}

TEST_CASE("Test TestMakeSetII")
{
   DisjSets ds(1);
   DisjSets ds1(1);
}

TEST_CASE("Test TestMakeSetIII")
{
   DisjSets ds(1);
   DisjSets ds1(2);
}

TEST_CASE("Test Simple TestUnion")
{
   DisjSets ds(2);
   ds.unionSets(0,1);

   REQUIRE(ds.find(0) == ds.find(1));
}

TEST_CASE("Test Multi-Relationship Union")
{
   DisjSets ds(6);
   ds.unionSets(1,2);
   ds.unionSets(3,4);
   ds.unionSets(0,5);
   ds.unionSets(3,2);
   ds.unionSets(4,0);
   ds.unionSets(5,1);
   REQUIRE(ds.find(2) == ds.find(0));
}

TEST_CASE("Test negative Multi-Relationship Union")
{
   DisjSets ds(6);
   ds.unionSets(1,2);
   ds.unionSets(3,4);
   ds.unionSets(0,5);
   ds.unionSets(4,0);
   REQUIRE(ds.find(2) != ds.find(0));
}
