#include <iostream>
#include <vector>

const int MAX = 10000;

int main() {

	std::vector<int> lista;

	int qtdNum;
	int num;
	
	std::cout << "Quantidade de numeros: ";
	std::cin >> qtdNum;

	for (int i = 0; i < qtdNum; i++) {
		std::cout << "Digite um numero: ";
		std::cin >> num;

		lista.push_back(num);
	}

	int* listaAux;
	listaAux = new int[MAX];

	std::fill_n(listaAux, MAX, 0); // zera todos os elementos da lista auxiliar

	std::vector<int>::iterator j; // iterador do std::vector

	int valor;

	/*
		A l�gica aqui � adicionar 1 unidade a casa do vetor auxiliar cuja posi��o � o valor do elemento da lista. Por exemplo, se o elemento da lista
		� 2, adicionaremos 1 unidade para listaAux[2].
		Ou seja, se listaAux[t] > 1, significa que o valor "t" apareceu mais de uma vez na lista e a� usamos o erase() para remover o elemento repetido.
	*/

	for (size_t i = 0; i < lista.size(); i++) {

		valor = lista[i];

		listaAux[valor] += 1;

		if (listaAux[valor] > 1) {
			j = lista.begin() + i; // a vari�vel j recebe o �ndice i 
			lista.erase(j);  // apaga o elemento repetido na lista
			listaAux[valor] -= 1;  // diminui uma unidade da lista auxiliar, j� que o elemento repetido foi apagado
			i--;  // como um elemento foi apagado da lista, o �ndice i precisa recuar 1 unidade para n�o pular nenhum valor da lista
		}
	}

	for (size_t i = 0; i < lista.size(); i++)
		std::cout << lista[i] << " ";

	std::cout << "\n";

	delete[] listaAux;

	return 0;
}
