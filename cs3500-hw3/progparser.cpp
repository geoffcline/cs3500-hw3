// Geoffrey Cline
// CS3500 - HW 3
// 4/19/2016

#include "gparser.h"
#include "glexer.h"

using namespace std;

int main()
{
  gparser gp;
  char x;

  cout << (gp.parse("gparse2.txt") ? "CORRECT" : "INVALID!") << endl;
  cout << (gp.parse("gparse3.txt") ? "CORRECT" : "INVALID!") << endl;
  cout << (gp.parse("gparse4.txt") ? "CORRECT" : "INVALID!") << endl;
  cout << (gp.parse("gparse5.txt") ? "CORRECT" : "INVALID!") << endl;
  cout << (gp.parse("gparse6.txt") ? "CORRECT" : "INVALID!") << endl;
  cout << (gp.parse("gparse7.txt") ? "CORRECT" : "INVALID!") << endl;


  cin >> x;
    
  return 0;
}

