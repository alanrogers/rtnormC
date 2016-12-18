//  Example for using rtnorm
//
//  Translated from C++ to C by Alan R. Rogers
//  
//  Copyright (C) 2012 Guillaume Dollé, Vincent Mazet (LSIIT,
//  CNRS/Université de Strasbourg)  
//  Licence: GNU General Public License Version 2
//  see http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt
//
//  Depends: LibGSL
//  OS: Unix based system

#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <time.h>

#include "rtnorm.h"

int main(void) {
    double      a = 1;          // Left bound
    double      b = 9;          // Right bound
    double      mu = 2;         // Mean
    double      sigma = 3;      // Standard deviation
    Pair        s;              // Output argument of rtnorm
    int         K = 1e5;        // Number of random variables to generate

    //--- GSL random init ---
    gsl_rng    *rng = gsl_rng_alloc(gsl_rng_taus);
    gsl_rng_set(rng, (unsigned long) time(NULL));

    //--- generate and display the random numbers ---
    printf("underlying distribution: Normal(%lf, %lf)\n", mu, sigma);
    printf("truncated interval: [%lf, %lf]\n", a, b);
    for(int k = 0; k < K; k++) {
        s = rtnorm(rng, a, b, mu, sigma);
        printf("%lf %lf\n", s.first, s.second);
    }

    gsl_rng_free(rng);

    return 0;
}
