#include <stdio.h>
#include "map.h"
#include "loc.h"
#include "tree.h"
#include "time.h"

// Structure pour passer plusieurs arguments à find_path
typedef struct {
    p_node node;
    struct s_node **path;
    int path_length;
    int *minValue;
    struct s_node**minPath;
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

    robot_vers_base();


        return 0;

}
