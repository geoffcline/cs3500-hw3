#include "glexer.h"

string type_line(const string s)
{
  const int SINTF = 0;
  const int SDECF = 1;
  const int SSCIF = 2;
  const int SHEXF = 3;
  const int SBINF = 4;
  //const int SKEYF = 5;
  const int SSTRF = 6;

  const int SSRT  = 10;
  const int SBIN  = 11;
  
  const int SSCI  = 13;
  const int SHEX  = 14;
  const int SHEXC = 15;
  const int SDEC  = 16;
  const int SSCI2 = 17;

  const int SBAD = 7;

  unsigned int i = 0;
  unsigned int st = SSRT;

  string rst = LINE_TYPES[SBAD];

  queue<int> states;
  queue<char> chars;

  while (i < s.length() && st != SBAD)
  {
  switch (st)
  {
  case SSRT:
    if (s[i] == '+' || s[i] == '-')
    st = SINTF;
    else if (s[i] == '0' || s[i] == '1')
    st = SBIN;
    else if (s[i] >= '2' && s[i] <= '9')
    st = SINTF;
    else if (s[i] >= 'A' && s[i] <= 'F')
    st = SHEXC;
    else if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
    st = SSTRF;
    else
    st = SBAD;
    break;

  case SBIN:
    if (s[i] == '0' || s[i] == '1')
    st = SBIN;
    else if (s[i] > '1' && s[i] <= '9')
    st = SINTF;
    else if (s[i] == 'B')
    st = SBINF;
    else if (s[i] >= 'A' && s[i] <= 'F')
    st = SHEX;
    else
    st = SBAD;
    break;

  case SINTF:
    if (s[i] >= '0' && s[i] <= '9')
    st = SINTF;
    else if (s[i] >= 'A' && s[i] <= 'F')
    st = SHEX;
    else if (s[i] == '.')
    st = SDEC;
    else
    st = SBAD;
    break;

  case SHEX:
    if (s[i] >= 'A' && s[i] <= 'F')
    st = SHEX;
    else if (s[i] >= '0' && s[i] <= '9')
    st = SHEX;
    else if (s[i] == 'H')
    st = SHEXF;
    else if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
    st = SSTRF;
    else
    st = SBAD;
    break;

  case SHEXC:
    if (s[i] >= 'A' && s[i] <= 'F')
    st = SHEXC;
    else if (s[i] >= '0' && s[i] <= '9')
    st = SHEXC;
    else if (s[i] == 'H')
    st = SHEXF;
    else if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
    st = SSTRF;
    else
    st = SBAD;
    break;

  case SSTRF:
    if (s[i] >= '0' && s[i] <= '9')
    st = SSTRF;
    else if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
    st = SSTRF;
    else if (s[i] == 0)
    st = SSTRF;
    else
    st = SBAD;
    break;

  case SBINF:
    if (s[i] != 0)
    st = SBAD;
    break;

  case SDEC:
    if (s[i] >= '0' && s[i] <= '9')
    st = SDECF;
    else
    st = SBAD;
    break;

  case SDECF:
    if (s[i] >= '0' && s[i] <= '9')
    st = SDECF;
    else if (s[i] == 'E')
    st = SSCI;
    else
    st = SBAD;
    break;

  case SSCI:
    if (s[i] >= '1' && s[i] <= '9')
    st = SSCIF;
    else if (s[i] == '-' || s[i] == '+')
    st = SSCI2;
    else
    st = SBAD;
    break;

  case SSCI2:
    if (s[i] >= '1' && s[i] <= '9')
    st = SSCIF;
    else
    st = SBAD;
    break;

  case SSCIF:
    if (s[i] >= '0' && s[i] <= '9')
    st = SSCIF;
    else
    st = SBAD;
    break;

  case SHEXF: 
    if (s[i] != 0)
    st = SSTRF;
    break;

  default:
    st = SBAD;
  }
  states.push(st);
  chars.push(s[i]);
  i++;
  }
  
  /*
  cout << "Ch:\t";
  while (!chars.empty())
  {
  cout << chars.front() << "\t";
  chars.pop();
  }
  cout << endl << "St:\t";
  while (!states.empty())
  {
  cout << states.front() << "\t";
  states.pop();
  }
  cout << endl;
  */

  if (st == SBIN)
  st = SINTF;
  else if (st == SHEXC)
  st = SSTRF;

  if (i == s.length() && st < LINE_TYPES_SZ && st != SBAD)
  {
    rst = LINE_TYPES[st];
  }
  else
  {
  rst = LINE_TYPES[SBAD];
  }


  return rst;
}
