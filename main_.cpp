#include <conio.h>
#include <iostream>
#include "comb_posib.hpp"

using namespace std;

int main()
{
    vector<char> uwu = {'u', 'w', 'o'}; //los elementos
    vector<vector<char>> owo = owo::comb_posib(uwu, 3); //la funcion para obtener las combinaciones posibles
    cout << "combinaciones posibles de los elementos: u, w, o" << endl;
    cout << "con un tamaño de 3 elementos" << endl;
    for (auto it_x: owo) //un bucle for para imprimir todos los elementos del vector
    {
        for (auto it_y: it_x) //otro mas por que es un vector dentro de otro
        {
            cout << it_y; //ahora si imprimimos el elemento que en este caso el un char
        }
        cout << endl; //un salto de linea para que no se vea todo apilado uwur
    }

    getch(); //para que no se cierre la consola al instante
    return 0;
}
