#include "newclass.hh"
#include "ops.hh"

int 
Newclass::compare(int a, int b){
	cmp_count+=1;
	return ( this->Ops::compare(a,b)   );
}

void
Newclass::swap(int a[], int i, int j){
	swp_count+=1;
	return ( this->Ops::swap(a,i,j)    );
}
