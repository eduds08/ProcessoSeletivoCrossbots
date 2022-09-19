#include <iostream>

float converte_temperatura(float gF);

int main() {

	float grausF;

	std::cout << "Temperatura em graus Fahrenheit: " << std::endl;
	std::cin >> grausF;

	std::cout << converte_temperatura(grausF) << std::endl;

	return 0;
}

float converte_temperatura(float gF) {
	float gC = (gF - 32) / 1.8f;
	return gC;
}