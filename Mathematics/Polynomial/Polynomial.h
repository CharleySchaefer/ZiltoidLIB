// DOWNLOADED FROM http://van-der-waals.pc.uni-koeln.de/quartic/quintic_C.c at 2013-02-13
// Polynomial root solvers; see README_Polynomial.md for conventions and limitations.

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

int quintic(double dd[6], double sol[5], double soli[5],
            int *Nsol, double xstart);
int quartic(double dd[5], double sol[4], double soli[4], int *Nsol);
int cubic(double A[4], double X[3], int *L);
int signR(double Z);
double CBRT(double Z);

#endif
