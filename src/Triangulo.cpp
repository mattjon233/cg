#include "Triangulo.h"

bool Triangulo::intersectar(const Raio& r,  float t_min, float t_max, PontoColisao& ptcol) const {
    /* Equaçao do plano */
    auto t_int = -produto_escalar(r.origem()-_vertice1, _normal)/produto_escalar(r.direcao(), _normal);

    /* verifica se t do raio esta na distancia valida */
    if(!(t_int > t_min && t_int < t_max)) return false;

    auto Pt_int = r.para(t_int);

    /* Vetor V_<vertice> utilizado para calcular a distancia do ponto */
    auto V_1 = _vertice1 - Pt_int;
    auto V_2 = _vertice2 - Pt_int;
    auto V_3 = _vertice3 - Pt_int;

    /* produto escalar da normal com a area V_<vertice> */
    auto V_3_1 = produto_escalar(_normal, cruz(V_3, V_1));
    auto V_1_2 = produto_escalar(_normal, cruz(V_1, V_2));
    auto V_2_3 = produto_escalar(_normal, cruz(V_2, V_3));

    /* verifica se nao houve interseccao com o plano do triangulo */
    if (!(V_3_1 > 0 && V_1_2 > 0 && V_2_3 > 0)) return false;

    ptcol.t_int = t_int;
    ptcol.pt = Pt_int;
    ptcol.normal = _normal;
    ptcol.cor = _cor;
    // ptcol.cor_especular = _cor_difusa;
    // ptcol.cor_difusa = _cor_especular;

    ptcol.dr = r.direcao();
    ptcol.m = 1;
    return true;
}

bool Triangulo::backface_culling(const Raio& r) const {
    /* se normal esta na mesma direcao a direcao do raio, a face esta de costa ao observador, e portanto, nao eh a 'vencedora' 
       se < 0 entao eh vencedora; caso contrario, nao eh. */
    return (produto_escalar(_normal, r.direcao()) < 0);
}

void Triangulo::atualizar_pontos(const Matriz &MT) {
    Ponto auxiliar = _vertice1;
    _vertice1 = MT*auxiliar;
    
    auxiliar = _vertice2;
    _vertice2 = MT*auxiliar;

    auxiliar = _vertice3;
    _vertice3 = MT*auxiliar;

    atualizar_propriedades();
}