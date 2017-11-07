//
//  token.hpp
//  slisp
//
//  Created by Jan Swoboda & Holger Zahnleiter on 2017-11-02
//

#ifndef Token_hpp
#define Token_hpp


//---- Include system headers C
//---- Include system headers C++
#include <string>
#include <ostream>
//---- Include 3rd party headers
//---- Include project headers


using namespace std;


namespace slisp
{
	
	class Token final
	{
		
		//----------------------------------------------------------------------
		// General/static declarations
		//----------------------------------------------------------------------
		
		public:
			enum class Type { INTEGER, L_PAREN, NAME, NONE, REAL, R_PAREN, STRING };
		
			static Token NONE;
		
		//----------------------------------------------------------------------
		// Data elements
		//----------------------------------------------------------------------
		
		private:
			Type type_;
			string value_;
			size_t line_;
			size_t column_;
		
		//----------------------------------------------------------------------
		// Construction/destruction
		//----------------------------------------------------------------------
		
		public:
			Token( const Type type, const string& value, const size_t line, const size_t column ) noexcept;
			Token( const Token& ) = default;
			Token( Token&& ) = default;
			~Token() noexcept = default;
		
		//----------------------------------------------------------------------
		// Public interface
		//----------------------------------------------------------------------
		
		public:
			Token & operator= ( const Token & ) = default;
			Token & operator= ( Token && ) = default;
		
			bool operator== ( Token const & other ) const;
			bool operator== ( Token const * const other ) const;
		
			operator Type() const;
			const std::string& value() const;
			const size_t line() const;
			const size_t column() const;
		
			explicit operator std::string() const;
		
		//----------------------------------------------------------------------
		// Internal helper methods
		//----------------------------------------------------------------------
		
		
	};
	
	
	std::ostream& operator<< ( std::ostream& outStream, const Token& token );
	
	std::ostream& operator<< ( std::ostream& outStream, const Token* token );

	
	
}


#endif /* token_hpp */
