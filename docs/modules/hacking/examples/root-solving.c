#include "common.h"
#include "bu.h"
#include "vmath.h"
#include "bn.h"
#include "raytrace.h"

int
main(int argc, char *argv[])
{
    bn_poly_t equation; /* holds our polynomial equation */
    bn_complex_t roots[BN_MAX_POLY_DEGREE]; /* stash up to six roots */
    int num_roots;

    if (argc > 1)
        bu_exit(1, "%s: unexpected argument(s)\n", argv[0]);

/*********************************************
     * Linear polynomial (1st degree equation):
     *  A*X + B = 0
     * [0]   [1]     <= coefficients
     */
    equation.dgr = 1;
    equation.cf[0] = 1;  /* A */
    equation.cf[1] = -2;  /* B */

    /* print the equation */
    bu_log("\n*** LINEAR ***\n");
    bn_pr_poly("Solving for Linear", &equation);
    /* solve for the roots */
    num_roots = rt_poly_roots(&equation, roots, "My Linear Polynomial");
    if (num_roots == 0) {
        bu_log("No roots found!\n");
        return 0;
    } else if (num_roots < 0) {
        bu_log("The root solver failed to converge on a solution\n");
        return 1;
    }

    /*  A*X + B = 0
     *  1*X + -2 = 0
     *    X -  2 = 0
     *    X      = 2
     */
    /* print the roots */
    bu_log("The root should be 2\n");
    bn_pr_roots("My Linear Polynomial", roots, num_roots);

 /*********************************************
     * Quadratic polynomial (2nd degree equation):
     *  A*X^2 + B*X + C = 0
     * [0]     [1]   [2]     <=coefficients
     */
    equation.dgr = 2;
    equation.cf[0] = 1;  /* A */
    equation.cf[1] = 0;  /* B */
    equation.cf[2] = -4; /* C */

    /* print the equation */
    bu_log("\n*** QUADRATIC ***\n");
    bn_pr_poly("Solving for Quadratic", &equation);

    /* solve for the roots */
    num_roots = rt_poly_roots(&equation, roots, "My Quadratic Polynomial");
    if (num_roots == 0) {
        bu_log("No roots found!\n");
        return 0;
    } else if (num_roots < 0) {
        bu_log("The root solver failed to converge on a solution\n");
        return 1;
    }

    /*  A*X^2 + B*X +  C = 0
     *  1*X^2 + 0*X + -4 = 0
     *    X^2       -  4 = 0
     * (X - 2) * (X + 2) = 0
     *  X - 2 = 0, X + 2 = 0
     *  X = 2, X = -2
     */
    /* print the roots */
    bu_log("The roots should be 2 and -2\n");
    bn_pr_roots("My Quadratic Polynomial", roots, num_roots);

 /*****************************************
     * Cubic polynomial (3rd degree equation):
     *  A*X^3 + B*X^2 + C*X + D = 0
     * [0]     [1]     [2]   [3]     <=coefficients
     */
    equation.dgr = 3;
    equation.cf[0] = 45;
    equation.cf[1] = 24;
    equation.cf[2] = -7;
    equation.cf[3] = -2;

    /* print the equation */
    bu_log("\n*** CUBIC ***\n");
    bn_pr_poly("Solving for Cubic", &equation);

    /* solve for the roots */
    num_roots = rt_poly_roots(&equation, roots, "My Cubic Polynomial");
    if (num_roots == 0) {
        bu_log("No roots found!\n");
        return 0;
    } else if (num_roots < 0) {
        bu_log("The root solver failed to converge on a solution\n");
        return 1;
    }

    /* print the roots */
    bu_log("The roots should be 1/3, -1/5, and -2/3\n");
    bn_pr_roots("My Cubic Polynomial", roots, num_roots);

 /*******************************************
     * Quartic polynomial (4th degree equation):
     *  A*X^4 + B*X^3 + C*X^2 + D*X + E = 0
     * [0]     [1]     [2]     [3]   [4]     <=coefficients
     */
    equation.dgr = 4;
    equation.cf[0] = 2;
    equation.cf[1] = 4;
    equation.cf[2] = -26;
    equation.cf[3] = -28;
    equation.cf[4] = 48;

    /* print the equation */
    bu_log("\n*** QUARTIC ***\n");
    bn_pr_poly("Solving for Quartic", &equation);

    /* solve for the roots */
    num_roots = rt_poly_roots(&equation, roots, "My Quartic Polynomial");
    if (num_roots == 0) {
        bu_log("No roots found!\n");
        return 0;
    } else if (num_roots < 0) {
        bu_log("The root solver failed to converge on a solution\n");
        return 1;
    }
    /* print the roots */
    bu_log("The roots should be 3, 1, -2, -4\n");
    bn_pr_roots("My Quartic Polynomial", roots, num_roots);

 /*******************************************
     * Sextic polynomial (6th degree equation):
     *  A*X^6 + B*X^5 + C*X^4 + D*X^3 + E*X^2 + F*X + G = 0
     * [0]     [1]     [2]     [3]     [4]     [5]   [6]  <=coefficients
     */

    equation.dgr = 6;
    equation.cf[0] = 1;
    equation.cf[1] = -8;
    equation.cf[2] = 32;
    equation.cf[3] = -78;
    equation.cf[4] = 121;
    equation.cf[5] = -110;
    equation.cf[6] = 50;

    /* print the equation */
    bu_log("\n*** SEXTIC ***\n");
    bn_pr_poly("Solving for Sextic", &equation);

    /* solve for the roots */
    num_roots = rt_poly_roots(&equation, roots, "My Sextic Polynomial");
    if (num_roots == 0) {
        bu_log("No roots found!\n");
        return 0;
    } else if (num_roots < 0) {
        bu_log("The root solver failed to converge on a solution\n");
        return 1;
    }

    /* print the roots */
    bu_log("The roots should be 1 - i, 1 + i, 2 - i,2 + i, 1 - 2*i, 1 + 2*i \n");
    bn_pr_roots("My Sextic Polynomial", roots, num_roots);

    return 0;
}
