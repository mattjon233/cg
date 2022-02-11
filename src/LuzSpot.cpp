#include "LuzSpot.h"

Cor LuzSpot::luminancia(PontoColisao& ptcol) const {
    auto l = vetor_unitario(_p0 - ptcol.pt);
    auto cosp = produto_escalar(_d, -l);

    /* passou do 'raio' de iluminacao da luz */
    if (cosp < cos(_theta)) return Cor(0, 0, 0);

    auto n = ptcol.normal;
    auto v = -ptcol.dr;
    auto r = reflexo(l, n);
    auto m = ptcol.m;
    auto Ko = ptcol.cor;
    // auto Kd = ptcol.cor_difusa;
    // auto Ks = ptcol.cor_especular;
    
    auto If = _intensidade * pow(cosp, _e);

    auto ftd = fd(n, l);
    auto fts = fs(r, v, m);

    // return If*Kd*ftd + If*Ks*fts + If*Ko;
    return If*Ko*ftd + If*Ko*fts;
}

void LuzSpot::atualizar_posicao(const Matriz &MT) {
    Ponto auxiliar = _p0;
    _p0 = MT*auxiliar;
}