library verilog;
use verilog.vl_types.all;
entity maindec_vlg_sample_tst is
    port(
        op              : in     vl_logic_vector(6 downto 0);
        sampler_tx      : out    vl_logic
    );
end maindec_vlg_sample_tst;
