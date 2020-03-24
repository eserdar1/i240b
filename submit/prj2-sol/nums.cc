#include "arrayseq.hh"
#include <iostream>
#include <fstream>

using TestType = int;
void output_from_seq (ConstIter<TestType> *begin, ConstIter<TestType> *end){
	ConstIter<TestType> *it1= begin;
	ConstIter<TestType> *it2= end;
	for (ConstIter<TestType>&p = *it1, &p2 = *it2; p,p2; ++p, --p2  ) {
		std::cout << " " << *p << " " << *p2;	
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
		std::cerr << "usage: ./nums [-a] INTS_FILE_PATH " << std::endl;
		exit(1);		
	}
	else if ( argc == 3){
		if (std::string(argv[1]) == "-a"){
			SeqPtr<TestType> obj1 = ArraySeq<TestType>::make();
			readInt(std::string(argv[2]), obj1.get()); // "-a" is the second argument so wee need to take third argument with argv[2]
		}
		else{
			std::cerr << "usage: ./nums [-a] INTS_FILE_PATH " << std::endl;
			exit(1);
		
		}
	}	
}

int main(int argc, char *argv[]){
	verify_args(argc, argv);
	return 0;
	
}
