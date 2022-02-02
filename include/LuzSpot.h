#ifndef LUZSPOT_H
#define LUZSPOT_H

#include "Base.h"
#include "Luz.h"

class LuzSpot : public Luz {
    public:
        LuzSpot(const Ponto& p, const Vetor& d, float e,  float t, const Cor& c) : _p0(p), _d(vetor_unitario(d)), _e(e), _theta(graus_em_radianos(t)), _intensidade(c) {}

        virtual Cor luminancia(PontoColisao& ptcol) const override;

        virtual void atualizar_posicao(const Matriz &MT) override;    

        virtual bool tem_posicao(void) const override { return true; }

        virtual Ponto posicao(void) const override  { return _p0; }

    public:
        Ponto _p0;
        Vetor _d;
        float _e;
        float _theta;
        Cor _intensidade;
};

#endif