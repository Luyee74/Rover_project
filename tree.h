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
    t_move mvt ;
};
typedef  struct s_node t_node, *p_node;

struct s_tree{
    p_node root;
};
typedef struct s_tree t_tree, *p_tree;
typedef struct QueueNode {
    p_node node;       // Le nœud de l'arbre
    int level;         // Niveau du nœud dans l'arbre
    struct QueueNode* next;
} QueueNode;

// Structure pour la file
typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

p_tree Create_abr();  // créé un arbre N-aire
p_node Create_node(int , int,t_move);  //Crée un noeud
char * selection_move(int nb); // selectionner un mouvement aleatoirement
char ** list_move(t_move *lst_move,int N);
void remplissage_arb(t_map map,p_node root,t_move * ind_move,int nb_rep,t_localisation localisation);
t_move * suppr(t_move *,int val,int);

p_tree ARBRE_POSIBILITE(t_map map,t_move *ind_move,t_localisation position_rover,int nb_move);

p_node find_minimum(p_node node);
void find_path(p_node node, p_node *path, int path_length, int *minValue, p_node *minPath, int *minPathLength);
void  robot_avance(p_node* minPath,t_localisation *position_rover,int nb_move);
void robot_vers_base();

#endif
