/** 
 * @file    Profesor.h
 * @author algarcia,demiras,jrbalsas @ujaen.es
 *
 * @date abril, 2018
 */

#ifndef PROFESOR_H
#define PROFESOR_H

#include <string>

class Profesor {
public:
    Profesor(std::string nom="Sin nombre", std::string dept = "Sin departamento");
    Profesor(const Profesor& orig);
    virtual ~Profesor();
    
    std::string GetDepartamento() const;
    void SetDepartamento(std::string departamento);
    std::string GetNombre() const;
    void SetNombre(std::string nombre);
    
private:
    std::string nombre;
    std::string departamento;

};

#endif /* PROFESOR_H */

