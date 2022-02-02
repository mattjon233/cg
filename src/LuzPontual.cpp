#include "LuzPontual.h"

Cor LuzPontual::luminancia(PontoColisao& ptcol) const {
    auto l = vetor_unitario(_p0 - ptcol.pt);
    auto n = ptcol.normal;
    auto v = -ptcol.dr;
    auto r = reflexo(l, n);
    auto m = ptcol.m;
    auto Ko = ptcol.cor;
    // auto s = ptcol.pt-_p0;
    
    auto If = _intensidade; //  * ( 1 / s.comprimento() )

    auto ftd = fd(n, l);
    auto fts = fs(r, v, m);

    return If*Ko*ftd + If*Ko*fts;
}

void LuzPontual::atualizar_posicao(const Matriz &MT) {
    Ponto auxiliar = _p0;
    _p0 = MT*auxiliar;
}