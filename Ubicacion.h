#ifndef _UBICACION_
#define _UBICACION_ 1

#include <iostream>
#include "INodo.h"

using namespace std;

class Ubicacion : public INodo {
    private:
        string nombre;
        int id;
    public:
        Ubicacion(int pId, string pNombre) {
            this->setId(pId);
            this->setNombre(pNombre);
        }

        string getNombre() {
            return this->nombre;
        }

        void setNombre(string pNombre) {
            this->nombre = pNombre;
        }

    
};

#endif