#include "tree.h"
static struct proba {

    int F_10;
};

p_tree Create_abr(int val, int fils){
    p_tree tree;
    p_node noeud;
    tree= (p_tree)malloc(sizeof(t_tree));
    tree->root=(p_node)malloc(sizeof(t_node ));
    tree->root= Create_node(val,fils,-1);

    return tree;
}

p_node Create_node(int val, int nb_fils,t_move mvt){
    p_node noeud;
    noeud=(p_node)malloc(sizeof(t_node));
    noeud->value=val;
    noeud->nb_sons=nb_fils;
    noeud->sons=(struct s_node**)malloc(sizeof(struct s_node**)*nb_fils);
    noeud->mvt=mvt;

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
    if (nb_rep==0 || nb_rep==4){
        root->sons=NULL;
        return;
    }

    else{
        for(int i=0;i<nb_rep;i++){
            t_move * new_list_move= suppr(ind_move,ind_move[i],nb_rep);
            t_localisation after_move= move(localisation,ind_move[i]);


            if (isValidLocalisation(after_move.pos,map.x_max,map.y_max)==1){
                p_node noeud;

                if (nb_rep==5){
                noeud = Create_node(returne_val_pos(map,after_move),0,ind_move[i]);}
                else {      noeud = Create_node(returne_val_pos(map,after_move),nb_rep-1,ind_move[i]);


                    }
                root->sons[i]=noeud;
                remplissage_arb(map,root->sons[i],new_list_move,nb_rep-1,after_move);

            }




            else{
                root->sons[i]= Create_node(10000,0,ind_move[i]);
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

void find_path(p_node node, struct s_node **path, int path_length, int  *minValue, struct s_node **minPath, int *minPathLength) {

    if (node == NULL)
        return;
    path[path_length] = node;
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

void  robot_avance(p_node* minPath,t_localisation *position_rover,int nb_move){
    for (int i=1;i<nb_move+1;i++) {
        char *lst_move[nb_move];
        lst_move[i]= getMoveAsString(minPath[i]->mvt);
        *position_rover=updateLocalisation(*position_rover, minPath[i]->mvt);

    }



}

void robot_vers_base(){


    t_map map = createMapFromFile("../maps/example1.map");
    printf("Map created with dimensions %d x %d\n", map.y_max, map.x_max);

    // Affichage des sols de la carte
    for (int i = 0; i < map.y_max; i++) {
        for (int j = 0; j < map.x_max; j++) {
            printf("%d ", map.soils[i][j]);
        }
        printf("\n");
    }

    // Affichage des coûts
    for (int i = 0; i < map.y_max; i++) {
        for (int j = 0; j < map.x_max; j++) {
            printf("%-5d ", map.costs[i][j]);
        }
        printf("\n");
    }
    int val;
    do {
    t_localisation position_rover = loc_init(5, 6, NORTH);
    int nb_move = 9;
        for (int i=0;i<5;i++){
        // Initialisation de la localisation du rover

        // Tirage aléatoire des mouvements

        t_move *ind_move = getRandomMoves(nb_move);  // Tire au sort des mouvements

        // Création de l'arbre
        p_tree tree = ARBRE_POSIBILITE(map, ind_move, position_rover, nb_move);
        int minValue = 1000000, minPathLength = 0;
        struct s_node **path = (struct s_node **) malloc(sizeof(struct s_node **) * 5), **minPath = (struct s_node **) malloc(sizeof(struct s_node **) * 5);

        find_path(tree->root,path,0,&minValue,minPath,&minPathLength);
        printf("Liste de mouvement minimum a partir de la position %d %d\n",position_rover.pos.x,position_rover.pos.y);
        for (int j=1;j<6;j++){
            printf("Le mouvement %s to a %d \n",getMoveAsString(minPath[j]->mvt),minPath[j]->value);

        }
        robot_avance(minPath, &position_rover, 5);

    }
        if(returne_val_pos(map,position_rover)==0){
            printf("Rover est arrive a la base\n");
            val=0;
        }
        else{
            printf("Rover n'a pas reussi a rentrer a la base\n");
            printf("Entrer le nombre 1 pour reessayer\n");
            val= scanf("%d",&val);
        }}while(val==1);

}