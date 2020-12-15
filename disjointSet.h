#ifndef DISJOINTSET_H
#define DISJOINTSET_H
#include<vector>
#include<iostream>
using namespace std;
 
class DisjSets
{
	public:
	explicit DisjSets( int numElements);
	
	//int find(int x) const;
	int find(int x);
	void unionSets( int root1, int root2);
	int size();
	
	private:
	vector <int> s;
	
};
#endif


