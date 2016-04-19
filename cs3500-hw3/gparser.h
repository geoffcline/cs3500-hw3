#pragma once

#include <queue>
#include <string>
#include <iostream>
#include <regex>
#include <fstream>

using namespace std;

class gparser
{
  queue<string> tokens;
  bool Exp();
  bool SimpExp();
  bool isRel();
  bool Rel();
  bool Term();
  bool isAddOp();
  bool AddOp();
  bool Factor();
  bool isMultOp();
  bool MultOp();
  bool isInt();
  bool isDec();
  bool isStr();
  bool isIdent();
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
  void pop();

  void parseLit(const string txt, bool& val);
  void parseIdent(bool &val);

public:
  gparser();
  ~gparser();
  bool parse();
  bool parse(const string& file);
};

