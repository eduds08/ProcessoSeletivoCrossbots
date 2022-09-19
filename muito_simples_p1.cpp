#include <iostream>
#include <math.h>

float distancia(float p1[], float p2[]);

int main() {

	float ponto1[2], ponto2[2];

	std::cout << "Coordenada X do ponto 1: " << std::endl;
	std::cin >> ponto1[0];
	std::cout << "Coordenada Y do ponto 1: " << std::endl;
	std::cin >> ponto1[1];

	std::cout << "Coordenada X do ponto 2: " << std::endl;
	std::cin >> ponto2[0];
	std::cout << "Coordenada Y do ponto 2: " << std::endl;
	std::cin >> ponto2[1];

	std::cout << distancia(ponto1, ponto2) << std::endl;

	return 0;
}

float distancia(float p1[], float p2[]) {
	float dist = sqrt(pow((p2[0] - p1[0]), 2) + pow((p2[1] - p1[1]), 2));
	return dist;
}
