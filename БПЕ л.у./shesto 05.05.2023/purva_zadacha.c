#include <stdio.h>
#include <math.h>

typedef struct Point {
   float x;
   float y;
   float z;
} point;

int main() {
    point points[3] = { {1, 0, 2}, {1, 5, 3}, {1, 1, 9} };

   float dist1, dist2, dist3;
   dist1 = sqrt(pow(points[1].x - points[0].x, 2) + pow(points[1].y - points[0].y, 2) + pow(points[1].z - points[0].z, 2));
   dist2 = sqrt(pow(points[2].x - points[0].x, 2) + pow(points[2].y - points[0].y, 2) + pow(points[2].z - points[0].z, 2));
   dist3 = sqrt(pow(points[2].x - points[1].x, 2) + pow(points[2].y - points[1].y, 2) + pow(points[2].z - points[1].z, 2));
   printf("X - Y: %f\nZ - X: %f\nY - Z: %f\n", dist1, dist2, dist3);

   return 0;
}

