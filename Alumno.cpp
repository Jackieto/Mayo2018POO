/** 
 * @file    Alumno.cpp
 * @author algarcia,demiras,jrbalsas @ujaen.es
 *
 * @date abril, 2018
 */

#include "Alumno.h"

Alumno::Alumno(std::string nom, float edad)
    :nombre(nom)
    ,edad(edad){
}

Alumno::Alumno(const Alumno& orig)
    :nombre(orig.nombre)
    ,edad(orig.edad) {
}

Alumno::~Alumno() {
}

int Alumno::GetEdad() const {
    return edad;
}

void Alumno::SetEdad(int edad) {
    this->edad = edad;
}

std::string Alumno::GetNombre() const {
    return nombre;
}

void Alumno::SetNombre(std::string nombre) {
    this->nombre = nombre;
}
