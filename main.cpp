#include <Windows.h>
#include <iostream>
#include <thread>
#include <chrono>

#include "vars.h"

int main(){

	std::cout << "Bind: ";
	while (bool keypress = true){ // simple while loop that is controlled with the "keypress" variable
		for (int i = 8; i <= 255; i++){ // up to 8 so we can remove the mouse inputs
			if (GetAsyncKeyState(i)) {
				keypress = false; // stop the key recording
				system("cls"); // clear the console
				asd::bind_ascii = i; 
				std::cout << "keybind set to: " <<asd::bind_ascii;

			}
		}
	}

	Sleep(1000);

	system("cls");

	std::cout << "activated? : " << asd::activated[0];

	while (true){

		if (GetAsyncKeyState(asd::bind_ascii)){

			asd::toggled = !asd::toggled; // sets the bool to what its not thanks to !

			system("cls");

			if (asd::toggled) std::cout << "activated? : " << asd::activated[asd::toggled]; // if its activated then print this
			else std::cout << "activated? : " << asd::activated[asd::toggled]; // if its dissabled then print this

			Sleep(200);

		}
	}
}
