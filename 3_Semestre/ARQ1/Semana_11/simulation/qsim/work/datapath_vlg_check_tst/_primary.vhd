library verilog;
use verilog.vl_types.all;
entity datapath_vlg_check_tst is
    port(
        ALUResult       : in     vl_logic_vector(31 downto 0);
        PC              : in     vl_logic_vector(31 downto 0);
        WriteData       : in     vl_logic_vector(31 downto 0);
        Zero            : in     vl_logic;
        sampler_rx      : in     vl_logic
    );
end datapath_vlg_check_tst;
