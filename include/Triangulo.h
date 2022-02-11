#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Objeto.h"
#include "Vetor.h"
#include "Matriz.h"
 
#include <vector>

using std::vector;

class Triangulo : public Objeto {
    public:
        Triangulo() {};

        Triangulo(Ponto vert1,Ponto vert2, Ponto vert3)
        : _vertice1(vert1)
        , _vertice2(vert2)
        , _vertice3(vert3)
        , _cor(0, 0, 0) {
            atualizar_propriedades();
        };

        Triangulo(Ponto vert1,Ponto vert2, Ponto vert3, Cor cor)
        : _vertice1(vert1)
        , _vertice2(vert2)
        , _vertice3(vert3)
        , _cor((cor * (1.0/255.0f))) {

            atualizar_propriedades();
        };

        virtual bool intersectar(const Raio& r,  float t_min, float t_max, PontoColisao& ptcol) const override;

        virtual void atualizar_pontos(const Matriz &MT) override;

        bool backface_culling(const Raio& r) const;

        void atualizar_propriedades(void) {
            _Vd1p2 = _vertice2-_vertice1;
            _Vd1p3 = _vertice3-_vertice1;
            _normal = vetor_unitario(cruz(_Vd1p2, _Vd1p3));
        }

    public:
        Ponto _vertice1, _vertice2, _vertice3;
        Vetor _Vd1p2, _Vd1p3, _normal; 
        Cor _cor;
};

#endif