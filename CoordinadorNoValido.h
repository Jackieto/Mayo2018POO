#ifndef COORDINADORNOVALIDO_H
#define COORDINADORNOVALIDO_H

#include <stdexcept>

class CoordinadorNoValido: public std::invalid_argument {
public:
    CoordinadorNoValido(std::string error = "Coordinador no válido"): std::invalid_argument(error) { };
    CoordinadorNoValido(const CoordinadorNoValido& orig): std::invalid_argument(orig) { };
    virtual ~CoordinadorNoValido() throw() {};
private:

};

#endif /* COORDINADORNOVALIDO_H */

