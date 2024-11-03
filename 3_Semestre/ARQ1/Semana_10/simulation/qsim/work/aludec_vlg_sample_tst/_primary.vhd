library verilog;
use verilog.vl_types.all;
entity aludec_vlg_sample_tst is
    port(
        ALUOp           : in     vl_logic_vector(1 downto 0);
        funct3          : in     vl_logic_vector(2 downto 0);
        funct7b5        : in     vl_logic;
        opb5            : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end aludec_vlg_sample_tst;
