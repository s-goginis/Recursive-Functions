//Shreya Gogini
//assignment2.cpp
//Purpose : The purpose of this program is to find the recursive formula's
//          for various different sequences and series in the world. We have
//          to set a base case and have the formula. This is a user
//          interactive program and the user can choose which program to run.

#include <iostream>
#include <cmath>
#include <string>


using namespace std;

//creating all the function prototypes
//they all run their respective functions with user input
int mysterySequence(int);
int tennisBalls(int);
string decToBase2(int);
bool isDivisibleBy7(int);
double ramanujan(double, double);
void runTests(); //runs all the functions

//desc : Uses the recursive formula to compute the mystery sequence
//pre : valid input is provided
//post : the nth number in the sequence is provided
int mysterySequence(int n){
  //Base case 1
  if(n==1){
    return 3;
  }
  //Base case 2
  if(n==0){
    return 2;
  }
  //recursive formula
  return mysterySequence(n-1) * mysterySequence(n-2);
    
}

//desc : takes the height of a pyramid and returns the number of tennis balls
//pre : valid input is provided
//post : returns the number of tennis balls in the pyramid
int tennisBalls(int n){
  //base case 1
  if(n==0){
    return 0;
  }
  //base case 1
  else if(n==1){
    return 1;
  }
  //recursive formula
  return tennisBalls(n-1)+(n*n);
  
}

//desc : turns an integer into a binary
//pre : valid input is provided
//post : returns the integer's binary representation as a string
string decToBase2(int dec){
  //base case 1
  if (dec==0){
    return "0";
  }
  //base case 2
  else if(dec == 1){
    return "1";
  }
  //recursive formula
  return (decToBase2(dec/2) + decToBase2(dec%2));
    
}

//desc : checks for divisibility by seven recursively w/o mod
//pre : valid input is provided
//post : returns true if divisible, otherwise false
bool isDivisibleBy7(int num){
  //base case 1
  if(num < 100){
    return num%7==0;
  }
  //base case 2
  else if(num < 0){
    return isDivisibleBy7(-num);
  }
  else{
    //converting the int to a string
    string str = to_string(num);
    //gets the last digit as a char
    char back = str.back();
    //the ascii value of '0' is 48 so we just subtract that 
    //from the actual value to get the correct int
    int last_digit = back - '0';
    int new_num = (num/10)-2*  last_digit;
    //recursive formula
    return isDivisibleBy7(new_num);
  }
}


//desc : Calculates ramanujan's formula at a certain depth
//pre : accepts a depth provided by user
//post : returns a type double value
double ramanujan (int depth, int i){
  //base case
  if(depth == i){
    return (i+1)*sqrt(6+i);
  }
  //recursive formula
  return (i+1)*sqrt((6+i) + ramanujan(depth, i+1));

}

//desc : function that runs all the functions and prints the reusts
//pre : functions are valid
//post : none
void runTests(){
  //mystery sequence
  cout << "The 0th number of the sequence is " << mysterySequence(0) << endl;
  cout << "The 1st number of the sequence is " << mysterySequence(1) << endl;
  cout << "The 4th number of the sequence is " << mysterySequence(4) << endl;
  cout << "The 7th number of the sequence is " << mysterySequence(7) << endl;
  cout << endl;

  //tennisballs
  cout << "A pyramid with 0 levels holds " 
       << tennisBalls(0) << " tennis balls" << endl;
  cout << "A pyramid with 1 level holds " 
       << tennisBalls(1) << " tennis balls" << endl;
  cout << "A pyramid with 3 levels holds " 
       << tennisBalls(3) << " tennis balls" << endl;
  cout << "A pyramid with 10 levels holds " 
       << tennisBalls(10) << " tennis balls" << endl << endl;

  //decToBase2
  cout << "The number 0 in Binary is " << decToBase2(0) << endl;
  cout << "The number 1 in Binary is " << decToBase2(1) << endl;
  cout << "The number 13 in Binary is " << decToBase2(13) << endl;
  cout << "The number 32 in Binary is " << decToBase2(32) << endl;
  cout << "The number 321 in Binary is " << decToBase2(321) << endl << endl;

  //isDivisibleBy7
  if(isDivisibleBy7(1)){
    cout << "The number 1 is divisible by 7" << endl;
  }
  else{
    cout << "The number 1 is not divisible by 7" << endl;
  }
  if(isDivisibleBy7(7)){
    cout << "The number 7 is divisible by 7" << endl;
  }
  else{
    cout << "The number 7 is not divisible by 7" << endl;
  }
  if(isDivisibleBy7(31)){
    cout << "The number 31 is divisible by 7" << endl;
  }
  else{
    cout << "The number 31 is not divisible by 7" << endl;
  }
  if(isDivisibleBy7(1073)){
    cout << "The number 1073 is divisible by 7" << endl;
  }
  else{
    cout << "The number 1073 is not divisible by 7" << endl;
  }
  if(isDivisibleBy7(1729)){
    cout << "The number 1729 is divisible by 7" << endl;
  }
  else{
    cout << "The number 1729 is not divisible by 7" << endl;
  }
  cout << endl;

  //ramanujan
  cout << "Result at depth 1: " << ramanujan(1, 0) << endl;
  cout << "Result at depth 3: " << ramanujan(3, 0) << endl;
  cout << "Result at depth 10: " << ramanujan(10, 0) << endl << endl;


}

