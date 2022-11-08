#ifndef STRUCT_HEADER
#define STRUCT_HEADER

typedef struct coord{
    double x;
    double y;
    double z;
}coord;

typedef struct line{
    coord p1;
    coord p2;
    double distance;
}line;

typedef struct rectangle{
    coord a;
    coord b;
    coord c;
    coord d;
}rectangle;

typedef struct triangle{
    coord a;
    coord b;
    coord c;
}triangle;

int isRectangle(rectangle object);
int isTriangle(triangle object);

#endif