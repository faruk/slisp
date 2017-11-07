//
//  text.hpp
//  slisp
//
//  Created by Jan Swoboda & Holger Zahnleiter on 2017-11-02
//

#ifndef text_hpp
#define text_hpp


//---- Include system headers C
//---- Include system headers C++
#include <string>
//---- Include 3rd party headers
//---- Include project headers


using namespace std;


namespace slisp::text
{
	
	bool containsWhiteSpace( const string& text );
	string escape( const char charToEscape, const string& input );
	string escape( const string& charsToEscape, const string& input );
	string doubleQuoted( const string& input );
	string singleQuoted( const string& input );
	
}


#endif /* text_hpp */
