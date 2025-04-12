library verilog;
use verilog.vl_types.all;
entity mux2_vlg_sample_tst is
    port(
        d0              : in     vl_logic_vector(7 downto 0);
        d1              : in     vl_logic_vector(7 downto 0);
        s               : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end mux2_vlg_sample_tst;
