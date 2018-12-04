-- ==============================================================
-- File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
-- Version: 2017.1
-- Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
-- 
-- ==============================================================

library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity Blowfish_deciphereOg_rom is 
    generic(
             dwidth     : integer := 32; 
             awidth     : integer := 8; 
             mem_size    : integer := 256
    ); 
    port (
          addr0      : in std_logic_vector(awidth-1 downto 0); 
          ce0       : in std_logic; 
          q0         : out std_logic_vector(dwidth-1 downto 0);
          clk       : in std_logic
    ); 
end entity; 


architecture rtl of Blowfish_deciphereOg_rom is 

signal addr0_tmp : std_logic_vector(awidth-1 downto 0); 
type mem_array is array (0 to mem_size-1) of std_logic_vector (dwidth-1 downto 0); 
signal mem : mem_array := (
    0 => "00001011111011111100110001011101", 
    1 => "10011100111000101010001110100110", 
    2 => "01010111010000010100000000110000", 
    3 => "01100001010110100001010001010110", 
    4 => "01000000111101110110110101110110", 
    5 => "01010011111001111000011101010011", 
    6 => "10101110001100111010001010010010", 
    7 => "01111010000000000011011010101110", 
    8 => "10011101011001100001001101100111", 
    9 => "11101111010100101100100110000111", 
    10 => "00111100100010010001110111110100", 
    11 => "10101111100110100100110100100111", 
    12 => "11100010110111100111010000011000", 
    13 => "11110101001010111000111001101100", 
    14 => "01110100100011010111100010110100", 
    15 => "00000100111010011110100100000101", 
    16 => "10010111010110000001100001000110", 
    17 => "11010100111100010101100111010010", 
    18 => "11111100111100101111110100010101", 
    19 => "10001100101101010110000101101000", 
    20 => "00110001001010111001011011101101", 
    21 => "10010010101100110101101101010101", 
    22 => "00110000110000010010100101000000", 
    23 => "01111000111100010101100111111100", 
    24 => "10001100110100101000110101110010", 
    25 => "10101111000010110010110100100100", 
    26 => "01010100001111100110001010010001", 
    27 => "01111010011100001001110111100000", 
    28 => "10101001010101011001001010010001", 
    29 => "00101010100101101110010111100001", 
    30 => "10010001111001111100110001011010", 
    31 => "01010100110111010011010001000011", 
    32 => "11111001000011000111010010111111", 
    33 => "10111100011001000100111110110101", 
    34 => "10010010110111010110011000100110", 
    35 => "00101010101000011111011000100111", 
    36 => "01000011011110010111101111110110", 
    37 => "11000110010010111101000110010101", 
    38 => "00000001101110001000100101000110", 
    39 => "01011010110100101001010010010010", 
    40 => "01010101101011011101010111101101", 
    41 => "01011101111010111000010111101001", 
    42 => "01110010001110100000101111001100", 
    43 => "10010101110000001010111101110010", 
    44 => "01100001111001000100011111001101", 
    45 => "01001001001010010101010010000010", 
    46 => "10011101000001100011001101011011", 
    47 => "10001111101001001001101000010001", 
    48 => "10000110010110111100111101101100", 
    49 => "00011111000011001010110011011001", 
    50 => "01001101100110110100110000000010", 
    51 => "11100111111000100001100101110000", 
    52 => "10010010000011111110110101011100", 
    53 => "11101101111000100001001011011100", 
    54 => "00110010100101100101000101010000", 
    55 => "00010110000011001101101011000010", 
    56 => "11001101100110001000110000001100", 
    57 => "11110101000010110100100001110101", 
    58 => "10110100000111001100111000010000", 
    59 => "10000001000110111110100100000111", 
    60 => "00100001001010110110000011101101", 
    61 => "11010011101001010110110001010100", 
    62 => "01010100011110100001111000101110", 
    63 => "00000110110001000001100000110001", 
    64 => "00011100101000110010000101101001", 
    65 => "01110110011011101011110001010010", 
    66 => "11110000110010111111011110110001", 
    67 => "11011111111111101011011001100100", 
    68 => "11101000001110010010000110001100", 
    69 => "00110111101010110001001110000001", 
    70 => "01011000101101000100110110110110", 
    71 => "00011100110111111000111010010001", 
    72 => "10101010101101011111010111000000", 
    73 => "10101111110000010011101010001110", 
    74 => "00100101111101110010011010011100", 
    75 => "01000101110111100110010000000000", 
    76 => "00111110100000110001110000001110", 
    77 => "01100100000101101110100001101001", 
    78 => "10010010100001100110000001001101", 
    79 => "11111111110000001001000001011000", 
    80 => "01111110000100110100100010111111", 
    81 => "00101101101111111100111011110001", 
    82 => "01101100110000111110001111100000", 
    83 => "10110010010000111100111111000100", 
    84 => "11111110111101001010001110001101", 
    85 => "10000101110010101000011111111001", 
    86 => "00011110011100101110001011011110", 
    87 => "10000101011111001011111110101110", 
    88 => "11011101101010011011010111110010", 
    89 => "11000010010101010001100010010100", 
    90 => "00111010100011011100100101100101", 
    91 => "10100010010101011010100101100110", 
    92 => "00000110000111101110100011010000", 
    93 => "00111001000010001101111010010010", 
    94 => "01011100100111101110111100100101", 
    95 => "00110010110011011101001101101011", 
    96 => "10011010001110010000101110111100", 
    97 => "10000001110100010010110000110001", 
    98 => "10010110001111101010011000000100", 
    99 => "10001100101001011110100111101110", 
    100 => "00000011110010000110010100111011", 
    101 => "10101011010001001010101000100111", 
    102 => "01100001000101101010001110000010", 
    103 => "01011001010100101111111101110101", 
    104 => "01100100000101011000011110000110", 
    105 => "10110111110011101101111100000010", 
    106 => "11101001001010101000111011000010", 
    107 => "11101111100110010000011100111100", 
    108 => "00100011001110110101000100000001", 
    109 => "11010101001100000001001101100011", 
    110 => "00011111000011111001110000101101", 
    111 => "00011000011101100010000111100001", 
    112 => "01001100000000110001101001000100", 
    113 => "01011111001101101111101001110111", 
    114 => "00011111111010101011111001100011", 
    115 => "10001100111000011010010101001000", 
    116 => "10110011011000000111111101011001", 
    117 => "01010100101001010100111011100011", 
    118 => "00110001010110010010010111000100", 
    119 => "10011000100001100011000001100001", 
    120 => "11000010010011011101110100101101", 
    121 => "11001101001000000011110101100001", 
    122 => "01100100111001001011000010111110", 
    123 => "11001010001110111011110110000011", 
    124 => "00001010001010001110100101001000", 
    125 => "01111010101010100001000000010001", 
    126 => "01000101001001100010100011001101", 
    127 => "01101001100110101100001010111110", 
    128 => "10001001111101000001110111000110", 
    129 => "01111000101100011100011100101111", 
    130 => "10110011100011101101001001100000", 
    131 => "00110100101011010000010111101100", 
    132 => "10011001011000000110011101100101", 
    133 => "11111100100000110101100101011111", 
    134 => "00010001001011110000100111101100", 
    135 => "01010101101000111111001111010010", 
    136 => "01000111000100010110001000111000", 
    137 => "00001110010001101110100011101111", 
    138 => "01010001100101111011100001000111", 
    139 => "10010000010001110001011001011011", 
    140 => "11101110110000010100001101101100", 
    141 => "01001110101111011000011001100010", 
    142 => "11000101010100111001000011110111", 
    143 => "01000100010101101010001101001010", 
    144 => "00100111100011111101110110001100", 
    145 => "10001100101010100100011011000011", 
    146 => "11000101100111000101011000101111", 
    147 => "01110100011100010111111001011101", 
    148 => "11001100101111001000010000011100", 
    149 => "00101111110110011011001000011111", 
    150 => "10001010111110110000101011011000", 
    151 => "11001111001111001101010110011110", 
    152 => "11001001010110101000001010011000", 
    153 => "01010010010000000111100100111011", 
    154 => "11010001011101000000011111001001", 
    155 => "11110110011101101001000011001111", 
    156 => "10001101001010110010100111111000", 
    157 => "10000001011101110110000101101111", 
    158 => "01010101111110111001110010010001", 
    159 => "11110011000010011111100111101001", 
    160 => "11101110101101100101000100000000", 
    161 => "11110011011101000111111100100111", 
    162 => "01000011001000000100110001001111", 
    163 => "10111100010000101110010110110101", 
    164 => "01111001010101000001000011111001", 
    165 => "01111110110000011101001101101011", 
    166 => "11110100110111000000000110101000", 
    167 => "10000101000111000100000101001011", 
    168 => "00000110001111001110101100000100", 
    169 => "01011001011001101100100000011001", 
    170 => "10010000101110100111111111101101", 
    171 => "01101011000100110110110101110001", 
    172 => "01100000100000001111000010001110", 
    173 => "01011001001100010101100101111000", 
    174 => "00100011010101100111100001000000", 
    175 => "01010010010011100101110100010110", 
    176 => "11101001011000110010100001000010", 
    177 => "11100101011100111101100100010111", 
    178 => "00010010011011011111100010000001", 
    179 => "11100100101110010110001011101011", 
    180 => "00111010110110101010100111000101", 
    181 => "11000011100100000110100111100000", 
    182 => "11111000011001011100011000011100", 
    183 => "00011110001001011000011010000111", 
    184 => "10001010100001110111001101000101", 
    185 => "10001101111000111100010001010010", 
    186 => "01100100100110011100101101110010", 
    187 => "10100101010010000100010000011101", 
    188 => "01010111010110010001000110111101", 
    189 => "01000011111111111011001100010000", 
    190 => "01011100100001111011010010001110", 
    191 => "01011000101001000010011011000001", 
    192 => "11001000000111111011001000010010", 
    193 => "11111100010011110101111100010101", 
    194 => "00001110110110110000011100001100", 
    195 => "01011110110110010110000100100001", 
    196 => "10010000111101001001011010011110", 
    197 => "10111011101100110000101111000011", 
    198 => "00001000111000001111010000001000", 
    199 => "10100011011011010001110101010000", 
    200 => "10110101111011000111000001110101", 
    201 => "00111001100100000110011110010011", 
    202 => "01011101000111010001111010101111", 
    203 => "00001000010110101001011001011100", 
    204 => "10001010111110100001101101111100", 
    205 => "11101011101010110001001100000100", 
    206 => "11101111010100001101110100011100", 
    207 => "00101110110000010111011111011010", 
    208 => "01010010000100110010111011111100", 
    209 => "10011010111000100000100101101101", 
    210 => "10011111100000100100000001010101", 
    211 => "10111000011000110000001000000011", 
    212 => "01111001000011001010010011111110", 
    213 => "01010000101101110010111111100110", 
    214 => "10100100101111011101001101111011", 
    215 => "10001010010010000100101111000011", 
    216 => "10011111001010101010011101111010", 
    217 => "11000010101101010101101111100001", 
    218 => "10011000101110010100000001101111", 
    219 => "01100111010011101001110101011001", 
    220 => "01010101000010111011111000001010", 
    221 => "10000011110001100010001111010101", 
    222 => "00110011111011000001011001100100", 
    223 => "00001110110110000101110011011010", 
    224 => "10100011101001110010101011000011", 
    225 => "01110001000111100001001101011101", 
    226 => "01001010000100010010101010000110", 
    227 => "10111001101101111101011001101001", 
    228 => "01101110101000010101001111000110", 
    229 => "01011011000101001000000000101100", 
    230 => "01110011110111011000010010000101", 
    231 => "00110101001111101000001101101111", 
    232 => "01101111110110010110110010011010", 
    233 => "10000110001001011111000100101111", 
    234 => "10011100100111010100101101010100", 
    235 => "11110111001001100111011100101001", 
    236 => "10001001101100010111011111101110", 
    237 => "10011110100010001010100000101111", 
    238 => "11000111001111100001001000110000", 
    239 => "11111001011111111100110110100011", 
    240 => "10000010101100001010111010111010", 
    241 => "11011010110010000101001001111010", 
    242 => "11011010110110110011000011111001", 
    243 => "00010111111010011011100011101000", 
    244 => "01111001001101101111110000100010", 
    245 => "00111100101001010110011100010100", 
    246 => "10111111100110111001111011000010", 
    247 => "01001100110110100110000100110101", 
    248 => "01101010011101110111000100010011", 
    249 => "10000000010011011110101100110000", 
    250 => "00010101001100000111000111010000", 
    251 => "00011000110111011100001001101110", 
    252 => "00111100101111101010101001010101", 
    253 => "01011111000000001001000111110100", 
    254 => "11010101010100001011101110111101", 
    255 => "00101100001001001111001110011101" );


