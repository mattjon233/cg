#include "Render.h"

void Render::tirar_fotografia(Cenario world, Luzes luzes, Cor background, string projecao) {
    auto largura = _cam.largura_imagem();
    auto altura = _cam.altura_imagem();
    auto janela_pts = _cam.janela_pontos();
    // auto origem_cam = _cam.origem();
    // auto ki_cam = _cam.eixo_k()*(-1);

    float Px, Py, Pz = janela_pts.z();
    
    auto x_min = -janela_pts.x();
    auto x_max = janela_pts.x();
    auto delta_x = (x_max-x_min)/largura;
    
    auto y_min = -janela_pts.y();
    auto y_max = janela_pts.y();
    auto delta_y = (y_max-y_min)/altura;

    MC = alocar(altura, largura);

    // auto MC = alocar(altura, largura);

    background = background * (1.0/255.0);
    _c_max = -1;

    for (int h = 0; h < altura; ++h)
    {
        Py = y_min + delta_y/2 + h*delta_y;
        for (int w = 0; w < largura; ++w)
        {
            PontoColisao ptcol;
            Raio raio;

            Px = x_min + delta_x/2 + w*delta_x;
            
            if (strcmp(projecao.c_str(), "perspectiva") == 0)
                raio = criar_raio_op(Ponto(0, 0, 0, 1), Ponto(Px, Py, Pz, 1));
            else 
                raio = criar_raio_od(Ponto(Px, Py, Pz, 1), Vetor(0, 0, -1)); // _cam.eixo_k()*(-1) OBS: projecao ortogonal com defeito
            
            if(world.intersectar(raio, 0, INFINITO, ptcol)) {
                luzes.iluminar(world, ptcol);
                MC[h][w] = ptcol.cor;
            }
            else {
                MC[h][w] = background;
            }
            obter_cmax(MC[h][w]);
        }
    }

    ofstream arq(_path_abs);

    conf_arquivo(arq, largura, altura);

    for (int j = altura-1; j >= 0; --j) for (int i = 0; i < largura; ++i) escrever_arquivo(arq, MC[j][i]);

    arq.close();
    
    executar_arquivo(_cmd);
}

void Render::escrever_arquivo(ofstream& arq, Cor p) {
    if (_c_max <= 1) arq << p.x() << ' ' << p.y() << ' ' << p.z() << '\n';
    else arq << static_cast<int>( fabs(p.x()/_c_max*255) ) << ' ' << static_cast<int>( fabs(p.y()/_c_max*255) ) << ' ' << static_cast<int>( fabs(p.z()/_c_max*255) ) << '\n';
}

void Render::conf_arquivo(ofstream& arq, int largura, int altura) {
    arq << "P3\n" << largura << ' ' << altura << "\n255\n";
}

void Render::executar_arquivo(string cmd) {
    cout << "system(\""<< cmd.c_str() << "\");" << endl;
    system(cmd.c_str());
}

void Render::obter_cmax(Cor& c) {
    // cout << c << '\n';
    if(_c_max < c.x()) _c_max = c.x();
    if(_c_max < c.y()) _c_max = c.y();
    if(_c_max < c.z()) _c_max = c.z();
    // cout << _c_max << '\n';
}