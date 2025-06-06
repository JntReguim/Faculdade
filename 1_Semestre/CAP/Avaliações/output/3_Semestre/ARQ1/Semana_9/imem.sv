
//
// imem.sv : memoria de instrucoes
//
// Simulacao: Waverform7.vwf
//
// Funciona como memora ROM (read-only), 
//  sendo inicializado com as instrucoes contidas 
//  no arquivo riscvtes.txt (apenas p/ simulacao)
//
// Capacidade de armazenamento: 64 posicoes de 32 bits.)
//

module imem(input logic [31:0] a,
				output logic [31:0] rd);
	
	logic [31:0] RAM[63:0];
	
	initial
		$readmemh("riscvtest.txt",RAM);
	
	assign rd = RAM[a[31:2]]; // word aligned

endmodule