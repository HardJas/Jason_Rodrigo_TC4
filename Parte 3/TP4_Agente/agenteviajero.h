#ifndef AGENTEVIAJERO_H
#define AGENTEVIAJERO_H

#include <stdlib.h>


class Individuo{
    public :
    int aptitud; //total de la ruta
    int genes[5] = {1,2,3,4,5};
    void LlenarGenes(){
        for(int i=0; i<5; i++){
            int a = rand() % 6;
            int b = rand() % 6;
            int temp = genes[a];
            genes[a] = genes[b];
            genes[b] = temp;
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
class AgenteViajero
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
    int distancias[5][5];
    int promedioAptitud;

    AgenteViajero();
    void GenerarPoblacion();
    void Cruzar();
    void Mutar();
    void CalcularAptitud();
    void Seleccionar();
    void EjecutarAlgoritmo();
};
#endif // AGENTEVIAJERO_H
