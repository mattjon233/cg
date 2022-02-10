#ifndef RENDER_H
#define RENDER_H

#include <iostream>
#include <fstream>
#include "Base.h"
#include "Camera.h"
#include "Matriz.h"
#include "Esfera.h"
#include "Cenario.h"
#include "Luzes.h"

class Render {
    public:
        Render(Camera& cam) : _cam(cam) {}

        void tirar_fotografia(Cenario world, Luzes luzes, Cor background, string projecao);

        void obter_cmax(Cor& c);

        Cor** MC;

    private:
        string _path_abs;
        string _cmd;
        Camera _cam;
        float _c_max;
};

#endif