int main(){
  //repeat variable
  bool repeat = true;
  //user's choice
  int choice;
  //loop for the program
  do{
    cout <<"Welcome to the recursion assignment." << 
            "What would you like to test?" << endl;
    cout <<"1. mysterySequence" << endl;
    cout <<"2. tennisBalls" << endl;
    cout <<"3. decToBase2" << endl;
    cout <<"4. isDivisibleBy7" << endl;
    cout <<"5. ramanujan" << endl;
    cout <<"6. run tests" << endl;
    cout <<"7. Exit" << endl;

    //gets the users choice 
    cin >> choice;
    //variable for the cases in the switch statement
    int num;
    
    //switch statment to call the functions based on user input
    switch(choice){
      //calls the mystery sequence function, 
      //gets user input for nth number of the sequence
      case 1:
        cout << "Mystery Sequence." << 
        "Please enter n to compute the nth number in sequence: " << endl;
        cin >> num;
        if(num <= 7){
          cout << "Number " << num << " in the sequence is: " 
               << mysterySequence(num) << endl;
        }
        else{
            cout<<"Sorry, mysterySequence cannot handle this number"<<endl;
        }
        break;
      //calls tennis balls functions, gets height from user
      case 2:
        cout<<"Tennis Balls. Please enter the height of the pyramid: "<<endl;
        cin >> num;
        if(num >=0){
          cout << "A pyramid with " << num << " level(s) holds " 
               << tennisBalls(num) << " tennis balls" << endl;
        }
        else{
            cout << "Invalid Input" << endl;
        }
        break;
      //calls decToBase2 function, gets integer from user
      case 3:
        cout << "DectoBase2." 
             <<"Please enter the number to convert to binary: " << endl;
        cin >> num;
        if(num >= 0){
          cout << "The number " << num 
               << " in Binary is " << decToBase2(num) << endl;
        }
        else{
            cout << "Invalid Input" << endl;
        }
        break;
      //calls isDivisibleBy7 function, gets integer from user
      case 4: 
        cout << "IsDivisibleBy7." << 
        "Please enter the number to check for divisibility: " << endl;
        cin >> num;
        //based on return bool, prints certain output
        if(isDivisibleBy7(num)){
          cout << "The number " << num << " is divisible by 7" << endl;
        }
        else{
          cout << "The number " << num << " is not divisible by 7" << endl;
        }
        break;
      //calls ramanujan function, gets depth from user
      case 5:
        cout << "Ramanujan. Please enter the depth of the radical: " << endl;
        cin >> num;
        if(num >= 0){
          cout << "Result at depth " << num 
               << ": " << ramanujan(num, 0) << endl;
          cout << "Result at infinite depth: 4" << endl;
        }
        else{
            cout << "Invalid Input" << endl;
        }
        
        break;
      //calls running tests function
      case 6:
        cout << "Running tests...." << endl;
        runTests();
        break;
      //if user wants to quit
      case 7:
        repeat = false;
        cout << "Thank you for playing! Exiting..." << endl;
        break;
      //if invalid input
      default:
        cout <<"Invalid input. Exiting ..." << endl;
        repeat = false;
        break;

    }
 //loops runs while the user wants to continue    
 }while(repeat);

}
