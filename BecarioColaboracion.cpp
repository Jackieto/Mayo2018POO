#include "BecarioColaboracion.h"

BecarioColaboracion::BecarioColaboracion(std::string nom, float edad, float sueldo, std::string dep):
    Alumno(nom, edad), sueldo(sueldo), departamento(dep)
{
}

BecarioColaboracion::BecarioColaboracion(const BecarioColaboracion& orig):
    Alumno(orig), sueldo(orig.sueldo), departamento(orig.departamento)
{
}

BecarioColaboracion::~BecarioColaboracion() {
}

