
module controller(input  logic [6:0] op,
                  input  logic [2:0] funct3,
                  input  logic       funct7b5,
                  input  logic       Zero, notZero,
                  input  logic       LessThan, GreaterEqual, 
                  output logic [1:0] ResultSrc,
                  output logic       MemWrite,
                  output logic       PCSrc, ALUSrc,
                  output logic       RegWrite, Jump,
                  output logic [1:0] ImmSrc,
                  output logic [2:0] ALUControl);

  logic [1:0] ALUOp;
  logic       Branch, CondBranch;

  // Decodificação principal
  maindec md(op, ResultSrc, MemWrite, Branch, ALUSrc, RegWrite, Jump, ImmSrc, ALUOp);
  
  // Decodificação ALU
  aludec  ad(op[5], funct3, funct7b5, ALUOp, ALUControl);

  // Determinando o condicional de branch baseado na instrução
  always_comb begin
    case(funct3)
      3'b000: CondBranch = Zero;         // beq
      3'b001: CondBranch = notZero;      // bne
      3'b100: CondBranch = LessThan;     // blt
      3'b101: CondBranch = GreaterEqual; // bge
      default: CondBranch = 1'b0;
    endcase
  end

  // PCSrc = Branch & CondBranch para decidir o salto
  assign PCSrc = Branch & CondBranch | Jump;
  
endmodule
