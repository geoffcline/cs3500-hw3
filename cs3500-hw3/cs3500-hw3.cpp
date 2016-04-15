// cs3500-hw3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gparser.h"

using namespace std;

int main()
{
  gparser gp;
  int x;

  cout << (gp.parse() ? "true" : "false") << endl;
  cin >> x;
    
  return 0;
}

