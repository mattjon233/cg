#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include "Base.h"

class Matriz {
    public:
        Matriz() {
            int i, j;
            for(i = 0; i < 4; i++)
                for(j = 0; j < 4; j++)
                    val[i][j] = 0;
        }

        Matriz(float x00, float x01, float x02, float x03,
               float x10, float x11, float x12, float x13,
               float x20, float x21, float x22, float x23,
               float x30, float x31, float x32, float x33) : C0{x00,x10,x20,x30}, C1{x01,x11,x21,x31}, C2{x02,x12,x22,x32}, C3{x03,x13,x23,x33} {
            val[0][0] = x00;
            val[0][1] = x01;
            val[0][2] = x02;
            val[0][3] = x03;

            val[1][0] = x10;
            val[1][1] = x11;
            val[1][2] = x12;
            val[1][3] = x13;

            val[2][0] = x20;
            val[2][1] = x21;
            val[2][2] = x22;
            val[2][3] = x23;

            val[3][0] = x30;
            val[3][1] = x31;
            val[3][2] = x32;
            val[3][3] = x33;
        }

    public:
        float val[4][4];
        Ponto C0, C1, C2, C3;
};

Matriz coordenadas_cpm(Vetor i, Vetor j, Vetor k, Ponto o);

Matriz coordenadas_mpc(Vetor i, Vetor j, Vetor w, Ponto o);

Matriz matriz_rotacao(float graus, char eixo);

Matriz matriz_escala(Vetor S);

Matriz matriz_translacao(Vetor t);

Matriz matriz_cisalhamento(char e_1, char e_2, char d, float graus);

Matriz matriz_reflexao(char e_1, char e_2);

/* Matriz reflexao no qual n eh perpendicular/normal ao plano */
Matriz matriz_reflexao_e(Vetor n);

/* Matriz reflexao em plano arbitrário com n normal, ponto de origem e ponto arbitrario ao plano */
Ponto matriz_reflexao_a(Ponto o, Ponto a, Vetor n);

/* multiplição entre uma matriz (4x4) e um vetor */
Vetor operator*(const Matriz &m, const Ponto &v);

/* alocacao dinamica para matriz de cores */
Cor **alocar(int coluna, int linha);

#endif