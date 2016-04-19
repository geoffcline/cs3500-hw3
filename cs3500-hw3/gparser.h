#pragma once

#include "stdafx.h"
#include <queue>
#include <string>
#include <iostream>
#include <regex>

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

  bool StatementSequence(); //HALP
  bool Statement(); //HALP

  bool Assignment();
  bool IncStatement();
  bool IfStatement();
  bool LoopStatement();
  bool PrintStatement();

  bool ParamSequence();
  bool RoutineDeclaration();

  string top() { return tokens.front(); }
  string pop() { tokens.pop(); }

  void parseLit(const string txt, bool& val);
  void parseIdent(bool &val);

public:
  gparser();
  ~gparser();
  bool parse();
};

