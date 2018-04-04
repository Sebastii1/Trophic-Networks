#include "grman/grman.h"
#include <iostream>
#include <fstream>
#include <stack>

#include "graph.h"

/**< Le code initial est celui donn� par Monsieur Fercoq. Les fonctions ajout�es ou modifi�es sont comment�es par nos soins
Pour la partie Allegro: il est possible que les fonctions utilis�es soient en C (et pas C++)
                        sources annexes: projet r�alis� au second semestre d'ING1 par S�bastien BRUNELLE, Zachary FLIMON et Petar MILETIC
 */


using namespace std;

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

    int menu(int choix)
{
    BITMAP* paint_menu;
    bool selectionne=false;
    switch(choix)
    {
        case 0:
           paint_menu=load_bitmap("menu.bmp", NULL);      //on utilise des images de menus (cr��s via Paint)
            selectionne=false;
            blit(paint_menu,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            while(!selectionne)
            {
                    if(mouse_b&1 && 84<mouse_y && mouse_y<206 && 38<mouse_x && mouse_x<797)     //le choix est d�termin� en fonction de l'endroit o� clique l'utilisateur
                    {
                        choix=1;
                        selectionne=true;
                    }
                    else if(mouse_b&1 && 300<mouse_y && mouse_y<416 && 38<mouse_x && mouse_x<797)
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

void creer_graphe(int choix, Graph g, BITMAP* buffer)
{
    BITMAP* barre;
    barre=load_bitmap("barre.bmp", NULL);
        blit(barre,buffer, 0,0,0,0, SCREEN_W, SCREEN_H);
        blit(buffer, screen, 0,0,0,0, SCREEN_W, SCREEN_H);

        if(mouse_b&1&&mouse_x<112&&mouse_y<35)
            choix=menu(0);
            ///on quitte le module de creation de graphe (retour au menu de base)

        if(mouse_b&1&&mouse_x>112&&mouse_x<256&&mouse_y<35)

            //  sauvegarde_graphe(g);
            //appel de la fonction permettant de sauvegarder le graphe actuel

        if(mouse_b&1&&mouse_x>257&&mouse_x<407&&mouse_y<35)

            //appel de la fonction permettant de charger les graphes sauvegard�s

        if(mouse_b&1&&mouse_x>408&&mouse_x<549&&mouse_y<35)

            //appel de la fonction permettant d'ajouter sommet, aretes etc

        if(mouse_b&1&&mouse_x>549&&mouse_x<720&&mouse_y<35)
            g.test_remove_edge(1);
            //appel de la fonction permettant de supprimer sommet, aretes etc
}

void sauvegarde_graphe(Graph g)
{
    g.m_ordre=7;
    vector <Edge> copie;
    ofstream fichier("base_donnee.txt", ios::out);
    for(int i=0; i<g.m_ordre; i++)
    {
        cout << g.m_edges[i].m_from <<endl;
        copie.emplace_back(g.m_edges[i]);
        fichier << copie[i].m_from;
        fichier << "  ";
        fichier<<copie[i].m_to;
        fichier <<endl;
        //copie.pop();
    }
}

int main()
{

    int choix=0;
    /// A appeler en 1er avant d'instancier des objets graphiques etc...
    grman::init();

    /**< Chargement des images et des BITMAP */
    BITMAP* buffer;
    buffer=create_bitmap(SCREEN_W, SCREEN_H);

    /// Le nom du r�pertoire o� se trouvent les images � charger
    grman::set_pictures_path("pics");

    /// Un exemple de graphe
    Graph g;
    g.make_example();
    install_keyboard();
    sauvegarde_graphe(g);

    /// Vous gardez la main sur la "boucle de jeu"
    /// ( contrairement � des frameworks plus avanc�s )
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
                    /// Il faut appeler les m�thodes d'update des objets qui comportent des widgets
                    g.update();

                    /// Mise � jour g�n�rale (clavier/souris/buffer etc...)
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
            creer_graphe(choix, g, buffer);
    }

    grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();


