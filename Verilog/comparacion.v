//Haciendo pruebas varias

module prueba;

    reg [2:0] num;  //Registro de 3 bits
    
    reg [3:0] A = 3;
    reg [3:0] B = 4;
    reg [3:0] C; 


    initial
    begin

        C = A<B;
        
        $display("dec: %d",C);  //Mostrar por consola numero
        $display("bin: %b",C);  //Mostrar por consola numero
    end

endmodule