
module top(input  logic        clk, reset,
           output logic [31:0] WriteData, DataAdr, 
           output logic        MemWrite,
			  output logic [31:0] PcOut, InstrOut);

  logic [31:0] PC, Instr, ReadData;
  
  // Instantiate processor and memories
  riscvsingle rvsingle(clk, reset, PC, Instr, MemWrite, DataAdr, 
                       WriteData, ReadData);
					  
  imem imem(PC, Instr);
  
  dmem dmem(clk, MemWrite, DataAdr, WriteData, ReadData);
  
  assign Pcout = PC;
  assign InstrOut = Instr;
	 
endmodule
