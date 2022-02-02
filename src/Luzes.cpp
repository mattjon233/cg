#include "Luzes.h"

void Luzes::atualizar_posicao(const Matriz &MT) {
    for (auto& l : _luzes) l->atualizar_posicao(MT);
}

void Luzes::iluminar(Cenario& world, PontoColisao& ptcol) {
    bool sombra = false;

    for (const auto& l : _luzes)
    {
        if (l->tem_posicao())
        {
            for (const auto& obj : world._objetos) {
                auto d_pt_l = (l->posicao() - ptcol.pt);

                Raio r_s(ptcol.pt, vetor_unitario(d_pt_l));
                PontoColisao aux;

                if (obj->intersectar(r_s, 0, d_pt_l.comprimento(), aux)) { sombra = true; break; }
            }
        }

        if (!sombra) ptcol.cor += l->luminancia(ptcol);

        if (sombra == true) sombra = false;
    }
}