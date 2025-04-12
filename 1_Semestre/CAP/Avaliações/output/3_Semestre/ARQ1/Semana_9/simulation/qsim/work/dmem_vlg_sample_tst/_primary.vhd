library verilog;
use verilog.vl_types.all;
entity dmem_vlg_sample_tst is
    port(
        a               : in     vl_logic_vector(31 downto 0);
        clk             : in     vl_logic;
        wd              : in     vl_logic_vector(31 downto 0);
        we              : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end dmem_vlg_sample_tst;
