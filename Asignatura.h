/** 
 * @file    Asignatura.h
 * @author algarcia,demiras,jrbalsas @ujaen.es
 *
 * @date abril, 2018
 */

#ifndef ASIGNATURA_H
#define ASIGNATURA_H

#include <string>
#include "Profesor.h"
#include "Alumno.h"

class Asignatura {
public:
    Asignatura(std::string nom = "Sin nombre", int cred = 3);
    Asignatura(const Asignatura& orig);
    virtual ~Asignatura();

    int getCreditos() const;
    void setCreditos(int creditos);
    std::string getNombre() const;
    void setNombre(std::string nombre);
    
    Profesor* getCoordinador() const;
    void setCoordinador(Profesor* dir);

    Alumno* getAlumno(int cual);
    void addAlumno(Alumno* alum);
    
    std::string alumnoMayor();

    Alumno* alumnoConSueldoMayor();
private:
    std::string nombre;
    int creditos;
    
    Profesor *coordinador;
    
    const static int MAX_ALUMNOS=25;
    Alumno* alumnos[MAX_ALUMNOS];
    int numAlumnos;
};

#endif /* ASIGNATURA_H */

