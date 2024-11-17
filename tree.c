#include "tree.h"

p_tree Create_abr(int value){
    p_tree tree;
    p_node noeud;
    noeud=(p_node*)malloc(sizeof( p_node));
    noeud->nb_sons=5;
    noeud->value=value;
    noeud->sons=(struct s_node*)malloc(sizeof(struct s_node)*5);
    tree->root=noeud;
    return tree;
}

p_node Create_node(int val, int nb_fils){
    p_node noeud;
    noeud=(p_node*)malloc(sizeof(p_node));
    noeud->nb_sons=nb_fils;
    noeud->value=val;
    noeud->sons=(struct s_node*)malloc(sizeof(struct s_node)*nb_fils);
    return noeud;

}  //Crée un noeud
