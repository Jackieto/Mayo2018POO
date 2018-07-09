#ifndef BECARIOGARANTIAJUVENIL_H
#define BECARIOGARANTIAJUVENIL_H

#include "Alumno.h"

class BecarioGarantiaJuvenil: public Alumno {
public:
    BecarioGarantiaJuvenil(std::string nom = "Sin nombre", float edad = 18, float sueldo = 0, std::string proy = "Sin asignar");
    BecarioGarantiaJuvenil(const BecarioGarantiaJuvenil& orig);
    virtual ~BecarioGarantiaJuvenil();
    
    std::string GetProyectoInvestigacion() const {
        return proyectoInvestigacion;
    }
    void SetProyectoInvestigacion(std::string proyectoInvestigacion) {
        this->proyectoInvestigacion = proyectoInvestigacion;
    }
    float GetSueldo() const {
        return sueldo;
    }
    void SetSueldo(float sueldo) {
        this->sueldo = sueldo;
    }

private:
    float sueldo;
    std::string proyectoInvestigacion;
};

#endif /* BECARIOGARANTIAJUVENIL_H */

