function splineCubico(x, y)
  #splineCubico([0, 1, 2, 3], [5, 9, 15, 12]);
  clc;
  
  n = length(x);
  m = length(y);
  
  if n == m
    
    res = zeros(12, 12);
    #res(:,  1) = a1
    #res(:,  2) = b1
    #res(:,  3) = c1
    #res(:,  4) = d1
    #res(:,  5) = a2
    #res(:,  6) = b2
    #res(:,  7) = c2
    #res(:,  8) = d2
    #res(:,  9) = a3
    #res(:, 10) = b3
    #res(:, 11) = c3
    #res(:, 12) = d3
    
    y1 = zeros(12, 1);

    y1(1, 1) = y(1);
    y1(2, 1) = y(2);
    y1(3, 1) = y(2);
    y1(4, 1) = y(3);
    y1(5, 1) = y(3);
    y1(6, 1) = y(4);
    
    # ec 1
    res(1,  1) = x(1)^3;
    res(1,  2) = x(1)^2;
    res(1,  3) = x(1);
    res(1,  4) = 1;
    
    # ec 2
    res(2,  1) = x(2)^3;
    res(2,  2) = x(2)^2;
    res(2,  3) = x(2);
    res(2,  4) = 1;
    
    # ec 3
    res(3,  5) = x(2)^3;
    res(3,  6) = x(2)^2;
    res(3,  7) = x(2);
    res(3,  8) = 1;
    
    # ec 4
    res(4,  5) = x(3)^3;
    res(4,  6) = x(3)^2;
    res(4,  7) = x(3);
    res(4,  8) = 1;
    
    # ec 5
    res(5,  9) = x(3)^3;
    res(5, 10) = x(3)^2;
    res(5, 11) = x(3);
    res(5, 12) = 1;
    
    # ec 6
    res(6,  9) = x(4)^3;
    res(6, 10) = x(4)^2;
    res(6, 11) = x(4);
    res(6, 12) = 1;
    
    # ec 7
    res(7,  1) = 3*x(2)^2;
    res(7,  2) = 2*x(2);
    res(7,  3) = 1;
    res(7,  5) = -3*x(2)^2;
    res(7,  6) = -2*x(2);
    res(7,  7) = -1;
    
    # ec 8
    res(8,  5) = 3*x(3)^2;
    res(8,  6) = 2*x(3);
    res(8,  7) = 1;
    res(8,  9) = -3*x(3)^2;
    res(8, 10) = -2*x(3);
    res(8, 11) = -1;
    
    # ec 9
    res( 9,  1) = 6*x(2);
    res( 9,  2) = 2;
    res( 9,  5) = -6*x(2);
    res( 9,  6) = -2;
    
    # ec 10
    res(10,  5) = 6*x(3);
    res(10,  6) = 2;
    res(10,  9) = -6*x(3);
    res(10, 10) = -2;
    
    # ec 11
    res(11,  1) = 6*x(1);
    res(11,  2) = 2;
    
    #ec 12
    res(12,  9) = 6*x(4);
    res(12, 10) = 2;
    
    coeficientes = res\y1;

    disp("MATRIZ RESULTANTE");
    disp([res y1]);
    
    disp("");
    disp("COEFICIENTES");
    fprintf("a1 = %f\n", coeficientes(1));
    fprintf("b1 = %f\n", coeficientes(2));
    fprintf("c1 = %f\n", coeficientes(3));
    fprintf("d1 = %f\n", coeficientes(4));
    fprintf("a2 = %f\n", coeficientes(5));
    fprintf("b2 = %f\n", coeficientes(6));
    fprintf("c2 = %f\n", coeficientes(7));
    fprintf("d2 = %f\n", coeficientes(8));
    fprintf("a3 = %f\n", coeficientes(9));
    fprintf("b3 = %f\n", coeficientes(10));
    fprintf("c3 = %f\n", coeficientes(11));
    fprintf("d3 = %f\n", coeficientes(12));
  else
    disp("Tamaño de X e Y incorrecto!");
  endif
endfunction