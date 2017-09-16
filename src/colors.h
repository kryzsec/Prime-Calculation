#ifndef colors_h
#define colors_h


#include <cstring>
using std::string;

string purple = "\033[95m";
string blue = "\033[94m";
string green = "\033[92m";
string yellow = "\033[93m";
string red = "\033[91m";
string white = "\033[0m";
string BOLD = "\033[1m";
string UNDERLINE = "\033[4m";

string errr = white + "[" + red + "!" + white + "] ";
string warn = white + "[" + red + "*" + white + "] ";
string cont = white + "[" + red + "&" + white + "] ";
string pric = white + "[" + red + "$" + white + "] ";
string meta = white + "[" + red + "#" + white + "] ";
string attg = white + "[" + red + "@" + white + "] ";
string addt = white + "[" + red + "+" + white + "] ";
string ques = white + "[" + red + "?" + white + "] ";

#endif
