#include "ReadTextFiles.h"

int analyse_data_file_properties(char *fname, int *Nlines, int *Ncol, int *Nheader, int *Ndata, int verbose)
{
  if(verbose)
    printf("#Analyse data file \'%s\'\n", fname);

  if(!countLines(fname, Nlines))
  {printf("ERROR: countLines() failed!\n");   return(0);}
  if(!countColumns(fname, Ncol))
  {printf("ERROR: countColumns() failed!\n"); return(0);}
  if(!getNheader(fname, Nheader))
  {printf("ERROR: getNheader() failed!\n");   return(0);}

  if(verbose)
    printf("#Ndata estimated as Ndata=Nlines-Nheader; TODO: Identify white lines at end file.\n");
  *Ndata=(*Nlines)-(*Nheader); // TODO: remove white lines


  if(verbose)
  {
    printf("#Number of lines:        %d\n", *Nlines);
    printf("#Number of columns:      %d\n", *Ncol);
    printf("#Number of header lines: %d\n", *Nheader);
    printf("#Number of data lines:   %d\n",   *Ndata);
  }
  return(1);
}

int getNheader(const char *fname, int *Nheader)
{
  int i, atheader;
  char line[MAX_LINE_WIDTH];
  FILE *ifp;
  char c;

  if( (ifp = fopen(fname, "r")) == NULL)
    {printf("\nERROR: Failed to open file \'%s\'!\n\n", fname); return(0);}

  *Nheader=-1; atheader=1;
  while( atheader & fgets( line, sizeof line, ifp) != NULL )
  {
    (*Nheader)++;
    i=0;
    while( ((c=line[i]) == ' ' | c == '\t') & c!='\n' & c!='\0') // Skip white space
      i++;
    atheader=!('0'<=c & c<='9');
  }
  fclose(ifp); 

  return(1);
}

int countColumns(char *fname, int *Ncols)
{
  FILE *ifp;
  int  i, Nchar;
  char line[MAX_LINE_WIDTH], word[MAX_STR_L];

  // Open file
  if( (ifp = fopen(fname, "r")) == NULL)
    {printf("\nERROR: Failed to open file \"%s\" in countLines()!\n\n", fname); return(0);}

  // Read first line in the file
  fgets( line, sizeof line, ifp);

  // Read words in the line till end of line has been reached
  if( !countWords(line, word, &(*Ncols)) )
    {printf("\nERROR: Failed to execute countWords()!\n\n", fname); return(0);}

  // Close file
  fclose(ifp);
  return(1);
}

// Count lines in a file
int countLines(char *fname, int *Nlines)
{
  FILE *ifp;
  char line[MAX_LINE_WIDTH];

  if( (ifp = fopen(fname, "r")) == NULL)
    {printf("\nERROR: Failed to open file \"%s\" in countLines()!\n\n", fname);return(0);}

  (*Nlines) = 0;
  while( fgets( line, sizeof line, ifp) != NULL)
    (*Nlines)++;
  fclose(ifp);
  return(1);
}

int transpose_plain_data_file(char *fname, double **buffer)
{
  int i,j, Nlines, Ncol;
  FILE *ifp;
    
    countLines(fname, &Nlines);
  countColumns(fname, &Ncol);

  if(!readMatrix(fname, buffer, Nlines, Ncol))
    {printf("ERROR: readMatrix() failed!\n"); return(0);}

  ifp=fopen(fname, "w");
  for(i=0; i<Ncol; i++)
  {
    for(j=0; j<Nlines; j++)
    {
      fprintf(ifp, "%16e ", buffer[j][i]);
    }
    fprintf(ifp, "\n");
  }
  fclose(ifp);
  return(1);
}



int checkFileName(char *fname)
{
  int  exists,
       Nmax = 3,  // Length of 'str' by which the original string is modified
       N=0;
  char *newfileName,
       *fileNameTmp,
       *tmpc;
  FILE *ifp;

  newfileName=(char*)malloc(MAX_STR_L*sizeof(char));
  fileNameTmp=(char*)malloc(MAX_STR_L*sizeof(char));

  // If file already exists a new file name is tried
  if( (ifp = fopen( fname , "r")) != NULL )
  {  
    fclose(ifp);
    exists=1;
    while(exists==1)
    {
      fileNameTmp[0]='\0';
      strcat(fileNameTmp, fname);
      if(!fileNumber(fileNameTmp, N, Nmax, newfileName))
        {printf("ERROR: fileNumber() failed!\n"); return(0);}

      if( (ifp = fopen( newfileName , "r")) == NULL ) // File found!
        exists=0;
      N++;
    }
  }
  fname[0]='\0';
  strcat(fname, newfileName);

  return(1);
}



