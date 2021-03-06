// Geoffrey Cline
// CS3500 - HW 3
// 4/19/2016

#include "gparser.h"

using namespace std;

gparser::gparser()
{
}


gparser::~gparser()
{
}

bool gparser::parse()
{
  string tmp;
  bool test;

  while (cin >> tmp)
  {
	tokens.push(tmp);
  }

  test = RoutineDeclaration();

  while (!tokens.empty())
	tokens.pop();

  return test;
}

bool gparser::parse(const string file)
{
  string tmp;
  bool test;

  ifstream fin;

  fin.open(file.c_str());

  while (fin >> tmp)
  {
	tokens.push(tmp);
  }

  fin.close();

  test = RoutineDeclaration();

  while(!tokens.empty())
  	tokens.pop();

  return test;
}

bool gparser::Exp()
{

  bool test = true;

  test = test && SimpExp();
  if(isRel())
  {
	test = test && Rel();
	test = test && SimpExp();
  }


  return test;
}

bool gparser::SimpExp()
{
  bool test = true;

  test = test && Term();
  while (isAddOp() && test)
  {
	test = test && AddOp();
	test = test && Term();
  }

  return test;
}

bool gparser::Term()
{
  bool test = true;

  test = test && Factor();
  while (isMultOp() && test)
  {
	test = test && MultOp();
	test = test && Factor();
  }

  return test;
}

bool gparser::Factor()
{
  bool test = true;

  if (isInt())
	test = test && Int();
  else if (isDec())
	test = test && Dec();
  else if (isStr())
	test = test && Str();
  else if (isIdent())
	test = test && Ident();
  else if (top() == "(")
  {
	pop();
	test = test && Exp();
	parseLit(")", test);
  }
  else if (top() == "~")
  {
	pop();
	test = test && Factor();
  }
  else
  {
	test = false;
  }


  return test;
}

bool gparser::isRel()
{
  bool res = true;

  if (top() != "lt" && top() != "gt" && top() != "eq")
	res = false;

  return res;
}

bool gparser::isAddOp()
{
  bool res = true;


  if (top() != "+" && top() != "-" && top() != "or")
	res = false;


  return res;
}

bool gparser::isMultOp()
{
  bool res = true;

  if (top() != "*" && top() != "/" && top() != "and")
	res = false;

  return res;
}

bool gparser::Rel()
{
  bool res = false;

  if (isRel())
  {
	res = true;
	pop();
  }

  return res;
}

bool gparser::AddOp()
{
  bool res = false;

  if (isAddOp())
  {
	res = true;
	pop();
  }

  return res;
}

bool gparser::MultOp()
{
  bool res = false;

  if (isMultOp())
  {
	res = true;
	pop();
  }

  return res;
}

void gparser::parseLit(const string txt, bool & val)
{
    if (top() == txt)
	pop();
  else
	val = false;

	return;
}

void gparser::parseIdent(bool & val)
{
  if (isIdent())
	pop();
  else
	val = false;

  return;
}

bool gparser::isInt()
{
  bool test = false;

  if (type_line(top()) == LINE_TYPES[0])
	test = true;

  return test;
}

bool gparser::Int()
{
  bool res = false;

  if (isInt())
  {
	res = true;
	pop();
  }

  return res;
}

bool gparser::isDec()
{
  bool test = false;

  if (type_line(top()) == LINE_TYPES[1])
	test = true;

  return test;
}

bool gparser::Dec()
{
  bool res = false;

  if (isDec())
  {
	res = true;
	pop();
  }

  return res;
}

bool gparser::isIdent()
{
  bool test = false;
  
  if (type_line(top()) == LINE_TYPES[6])
	test = true;

  return test;
}

bool gparser::Ident()
{
  bool res = false;

  if (isIdent())
  {
	res = true;
	pop();
  }

  return res;
}

bool gparser::isStr()
{
  bool test = true;
  string ev = top();

  unsigned int i = 0;

  if (ev[0] != '\"')
	test = false;
  else
	i++;

  while (i < top().length() && test)
  {
	if (i + 1 == top().length())
	{
	  if (ev[i] != '\"')
		test = false;
	}

	i++;
  }

  return test;
}

bool gparser::Str()
{
  bool res = false;

  if (isStr())
  {
	res = true;
	pop();
  }

  return res;
}


bool gparser::StatementSequence()
{
  bool res = true;
  bool statementloop = true;

  do
  {
	res = res && Statement();

	if (top() == "ret" || top() == "blorp" || top() == "else" || 
	    top() == "fi" || top() == "elihw")
	  statementloop = false;

  } while (statementloop && res);

  return res;
}

bool gparser::Statement()
{
  bool test = false; 

  if (top() == "inc")
	test = IncStatement();
  else if (top() == "if")
	test = IfStatement();
  else if (top() == "while")
	test = LoopStatement();
  else if (top() == "print")
	test = PrintStatement();
  else if (isIdent())
	test = Assignment();
  else 
	test = false;

  return test;
}

bool gparser::Assignment()
{
  bool test = true;

  parseIdent(test);

  parseLit("<=", test);

  test = test && Exp();

  parseLit("!", test);

  return test;

}

bool gparser::IncStatement()
{
  bool test = true;

  parseLit("inc", test);

  parseIdent(test);

  parseLit("!", test);

  return test;
}

bool gparser::IfStatement()
{
  bool test = true;

  parseLit("if", test);

  parseLit("<", test);

  test = test && Exp();

  parseLit(">", test);

  test = test && StatementSequence();

  if (top() == "else")
  {
	pop();
	test = test && StatementSequence();
  }

  parseLit("fi", test);

  return test;
}

bool gparser::LoopStatement()
{
  bool test = true;

  parseLit("while", test);

  parseLit("<", test);

  test = test && Exp();

  parseLit(">", test);

  test = test && StatementSequence();

  parseLit("elihw", test);
  
  return test;
}

bool gparser::PrintStatement()
{
  bool test = true;

  parseLit("print", test);

  parseIdent(test);

  parseLit("!", test);

  return test;
}

bool gparser::ParamSequence()
{
  bool test = true;

  parseIdent(test);

  while (top() == "," && test)
  {
	pop();
	parseIdent(test);
  }

  return test;
}

bool gparser::RoutineDeclaration()
{
  bool test = true;

  parseLit("defprog", test);

  parseIdent(test);

  parseLit("<", test);

  if (top() != ">")
	test = test && ParamSequence();

  parseLit(">", test);

  parseLit("blip", test);

  if (top() != "blorp" && top() != "ret")
	test = test && StatementSequence();

  if (top() == "ret")
  {
	pop();
	test = test && Exp();
  }

  parseLit("blorp", test);

  if (!tokens.empty())
	test = false;

  return test;
}
