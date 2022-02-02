#include "Cone.h"

bool Cone::intersectar(const Raio& r,  float t_min, float t_max, PontoColisao& ptcol) const {
    /* V - P0 */
    auto w = _vertice-r.origem();

    /* valores auxiliares */
    auto dr_dr = produto_escalar(r.direcao(), r.direcao());
    auto dr_dc = produto_escalar(r.direcao(), _direcao);
    auto w_w = produto_escalar(w, w);
    auto w_dr = produto_escalar(w, r.direcao());
    auto w_dc = produto_escalar(w, _direcao);
    
    /* cos²(alfa) */
    auto ca = pow(_altura,2)/(pow(_raio,2) + pow(_altura,2));

    auto a = pow(dr_dc,2) - ca * dr_dr;
    auto b = w_dr * ca - w_dc * dr_dc;
    auto c = pow(w_dc,2) - w_w * ca;

    float t_int, s, pb;
    bool base = false;

    if (a == 0) {
        /* caso especial: dr paralela a geratriz. somente uma raiz: delta = -2*b + c; */
        t_int = -c/b;
        
        /* interseccao com a superficie do cone */
        s = produto_escalar(r.para(t_int) - _centro, _direcao);
        
        /* ponto de colisao dentro do cone 0 < S < H : (s > 0 && s < _altura)*/

        /* interseccao com a base do cone */
        pb = -produto_escalar(r.origem()-_centro, _direcao)/dr_dc;

        /* verificar se ponto esta dentro do raio da base: ((r.para(pb)-_centro).comprimento()) */

        /* com pb ja valido, vemos qual t menor */
        t_int = (s < pb) ? t_int : pb;
    } else {
        auto delta = pow(b,2) - a*c;

        /* sem interseccao */
        if (delta < 0) return false;
        
        auto t_1 = (-b + sqrt(delta))/a;
        auto s_1 = produto_escalar(r.para(t_1) - _centro, _direcao);
        auto s_1_valida = (s_1 > 0 && s_1 < _altura);

        auto t_2 = (-b - sqrt(delta))/a;
        auto s_2 = produto_escalar(r.para(t_2) - _centro, _direcao);
        auto s_2_valida = (delta > 0 && (s_2 > 0 && s_2 < _altura));
        
        if (s_1_valida && s_2_valida) { 
            t_int = (t_1 < t_2) ? t_1 : t_2;
        } 
        else if (!s_1_valida && s_2_valida) {
            t_int = t_2;
        } 
        else if (s_1_valida && !s_2_valida) {
            pb = -produto_escalar(r.origem()-_centro, _direcao)/dr_dc;

            t_int = ((r.para(pb)-_vertice).comprimento() > _raio && t_1 < pb) ? t_1 : pb;
            base = (t_int == pb);
        } 
        else {
            return false;
        }
    }

    if(!(t_int > t_min && t_int < t_max)) return false;

    ptcol.t_int = t_int;
    ptcol.pt = r.para(t_int);
    if (!base) ptcol.normal = vetor_unitario(_direcao - vetor_unitario(_vertice - ptcol.pt) * ca); // TODO: ajeitar
    else ptcol.normal = -_direcao;
    ptcol.cor = _cor;
    ptcol.dr = r.direcao();
    ptcol.m = 1;

    return true;
}

void Cone::atualizar_pontos(const Matriz &MT) {
    Ponto auxiliar = _centro;
    _centro = MT*auxiliar;
    atualizar_vertice();
    rotacionar(MT);
}

void Cone::rotacionar(const Matriz &MT) {
    Ponto auxiliar = _direcao;
    _direcao = vetor_unitario(MT*auxiliar);
    atualizar_vertice();
}