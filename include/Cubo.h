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

        Cubo(Ponto centro, float largura, float altura, float profundidade) {
            Ponto ponto_1 = Ponto(centro.e[0] - largura/2, centro.e[1] + altura/2, centro.e[2] + profundidade/2, 1);
            Ponto ponto_2 = Ponto(centro.e[0] - largura/2, centro.e[1] - altura/2, centro.e[2] + profundidade/2, 1);
            Ponto ponto_3 = Ponto(centro.e[0] - largura/2, centro.e[1] + altura/2, centro.e[2] - profundidade/2, 1);
            Ponto ponto_4 = Ponto(centro.e[0] - largura/2, centro.e[1] - altura/2, centro.e[2] - profundidade/2, 1);
            Ponto ponto_5 = Ponto(centro.e[0] + largura/2, centro.e[1] + altura/2, centro.e[2] + profundidade/2, 1);
            Ponto ponto_6 = Ponto(centro.e[0] + largura/2, centro.e[1] - altura/2, centro.e[2] + profundidade/2, 1);
            Ponto ponto_7 = Ponto(centro.e[0] + largura/2, centro.e[1] + altura/2, centro.e[2] - profundidade/2, 1);
            Ponto ponto_8 = Ponto(centro.e[0] + largura/2, centro.e[1] - altura/2, centro.e[2] - profundidade/2, 1);         
            
            int r = 216;
            int g = 34;
            int b = 47;
            
            _triangulos[0] = Triangulo(ponto_3, ponto_1, ponto_5, Cor(r,g,b));
            _triangulos[1] = Triangulo(ponto_3, ponto_5, ponto_7, Cor(r,g,b));
            _triangulos[2] = Triangulo(ponto_1, ponto_4, ponto_2, Cor(r,g,b));
            _triangulos[3] = Triangulo(ponto_1, ponto_3, ponto_4, Cor(r,g,b));
            _triangulos[4] = Triangulo(ponto_1, ponto_2, ponto_6, Cor(r,g,b));
            _triangulos[5] = Triangulo(ponto_6, ponto_5, ponto_1, Cor(r,g,b));
            _triangulos[6] = Triangulo(ponto_2, ponto_6, ponto_8, Cor(r,g,b));
            _triangulos[7] = Triangulo(ponto_8, ponto_4, ponto_2, Cor(r,g,b));
            _triangulos[8] = Triangulo(ponto_7, ponto_6, ponto_8, Cor(r,g,b));
            _triangulos[9] = Triangulo(ponto_7, ponto_5, ponto_6, Cor(r,g,b));
            _triangulos[10] = Triangulo(ponto_4, ponto_7, ponto_8, Cor(r,g,b));
            _triangulos[11] = Triangulo(ponto_7, ponto_4, ponto_3, Cor(r,g,b));

            atualizar_propriedades();

        };

        virtual bool intersectar(const Raio& r,  float t_min, float t_max, PontoColisao& ptcol) const override;

        virtual void atualizar_pontos(const Matriz &MT) override;

        void atualizar_propriedades(void) {
            for (int i = 0; i < 12; i++){
                _triangulos[i].atualizar_propriedades();
            }

        }

    public:
        Triangulo _triangulos[12];
        Cor _cor;
};

#endif