int countFiles(char *fname, int Nmax, int *Nfiles)
{
  int   i,
        check;
  char  c,
        ctmp[MAX_STR_L];
  FILE  *ifp;

  (*Nfiles)=0;
  if( (ifp=fopen(fname, "r")) != 0)
  {
    (*Nfiles)++;
    fclose(ifp);
  }

  check=1;i=0;
  while(check)
  {
    if(!fileNumber(fname, i, Nmax, ctmp))
    {
      printf("ERROR: fileNumber function not executed!\n");
      return(0);
    }
    if( (ifp=fopen(ctmp, "r")) != NULL) // file exists
    {
      (*Nfiles)++;
      fclose(ifp);
    }
    else  // file does not exist
      check=0;
    i++;
  }
  (*Nfiles)--;
  return(1);
}



int readColumn(char *fname, int Ndata, int Nheader, int Ncol, double *col)
{
  int  i,j,countCol;
  char c;
  char line[MAX_LINE_WIDTH];
  FILE *ifp;

  if(Ncol<0)
  {
    printf("WARNING: algorithm starts reading data at Ncol=1!\n");
    return(0);
  }
  if((ifp = fopen(fname, "r")) == NULL){printf("ERROR: Failed to open \'%s\'!\n", fname); return(0);}

  // Go to first line in file that contains data

  for(i=0; i<Nheader; i++)
    fgets(line, sizeof(line), ifp);


  // Get data from last column
  for(i=Nheader-1; i<Ndata+Nheader-1; i++) // sweep over all lines
  {
    fgets(line, sizeof(line), ifp);

    j=0;countCol=0;// initialise position in line
    // Skip white space before first column

    // Find position of first column in the line
    if((c=line[j])==' ') // Read line until space is found (column delimiter)
    {
      while( (c=line[j]) != '\0' & c != '\n' & c != ' ')
        j++;

      // Read line until end of space
      while( (c=line[j]) == ' ' & c != '\0' & c != '\n')
        j++;
    }

    // start reading columns
    while( countCol<Ncol & (c=line[j]) != '\0' & c != '\n' )
    {
      // Read line until space is found
      while( (c=line[j]) != '\0' & c != '\n' & c != ' ')
        j++;

      // Read line until end of space
      while( (c=line[j]) == ' ' & c != '\0' & c != '\n')
        j++;

      // If character after space is not the end of the line a column is found
      if( (c=line[j]) != ' ' & c != '\0' & c != '\n')
        countCol++;
    }
    col[i+1-Nheader] = atof(line+j); // Read column entry 
  }
  fclose(ifp);
  return(1);
}
  
int readColumn_int(
  char  *fname,    // File name         
  int   Ngrid,     // Number of datapoints     
  int   dataLine,   // Line number with first data points
  int    Ncol,    // Column number      
  int  *col    // Output array in with column values   
  ) // End of function arguments
  {
    int  i,j,countCol;
    char  c;
    char  line[MAX_LINE_WIDTH];
    FILE  *ifp;

    if(Ncol<0)
    {
      printf("WARNING: algorithm starts reading data at Ncol=1!\n");
      return(0);
    }

    if((ifp = fopen(fname, "r")) == NULL){printf("ERROR: Failed to open \'%s\' in readColumn!\n", fname); return(0);}

  /* Go to first line with data */  
    for(i=0; i<dataLine; i++)
      fgets(line, sizeof(line), ifp);

  /* Get data from last column */
    for(i=dataLine-1; i<Ngrid+dataLine-1; i++){
      fgets(line, sizeof(line), ifp);
      j=0;countCol=0;

      // Skip white space before first column
      if((c=line[j])==' ')
         {/* Read line until space is found */  
        while( (c=line[j]) != '\0' & c != '\n' & c != ' ')
          j++;

        /* Read line until end of space */    
        while( (c=line[j]) == ' ' & c != '\0' & c != '\n')
          j++;}
      
      // start reading columns
      while( countCol<Ncol & (c=line[j]) != '\0' & c != '\n' ){
    
        /* Read line until space is found */  
        while( (c=line[j]) != '\0' & c != '\n' & c != ' ')
          j++;

        /* Read line until end of space */    
        while( (c=line[j]) == ' ' & c != '\0' & c != '\n')
          j++;

        /* If character after space is not the end of the line a column is found */
        if( (c=line[j]) != ' ' & c != '\0' & c != '\n')
          countCol++;
        }
      col[i+1-dataLine] = atoi(line+j);  
      }
    fclose(ifp);
    return(1);
  }

int readRow(char *fname, int Nrow, double *row)
{
  int    i,j,ind, Nchar;
  char   word[MAX_STR_L], line[MAX_LINE_WIDTH];
  FILE   *ifp;
  
  if( (ifp = fopen(fname, "r")) == NULL){
    printf("\nERROR: Failed to open file \"%s\" in countLines!\n\n", fname);
    return(0);
    }
  // get to line at Nrow (Nrow=0) is the first line
  i=0;
  while( fgets( line, sizeof line, ifp) != NULL & i<Nrow)
    i++;
  
  ind=0;i=0;
  while( getWord( line+ind, word, &Nchar) )
  {
    ind+= Nchar;
    row[i] = atof(word);
    i++; // Count number of words
  }
  
  fclose(ifp);
  return(1);
}