attribute EQUIVALENT_REGISTER_REMOVAL : string;
begin 


memory_access_guard_0: process (addr0) 
begin
      addr0_tmp <= addr0;
--synthesis translate_off
      if (CONV_INTEGER(addr0) > mem_size-1) then
           addr0_tmp <= (others => '0');
      else 
           addr0_tmp <= addr0;
      end if;
--synthesis translate_on
end process;

p_rom_access: process (clk)  
begin 
    if (clk'event and clk = '1') then
        if (ce0 = '1') then 
            q0 <= mem(CONV_INTEGER(addr0_tmp)); 
        end if;
    end if;
end process;

end rtl;


Library IEEE;
use IEEE.std_logic_1164.all;

entity Blowfish_deciphereOg is
    generic (
        DataWidth : INTEGER := 32;
        AddressRange : INTEGER := 256;
        AddressWidth : INTEGER := 8);
    port (
        reset : IN STD_LOGIC;
        clk : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR(AddressWidth - 1 DOWNTO 0);
        ce0 : IN STD_LOGIC;
        q0 : OUT STD_LOGIC_VECTOR(DataWidth - 1 DOWNTO 0));
end entity;

architecture arch of Blowfish_deciphereOg is
    component Blowfish_deciphereOg_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    Blowfish_deciphereOg_rom_U :  component Blowfish_deciphereOg_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


