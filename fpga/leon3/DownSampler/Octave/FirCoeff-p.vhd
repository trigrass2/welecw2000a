------------------------------------------------------------------------
-- Script created table file
------------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
library DSO;
use DSO.Global.all;

package pFirCoeff is
constant cFirCoeff : aInputValues(0 to 128-1) := ( 234, -87, -2969, 12798, 21982, 2123, -2262, 621, 621, -2262, 2123, 21982, 12798, -2969, -87, 234, 110, 155, -1705, 5009, 11481, 2269, -1505, 378, 257, -314, -1234, 7834, 10164, 97, -940, 381, 381, -940, 97, 10164, 7834, -1234, -314, 257, 378, -1505, 2269, 11481, 5009, -1705, 155, 110, -221, 44, 3620, 3279, -148, 0, 0, 0, -286, 285, 3909, 2900, -290, 0, 0, 0, -348, 574, 4137, 2497, -386, 0, 0, 0, -401, 907, 4294, 2083, -438, 0, 0, 0, -439, 1276, 4374, 1671, -454, 0, 0, 0, -454, 1671, 4374, 1276, -439, 0, 0, 0, -438, 2083, 4294, 907, -401, 0, 0, 0, -386, 2497, 4137, 574, -348, 0, 0, 0, -290, 2900, 3909, 285, -286, 0, 0, 0, -148, 3279, 3620, 44, -221, 0, 0, 0);
end;
