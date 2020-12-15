#include "disjointSet.h"
#include <iostream>

using namespace std;

DisjSets::DisjSets(int numElements)
	{
     s.resize(numElements, -1);
	 
	}

int DisjSets::find(int x) //with path compression
{
	//cout<<"in";
	//static int i=0;
	//cout<<i<<" ";
	//i++;
	
	if(s[x]<0)
		return x;
	else
	{ 
		return  s[x]= find(s[x]);
	}
}

void DisjSets::unionSets(int root1, int root2) //union by rank
{
    int left = find(root1);
    int right = find(root2);
    if (left == right) return;

	if(s[right]<s[left])
		s[left]=right;
	
	else
	{
		if(s[right]==s[left])
			--s[left];
		s[right]=left;
	}
}

int DisjSets::size()
{
	int total=0;
	for(unsigned i=0; i<s.size(); i++)
	{
		if(s[i]<0)
		{
			return -1*s[i];
		}
	}
	
		return 0;
}