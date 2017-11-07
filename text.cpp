//
//  text.cpp
//  slisp
//
//  Created by Jan Swoboda & Holger Zahnleiter on 2017-11-02
//

//---- Corresponding header
#include "text.hpp"
//---- Include system headers C
//---- Include system headers C++
//---- Include 3rd party headers
//---- Include project headers



namespace slisp::text
{
	
	
	bool containsWhiteSpace( const string& text )
	{
		for( const auto c : text )
		{
			if ( isspace( c ) ) return true;
		}
		return false;
	}
	
	
	string escape( const char charToEscape, const string& input )
	{
		string l_result;
		for ( const auto l_char : input )
		{
			if ( '\\' == l_char || charToEscape == l_char )
				l_result += '\\';
			l_result += l_char;
		}
		return l_result;
	}
	
	
	string escape( const string& charsToEscape, const string& input )
	{
		string l_result;
		for ( const auto l_char : input )
		{
			if ( '\\' == l_char || charsToEscape.length() >= charsToEscape.find( l_char ) )
				l_result += '\\';
			l_result += l_char;
		}
		return l_result;
	}
	
	
	string doubleQuoted( const string& input )
	{
		return '"' + escape( '"', input ) + '"';
	}
	
	
	string singleQuoted( const string& input )
	{
		return '\'' + escape( '\'', input ) + '\'';
	}
	
	
}
