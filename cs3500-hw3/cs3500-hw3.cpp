// cs3500-hw3.cpp : Defines the entry point for the console application.
//

#include "gparser.h"

using namespace std;

int main()
{
  gparser gp;
  string x;

  cout << (gp.parse("gparse3.txt") ? "CORRECT" : "INVALID!") << endl;
  cout << (gp.parse("gparse4.txt") ? "CORRECT" : "INVALID!") << endl;
  cout << (gp.parse("gparse5.txt") ? "CORRECT" : "INVALID!") << endl;
  cout << (gp.parse("gparse6.txt") ? "CORRECT" : "INVALID!") << endl;
  cout << (gp.parse("gparse7.txt") ? "CORRECT" : "INVALID!") << endl;

  cin >> x;
    
  return 0;
}

