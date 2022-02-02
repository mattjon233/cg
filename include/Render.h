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
        Render(string path_abs, string cmd, Camera& cam) : _path_abs(path_abs), _cmd(cmd), _cam(cam) {}

        void tirar_fotografia(Cenario world, Luzes luzes, Cor background, string projecao);

        void escrever_arquivo(ofstream& arq, Cor p);

        void conf_arquivo(ofstream& arq, int largura, int altura);

        void executar_arquivo(string cmd);

        void obter_cmax(Cor& c);

        Cor** MC;

    private:
        string _path_abs;
        string _cmd;
        Camera _cam;
        float _c_max;
};

#endif