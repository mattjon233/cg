#ifndef CUBO_H
#define CUBO_H

#include "Objeto.h"
#include "Vetor.h"
#include "Matriz.h"
#include "Triangulo.h"
 
#include <vector>

using std::vector;

class Cubo : public Objeto {
    public:
        Cubo() {};

        Cubo(Ponto centro, float largura, float altura, float profundidade) : _cor(0, 0, 0) {
            Ponto ponto_1 = Ponto(centro.e[0] - largura/2, centro.e[1] + altura/2, centro.e[2] + profundidade/2, 0);
            Ponto ponto_2 = Ponto(centro.e[0] - largura/2, centro.e[1] - altura/2, centro.e[2] + profundidade/2, 0);
            Ponto ponto_3 = Ponto(centro.e[0] - largura/2, centro.e[1] + altura/2, centro.e[2] - profundidade/2, 0);
            Ponto ponto_4 = Ponto(centro.e[0] - largura/2, centro.e[1] - altura/2, centro.e[2] - profundidade/2, 0);
            Ponto ponto_5 = Ponto(centro.e[0] + largura/2, centro.e[1] + altura/2, centro.e[2] + profundidade/2, 0);
            Ponto ponto_6 = Ponto(centro.e[0] + largura/2, centro.e[1] - altura/2, centro.e[2] + profundidade/2, 0);
            Ponto ponto_7 = Ponto(centro.e[0] + largura/2, centro.e[1] + altura/2, centro.e[2] - profundidade/2, 0);
            Ponto ponto_8 = Ponto(centro.e[0] + largura/2, centro.e[1] - altura/2, centro.e[2] - profundidade/2, 0);         
    
            _triangulos[0] = Triangulo(ponto_3, ponto_1, ponto_5);
            _triangulos[1] = Triangulo(ponto_3, ponto_5, ponto_7);
            _triangulos[2] = Triangulo(ponto_1, ponto_4, ponto_2);
            _triangulos[3] = Triangulo(ponto_1, ponto_3, ponto_4);
            _triangulos[4] = Triangulo(ponto_1, ponto_2, ponto_6);
            _triangulos[5] = Triangulo(ponto_6, ponto_5, ponto_1);
            _triangulos[6] = Triangulo(ponto_2, ponto_6, ponto_8);
            _triangulos[7] = Triangulo(ponto_8, ponto_4, ponto_2);
            _triangulos[8] = Triangulo(ponto_7, ponto_6, ponto_8);
            _triangulos[9] = Triangulo(ponto_7, ponto_5, ponto_6);
            _triangulos[10] = Triangulo(ponto_4, ponto_7, ponto_8);
            _triangulos[11] = Triangulo(ponto_7, ponto_4, ponto_3);

            atualizar_propriedades();

        };

        Cubo(Ponto centro, float largura, float altura, float profundidade, Cor cor) : _cor(cor) {
            Ponto ponto_1 = Ponto(centro.e[0] - largura/2, centro.e[1] + altura/2, centro.e[2] + profundidade/2, 0);
            Ponto ponto_2 = Ponto(centro.e[0] - largura/2, centro.e[1] - altura/2, centro.e[2] + profundidade/2, 0);
            Ponto ponto_3 = Ponto(centro.e[0] - largura/2, centro.e[1] + altura/2, centro.e[2] - profundidade/2, 0);
            Ponto ponto_4 = Ponto(centro.e[0] - largura/2, centro.e[1] - altura/2, centro.e[2] - profundidade/2, 0);
            Ponto ponto_5 = Ponto(centro.e[0] + largura/2, centro.e[1] + altura/2, centro.e[2] + profundidade/2, 0);
            Ponto ponto_6 = Ponto(centro.e[0] + largura/2, centro.e[1] - altura/2, centro.e[2] + profundidade/2, 0);
            Ponto ponto_7 = Ponto(centro.e[0] + largura/2, centro.e[1] + altura/2, centro.e[2] - profundidade/2, 0);
            Ponto ponto_8 = Ponto(centro.e[0] + largura/2, centro.e[1] - altura/2, centro.e[2] - profundidade/2, 0);         
    
            _triangulos[0] = Triangulo(ponto_3, ponto_1, ponto_5, Cor (255,0,0));
            _triangulos[1] = Triangulo(ponto_3, ponto_5, ponto_7, Cor (255,0,0));
            _triangulos[2] = Triangulo(ponto_1, ponto_4, ponto_2, Cor (255,0,0));
            _triangulos[3] = Triangulo(ponto_1, ponto_3, ponto_4, Cor (255,0,0));
            _triangulos[4] = Triangulo(ponto_1, ponto_2, ponto_6, Cor (255,0,0));
            _triangulos[5] = Triangulo(ponto_6, ponto_5, ponto_1, Cor (255,0,0));
            _triangulos[6] = Triangulo(ponto_2, ponto_6, ponto_8, Cor (255,0,0));
            _triangulos[7] = Triangulo(ponto_8, ponto_4, ponto_2, Cor (255,0,0));
            _triangulos[8] = Triangulo(ponto_7, ponto_6, ponto_8, Cor (255,0,0));
            _triangulos[9] = Triangulo(ponto_7, ponto_5, ponto_6, Cor (255,0,0));
            _triangulos[10] = Triangulo(ponto_4, ponto_7, ponto_8, Cor (255,0,0));
            _triangulos[11] = Triangulo(ponto_7, ponto_4, ponto_3, Cor (255,0,0));            

            atualizar_propriedades();
        }

        virtual bool intersectar(const Raio& r,  float t_min, float t_max, PontoColisao& ptcol) const override;

        virtual void atualizar_pontos(const Matriz &MT) override;

        bool backface_culling(const Raio& r) const;

        void atualizar_propriedades(void) {
            for (int i = 0; i < 12; i++){
                _triangulos[i].atualizar_propriedades();
            }

        }

    public:
        Triangulo _triangulos[12];
        Vetor _Vd1p2, _Vd1p3, _normal; 
        Cor _cor;
};

#endif