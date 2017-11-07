//
//  scanner.hpp
//  slisp
//
//  Created by Jan Swoboda & Holger Zahnleiter on 2017-11-02
//

#ifndef scanner_hpp
#define scanner_hpp


//---- Include system headers C
//---- Include system headers C++
#include <string>
#include <sstream>
#include <memory>
//---- Include 3rd party headers
//---- Include project headers
#include "scanner_if.hpp"


using namespace std;


namespace slisp
{
	
	class Scanner final : public ScannerIf
	{
		
		//----------------------------------------------------------------------
		// General/static declarations
		//----------------------------------------------------------------------
		
		//----------------------------------------------------------------------
		// Data elements
		//----------------------------------------------------------------------
		
		private:
			unique_ptr<istringstream> input_;
			Token lookAhead_ = Token::NONE;
			size_t line_ = 1;
			size_t column_ = 1;
		
		//----------------------------------------------------------------------
		// Construction/destruction
		//----------------------------------------------------------------------
		
		public:
			Scanner( unique_ptr<istringstream> input );
			Scanner( const string& input );
			Scanner( const Scanner& ) = delete;
			Scanner( Scanner&& ) = default;
			virtual ~Scanner() = default;
		
		//----------------------------------------------------------------------
		// Public interface
		//----------------------------------------------------------------------
		
		public:
			bool hasMore() const override;
			Token consume() override;
			const Token& peek() const override;
		
		//----------------------------------------------------------------------
		// Internal helper methods
		//----------------------------------------------------------------------
		
		private:
			Token readAhead();
		
	};
	
	
}


#endif /* scanner_hpp */
