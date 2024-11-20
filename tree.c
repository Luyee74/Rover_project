#include "tree.h"
static struct proba {

    int F_10;
};

p_tree Create_abr(int value){
    p_tree tree;
    p_node noeud;
    tree= (p_tree*)malloc(sizeof(p_tree));

    noeud= Create_node(value,5);
    tree->root=noeud;
    return tree;
}

p_node Create_node(int val, int nb_fils){
    p_node noeud;
    noeud=(p_node*)malloc(sizeof(p_node));
    noeud->value=val;
    noeud->nb_sons=nb_fils;
    noeud->sons=(struct s_node**)malloc(sizeof(struct s_node**)*nb_fils);
    return noeud;


}  //Crée un noeud
char * selection_move(int nb){    //tire aléatoirement un mouvement au sort
    int result;
    t_move nb_move;
    char* nom_move;
    result=rand()%nb;



    nb_move=result;
    nom_move= getMoveAsString(nb_move);

    return nom_move;
}

char ** list_move(int nb_move,int possibilité){
    srand(time(NULL));

    char ** move=(char**)malloc(sizeof(char*)*nb_move);
    for (int i=0;i<nb_move;i++){
        move[i]=selection_move(possibilité);
        printf("%d\n",i);


    }
    return move;

}