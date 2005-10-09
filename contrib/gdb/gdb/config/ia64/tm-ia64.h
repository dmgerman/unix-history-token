begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to target GDB to GNU/Linux on an ia64 architecture.    Copyright 1992, 1993, 2000 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_IA64_H
end_ifndef

begin_define
define|#
directive|define
name|TM_IA64_H
end_define

begin_define
define|#
directive|define
name|GDB_MULTI_ARCH
value|1
end_define

begin_comment
comment|/* Register numbers of various important registers */
end_comment

begin_comment
comment|/* General registers; there are 128 of these 64 bit wide registers.  The    first 32 are static and the last 96 are stacked. */
end_comment

begin_define
define|#
directive|define
name|IA64_GR0_REGNUM
value|0
end_define

begin_define
define|#
directive|define
name|IA64_GR1_REGNUM
value|(IA64_GR0_REGNUM+1)
end_define

begin_define
define|#
directive|define
name|IA64_GR2_REGNUM
value|(IA64_GR0_REGNUM+2)
end_define

begin_define
define|#
directive|define
name|IA64_GR3_REGNUM
value|(IA64_GR0_REGNUM+3)
end_define

begin_define
define|#
directive|define
name|IA64_GR4_REGNUM
value|(IA64_GR0_REGNUM+4)
end_define

begin_define
define|#
directive|define
name|IA64_GR5_REGNUM
value|(IA64_GR0_REGNUM+5)
end_define

begin_define
define|#
directive|define
name|IA64_GR6_REGNUM
value|(IA64_GR0_REGNUM+6)
end_define

begin_define
define|#
directive|define
name|IA64_GR7_REGNUM
value|(IA64_GR0_REGNUM+7)
end_define

begin_define
define|#
directive|define
name|IA64_GR8_REGNUM
value|(IA64_GR0_REGNUM+8)
end_define

begin_define
define|#
directive|define
name|IA64_GR9_REGNUM
value|(IA64_GR0_REGNUM+9)
end_define

begin_define
define|#
directive|define
name|IA64_GR10_REGNUM
value|(IA64_GR0_REGNUM+10)
end_define

begin_define
define|#
directive|define
name|IA64_GR11_REGNUM
value|(IA64_GR0_REGNUM+11)
end_define

begin_define
define|#
directive|define
name|IA64_GR12_REGNUM
value|(IA64_GR0_REGNUM+12)
end_define

begin_define
define|#
directive|define
name|IA64_GR31_REGNUM
value|(IA64_GR0_REGNUM+31)
end_define

begin_define
define|#
directive|define
name|IA64_GR32_REGNUM
value|(IA64_GR0_REGNUM+32)
end_define

begin_define
define|#
directive|define
name|IA64_GR127_REGNUM
value|(IA64_GR0_REGNUM+127)
end_define

begin_comment
comment|/* Floating point registers; 128 82-bit wide registers */
end_comment

begin_define
define|#
directive|define
name|IA64_FR0_REGNUM
value|128
end_define

begin_define
define|#
directive|define
name|IA64_FR1_REGNUM
value|(IA64_FR0_REGNUM+1)
end_define

begin_define
define|#
directive|define
name|IA64_FR2_REGNUM
value|(IA64_FR0_REGNUM+2)
end_define

begin_define
define|#
directive|define
name|IA64_FR8_REGNUM
value|(IA64_FR0_REGNUM+8)
end_define

begin_define
define|#
directive|define
name|IA64_FR9_REGNUM
value|(IA64_FR0_REGNUM+9)
end_define

begin_define
define|#
directive|define
name|IA64_FR10_REGNUM
value|(IA64_FR0_REGNUM+10)
end_define

begin_define
define|#
directive|define
name|IA64_FR11_REGNUM
value|(IA64_FR0_REGNUM+11)
end_define

begin_define
define|#
directive|define
name|IA64_FR12_REGNUM
value|(IA64_FR0_REGNUM+12)
end_define

begin_define
define|#
directive|define
name|IA64_FR13_REGNUM
value|(IA64_FR0_REGNUM+13)
end_define

