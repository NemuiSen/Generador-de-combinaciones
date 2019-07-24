#ifndef comb_hpp
#define comb_hpp

#include <math.h> //pow
#include <iostream> //imprimer mensajes
#include <vector> //es mejor que los punteros uwu
using namespace std;

namespace owo
{    
    template<typename T, size_t n>
    void comb_posib_nR_s (T (&elementos)[n]) //combinaciones posibles estaticas sin retorno
    {
        cout << "total: " << pow(n, 4) << endl; //el total
        int it = 0; //iteracion
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    for (int l = 0; l < n; l++)
                    {
                        cout << "out: "<<elementos[i]<<elementos[j]<<elementos[k]<<elementos[l]<<"  #:" << ++it << endl;
                    }
                }
            }
        }
    }

    template <typename t>
    vector<vector<t>> comb_posib_s (vector<t> ele) //combinacon posible estatico con retorno
    {
        int it = 0; //iterador
        vector<vector<t>> out; //variable de salida
        out.resize(ele.size()*ele.size()); //establecer el tamaño de la salida
        for (int i = 0; i < ele.size(); i++) //primer elemeto
        {
            for (int j = 0; j < ele.size(); j++) //segundo elemento
            {
                for (int k = 0; k < ele.size(); j++) //ultimo elemento en implementarse
                {
                    out.at(it).push_back(ele.at(i)); //poner el primer elemento
                    out.at(it).push_back(ele.at(j)); //poner el segundo elemento
                    out.at(it).push_back(ele.at(k)); //poner el ultimo elemento
                    it++; //el iterador aumenta
                }
            }
        }
        return out; //retorna el resultado final
    }

    template<typename t>
    vector<vector<t>> comb_posib (vector<t> ele, int cant) // cominaciones posibles con no estatico
    {
        vector<vector<t>> out; //valor de salida
        out.resize(pow(ele.size(), cant)); //establecer como tamaño el total de elementos
        if (cant <= 1) //si es el ultimo elemento o solo 1, guarda todos los elementos dentro de un vector personal
        {
            for (int i = 0; i < out.size(); i++)
            {
                out.at(i).push_back(ele.at(i)); //guarda el elemento
            }
        }
        else //de lo contrario
        {
            int it_t = 0, // iteracion del elemento temporal
                it_e = 0; // iteracion del los elementos dados
            vector<vector<t>> temp = comb_posib(ele, cant - 1); //elemento temporal
            for (int i = 0; i < out.size(); i++)
            {
                out.at(i).push_back(ele.at(it_e)); //poner el primer elemento
                for (int j = 0; j < temp.at(it_t).size(); j++)
                {
                    out.at(i).push_back(temp.at(it_t).at(j)); //poner el o los siguientes elementos
                }
                it_t++; // el iterator del temporal ahumentr
                if (it_t >= temp.size()) {it_t = 0; it_e++;} //si el iterador temporal es mayor al tamaño del temporal el it = 0 y el it del elemento ahumenta
                if (it_e >= ele.size())  it_e = 0; // si el it del elemento es mayor a el it = 0
            }
        }
        return out; //retorna el valor de salida
    }
} // namespace owo

#endif //comb_hpp
