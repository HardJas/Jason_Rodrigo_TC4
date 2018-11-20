#ifndef ALGORITMO_GENETICO_H
#define ALGORITMO_GENETICO_H

#include <iostream>
#include <math.h>
#include <stdlib>

using namespace std;

//AG (config)
//for(1-10000)
//cruzar() fusiona la mitad de los binarios de un vector con la mitad de otro
//mutar()toma un porcentaje de la población y le hace mutaciones
//Aptitud()
//Seleccionar() selecciona solo los mas aptos

// configuración
//1000 iteraciones o cuando la aptitud este bien
//100 individuos
//30% de cruces
//10%-20% de Mutaciones
//85% Cargas - 15% chapas

class Algoritmo_Genetico
{
public:
    int Generaciones; //iteraciones o generaciones
    int Individuos;
    int Porcentaje_Cruces =30;
    int P_Mutaciones = 20;
    int P_Mejores = 85;
    Individuo poblacion[];
    Individuo poblacionNueva[];



    Algoritmo_Genetico(int Gn, int Id, int Pc, int Pmut, int Pme){
        Generaciones = Gn;
        Individuos = Id;
        Porcentaje_Cruces = Pc;
        P_Mutaciones = Pmut;
        P_Mejores = Pme;
    }

    void cruzar(int a[], int b[], int tamano);
    void Mutar();
    void Aptitud();
    void Seleccionar();

    struct Individuo{
        //Aptitud
        int genes[6];
        void LlenarGenes(){
            for(int i=0; i<6; i++){
                genes[i] = rand() %2;
            }

        }


    };
};

#endif // ALGORITMO_GENETICO_H
