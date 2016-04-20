// Geoffrey Cline
// CS3500 - HW 3
// 4/19/2016

#pragma once

#include <queue>
#include <string>
#include <iostream>
#include <boost/regex.hpp>
#include <fstream>

using namespace std;

class gparser
{
  queue<string> tokens;

  bool isRel();
  bool isInt();
  bool isDec();
  bool isStr();
  bool isAddOp();
  bool isMultOp();
  bool isIdent();

  bool Rel();
  bool Term();
  bool AddOp();
  bool Factor();
  bool MultOp();
  
  bool Exp();
  bool SimpExp();
  
  bool Int();
  bool Dec();
  bool Str();
  bool Ident();

  bool StatementSequence();
  bool Statement();

  bool Assignment();
  bool IncStatement();
  bool IfStatement();
  bool LoopStatement();
  bool PrintStatement();

  bool ParamSequence();
  bool RoutineDeclaration();

  bool empty() {return tokens.empty();}

  string top() { return (tokens.empty() ? "\0" : tokens.front()); }
  void pop() { if (!tokens.empty()) { tokens.pop(); } }

  void parseLit(const string txt, bool& val);
  void parseIdent(bool &val);

public:
  gparser();
  ~gparser();
  bool parse();
};

