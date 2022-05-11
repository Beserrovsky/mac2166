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

const double G = 0.0000000000667;

double dist(double p1x, double p1y, double p2x, double p2y) {
    return sqrt(pow((p1x - p2x), 2) + pow((p1y - p2y), 2));
}

double forca(char c, int i,
             double x0, double y0, double m0,
             double x1, double y1, double m1,
             double x2, double y2, double m2) {
    
/*    
 *    TODO: Implement forca()
 *    return; 
 */
}

void atualize(double *x, double *y, double *vx, double *vy,
              double ax, double ay, double dt) {

/*
 *    TODO: Implement atualize()
 */
}

int main() {


    printf("\n");
    return 0;
}
