#pragma once
#include <iostream> //imprimer mensajes
#include <vector>   //es mejor que los punteros
#include <math.h>   //pow

namespace nemui
{
	// cominaciones posibles no estaticas versión 2.0
	template <typename t>
	std::vector<std::vector<t>> comb_posib(std::vector<t> ele, uint32_t cant)
	{
		std::vector<std::vector<t>> out;

		if (cant <= 1)
		{
			out.resize(ele.size());
			for (int i = 0; i < out.size(); i++)
				out.at(i).push_back(ele.at(i));
			return out;
		}
		else
		{
			//numero el total de elementos
			//(numero de elementos presentes ^ la cantidad de elementos que queremos)
			out.resize(pow(ele.size(), cant));

			std::vector<std::vector<t>> last = comb_posib(ele, cant - 1);
			int it_e = 0;
			int it_l = 0;

			for (int i = 0; i < out.size(); i++)
			{
				it_e = i % ele.size();
				it_l = (i/ele.size())%last.size();

				out.at(i).insert(out.at(i).end(), last.at(it_l).begin(), last.at(it_l).end());
				out.at(i).push_back(ele.at(it_e));
			}
			return out;
		}
	}
} // namespace nemui













namespace nemui
{
	namespace olds
	{
		template<typename T, size_t n>
		void comb_posib_nr_s (T (&elementos)[n]) //combinaciones posibles estaticas sin retorno
		{
			std::cout << "total: " << pow(n, 4) << std::endl; //el total
			int it = 0; //iteracion
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					for (int k = 0; k < n; k++)
					{
						for (int l = 0; l < n; l++)
						{
							std::cout << "out: "<<elementos[i]<<elementos[j]<<elementos[k]<<elementos[l]<<"  #:" << ++it << std::endl;
						}
					}
				}
			}
		}






		//combinaciones posibles estaticas con retorno
		template <typename t>
		std::vector<std::vector<t>> comb_posib_s (std::vector<t> ele)
		{
			int it = 0; //iterador
			std::vector<std::vector<t>> out; //variable de salida
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




		// cominaciones posibles no estaticas versión 1.0
		template <typename t>
		std::vector<std::vector<t>> comb_posib_1 (std::vector<t> ele, int cant)
		{
			std::vector<std::vector<t>> out(pow(ele.size(), cant));
			//numero el total de elementos (numero de elementos ^ la cantidad de elementos)

			if (cant > 1)
			{
				int it_t = 0; // iteracion del elemento temporal
				int	it_e = 0; // iteracion del los elementos dados
				std::vector<std::vector<t>> temp = comb_posib_1(ele, cant - 1); //elemento temporal
				for (int i = 0; i < out.size(); i++)
				{
					out.at(i).push_back(ele.at(it_e)); //poner el primer elemento
					for (int j = 0; j < temp.at(it_t).size(); j++)
					{
						out.at(i).push_back(temp.at(it_t).at(j)); //poner el o los siguientes elementos
					}

					it_t++; // el iterator del temporal ahumenta
					if (it_t >= temp.size()) { it_t = 0; it_e++; } //si el iterador temporal es mayor al tamaño del temporal el it = 0 y el it del elemento ahumenta
					if (it_e >= ele.size())  it_e = 0; // si el it del elemento es mayor a el it = 0
				}
				return out;
			}

			for (int i = 0; i < out.size(); i++)
			{
				out.at(i).push_back(ele.at(i)); //guarda el elemento
			}

			return out; //retorna el valor de salida
		}
	} // namespace olds
} // namespace nemui