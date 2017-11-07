//
//  scanner_test.cpp
//  test
//
//  Created by Jan Swoboda & Holger Zahnleiter on 2017-11-02
//

//---- Include system headers C
//---- Include system headers C++
//---- Include 3rd party headers
#include "gtest/gtest.h"
//---- Include project headers
#include "scanner.hpp"


using namespace std;
using namespace slisp;


TEST( Scanner, emptyInputWillNotCauseTrouble )
{
	Scanner scanner{""};
	ASSERT_FALSE( scanner.hasMore() );
	ASSERT_EQ( Token::NONE, scanner.peek() );
	ASSERT_EQ( Token::NONE, scanner.consume() );
}


TEST( Scanner, scanSingleInteger )
{
	Scanner scanner{"123"};
	ASSERT_TRUE( scanner.hasMore() );
	ASSERT_EQ( Token::NONE, scanner.peek() );
	auto token = scanner.consume();
	ASSERT_EQ( "123", token.value() );
	ASSERT_EQ( Token::Type::INTEGER, token );
	ASSERT_EQ( 1, token.line() );
	ASSERT_EQ( 1, token.column() );
	ASSERT_FALSE( scanner.hasMore() );
}

TEST( Scanner, scanMultipleIntegers )
{
	Scanner scanner{"123 456 789"};
	
	ASSERT_TRUE( scanner.hasMore() );
	ASSERT_EQ( "456", scanner.peek().value() );
	auto token = scanner.consume();
	ASSERT_EQ( "123", token.value() );
	ASSERT_EQ( Token::Type::INTEGER, token );
	ASSERT_EQ( 1, token.line() );
	ASSERT_EQ( 1, token.column() );
	
	ASSERT_TRUE( scanner.hasMore() );
	ASSERT_EQ( "789", scanner.peek().value() );
	token = scanner.consume();
	ASSERT_EQ( "456", token.value() );
	ASSERT_EQ( Token::Type::INTEGER, token );
	ASSERT_EQ( 1, token.line() );
	ASSERT_EQ( 5, token.column() );
	
	ASSERT_TRUE( scanner.hasMore() );
	ASSERT_EQ( Token::NONE, scanner.peek() );
	token = scanner.consume();
	ASSERT_EQ( "789", token.value() );
	ASSERT_EQ( Token::Type::INTEGER, token );
	ASSERT_EQ( 1, token.line() );
	ASSERT_EQ( 9, token.column() );
	
	ASSERT_FALSE( scanner.hasMore() );
}


TEST( Scanner, scanSimpleExpression )
{
	Scanner scanner{"(def! pi 3.14)"};
	
	ASSERT_TRUE( scanner.hasMore() );
	auto token = scanner.consume();
	ASSERT_EQ( "(", token.value() );
	ASSERT_EQ( Token::Type::L_PAREN, token );
	ASSERT_EQ( 1, token.line() );
	ASSERT_EQ( 1, token.column() );
	
	ASSERT_TRUE( scanner.hasMore() );
	token = scanner.consume();
	ASSERT_EQ( "def!", token.value() );
	ASSERT_EQ( Token::Type::NAME, token );
	ASSERT_EQ( 1, token.line() );
	ASSERT_EQ( 2, token.column() );
	
	ASSERT_TRUE( scanner.hasMore() );
	token = scanner.consume();
	ASSERT_EQ( "pi", token.value() );
	ASSERT_EQ( Token::Type::NAME, token );
	ASSERT_EQ( 1, token.line() );
	ASSERT_EQ( 7, token.column() );
	
	ASSERT_TRUE( scanner.hasMore() );
	token = scanner.consume();
	ASSERT_EQ( "3.14", token.value() );
	ASSERT_EQ( Token::Type::REAL, token );
	ASSERT_EQ( 1, token.line() );
	ASSERT_EQ( 10, token.column() );
	
	ASSERT_TRUE( scanner.hasMore() );
	token = scanner.consume();
	ASSERT_EQ( ")", token.value() );
	ASSERT_EQ( Token::Type::R_PAREN, token );
	ASSERT_EQ( 1, token.line() );
	ASSERT_EQ( 14, token.column() );
	
	ASSERT_FALSE( scanner.hasMore() );
}

