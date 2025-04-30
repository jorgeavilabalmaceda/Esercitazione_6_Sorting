#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace SortLibrary {

template<typename T>
//Bubble sort

void BubbleSort(std::vector<T>& v)
{
    const unsigned int n = v.size();

    for(unsigned int i = 0; i < n - 2; i++)
    {
        for(unsigned int j = i + 1; j < n - 1; j++)
        {
            if (v[j] < v[i])
			{
				//swap
				T tmp;
				tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
        }        
    }
}

// Funzione per mantenere la proprietà di heap
void Heap_Prop(std::vector<int> v, int n, int i)
{	
	int mag = i;             // Nodo corrente
    int sx = 2 * i + 1;        // Figlio sinistro
    int dx = 2 * i + 2;       // Figlio destro

    if (sx < n && v[sx] > v[mag])
        mag = sx;

    if (dx < n && v[dx] > v[mag])
        mag = dx;

    if (mag != i) {
        std::swap(v[i], v[mag]);
        Heap_Prop(v, n, mag);  // Chiamata ricorsiva
    }
}


template<typename T>
//Heap sort
void HeapSort(std::vector<int>& v) 
{
	int n = v.size();
	
    // Costruzione dell'heap (max heap)
    for (int i = n / 2 - 1; i >= 0; --i)
        Heap_Prop(v, n, i);

    // Estrazione di un elemento alla volta dall'heap
    for (int i = n - 1; i >= 0; --i) 
	{
		std::swap(v[0], v[1]);

        // Richiama la proprieta di heap sul sottoalbero ridotto
        Heap_Prop(v, i, 0);
    }
}

}