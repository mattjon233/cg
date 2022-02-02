#ifndef CONE_H
#define CONE_H

#include "Objeto.h"
#include "Vetor.h"
#include "Matriz.h"
 
#include <vector>

using std::vector;

class Cone : public Objeto {
    public:
        /*dc = (V-C) / ||V-C||
          h  = ||V-C||
        */
        Cone() {};

        Cone(Ponto cen, float r, Vetor dir, float alt) : _centro(cen), _raio(r), _direcao(dir), _altura(alt), _cor(0, 0, 0) {
            atualizar_vertice();
        };

        Cone(Ponto cen, float r, Vetor dir, float alt, Cor cor) : _centro(cen), _raio(r), _direcao(dir), _altura(alt), _cor(cor/255) {
            atualizar_vertice();
        };

        virtual bool intersectar(const Raio& r,  float t_min, float t_max, PontoColisao& ptcol) const override;

        virtual void atualizar_pontos(const Matriz &MT) override;

        void rotacionar(const Matriz &MT);

        void atualizar_vertice(void) {
            _vertice = _centro + _direcao*_altura;
        };

    public:
        Ponto _centro;
        float _raio;
        Vetor _direcao;
        float   _altura;
        Cor   _cor;
        Ponto _vertice;
};

#endif