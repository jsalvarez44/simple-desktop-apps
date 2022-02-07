function w = regresionCubica(x, y)  
  n = length(x);
  m = length(y);
  
  if n == m 
    a  = zeros(1, 4);
    b  = zeros(1, 4);
    c  = zeros(1, 4);
    d  = zeros(1, 4);
    y1 = zeros(1, 4);
    
    a(1, 1) = n;
    
    for i=1:n
      b (1, 1) += x(i);
      c (1, 1) += x(i)*x(i);
      d (1, 1) += x(i)*x(i)*x(i);
      y1(1, 1) += y(i);
      
      a (1, 2) += x(i);
      b (1, 2) += x(i)*x(i);
      c (1, 2) += x(i)*x(i)*x(i);
      d( 1, 2) += x(i)*x(i)*x(i)*x(i);
      y1(1, 2) += x(i)*y(i);
      
      a (1, 3) += x(i)*x(i);
      b (1, 3) += x(i)*x(i)*x(i);
      c (1, 3) += x(i)*x(i)*x(i)*x(i);
      d (1, 3) += x(i)*x(i)*x(i)*x(i)*x(i);
      y1(1, 3) += x(i)*x(i)*y(i);
      
      a (1, 4) += x(i)*x(i)*x(i);
      b (1, 4) += x(i)*x(i)*x(i)*x(i);
      c (1, 4) += x(i)*x(i)*x(i)*x(i)*x(i);
      d (1, 4) += x(i)*x(i)*x(i)*x(i)*x(i)*x(i);
      y1(1, 4) += x(i)*x(i)*x(i)*y(i);
    endfor
    
    A = [a(1,1),b(1,1),c(1,1),d(1,1);a(1,2),b(1,2),c(1,2),d(1,2);a(1,3),b(1,3),c(1,3),d(1,3);a(1,4),b(1,4),c(1,4),d(1,4)];
    B = [y1(1,1);y1(1,2);y1(1,3);y1(1,4)];
    
    output_precision(8);
    
    w = A\B;
    
  else
    disp("ERROR! X y Y deben tener la misma cantidad de datos");
  endif
  
endfunction