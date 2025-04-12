library verilog;
use verilog.vl_types.all;
entity controller_vlg_sample_tst is
    port(
        Zero            : in     vl_logic;
        funct3          : in     vl_logic_vector(2 downto 0);
        funct7b5        : in     vl_logic;
        op              : in     vl_logic_vector(6 downto 0);
        sampler_tx      : out    vl_logic
    );
end controller_vlg_sample_tst;
