library verilog;
use verilog.vl_types.all;
entity mux3_vlg_check_tst is
    port(
        y               : in     vl_logic_vector(7 downto 0);
        sampler_rx      : in     vl_logic
    );
end mux3_vlg_check_tst;
