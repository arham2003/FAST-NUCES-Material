#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, discrim, root1, root2, realPart;
    printf("Enter coefficients a \n b \n c \n ");
    scanf("%lf %lf %lf", &a, &b, &c);

    discrim = b * b - 4 * a * c;

    // condition for real and different roots
    if (discrim > 0) {
        root1 = (-b + sqrt(discrim)) / (2 * a);
        root2 = (-b - sqrt(discrim)) / (2 * a);
        printf("root1 = %lf and root2 = %lf", root1, root2);
    }

    // condition for real and equal roots
    else if (discrim == 0) {
        root1 = root2 = -b / (2 * a);
        printf("root1 = root2 = %lf;", root1);
    }

    // if roots are not real
    else {
        realPart = -b / (2 * a);
        
        printf("root1 = %lf \n and root2 = %f \n", realPart, realPart);
    }

    return 0;
}
