#ifndef ALGORITMOGENETICO_H
#define ALGORITMOGENETICO_H
#include <stdlib.h>

class Individuo{
    //APTITUD
    public :
    int genes[6]; //limite 63
    void LlenarGenes(){
        for(int i=0; i<6 ;i++){
            genes[i] = rand() % 2;
        }
    }
};

/*
     CONFIGURACION
     10000 ITERACIONES
     100 INDIVIDUOS
     30% CRUCES
     10-20% MUTACIONES
     85% CARGAS - 15% CHAPAS
*/

class AlgoritmoGenetico
{
    public:
    int cantIteraciones;
    int cantIndividuos;
    int cantCruces;
    int cantMutaciones;
    int cantBuenos;
    int cantMalos;
    Individuo* poblacion[100];
    Individuo* poblacionNueva[130];

    AlgoritmoGenetico();
    void GenerarPoblacion();
    void Cruzar();
    void Mutar();
    void CalcularAptitud();
    void Seleccionar();
};

#endif // ALGORITMOGENETICO_H
