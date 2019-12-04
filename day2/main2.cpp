#include <iostream>
#include <numeric>
#include <vector>
#include <iterator>

using namespace std;
class IntcodeMachine{
private:

// operators could not be overridden for basic types. I wished i could do it through callbacks
// but no luck this time
void processOneSentence(vector<int> sentance, vector<int>& instructions_book ) {
  switch (sentance[0] ){
    case 1:
    case 2:
//      instructions_book[sentance[3]] = [=](int op1, int op2) ->int { return (sentance[0] == 1)?int (* operator+)(int *a, int *b):int (* operator*)(int *a, int*b)}
//      instructions_book[sentance[3]] = ((sentance[0] == 1)?operator+:operator*)(sentance[1],sentance[2]);
      instructions_book[sentance[3]] = sentance[0] == 1?sentance[1]+sentance[2]:sentance[1]*sentance[2];
      break;
    case 99: return;
    default:
      throw;
  }	  
  return; 
}

// The realisation of this function was made like this just for fun.
// The external lambda provides the vector of values of words of this sentance
// The internal one was made just because that was the most adequate way (as I see it)
// to implement range from x to x+delta to grab the values for words of sentence getter
// That was, until I realized that if I'm already creating the external lambda I can 
// simply make it through for(int index=id*4;index<(id*4+sentance_size)) {...} cycle
// but the logic was already done so be it.
vector<int> getSentenceByID(
		vector<int> instructions_book, int id, int sentance_size ) {
   return [=]() -> vector<int> {
     vector<int> sentance = {}; 
     for (int every_value_this_line : 
       [=]() -> vector<int> {
         vector<int> range(sentance_size);
	 iota(range.begin(), range.end(), id*sentance_size);
         return range; 
       }
     ) {
         sentance.push_back(instructions_book[every_value_this_line]);
     }
     return sentance;
   };
}

//- - - 
bool endNotReached;
//- - -


public:
void processInstructions(vector<int>& instructions_set) {
  endNotReached=true;
  int line_id=0;
  do {
	  processOneSentence(getSentenceByID(instructions_set, line_id, 4), instructions_set);  }while(endNotReached);
}

};

int main(int argc, char** argv) {

  string rawInput;
  vector<int> intMasses;

  for(string rawInput; getline(cin, rawInput);){
    intMasses.push_back(stoi(rawInput));
  }

//cout << calculateTotalRequiredAmount(intMasses) << endl;
  return 0;
}
