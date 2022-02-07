function regresionCuadraticaMinimosCuadradosSA (x, y)
  # regresionCuadraticaMinimosCuadradosSA([85, 210, 285, 350], [874, 825, 812, 796]);
  
  n = length(x);
  m = length(y);
  
  if n == m 
    a = zeros(1, 3);
    b = zeros(1, 3);
    c = zeros(1, 3);
    y1 = zeros(1, 3);
    
    a(1, 1) = n;
    
    for i=1:n
      b (1, 1) += x(i);
      c (1, 1) += x(i)*x(i);
      y1(1, 1) += y(i);
      
      a (1, 2) += x(i);
      b (1, 2) += x(i)*x(i);
      c (1, 2) += x(i)*x(i)*x(i);
      y1(1, 2) += x(i)*y(i);
      
      a (1, 3) += x(i)*x(i);
      b (1, 3) += x(i)*x(i)*x(i);
      c (1, 3) += x(i)*x(i)*x(i)*x(i);
      y1(1, 3) += x(i)*x(i)*y(i);
    endfor
    
    A = [a(1,1),b(1,1),c(1,1);a(1,2),b(1,2),c(1,2);a(1,3),b(1,3),c(1,3)];
    B = [y1(1,1);y1(1,2);y1(1,3)];
    
    output_precision(8);
    
    w = A\B;
    
    disp("Al resolver el sistema obtenemos:");
    fprintf("\tb0 = %f\n", w(1,1));
    fprintf("\tb1 = %f\n", w(2,1));
    fprintf("\tb2 = %f\n\n", w(3,1));
    
    disp("Modelo de regresion cuadratico:");
    fprintf("y = %f ", w(1,1));
    if w(2,1) >= 0
      fprintf("+ %fx ", w(2,1));
    else
      fprintf("- %fx ", abs(w(2,1)));
    endif
    if w(3,1) >= 0
      fprintf("+ %fx^2\n", w(3,1));
    else
      fprintf("- %fx^2\n", abs(w(3,1)));
    endif
    
  else
    disp("ERROR! X y Y deben tener la misma cantidad de datos");
  endif
  
endfunction