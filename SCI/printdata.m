load data

npoints = size(points, 1);

Odat = fopen('data.h','w');
%
fprintf(Opar, 'const int npoints = %d;',npoints);

 fprintf(Odat, '\n\nconst float pointsM[%d][%d] = {\n\t', npoints, ndim);

 for i=1 : (npoints-1)
     fprintf(Odat, '\t%f,', points(i,:)); 
     fprintf(Odat, '\n'); 
 end
 
 for i = 1: (ndim-1)
    fprintf(Odat, '\t%f,', points(npoints, i));     
 end
 fprintf(Odat, '\t%f};', points(npoints,end)); 
 
 
fclose(Odat);