//=================================================================
// Example: function template
//
// Author:	Jen Miller
// Date:	4/12/16
// Purpose:	To demonstrate the creation and use of a 
//            simple function template in C++
//
//  1) Cut and paste code into .cpp file,
//  2) Look at largerInt() function, think about how it would be 
//	different for chars, floats, strings, etc..
//  3) Discuss template function.
//  4) test it (compile and run)
//
//=================================================================

#include <iostream>

using namespace std;

// function prototype
int largerInt(int a, int b); // only works on integers

							 // template function prototype - should work with any data type for
							 // which the relational operator >= is defined
template <class type>
type larger(type a, type b);

void main()
{
	// test the largerInt function
	cout << "The larger between 2 and 3 is: " << largerInt(2, 3) << endl;
	cout << "The larger between -2 and 13 is: " << largerInt(-2, 13) << endl;

	// test the larger function (should work with multiple types)
	cout << "The larger between 2 and 3 is: " << larger(2, 3) << endl;
	cout << "The larger between 'A' and 'C' is: " << larger('C', 'A') << endl;
	cout << "The larger between 1.5 and 3.14 is: " << larger(1.5, 3.14) << endl;
}

//===============================================================
// Function Name:   largerInt	
// Description:		Compares two integers and returns the larger
//                  of the two
// Parameters:		a, b (both integers)	
// Return Value:	int - the larger between a and b
//===============================================================
int largerInt(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

//===============================================================
// Function Name:   larger	
// Description:		Compares two values of flexible data type 
//                  and returns the larger of the two
// Parameters:		a, b (both of the same data type)	
// Return Value:	the same data type as a and b
//===============================================================
template <class type>
type larger(type a, type b)
{
	if (a >= b)
		return a;
	else
		return b;
}

