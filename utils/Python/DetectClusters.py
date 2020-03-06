#!/usr/bin/env python
# Charley Schaefer, University of York, 2020
# CLUSTER DETECTION - conditional dilation algorithm
#   > scan elements of 2D binary matrix
#   > find a 'seed' (a matrix element with value 1)
#   > dilate the seed to find 4-connected matrix elements 
#     (referred to as a cluster)
#   get_cluster_list: 
#     get list with seed locations 
#     and size of associated clusters
#   get_cluster:      
#     get coordinates of all matrix elements
#     belonging to the same cluster
#   select_largest_cluster:
#     read matrix and create binary matrix with ones
#     only at the location of the largest cluster
#   analyse_cluster:
#     get size of cluster, mean xy position, and std xy position
import sys
import numpy as np
import math
#from decimal import Decimal

def get_cluster_list(matrix):
  M=len(matrix)
  N=len(matrix[0])
  analysed=np.zeros([M,N], int) # keep track of what matrix entries are analysed
  clusters=np.empty((0,3), int)
  Nclusters=0
  for i in range(M):
    for j in range(N):
      if ((analysed[i,j]==0) & (matrix[i,j]>0)):  # New cluster
        analysed[i,j]=1
        Nclusters+=1
        clustersize=1;
        nn_list=np.empty((0,2), int);
        Nnn=0 # length of nn_list

        # get neighbour sites
        if (j>0):
          k=i; l=j-1;
          if ( analysed[k,l]==0):
            nn_list=np.append(nn_list, [[k,l]], axis=0); Nnn=Nnn+1;
        if ( j<N-1 ):
          k=i; l=j+1;
          if ( analysed[k,l]==0):
            nn_list=np.append(nn_list, [[k,l]], axis=0); Nnn=Nnn+1;
        if ( i>0 ):
          k=i-1; l=j;
          if ( analysed[k,l]==0):
            nn_list=np.append(nn_list, [[k,l]], axis=0); Nnn=Nnn+1;
        if ( i<M-1 ):
          k=i+1; l=j;
          if (analysed[k,l]==0):
            nn_list=np.append(nn_list, [[k,l]], axis=0); Nnn=Nnn+1;
        # analyse neighbours
        while (Nnn>0): # analyse neighbours
          m=nn_list[Nnn-1,0]; # analyse neighbour
          n=nn_list[Nnn-1,1]; # analyse neighbour
      
          nn_list=np.delete( nn_list, Nnn-1, axis=0) ; Nnn=Nnn-1;
          if ( analysed[m,n]!=1):
            analysed[m,n]=1;
            if ( matrix[m,n]>0): # new element in cluster
              clustersize=clustersize+1;
              # Get new neighbours
              # get neighbour sites
              if ( n>0 ):
                k=m; l=n-1;
                if ( analysed[k,l]==0):
                  nn_list=np.append(nn_list, [[k,l]], axis=0); Nnn=Nnn+1;
              if ( n<N-1 ):
                k=m; l=n+1;
                if ( analysed[k,l]==0):
                  nn_list=np.append(nn_list, [[k,l]], axis=0); Nnn=Nnn+1;
              if ( m>0 ):
                k=m-1; n=j;
                if ( analysed[k,l]==0):
                  nn_list=np.append(nn_list, [[k,l]], axis=0); Nnn=Nnn+1;
              if ( m<M-1 ):
                k=m+1; n=j;
                if (analysed[k,l]==0):
                  nn_list=np.append(nn_list, [[k,l]], axis=0); Nnn=Nnn+1;
        # end while loop: cluster completed
        clusters=np.append(clusters, [[i,j,clustersize]], axis=0)
  return clusters

