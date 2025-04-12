library verilog;
use verilog.vl_types.all;
entity riscvsingle_vlg_check_tst is
    port(
        ALUResult       : in     vl_logic_vector(31 downto 0);
        MemWrite        : in     vl_logic;
        PC              : in     vl_logic_vector(31 downto 0);
        WriteData       : in     vl_logic_vector(31 downto 0);
        sampler_rx      : in     vl_logic
    );
end riscvsingle_vlg_check_tst;
