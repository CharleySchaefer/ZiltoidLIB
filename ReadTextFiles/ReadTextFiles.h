
#include <stdio.h> // used by ReadTextFiles
#include <stdlib.h> // used by ReadTextFiles
#include <string.h> // used by ReadTextFiles

#ifndef MAX_LINE_WIDTH
  #define MAX_LINE_WIDTH 25000
#endif
#ifndef MAX_STR_L
  #define  MAX_STR_L 200
#endif
#include "../StringOperations/StringOperations.h"

int analyse_data_file_properties(char *, int *, int *, int *, int *, int);
int getNheader(const char *, int *);
int countColumns(char *, int, int *);
int countLines(char *, int *);
int checkFileName(char *);
int countFiles(char *, int, int *);
int readMatrix(char *, double **, int, int);
int readMatrix_short(char *, short **, int, int);
int readMatrix_int(char *, int **, int, int);
int readLine(char *, char *, int);
int readRow_int(char *, int, int *, int *);
int readRow_short(char *, int, short *, int *);
int readRow(char *, int, double *);
int ireadColumn(char *, int, int, int, int *);
int freadColumn(char *, int, int, int, float *);
int dreadColumn(char *, int, int, int, double *);
int transpose_plain_data_file(char *, double ** );
