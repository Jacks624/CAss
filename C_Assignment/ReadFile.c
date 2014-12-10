#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "Structs.h"
#include "LinkedLists.h"
#include "ReadFile.h"

char * getTitle(char *a, char *b) {
    char *tempString;
    tempString = malloc(strlen(a)+strlen(b)+1) ;
        strcat(tempString, a);
        strcat(tempString, b);
        return tempString;
 
}
void readFileObservers(char * location) {

    FILE * fp;
     char * directory = "/ceri/homes1/j/jas78/documents/Data/";


    fp = fopen(getTitle(directory, location), "r");
    char buffer[BUFSIZ];
    double longit = 0;
    double lat = 0;
    Time fot;
    int i;
    fscanf(fp, "%d %d %d %d %d %d", &fot.day, &fot.month, &fot.year, &fot.hours, &fot.minutes, &fot.seconds);
    printf("Last File Open Time: %d %d %d %d %d %d \n", fot.day, fot.month, fot.year, fot.hours, fot.minutes, fot.seconds);
    while (fscanf(fp, " %s %lf %lf", buffer, &lat, &longit) != EOF) {
        Observer *tempObserver = malloc(sizeof (Observer));
        strcpy(tempObserver->ID, buffer);
        tempObserver->latitude = lat;
        tempObserver->longitude = longit;
        addToList(tempObserver, getObserverRoot(), 'O');
        i++;

       // printf("Data from file:%s %lf %lf \n", buffer, lat, longit);
    }
    fclose(fp);
}

void readFileSighting(char * location) {
    char * directory = "/ceri/homes1/j/jas78/documents/Data/";
    FILE * fp;
         
  
    fp = fopen(getTitle(directory, location), "r");
    char buffer[BUFSIZ];
    char type;
    double bearing = 0;
    double range = 0;
    Time fot;
    int i;
    if(fp != NULL) {
    while (fscanf(fp, " %s %c %lf %lf", buffer, &type, &bearing, &range) != EOF) {
        Sighting *tempSighting = malloc(sizeof (Sighting));
        tempSighting->Type = type;
        strcpy(tempSighting->observerID, buffer);
        tempSighting->bearing = bearing;
        tempSighting->range = range;
        addToList(tempSighting, getObserverRoot(), 'S');
        i++;
    
       // printf("%s %c %lf %lf", buffer, type, bearing, range);
        }
    }else {
      printf("Can't open file");  
    }
    fclose(fp);

}

