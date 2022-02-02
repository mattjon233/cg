#ifndef CLUSTER_H
#define CLUSTER_H

#include "Base.h"
#include "Objeto.h"
 
#include "Malha.h"

#include <vector>

using std::vector;

class Cluster : public Objeto {
    public:
        Cluster() {}

        void clear() { _objetos.clear(); }
        void add(Malha obj) { _objetos.push_back(obj); }
        void add(Cluster clt) { _clusters.push_back(clt); }
        virtual bool intersectar(const Raio& r, float t_min, float t_max, PontoColisao& ptcol) const override;
        virtual void atualizar_pontos(const Matriz &CpM) override;
        void configurar();
        void atualizar_topo(void) { _topo = _base + vetor_unitario(_direcao)*_altura; }

    public:
        vector<Cluster> _clusters;
        vector<Malha> _objetos;
        Ponto _base;
        Ponto _topo;
        Vetor _direcao;
        float _raio;
        float _altura;
};

#endif