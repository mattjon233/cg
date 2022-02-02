#include <stdio.h>
#include <iostream>
#include <fstream>

#include "Base.h"
#include "Camera.h"
#include "Render.h"
#include "Objeto.h"
#include "Esfera.h"
#include "Cone.h"
#include "Cilindro.h"
#include "Malha.h"
#include "Luzes.h"
#include "Luz.h"
#include "LuzAmbiente.h"
#include "LuzDirecional.h"
#include "LuzPontual.h"
#include "LuzSpot.h"
#include "Cluster.h"

//includes do GL
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <GL/gl.h>

void construir_chao(Cenario &world, string obj) {
    shared_ptr<Malha> chao = make_shared<Malha>(obj, Cor(90,119,47));
    chao->atualizar_pontos(matriz_escala(Vetor(50, 0.2, 15)));
    chao->atualizar_pontos(matriz_translacao(Ponto(10.0, 0.0, -25.0)));

    world.add(chao);

}

void consturir_nave(Cenario &world) {
    shared_ptr<Cone> nave = make_shared<Cone>(Ponto(9.0, 12.0, -20.0, 1), 5, Vetor(0.2, 1, 0), 4.0, Cor(154,154,154));    
    shared_ptr<Cone> nave2 = make_shared<Cone>(Ponto(9.0, 11.8, -20.0, 1), 3.8, Vetor(0.2, 1, 0), 4.0, Cor(192,192,192));    

    world.add(nave);
    world.add(nave2);

}

void construir_boneco_de_neve(Cenario &world) {
    shared_ptr<Esfera> baixo = make_shared<Esfera>(Ponto(8.8, 3.5, -20.0, 1), 1.2, Cor(255,255,255));
    shared_ptr<Esfera> cima = make_shared<Esfera>(Ponto(9.2, 5.5, -20.0, 1), 1.2, Cor(255,255,255));
    shared_ptr<Esfera> olho_esq = make_shared<Esfera>(Ponto(8.3, 5.9, -19.2, 1), 0.2, Cor(0,0,0));
    shared_ptr<Esfera> olho_dir = make_shared<Esfera>(Ponto(9.0, 5.6, -18.7, 1), 0.2, Cor(0,0,0));
    // segundo ponto do cone = achatação (quanto maior mais achatado)
    shared_ptr<Cone> chapeu = make_shared<Cone>(Ponto(8.9, 5.74, -19.2, 1), 1.3, Vetor(0.31, 1, -0.1), 0.75, Cor(255,165,0));    

    world.add(baixo);
    world.add(cima);
    world.add(olho_esq);
    world.add(olho_dir);
    world.add(chapeu);
}

void construir_arvore_natal(Cenario &world, string obj, string obj2) {
    shared_ptr<Malha> copa = make_shared<Malha>(obj, Cor(34,139,34));
    copa->atualizar_pontos(matriz_escala(Vetor(2.0, 2.0, 2.0)));
    copa->atualizar_pontos(matriz_translacao(Ponto(-9.0, 1.0, -20.0)));
    world.add(copa);

    shared_ptr<Esfera> bolinha_vermelha = make_shared<Esfera>(Ponto(-7.0, 7.0, -18.5, 1), 0.3, Cor(249,25,14));
    shared_ptr<Esfera> bolinha_azul = make_shared<Esfera>(Ponto(-7.5, 4.0, -17.5, 1), 0.3, Cor(0,0,255));
    shared_ptr<Esfera> bolinha_amarela = make_shared<Esfera>(Ponto(-8.5, 4.5, -17.35, 1), 0.3, Cor(254,254,90));
    shared_ptr<Esfera> bolinha_amarela_2 = make_shared<Esfera>(Ponto(-7.5, 7.0, -17.5, 1), 0.3, Cor(254,254,90));
    shared_ptr<Esfera> bolinha_vermelha_2 = make_shared<Esfera>(Ponto(-10.5, 4.0, -17.5, 1), 0.3, Cor(249,25,14));
    shared_ptr<Esfera> bolinha_azul_2 = make_shared<Esfera>(Ponto(-8.5, 8.5, -18.5, 1), 0.3, Cor(0,0,255));
    shared_ptr<Esfera> bolinha_amarela_3 = make_shared<Esfera>(Ponto(-8.5, 10.5, -18.5, 1), 0.3, Cor(254,254,90));
    world.add(bolinha_vermelha);
    world.add(bolinha_azul);
    world.add(bolinha_amarela);
    world.add(bolinha_vermelha_2);
    world.add(bolinha_azul_2);
    world.add(bolinha_amarela_2);
    world.add(bolinha_amarela_3);

    shared_ptr<Malha> estrela = make_shared<Malha>(obj2, Cor(94,75,0));
    estrela->atualizar_pontos(matriz_escala(Vetor(0.2, 0.2, 0.2)));
    estrela->atualizar_pontos(matriz_translacao(Ponto(-9.0, 13.2, -20.0)));
    world.add(estrela);

    shared_ptr<Cilindro> tronco = make_shared<Cilindro>(Ponto(-9.0, 0.0, -20.0, 1), 0.8, Vetor(0, 1, 0), 4.0, Cor(139,69,19));    
    world.add(tronco);

}

void construir_arvore(Cenario &world) {
    shared_ptr<Cilindro> tronco = make_shared<Cilindro>(Ponto(-1.5, 0.0, -20.0, 1), 0.8, Vetor(0, 1, 0), 4.0, Cor(139,69,19));
    shared_ptr<Esfera> folhas = make_shared<Esfera>(Ponto(-1.5, 5.0, -20.0, 1), 2.0, Cor(34,139,34));

    world.add(tronco);
    world.add(folhas);

}

