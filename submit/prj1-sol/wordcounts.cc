#include <iostream>
#include <algorithm> 
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <map>
#include <vector>
#include <set>
#include <unordered_map>
#include  <utility>
typedef std::string FileName;
typedef std::string Word;
typedef int Count;

std::string just_alphabet(std::string word){
	int len = word.length();
	int i=0;
	int counter=0;
       // char* result=(char*)malloc(len*sizeof(char));
	char result[len];
	for(i=0;i<len;i++){
		if (word[i]>='A' && word[i]<='Z'){
			word[i] = word[i] - 'A' + 'a' ;
			result[counter]=word[i];
			counter++;
		}
		else if(word[i]>='a' && word[i]<='z'){
			result[counter]=word[i];
			counter++;
		}
	}
	
	
	result[counter]='\0';
	return result;
} 

bool wordCountCompare(const std::pair<std::string, int> &str1, const std::pair<std::string, int> &str2) 
{ 
	if (str1.second>str2.second) return true;
	if (str1.second<str2.second) return false;
	if (str1.first>str2.first) return false;
	return true;
 	 //return( str1.second > str2.second);
}		   

std::unordered_map<Word,int > readWords(int MAX_N_OUT, int MIN_WORD_LEN, int MAX_WORD_LEN, std::string filename){
   

    std::unordered_map<Word, int> map; //empty collection	
    std::ifstream in(filename); // opening a file
    
   if (!in) {
      std::cerr << "cannot read \"" << filename << "\"" << std::endl;
      std::exit(1);
    } 

        
	

    while (in.good()){
	std::string w;
	in>>w;
	w = just_alphabet(w);
        if (w.length() >= MIN_WORD_LEN && w.length()<= MAX_WORD_LEN){

		Count& count = map[w];
		count +=1;
    
	}
    }    


    if (!in.eof()) {
      std::cerr << "i/o error on file \"" << filename << "\"" << std::endl;
      std::exit(1);

    } 

    
   
    typedef std::pair<std::string, int> WordCount; 
    auto wordCounts = std::vector<WordCount>(map.begin(), map.end());
    sort(wordCounts.begin(), wordCounts.end(), wordCountCompare);
    int max = (map.size()<MAX_N_OUT)? map.size() : MAX_N_OUT;
  	
    for (int i=0; i<max; i++){
		std::cout << wordCounts[i].first <<":"<< wordCounts[i].second << std::endl ; 
    } 
    return map;	
}

int main(int argc, char *argv[]){
	
	
	auto args = std::vector<std::string>(&argv[1], &argv[argc-1]);
	
	for (auto &arg:args){
		size_t endIndex;
		std::stoi(arg,&endIndex);
		
		if (endIndex != arg.length()) {
	    		std::cerr << "Arg is not an int" << std::endl;
	    		std::exit(1);
	  	}
	}
	readWords(std::stoi(argv[1]), std::stoi(argv[2]), std::stoi(argv[3]), argv[4]);
	
}
