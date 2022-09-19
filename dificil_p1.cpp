#include <iostream>
#include <string>

int main() {

	int nCasos;

	std::cout << "Quantidade de casos de teste: ";
	std::cin >> nCasos;

	std::string mina;

	int diamantes;

	bool cavouPedra = false;
	bool cavouDiamante1 = false;
	bool cavouDiamante2 = false;

	while (nCasos--) {

		diamantes = 0;

		std::cout << "Digite a mina: ";
		std::cin >> mina;

		for (int i = 0; i < mina.size(); i++) {

			cavouPedra = false;
			cavouDiamante1 = false;
			cavouDiamante2 = false;
			
			// Remove as pedras da mina
			if (mina[i] == '.') {
				mina.erase(mina.begin() + i);
				cavouPedra = true;
			}

			// Confere se a posição atual e a posição seguinte formam um diamante. Caso afirmativo, remove o diamante e soma 1 a variavel diamantes.
			if (mina[i] == '<' && mina[i + 1] == '>') {
				diamantes++;
				mina.erase(mina.begin() + i);
				mina.erase(mina.begin() + i);
				cavouDiamante1 = true;
			}

			// Confere se a posição anterior e a posição atual formam um diamante. Caso afirmativo, remove o diamante e soma 1 a variavel diamantes.
			if (i - 1 >= 0) {
				if (mina[i - 1] == '<' && mina[i] == '>') {
					diamantes++;
					mina.erase(mina.begin() + i - 1);
					mina.erase(mina.begin() + i - 1);
					cavouDiamante2 = true;
				}
			}

			/*
			A parte a seguir ajusta o índice i de acordo com quais elementos foram removidos da mina.
			Serve para o índice i não "pular" nenhum elemento do vetor da mina 
			*/
			if (cavouPedra)
				i--;
			if (cavouDiamante1)
				i -= 2;
			if (cavouDiamante2)
				i -= 2;

			if (i < 0)
				i = 0;
		}

		std::cout << "Diamantes extraidos: " << diamantes << std::endl;
	}

	return 0;
}