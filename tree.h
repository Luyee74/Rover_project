#ifndef UNTITLED1_TREE_H
#define UNTITLED1_TREE_H
#include <stdlib.h>
#include <time.h>
#include "moves.h"
#include <stdio.h>
#include "map.h"
typedef struct s_cell{
    int value; //valeur de la cellule
    int next; //adresse de la cellule suivante
}t_cell;

typedef struct s_ht_list
{
    t_cell *head;   	// adresse de la première cellule
    t_cell *tail;	// adresse de la dernière cellule
} t_ht_list;


struct s_node{
    int value; //valeur de la feuille
    int nb_sons; //nombre de fils (5 car 5 déplacements)
    struct s_node **sons; //adresses des fils
};
typedef  struct s_node t_node, *p_node;

struct t_tree{
    p_node root;
};
typedef struct t_tree *p_tree;

p_tree Create_abr(int );  // créé un arbre N-aire
p_node Create_node(int , int);  //Crée un noeud
char * selection_move(int nb); // selectionner un mouvement aleatoirement
char ** list_move(int nb_move);
void remplissage_arb(t_map map,p_tree tree,char ** list_move,int nb_rep,t_localisation localisation);






#endif //UNTITLED1_TREE_H
