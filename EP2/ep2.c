/***************************************************************/
/**                                                           **/
/**   Felipe Beserra de Oliveira                 13683702     **/
/**   Exercício-Programa 2                                    **/
/**   Professor: Yoshiharu Kohayakawa                         **/
/**   Turma: 03                                               **/
/**                                                           **/
/***************************************************************/

#include <stdio.h>
#include <math.h>

#define G 6.67e-11

/* Distance between two points in space */
double dist(double p1x, double p1y, double p2x, double p2y);

/* Sum abs forces in one direction acting on Bi*/
double forca(char c, int i,
             double x0, double y0, double m0,  
             double x1, double y1, double m1,  
             double x2, double y2, double m2); 

/* Abs force in X direction */
double fx(double x0, double y0, double m0,
          double x1, double y1, double m1);

/* Abs force in Y direction */
double fy(double x0, double y0, double m0,
          double x1, double y1, double m1);

/* Update position with velocity */
void atualize(double *x, double *y, double *vx, double *vy,
              double ax, double ay, double dt);

/* Prints data at the moment */
void print();


int main() {

    double x0, y0, vx0, vy0, m0;
    double x1, y1, vx1, vy1, m1;
    double x2, y2, vx2, vy2, m2;
    double T, dt, t = 0;

    scanf("%lf %lf %lf %lf %lf", &x0, &y0, &vx0, &vy0, &m0); 
    scanf("%lf %lf %lf %lf %lf", &x1, &y1, &vx1, &vy1, &m1); 
    scanf("%lf %lf %lf %lf %lf", &x2, &y2, &vx2, &vy2, &m2);

    scanf("%lf", &T);
    scanf("%lf", &dt); 

    while (t <= T) {
        t+= dt;

        atualize(&x0, &y0, &vx0, &vy0, 
                forca('x', 0, x0, y0, m0, x1, y1, m1, x2, y2, m2) / m0,
                forca('y', 0, x0, y0, m0, x1, y1, m1, x2, y2, m2) / m0,
                dt);   
        
        atualize(&x1, &y1, &vx1, &vy1, 
                forca('x', 1, x0, y0, m0, x1, y1, m1, x2, y2, m2) / m1,
                forca('y', 1, x0, y0, m0, x1, y1, m1, x2, y2, m2) / m1,
                dt);   
        
        atualize(&x2, &y2, &vx2, &vy2, 
                forca('x', 2, x0, y0, m0, x1, y1, m1, x2, y2, m2) / m2,
                forca('y', 2, x0, y0, m0, x1, y1, m1, x2, y2, m2) / m2,
                dt);

        printf("%E %E %E %E %E %E\n", x0, y0, x1, y1, x2, y2);
    }

    printf("\n");
    return 0;
}

double dist(double p1x, double p1y, double p2x, double p2y) {
    return sqrt(pow((p1x - p2x), 2) + pow((p1y - p2y), 2));
}

double forca(char c, int i,
             double x0, double y0, double m0,
             double x1, double y1, double m1,
             double x2, double y2, double m2) {
    
    if (c == 'x') {
        if (i == 0) {
            return fx(x0, y0, m0, x1, y1, m1) + fx(x0, y0, m0, x2, y2, m2);    
        }
        if (i == 1) {
            return fx(x1, y1, m1, x0, y0, m0) + fx(x1, y1, m1, x2, y2, m2);    
        }
        if (i == 2) {
            return fx(x2, y2, m2, x0, y0, m0) + fx(x2, y2, m2, x1, y1, m1);    
        }
    }
    if (c == 'y') {
        if (i == 0) {
            return fy(x0, y0, m0, x1, y1, m1) + fy(x0, y0, m0, x2, y2, m2);    
        }
        if (i == 1) {
            return fy(x1, y1, m1, x0, y0, m0) + fy(x1, y1, m1, x2, y2, m2);    
        }
        if (i == 2) {
            return fy(x2, y2, m2, x0, y0, m0) + fy(x2, y2, m2, x1, y1, m1);    
        }
    }
    return 0;
}

double fx(double x0, double y0, double m0,
          double x1, double y1, double m1) {

    return G * m0 * m1 * (x0 - x1) / pow(dist(x0, y0, x1, y1), 3); 
}

double fy(double x0, double y0, double m0,
          double x1, double y1, double m1) {

    return G * m0 * m1 * (y0 - y1) / pow(dist(x0, y0, x1, y1), 3); 
}

void atualize(double *x, double *y, double *vx, double *vy,
              double ax, double ay, double dt) {

    *vx = *vx + ax * dt;
    *vy = *vy + ay * dt;
    *x = *x + *vx * dt;
    *y = *y + *vy * dt;
}
