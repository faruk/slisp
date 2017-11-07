//
//  scanner.cpp
//  slisp
//
//  Created by Jan Swoboda & Holger Zahnleiter on 2017-11-02
//

//---- Corresponding header
#include "scanner.hpp"
//---- Include system headers C
//---- Include system headers C++
//---- Include 3rd party headers
//---- Include project headers


namespace slisp
{
	
	//--------------------------------------------------------------------------
	// General/static declarations
	//--------------------------------------------------------------------------
	
	//--------------------------------------------------------------------------
	// Construction/destruction
	//--------------------------------------------------------------------------
	
	Scanner::Scanner( unique_ptr<istringstream> input ) : input_( move( input ) )
	{
		lookAhead_ = readAhead();
	}
	
	
	Scanner::Scanner( const string& input ) : Scanner( make_unique<istringstream>( input ) )
	{
	}
	
	
	//--------------------------------------------------------------------------
	// Public interface
	//--------------------------------------------------------------------------
	
	bool Scanner::hasMore() const
	{
		return Token::NONE != lookAhead_;
	}
	
	
	Token Scanner::consume()
	{
		auto current = lookAhead_;
		lookAhead_ = readAhead();
		return current;
	}
	
	
	const Token& Scanner::peek() const
	{
		return lookAhead_;
	}
	
	
	//--------------------------------------------------------------------------
	// Internal helper methods
	//--------------------------------------------------------------------------

	Token Scanner::readAhead()
	{
// TODO swoboda
		return Token::NONE;
	}
	
	
}
