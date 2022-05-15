% Charley Schaefer, University of York, UK (2021)
% https://github.com/CharleySchaefer/ZiltoidLIB/utils
%
% Any integer M can be written as a partition, which 
% is a sum of integers l_m:
%
%  M = \sum_{m=1}^{N} m*l_m,
%
%  e.g. 4 = 1*1 + 2*0 + 3*1 + 4*0
%
% This function finds all possible values of l_m to product M
% and stores them in the global partitions array.

function partitions=integer_partitions(M,N)
  global partitions;
  partitions=[];
  nested_partitions_find(M,N,[]); % stores results in partitions
  partitions=flip(partitions,2);
end

function [par, Mrest]=nested_partitions_find(M,N,par0)
  global partitions; 
  K=floor(M/N);
  for i=0:K
    j=K-i;
    Mrest=M-N*j;
    if Mrest==0
      par=[par0, j, zeros(1,N-1)];
      partitions=[partitions; par];  % Add to global results
    elseif ~(Mrest>0 && N==1)
      par=[par0, j];
      [par, Mrest]=nested_partitions_find(Mrest,N-1,par);
    end
  end
end
