/** 
 * @file    Profesor.cpp
 * @author algarcia,demiras,jrbalsas @ujaen.es
 *
 * @date abril, 2018
 */

#include "Profesor.h"

Profesor::Profesor(std::string nom, std::string dept)
    :nombre(nom),departamento(dept) {
}

Profesor::Profesor(const Profesor& orig)
    :nombre(orig.nombre),departamento(orig.departamento){
}

Profesor::~Profesor() {
}

std::string Profesor::GetDepartamento() const {
    return departamento;
}

void Profesor::SetDepartamento(std::string departamento) {
    this->departamento = departamento;
}

std::string Profesor::GetNombre() const {
    return nombre;
}

void Profesor::SetNombre(std::string nombre) {
    this->nombre = nombre;
}
