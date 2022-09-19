#include <iostream>

int main() {

	int lista[10];

	for (int i = 0; i < 10; i++) {
		std::cout << "Digite o " << i << " valor da lista: " << std::endl;
		std::cin >> lista[i];
	}

	for (int i = 0; i < 10; i++)
		std::cout << lista[i] << ", ";

	std::cout << "\n";

	int x = -1, y = -1;

	while (x < 0 || x > 9) {
		std::cout << "Digite x: " << std::endl;
		std::cin >> x;
	}
	while (y < 0 || y > 9) {
		std::cout << "Digite y: " << std::endl;
		std::cin >> y;
	}
	
	int soma = lista[x] + lista[y];

	std::cout << "Soma: " << soma << std::endl;

	return 0;
}
