library verilog;
use verilog.vl_types.all;
entity top is
    port(
        clk             : in     vl_logic;
        reset           : in     vl_logic;
        WriteData       : out    vl_logic_vector(31 downto 0);
        DataAdr         : out    vl_logic_vector(31 downto 0);
        MemWrite        : out    vl_logic;
        PcOut           : out    vl_logic_vector(31 downto 0);
        InstrOut        : out    vl_logic_vector(31 downto 0)
    );
end top;
