//
//  main.cpp
//  test
//
//  Created by Jan Swoboda & Holger Zahnleiter on 2017-11-02
//

//---- Include system headers C
//---- Include system headers C++
//---- Include 3rd party headers
#include "gtest/gtest.h"
//---- Include project headers

int main(int argc, const char * argv[]) {
	testing::InitGoogleTest( &argc, (char**)argv );
	return RUN_ALL_TESTS();
}
