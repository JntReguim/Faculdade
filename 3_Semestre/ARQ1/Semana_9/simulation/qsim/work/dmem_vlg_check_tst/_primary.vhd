library verilog;
use verilog.vl_types.all;
entity dmem_vlg_check_tst is
    port(
        rd              : in     vl_logic_vector(31 downto 0);
        sampler_rx      : in     vl_logic
    );
end dmem_vlg_check_tst;
