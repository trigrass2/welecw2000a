





-----------------------------------------------------------------------------
-- LEON3 Demonstration design test bench configuration
-- Copyright (C) 2004 Jiri Gaisler, Gaisler Research
--
-- This program is free software; you can redistribute it and/or modify
-- it under the terms of the GNU General Public License as published by
-- the Free Software Foundation; either version 2 of the License, or
-- (at your option) any later version.
--
-- This program is distributed in the hope that it will be useful,
-- but WITHOUT ANY WARRANTY; without even the implied warranty of
-- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
-- GNU General Public License for more details.
------------------------------------------------------------------------------


library techmap;
use techmap.gencomp.all;

package config is

  -----------------------------------------------------------------------------
  -- GLEICHMANN SPECIFIC OPTIONS
  -----------------------------------------------------------------------------

  -- boot prom source
  -- 0: external
  -- 1: internal
  constant CFG_BOOTOPT : integer := 0;

  -- HPE board version
  -- 1: version 1
  -- /= 1: version 2
  constant CFG_HPEVER : integer := 2;

  -- provide ahb signals for an external slave
  -- slave number can be defined below
  -- numbers 8 to 15 can be used safely, numbers below
  -- might be used by other LEON cores depending on configuration
  constant CFG_EXTAHB : integer := 0;

  constant CFG_EXTAHB_ADDR : integer := 16#A00#;

  -- interrupt number the external slave is assigned to
  -- unused at the moment
  constant CFG_EXTAHB_IRQ : integer := 6;

  -- AHB slave number the external slave is assigned to
  constant CFG_EXTAHB_NR : integer := 8;

  -- index number the external slave is assigned to
  constant CFG_EXTAHB_ID : integer := 8;

  -- shift sdram address to bits 12+
  constant CFG_SDSHIFT : integer := 0;

  -----------------------------------------------------------------------------
  -- END GLEICHMANN SPECIFIC OPTIONS
  -----------------------------------------------------------------------------
-- Technology and synthesis options
  constant CFG_FABTECH : integer := altera;
  constant CFG_MEMTECH : integer := altera;
  constant CFG_PADTECH : integer := inferred;
  constant CFG_NOASYNC : integer := 0;
  constant CFG_SCAN : integer := 0;
-- Clock generator
  constant CFG_CLKTECH : integer := altera;
  constant CFG_CLKMUL : integer := (1);
  constant CFG_CLKDIV : integer := (2);
  constant CFG_OCLKDIV : integer := 2;
  constant CFG_PCIDLL : integer := 0;
  constant CFG_PCISYSCLK: integer := 0;
  constant CFG_CLK_NOFB : integer := 0;
-- LEON3 processor core
  constant CFG_LEON3 : integer := 1;
  constant CFG_NCPU : integer := (1);
  constant CFG_NWIN : integer := (8);
  constant CFG_V8 : integer := 2;
  constant CFG_MAC : integer := 0;
  constant CFG_SVT : integer := 0;
  constant CFG_RSTADDR : integer := 16#00000#;
  constant CFG_LDDEL : integer := (1);
  constant CFG_NWP : integer := (0);
  constant CFG_PWD : integer := 0*2;
  constant CFG_FPU : integer := 0 + 16*0;
  constant CFG_GRFPUSH : integer := 0;
  constant CFG_ICEN : integer := 1;
  constant CFG_ISETS : integer := 1;
  constant CFG_ISETSZ : integer := 2;
  constant CFG_ILINE : integer := 8;
  constant CFG_IREPL : integer := 0;
  constant CFG_ILOCK : integer := 0;
  constant CFG_ILRAMEN : integer := 0;
  constant CFG_ILRAMADDR: integer := 16#8E#;
  constant CFG_ILRAMSZ : integer := 1;
  constant CFG_DCEN : integer := 1;
  constant CFG_DSETS : integer := 1;
  constant CFG_DSETSZ : integer := 2;
  constant CFG_DLINE : integer := 8;
  constant CFG_DREPL : integer := 0;
  constant CFG_DLOCK : integer := 0;
  constant CFG_DSNOOP : integer := 0 + 0 + 4*0;
  constant CFG_DFIXED : integer := 16#0#;
  constant CFG_DLRAMEN : integer := 0;
  constant CFG_DLRAMADDR: integer := 16#8F#;
  constant CFG_DLRAMSZ : integer := 1;
  constant CFG_MMUEN : integer := 0;
  constant CFG_ITLBNUM : integer := 2;
  constant CFG_DTLBNUM : integer := 2;
  constant CFG_TLB_TYPE : integer := 1 + 0*2;
  constant CFG_TLB_REP : integer := 1;
  constant CFG_DSU : integer := 1;
  constant CFG_ITBSZ : integer := 1;
  constant CFG_ATBSZ : integer := 0;
  constant CFG_LEON3FT_EN : integer := 0;
  constant CFG_IUFT_EN : integer := 0;
  constant CFG_FPUFT_EN : integer := 0;
  constant CFG_RF_ERRINJ : integer := 0;
  constant CFG_CACHE_FT_EN : integer := 0;
  constant CFG_CACHE_ERRINJ : integer := 0;
  constant CFG_LEON3_NETLIST: integer := 0;
  constant CFG_DISAS : integer := 0 + 0;
  constant CFG_PCLOW : integer := 2;
