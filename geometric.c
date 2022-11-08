#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <math.h>

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "geometric.h"

int perimeter (){
    return 0 ;
}

int air (){
    return 0;
}

int cube(){
    return 0;
}

int getCoord (coord *p){
    return 0;
}

int isRectangle (rectangle object){

    double hypotenuse1, hypotenuse2;
    line A, B, C, D;

    A.p1 = object.a;
    A.p2 = object.b;
    A.distance = sqrt(A.p1.x * A.p1.x + A.p2.y * A.p2.y);

    B.p1 = object.b;
    B.p2 = object.c;
    B.distance = sqrt(B.p1.x * B.p1.x + B.p2.y * B.p2.y);

    C.p1 = object.c;
    C.p2 = object.d;
    C.distance = sqrt(C.p1.x * C.p1.x + C.p2.y * C.p2.y);

    D.p1 = object.d;
    D.p2 = object.a;
    D.distance = sqrt(D.p1.x * D.p1.x + D.p2.y * D.p2.y);

    printf("Distance A: %f\n", A.distance);
    printf("Distance B: %f\n", B.distance);
    printf("Distance C: %f\n", C.distance);
    printf("Distance D: %f\n", D.distance);

    hypotenuse1 = sqrt(pow(A.distance,2)+pow(B.distance,2));
    hypotenuse2 = sqrt(pow(D.distance,2)+pow(C.distance,2));

    if (hypotenuse1 == hypotenuse2 &&
       (A.distance == B.distance == C.distance == D.distance)){
        printf("C'est un carré \n");
        return 1;
    }else if ((A.distance == C.distance && B.distance == D.distance)){
        printf("C'est un rectangle \n");
        return 2;
    } else{
        printf("Ceci n'est ni un carré ni un rectangle \n");
        return 0;
    }

    return -1;
}

int isTriangle(triangle object){

    line A,B,C;
    double angA, angB, angC;
    double radA, radB, radC;
    int totalAng;

    A.p1 = object.a;
    A.p2 = object.b;
    A.distance = sqrt(pow((A.p2.x - A.p1.x),2) + pow((A.p2.y - A.p1.y),2));

    B.p1 = object.b;
    B.p2 = object.c;
    B.distance = sqrt(pow((B.p2.x - B.p1.x),2) + pow((B.p2.y - B.p1.y),2));

    C.p1 = object.c;
    C.p2 = object.a;
    C.distance = sqrt(pow((C.p2.x - C.p1.x),2) + pow((C.p2.y - C.p1.y),2));

    double A2 = pow(A.distance,2), B2 = pow(B.distance,2), C2 = pow(C.distance,2);

    radA = acos(( B2 - C2 - A2 )/( -2 * B.distance * C.distance));
    angA = (180/M_PI) * radA;

    radB = acos(( C2 - B2 - A2 )/( -2 * A.distance * C.distance));
    angB = (180/M_PI) * radB;

    radC = acos(( A2 - C2 - B2 )/( -2 * A.distance * B.distance));
    angC = (180/M_PI) * radC;

    totalAng = angA + angB + angC;

    if (totalAng != 180){
        printf("Ceci n'est pas un triangle \n");
        printf("angle total = %lf \n", angA + angB + angC);
        return 0;
    }

    printf("A: %lf, B: %lf, C:%lf \n", A.distance, B.distance, C.distance);

    if (A.distance == B.distance && B.distance == C.distance && A.distance == C.distance){
        printf("C'est un triangle équilatéral \n");
        return 1;
    }
    else if ((A.distance == B.distance && A.distance == C.distance) ||
             (C.distance == A.distance && C.distance == B.distance) ||
             (B.distance == A.distance && B.distance == A.distance)){
        printf("C'est un triangle isocèle \n");
        return 2;
    }
    else if (angA == 90 || angB == 90 || angC == 90){
        printf("C'est un triangle rectangle \n");
        return 3;
    }
    else {
        printf("The world is doom \n");
        return -1;
    }
    return -1;

}

