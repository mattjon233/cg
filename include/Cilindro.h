#ifndef CILINDRO_H
#define CILINDRO_H

#include "Objeto.h"
#include "Vetor.h"
#include "Matriz.h"
#include <vector>

using std::vector;

class Cilindro : public Objeto {
    public:
        /*dc = (V-C) / ||V-C||
          h  = ||V-C||
        */
        Cilindro() {};

        Cilindro(Ponto cen, float r, Vetor dir, float alt) : _base(cen), _raio(r), _direcao(dir), _altura(alt), _cor(0, 0, 0) {
            atualizar_topo();
        };
        Cilindro(Ponto cen, float r, Vetor dir, float alt, Cor cor) : _base(cen), _raio(r), _direcao(vetor_unitario(dir)), _altura(alt), _cor(cor/255) {
            atualizar_topo();
        };
        virtual bool intersectar(const Raio& r,  float t_min, float t_max, PontoColisao& ptcol) const override;
        virtual void atualizar_pontos(const Matriz &MT) override;
        void rotacionar(const Matriz &MT);
        void atualizar_topo(void) {
            _topo = _base + _direcao*_altura;
        };

    public:
        Ponto _base;
        float _raio;
        Vetor _direcao;
        float   _altura;
        Cor   _cor;
        Ponto _topo;
};

#endif