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
    return minNode;
}



void find_path(p_node node, int *path, int path_length, int *minValue, int *minPath, int *minPathLength) {
    if (node == NULL)
        return;
    path[path_length] = node->value;
    path_length++;
    if (node->nb_sons == 0) {
        if (node->value < *minValue) {
            *minValue = node->value;
            for (int i = 0; i < path_length; i++) {
                minPath[i] = path[i];
            }
            *minPathLength = path_length;
        }
        return;
    }
    for (int i = 0; i < node->nb_sons; i++) {
        find_path(node->sons[i], path, path_length, minValue, minPath, minPathLength);
    }
}






void remplissage_arb(t_map map,p_tree tree,char ** list_move,int nb_rep,t_localisation localisation) {
    p_node noeud =Create_node(map.costs[localisation.pos.y][localisation.pos.x],nb_rep);





}



