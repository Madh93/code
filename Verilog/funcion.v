module func;
  function [7:0] add;
    input [7:0] a, b;
    reg [7:0] res;
  begin
      res = a + b;
      add = res;
  end
  endfunction

  reg [7:0] A;

  initial
  begin
    A = add(8'b1010, 8'b1);
    $display("%b",A);
  end
endmodule