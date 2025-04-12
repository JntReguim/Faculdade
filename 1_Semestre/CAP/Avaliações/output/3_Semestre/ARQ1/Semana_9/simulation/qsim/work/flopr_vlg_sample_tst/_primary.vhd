library verilog;
use verilog.vl_types.all;
entity flopr_vlg_sample_tst is
    port(
        clk             : in     vl_logic;
        d               : in     vl_logic_vector(7 downto 0);
        reset           : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end flopr_vlg_sample_tst;