begin_define
define|#
directive|define
name|IA64_FR14_REGNUM
value|(IA64_FR0_REGNUM+14)
end_define

begin_define
define|#
directive|define
name|IA64_FR15_REGNUM
value|(IA64_FR0_REGNUM+15)
end_define

begin_define
define|#
directive|define
name|IA64_FR16_REGNUM
value|(IA64_FR0_REGNUM+16)
end_define

begin_define
define|#
directive|define
name|IA64_FR31_REGNUM
value|(IA64_FR0_REGNUM+31)
end_define

begin_define
define|#
directive|define
name|IA64_FR32_REGNUM
value|(IA64_FR0_REGNUM+32)
end_define

begin_define
define|#
directive|define
name|IA64_FR127_REGNUM
value|(IA64_FR0_REGNUM+127)
end_define

begin_comment
comment|/* Predicate registers; There are 64 of these one bit registers.    It'd be more convenient (implementation-wise) to use a single    64 bit word with all of these register in them.  Note that there's    also a IA64_PR_REGNUM below which contains all the bits and is used for    communicating the actual values to the target. */
end_comment

begin_define
define|#
directive|define
name|IA64_PR0_REGNUM
value|256
end_define

begin_define
define|#
directive|define
name|IA64_PR1_REGNUM
value|(IA64_PR0_REGNUM+1)
end_define

begin_define
define|#
directive|define
name|IA64_PR2_REGNUM
value|(IA64_PR0_REGNUM+2)
end_define

begin_define
define|#
directive|define
name|IA64_PR3_REGNUM
value|(IA64_PR0_REGNUM+3)
end_define

begin_define
define|#
directive|define
name|IA64_PR4_REGNUM
value|(IA64_PR0_REGNUM+4)
end_define

begin_define
define|#
directive|define
name|IA64_PR5_REGNUM
value|(IA64_PR0_REGNUM+5)
end_define

begin_define
define|#
directive|define
name|IA64_PR6_REGNUM
value|(IA64_PR0_REGNUM+6)
end_define

begin_define
define|#
directive|define
name|IA64_PR7_REGNUM
value|(IA64_PR0_REGNUM+7)
end_define

begin_define
define|#
directive|define
name|IA64_PR8_REGNUM
value|(IA64_PR0_REGNUM+8)
end_define

begin_define
define|#
directive|define
name|IA64_PR9_REGNUM
value|(IA64_PR0_REGNUM+9)
end_define

begin_define
define|#
directive|define
name|IA64_PR10_REGNUM
value|(IA64_PR0_REGNUM+10)
end_define

begin_define
define|#
directive|define
name|IA64_PR11_REGNUM
value|(IA64_PR0_REGNUM+11)
end_define

begin_define
define|#
directive|define
name|IA64_PR12_REGNUM
value|(IA64_PR0_REGNUM+12)
end_define

begin_define
define|#
directive|define
name|IA64_PR13_REGNUM
value|(IA64_PR0_REGNUM+13)
end_define

begin_define
define|#
directive|define
name|IA64_PR14_REGNUM
value|(IA64_PR0_REGNUM+14)
end_define

begin_define
define|#
directive|define
name|IA64_PR15_REGNUM
value|(IA64_PR0_REGNUM+15)
end_define

begin_define
define|#
directive|define
name|IA64_PR16_REGNUM
value|(IA64_PR0_REGNUM+16)
end_define

begin_define
define|#
directive|define
name|IA64_PR17_REGNUM
value|(IA64_PR0_REGNUM+17)
end_define

begin_define
define|#
directive|define
name|IA64_PR18_REGNUM
value|(IA64_PR0_REGNUM+18)
end_define

begin_define
define|#
directive|define
name|IA64_PR19_REGNUM
value|(IA64_PR0_REGNUM+19)
end_define

begin_define
define|#
directive|define
name|IA64_PR20_REGNUM
value|(IA64_PR0_REGNUM+20)
end_define

begin_define
define|#
directive|define
name|IA64_PR21_REGNUM
value|(IA64_PR0_REGNUM+21)
end_define

