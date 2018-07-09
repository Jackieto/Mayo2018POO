/** 
 * @file   main.cpp
 * @author algarcia,demiras,jrbalsas @ujaen.es
 *
 * @date abril, 2018
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <typeinfo>

#include "Asignatura.h"
#include "Profesor.h"
#include "Alumno.h"
#include "BecarioGarantiaJuvenil.h"
#include "CoordinadorNoValido.h"
#include "BecarioColaboracion.h"

using namespace std;

// c) funcion que visualiza por pantalla el tipo de alumno y su nombre
void visualiza(Alumno& al) {
    try {
        BecarioColaboracion& bc = dynamic_cast<BecarioColaboracion&>(al);
        std::cout << "Es un becario de colaboración de nombre " << bc.GetNombre() << std::endl;
    } catch(std::bad_cast& e) {
        try {
            BecarioGarantiaJuvenil& bgj = dynamic_cast<BecarioGarantiaJuvenil&>(al);
            std::cout << "Es un becario de garantia juvenil de nombre " << bgj.GetNombre() << std::endl;
        } catch(std::bad_cast& e) {
            std::cerr << "Tipo de alumno desconocido" << std::endl;
        }
    }
}

int main(int argc, char** argv) {

    // a) Vector de 2 punteros a alumnos, con becario colaboración "Pepe" y becario garantai juvenil "Antonia"
    //    Crear un profesor "Luisa" del departamento de "Física"
    Alumno* val[2] = {new BecarioColaboracion("Pepe", 20, 300, "Informática"), 
                      new BecarioGarantiaJuvenil("Antonia", 21, 1200, "Fractales")};    
    Profesor prof("Luisa", "Física");

    // b) Crear una asignatura asig1 de nombre "POO" y 6 créditos
    //    Añadir a la asignatura asig1 los alumnos de a) y asignar como coordinador a la profesora a), capturar las excepciones
    Asignatura asig1("POO", 6);
    
    try {
        asig1.addAlumno(val[0]);
        asig1.addAlumno(val[1]);
    
        asig1.setCoordinador(&prof);
    } catch(std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    } catch(CoordinadorNoValido& e) {
        std::cerr << e.what() << std::endl;        
    }
    
    // d) localizar el alumno de sueldo mayor en asig1 utilizando método Asignatura::alumnoConSueldoMayor()
    Alumno* al = asig1.alumnoConSueldoMayor();
    visualiza(*al);
    
    // e) Liberar recursos que sea necesario
    delete val[0];
    delete val[1];

    return 0;
}

