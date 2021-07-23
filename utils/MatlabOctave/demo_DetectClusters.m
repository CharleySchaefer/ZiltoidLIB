%-------------------------------------------------------
% getClusters(): identify clusters of particles based on their connectivity
%
% Charley Schaefer, University of York, UK (2021)
% https://github.com/CharleySchaefer/ZiltoidLIB/utils
%
% all_particles: cell with particle structures
% Each particle structure contains
%    pID:        particle identifier (not used, actually)
%    evaluated:  initialised to 0
%                trackes which structures have been evaluated
%    Nneigh:     Number of neighbours
%    neigh:      list with particle identifiers (pID's)
%                of neighbours
function demo_DetectClusters()
  clc; close all;

  %==================================================
  % INITIALISATION
  Nparticles=10;

  %-----------------------------------------
  % function to create particle connectivities
  global all_particles;
  function add_particles_neighbours(pID1, pID2)
    all_particles{pID1}.Nneig=all_particles{pID1}.Nneig+1;
    all_particles{pID1}.neigh=[all_particles{pID1}.neigh, pID2];
    all_particles{pID2}.Nneig=all_particles{pID2}.Nneig+1;
    all_particles{pID2}.neigh=[all_particles{pID2}.neigh, pID1];
  end

  %-----------------------------------------
  % Initialise particles structure
  for pID=1:Nparticles
    particle.ID=pID; 
    particle.evaluated=0;
    particle.Nneig=0;
    particle.neigh=[];
    all_particles{pID}=particle;
  end 

  %-----------------------------------------
  % Add neighbour information (e.g., using rangesearch)
  pID1=1;   pID2=2; 
  add_particles_neighbours(pID1, pID2)
  pID1=1;   pID2=3; 
  add_particles_neighbours(pID1, pID2)
  pID1=6;   pID2=9; 
  add_particles_neighbours(pID1, pID2)
  pID1=5;   pID2=7; 
  add_particles_neighbours(pID1, pID2)
  %INITIALISATION DONE
  %==================================================


  %==================================================
  % CORE CALCULATION
  all_clusters=DetectClusters();
  % CORE CALCULATION DONE
  %==================================================


  %==================================================
  % REPORTING
  Nclusters=length(all_clusters);
  fprintf('Nclusters: %d\n', Nclusters)
  fprintf('----------------\n')
  fprintf('clusterID | Size | particleIDs\n')
  for i=1:Nclusters
    fprintf('%9d | %4d |',i, length(all_clusters{i}.plist) );
    for j=1:length(all_clusters{i}.plist)
      pID=all_clusters{i}.plist(j);
      fprintf(' %d', pID);
    end
    fprintf('\n');
  end
  % REPORTING DONE
  %==================================================
end



