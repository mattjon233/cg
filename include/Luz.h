#ifndef LUZ_H
#define LUZ_H

#include "Base.h"
#include "Objeto.h"

class Luz {
    public:
        virtual Cor luminancia(PontoColisao& ptcol) const = 0;

        virtual void atualizar_posicao(const Matriz &MT) = 0;

        float fd(Vetor& n, Vetor& l) const { 
            auto res = produto_escalar(n, l);
            if (res < 0) return 0;
            return res;
        }

        float fs(Vetor& r, Vetor& v, int m) const { 
            auto res = pow(produto_escalar(r, v), m);
            if (res < 0) return 0;
            return res;
        }

        virtual bool tem_posicao(void) const = 0;

        virtual Ponto posicao(void) const = 0;

};

#endif