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
function demo_integer_partitions()

  %-----------------------
  % USER INPUT
  M=8;
  N=5;
  %-----------------------
  
  
  %-----------------------
  % CORE CALCULATION
  partitions=integer_partitions(M,N);
  [Npartitions, ~]=size(partitions);
  %-----------------------
  
  
  %-----------------------  
  % CHECK RESULTS
  check=1;
  for i=1:Npartitions
    summ=0; check2=0;
    for j=1:N
      if partitions(i,j)>0
        if check2==0
          fprintf('%d = %d', M,  j);
          for k=1:partitions(i,j)-1
            fprintf(' + %d', j);          
          end
          check2=1;
        else
          for k=1:partitions(i,j)
            fprintf(' + %d', j);          
          end
         
        end
      end  
      summ=summ+partitions(i,j)*j;
    end
    fprintf('\n');
    if summ~=M
      fprintf('Error: partition %d returned %d instead of %d.\n', i, summ, M);
       check=0;
    end
  end
  if check==1
    fprintf('The number %d can be partioned in %d ways if %d is the maximum number within the partition.\n', M, Npartitions, N);
  end
  %-----------------------
end
