begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-dependent code for GDB, the GNU debugger.    Copyright 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S390_TDEP_H
end_ifndef

begin_define
define|#
directive|define
name|S390_TDEP_H
end_define

begin_comment
comment|/* Register information.  */
end_comment

begin_comment
comment|/* Program Status Word.  */
end_comment

begin_define
define|#
directive|define
name|S390_PSWM_REGNUM
value|0
end_define

begin_define
define|#
directive|define
name|S390_PSWA_REGNUM
value|1
end_define

begin_comment
comment|/* General Purpose Registers.  */
end_comment

begin_define
define|#
directive|define
name|S390_R0_REGNUM
value|2
end_define

begin_define
define|#
directive|define
name|S390_R1_REGNUM
value|3
end_define

begin_define
define|#
directive|define
name|S390_R2_REGNUM
value|4
end_define

begin_define
define|#
directive|define
name|S390_R3_REGNUM
value|5
end_define

begin_define
define|#
directive|define
name|S390_R4_REGNUM
value|6
end_define

begin_define
define|#
directive|define
name|S390_R5_REGNUM
value|7
end_define

begin_define
define|#
directive|define
name|S390_R6_REGNUM
value|8
end_define

begin_define
define|#
directive|define
name|S390_R7_REGNUM
value|9
end_define

begin_define
define|#
directive|define
name|S390_R8_REGNUM
value|10
end_define

begin_define
define|#
directive|define
name|S390_R9_REGNUM
value|11
end_define

begin_define
define|#
directive|define
name|S390_R10_REGNUM
value|12
end_define

begin_define
define|#
directive|define
name|S390_R11_REGNUM
value|13
end_define

begin_define
define|#
directive|define
name|S390_R12_REGNUM
value|14
end_define

begin_define
define|#
directive|define
name|S390_R13_REGNUM
value|15
end_define

begin_define
define|#
directive|define
name|S390_R14_REGNUM
value|16
end_define

begin_define
define|#
directive|define
name|S390_R15_REGNUM
value|17
end_define

begin_comment
comment|/* Access Registers.  */
end_comment

begin_define
define|#
directive|define
name|S390_A0_REGNUM
value|18
end_define

begin_define
define|#
directive|define
name|S390_A1_REGNUM
value|19
end_define

begin_define
define|#
directive|define
name|S390_A2_REGNUM
value|20
end_define

begin_define
define|#
directive|define
name|S390_A3_REGNUM
value|21
end_define

begin_define
define|#
directive|define
name|S390_A4_REGNUM
value|22
end_define

begin_define
define|#
directive|define
name|S390_A5_REGNUM
value|23
end_define

begin_define
define|#
directive|define
name|S390_A6_REGNUM
value|24
end_define

begin_define
define|#
directive|define
name|S390_A7_REGNUM
value|25
end_define

begin_define
define|#
directive|define
name|S390_A8_REGNUM
value|26
end_define

begin_define
define|#
directive|define
name|S390_A9_REGNUM
value|27
end_define

begin_define
define|#
directive|define
name|S390_A10_REGNUM
value|28
end_define

begin_define
define|#
directive|define
name|S390_A11_REGNUM
value|29
end_define

begin_define
define|#
directive|define
name|S390_A12_REGNUM
value|30
end_define

begin_define
define|#
directive|define
name|S390_A13_REGNUM
value|31
end_define

begin_define
define|#
directive|define
name|S390_A14_REGNUM
value|32
end_define

begin_define
define|#
directive|define
name|S390_A15_REGNUM
value|33
end_define

begin_comment
comment|/* Floating Point Control Word.  */
end_comment

begin_define
define|#
directive|define
name|S390_FPC_REGNUM
value|34
end_define

begin_comment
comment|/* Floating Point Registers.  */
end_comment

begin_define
define|#
directive|define
name|S390_F0_REGNUM
value|35
end_define

begin_define
define|#
directive|define
name|S390_F1_REGNUM
value|36
end_define

begin_define
define|#
directive|define
name|S390_F2_REGNUM
value|37
end_define

begin_define
define|#
directive|define
name|S390_F3_REGNUM
value|38
end_define

begin_define
define|#
directive|define
name|S390_F4_REGNUM
value|39
end_define

begin_define
define|#
directive|define
name|S390_F5_REGNUM
value|40
end_define

begin_define
define|#
directive|define
name|S390_F6_REGNUM
value|41
end_define

begin_define
define|#
directive|define
name|S390_F7_REGNUM
value|42
end_define

begin_define
define|#
directive|define
name|S390_F8_REGNUM
value|43
end_define

begin_define
define|#
directive|define
name|S390_F9_REGNUM
value|44
end_define

begin_define
define|#
directive|define
name|S390_F10_REGNUM
value|45
end_define

begin_define
define|#
directive|define
name|S390_F11_REGNUM
value|46
end_define

begin_define
define|#
directive|define
name|S390_F12_REGNUM
value|47
end_define

begin_define
define|#
directive|define
name|S390_F13_REGNUM
value|48
end_define

begin_define
define|#
directive|define
name|S390_F14_REGNUM
value|49
end_define

begin_define
define|#
directive|define
name|S390_F15_REGNUM
value|50
end_define

begin_comment
comment|/* Total.  */
end_comment

begin_define
define|#
directive|define
name|S390_NUM_REGS
value|51
end_define

begin_comment
comment|/* Pseudo registers -- PC and condition code.  */
end_comment

begin_define
define|#
directive|define
name|S390_PC_REGNUM
value|S390_NUM_REGS
end_define

begin_define
define|#
directive|define
name|S390_CC_REGNUM
value|(S390_NUM_REGS+1)
end_define

begin_define
define|#
directive|define
name|S390_NUM_PSEUDO_REGS
value|2
end_define

begin_define
define|#
directive|define
name|S390_NUM_TOTAL_REGS
value|(S390_NUM_REGS+2)
end_define

begin_comment
comment|/* Special register usage.  */
end_comment

begin_define
define|#
directive|define
name|S390_SP_REGNUM
value|S390_R15_REGNUM
end_define

begin_define
define|#
directive|define
name|S390_RETADDR_REGNUM
value|S390_R14_REGNUM
end_define

begin_define
define|#
directive|define
name|S390_FRAME_REGNUM
value|S390_R11_REGNUM
end_define

begin_comment
comment|/* Core file register sets, defined in s390-tdep.c.  */
end_comment

begin_define
define|#
directive|define
name|s390_sizeof_gregset
value|0x90
end_define

begin_decl_stmt
specifier|extern
name|int
name|s390_regmap_gregset
index|[
name|S390_NUM_REGS
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|s390x_sizeof_gregset
value|0xd8
end_define

begin_decl_stmt
specifier|extern
name|int
name|s390x_regmap_gregset
index|[
name|S390_NUM_REGS
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|s390_sizeof_fpregset
value|0x88
end_define

begin_decl_stmt
specifier|extern
name|int
name|s390_regmap_fpregset
index|[
name|S390_NUM_REGS
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

