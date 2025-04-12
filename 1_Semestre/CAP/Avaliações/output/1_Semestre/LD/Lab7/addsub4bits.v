`timescale 1ns / 1ps
// Use este modulo quando for gravar na placa
// Bancada A1B
// Nome Jonatã Aparecido Reguim RA 824754
//      Bruna da Cunha silva    RA 779790

module top(
  input [0:0]btn, // Usar o pb[0]
  input [3:0] sw, // x
  input [3:0] ja, // y
  output [3:0] jb, // segmentos [a-d]
  output [3:0] jc); // segmentos [e-g]+cat
  
  wire [3:0]hex;
  wire [6:0]segs;
  wire [3:0]ss; 
  wire ov;
  
  addsum4bits ass (btn[0], sw, ja, ss, ov);
  dec7seg decodificador (hex, segs);
  
  assign hex = ov ? 4'he : ss;
  assign {jc, jb} = {ov, segs};

endmodule

module addsum4bits (
  input op,
  input [3:0] x, y,
  output [3:0] s,
  output ov);
  
  wire [3:0] fio;
  
  // Implemente aqui o somador/subtrator
  sum4bits sum (op, x, fio, s, ov);
  assign fio[3:0] = op ? ~y[3:0] : y[3:0];
  
endmodule
