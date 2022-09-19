#include <iostream>
#include <vector>

std::vector<int> encontra_primo(std::vector<int> l);

int main() {

	std::vector<int> lista;

	int valor = 0;

	while (valor != -999) {
		std::cout << "Digite um valor para adicionar na lista (-999 para terminar): ";
		std::cin >> valor;

		if (valor != -999)
			lista.push_back(valor);	
	}

	lista = encontra_primo(lista);

	for (auto i = lista.begin(); i != lista.end(); ++i)
		std::cout << *i << " ";

	std::cout << "\n";

	return 0;
}

std::vector<int> encontra_primo(std::vector<int> l) {

	int j;

	std::vector<int> primos;
	bool primo;

	for (int i = 0; i < l.size() - 1; i++) {
		primo = true;
		j = l[i];
		
		if (j >= 2) {
			for (int k = 2; k * k <= j; k++)
				if (j % k == 0)
					primo = false;
		}
		else
			primo = false;

		if (primo)
			primos.push_back(j);
	}

	return primos;
}