begin_define
define|#
directive|define
name|IA64_PR22_REGNUM
value|(IA64_PR0_REGNUM+22)
end_define

begin_define
define|#
directive|define
name|IA64_PR23_REGNUM
value|(IA64_PR0_REGNUM+23)
end_define

begin_define
define|#
directive|define
name|IA64_PR24_REGNUM
value|(IA64_PR0_REGNUM+24)
end_define

begin_define
define|#
directive|define
name|IA64_PR25_REGNUM
value|(IA64_PR0_REGNUM+25)
end_define

begin_define
define|#
directive|define
name|IA64_PR26_REGNUM
value|(IA64_PR0_REGNUM+26)
end_define

begin_define
define|#
directive|define
name|IA64_PR27_REGNUM
value|(IA64_PR0_REGNUM+27)
end_define

begin_define
define|#
directive|define
name|IA64_PR28_REGNUM
value|(IA64_PR0_REGNUM+28)
end_define

begin_define
define|#
directive|define
name|IA64_PR29_REGNUM
value|(IA64_PR0_REGNUM+29)
end_define

begin_define
define|#
directive|define
name|IA64_PR30_REGNUM
value|(IA64_PR0_REGNUM+30)
end_define

begin_define
define|#
directive|define
name|IA64_PR31_REGNUM
value|(IA64_PR0_REGNUM+31)
end_define

begin_define
define|#
directive|define
name|IA64_PR32_REGNUM
value|(IA64_PR0_REGNUM+32)
end_define

begin_define
define|#
directive|define
name|IA64_PR33_REGNUM
value|(IA64_PR0_REGNUM+33)
end_define

begin_define
define|#
directive|define
name|IA64_PR34_REGNUM
value|(IA64_PR0_REGNUM+34)
end_define

begin_define
define|#
directive|define
name|IA64_PR35_REGNUM
value|(IA64_PR0_REGNUM+35)
end_define

begin_define
define|#
directive|define
name|IA64_PR36_REGNUM
value|(IA64_PR0_REGNUM+36)
end_define

begin_define
define|#
directive|define
name|IA64_PR37_REGNUM
value|(IA64_PR0_REGNUM+37)
end_define

begin_define
define|#
directive|define
name|IA64_PR38_REGNUM
value|(IA64_PR0_REGNUM+38)
end_define

begin_define
define|#
directive|define
name|IA64_PR39_REGNUM
value|(IA64_PR0_REGNUM+39)
end_define

begin_define
define|#
directive|define
name|IA64_PR40_REGNUM
value|(IA64_PR0_REGNUM+40)
end_define

begin_define
define|#
directive|define
name|IA64_PR41_REGNUM
value|(IA64_PR0_REGNUM+41)
end_define

begin_define
define|#
directive|define
name|IA64_PR42_REGNUM
value|(IA64_PR0_REGNUM+42)
end_define

begin_define
define|#
directive|define
name|IA64_PR43_REGNUM
value|(IA64_PR0_REGNUM+43)
end_define

begin_define
define|#
directive|define
name|IA64_PR44_REGNUM
value|(IA64_PR0_REGNUM+44)
end_define

begin_define
define|#
directive|define
name|IA64_PR45_REGNUM
value|(IA64_PR0_REGNUM+45)
end_define

begin_define
define|#
directive|define
name|IA64_PR46_REGNUM
value|(IA64_PR0_REGNUM+46)
end_define

begin_define
define|#
directive|define
name|IA64_PR47_REGNUM
value|(IA64_PR0_REGNUM+47)
end_define

begin_define
define|#
directive|define
name|IA64_PR48_REGNUM
value|(IA64_PR0_REGNUM+48)
end_define

begin_define
define|#
directive|define
name|IA64_PR49_REGNUM
value|(IA64_PR0_REGNUM+49)
end_define

begin_define
define|#
directive|define
name|IA64_PR50_REGNUM
value|(IA64_PR0_REGNUM+50)
end_define

