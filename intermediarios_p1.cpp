#include <iostream>
#include <math.h>

typedef struct Ponto {
	int x, y;
} Ponto;

typedef struct Vetor {
	int x, y;
} Vetor;

int main() {

	Ponto A, B, C;

	std::cout << "Coordenada X do ponto A: ";
	std::cin >> A.x;
	std::cout << "Coordenada Y do ponto A: ";
	std::cin >> A.y;

	std::cout << "Coordenada X do ponto B: ";
	std::cin >> B.x;
	std::cout << "Coordenada Y do ponto B: ";
	std::cin >> B.y;

	std::cout << "Coordenada X do ponto C: ";
	std::cin >> C.x;
	std::cout << "Coordenada Y do ponto C: ";
	std::cin >> C.y;

	Vetor AB, BC;

	AB.x = A.x - B.x;
	AB.y = A.y - B.y;
	BC.x = C.x - B.x;
	BC.y = C.y - B.y;

	float normaAB, normaBC;

	normaAB = sqrt(pow(AB.x, 2) + pow(AB.y, 2));
	normaBC = sqrt(pow(BC.x, 2) + pow(BC.y, 2));

	float cosseno = ((AB.x * BC.x) + (AB.y * BC.y)) / (normaAB * normaBC);

	float angulo = (acos(cosseno) * 180.f) / 3.1415f;

	std::cout << "Angulo: " << angulo << std::endl;

	return 0;
}