library verilog;
use verilog.vl_types.all;
entity flopr_vlg_check_tst is
    port(
        q               : in     vl_logic_vector(7 downto 0);
        sampler_rx      : in     vl_logic
    );
end flopr_vlg_check_tst;
