function include_optimisation_pkg()
  % Charley Schaefer, University of York 2021
  % https://github.com/CharleySchaefer/ZiltoidLIB/tree/master/utils/MatlabOctave
  
  isOctave = exist('OCTAVE_VERSION', 'builtin') ~= 0 ;
  if isOctave % RUN IN OCTAVE
     % install octave packages: run "pkg install -forge struct optim statistics"
      %                           in command window
      pkg load struct
      pkg load optim       % lsqnonlin; dependency: struct
      pkg load statistics  % lhsdesign
  
  else % ASSUME PROG IS RUNNING IN MATLAB
    warning('Potential compatibility options - were developed using Octave rather than matlab');
      % Check licences
      if ~license('test','optimization_toolbox')
        error('ERROR: this code uses MATLAB''s optimization toolbox!')
        return
      end
      if ~license('test','statistics_toolbox')
         error('ERROR: this code uses MATLAB''s statistics toolbox!')
       return
      end
  end
end
