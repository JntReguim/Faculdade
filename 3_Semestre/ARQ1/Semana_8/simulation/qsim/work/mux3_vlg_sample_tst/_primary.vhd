library verilog;
use verilog.vl_types.all;
entity mux3_vlg_sample_tst is
    port(
        d0              : in     vl_logic_vector(7 downto 0);
        d1              : in     vl_logic_vector(7 downto 0);
        d2              : in     vl_logic_vector(7 downto 0);
        s               : in     vl_logic_vector(1 downto 0);
        sampler_tx      : out    vl_logic
    );
end mux3_vlg_sample_tst;
