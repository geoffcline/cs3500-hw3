// Geoffrey Cline
// CS3500 - HW 3
// 4/19/2016

#include "gparser.h"
#include "glexer.h"

using namespace std;

int main()
{
  gparser gp;

  cout << (gp.parse() ? "CORRECT" : "INVALID!") << endl;

  return 0;
}

