#ifndef CENARIO_H
#define CENARIO_H

#include "Base.h"
#include "Objeto.h"
 

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;
using std::vector;

class Cenario : public Objeto {
    public:
        Cenario() {}

        void clear() { _objetos.clear(); }
        
        void add(shared_ptr<Objeto> obj) { _objetos.push_back(obj); }

        virtual bool intersectar(const Raio& r, float t_min, float t_max, PontoColisao& ptcol) const override;

        virtual void atualizar_pontos(const Matriz &CpM) override;

    public:
        vector<shared_ptr<Objeto>> _objetos;
};

#endif