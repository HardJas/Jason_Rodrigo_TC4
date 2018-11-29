#ifndef ALGORITMOGENETICO_H
#define ALGORITMOGENETICO_H
#include <stdlib.h>


class Individuo{
    int aptitud; //total de la ruta 
    int genes[] = {1,2,3,4,5}; 
    public :
    void LlenarGenes(){ 
		for(int i=0;i<5; i++){
			int a = rand() % 6;
			int b = rand() % 6;
			int temp = genes[a];
			genes[a] = genes[b];
			genes[b] = temp;
        }
    }
};

/*
        genera poblacion		A B D E A
                                A B E D A

        cruces			// TOMAR DOS Y Q HAGAN CHUQUCHUQU
        mutaciones		// TOMAR UN CHAVALO AL AZAR Y MUTARLO
        calcula aptitud // AUTOEXPLICATORIO
        selecciona		// DEFINIR CUANTOS, PASAN ALGUNOS CHAPAS

        //CONFIGURACION
        10000 ITERACIONES O CUANDO LA APTITUD ESTE DEMASIADO BIEN
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
	int distancias[5][5];
	int promedioAptitud;

    AlgoritmoGenetico();
    void GenerarPoblacion();
    void Cruzar();
    void Mutar();
    void CalcularAptitud();
    void Seleccionar();
	void EjecutarAlgoritmo();
};

#endif // ALGORITMOGENETICO_H
