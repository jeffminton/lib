/**
Programmer:		Jeffrey Minton
File:			util.cpp
Description:	A file containing various utilities
*/


#include "util.h"


//match
bool Util::match(string str, string pattern)
{
	regex regPattern = regex(pattern);

	return regex_match(str, regPattern);
}


//getMatch
string Util::getMatch(string str, string pattern, int grp)
{
	regex regPattern = regex(pattern);
	smatch regOut;

	if(regex_match(str, regOut, regPattern) == false)
	{
		return "";
	}

	return regOut[grp];
}


//split
vector<string> Util::split(string str, string pattern)
{
	vector<string> out;
	regex splitReg = regex(pattern);

	const sregex_token_iterator end;

	for(sregex_token_iterator i(str.begin(), str.end(), splitReg); i != end; ++i)
	{
		out.push_back(*i);
	}

	return out;
}


//strip
void Util::strip(string &str)
{
	str = getMatch(str, STRIPLINE, 1);

	return;
}