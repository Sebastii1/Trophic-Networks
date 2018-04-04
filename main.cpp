#include "grman/grman.h"
#include <iostream>
#include <fstream>

#include "graph.h"

using namespace std;

void sauvegarde_graphe(Graph g)
{
    ofstream fichier("base_donnee.txt", ios::out);
    for(int i=0; i<g.m_ordre; i++)
        fichier <<
}

    int menu(int choix)
{
    BITMAP* paint_menu;
    bool selectionne=false;
    switch(choix)
    {
        case 0:
           paint_menu=load_bitmap("menu.bmp", NULL);
            selectionne=false;
            blit(paint_menu,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            while(!selectionne)
            {
                    if(mouse_b&1 && 84<mouse_y && mouse_y<206 && 38<mouse_x && mouse_x<797)
                    {
                        choix=1;
                        selectionne=true;
                    }
                    else if(mouse_b&1 && 356<mouse_y && mouse_y<416 && 38<mouse_x && mouse_x<797)
                    {
                        choix=2;
                        selectionne=true;
                    }
            }
            break;

        case 1:
            paint_menu=load_bitmap("graphes.bmp", NULL);
            selectionne=false;
            while(!selectionne)
            {
                blit(paint_menu,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                if(mouse_b&1 && mouse_x<50 && mouse_y<50)
                    choix=menu(0);
                if(mouse_b&1 && 38<mouse_y && mouse_y<158 && 54<mouse_x && mouse_x<790)
                {
                    choix=1;
                    selectionne=true;
                }
                else if(mouse_b&1 && 220<mouse_y && mouse_y<343 && 54<mouse_x && mouse_x<790)
                {
                    choix=2;
                    selectionne=true;
                }
                else if(mouse_b&1 && 400<mouse_y && mouse_y <520 && 54<mouse_x && mouse_x<790)
                {
                    choix=3;
                    selectionne=true;
                }
            }
            break;


    }
        return choix;
}

int main()
{

    int choix=0;
    /// A appeler en 1er avant d'instancier des objets graphiques etc...
    grman::init();

    /// Le nom du répertoire où se trouvent les images à charger
    grman::set_pictures_path("pics");
    BITMAP* barre;
    barre=load_bitmap("barre.bmp", NULL);
    BITMAP* buffer;
    buffer=create_bitmap(SCREEN_W, SCREEN_H);


    /// Un exemple de graphe
    Graph g;
    g.make_example();


    /// Vous gardez la main sur la "boucle de jeu"
    /// ( contrairement à des frameworks plus avancés )
    while ( !key[KEY_ESC] )
    {
        clear(buffer);
        choix=menu(choix);
        if(choix==1)
        {
            choix=menu(1);
            if(choix==1)
            {
                while(!(mouse_b&1&&mouse_x<50&&mouse_y<50))
                {
                    /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
                    g.update();

                    /// Mise à jour générale (clavier/souris/buffer etc...)
                    grman::mettre_a_jour();
                }
            }
                //afficher graphe 1
            if(choix==2)
                //afficher graphe 2
            if(choix==3)
                {}//afficher graphe 3
        }
        if(choix==2)
        {
            blit(barre, buffer, 0,0,0,0, SCREEN_W, SCREEN_H);
            blit(buffer, screen, 0,0,0,0, SCREEN_W, SCREEN_H);

            if(mouse_b&1&&mouse_x<112&&mouse_y<35)
                choix=menu(0);
                ///on quitte le module de creation de graphe (retour au menu de base)

            if(mouse_b&1&&mouse_x>112&&mouse_x<256&&mouse_y<35)
              //  sauvegarde_graphe(g);
                //appel de la fonction permettant de sauvegarder le graphe actuel

            if(mouse_b&1&&mouse_x>257&&mouse_x<407&&mouse_y<35)
                //appel de la fonction permettant de charger les graphes sauvegardés

            if(mouse_b&1&&mouse_x>408&&mouse_x<549&&mouse_y<35)
                //appel de la fonction permettant d'ajouter sommet, aretes etc

            if(mouse_b&1&&mouse_x>549&&mouse_x<720&&mouse_y<35)
                {}//appel de la fonction permettant de supprimer sommet, aretes etc
        }
    }

    grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();


