#include "Esfera.h"

bool Esfera::intersectar(const Raio& r,  float t_min, float t_max, PontoColisao& ptcol) const {
    Vetor oc = r.origem() - _centro;

    float b = produto_escalar(oc, r.direcao());
    float c = produto_escalar(oc, oc)-(_raio*_raio); 
    float delta = b*b - c;
    
    if (delta < 0) return false;
    
    float t_int_mp = -b + sqrt(delta);
    
    if (delta > 0) t_int_mp = -b - sqrt(delta);

    if(!(t_int_mp > t_min && t_int_mp < t_max)) return false;

    ptcol.t_int = t_int_mp;
    ptcol.pt = r.para(t_int_mp);
    ptcol.normal = (ptcol.pt - _centro) / _raio;
    ptcol.cor = _cor;
    // ptcol.cor_especular = _cor_difusa;
    // ptcol.cor_difusa = _cor_especular;
    ptcol.dr = r.direcao();
    ptcol.m = 1;

    return true;
}

void Esfera::atualizar_pontos(const Matriz &MT) {
    Ponto auxiliar = _centro;
    _centro = MT*auxiliar;
}