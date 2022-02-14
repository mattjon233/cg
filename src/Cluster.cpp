#include "Cluster.h"

void Cluster::configurar() {
    Ponto Pc(0, 0, 0, 0);
    double x_min = 1000000, y_min = 1000000, z_min = 1000000;

    for (const Malha& obj : _objetos) 
    {
        for(const Triangulo& f : obj._faces)
        {
            if(x_min > f._vertice1.x()) x_min = f._vertice1.x();
            if(y_min > f._vertice1.y()) y_min = f._vertice1.y();
            if(z_min > f._vertice1.z()) z_min = f._vertice1.z();

            if(x_min > f._vertice2.x()) x_min = f._vertice2.x();
            if(y_min > f._vertice2.y()) y_min = f._vertice2.y();
            if(z_min > f._vertice2.z()) z_min = f._vertice2.z();

            if(x_min > f._vertice3.x()) x_min = f._vertice3.x();
            if(y_min > f._vertice3.y()) y_min = f._vertice3.y();
            if(z_min > f._vertice3.z()) z_min = f._vertice3.z();

            Pc += f._vertice1 + f._vertice2 + f._vertice3;
        }
    }
    /* Ponto por padrao eh instanciado com a ultima posicao igual a 1 */
    Pc /= Pc[3];
    
    _altura  = 2 * (Pc.y() - y_min);
    _raio    = sqrt(pow(Pc.z() - z_min, 2) + pow(Pc.x() - x_min, 2));
    _base    = Ponto(Pc.x(), y_min, Pc.z(), 1);
    _direcao = Vetor(0, 1, 0);

    atualizar_topo();
}

bool Cluster::intersectar(const Raio& r, float t_min, float t_max, PontoColisao& ptcol) const {
    auto w = r.origem()-_base;

    // valores auxiliares
    auto dr_dc = produto_escalar(r.direcao(), _direcao);
    auto w_w = produto_escalar(w, w);
    auto w_dr = produto_escalar(w, r.direcao());
    auto w_dc = produto_escalar(w, _direcao);

    auto a = 1 - pow(dr_dc,2);
    auto b = (w_dr - w_dc * dr_dc); // 2 *
    auto c = w_w - pow(w_dc,2) - pow(_raio,2);

    auto delta = pow(b,2) - a*c;

    // sem intersecção
    if (delta < 0) return false;

    float t_int;

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
    } 
    else if (!(v_1_valida && v_2_valida)) {
        auto t_b = -produto_escalar(w, _direcao)/dr_dc;
        auto t_t = -produto_escalar(r.origem()-_topo, _direcao)/dr_dc;

        if (!((r.para(t_b)-_base).comprimento() < _raio || (r.para(t_t)-_topo).comprimento() < _raio)) return false;
        t_int = (t_b < t_t) ? t_b : t_t;
    }

    if(!(t_int > t_min && t_int < t_max)) return false;
    
    for (auto& obj : _objetos)
        if (obj.intersectar(r, t_min, t_max, ptcol)) 
            return true;

    return false;
}

void Cluster::atualizar_pontos(const Matriz &MT) {
    for (auto& obj : _objetos) obj.atualizar_pontos(MT);
}