// Geoffrey Cline
// CS3500 - HW 3
// 4/19/2016

#pragma once

#include <queue>
#include <string>
#include <iostream>
#include <fstream>
#include "glexer.h"

using namespace std;

class gparser
{
  queue<string> tokens;

  //determine type of top() token
  bool isRel() const;
  bool isInt() const;
  bool isDec() const;
  bool isStr() const;
  bool isAddOp() const;
  bool isMultOp() const;
  bool isIdent() const;

  //parse elements of expression
  bool Rel();
  bool Term();
  bool AddOp();
  bool Factor();
  bool MultOp();
  bool Int();
  bool Dec();
  bool Str();
  bool Ident();
	void parseIdent(bool &val);

	//parse given string, updates test variable
	void parseLit(const string txt, bool& val);

  //parse expressions
  bool Exp();
  bool SimpExp();

	//parse types of statements
	bool Assignment();
  bool IncStatement();
  bool IfStatement();
  bool LoopStatement();
  bool PrintStatement();

	//parse statements
  bool StatementSequence();
  bool Statement();
	bool ParamSequence();

	//parse program
  bool RoutineDeclaration();

	//token queue manipulation fuctions
  bool empty() {return tokens.empty();}
  string top() { return (tokens.empty() ? "\0" : tokens.front()); }
  void pop() { if (!tokens.empty()) { tokens.pop(); } }


public:
  gparser();
  ~gparser();

	//parse from cin
  bool parse();

	//parse from file
  bool parse(const string file);
};

