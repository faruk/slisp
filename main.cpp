//
//  main.cpp
//  slisp
//
//  Created by Jan Swoboda & Holger Zahnleiter on 2017-11-02
//

//---- Include system headers C
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
//---- Include system headers C++
#include <iostream>
//---- Include 3rd party headers
//---- Include project headers

using namespace std;


int main(int argc, const char * argv[]) {
	cout << "++++ Welcome to slisp ++++" << endl;
	cout << "2017-11-02, Jan Swoboda, Holger Zahnleiter" << endl;
	
	char *buf;
	while( nullptr != (buf = readline( "\n>> " )) )
	{
		cout << buf << endl;
		if ( 0 != buf[0] )
			add_history( buf );
	}
	free( buf );
	
	return 0;
}
