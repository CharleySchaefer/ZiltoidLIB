#ifndef LATTICE_CUBE_H
  #define LATTICE_CUBE_H 1
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>

  #include "../NN/NN.h"

  // Structure for lattice with square (2D) or cubic (3D) geometry

  // east  = x/i -direction
  // north = y/j -direction
  typedef struct{
    int dim;   // 1, 2 or 3 dimensions
    int Ncomponents;   // 
    int *site;         // array with sites
    int *num_neighbours;  // number of neighbours around a site
    int is_periodic_x; // default 1
    int is_periodic_y; // default 1
    int is_periodic_z; // default 1
    int Nx, Ny, Nz;    // Size
    int Nxy, Nyz;
    int Nxyz; // Total number of sites: Nsites=Nx*Ny*Nz
  } LATTICE_CUBE;

  LATTICE_CUBE *make_lattice_cube(int, int, int); // input: NX, NY, NZ;
  int free_lattice_cube(LATTICE_CUBE *);


  /* Adding cuboid domains to lattice (change 'site' values within a cuboid domain) */
  typedef struct {
    int val;
    int xL,yL,zL; // Lower coordinates
    int xU,yU,zU; // Upper coordinates
  } CUBOID ;

  CUBOID * make_Cuboid(void);
  void free_Cuboid(CUBOID *);
  int add_CuboidToLattice(LATTICE_CUBE *, CUBOID *); 




  // 2D lattice
  int NN_square_periodic(int, int, int, int *, int);             // NX, NY, ind, newind, direction: 0-N , 1-S , 2-E , 3-W 
           
  /*DATA STORAGE */  //                                 4-NE, 5-NW, 6-SE, 7-SW
  int coor2ind_square(LATTICE_CUBE *, int, int         );        // x,y   -> ind
  int ind2coor_square(LATTICE_CUBE *, int, int *, int *);        // ind   -> x,y
  int coor2ind_cube(  LATTICE_CUBE *, int, int,   int         ); // x,y,z -> ind
  int ind2coor_cube(  LATTICE_CUBE *, int, int *, int *, int *); // ind   -> x,y,z 

  /*ANALYSIS*/
  int get_sites_in_sphere_shell(double, double, double, double, double, int *, int *, int *, int *);
  int get_sites_in_spheres(int, double *, double *, double *, double,  int *, int *, int *, int *);
  int is_cube_vacant( LATTICE_CUBE *, int, int, int);
  int get_cosangle_between_lattice_coordinates(LATTICE_CUBE *, int, int, int, int, int, int, int, int, int, double, float *);
  int get_cosangle_between_lattice_sites(LATTICE_CUBE *, int , int , int , double, float *);

  int get_NeighbourSite(LATTICE_CUBE *, NN_STRUCT *, int, int, int, int, int *, int *, int *);

#endif

