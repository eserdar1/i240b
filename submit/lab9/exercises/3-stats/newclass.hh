#include "ops.hh"
#ifndef NEWCLASS_HH_
#define NEWCLASS_HH_

class Newclass : public Ops 
{
public:
	int cmp_count=0;
	int swp_count = 0;
	
	virtual int compare(int a, int b);
	
	virtual void swap(int a[], int i, int j);

};

#endif 
