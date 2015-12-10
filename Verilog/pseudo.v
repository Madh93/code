//Pseudocodigo del algoritmo de booth o multiplicador

1) Inicializar registros

// X e Y de entrada
// done y P¿?

A <- 0 || Q <- Y || q-1 <- 0 || M <- X || done = 0

2)

for j=0 to (n-1) do

    2.1)

    case {q0,q1}

        00: A <- A;
        01: A <- A + M;     //tener cuidado con el overflow añadiendo un XOR
        10: A <- A - M;
        11: A <- A;

    end case

    2.2)

    A0Q0q-1 <- shra (A0Q0q-1,1)     //desplazamiento
end for

3)

done <- 1;

//

module mimodulo #(parameter retardo = 1)(input wire X, Y, start, output wire P, done);
//reset asíncrono, carga síncrona
always @(posedge clk, posedge reset)
  if (reset)
    q <= #retardo 1'b0; //'asignación no bloqueante q=0
  else
    if (carga)
      q <= #retardo d; //asignación no bloqueante q=d
endmodule
