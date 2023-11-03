#include <iostream>
#include "grafo.h"
#include "Ubicacion.h"
#include "NodoGrafo.h"
#include "INodo.h"
#include <vector>

using namespace std;

int main(){
    random_device rd;
    mt19937 generador(rd());


    Grafo grafo1(true);

    Ubicacion templo = Ubicacion(1, "Templo");
    Ubicacion mina = Ubicacion(2, "Mina");
    Ubicacion hangar = Ubicacion(3, "Hangar");
    Ubicacion centroDeArmas = Ubicacion(4, "Centro De Armas");
    Ubicacion ciudad = Ubicacion(5, "Ciudad");
    Ubicacion bosque = Ubicacion(6, "Bosque");
    Ubicacion montannas = Ubicacion(7, "Montañas");
    Ubicacion ruinas = Ubicacion(8, "Ruinas");
    Ubicacion playa = Ubicacion(9, "Playa");
    Ubicacion cuevaOscura = Ubicacion(10, "Cueva Oscura");
    Ubicacion pueblo = Ubicacion(11, "Pueblo");
    Ubicacion castillo = Ubicacion(12, "Castillo");
    Ubicacion pantano = Ubicacion(13, "Pantano");
    Ubicacion ciudadSubterranea = Ubicacion(14, "Ciudad Subterránea");
    Ubicacion desierto = Ubicacion(15, "Desierto");
    Ubicacion arenasDeBatalla = Ubicacion(16, "Arenas De Batalla");
    Ubicacion abismo = Ubicacion(17, "Abismo");
    Ubicacion allUbi[] = {templo, mina, hangar, centroDeArmas, ciudad, bosque, montannas, ruinas, playa, cuevaOscura, pueblo, castillo, pantano, ciudadSubterranea, desierto, arenasDeBatalla, abismo};
    
    for(int i=0; i<5; i++) {
        grafo1.addNode(&allUbi[i]);
    }

    for (int i = 0; i < allUbi.size() - 1; i++) {
        uniform_int_distribution<int> randomGen(1,100);
        int NumeroRandom = randomGen(generador);
        grafo1.addArc(&allUbi[i], &allUbi[i + 1], NumeroRandom); 
    }

    for (int i = 0; i < allUbi.size(); i++) {
        for (int j = 0; j < allUbi.size(); j++) {
            if (i != j) {
                Arco *arco = grafo1.getNodo(&allUbi[i])->getArcTo(grafo1.getNodo(&allUbi[j]));
                int pesoDelArco = arco->getPeso();
                cout << "Peso del arco entre " << allUbi[i].getNombre() << " y " << allUbi[j].getNombre() << ": " << pesoDelArco << endl;
            }
        }
    }
}