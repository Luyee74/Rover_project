#include <stdio.h>
#include "map.h"
#include "loc.h"
#include "tree.h"
#include "time.h"

// Structure pour passer plusieurs arguments à find_path
typedef struct {
    p_node node;
    int *path;
    int path_length;
    int *minValue;
    int *minPath;
    int *minPathLength;
} find_path_args;

// Wrapper pour find_minimum
p_node wrapper_find_minimum(p_node node) {
    return find_minimum(node);
}

// Wrapper pour find_path
void wrapper_find_path(void *args) {
    find_path_args *fp_args = (find_path_args *)args;
    find_path(fp_args->node, fp_args->path, fp_args->path_length, fp_args->minValue, fp_args->minPath, fp_args->minPathLength);
}

// Fonction pour mesurer le temps d'exécution
void measure_time(void (*func)(void *), void *arg) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();  // Début du chronométrage
    func(arg);        // Appel de la fonction à tester
    end = clock();    // Fin du chronométrage

    // Calcul du temps en secondes
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);
}

int main() {
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

    // Initialisation de la localisation du rover
    t_localisation position_rover = loc_init(5, 6, NORTH);

    // Tirage aléatoire des mouvements
    int nb_move = 9;
    t_move *ind_move = getRandomMoves(nb_move);  // Tire au sort des mouvements

<<<<<<< Updated upstream
    // Création de l'arbre
    p_tree tree = ARBRE_POSIBILITE(map, ind_move, position_rover, nb_move);

    // Mesurer le temps pour find_minimum
    printf("Starting measurement for find_minimum...\n");
    measure_time((void(*)(void*)) wrapper_find_minimum, tree->root);

    // Initialisation des variables pour find_path
    int path[100], minValue = 1000000, minPath[100], minPathLength = 0;
    find_path_args fp_args = {
            tree->root,
            path,
            0,
            &minValue,
            minPath,
            &minPathLength
    };

    // Mesurer le temps pour find_path
    printf("Starting measurement for find_path...\n");
    measure_time(wrapper_find_path, &fp_args);

    // Afficher les résultats de find_path
    printf("Minimum value found: %d\n", minValue);
    printf("Minimum path length: %d\n", minPathLength);
    printf("Minimum path: ");
    for (int i = 0; i < minPathLength; i++) {
        printf("%d ", minPath[i]);
    }
    printf("\n");

    return 0;
=======
p_node temp=tree->root;
int i=0;
while (temp!=NULL){
    printf("%d a %d fils\n",i,temp->nb_sons);
    temp=temp->sons[0];
    i++;


}
        return 0;
>>>>>>> Stashed changes
}
