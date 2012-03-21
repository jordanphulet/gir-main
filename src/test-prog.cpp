#include <cstdio>
#include <TCPCommunicator.h>

int main( int argc, char** argv )
{
	printf( "testing...\n" );

	// connect
	char* ip_address = "sebulba";
	char* port = "9999";
	printf( "Connecting to %s:%s...\n", ip_address, port );
	TCPCommunicator communicator;
	if( !communicator.Connect( ip_address, port ) )
		printf( "communicator.Connect() failed!\n" );

	return 0;
}
