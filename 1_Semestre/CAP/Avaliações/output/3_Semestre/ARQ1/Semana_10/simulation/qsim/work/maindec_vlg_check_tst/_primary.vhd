library verilog;
use verilog.vl_types.all;
entity maindec_vlg_check_tst is
    port(
        ALUOp           : in     vl_logic_vector(1 downto 0);
        ALUSrc          : in     vl_logic;
        Branch          : in     vl_logic;
        ImmSrc          : in     vl_logic_vector(1 downto 0);
        Jump            : in     vl_logic;
        MemWrite        : in     vl_logic;
        RegWrite        : in     vl_logic;
        ResultSrc       : in     vl_logic_vector(1 downto 0);
        sampler_rx      : in     vl_logic
    );
end maindec_vlg_check_tst;
