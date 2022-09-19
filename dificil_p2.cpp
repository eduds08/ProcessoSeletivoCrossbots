#include <iostream>
#include <string>

int** criarMatrizCavalo(int i, int j);
bool movimentoDiagonal(int i, int j, int posRei[2], std::string tabuleiro[8], char reiInimigo);
bool movimentoHorizontal(int i, int j, int posRei[2], std::string tabuleiro[8], char reiInimigo);
bool movimentoVertical(int i, int j, int posRei[2], std::string tabuleiro[8], char reiInimigo);
bool movimentoCavalo(std::string tabuleiro[8], int** matrizCavalo, char reiInimigo);
bool movimentoPeao(int i, int j, int posRei[2], std::string tabuleiro[8], char reiInimigo);

int main() {

	std::string tabuleiro[8];

	bool fim = false;

	bool xequePreto = false, xequeBranco = false;
	
	int idJogo = 0;

	int posReiBranco[2] = { 0, 0 }, posReiPreto[2] = { 0, 0 };

	int** matrizCavalo; // Matriz com as 8 posi��es nas quais o cavalo pode ir.

	while (!fim) {

		fim = true;

		xequePreto = false;
		xequeBranco = false;

		for (int i = 0; i < 8; i++) {
			std::cout << "Digite a linha " << i << " do tabuleiro: ";
			std::cin >> tabuleiro[i];

			/* O loop a seguir salva as posi��es i e j dos reis em vetores */
			for (int j = 0; j < 8; j++) {
				if (tabuleiro[i][j] == 'k') {
					posReiPreto[0] = i;
					posReiPreto[1] = j;
					break;
				}
				if (tabuleiro[i][j] == 'K') {
					posReiBranco[0] = i;
					posReiBranco[1] = j;
					break;
				}
			}

			if (tabuleiro[i] != "........")
				fim = false;
		}

		idJogo++;

		std::cout << "\n";

		// imprime o tabuleiro
		for (int i = 0; i < 8; i++)
			std::cout << tabuleiro[i] << "\n\n";

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				
				/*
				---------------------------------
				PE�AS PRETAS
				---------------------------------
				*/

				// pe�o preto
				if (tabuleiro[i][j] == 'p')
					xequeBranco = movimentoPeao(i, j, posReiBranco, tabuleiro, 'K');

				// torre preta
				else if (tabuleiro[i][j] == 'r') {
					xequeBranco = movimentoHorizontal(i, j, posReiBranco, tabuleiro, 'K');
					if (xequeBranco == false)
						xequeBranco = movimentoVertical(i, j, posReiBranco, tabuleiro, 'K');
				}

				// bispo preto
				else if (tabuleiro[i][j] == 'b')
					xequeBranco = movimentoDiagonal(i, j, posReiBranco, tabuleiro, 'K');

				// rainha preta
				else if (tabuleiro[i][j] == 'q') {
					xequeBranco = movimentoDiagonal(i, j, posReiBranco, tabuleiro, 'K');
					if (xequeBranco == false)
						xequeBranco = movimentoHorizontal(i, j, posReiBranco, tabuleiro, 'K');
					if (xequeBranco == false)
						xequeBranco = movimentoVertical(i, j, posReiBranco, tabuleiro, 'K');
				}

				// cavalo preto
				else if (tabuleiro[i][j] == 'n') {
					matrizCavalo = criarMatrizCavalo(i, j);
					xequeBranco = movimentoCavalo(tabuleiro, matrizCavalo, 'K');

					for (int i = 0; i < 8; i++)
						delete[] matrizCavalo[i];
					delete[] matrizCavalo;
				}

				/*
				---------------------------------
				PE�AS BRANCAS
				---------------------------------
				*/

				// pe�o branco
				else if (tabuleiro[i][j] == 'P')
					xequeBranco = movimentoPeao(i, j, posReiPreto, tabuleiro, 'k');

				// torre branca
				else if (tabuleiro[i][j] == 'R') {
					xequePreto = movimentoHorizontal(i, j, posReiPreto, tabuleiro, 'k');
					if (xequePreto == false)
						xequePreto = movimentoVertical(i, j, posReiPreto, tabuleiro, 'k');
				}

				// bispo branco
				else if (tabuleiro[i][j] == 'B')
					xequePreto = movimentoDiagonal(i, j, posReiPreto, tabuleiro, 'k');

				// rainha branca
				else if (tabuleiro[i][j] == 'Q') {
					xequePreto = movimentoDiagonal(i, j, posReiPreto, tabuleiro, 'k');
					if (xequePreto == false)
						xequePreto = movimentoHorizontal(i, j, posReiPreto, tabuleiro, 'k');
					if (xequePreto == false)
						xequePreto = movimentoVertical(i, j, posReiPreto, tabuleiro, 'k');
				}

				// cavalo branco
				else if (tabuleiro[i][j] == 'N') {
					matrizCavalo = criarMatrizCavalo(i, j);
					xequePreto = movimentoCavalo(tabuleiro, matrizCavalo, 'k');

					for (int i = 0; i < 8; i++)
						delete[] matrizCavalo[i];
					delete[] matrizCavalo;
				}

				// Confere se o jogo acabou
				if (xequePreto || xequeBranco)
					break;
			}

			if (xequePreto) {
				std::cout << "\nJogo #" << idJogo << ": rei preto esta em xeque.\n\n\n";
				break;
			}
			else if (xequeBranco) {
				std::cout << "\nJogo #" << idJogo << ": rei branco esta em xeque.\n\n\n";
				break;
			}
		}
	}

	return 0;
}

