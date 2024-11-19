#include "tree.h"

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
