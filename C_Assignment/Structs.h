#ifndef STRUCTS
#define STRUCTS
typedef struct {
    char ID[16];
    double latitude;
    double longitude;
} Observer;

typedef struct {
    int day;
    int month;
    int year;
    int hours;
    int minutes;
    int seconds;
}Time;

typedef struct {
    char observerID[16];
    char Type;
    double bearing;
    double range;
} Sighting;

typedef struct SightingNode SightingNode;

struct SightingNode {
    Sighting data;
    SightingNode *next;
};
typedef struct node node;
struct node {
    void * data;
    node *next;
};

#endif