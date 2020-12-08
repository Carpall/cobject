#include <iostream>
#include "CObject.h"

int main() {
	Object myobj = 23+23;
	myobj = "Hello World!";
	std::cout << "Type: "   << TypeToString(myobj.GetType()) << " Size: " << myobj.GetSize()
			  << " Value: " << myobj.ToString();
}