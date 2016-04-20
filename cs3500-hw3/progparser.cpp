// cs3500-hw3.cpp : Defines the entry point for the console application.
//

#include "gparser.h"

using namespace std;

int main()
{
  gparser gp;

  cout << (gp.parse() ? "CORRECT" : "INVALID!") << endl;
    
  return 0;
}

