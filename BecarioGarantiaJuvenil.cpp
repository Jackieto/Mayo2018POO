#include "BecarioGarantiaJuvenil.h"

BecarioGarantiaJuvenil::BecarioGarantiaJuvenil(std::string nom, float edad, float sueldo, std::string proy):
    Alumno(nom, edad), sueldo(sueldo), proyectoInvestigacion(proy)
{
}

BecarioGarantiaJuvenil::BecarioGarantiaJuvenil(const BecarioGarantiaJuvenil& orig):
    Alumno(orig), sueldo(orig.sueldo), proyectoInvestigacion(orig.proyectoInvestigacion)
{
}

BecarioGarantiaJuvenil::~BecarioGarantiaJuvenil() {
}

