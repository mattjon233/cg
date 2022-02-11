#ifndef ESFERA_H
#define ESFERA_H

#include "Objeto.h"
#include "Vetor.h"
#include "Matriz.h"
 
#include <vector>

using std::vector;

class Esfera : public Objeto {
    public:
        // Esfera(Ponto cen, float r, Cor cor, Cor cor_difusa, Cor cor_especular) 
        // : _centro(cen)
        // , _raio(r)
        // , _cor(cor/255) 
        // , _cor_difusa(cor_difusa/255.0f)
        // , _cor_especular(cor_especular/255.0f) {};

        Esfera(Ponto cen, float r, Cor cor) 
        : _centro(cen)
        , _raio(r)
        , _cor(cor/255)
        // , _cor_difusa(_cor)
        // , _cor_especular(_cor) {};
        {};

        virtual bool intersectar(const Raio& r,  float t_min, float t_max, PontoColisao& ptcol) const override;
        virtual void atualizar_pontos(const Matriz &MT) override;

    public:
        Ponto _centro;
        float _raio;
        Cor _cor;
        // Cor _cor_difusa;
        // Cor _cor_especular;
};

#endif