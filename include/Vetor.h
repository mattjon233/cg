#ifndef VETOR_H
#define VETOR_H

#include <cmath>
#include <iostream>

using namespace std;


/**
 * Coordenadas possuem 4 componentes. Na cood de câmera, temos um vetor:
 *  Ic = {e0, e1, e2, 1} = C0 + Xe0 + Ye1 + Ze2
 *  Jc = {e0, e1, e2, 1} = C0 + Xe0 + Ye1 + Ze2
 *  Kc = {e0, e1, e2, 1} = C0 + Xe0 + Ye1 + Ze2
 *  com {X, Y, Z} a base ortonognal desse plano e C0 um ponto
 * Para coordenadas do mundo, temos:
 *  Cm = 
*/

class Vetor {
    public:
        Vetor() : e{0, 0, 0, 0} {}
        Vetor(float e0, float e1, float e2) : e{e0, e1, e2, 0} {}
        Vetor(float e0, float e1, float e2, float e3) : e{e0, e1, e2, e3} {}

        float x() const { return e[0]; }
        float y() const { return e[1]; }
        float z() const { return e[2]; }
        float w() const { return e[3]; }

        Vetor operator-() const { return Vetor(-e[0], -e[1], -e[2], -e[3]); }
        Vetor operator-(const float t) const { return Vetor(e[0]-t, e[1]-t, e[2]-t); }
        float operator[](int i) const { return e[i]; }
        float& operator[](int i) { return e[i]; }

        Vetor& operator+=(const Vetor &v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            e[3] += v.e[3];
            return *this;
        }

        Vetor& operator*=(const float t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            e[3] *= t;
            return *this;
        }

        Vetor& operator/=(const float t) {
            return *this *= 1/t;
        }

        float comprimento() const {
            return sqrt(componentes_ao_quadrado());
        }

        float componentes_ao_quadrado() const {
            return     e[0]*e[0]
                     + e[1]*e[1]
                     + e[2]*e[2]
                     + e[3]*e[3];
        }

        /*
        static Vetor random() {
            return Vetor(random_double(), random_double(), random_double());
        }

        static Vetor random(double min, double max) {
            return Vetor(random_double(min, max), random_double(min, max), random_double(min,max));
        }
        */
        bool proximo_de_zero() const {
            return     (fabs(e[0]) < 1e-8)
                    && (fabs(e[1]) < 1e-8)
                    && (fabs(e[2]) < 1e-8)
                    && (fabs(e[3]) < 1e-8);
        }
        
    public:
        float e[4];
};

using Ponto = Vetor;
using Cor = Vetor;
// using Pixel = Vetor;

ostream& operator<<(ostream &out, const Vetor &v);

Vetor operator+(const Vetor &u, const Vetor &v);

Vetor operator-(const Vetor &u, const Vetor &v);

Vetor operator*(const Vetor &u, const Vetor &v);

Vetor operator*(float t, const Vetor &v);

Vetor operator*(const Vetor &v, float t);

Vetor operator/(Vetor v, float t);

/**
 * @brief também conhecido por produto escalar (dot), é soma dos produtos resultantes da multiplicação dos componentes dos vetores
 * @return escalar de tipo float
*/
float produto_escalar(const Vetor &u, const Vetor &v);

/**
 * @brief produto vetorial dos vetores u e v
*/
Vetor cruz(const Vetor &u, const Vetor &v);

/**
 * @brief vetor direcao, tambem conhecido como a normal do vetor v
*/
Vetor vetor_unitario(Vetor v);

Vetor reflexo(const Vetor& v, const Vetor& n);

#endif