%-------------------------------------------------------
% getClusters(): identify clusters of particles based on their connectivity
%
% Charley Schaefer, University of York, UK (2021)
%
% all_particles: cell with particle structures
% Each particle structure contains
%    pID:        particle identifier (not used, actually)
%    evaluated:  initialised to 0
%                trackes which structures have been evaluated
%    Nneigh:     Number of neighbours
%    neigh:      list with particle identifiers (pID's)
%                of neighbours
function all_clusters=DetectClusters(all_particles)
  
  Nparticles=length(all_particles);
  global all_particles=all_particles;

  % NOTE: might be more efficient to make all_clusters()
  %       also into a global.
  function cluster=dilate_cluster(cluster, pID)
    cluster.plist=[cluster.plist, pID];
    
    particle= all_particles{pID};
    all_particles{pID}.evaluated=1;
    for i=1: all_particles{pID}.Nneig
      pIDnn=all_particles{pID}.neigh(i);  % ID of neighbour
      if all_particles{pIDnn}.evaluated==0
        cluster=dilate_cluster(cluster, pIDnn); 
      end
    end
  end

  Nclusters=0;
  for pID=1:Nparticles
    particle=all_particles{pID};

    if particle.evaluated==0 % Make new cluster

      all_particles{pID}.evaluated=1;
      Nclusters=Nclusters+1;
      cID=Nclusters;
      cluster.plist=[];
      all_clusters{cID}=cluster; % Inialise

      % Dilate
      cluster=dilate_cluster(cluster, pID) ;
      all_clusters{cID}=cluster;
    end
  end
end