begin_define
define|#
directive|define
name|IA64_PR51_REGNUM
value|(IA64_PR0_REGNUM+51)
end_define

begin_define
define|#
directive|define
name|IA64_PR52_REGNUM
value|(IA64_PR0_REGNUM+52)
end_define

begin_define
define|#
directive|define
name|IA64_PR53_REGNUM
value|(IA64_PR0_REGNUM+53)
end_define

begin_define
define|#
directive|define
name|IA64_PR54_REGNUM
value|(IA64_PR0_REGNUM+54)
end_define

begin_define
define|#
directive|define
name|IA64_PR55_REGNUM
value|(IA64_PR0_REGNUM+55)
end_define

begin_define
define|#
directive|define
name|IA64_PR56_REGNUM
value|(IA64_PR0_REGNUM+56)
end_define

begin_define
define|#
directive|define
name|IA64_PR57_REGNUM
value|(IA64_PR0_REGNUM+57)
end_define

begin_define
define|#
directive|define
name|IA64_PR58_REGNUM
value|(IA64_PR0_REGNUM+58)
end_define

begin_define
define|#
directive|define
name|IA64_PR59_REGNUM
value|(IA64_PR0_REGNUM+59)
end_define

begin_define
define|#
directive|define
name|IA64_PR60_REGNUM
value|(IA64_PR0_REGNUM+60)
end_define

begin_define
define|#
directive|define
name|IA64_PR61_REGNUM
value|(IA64_PR0_REGNUM+61)
end_define

begin_define
define|#
directive|define
name|IA64_PR62_REGNUM
value|(IA64_PR0_REGNUM+62)
end_define

begin_define
define|#
directive|define
name|IA64_PR63_REGNUM
value|(IA64_PR0_REGNUM+63)
end_define

begin_comment
comment|/* Branch registers: 8 64-bit registers for holding branch targets */
end_comment

begin_define
define|#
directive|define
name|IA64_BR0_REGNUM
value|320
end_define

begin_define
define|#
directive|define
name|IA64_BR1_REGNUM
value|(IA64_BR0_REGNUM+1)
end_define

begin_define
define|#
directive|define
name|IA64_BR2_REGNUM
value|(IA64_BR0_REGNUM+2)
end_define

begin_define
define|#
directive|define
name|IA64_BR3_REGNUM
value|(IA64_BR0_REGNUM+3)
end_define

begin_define
define|#
directive|define
name|IA64_BR4_REGNUM
value|(IA64_BR0_REGNUM+4)
end_define

begin_define
define|#
directive|define
name|IA64_BR5_REGNUM
value|(IA64_BR0_REGNUM+5)
end_define

begin_define
define|#
directive|define
name|IA64_BR6_REGNUM
value|(IA64_BR0_REGNUM+6)
end_define

begin_define
define|#
directive|define
name|IA64_BR7_REGNUM
value|(IA64_BR0_REGNUM+7)
end_define

begin_comment
comment|/* Virtual frame pointer; this matches IA64_FRAME_POINTER_REGNUM in    gcc/config/ia64/ia64.h. */
end_comment

begin_define
define|#
directive|define
name|IA64_VFP_REGNUM
value|328
end_define

begin_comment
comment|/* Virtual return address pointer; this matches IA64_RETURN_ADDRESS_POINTER_REGNUM    in gcc/config/ia64/ia64.h. */
end_comment

begin_define
define|#
directive|define
name|IA64_VRAP_REGNUM
value|329
end_define

begin_comment
comment|/* Predicate registers: There are 64 of these 1-bit registers.  We    define a single register which is used to communicate these values    to/from the target.  We will somehow contrive to make it appear that    IA64_PR0_REGNUM thru IA64_PR63_REGNUM hold the actual values. */
end_comment

begin_define
define|#
directive|define
name|IA64_PR_REGNUM
value|330
end_define

begin_comment
comment|/* Instruction pointer: 64 bits wide */
end_comment

begin_define
define|#
directive|define
name|IA64_IP_REGNUM
value|331
end_define

begin_comment
comment|/* Process Status Register */
end_comment