// Cria uma matriz com as 8 posi��es nas quais o cavalo pode ir
int** criarMatrizCavalo(int i, int j) {

	int** matrizCavalo = new int* [8];

	for (int i = 0; i < 8; i++)
		matrizCavalo[i] = new int[2];

	matrizCavalo[0][0] = i - 2;
	matrizCavalo[0][1] = j - 1;

	matrizCavalo[1][0] = i - 2;
	matrizCavalo[1][1] = j + 1;

	matrizCavalo[2][0] = i - 1;
	matrizCavalo[2][1] = j + 2;

	matrizCavalo[3][0] = i + 1;
	matrizCavalo[3][1] = j + 2;

	matrizCavalo[4][0] = i + 2;
	matrizCavalo[4][1] = j + 1;

	matrizCavalo[5][0] = i + 2;
	matrizCavalo[5][1] = j - 1;

	matrizCavalo[6][0] = i + 1;
	matrizCavalo[6][1] = j - 2;

	matrizCavalo[7][0] = i - 1;
	matrizCavalo[7][1] = j - 2;

	return matrizCavalo;
}

/*
Simula a pe�a caminhando na diagonal (em dire��o ao rei inimigo). Como se a pe�a fosse andando de casa em casa (na diagonal) e vai verificando se os espa�os
est�o vazios, pois caso tenha alguma pe�a (excetuando o rei inimigo), o caminho est� bloqueado.
Caso o caminho at� o rei inimigo esteja vazio, a fun��o retorna true.
*/
bool movimentoDiagonal(int i, int j, int posRei[2], std::string tabuleiro[8], char reiInimigo) {

	int aux1, aux2; // vari�veis auxiliares para guardar as coordenadas das posi��es

	// O rei est� abaixo da pe�a
	if (posRei[0] > i) {

		// direita abaixo
		if (posRei[1] > j) {

			aux1 = i + 1;
			aux2 = j + 1;

			while (tabuleiro[aux1][aux2] == '.') {
				aux1++;
				aux2++;
			}

			if (tabuleiro[aux1][aux2] == reiInimigo)
				return true;
		}
		// esquerda abaixo
		else if (posRei[1] < j) {
			aux1 = i + 1;
			aux2 = j - 1;

			while (tabuleiro[aux1][aux2] == '.') {
				aux1++;
				aux2--;
			}
			if (tabuleiro[aux1][aux2] == reiInimigo)
				return true;
		}

	}

	// O rei est� acima da pe�a
	else if (posRei[0] < i) {

		// direita acima
		if (posRei[1] > j) {
			aux1 = i - 1;
			aux2 = j + 1;

			while (tabuleiro[aux1][aux2] == '.') {
				aux1--;
				aux2++;
			}
			if (tabuleiro[aux1][aux2] == reiInimigo)
				return true;
		}
		// esquerda acima
		else if (posRei[1] < j) {
			aux1 = i - 1;
			aux2 = j - 1;

			while (tabuleiro[aux1][aux2] == '.') {
				aux1--;
				aux2--;
			}
			if (tabuleiro[aux1][aux2] == reiInimigo)
				return true;
		}
	}

	return false;
}

