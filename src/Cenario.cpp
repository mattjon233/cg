#include "Cenario.h"

bool Cenario::intersectar(const Raio& r, float t_min, float t_max, PontoColisao& ptcol) const {
    PontoColisao temp_ptcol;
    auto temp_t_max = t_max;
    bool colisao = false;

    for (const auto& obj : _objetos)
    {
        if (obj->intersectar(r, t_min, temp_t_max, temp_ptcol)) 
        {
            colisao = true;
            temp_t_max = temp_ptcol.t_int;
            ptcol = temp_ptcol;
        }
    }

    return colisao;
}

void Cenario::atualizar_pontos(const Matriz &MT) {
    for (auto& obj : _objetos) obj->atualizar_pontos(MT);
}