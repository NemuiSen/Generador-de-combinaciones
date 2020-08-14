#include <iostream>
#include <string>
#include "comb_posib.hpp"

int main()
{
	std::cout << "Ponga los elementos que quiere prosesar: ";
	std::string input;
	std::getline(std::cin, input);
	std::cout << "Ponga el numero de elemento por cada fila que quiere: ";
	int n;
	std::cin >> n;

	std::vector<char> v(input.begin(), input.end());
	std::vector<std::vector<char>> result = nemui::comb_posib(v, n);
	std::cout << "resultado" << std::endl;
	for (auto it_x: result) //obtenemos los elementos de las filas de la matriz
	{
		for (auto it_y: it_x) //obtenemos el elemento de la fila
		{
			std::cout << it_y; //ahora si imprimimos el elemento que en este caso el un char
		}
		std::cout << std::endl; //un salto de linea para que no se vea todo apilado
	}

	std::cin.get(); //para que no se cierre la consola al instante
	return 0;
}
