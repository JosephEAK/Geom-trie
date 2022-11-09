#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "geometric.h"

#define APPROX_EPS 0.0001
static const float M_PI_F = (float)M_PI;

int perimeter (){
    return 0 ;
}

int air (){
    return 0;
}

int cube(){
    return 0;
}

int approx(float a, float b) {
  int ret;
  if (fabsf(a) == 0 || fabsf(b) == 0) {
    ret = fabsf(a - b) <= APPROX_EPS;
  } else {
    ret = fabsf(a - b) <= APPROX_EPS * MAX(fabsf(a), fabsf(b));
    }
  return ret;
}

float distance(coord a, coord b){
    return sqrt(pow((b.x - a.x),2) + pow((b.y - a.y),2));
}

float angle (line A, line B, line C){
    float ang, rad;
    float A2 = pow(A.distance,2), B2 = pow(B.distance,2), C2 = pow(C.distance,2);
    rad = acos(( B2 - C2 - A2 )/( -2 * A.distance * C.distance));
    return ang = (180/M_PI_F) * rad;
}

int isRectangle (rectangle object){

    float hypotenuse1, hypotenuse2;
    line A, B, C, D;

    A.p1 = object.a;
    A.p2 = object.b;
    A.distance = distance(A.p1, A.p2);

    B.p1 = object.b;
    B.p2 = object.c;
    B.distance = distance(B.p1, B.p2);

    C.p1 = object.c;
    C.p2 = object.d;
    C.distance = distance(C.p1, C.p2);

    D.p1 = object.d;
    D.p2 = object.a;
    D.distance = distance(D.p1, D.p2);

    /*
    printf("Distance A: %f\n", A.distance);
    printf("Distance B: %f\n", B.distance);
    printf("Distance C: %f\n", C.distance);
    printf("Distance D: %f\n", D.distance);*/

    hypotenuse1 = sqrt(pow(A.distance,2)+pow(B.distance,2));
    hypotenuse2 = sqrt(pow(D.distance,2)+pow(C.distance,2));

    if (hypotenuse1 == hypotenuse2 &&
       (A.distance == B.distance == C.distance == D.distance)){
        printf("C'est un carré \n");
        return 1;
    }else if (hypotenuse1 == hypotenuse2 &&
       (A.distance == C.distance && B.distance == D.distance)){
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
    float angA, angB, angC;
    float radA, radB, radC;
    float totalAng;

    A.p1 = object.a;
    A.p2 = object.b;
    A.distance = distance(A.p1, A.p2);

    B.p1 = object.c;
    B.p2 = object.b;
    B.distance = distance(B.p1, B.p2);

    C.p1 = object.a;
    C.p2 = object.c;
    C.distance = distance(C.p1, C.p2);

    angA = angle(A, B, C);
    angB = angle(B, C, A);
    angC = angle(C, A, B);

    totalAng = angA + angB + angC;

    /*printf("A: %lf, B: %lf, C:%lf \n", A.distance, B.distance, C.distance);
    printf("radA:%lf, radB:%lf, radC:%lf \n", radA, radB, radC);
    printf("angA:%lf + angB:%lf + angC:%lf = %lf \n",angA,angB,angC, angA + angB + angC);*/

    if (totalAng != 180){
        printf("Ceci n'est pas un triangle \n");
        printf("angle total = %lf \n", angA + angB + angC);
        return 0;
    }
    
    if (approx(A.distance, B.distance) && approx(B.distance, C.distance) && approx(A.distance, C.distance)){
        printf("C'est un triangle équilatéral \n");
        return 1;
    }
    else if (
            approx(A.distance, B.distance) || 
            approx(A.distance, C.distance) || 
            approx(B.distance, C.distance)
            ){
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

