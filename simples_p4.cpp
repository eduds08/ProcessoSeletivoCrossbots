#include <iostream>
#include <string>

int encontra_letra(const char& letra, const std::string& frase);

int main() {

	char letra;
	std::string frase;

	std::cout << "Digite uma letra: ";
	std::cin >> letra;

	// acabar com o problema do getline ler o \n do std::cin
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Digite uma frase: ";
	std::getline(std::cin, frase);

	std::cout << encontra_letra(letra, frase);

	return 0;
}

int encontra_letra(const char& letra, const std::string& frase) {
	int soma = 0;
	for (auto i = frase.begin(); i != frase.end(); i++)
		if (letra == *i)
			soma++;
	return soma;
}