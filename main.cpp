#include <conio.h>
#include <iostream>
#include "comb_posib.hpp"

using namespace std;

int main()
{
    vector<char> uwu = {'0', '1'}; //los elementos
    vector<vector<char>> owo = nemui::comb_posib(uwu, 2); //la funcion para obtener las combinaciones posibles
    cout << "combinaciones posibles de los elementos: 0, 1" << endl;
    cout << "con un tamaño de 3 elementos" << endl;
    for (auto it_x: owo) //obtenemos los elementos de las filas de la matriz
    {
        for (auto it_y: it_x) //obtenemos el elemento de la fila
        {
            cout << it_y; //ahora si imprimimos el elemento que en este caso el un char
        }
        cout << endl; //un salto de linea para que no se vea todo apilado
    }

    getch(); //para que no se cierre la consola al instante
    return 0;
}
