/** 
 * @file    Alumno.h
 * @author algarcia,demiras,jrbalsas @ujaen.es
 *
 * @date abril, 2018
 */

#ifndef ALUMNO_H
#define ALUMNO_H
#include <string>

class Alumno {
public:
    Alumno(std::string nom = "Sin nombre", float edad = 18);
    Alumno(const Alumno& orig);
    virtual ~Alumno();

    int GetEdad() const;
    void SetEdad(int edad);
    std::string GetNombre() const;
    void SetNombre(std::string nombre);
    
    virtual float GetSueldo() const = 0;
private:
    std::string nombre;
    int edad;

};

#endif /* ALUMNO_H */

