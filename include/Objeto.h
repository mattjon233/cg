#ifndef OBJETO_H
#define OBJETO_H

#include "Raio.h"
#include "Matriz.h"

struct PontoColisao {
    Ponto pt;
    Vetor normal;
    Vetor dr;
    float m;
    float t_int;
    Cor cor;
};

class Objeto {
    public:
        virtual bool intersectar(const Raio& r, float t_min, float t_max, PontoColisao& ptcol) const = 0;

        virtual void atualizar_pontos(const Matriz &CpM) = 0;
};

#endif