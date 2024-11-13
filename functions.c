#include "functions.h"
#include <stdio.h>

t_node Create_abr(int value){
    t_node noeud;
    noeud=(t_node*)malloc(sizeof(t_node));
    noeud.value=value;
    noeud.nb_sons=7;
    noeud.sons=(t_node*)malloc(sizeof(t_node)*noeud.nb_sons);
    return noeud;





}