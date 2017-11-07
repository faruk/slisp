//
//  token_test.cpp
//  test
//
//  Created by Jan Swoboda & Holger Zahnleiter on 2017-11-02
//

//---- Include system headers C
//---- Include system headers C++
#include <sstream>
//---- Include 3rd party headers
#include "gtest/gtest.h"
//---- Include project headers
#include "token.hpp"


using namespace std;
using namespace slisp;


TEST( Token, tokenInitializedCorrectly )
{
	Token token{Token::Type::INTEGER, "123", 4, 5};
	ASSERT_EQ( Token::Type::INTEGER, (Token::Type)token );
	ASSERT_EQ( Token::Type::INTEGER, token );
	ASSERT_EQ( "123", token.value() );
	ASSERT_EQ( 4, token.line() );
	ASSERT_EQ( 5, token.column() );
}


TEST( Token, tokenAsString )
{
	Token token{Token::Type::STRING, "Hello!", 12, 13};
	ASSERT_EQ( "(TOKEN 12 13 'Hello!')", (string)token );
}


TEST( Token, tokenPrintedToStream )
{
	Token token{Token::Type::STRING, "Hello!", 12, 13};
	ostringstream stream;
	stream << token;
	ASSERT_EQ( "(TOKEN 12 13 'Hello!')", stream.str() );
}

// TODO swoboda test für vergleichs- und zuweisungsoperatoren
