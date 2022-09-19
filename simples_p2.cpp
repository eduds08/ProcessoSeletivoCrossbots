#include <iostream>

bool eh_perfeito(int num);

int main() {

	int n;

	std::cout << "Digite um valor: ";
	std::cin >> n;

	eh_perfeito(n) ? std::cout << "Eh perfeito" << std::endl : std::cout << "Nao eh perfeito" << std::endl;
		
	return 0;
}

bool eh_perfeito(int num) {

	int soma = 0;

	for (int i = num - 1; i > 0; i--)
		if (num % i == 0)
			soma += i;

	if (soma == num)
		return true;
	return false;
}