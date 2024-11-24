#include "tree.h"
static struct proba {

    int F_10;
};

p_tree Create_abr(int val, int fils){
    p_tree tree;
    p_node noeud;
    tree= (p_tree)malloc(sizeof(t_tree));
    tree->root=(p_node)malloc(sizeof(t_node ));
    tree->root= Create_node(val,fils);

    return tree;
}

p_node Create_node(int val, int nb_fils){
    p_node noeud;
    noeud=(p_node)malloc(sizeof(t_node));
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

char ** list_move(t_move *lst_move,int N){

    char ** move=(char**)malloc(sizeof(char*)*N);
    for (int i=0;i<N;i++){
        move[i]= getMoveAsString(lst_move[i]);


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





t_move * suppr(t_move * ind_move,int val,int nb_val){
    t_move * new=(t_move*)malloc(sizeof(t_move)*(nb_val-1));
    ;
    int j=0,ind;
    for(int i=0;i<nb_val;i++){
        ind=ind_move[i];
        if (ind==val){
            j=i;
            break;
        }
        else{
            new[i]=ind_move[i];
        }
    }

    for(j;j<nb_val-1;j++){
        new[j]=ind_move[j+1];
    }return new;
}







void remplissage_arb(t_map map,p_node root,t_move * ind_move,int nb_rep,t_localisation localisation) {
    if (nb_rep==0){
        root->sons=NULL;
        return;
    }

    else{
        for(int i=0;i<nb_rep;i++){
            t_move * new_list_move= suppr(ind_move,ind_move[i],nb_rep);
            t_localisation after_move= move(localisation,ind_move[i]);


            if (isValidLocalisation(after_move.pos,map.x_max,map.y_max)==1){
                p_node neoud =Create_node(returne_val_pos(map,after_move),nb_rep-1);
                root->sons[i]=neoud;
                remplissage_arb(map,root->sons[i],new_list_move,nb_rep-1,after_move);

            }

            else{
                root->sons[i]= Create_node(10000,1);
                root->sons[i]->sons=NULL;
            }
        }}

}


p_tree ARBRE_POSIBILITE(t_map map,t_move *ind_move,t_localisation position_rover,int nb_move){

    position_rover = loc_init(5, 6, NORTH);
    p_tree tree=Create_abr(returne_val_pos(map,position_rover),nb_move);




    t_move * test=(t_move*)malloc(sizeof(t_move*)*5);
    test[0]=0;test[1]=4;test[2]=5;test[3]=1;test[4]=6;



    remplissage_arb(map, tree->root,ind_move,nb_move, position_rover) ;
    return tree;
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