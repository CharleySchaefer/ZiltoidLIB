# Polynomial root solvers

`Polynomial.c` and `Polynomial.h` provide legacy C routines for cubic, quartic and quintic polynomials. The source was originally downloaded from the URL recorded at the top of the files (2013-02-13), with later local changes.

## Interface and coefficient order

The coefficients are in **ascending order of power**:

- `cubic(A, X, &L)`: `A[0] + A[1]*x + A[2]*x^2 + A[3]*x^3`; `X` has room for 3 values.
- `quartic(dd, sol, soli, &Nsol)`: `dd[0] + ... + dd[4]*x^4`; real and imaginary output arrays each have room for 4 values.
- `quintic(dd, sol, soli, &Nsol, xstart)`: `dd[0] + ... + dd[5]*x^5`; real and imaginary output arrays each have room for 5 values. `xstart` is the initial Newton guess.

For quartic and quintic, `sol[i] + I*soli[i]` represents a returned root. `Nsol` is intended to count **real roots**, not the total number of root slots. The cubic routine returns only real roots, with their count in `L`.

## Known limitations — important

These are legacy numerical routines, **not robust general-purpose polynomial solvers**:

- The quintic routine finds one real root using Newton iteration, then divides by that root and calls the quartic routine. Newton iteration can fail for some starting guesses; the current code reports failure with `-1` and success with `1`. It uses a finite iteration limit and residual check, but neither guarantees a numerically accurate solution in all cases.
- The quartic implementation handles complex-conjugate pairs in some branches, but can encounter division by zero or invalid square roots in degenerate or repeated-root cases. Results may be incorrect or non-finite.
- The cubic implementation returns real roots only; complex roots are not provided. It has known edge-case weaknesses, including a zero-discriminant quadratic case and a sign error in its linear fallback. Repeated roots and Newton polishing may also be problematic.
- Root counts may count multiplicities differently across degenerate cases. Do not assume that all returned slots are valid unless you have verified the particular case.
- The quartic and cubic routines return `0` irrespective of ordinary success; their return values are not useful status indicators. The quintic routine uses a different return convention.
- No general input-pointer validation is performed. Arrays must have the sizes specified in the header, and leading coefficients must be appropriate for the requested polynomial degree.

**Recommendation:** use these functions only for well-tested cases where numerical failures can be tolerated. Validate returned roots by evaluating the original polynomial. For reliable complex roots, repeated roots, or ill-conditioned polynomials, replace the algorithms with a tested numerical library.

## Build

From the directory containing both files:

```sh
gcc -std=c11 -O2 -Wall -Wextra -Wpedantic -c Polynomial.c -o Polynomial.o
```

When linking an executable that uses these functions, link the math library (`-lm`), for example:

```sh
gcc main.c Polynomial.o -lm -o example
```

## Changes in this cleanup

- Matched array parameter bounds in `Polynomial.h` to the definitions in `Polynomial.c`, eliminating `-Warray-parameter` warnings.
- Replaced the non-standard `M_PI` macro with a local numerical constant so strict C11 compilation works.
- Kept the existing root-finding algorithms and their known numerical limitations unchanged.
