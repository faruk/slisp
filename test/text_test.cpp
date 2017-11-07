//
//  text_test.cpp
//  test
//
//  Created by Jan Swoboda & Holger Zahnleiter on 2017-11-02
//

//---- Include system headers C
//---- Include system headers C++
//---- Include 3rd party headers
#include "gtest/gtest.h"
//---- Include project headers
#include "text.hpp"


using namespace std;
using namespace slisp;


TEST( Text, makeSureWhitespaceRecognized )
{
	ASSERT_TRUE( slisp::text::containsWhiteSpace( " " ) );
	ASSERT_TRUE( slisp::text::containsWhiteSpace( "Hello, World!" ) );
	ASSERT_TRUE( slisp::text::containsWhiteSpace( "This is a \tab" ) );
}


TEST( Text, makeSureNoWhitespaceRecognized )
{
	ASSERT_FALSE( slisp::text::containsWhiteSpace( "" ) );
	ASSERT_FALSE( slisp::text::containsWhiteSpace( "Hello,World!" ) );
	ASSERT_FALSE( slisp::text::containsWhiteSpace( "Thisisatab" ) );
}

// TODO swoboda test für escape, doubleQuoted und singleQuoted
