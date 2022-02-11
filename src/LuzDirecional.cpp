#include "LuzDirecional.h"

Cor LuzDirecional::luminancia(PontoColisao& ptcol) const {
    auto l = -_d;
    auto n = ptcol.normal;
    auto v = -ptcol.dr;
    auto r = reflexo(l, n);
    auto m = ptcol.m;
    auto Ko = ptcol.cor;
    // auto Kd = ptcol.cor_difusa;
    // auto Ks = ptcol.cor_especular;
    
    auto If = _intensidade;

    auto ftd = fd(n, l);
    auto fts = fs(r, v, m);

    // return If*Kd*ftd + If*Ks*fts + If*Ko;
    return If*Ko*ftd + If*Ko*fts;
}