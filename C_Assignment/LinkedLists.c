
#include <stdlib.h>
#include <stdio.h>
#include "Structs.h"
#include "LinkedLists.h"
void addToList(void * toAdd, node *root, char type) {
    node *toMove;
    toMove = root;
    if(toMove != 0) {
        while(toMove->next != 0) {
            toMove = toMove->next;   
        }
    }//go to end of the list
    
    toMove->next = malloc(sizeof(node));//add new node at the end
    toMove->next->data = toAdd;//assign it to the variable to add
    //printf("%s", toAdd.ID);
    if(type == 'O') {
    Observer *s =  ((Observer*)(toMove->next->data));
    printf("In List: %s %lf %lf \n", s->ID, s->latitude, s->longitude);
    } else if (type == 'S') {
         Sighting *s =  ((Sighting*)(toMove->next->data));
    printf("%s %lf %lf %c \n", s->observerID, s->bearing, s->range, s->Type);
    }
}
node * get(int x, node *root) {
    node *toMove;
    toMove = root;
    int i = 0;
    if(toMove != 0) {
        for(i; i > x; i++) {
            if(toMove->next != 0) {
            toMove = toMove->next; 
            }
        }
    }
    return toMove;
}