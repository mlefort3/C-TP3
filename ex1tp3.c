#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxi 100
#define OFFSET(x,Y)((unsigned long)&(Y.x)-(unsigned long)&(Y))

typedef struct Point Point;
struct Point {
   int  id;
   float x;
   float y;
};

typedef struct Point2 Point2;
struct Point2 {
    short  id;
    float x;
    float y;
};

typedef enum Option Option;
enum Option {XX = 1,YY,ORIG};
void printPoint(struct Point point) {
    printf("\n%d(%f,%f)\n", point.id, point.x, point.y);
}

//Option 1 : XX, Option 2 : YY, Option 3 : ORIG

int symetrique(struct Point *point, Option option) {
    float x = point -> x;
    float y = point -> y;
    if (option==XX) {
        point -> y = -y;
        return 1;
    }
    if (option==YY) {
        point -> x = -x;
        return 1;
    }
    if (option==ORIG) {
        point -> x = -x;
        point -> y = -y;
        return 1;
    }
    return 0;
}

Point setPoint(int id, float x, float y) {
    Point point;
    point.id = id;
    point.x = x;
    point.y = y;
    return point;
}
typedef struct segment segment;
struct segment {
    int MAX;
    Point points[maxi];
};

segment setSegment(int MAX, Point pointA, Point pointB) {
    segment seg;
    seg.MAX = MAX;
    seg.points[0] = pointA;
    seg.points[seg.MAX-1] = pointB;
    float VectX = pointB.x - pointA.x;
    float VectY = pointB.y - pointA.y;
    VectX = VectX/seg.MAX;
    VectY = VectY/seg.MAX;
    for (int i=1;i<MAX-1;i++) {
        seg.points[i].id = i;
        seg.points[i].x = seg.points[i-1].x + VectX;
        seg.points[i].y = seg.points[i-1].y + VectY;
    }
    return seg;
}

void printSegment(segment seg) {
    for (int i=0;i<seg.MAX;i++) {
        printPoint(seg.points[i]);
    }
}

int main() {
    printf("\nLa taille de la structure point est %d\n\n",sizeof(Point));
    printf("\nLa taille de Point.id est %d\n\n",sizeof(int));
    printf("\nLa taille de Point.x est %d\n\n",sizeof(float));
    printf("\nLa taille de Point.y est %d\n\n",sizeof(float));
    printf("\nLa taille de la structure point2 est %d\n\n",sizeof(Point2));
    printf("\nLa taille de Point2.id est %d\n\n",sizeof(short));
    printf("\nLa taille de Point2.x est %d\n\n",sizeof(float));
    printf("\nLa taille de Point2.y est %d\n\n",sizeof(float));
    
    
    Point A;
    Point2 B;
    printf("\nOffset Point :%d\n",OFFSET(id,A));
    printf("\nOffset Point2 :%d\n",OFFSET(x,B));
    
    
    printf("Choisissez une option :\n");
    printf("1 : Symétrie d'un point\n");
    printf("2 : Création d'un segment\n");
    int choixMenu;
    scanf("%d",&choixMenu);
    if (choixMenu==1) {
        int x,y;
        printf("\nCoordonnée x du point :\n");
        scanf("%d",&x);
        printf("\nCoordonnée y du point :\n");
        scanf("%d",&y);
        Point point1 = setPoint(-1, x, y);
        printf("\nLe point créé est :");
        printPoint(point1);
        printf("\nQuelle est la symétrie voulue ? (1 : X | 2 : Y | 3 : ORIG) \n");
        int choix;
        Option opt;
        scanf("%d",&choix);
        opt = (Option)choix;
        symetrique(&point1,opt);
        printf("Le nouveau point est :");
        printPoint(point1);
    }
    else if (choixMenu==2) {
        int xA,yA,xB,yB;
        int nbPoints;
        printf("\nCoordonnée x du point A :\n");
        scanf("%d",&xA);
        printf("\nCoordonnée y du point A :\n");
        scanf("%d",&yA);
        printf("\nCoordonnée x du point B :\n");
        scanf("%d",&xB);
        printf("\nCoordonnée y du point B :\n");
        scanf("%d",&yB);
        printf("\nNombre de points voulus :\n");
        scanf("%d",&nbPoints);
        Point pointA = setPoint(0,xA,yA);
        Point pointB = setPoint(nbPoints-1,xB,yB);
        segment segment = setSegment(nbPoints,pointA,pointB);
        printSegment(segment);
    }
}
