#ifndef CAMERA_H
#define CAMERA_H

#include "Base.h"
#include "Matriz.h"

/**
 * @param lookfrom ponto de origem da camera
 * @param lookat ponto no qual a camera aponta
 * @param viewup vetor unitario de sentido eixo j
*/
class Camera {
    public:
        Camera() {}

        Camera(Ponto lookfrom, Ponto lookat, Ponto viewup, Ponto janela_pts, int Wpix, int Hpix) {
            
            /* coordenadas de camera (i, k, j) */
            _k = vetor_unitario(lookfrom - lookat);
            _i = vetor_unitario(cruz((viewup - lookfrom), _k));
            _j = cruz(_k, _i);
            _Q0 = lookfrom;

            _CpM = coordenadas_cpm(_i, _j, _k, _Q0);
            _MpC = coordenadas_mpc(_i, _j, _k, _Q0);

            _jp = janela_pts;
            _Hpix = Hpix;
            _Wpix = Wpix;
        }

        Ponto origem() {
            return _Q0;
        }

        int largura_imagem() {
            return _Wpix;
        }

        int altura_imagem() {
            return _Hpix;
        }

        Matriz coord_CpM() {
            return _CpM;
        }

        Matriz coord_MpC() {
            return _MpC;
        }

        Vetor eixo_i() {
            return _i;
        }

        Vetor eixo_j() {
            return _j;
        }

        Vetor eixo_k() {
            return _k;
        }

        Vetor janela_pontos() {
            return _jp;
        }

    private:
        Ponto _Q0;
        Vetor _i;
        Vetor _j;
        Vetor _k;
        Vetor _jp;
        Matriz _CpM;
        Matriz _MpC;
        int _Hpix, _Wpix;
};

#endif