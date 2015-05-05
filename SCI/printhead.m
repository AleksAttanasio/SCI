load data


% domain.xmin = [0 0];
% domain.xmax = [3 3];
% ndim = 2;
% P = cell(ndim,1);
% P{1} = [0 1 3];
% P{2} = [0 2 3];
% W = [0 2 3 1 3 4 3 5 6];

%dimpart is the homogeneus partition
dimpart = cell(ndim,1);
for i = 1 : ndim
    dimpart{i} = [0:1:(numel(P{i})-1)];
end

%asys is the A matrix for system solving (A*X = B)
Asys = cell(ndim,1);
for i = 1 : ndim
    Asys{i} = cat(2, P{i}', ones(numel(dimpart{i}),1));
end

solM = [];

for i = 1 : ndim
    for k = 1 : ((numel(dimpart{i}) - 1))
        A = Asys{i}(k:(k+1),1:2);
        B = dimpart{i}(k:(k+1));
        
        S = A\B';
        solM = [solM S];
        
    end
end


maxNp = max(numel(P{1}), numel(P{2})) - 1;

Opar = fopen('parameters.h','w');

% const int maxNp = ...
fprintf(Opar, 'const int maxNp = %d;',maxNp);

% const int N = ...
fprintf(Opar, '\n\nconst int N = %d;',ndim);

% const int Np[maxNp] = {...};
fprintf(Opar, '\n\nconst int Np[%d] = {', maxNp);
for i=1:(ndim-1)
    fprintf(Opar, '%d,',numel(P{i}));
end
fprintf(Opar, '%d};',numel(P{ndim}));

% float values[N][maxNp + 1] = {...}
fprintf(Opar, '\n\nfloat values[%d][%d] = {\n\t', ndim, (maxNp+1));
for i=1 :(ndim - 1)
    fprintf(Opar, '%f,',P{i});
    fprintf(Opar, '\n\t');
end
for i = 1 : (numel(P{ndim}) - 1)
    fprintf(Opar, '%f,',P{ndim}(i));
end
 fprintf(Opar, '%f\n};', P{ndim}(end));

 % const float m[N][maxNp] = {
 fprintf(Opar, '\n\nconst float m[%d][%d] = {\n\t', ndim, maxNp);
 for i = 1: (numel(solM(1,:))- 1)
     fprintf(Opar, '%f,',solM(1,i));
 end
 fprintf(Opar, '%f\n};',solM(1,end));
 
  % const float q[N][maxNp] = {
 fprintf(Opar, '\n\nconst float q[%d][%d] = {\n\t', ndim, maxNp);
 for i = 1: (numel(solM(2,:))- 1)
     fprintf(Opar, '%f,',solM(2,i));
 end
 fprintf(Opar, '%f\n};',solM(2,end));
 
% const int data[] = {...}
fprintf(Opar, '\n\nconst float data[] = {');
for i = 1 : (numel(w) - 1)
    fprintf(Opar, '\n\t%f,', w(i));
end
fprintf(Opar, '\n\t%f\n};',w(end));




fclose(Opar);
