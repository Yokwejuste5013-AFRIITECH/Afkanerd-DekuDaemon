#include "helpers.hpp"
#include "declarations.hpp"
#include "gl_request_queue_listener.cxx"


using namespace std;


string test_request_file = string( getenv("HOME")) + "/deku/test_request.txt";
string sample_request_string = "number=0000000,message=\"sample request\nmessage\"";

int main() {
	CURRENT_SYSTEM_STATE = "TESTING";
	//CURRENT_SYSTEM_STATE = "PRODUCTION";

	cout << "Testing=> gl_request_queue_listener => " << endl;
	// input = filename, output = stats
	helpers::write_file( test_request_file, sample_request_string, ios::trunc, true );

	//TODO: Build a tester function, not this manual method
	if( map<string, string[2] > test_gl_request_queue_listener = gl_request_queue_listener( test_request_file.c_str() ); test_gl_request_queue_listener.size() != helpers::read_file( test_request_file ).size() ) {
		cout << "Testing=> Failed...." << endl;
		cout << "processed request = " << test_gl_request_queue_listener.size() <<endl;
		cout << "expected request = " << helpers::read_file( test_request_file).size() << endl;
	}
	else {
		cout << "Testing=> Passed..." << endl;
		cout << "processed request = " << test_gl_request_queue_listener.size() <<endl;
		cout << "expected request = " << helpers::read_file( test_request_file).size() << endl;
	}


	return 0;
}
