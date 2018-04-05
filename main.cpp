#include "grman/grman.h"
#include <iostream>
#include <fstream>
#include <stack>

#include "graph.h"

/**< Le code initial est celui donné par Monsieur Fercoq. Les fonctions ajoutées ou modifiées sont commentées par nos soins
Pour la partie Allegro: il est possible que les fonctions utilisées soient en C (et pas C++)
                        sources annexes: projet réalisé au second semestre d'ING1 par Sébastien BRUNELLE, Zachary FLIMON et Petar MILETIC
 */


using namespace std;

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

    int menu(int choix=0)   /**< Menu initial (choix entre créer un graphe et travailler avec un graphe déjà construit) */
{
    BITMAP* paint_menu;
    bool selectionne=false;

           paint_menu=load_bitmap("menu.bmp", NULL);      //on utilise des images de menus (créés via Paint)
            selectionne=false;
            blit(paint_menu,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            while(!selectionne)
            {
                    if(mouse_b&1 && 84<mouse_y && mouse_y<206 && 38<mouse_x && mouse_x<797)     //le choix est déterminé en fonction de l'endroit où clique l'utilisateur
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
        return choix;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


int menu_graphe(int choix=0)    /**< Menu du choix du graphe sur lequel on travaille */
{
    BITMAP* paint_menu;
            paint_menu=load_bitmap("graphes.bmp", NULL);
            bool selectionne=false;
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
            return choix;
}

void creer_graphe(int choix, Graph g, BITMAP* buffer)
{
    BITMAP* barre;
    barre=load_bitmap("barre.bmp", NULL);
        blit(barre,buffer, 0,0,0,0, SCREEN_W, SCREEN_H);
        blit(buffer, screen, 0,0,0,0, SCREEN_W, SCREEN_H);

        if(mouse_b&1 && mouse_x<112 && mouse_y<35)
            choix=menu(0);
            ///on quitte le module de creation de graphe (retour au menu de base)

        if(mouse_b&1 && mouse_x>86 && mouse_x<166 && mouse_y<35)

            //  sauvegarde_graphe(g);
            //appel de la fonction permettant de sauvegarder le graphe actuel

        if(mouse_b&1 && mouse_x>166 && mouse_x<254 && mouse_y<35)

            //appel de la fonction permettant de charger les graphes sauvegardés

        if(mouse_b&1 && mouse_x>255 && mouse_x<337 && mouse_y<35)

            //appel de la fonction permettant d'ajouter sommet, aretes etc

        if(mouse_b&1 && mouse_x>337 && mouse_x<459 && mouse_y<35)
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

bool connexite(string nomfichier)
{
    ifstream fichier(nomfichier, ios::in);
    int ordre;
    fichier >> ordre;
    int som=0;
    int verif=0;
    vector<bool> connexe;
    stack<int> pile;
    pile.push(som);

    for(int i=0; i<ordre; i++)
        connexe.push_back(false);


    int matrice_adj[ordre][ordre];
    for(int i=0; i<ordre; i++)
    {
        for(int j=0; j<ordre; j++)
            fichier >> matrice_adj[i][j];
    }

    while(!pile.empty())
   {
        som=pile.top();
        pile.pop();
        connexe[som]=true;
        for(int i=0; i<ordre; i++)
       {
            if(matrice_adj[som][i]==1 && connexe[i]==false)
            {
                    pile.push(i);
                    connexe[i]=true;
            }
       }
   }
    for(int i=0; i<connexe.size(); i++)
   {
       if(connexe[i]==false)
            verif++;
   }
   if(verif!=0)
    {
        cout << "Graphe non fortement connexe";
        return false;
    }
    else
    {
        cout << "Graphe fortement connexe";
        return true;
    }

}

void clique_bouton(int numero_graphe, string nomfichier)
{
    if(mouse_b&1 && mouse_x>86 && mouse_x<165 && mouse_y<50)
        cout << "A";
        //appel de la fonction permettant de sauver le graphe
    if(mouse_b&1 && mouse_x>165 && mouse_x<255 && mouse_y<50)
        cout << "B";
        //appel de la fonction permettant de charger un graphe
    if(mouse_b&1 && mouse_x>255 && mouse_x<338 && mouse_y<50)
        cout << "C";
        //appel de la fonction permettant d'ajouter un sommet
    if(mouse_b&1 && mouse_x>337 && mouse_x<459 && mouse_y<50)
        cout << "D";
        //appel de la fonction permettant de supprimer un sommet
    if(mouse_b&1 && mouse_x>459 && mouse_x<576 && mouse_y<50)
        connexite(nomfichier);
        //appel de la fonction permettant de verifier si un graphe est fortement connexe ou non
}

int main()
{
    int choix_graphe=0;
    int choix=0;
    /// A appeler en 1er avant d'instancier des objets graphiques etc...
    grman::init();

    /**< Chargement des images et des BITMAP */
    BITMAP* buffer;
    buffer=create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* barre;
    barre=load_bitmap("barre.bmp", NULL);

    /// Le nom du répertoire où se trouvent les images à charger
    grman::set_pictures_path("pics");

    /// Un exemple de graphe
    Graph g;
    g.make_example();
    install_keyboard();
    sauvegarde_graphe(g);

    /// Vous gardez la main sur la "boucle de jeu"
    /// ( contrairement à des frameworks plus avancés )
    while ( !key[KEY_ESC] )
    {
        clear(buffer);
        choix=menu(choix);
        if(choix==1)
        {
            choix_graphe=menu_graphe(choix);

            if(choix_graphe==1)
            {
                while(!(mouse_b&1&&mouse_x<50&&mouse_y<50))
                {
                    /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
                    g.update();

                    /// Mise à jour générale (clavier/souris/buffer etc...)
                    grman::mettre_a_jour();
                    clique_bouton(1, "matrice1.txt");
                }
                choix_graphe=menu_graphe(choix);

            }
                //afficher graphe 1
            if(choix_graphe==2)
            {
                while(!(mouse_b&1&&mouse_x<50&&mouse_y<50))
                {
                    cout << "2";
                    ///clique_bouton(2, "matrice2.txt");
                //afficher graphe 2
                }
            }
            if(choix_graphe==3)
            {
                while(!(mouse_b&1&&mouse_x<50&&mouse_y<50))
                {
                    cout << "3";
                    ///clique_bouton(3, "matrice3.txt");
                    //afficher graphe 3
                }
            }
        }
        if(choix==2)
            creer_graphe(choix, g, buffer);
    }

    grman::fermer_allegro();



    return 0;
}
END_OF_MAIN();