/*
Simula uma caminhada na horizontal na dire��o do rei inimigo (mesma l�gica do movimentoDiagonal).
*/
bool movimentoHorizontal(int i, int j, int posRei[2], std::string tabuleiro[8], char reiInimigo) {

	int aux;

	// Confere se o rei est� na mesma linha da pe�a
	if (posRei[0] == i) {

		// rei est� a direita da pe�a
		if (posRei[1] > j) {
			aux = j + 1;

			while (tabuleiro[i][aux] == '.')
				aux++;

			if (tabuleiro[i][aux] == reiInimigo)
				return true;
		}

		// rei est� a esquerda da pe�a
		else if (posRei[1] < j) {
			aux = j - 1;

			while (tabuleiro[i][aux] == '.')
				aux--;

			if (tabuleiro[i][aux] == reiInimigo)
				return true;
		}
	}

	return false;
}

/*
Simula uma caminhada na vertical em dire��o ao rei (mesma l�gica do movimentoDiagonal e do movimentoHorizontal)
*/
bool movimentoVertical(int i, int j, int posRei[2], std::string tabuleiro[8], char reiInimigo) {

	int aux;

	// Confere se o rei est� na mesma coluna da pe�a
	if (posRei[1] == j) {
		
		// rei est� acima da pe�a
		if (posRei[0] < i) {
			aux = i - 1;

			while (tabuleiro[aux][j] == '.')
				aux--;

			if (tabuleiro[aux][j] == reiInimigo)
				return true;
		}

		// rei est� abaixo da pe�a
		else if (posRei[0] > i) {
			aux = i + 1;

			while (tabuleiro[aux][j] == '.')
				aux++;

			if (tabuleiro[aux][j] == reiInimigo)
				return true;
		}
	}

	return false;
}

/*
Apenas confere se alguma das 8 posi��es nas quais o cavalo pode ir est� ocupada pelo rei inimigo.
Tamb�m faz uma verifica��o extra para saber se a posi��o est� dentro do tabuleiro 8x8 para n�o dar problemas de acesso de posi��es inv�lidas do vetor.
*/
bool movimentoCavalo(std::string tabuleiro[8], int** matrizCavalo, char reiInimigo) {

	for (int k = 0; k < 8; k++) {
		if ((matrizCavalo[k][0] >= 0 && matrizCavalo[k][0] < 8) && (matrizCavalo[k][1] >= 0 && matrizCavalo[k][1] < 8))
			if (tabuleiro[matrizCavalo[k][0]][matrizCavalo[k][1]] == reiInimigo)
				return true;
	}
		
	return false;
}

/*
Verifica a cor do pe�o (para saber em qual dire��o ele ir� andar) e verifica se alguma das 2 posi��es nas quais ele pode ir, est� ocupada pelo rei.
Tamb�m faz uma verifica��o extra para saber se a posi��o est� dentro do tabuleiro 8x8 para n�o dar problemas de acesso de posi��es inv�lidas do vetor.
*/
bool movimentoPeao(int i, int j, int posRei[2], std::string tabuleiro[8], char reiInimigo) {

	// pe�o preto
	if (reiInimigo == 'K') {

		if (i + 1 < 8) {

			if (j - 1 >= 0)
				if (tabuleiro[i + 1][j - 1] == reiInimigo)
					return true;
			if (j + 1 < 8)
				if (tabuleiro[i + 1][j + 1] == reiInimigo)
					return true;
		}
	}

	// pe�o branco
	else if (reiInimigo == 'k') {

		if (i - 1 >= 0) {

			if (j - 1 >= 0)
				if (tabuleiro[i - 1][j - 1] == reiInimigo)
					return true;
			if (j + 1 < 8)
				if (tabuleiro[i - 1][j + 1] == reiInimigo)
					return true;
		}
	}
	
	return false;
}