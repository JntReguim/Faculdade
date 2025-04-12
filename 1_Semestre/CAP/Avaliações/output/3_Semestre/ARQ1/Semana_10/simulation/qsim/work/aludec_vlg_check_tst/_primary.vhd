library verilog;
use verilog.vl_types.all;
entity aludec_vlg_check_tst is
    port(
        ALUControl      : in     vl_logic_vector(2 downto 0);
        sampler_rx      : in     vl_logic
    );
end aludec_vlg_check_tst;