void construir_arvore_2(Cenario &world) {
    shared_ptr<Cilindro> tronco = make_shared<Cilindro>(Ponto(-17.5, 0.0, -24.0, 1), 0.8, Vetor(0, 1, 0), 7.0, Cor(139,69,19));
    shared_ptr<Esfera> folhas = make_shared<Esfera>(Ponto(-17.5, 9.0, -24.0, 1), 3.0, Cor(34,139,34));

    world.add(tronco);
    world.add(folhas);

}

//dimensoes da tela, adaptar com a quantidade de pixels da imagem usada
float windowWidth  = 400.0;
float windowHeight = 400.0;
Cor *canvas;

void display() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawPixels(windowWidth, windowHeight, GL_RGBA, GL_FLOAT, (float*)canvas);
    glutSwapBuffers();
    glutPostRedisplay();
}

// 0,0 = arvore 3d, chao 2d, perto (ortogonal)
// 1,0 = cenario 3d frente (perspectiva)
// 1,1 = cenario 3d lateral 
int tipo = 1;
int girar = 0;

int main(int argc, char **argv) {
    /* configuracao de arquivo */
    string path_abs = "img/img_"+data_atual()+".ppm";
    string cmd = "eog "+path_abs;

    // -------------------------------------- CÂMERA -------------------------------------- //

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition((1920 / 2) - windowWidth / 2, (1080 / 2) - (windowHeight + 50) / 2);
    glutCreateWindow("Trabalho Final - CG");
    glutDisplayFunc(display);

    Ponto janela_pts;
    // y,x = mexer no janela pts = achata a visão 
    if (tipo == 1) janela_pts = Ponto(0.75, 0.75, -0.75, 1);
    else  janela_pts = Ponto(25.0, 25.0, -1.0, 1);

    // caso mexer y = mexer y no lookat (iguais) e y no view up (+1) e MOVE A CAMERA

    // eixo x = rotaciona sobre o proprio eixo
    // eixo z = afasta (positivo) (0) ou inverte e aproxima (negativo) a câmera do cenário (-50) 
    // eixo y = subir camera para y=4 para os objetos ficarem em (0,0)
    // origem

    // no eixo x, inclina a câmera 
    // no eixo y, zoom
    // lookat

    // no eixo x, rotaciona a camera
    // no eixo y, zoom
    // no eixo z = sobre o proprio eixo (nao muda nada)
    // viewup

    Ponto origem(0, 4, 0, 1);
    Ponto lookat(0, 4, -1, 1);
    Ponto viewup(0, 5, 3, 1);


    Camera cam(origem, lookat, viewup, janela_pts, windowWidth, windowHeight);

    // -------------------------------------- CRIAÇÃO DO CENÁRIO -------------------------------------- //

    Cenario world;
    consturir_nave(world);
    construir_chao(world, "obj/cubo.obj");
    construir_arvore_natal(world, "obj/copa.obj", "obj/star.obj");
    construir_boneco_de_neve(world);
    construir_arvore(world);
    construir_arvore_2(world);
    shared_ptr<Esfera> lua = make_shared<Esfera>(Ponto(-150.0, 250, -600, 1), 50, Cor(253,253,150));
    world.add(lua);

    // -------------------------------------- LUZES -------------------------------------- //

    /* adicionando as luzes */
    Luzes luzes;

    // luz da estrela (sol) abaixo do horizonte
    luzes.add(make_shared<LuzDirecional>(Vetor(0, 1, 1), Cor(0.04, 0.04, 0.04)));
    
    // luz da lua
    luzes.add(make_shared<LuzAmbiente>(Cor(0, 0, 0)));
    luzes.add(make_shared<LuzPontual>(Ponto(-150, 250, -200, 1), Cor(0.1, 0.1, 0.1)));

    // luz da nave et
    luzes.add(make_shared<LuzSpot>(Ponto(9, 10, -20.0, 1), Vetor(0, -1, 0), 0.001, 45, Cor(0.25, 0.25, 0.25)));

    if (girar == 1) {
        world.atualizar_pontos(matriz_rotacao(-45, 'y'));
        world.atualizar_pontos(matriz_translacao(Ponto(-15, 0, -5, 1)));
        luzes.atualizar_posicao(matriz_rotacao(-45, 'y'));
        luzes.atualizar_posicao(matriz_translacao(Ponto(-15, 0, -5, 1)));
    }     

    /* atualizando de coord de mundo para coor de camera */
    luzes.atualizar_posicao(cam.coord_MpC());
    world.atualizar_pontos(cam.coord_MpC());

    // dia ou noite (255,255,255) ou (1,1,1)
    // noite = sem sombra
    Cor bg(0, 0, 0);

    Render render(path_abs, cmd, cam);
    if (tipo == 1) render.tirar_fotografia(world, luzes, bg, "perspectiva");
    else render.tirar_fotografia(world, luzes, bg, "ortografica");

    // cria o framebuffer do opengl para alocar os pixels
    canvas = (Cor*)malloc(sizeof(Cor)*windowWidth*windowHeight);

    // aloca os pixels
    for(int i = 0; i < windowWidth; i++)
    {
        for(int j = 0; j < windowHeight; j++)
        {
            canvas[int(j+(i*windowHeight))] = render.MC[i][j];

        }
    }

    glutMainLoop();

    return 0;
}