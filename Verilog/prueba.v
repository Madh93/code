//Haciendo pruebas varias

module prueba;

    reg [2:0] num;  //Registro de 3 bits
    
    reg [9:0] A = 0;
    reg [9:0] B = -2;
    reg [9:0] C; 


    initial
    begin
        C = A+B;
        $display("dec: %d",C);  //Mostrar por consola numero
        $display("bin: %b",C);  //Mostrar por consola numero
    end

endmodule