begin_define
define|#
directive|define
name|IA64_PSR_REGNUM
value|332
end_define

begin_comment
comment|/* Current Frame Marker (Raw form may be the cr.ifs) */
end_comment

begin_define
define|#
directive|define
name|IA64_CFM_REGNUM
value|333
end_define

begin_comment
comment|/* Application registers; 128 64-bit wide registers possible, but some   of them are reserved */
end_comment

begin_define
define|#
directive|define
name|IA64_AR0_REGNUM
value|334
end_define

begin_define
define|#
directive|define
name|IA64_KR0_REGNUM
value|(IA64_AR0_REGNUM+0)
end_define

begin_define
define|#
directive|define
name|IA64_KR7_REGNUM
value|(IA64_KR0_REGNUM+7)
end_define

begin_define
define|#
directive|define
name|IA64_RSC_REGNUM
value|(IA64_AR0_REGNUM+16)
end_define

begin_define
define|#
directive|define
name|IA64_BSP_REGNUM
value|(IA64_AR0_REGNUM+17)
end_define

begin_define
define|#
directive|define
name|IA64_BSPSTORE_REGNUM
value|(IA64_AR0_REGNUM+18)
end_define

begin_define
define|#
directive|define
name|IA64_RNAT_REGNUM
value|(IA64_AR0_REGNUM+19)
end_define

begin_define
define|#
directive|define
name|IA64_FCR_REGNUM
value|(IA64_AR0_REGNUM+21)
end_define

begin_define
define|#
directive|define
name|IA64_EFLAG_REGNUM
value|(IA64_AR0_REGNUM+24)
end_define

begin_define
define|#
directive|define
name|IA64_CSD_REGNUM
value|(IA64_AR0_REGNUM+25)
end_define

begin_define
define|#
directive|define
name|IA64_SSD_REGNUM
value|(IA64_AR0_REGNUM+26)
end_define

begin_define
define|#
directive|define
name|IA64_CFLG_REGNUM
value|(IA64_AR0_REGNUM+27)
end_define

begin_define
define|#
directive|define
name|IA64_FSR_REGNUM
value|(IA64_AR0_REGNUM+28)
end_define

begin_define
define|#
directive|define
name|IA64_FIR_REGNUM
value|(IA64_AR0_REGNUM+29)
end_define

begin_define
define|#
directive|define
name|IA64_FDR_REGNUM
value|(IA64_AR0_REGNUM+30)
end_define

begin_define
define|#
directive|define
name|IA64_CCV_REGNUM
value|(IA64_AR0_REGNUM+32)
end_define

begin_define
define|#
directive|define
name|IA64_UNAT_REGNUM
value|(IA64_AR0_REGNUM+36)
end_define

begin_define
define|#
directive|define
name|IA64_FPSR_REGNUM
value|(IA64_AR0_REGNUM+40)
end_define

begin_define
define|#
directive|define
name|IA64_ITC_REGNUM
value|(IA64_AR0_REGNUM+44)
end_define

begin_define
define|#
directive|define
name|IA64_PFS_REGNUM
value|(IA64_AR0_REGNUM+64)
end_define

begin_define
define|#
directive|define
name|IA64_LC_REGNUM
value|(IA64_AR0_REGNUM+65)
end_define

begin_define
define|#
directive|define
name|IA64_EC_REGNUM
value|(IA64_AR0_REGNUM+66)
end_define

begin_comment
comment|/* NAT (Not A Thing) Bits for the general registers; there are 128 of these */
end_comment

begin_define
define|#
directive|define
name|IA64_NAT0_REGNUM
value|462
end_define

begin_define
define|#
directive|define
name|IA64_NAT31_REGNUM
value|(IA64_NAT0_REGNUM+31)
end_define

begin_define
define|#
directive|define
name|IA64_NAT32_REGNUM
value|(IA64_NAT0_REGNUM+32)
end_define

begin_define
define|#
directive|define
name|IA64_NAT127_REGNUM
value|(IA64_NAT0_REGNUM+127)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TM_IA64_H */
end_comment

end_unit

