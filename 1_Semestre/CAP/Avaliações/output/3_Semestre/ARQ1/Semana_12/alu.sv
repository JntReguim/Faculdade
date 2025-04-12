
module alu(input  logic [31:0] a, b,
           input  logic [2:0] alucontrol,
           output logic [31:0] result,
           output logic zero, notZero,
           output logic LessThan, GreaterEqual);

  logic [31:0] condinvb, sum;
  logic        v; // overflow
  logic        isAddSub; // true when is add or subtract operation

  // Sum and Subtraction logic
  assign condinvb = alucontrol[0] ? ~b : b;
  assign sum = a + condinvb + alucontrol[0];
  assign isAddSub = ~alucontrol[2] & ~alucontrol[1] | ~alucontrol[1] & alucontrol[0];

  always_comb begin
    case (alucontrol)
      3'b000: result = sum;         // add
      3'b001: result = sum;         // subtract
      3'b010: result = a & b;       // and
      3'b011: result = a | b;       // or
      3'b100: result = a << b;      // sll
      3'b101: result = sum[31];     // slt (set less than)
      3'b110: result = a >> b;      // srl
      3'b111: result = a ^ b;       // xor
      default: result = 32'bx;
    endcase
  end

  // Zero flag for bne and beq
  assign zero = (result == 32'b0);
  assign notZero = ~zero;
  
  // Comparisons for blt and bge
  assign LessThan = (a[31] != b[31]) ? a[31] : sum[31]; // Signed comparison
  assign GreaterEqual = ~LessThan;
  
  assign v = ~(alucontrol[0] ^ a[31] ^ b[31]) & (a[31] ^ sum[31]) & isAddSub;
  
endmodule
