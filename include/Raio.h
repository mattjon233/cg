#ifndef RAIO_H
#define RAIO_H

#include "Vetor.h"

class Raio {
    public:
        Raio() {}
        
        Raio(const Ponto& o, const Vetor& d) : _origem(o), _direcao(vetor_unitario(d)) {}

        Ponto origem() const  { return _origem; }

        Vetor direcao() const { return _direcao; }

        Ponto para(double t) const {
            return _origem + _direcao*t;
        }

    public:
        Ponto _origem;
        Vetor _direcao;
};

/* criar raio com parametro (origem, ponto) */
Raio criar_raio_op(const Ponto& o, const Ponto& p);

/* criar raio com parametro (origem, direcao) */
Raio criar_raio_od(const Ponto& o, const Vetor& d);

#endif