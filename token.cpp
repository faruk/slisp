//
//  token.cpp
//  slisp
//
//  Created by Jan Swoboda & Holger Zahnleiter on 2017-11-02
//

//---- Corresponding header
#include "token.hpp"
//---- Include system headers C
//---- Include system headers C++
#include <sstream>
//---- Include 3rd party headers
//---- Include project headers
#include "text.hpp"


namespace slisp
{
	
	//--------------------------------------------------------------------------
	// General/static declarations
	//--------------------------------------------------------------------------
	
	Token Token::NONE{Type::NONE, "", 0, 0};
	
	std::ostream& operator<< ( std::ostream& outStream, const Token& token )
	{
		return outStream << (string)token;
	}
	
	std::ostream& operator<< ( std::ostream& outStream, const Token* token )
	{
		return outStream << (nullptr == token ? "nullptr" : (string)*token);
	}
	
	
	//--------------------------------------------------------------------------
	// Construction/destruction
	//--------------------------------------------------------------------------
	
	Token::Token( const Type type, const std::string& value, const size_t line, const size_t column ) noexcept : type_( type ), value_( value ), line_( line ), column_( column )
	{
	}

	
	//--------------------------------------------------------------------------
	// Public interface
	//--------------------------------------------------------------------------
	
	
	bool Token::operator== ( Token const & other ) const
	{
		if ( type_ != other.type_ )
			return false;
		return value_ == other.value_;
	}
	
	
	bool Token::operator== ( Token const * const other ) const
	{
		return nullptr == other ? false : *this == *other;
	}
	
	
	Token::operator Type() const
	{
		return type_;
	}
	
	const std::string& Token::value() const
	{
		return value_;
	}
	
	
	const size_t Token::line() const
	{
		return line_;
	}
	
	
	const size_t Token::column() const
	{
		return column_;
	}
	
	
	Token::operator std::string() const
	{
		ostringstream result;
		result << "(TOKEN " << line_ << " " << column_ << " " << text::singleQuoted( value_ ) << ")";
		return result.str();
	}
	
	
	//--------------------------------------------------------------------------
	// Internal helper methods
	//--------------------------------------------------------------------------
	
}
