#pragma once

#include "stdafx.h"
#include <stack>
#include <string>
#include <iostream>
#include <regex>

using namespace std;

class gparser
{
  stack<string> tokens;
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

  char getTopChar();

public:
  gparser();
  ~gparser();
  bool parse();
};

