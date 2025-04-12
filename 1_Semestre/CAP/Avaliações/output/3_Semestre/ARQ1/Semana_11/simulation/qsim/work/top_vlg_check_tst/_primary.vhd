library verilog;
use verilog.vl_types.all;
entity top_vlg_check_tst is
    port(
        DataAdr         : in     vl_logic_vector(31 downto 0);
        InstrOut        : in     vl_logic_vector(31 downto 0);
        MemWrite        : in     vl_logic;
        PcOut           : in     vl_logic_vector(31 downto 0);
        WriteData       : in     vl_logic_vector(31 downto 0);
        sampler_rx      : in     vl_logic
    );
end top_vlg_check_tst;
