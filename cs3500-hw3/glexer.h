// Geoffrey Cline
// CS3500 - HW 3
// 4/19/2016

#ifndef GLEXER_H
#define GLEXER_H

#include <string>
#include <iostream>
#include <queue>

using namespace std;

const string LINE_TYPES[] = { "Integer.", "Decimal.", "Scientific.", "Hexadecimal.", 
                 "Binary.", "Keyword.", "Identifier.", "Invalid!" };
const int LINE_TYPES_SZ = 8;

const string KEYWORDS[]   = { "while", "else", "end", "print" };
const int KEYWORDS_SZ = 4;

string type_line(const string s);

#endif
