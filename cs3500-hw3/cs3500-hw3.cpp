// cs3500-hw3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gparser.h"

using namespace std;

int main()
{
  gparser gp;
  string x;

  do
  {
	cout << (gp.parse() ? "true" : "false") << endl;
	cout << "PARSE AGAIN? y/n" << endl;
	cin >> x;
  } while (x != "n");
    
  return 0;
}

