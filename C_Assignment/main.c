/* 
 * File:   main.c
 * Author: jack-s624
 *
 *§§ Created on 05 December 2014, 23:42
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Structs.h"
#include "LinkedLists.h"
#include "ReadFile.h"

char observerFile[255];
char cetaceanFile[255];

node *sightingRoot;
node *observerRoot;
node* getObserverRoot() {  
    return observerRoot;
}
node* getSightingRoot() {  
    return sightingRoot;
}

int main(int argc, char** argv) {
    observerRoot = malloc(sizeof(node));
    sightingRoot = malloc(sizeof(node));   
    
    printf("Please enter the location of the Observers\n");
    readFileObservers("observers_1.txt");
    printf("Please enter cetacean mammal file location\n");
     readFileSighting("sighting_1.txt");
    system("hostname");
    return (EXIT_SUCCESS);
}

