/**
Programmer:		Jeffrey Minton
File:			util.h
Description:	A file containing various utilities
*/


#include <regex>
#include <vector>
#include <string>

#define STRIPLINE "^\\s*(.*)\\s$"
#define IGNORE_TAG "<\\?.*\\?>"
#define TAG "^<.*>$"
#define CLOSE_TAG "^</.*>$"
#define CLOSE_TAG_NAME "</(\\w+)>"
#define ONE_LINE_TAG "^<.+/>$"
#define ONE_LINE_OPEN_CLOSE "(<.*>)(.+)(</.*>)"
#define OPEN_TAG_NAME "<(\\w+).*>"
#define ATTRIBUTE "(\\w+\\s*=\\s*\"\\w+\")"
#define ATTR_SPLIT "(\\w+)\\s*=\\s*\"(\\w+)\""
#define WORD_SPLIT "(\\w+)"

using namespace std;

class Util
{
public:
	/**
	Function:		match
	Description:	Determines if a string matches a regex
	Parameters:		string str - the string ti check
					string pattern - the pattern to search for
	Return:			bool - true matches, false, no match
	*/
	bool match(string str, string pattern);


	/**
	Function:		getMatch
	Description:	return the substring from a string that
					matches the given group of a regex
	Parameters:		string str - the string to match
					string pattern - the pattern to match
					int grp - the group of the regex to return
	Return:			string - the sub string representing the group
					null if not found
	*/
	string getMatch(string str, string pattern, int grp);

	/**
	Function:		split
	Description:	return a vector containing all items in a string
					that match a give regex
	Parameters:		string str - the string to split
					string pattern - the regex patter to split on
	Return:			vector<string> - vector containing items
	*/
	vector<string> split(string str, string pattern);

	/**
	Function:		strip
	Description:	remove the leading and trailing white space from
					a string
	Parameters:		string str - the string to strip
	*/
	void strip(string &str);
};

