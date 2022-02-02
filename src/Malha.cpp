#include "Malha.h"

bool Malha::intersectar(const Raio& r, float t_min, float t_max, PontoColisao& ptcol) const {
    for (auto& face : _faces)
        if (face.backface_culling(r))
            if (face.intersectar(r, t_min, t_max, ptcol))
                return true;

    return false;
}

void Malha::atualizar_pontos(const Matriz &CpM) {
    for (auto& face : _faces) face.atualizar_pontos(CpM);
}