#ifndef LUZES_H
#define LUZES_H

#include "Base.h"
#include "Luz.h"
#include "Cenario.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;
using std::vector;

class Cenario;

class Luzes {
    public:
        Luzes() {}

        void clear() { _luzes.clear(); }
        
        void add(shared_ptr<Luz> l) { _luzes.push_back(l); }

        void atualizar_posicao(const Matriz &MT);

        void iluminar(Cenario& world, PontoColisao& ptcol);

    public:
        vector<shared_ptr<Luz>> _luzes;
};

#endif