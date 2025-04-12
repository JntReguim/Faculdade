library verilog;
use verilog.vl_types.all;
entity datapath_vlg_sample_tst is
    port(
        ALUControl      : in     vl_logic_vector(2 downto 0);
        ALUSrc          : in     vl_logic;
        ImmSrc          : in     vl_logic_vector(1 downto 0);
        Instr           : in     vl_logic_vector(31 downto 0);
        PCSrc           : in     vl_logic;
        ReadData        : in     vl_logic_vector(31 downto 0);
        RegWrite        : in     vl_logic;
        ResultSrc       : in     vl_logic_vector(1 downto 0);
        clk             : in     vl_logic;
        reset           : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end datapath_vlg_sample_tst;
