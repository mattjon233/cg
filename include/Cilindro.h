#ifndef CILINDRO_H
#define CILINDRO_H

#include "Objeto.h"
#include "Vetor.h"
#include "Matriz.h"
#include <vector>

using std::vector;

class Cilindro : public Objeto {
    public:
        Cilindro() {};

        Cilindro(Ponto cen, float r, Vetor dir, float alt) 
        : _base(cen)
        , _raio(r)
        , _direcao(dir)
        , _altura(alt)
        , _cor(0, 0, 0)
        // , _cor_difusa(0, 0, 0)
        // , _cor_especular(0, 0, 0) {
        {
            atualizar_topo();
        };

        // Cilindro(Ponto cen, float r, Vetor dir, float alt, Cor cor, Cor cor_difusa, Cor cor_especular) 
        // : _base(cen)
        // , _raio(r)
        // , _direcao(vetor_unitario(dir))
        // , _altura(alt)
        // , _cor(cor/255)
        // , _cor_difusa(cor_difusa/255.0f)
        // , _cor_especular(cor_especular/255.0f) {
        //     atualizar_topo();
        // };

        Cilindro(Ponto cen, float r, Vetor dir, float alt, Cor cor) 
        : _base(cen)
        , _raio(r)
        , _direcao(vetor_unitario(dir))
        , _altura(alt)
        , _cor(cor/255)
        // , _cor_difusa(_cor)
        // , _cor_especular(_cor) {
        {
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
        // Cor _cor_difusa;
        // Cor _cor_especular;
        Ponto _topo;
};

#endif