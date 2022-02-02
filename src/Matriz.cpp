#include "Matriz.h"

Matriz coordenadas_cpm(Vetor i, Vetor j, Vetor k, Ponto o) {
    return Matriz(i.x(), j.x(), k.x(), o.x(),
                  i.y(), j.y(), k.y(), o.y(),
                  i.z(), j.z(), k.z(), o.z(),
                  0,     0,     0,     1);
}

Matriz coordenadas_mpc(Vetor i, Vetor j, Vetor k, Ponto o) {
    return Matriz(i.x(), i.y(), i.z(), -produto_escalar(o, i),
                  j.x(), j.y(), j.z(), -produto_escalar(o, j),
                  k.x(), k.y(), k.z(), -produto_escalar(o, k),
                  0,     0,     0,      1);
}

Matriz matriz_rotacao(float graus, char eixo) {
    graus = graus_em_radianos(graus);
    if (eixo == 'z')
    {
        return Matriz( cos(graus), -sin(graus), 0, 0,
                       sin(graus),  cos(graus), 0, 0,
                       0,           0,          1, 0,
                       0,           0,          0, 1);
    } 
    else if (eixo == 'x')
    {
        return Matriz( 1, 0,           0,          0,
                       0, cos(graus), -sin(graus), 0,
                       0, sin(graus),  cos(graus), 0,
                       0, 0,           0,          1);
    } 
    else if (eixo == 'y')
    {
        return Matriz( cos(graus),  0, sin(graus), 0,
                       0,           1, 0,          0,
                      -sin(graus),  0, cos(graus), 0,
                       0,           0, 0,          1);
    } else {
        return Matriz();
    }
}

Matriz matriz_escala(Vetor S) {
    return Matriz(S.x(), 0,     0,     0,
                  0,     S.y(), 0,     0,
                  0,     0,     S.z(), 0,
                  0,     0,     0,     1);
}

Matriz matriz_escala(Vetor S, Ponto P) {
    return Matriz(S.x(), 0,     0,     (1-S.x())*P.x(),
                  0,     S.y(), 0,     (1-S.y())*P.y(),
                  0,     0,     S.z(), (1-S.z())*P.z(),
                  0,     0,     0,     1);
}

Matriz matriz_translacao(Vetor t) {
    return Matriz(1, 0, 0, t.x(),
                  0, 1, 0, t.y(),
                  0, 0, 1, t.z(),
                  0, 0, 0, 1);
}

Matriz matriz_cisalhamento(char e_1, char e_2, char d, float graus) {
    graus = graus_em_radianos(graus);
    if (e_1 == 'x' && e_2 == 'y' && d == 'x')
    {
        return Matriz( 1, tan(graus), 0, 0,
                       0,     1,      0, 0,
                       0,     0,      1, 0,
                       0,     0,      0, 1);
    }
    else if (e_1 == 'x' && e_2 == 'y' && d == 'y')
    {
        return Matriz( 1,         0, 0, 0,
                      tan(graus), 1, 0, 0,
                       0,         0, 1, 0,
                       0,         0, 0, 1);
    } 
    else if (e_1 == 'x' && e_2 == 'z' && d == 'x')
    {
        return Matriz( 1, 0, tan(graus), 0,
                       0, 1,    0,       0,
                       0, 0,    1,       0,
                       0, 0,    0,       1);
    }
    else if (e_1 == 'x' && e_2 == 'z' && d == 'z')
    {
        return Matriz( 1,          0, 0, 0,
                       0,          1, 0, 0,
                       tan(graus), 0, 1, 0,
                       0,          0, 0, 1);
    }
    else if (e_1 == 'y' && e_2 == 'z' && d == 'y')
    {
        return Matriz( 1, 0,    0,       0,
                       0, 1, tan(graus), 0,
                       0, 0,    1,       0,
                       0, 0,    0,       1);
    }
    else if (e_1 == 'y' && e_2 == 'z' && d == 'z')
    {
        return Matriz( 1,   0,        0, 0,
                       0,   1,        0, 0,
                       0, tan(graus), 1, 0,
                       0,   0,        0, 1);
    }
    else {
        return Matriz();
    }
}

Matriz matriz_reflexao(char e_1, char e_2) {
    if (e_1 == 'x' && e_2 == 'y')
    {
        return Matriz( 1, 0, 0, 0,
                       0, 1, 0, 0,
                       0, 0,-1, 0,
                       0, 0, 0, 1);
    }
    else if (e_1 == 'x' && e_2 == 'z')
    {
        return Matriz( 1, 0, 0, 0,
                       0,-1, 0, 0,
                       0, 0, 1, 0,
                       0, 0, 0, 1);
    }
    else if (e_1 == 'y' && e_2 == 'z')
    {
        return Matriz(-1, 0, 0, 0,
                       0, 1, 0, 0,
                       0, 0, 1, 0,
                       0, 0, 0, 1);
    }
    else {
        return Matriz();
    }
}

Matriz matriz_reflexao_e(Vetor n) {
    if (n.comprimento() == 1)
    {
        return Matriz( 1-2*n.x()*n.x(), -2*n.x()*n.y(), -2*n.x()*n.z(), 0,
                       -2*n.y()*n.x(), 1-2*n.y()*n.y(), -2*n.y()*n.z(), 0,
                       -2*n.z()*n.x(), -2*n.z()*n.y(), 1-2*n.z()*n.z(), 0,
                               0,              0,               0,      1);
    }
    else {
        return Matriz();
    }
}

Ponto matriz_reflexao_a(Ponto o, Ponto a, Vetor n) {
    if (n.comprimento() == 1)
    {
        auto t_ao = o-a;
        auto t_oa = a-o;
        return (matriz_reflexao_e(n)*t_ao)*t_oa;
    }
    else {
        return Ponto();
    }
}

Vetor operator*(const Matriz &m, const Ponto &v) {
    return m.C0*v.x() + m.C1*v.y() + m.C2*v.z() + m.C3*v.w();
}

Cor **alocar(int coluna, int linha) {
    Cor **M;
    
    M = (Cor **) malloc(sizeof(Cor *) * coluna);
    if(M == NULL) return nullptr;

    for(int i = 0; i < coluna; i++)
    {
        M[i] = (Cor *) malloc(sizeof(Cor) * linha);
        if(M[i] == NULL) return nullptr;
    }
    
    return M;
}