`timescale 1ns / 1ps

module full_adder(
    input Cin, X, Y,
    output S, Cout);
    assign S = X ^ Y ^ Cin;
    assign Cout = (X & Y) | (Cin & X) | (Cin & Y);    
endmodule