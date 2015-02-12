#include <iostream>

// CallBack function - A function that's called when an event occurs.

void cb_function (int a) {

std::cout <<"--------I'm inside the Call Back Function Doing Nothing. I just entered --------" << a << "\n";

}

// Demonstrating Callback Functions and their variations

void register_callback(void (*callback)(int a)) {

	int x = 1;

	std::cout <<"--------I registered a Callback Function--------\n";
	
	/*
		Imagine this running in a seperate thread and all the events occuring. 
		As soon as the user desired event occurs, that callback function is 
		called using the pointer passed in this function. 
	*/

	do{

		std::cout<<

		"Enter the value for x";

		std::cin >> x;

	}
	while (x==1);
	(*callback) (x);
	
}


int main ()

{
	
	
	void (*my_cb_function) (int a); // Pointer to the callback function

	my_cb_function = &cb_function; // Initializing the pointer to the callback function

	register_callback(my_cb_function); // Registering the callback function

	return 1;

}