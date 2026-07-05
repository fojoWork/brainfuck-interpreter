#include <iostream>
#include <vector>
#include <string>
//removing the use of std::
using std::vector;
using std::string;
using std::getline;
using std::cin;
using std::cout;

int main(void) {
  //Declaring variable for user input, create one for the instruction stream, and tape memory for the actual execution.
   string sInput;
   vector<unsigned char> uc_bfStream;
   
   vector<unsigned char> tape(30000, 0); 
   //Variables for pointing to a cell and another for iterating through instructions(remembering which instruction cell we are on)
   //Basically one is for writing the cells and another is for reading the cells. could probably just create just one cell pointer and then create 2 other pointers that point to it instead of making two extra variables for basically the same task.
   size_t sCell_Pointer{};
   size_t instr_pointer{};

  //Gather input
   cout << "Please enter your brainfuck code: \n";
   getline(cin, sInput);
  //take input and put inside instruction stream;
   for (size_t i{}; i < sInput.size(); ++i) {
      switch(sInput[i]) {
        //ugly ass switch statement
          case '<' : uc_bfStream.push_back('<'); break; 
          case '>' : uc_bfStream.push_back('>'); break; 
          case '-' : uc_bfStream.push_back('-'); break; 
          case '+' : uc_bfStream.push_back('+'); break;
          case '[' : uc_bfStream.push_back('['); break;
          case ']' : uc_bfStream.push_back(']'); break;
          case ',' : uc_bfStream.push_back(','); break;
          case '.' : uc_bfStream.push_back('.'); break;
          default : break;
      }
   }
   //take our uc_bfStream and execute the instructions in our taped memory; 
   while(instr_pointer < uc_bfStream.size()) {
     switch(uc_bfStream[instr_pointer]) {
       case '>' : sCell_Pointer++; break;
       case '<' : sCell_Pointer--; break;
       case '-' : tape[sCell_Pointer]--; break;
       case '+' : tape[sCell_Pointer]++; break;
       case '.' : cout << tape[sCell_Pointer]; break;
       case ',' : tape[sCell_Pointer] = cin.get(); break;
       default : break;
     }
    //iterate to the next instruction
     instr_pointer++;
   }
    //create a line break  
   cout << "\n";
}
