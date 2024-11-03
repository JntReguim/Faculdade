library verilog;
use verilog.vl_types.all;
entity extend_vlg_sample_tst is
    port(
        immsrc          : in     vl_logic_vector(1 downto 0);
        instr           : in     vl_logic_vector(31 downto 0);
        sampler_tx      : out    vl_logic
    );
end extend_vlg_sample_tst;
