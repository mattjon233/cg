#include "Raio.h"

Raio criar_raio_op(const Ponto& o, const Ponto& p) {
    return Raio(o, vetor_unitario(p-o));
}

Raio criar_raio_od(const Ponto& o, const Vetor& d) {
    return Raio(o, vetor_unitario(d));
}