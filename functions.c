#include "functions.h"

t_node Create_abr(int value){
    t_node* noeud;
    noeud=(t_node*)malloc(sizeof(t_node));
    noeud->nb_sons=7;
    noeud->value=value;
    noeud->sons=(t_node*)malloc(sizeof(t_node)*7);

    return *noeud;
}