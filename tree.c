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

char ** list_move(int nb_move){
    srand(time(NULL));
    t_move * lst_move= getRandomMoves(nb_move);
    char ** move=(char**)malloc(sizeof(char*)*nb_move);
    for (int i=0;i<nb_move;i++){
        move[i]= getMoveAsString(lst_move[i]);
        printf("%d == %s |",i,move[i]);


    }
    return move;

}

<<<<<<< HEAD
p_node find_minimum(p_node node) {
    if(node==NULL)
        return NULL;
    if (node->sons==0)
        return node;
    p_node minNode = NULL;
    int minValue = 1000000;
    for (int i=0 ; i<node->nb_sons ; i++){
        p_node min_in_tree = find_minimum(node->sons[i]);
        if (min_in_tree && min_in_tree->value < minValue) {
            minValue = min_in_tree->value;
            minNode =min_in_tree;
        }
    }
}
=======
void remplissage_arb(char ** list_move,)
>>>>>>> 76550be2b1e8e64b3aafffa37a457e051a82e961
