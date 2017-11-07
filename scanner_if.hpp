//
//  scanner_if.hpp
//  slisp
//
//  Created by Jan Swoboda & Holger Zahnleiter on 2017-11-02
//

#ifndef scanner_if_hpp
#define scanner_if_hpp


//---- Include system headers C
//---- Include system headers C++
//---- Include 3rd party headers
//---- Include project headers
#include "token.hpp"


namespace slisp
{
	
	class ScannerIf
	{
		
		//----------------------------------------------------------------------
		// General/static declarations
		//----------------------------------------------------------------------
		
		//----------------------------------------------------------------------
		// Data elements
		//----------------------------------------------------------------------
		
		//----------------------------------------------------------------------
		// Construction/destruction
		//----------------------------------------------------------------------
		
		public:
			ScannerIf() = default;
			ScannerIf( const ScannerIf& ) = delete;
			ScannerIf( ScannerIf&& ) = default;
			virtual ~ScannerIf() = default;
		
		//----------------------------------------------------------------------
		// Public interface
		//----------------------------------------------------------------------
		
		public:
			virtual bool hasMore() const = 0;
			virtual Token consume() = 0;
			virtual const Token& peek() const = 0;
		
		//----------------------------------------------------------------------
		// Internal helper methods
		//----------------------------------------------------------------------
		
		
	};
	

}

#endif /* scanner_if_hpp */
