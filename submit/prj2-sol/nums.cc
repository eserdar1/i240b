#include "arrayseq.hh"
#include <iostream>
#include <fstream>

using TestType = int;
void output_from_seq (ConstIter<TestType> *begin, ConstIter<TestType> *end){
	for (;begin, end; ++begin, --end) {
		std::cout << *begin << ' ' << *end ;	
	} 
 	std::cout << std::endl;
}

void readInt(std::string filename, Seq<TestType> *x){
	std::ifstream in(filename);
	int a;
	while (in >> a){
		x -> push(a);
		
	}
	ConstIterPtr<TestType> begin = x -> cbegin();
	ConstIterPtr<TestType> end = x-> cend();
	output_from_seq(begin.get(), end.get());
}





void verify_args(int argc, char * argv[]){
	if (argc > 3 || argc<2 ){
	
	}
	else if ( argc == 2){
		if (argv[1] == "-a"){
		
		}
		else{
		}
	}	
}

int main(int argc, char *argv[]){
	SeqPtr<TestType> obj1 = ArraySeq<TestType>::make();
	readInt(std::string(argv[1]), obj1.get());
	return 0;
	
}