-- AMBA settings
  constant CFG_DEFMST : integer := (0);
  constant CFG_RROBIN : integer := 0;
  constant CFG_SPLIT : integer := 0;
  constant CFG_AHBIO : integer := 16#FFF#;
  constant CFG_APBADDR : integer := 16#800#;
  constant CFG_AHB_MON : integer := 1;
  constant CFG_AHB_MONERR : integer := 1;
  constant CFG_AHB_MONWAR : integer := 1;
-- DSU UART
  constant CFG_AHB_UART : integer := 1;
-- JTAG based DSU interface
  constant CFG_AHB_JTAG : integer := 0;
-- Ethernet DSU
  constant CFG_DSU_ETH : integer := 0 + 0;
  constant CFG_ETH_BUF : integer := 1;
  constant CFG_ETH_IPM : integer := 16#C0A8#;
  constant CFG_ETH_IPL : integer := 16#0033#;
  constant CFG_ETH_ENM : integer := 16#00007A#;
  constant CFG_ETH_ENL : integer := 16#CC0001#;
-- PROM/SRAM controller
  constant CFG_SRCTRL : integer := 1;
  constant CFG_SRCTRL_PROMWS : integer := (4);
  constant CFG_SRCTRL_RAMWS : integer := (2);
  constant CFG_SRCTRL_IOWS : integer := (2);
  constant CFG_SRCTRL_RMW : integer := 0;
  constant CFG_SRCTRL_8BIT : integer := 0;
  constant CFG_SRCTRL_SRBANKS : integer := 1;
  constant CFG_SRCTRL_BANKSZ : integer := 8;
  constant CFG_SRCTRL_ROMASEL : integer := (19);
-- LEON2 memory controller
  constant CFG_MCTRL_LEON2 : integer := 0;
  constant CFG_MCTRL_RAM8BIT : integer := 0;
  constant CFG_MCTRL_RAM16BIT : integer := 0;
  constant CFG_MCTRL_5CS : integer := 0;
  constant CFG_MCTRL_SDEN : integer := 0;
  constant CFG_MCTRL_SEPBUS : integer := 0;
  constant CFG_MCTRL_INVCLK : integer := 0;
  constant CFG_MCTRL_SD64 : integer := 0;
  constant CFG_MCTRL_PAGE : integer := 0 + 0;
-- AHB ROM
  constant CFG_AHBROMEN : integer := 0;
  constant CFG_AHBROPIP : integer := 0;
  constant CFG_AHBRODDR : integer := 16#000#;
  constant CFG_ROMADDR : integer := 16#000#;
  constant CFG_ROMMASK : integer := 16#E00# + 16#000#;
-- AHB RAM
  constant CFG_AHBRAMEN : integer := 0;
  constant CFG_AHBRSZ : integer := 1;
  constant CFG_AHBRADDR : integer := 16#A00#;
-- Gaisler Ethernet core
  constant CFG_GRETH : integer := 0;
  constant CFG_GRETH1G : integer := 0;
  constant CFG_ETH_FIFO : integer := 8;
-- UART 1
  constant CFG_UART1_ENABLE : integer := 1;
  constant CFG_UART1_FIFO : integer := 1;
-- LEON3 interrupt controller
  constant CFG_IRQ3_ENABLE : integer := 1;
  constant CFG_IRQ3_NSEC : integer := 0;
-- Modular timer
  constant CFG_GPT_ENABLE : integer := 1;
  constant CFG_GPT_NTIM : integer := (2);
  constant CFG_GPT_SW : integer := (8);
  constant CFG_GPT_TW : integer := (32);
  constant CFG_GPT_IRQ : integer := (8);
  constant CFG_GPT_SEPIRQ : integer := 0;
  constant CFG_GPT_WDOGEN : integer := 0;
  constant CFG_GPT_WDOG : integer := 16#0#;
-- ATA interface
  constant CFG_ATA : integer := 0;
  constant CFG_ATAIO : integer := 16#0#;
  constant CFG_ATAIRQ : integer := 0;
  constant CFG_ATADMA : integer := 0;
  constant CFG_ATAFIFO : integer := 8;
-- VGA and PS2/ interface
  constant CFG_KBD_ENABLE : integer := 0;
  constant CFG_VGA_ENABLE : integer := 0;
  constant CFG_SVGA_ENABLE : integer := 1;
-- AHB2HPI enable
  constant CFG_AHB2HPI : integer := 0;
-- DAC_AHB enable
  constant CFG_DAC_AHB : integer := 0;
-- W2000 definitions
  constant CFG_DSO_ENABLE : integer := 1;
  constant CFG_DSO_PLATTFORM : integer := (2022);
  constant CFG_DSO_CHANNELS : integer := (2);
  constant CFG_DSO_SAMPLING_FREQUENCY : integer := (1000000000);
  constant CFG_DSO_INPUT_BIT_WIDTH : integer := (8);
  constant CFG_DSO_TRIGGER_DATA_SIZE : integer := (16);
-- GRLIB debugging
  constant CFG_DUART : integer := 1;
end;
