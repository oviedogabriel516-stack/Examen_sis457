#pragma once
#include "CoreMinimal.h"

template<class T>
class Nodo
{
public:
    T Valor;
    Nodo<T>* Siguiente;
    Nodo(T InValor) : Valor(InValor), Siguiente(nullptr) {}
};

template<class T>
class Lista
{
private:
    Nodo<T>* Cabeza;

public:
    Lista() : Cabeza(nullptr) {}

    void Agregar(T InValor)
    {
        Nodo<T>* NuevoNodo = new Nodo<T>(InValor);
        if (!Cabeza) { Cabeza = NuevoNodo; }
        else
        {
            Nodo<T>* Actual = Cabeza;
            while (Actual->Siguiente) Actual = Actual->Siguiente;
            Actual->Siguiente = NuevoNodo;
        }
    }
    TArray<T> Convertir_A_TArray()
    {
        TArray<T> Arreglo;
        Nodo<T>* Actual = Cabeza;
        while (Actual) { Arreglo.Add(Actual->Valor); Actual = Actual->Siguiente; }
        return Arreglo;
    }
};