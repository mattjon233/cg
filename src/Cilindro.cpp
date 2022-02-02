#include "Cilindro.h"

bool Cilindro::intersectar(const Raio& r,  float t_min, float t_max, PontoColisao& ptcol) const {
    /* P0 - Cc */
    auto w = r.origem()-_base;

    /* valores auxiliares */
    auto dr_dc = produto_escalar(r.direcao(), _direcao);
    auto w_w = produto_escalar(w, w);
    auto w_dr = produto_escalar(w, r.direcao());
    auto w_dc = produto_escalar(w, _direcao);

    auto a = 1 - pow(dr_dc,2);
    auto b = (w_dr - w_dc * dr_dc); // 2 *
    auto c = w_w - pow(w_dc,2) - pow(_raio,2);

    auto delta = pow(b,2) - a*c;

    /* sem interseccao */
    if (delta < 0) return false;

    float t_int;
    bool base = false, topo = false;

    auto t_1 = (-b + sqrt(delta))/a;
    auto v_1_dr = produto_escalar((r.para(t_1) - _base), _direcao);
    auto v_1_valida = (v_1_dr > 0 && v_1_dr < _altura);

    auto t_2 = (-b - sqrt(delta))/a;
    auto v_2_dr = produto_escalar((r.para(t_2) - _base), _direcao);
    auto v_2_valida = (delta > 0 && (v_2_dr > 0 && v_2_dr < _altura));
    
    if (v_1_valida && v_2_valida) { 
        t_int = (t_1 < t_2) ? t_1 : t_2;
    } 
    else if (!v_1_valida && v_2_valida) {
        t_int = t_2;
    } 
    else if (v_1_valida && !v_2_valida) {
        auto t_b = -produto_escalar(w, _direcao)/dr_dc;
        auto t_t = -produto_escalar(r.origem()-_topo, _direcao)/dr_dc;
        auto t_m = (t_b < t_t) ? t_b : t_t;

        t_int = ((r.para(t_m)-_base).comprimento() > _raio && t_1 < t_m) ? t_1 : t_m;
        base = (t_int == t_b);
        topo = (t_int == t_t);
    } 
    else if (!(v_1_valida && v_2_valida)) {
        auto t_b = -produto_escalar(w, _direcao)/dr_dc;
        auto t_t = -produto_escalar(r.origem()-_topo, _direcao)/dr_dc;

        if (!((r.para(t_b)-_base).comprimento() < _raio || (r.para(t_t)-_topo).comprimento() < _raio)) return false;
        t_int = (t_b < t_t) ? t_b : t_t;
        base = (t_int == t_b);
        topo = (t_int == t_t);
    }

    if(!(t_int > t_min && t_int < t_max)) return false;

    ptcol.t_int = t_int;
    ptcol.pt = r.para(t_int);
    if (!base && !topo) {
        auto w = vetor_unitario(ptcol.pt-_base);
        ptcol.normal = vetor_unitario(w - _direcao*produto_escalar(w, _direcao));
    } else if (base) {
        ptcol.normal = -_direcao;
    } else if (topo) {
        ptcol.normal = _direcao;
    }
    
    ptcol.cor = _cor;
    ptcol.dr = r.direcao();
    ptcol.m = 1;

    return true;
}

void Cilindro::atualizar_pontos(const Matriz &MT) {
    Ponto auxiliar = _base;
    _base = MT*auxiliar;
    atualizar_topo();
    rotacionar(MT);
}

void Cilindro::rotacionar(const Matriz &MT) {
    Ponto auxiliar = _direcao;
    _direcao = vetor_unitario(MT*auxiliar);
}