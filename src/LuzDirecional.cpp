#include "LuzDirecional.h"

Cor LuzDirecional::luminancia(PontoColisao& ptcol) const {
    auto l = -_d;
    auto n = ptcol.normal;
    auto v = -ptcol.dr;
    auto r = reflexo(l, n);
    auto m = ptcol.m;
    auto Ko = ptcol.cor;
    
    auto ftd = fd(n, l);
    auto fts = fs(r, v, m);

return _intensidade*Ko*ftd + _intensidade*Ko*fts;
}