def get_cluster(matrix, seed):
  i=seed[0]
  j=seed[1]
  M=len(matrix)
  N=len(matrix[0])
  analysed=np.zeros([M,N], int) # keep track of what matrix entries are analysed
  cluster=np.empty((0,2), int)  # will contain coordinates

  if ((analysed[i,j]==0) & (matrix[i,j]>0)):  # New cluster
    analysed[i,j]=1
    cluster= np.append(cluster, [[i,j]], axis=0);

    nn_list=np.empty((0,2), int);
    Nnn=0 # length of nn_list

    # get neighbour sites
    if (j>0):
      k=i; l=j-1;
      if ( analysed[k,l]==0):
        nn_list=np.append(nn_list, [[k,l]], axis=0); Nnn=Nnn+1;
    if ( j<N-1 ):
      k=i; l=j+1;
      if ( analysed[k,l]==0):
        nn_list=np.append(nn_list, [[k,l]], axis=0); Nnn=Nnn+1;
    if ( i>0 ):
      k=i-1; l=j;
      if ( analysed[k,l]==0):
        nn_list=np.append(nn_list, [[k,l]], axis=0); Nnn=Nnn+1;
    if ( i<M-1 ):
      k=i+1; l=j;
      if (analysed[k,l]==0):
        nn_list=np.append(nn_list, [[k,l]], axis=0); Nnn=Nnn+1;
    # analyse neighbours
    while (Nnn>0): # analyse neighbours
      m=nn_list[Nnn-1,0]; # analyse neighbour
      n=nn_list[Nnn-1,1]; # analyse neighbour
    
      nn_list=np.delete( nn_list, Nnn-1, axis=0) ; Nnn=Nnn-1;
      if ( analysed[m,n]!=1):
        analysed[m,n]=1;
        if ( matrix[m,n]>0): # new element in cluster
          cluster=np.append(cluster, [[m,n]], axis=0)
          # Get new neighbours
          # get neighbour sites
          if ( n>0 ):
            k=m; l=n-1;
            if ( analysed[k,l]==0):
              nn_list=np.append(nn_list, [[k,l]], axis=0); Nnn=Nnn+1;
          if ( n<N-1 ):
            k=m; l=n+1;
            if ( analysed[k,l]==0):
              nn_list=np.append(nn_list, [[k,l]], axis=0); Nnn=Nnn+1;
          if ( m>0 ):
            k=m-1; n=j;
            if ( analysed[k,l]==0):
              nn_list=np.append(nn_list, [[k,l]], axis=0); Nnn=Nnn+1;
          if ( m<M-1 ):
            k=m+1; n=j;
            if (analysed[k,l]==0):
              nn_list=np.append(nn_list, [[k,l]], axis=0); Nnn=Nnn+1;
    # end while loop: cluster completed
  return cluster

def select_largest_cluster(matrix_in):

  # Detect clusters
  clusters=get_cluster_list(matrix_in)
  Nclusters=len(clusters)

  # Get largest cluster
  max_cluster_size = max(clusters[:,2])
  max_index =  np.argmax(clusters[:,2])
  seed=[clusters[max_index,0], clusters[max_index,1]]
  cluster=get_cluster(matrix_in, seed)
  cluster_size=len(cluster)

  matrix_out=np.zeros([len(matrix_in), len(matrix_in[0])])
  for i in range(cluster_size):
    matrix_out[cluster[i,0],cluster[i,1]]=1
  return matrix_out

def analyse_cluster(matrix):
  M=len(matrix);
  N=len(matrix[0]);
  cluster_size=0 ; xi=0 ; yi=0 # mean position
  for i in range(M):
    for j in range(N):
      if (matrix[i][j]==1):
        xi+=i 
        yi+=j
        cluster_size=cluster_size+1 # cluster size
  xi=xi/cluster_size
  yi=yi/cluster_size
  xistd=0; yistd=0; # standard deviation
  for i in range(M):
    for j in range(N):
      if (matrix[i][j]==1):
        xistd+=(i-xi)**2 
        yistd+=(j-yi)**2
  xistd=np.sqrt(xistd/cluster_size)
  yistd=np.sqrt(yistd/cluster_size)
  arr=[cluster_size, xi, xistd, yi, yistd]
  return arr


