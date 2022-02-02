#ifndef LUZPONTUAL_H
#define LUZPONTUAL_H

#include "Base.h"
#include "Luz.h"

class LuzPontual : public Luz {
    public:
        LuzPontual(const Ponto& p, const Cor& c) : _p0(p), _intensidade(c) {}

        virtual Cor luminancia(PontoColisao& ptcol) const override;
        
        virtual void atualizar_posicao(const Matriz &MT) override;

        virtual bool tem_posicao(void) const override { return true; }

        virtual Ponto posicao(void) const override  { return _p0; }

    public:
        Ponto _p0;
        Cor _intensidade;
};

#endif