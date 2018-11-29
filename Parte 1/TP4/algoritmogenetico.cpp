#include "algoritmogenetico.h"

AlgoritmoGenetico::AlgoritmoGenetico(){
    cantIteraciones = 10000;
    cantIndividuos = 100;
    cantCruces = 30;
    cantMutaciones = 15;
    cantBuenos = 85;
    cantMalos = 15;
}

void AlgoritmoGenetico::GenerarPoblacion() {
    for(int i = 0; i<cantIndividuos; i++){
        poblacion[i] = new Individuo();
        poblacion[i]-> LlenarGenes();
    }
}

void AlgoritmoGenetico::Cruzar(){
    for(int i = 0; i<cantIndividuos; i++){
        poblacionNueva[i] = poblacion[i];
    }
    for(int i = 0;i<30;i++){
        int cont = 100;
        Individuo* individuoCruzado = new Individuo();
        int a = rand() % cantIndividuos;
        int b = rand() % cantIndividuos;
        individuoCruzado->genes[0] = poblacion[a]->genes[0];
        individuoCruzado->genes[1] = poblacion[a]->genes[1];
        individuoCruzado->genes[2] = poblacion[a]->genes[2];
        individuoCruzado->genes[3] = poblacion[b]->genes[3];
        individuoCruzado->genes[4] = poblacion[b]->genes[4];
        individuoCruzado->genes[5] = poblacion[b]->genes[5];
        poblacionNueva[cont] = individuoCruzado;
        cont++;
    }
}

void AlgoritmoGenetico::Mutar(){
    for(int i = 0; i<cantMutaciones; i++){
        int sel = rand() % 30 + 100;
        int a = rand() % 7;
        if(poblacionNueva[sel]->genes[a] == 0){
           poblacionNueva[sel]->genes[a] = 1;
        }else{
           poblacionNueva[sel]->genes[a] = 0;
        }
    }
}

void AlgoritmoGenetico::CalcularAptitud(){
    /*
     * for(poblacionNueva[])
     *  aptitud = poblacionNueva[i].calcAptitud
     */
}

void AlgoritmoGenetico::Seleccionar(){
    /*
     *  for(poblacionNueva[])
     *
     *
     */
}
