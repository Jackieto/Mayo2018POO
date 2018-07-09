/** 
 * @file    Asignatura.cpp
 * @author algarcia,demiras,jrbalsas @ujaen.es
 *
 * @date abril, 2018
*/

#include "Asignatura.h"
#include "Alumno.h"
#include "CoordinadorNoValido.h"
#include <stdexcept>

Asignatura::Asignatura(std::string nom, int cred)
    :nombre(nom)
    ,creditos(cred)
    ,numAlumnos(0)
    ,coordinador(0){

    for (int i = 0; i < Asignatura::MAX_ALUMNOS; i++) {
        alumnos[i] = 0;
    }
}

Asignatura::Asignatura(const Asignatura& orig)
    :nombre(orig.nombre)
    ,creditos(orig.creditos)
    ,numAlumnos(orig.numAlumnos)
    ,coordinador(orig.coordinador){

    for (int i = 0; i < Asignatura::MAX_ALUMNOS; i++) {
        if (orig.alumnos[i] != 0)
            alumnos[i] = orig.alumnos[i];
        else
            alumnos[i] = 0;
    }
}

Asignatura::~Asignatura() {
}

int Asignatura::getCreditos() const {
    return creditos;
}

void Asignatura::setCreditos(int creditos) {
    if ((creditos < 3) || (creditos > 12))
        throw std::invalid_argument("Asignatura::setCreditos: número de créditos no válido");
    else
        this->creditos = creditos;
}

std::string Asignatura::getNombre() const {
    return nombre;
}

void Asignatura::setNombre(std::string nombre) {
    this->nombre = nombre;
}

/** @brief Asigna un coordinador a un Asignatura
 *  @param[in] Profesor* coor, profesor que coordina la asignatura
 *  @post Asigna el coordinador a la asignatura, sustituyendo el coordinador anterior si lo hubiera
 *  @throws std::invalid_argument si el departamento del profesor no es válido
 */
 void Asignatura::setCoordinador(Profesor* coor) {
     if ((coor == 0) || (coor->GetDepartamento() != "Informática"))
         throw CoordinadorNoValido("Asignatura::setCoordinador: departamento del coordinador no válido");
     else
         this->coordinador = coor;
 }

 Profesor* Asignatura::getCoordinador() const {
     return coordinador;
 }

Alumno* Asignatura::getAlumno(int cual) {
    if (cual<1 || cual>numAlumnos)
        throw std::out_of_range("Asignatura::getAlumno: No existe el alumno indicado");

    return alumnos[cual-1];
}

void Asignatura::addAlumno(Alumno* alum) {
    if (numAlumnos == MAX_ALUMNOS)
        throw std::out_of_range("Asignatura::addAlumno: No se admiten más alumnos");
    if (alum->GetEdad() < 16)
        throw std::out_of_range("Asignatura::addAlumno: La edad del alumno debe ser igual o superior a 16");

    alumnos[numAlumnos]=alum;
    numAlumnos++;
}

std::string Asignatura::alumnoMayor() {
    int mayorEdad = alumnos[0]->GetEdad();
    int mayor = 0;
    
    for (int i = 1; i < numAlumnos; i++) {
        if (alumnos[i]->GetEdad() > mayorEdad) {
            mayorEdad = alumnos[i]->GetEdad();
            mayor = i;
        }
    }
    return alumnos[mayor]->GetNombre();
}

Alumno* Asignatura::alumnoConSueldoMayor() {
    Alumno* mayor = 0;
    float max = 0;
    for(int i = 0; i < this->numAlumnos; i++) {
        if (this->alumnos[i]->GetSueldo() > max) {
            mayor = this->alumnos[i];
            max = this->alumnos[i]->GetSueldo();
        }
    }
    return mayor;
}
