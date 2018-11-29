#include "agenteviajero.h"


AgenteViajero::AgenteViajero(){
    cantIteraciones = 10000;
    cantIndividuos = 100;
    promedioAptitud = 0;
    cantCruces = 30;
    cantMutaciones = 15;
    cantBuenos = 85;
    cantMalos = 15;

    for(int i = 0; i<5; i++){
        for(int j = 0; j < 5; j++){
            if (j != i)
            distancias[i][j] = rand() % 11;
        }
    }
}

void AgenteViajero::GenerarPoblacion() {
    for(int i = 0; i<cantIndividuos; i++){
        poblacion[i] = new Individuo();
        poblacion[i]->LlenarGenes();
    }
}

void AgenteViajero::Cruzar(){
    for(int i = 0; i<cantIndividuos; i++){
        poblacionNueva[i] = poblacion[i];
    }
    int c = 100;
    for(int j = 0; j < cantCruces; j++){
        Individuo* individuoMutado = new Individuo();
        int a = rand() % cantIndividuos;
        int b = rand() % cantIndividuos;
        individuoMutado -> genes[0] = poblacion[a] -> genes[0];
        individuoMutado -> genes[1] = poblacion[a] -> genes[1];
        individuoMutado -> genes[2] = poblacion[a] -> genes[2];
        individuoMutado -> genes[3] = poblacion[b] -> genes[3];
        individuoMutado -> genes[4] = poblacion[b] -> genes[4];
        //revisar repetidos y corregir
        //
        poblacionNueva[c] = individuoMutado;
        c++;
    }
}

void AgenteViajero::Mutar(){
    for(int i = 0; i < cantMutaciones; i++){
        int sel = rand() % 30 + 100;
        Individuo* t = poblacionNueva[sel];
        int a = rand() % 6;
        int b = rand() % 6;
        int temp = t->genes[a];
        t->genes[a] = t->genes[b];
        t->genes[b] = temp;
        poblacionNueva[sel] = t;
    }
}

void AgenteViajero::CalcularAptitud(){
    for(int i = 0; i < 130; i++){       //recorre poblacionNueva
        for(int j = 0; j < 4; j++){     //recorre sarreglo de genes
            int a = poblacionNueva[i]->genes[j];
            int b = poblacionNueva[i]->genes[j+1];
            poblacionNueva[i]->aptitud += distancias[a][b];
            promedioAptitud += poblacionNueva[i]->aptitud;
        }
    }
    promedioAptitud = promedioAptitud / 130;
}

void AgenteViajero::Seleccionar(){
    //85 cargas 15 chapas
    int contCargas = 0;
    int contChapas = 0;
    int contUni = 0;
    int iter = 0;
    while(contCargas < cantBuenos){
        if (poblacionNueva[contUni]->aptitud > promedioAptitud){
            poblacion[iter] = poblacionNueva[contUni];
            contCargas++;
            iter++;
            contUni++;
        }else{
            contUni++;
        }
    }
    contUni = 0;
    while (contChapas < cantMalos){
        if (poblacionNueva[contUni]->aptitud < promedioAptitud){
            poblacion[iter] = poblacionNueva[contUni];
            contChapas++;
            iter++;
            contUni++;
        }else{
            contUni++;
        }
    }
}

void AgenteViajero::EjecutarAlgoritmo(){
    GenerarPoblacion();
    for(int i = 0; i < cantIteraciones; i++){
        Cruzar();
        Mutar();
        CalcularAptitud();
        Seleccionar();
    }
}
