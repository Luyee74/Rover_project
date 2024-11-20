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



/*
void find_path(p_node node, int *path, int path_length, int *minValue, int *minPath, int *minPathLength){
    if(node==NULL)
        return NULL;
    if (node->nb_sons == 0);
        *minValue = node->value;
    for (int i=0, i<path_lenght, i++){
        minpath[i]=path[i]
    }


}
*/


t_move * suppr(t_move * ind_move,int val,int nb_val){
    t_move * new=(t_move*)malloc(sizeof(t_move)*nb_val);
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







p_node remplissage_arb(t_map map,p_node root,t_move * ind_move,int nb_rep,t_localisation localisation) {
    p_node noeud =Create_node(returne_val_pos(map,localisation),nb_rep); // Créer un noeud avec la valeur de la pos actuel

    if (ind_move[0]==NULL){ // Si il n'a plus de mouvement
        return noeud; // il renvoie la feuille sur laquelle il est allé

    }

    else {
        for (int i=0;i<nb_rep;i++){         //Pour chaque mouvement qu'il doit faire
        t_localisation  pos_move;
        t_move * new_ind;
        new_ind= suppr(ind_move,ind_move[i],nb_rep);     // on supprime le mouvement qu'il vient de faire
        pos_move=updateLocalisation(localisation, ind_move[i]);      // on le fait avancé
        root->sons[i]= remplissage_arb(map,noeud,new_ind,nb_rep-1,pos_move);  //on retourne récursivement les feuilles jusqu'à ce qu'il n'y ai plus de mouvement


    }}





}



