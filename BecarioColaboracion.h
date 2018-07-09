#ifndef BECARIOCOLABORACION_H
#define BECARIOCOLABORACION_H

#include "Alumno.h"

class BecarioColaboracion: public Alumno {
public:
    BecarioColaboracion(std::string nom = "Sin nombre", float edad = 18, float sueldo = 0, std::string dep = "Sin asignar");
    BecarioColaboracion(const BecarioColaboracion& orig);
    virtual ~BecarioColaboracion();
    
    std::string GetDepartamento() const {
        return departamento;
    }
    void SetDepartamento(std::string departamento) {
        this->departamento = departamento;
    }
    virtual float GetSueldo() const {
        return sueldo;
    }
    void SetSueldo(float sueldo) {
        this->sueldo = sueldo;
    }

private:
    float sueldo;
    std::string departamento;
};

#endif /* BECARIOCOLABORACION_H */

