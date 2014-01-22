
#include <iostream>  // Provides cout, cin
#include <cstdlib>   // Provides EXIT_SUCCESS
using namespace std;


double underflow_double( );

float underflow_float( );

int main( )
{
    cout << underflow_float() << endl;
    cout << underflow_double() << endl;
    return EXIT_SUCCESS;
}

double underflow_double( )
{
    double n1 = 1;
    while(n1/2.0 != 0.0)
    	n1 = n1/2.0;
	return n1;	// more is needed here
}

float underflow_float( )
{
    float n1 = 1;
    while(n1/2 != 0)
    	n1 = n1/2;
	return n1;	// more is needed here
}
