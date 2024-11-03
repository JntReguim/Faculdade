library verilog;
use verilog.vl_types.all;
entity regfile_vlg_sample_tst is
    port(
        a1              : in     vl_logic_vector(5 downto 0);
        a2              : in     vl_logic_vector(5 downto 0);
        a3              : in     vl_logic_vector(5 downto 0);
        clk             : in     vl_logic;
        wd3             : in     vl_logic_vector(31 downto 0);
        we3             : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end regfile_vlg_sample_tst;