int readRow_short(char *fname, int Nrow, short *row, int *Nword)
{
  int    i,j,ind, Nchar;
  char   word[MAX_STR_L], line[MAX_LINE_WIDTH];
  FILE   *ifp;
  
  if( (ifp = fopen(fname, "r")) == NULL){
    printf("\nERROR: Failed to open file \"%s\" in countLines!\n\n", fname);
    return(0);
    }
  // get to line at Nrow (Nrow=0) is the first line
  i=0;
  while( fgets( line, sizeof line, ifp) != NULL & i<Nrow)
    i++;
  
  ind=0;(*Nword)=0;
  while( getWord( line+ind, word, &Nchar) )
  {
    ind+= Nchar;
    row[(*Nword)] = atof(word);
    (*Nword)++; // Count number of words
  }
  
  fclose(ifp);
  return(1);
}

int readRow_int(char *fname, int Nrow, int *row, int *Nword)
{
  int    i,j,ind, Nchar;
  char   word[MAX_STR_L], line[MAX_LINE_WIDTH];
  FILE   *ifp;
  
  if( (ifp = fopen(fname, "r")) == NULL){
    printf("\nERROR: Failed to open file \"%s\" in countLines!\n\n", fname);
    return(0);
    }
  // get to line at Nrow (Nrow=0) is the first line
  i=0;
  while( fgets( line, sizeof line, ifp) != NULL & i<Nrow)
    i++;
  
  ind=0;(*Nword)=0;
  while( getWord( line+ind, word, &Nchar) )
  {
    ind+= Nchar;
    row[(*Nword)] = atoi(word);
    (*Nword)++; // Count number of words
  }
  
  fclose(ifp);
  return(1);
}


int readLine(char *fname, char *line, int Nline)
{
  int i;
  FILE *ifp;
  if(NULL==(ifp = fopen(fname, "r")))
    {printf("ERROR: Failed to read file \'%s\'!\n", fname); return(0);}
  for(i=0; i<Nline; i++)
    fgets(line, MAX_LINE_WIDTH*sizeof(char), ifp);
  fclose(ifp);
  return(1);
}


int readMatrix(char *fname, double **mat, int Nlines, int Ncols)
{
  int    i,j,ind, Nchar;
  char   c, word[MAX_STR_L], line[MAX_LINE_WIDTH];
  FILE   *ifp;
  
  if( (ifp = fopen(fname, "r")) == NULL){
    printf("\nERROR: Failed to open file \"%s\" in countLines!\n\n", fname);
    return(0);
    }
  i=0;
  while( fgets( line, sizeof line, ifp) != NULL)
  {
    ind=0;j=0;
    // Skip white space before first column
    while( (c=line[ind]) == ' ' & c != '\0' & c != '\n')
      ind++;
        
    while( getWord( line+ind, word, &Nchar) )
    {
      ind+= Nchar;
      mat[i][j] = atof(word);
      j++; // Count number of words
    }
    i++;
  }
  fclose(ifp);
  return(1);
}

int readMatrix_short(char *fname, short **mat, int Nlines, int Ncols)
{
  int    i,j,ind, Nchar;
  char   word[MAX_STR_L], line[MAX_LINE_WIDTH];
  FILE   *ifp;
  
  if( (ifp = fopen(fname, "r")) == NULL){
    printf("\nERROR: Failed to open file \"%s\" in countLines!\n\n", fname);
    return(0);
    }
  i=0;
  while( fgets( line, sizeof line, ifp) != NULL)
  {
    ind=0;j=0;
    while( getWord( line+ind, word, &Nchar) )
    {
      ind+= Nchar;
      mat[i][j] = atof(word);
      j++; // Count number of words
    }
    i++;
  }
  fclose(ifp);
  return(1);
}

int readMatrix_int(char *fname, int **mat, int Nlines, int Ncols)
{
  int    i,j,ind, Nchar;
  char   word[MAX_STR_L], line[MAX_LINE_WIDTH];
  FILE   *ifp;
  
  if( (ifp = fopen(fname, "r")) == NULL){
    printf("\nERROR: Failed to open file \"%s\" in countLines!\n\n", fname);
    return(0);
    }
  i=0;
  while( fgets( line, sizeof line, ifp) != NULL)
  {
    ind=0;j=0;
    while( getWord( line+ind, word, &Nchar) )
    {
      ind+= Nchar;
      mat[i][j] = atoi(word);
      j++; // Count number of words
    }
    i++;
  }
  fclose(ifp);
  return(1);
}
