#include "Cubo.h"

//   3   7
// 1 4 5 8
// 2   6

// 315 - 357
// 142 - 134
// 126 - 651
// 268 - 842
// 768 - 756
// 478 - 743

bool Cubo::intersectar(const Raio& r,  float t_min, float t_max, PontoColisao& ptcol) const {
    
    bool intersect = false;
    PontoColisao ptcol_aux = ptcol;
    for(int i = 0; i < 12; i++){
        bool intersect_aux = _triangulos[i].intersectar(r, t_min, t_max, ptcol_aux);
        if (intersect_aux){
            intersect = true;
            if (ptcol_aux.t_int < ptcol.t_int){
                ptcol = ptcol_aux;
            }
        }
    }

    return intersect;
}

bool Cubo::backface_culling(const Raio& r) const {
    /* se normal esta na mesma direcao a direcao do raio, a face esta de costa ao observador, e portanto, nao eh a 'vencedora' 
       se < 0 entao eh vencedora; caso contrario, nao eh. */
    return (produto_escalar(_normal, r.direcao()) < 0);
}

void Cubo::atualizar_pontos(const Matriz &MT) {
    for (int i = 0; i < 12; i++){
        _triangulos[i].atualizar_pontos(MT);
    }
    atualizar_propriedades();
}