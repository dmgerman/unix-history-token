begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* m68k-parse.h -- header file for m68k assembler    Copyright 1987, 1991, 1992, 1993, 1994, 1995, 1996, 1999, 2000,    2003, 2004, 2005 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|M68K_PARSE_H
end_ifndef

begin_define
define|#
directive|define
name|M68K_PARSE_H
end_define

begin_comment
comment|/* This header file defines things which are shared between the    operand parser in m68k.y and the m68k assembler proper in    tc-m68k.c.  */
end_comment

begin_comment
comment|/* The various m68k registers.  */
end_comment

begin_comment
comment|/* DATA and ADDR have to be contiguous, so that reg-DATA gives    0-7==data reg, 8-15==addr reg for operands that take both types.     We don't use forms like "ADDR0 = ADDR" here because this file is    likely to be used on an Apollo, and the broken Apollo compiler    gives an `undefined variable' error if we do that, according to    troy@cbme.unsw.edu.au.  */
end_comment

begin_define
define|#
directive|define
name|DATA
value|DATA0
end_define

begin_define
define|#
directive|define
name|ADDR
value|ADDR0
end_define

begin_define
define|#
directive|define
name|SP
value|ADDR7
end_define

begin_define
define|#
directive|define
name|BAD
value|BAD0
end_define

begin_define
define|#
directive|define
name|BAC
value|BAC0
end_define

begin_enum
enum|enum
name|m68k_register
block|{
name|DATA0
init|=
literal|1
block|,
comment|/*   1- 8 == data registers 0-7 */
name|DATA1
block|,
name|DATA2
block|,
name|DATA3
block|,
name|DATA4
block|,
name|DATA5
block|,
name|DATA6
block|,
name|DATA7
block|,
name|ADDR0
block|,
name|ADDR1
block|,
name|ADDR2
block|,
name|ADDR3
block|,
name|ADDR4
block|,
name|ADDR5
block|,
name|ADDR6
block|,
name|ADDR7
block|,
name|FP0
block|,
comment|/* Eight FP registers */
name|FP1
block|,
name|FP2
block|,
name|FP3
block|,
name|FP4
block|,
name|FP5
block|,
name|FP6
block|,
name|FP7
block|,
name|COP0
block|,
comment|/* Co-processor #0-#7 */
name|COP1
block|,
name|COP2
block|,
name|COP3
block|,
name|COP4
block|,
name|COP5
block|,
name|COP6
block|,
name|COP7
block|,
name|PC
block|,
comment|/* Program counter */
name|ZPC
block|,
comment|/* Hack for Program space, but 0 addressing */
name|SR
block|,
comment|/* Status Reg */
name|CCR
block|,
comment|/* Condition code Reg */
name|ACC
block|,
comment|/* Accumulator Reg0 (EMAC or ACC on MAC).  */
name|ACC1
block|,
comment|/* Accumulator Reg 1 (EMAC).  */
name|ACC2
block|,
comment|/* Accumulator Reg 2 (EMAC).  */
name|ACC3
block|,
comment|/* Accumulator Reg 3 (EMAC).  */
name|ACCEXT01
block|,
comment|/* Accumulator extension 0&1 (EMAC).  */
name|ACCEXT23
block|,
comment|/* Accumulator extension 2&3 (EMAC).  */
name|MACSR
block|,
comment|/* MAC Status Reg */
name|MASK
block|,
comment|/* Modulus Reg */
comment|/* These have to be grouped together for the movec instruction to work.  */
name|USP
block|,
comment|/*  User Stack Pointer */
name|ISP
block|,
comment|/*  Interrupt stack pointer */
name|SFC
block|,
name|DFC
block|,
name|CACR
block|,
name|VBR
block|,
name|CAAR
block|,
name|MSP
block|,
name|ITT0
block|,
name|ITT1
block|,
name|DTT0
block|,
name|DTT1
block|,
name|MMUSR
block|,
name|TC
block|,
name|SRP
block|,
name|URP
block|,
name|BUSCR
block|,
comment|/* 68060 added these.  */
name|PCR
block|,
name|ROMBAR
block|,
comment|/* mcf5200 added these.  */
name|RAMBAR_ALT
block|,
comment|/* Some CF chips have RAMBAR using 				   RAMBAR0's number */
name|RAMBAR0
block|,
name|RAMBAR1
block|,
name|MMUBAR
block|,
comment|/* mcfv4e added these.  */
name|ROMBAR0
block|,
comment|/* mcfv4e added these.  */
name|ROMBAR1
block|,
comment|/* mcfv4e added these.  */
name|MPCR
block|,
name|EDRAMBAR
block|,
name|SECMBAR
block|,
comment|/* mcfv4e added these.  */
name|PCR1U0
block|,
name|PCR1L0
block|,
name|PCR1U1
block|,
name|PCR1L1
block|,
comment|/* mcfv4e added these.  */
name|PCR2U0
block|,
name|PCR2L0
block|,
name|PCR2U1
block|,
name|PCR2L1
block|,
comment|/* mcfv4e added these.  */
name|PCR3U0
block|,
name|PCR3L0
block|,
name|PCR3U1
block|,
name|PCR3L1
block|,
comment|/* mcfv4e added these.  */
name|MBAR0
block|,
name|MBAR1
block|,
comment|/* mcfv4e added these.  */
name|ACR0
block|,
name|ACR1
block|,
name|ACR2
block|,
name|ACR3
block|,
comment|/* mcf5200 added these.  */
name|FLASHBAR
block|,
name|RAMBAR
block|,
comment|/* mcf528x added these.  */
name|MBAR2
block|,
comment|/* mcf5249 added this.  */
name|MBAR
block|,
name|ASID
block|,
comment|/* m5475.  */
name|CAC
block|,
comment|/* fido added this.  */
name|MBB
block|,
define|#
directive|define
name|last_movec_reg
value|MBB
comment|/* End of movec ordering constraints.  */
name|FPI
block|,
name|FPS
block|,
name|FPC
block|,
name|DRP
block|,
comment|/* 68851 or 68030 MMU regs */
name|CRP
block|,
name|CAL
block|,
name|VAL
block|,
name|SCC
block|,
name|AC
block|,
name|BAD0
block|,
name|BAD1
block|,
name|BAD2
block|,
name|BAD3
block|,
name|BAD4
block|,
name|BAD5
block|,
name|BAD6
block|,
name|BAD7
block|,
name|BAC0
block|,
name|BAC1
block|,
name|BAC2
block|,
name|BAC3
block|,
name|BAC4
block|,
name|BAC5
block|,
name|BAC6
block|,
name|BAC7
block|,
name|PSR
block|,
comment|/* aka MMUSR on 68030 (but not MMUSR on 68040) 				   and ACUSR on 68ec030 */
name|PCSR
block|,
name|IC
block|,
comment|/* instruction cache token */
name|DC
block|,
comment|/* data cache token */
name|NC
block|,
comment|/* no cache token */
name|BC
block|,
comment|/* both caches token */
name|TT0
block|,
comment|/* 68030 access control unit regs */
name|TT1
block|,
name|ZDATA0
block|,
comment|/* suppressed data registers.  */
name|ZDATA1
block|,
name|ZDATA2
block|,
name|ZDATA3
block|,
name|ZDATA4
block|,
name|ZDATA5
block|,
name|ZDATA6
block|,
name|ZDATA7
block|,
name|ZADDR0
block|,
comment|/* suppressed address registers.  */
name|ZADDR1
block|,
name|ZADDR2
block|,
name|ZADDR3
block|,
name|ZADDR4
block|,
name|ZADDR5
block|,
name|ZADDR6
block|,
name|ZADDR7
block|,
comment|/* Upper and lower half of data and address registers.  Order *must*      be DATAxL, ADDRxL, DATAxU, ADDRxU.  */
name|DATA0L
block|,
comment|/* lower half of data registers */
name|DATA1L
block|,
name|DATA2L
block|,
name|DATA3L
block|,
name|DATA4L
block|,
name|DATA5L
block|,
name|DATA6L
block|,
name|DATA7L
block|,
name|ADDR0L
block|,
comment|/* lower half of address registers */
name|ADDR1L
block|,
name|ADDR2L
block|,
name|ADDR3L
block|,
name|ADDR4L
block|,
name|ADDR5L
block|,
name|ADDR6L
block|,
name|ADDR7L
block|,
name|DATA0U
block|,
comment|/* upper half of data registers */
name|DATA1U
block|,
name|DATA2U
block|,
name|DATA3U
block|,
name|DATA4U
block|,
name|DATA5U
block|,
name|DATA6U
block|,
name|DATA7U
block|,
name|ADDR0U
block|,
comment|/* upper half of address registers */
name|ADDR1U
block|,
name|ADDR2U
block|,
name|ADDR3U
block|,
name|ADDR4U
block|,
name|ADDR5U
block|,
name|ADDR6U
block|,
name|ADDR7U
block|, }
enum|;
end_enum

begin_comment
comment|/* Size information.  */
end_comment

begin_enum
enum|enum
name|m68k_size
block|{
comment|/* Unspecified.  */
name|SIZE_UNSPEC
block|,
comment|/* Byte.  */
name|SIZE_BYTE
block|,
comment|/* Word (2 bytes).  */
name|SIZE_WORD
block|,
comment|/* Longword (4 bytes).  */
name|SIZE_LONG
block|}
enum|;
end_enum

begin_comment
comment|/* The structure used to hold information about an index register.  */
end_comment

begin_struct
struct|struct
name|m68k_indexreg
block|{
comment|/* The index register itself.  */
name|enum
name|m68k_register
name|reg
decl_stmt|;
comment|/* The size to use.  */
name|enum
name|m68k_size
name|size
decl_stmt|;
comment|/* The value to scale by.  */
name|int
name|scale
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_ELF
end_ifdef

begin_comment
comment|/* The type of a PIC expression.  */
end_comment

begin_enum
enum|enum
name|pic_relocation
block|{
name|pic_none
block|,
comment|/* not pic */
name|pic_plt_pcrel
block|,
comment|/* @PLTPC */
name|pic_got_pcrel
block|,
comment|/* @GOTPC */
name|pic_plt_off
block|,
comment|/* @PLT */
name|pic_got_off
comment|/* @GOT */
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The structure used to hold information about an expression.  */
end_comment

begin_struct
struct|struct
name|m68k_exp
block|{
comment|/* The size to use.  */
name|enum
name|m68k_size
name|size
decl_stmt|;
ifdef|#
directive|ifdef
name|OBJ_ELF
comment|/* The type of pic relocation if any.  */
name|enum
name|pic_relocation
name|pic_reloc
decl_stmt|;
endif|#
directive|endif
comment|/* The expression itself.  */
name|expressionS
name|exp
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The operand modes.  */
end_comment

begin_enum
enum|enum
name|m68k_operand_type
block|{
name|IMMED
init|=
literal|1
block|,
name|ABSL
block|,
name|DREG
block|,
name|AREG
block|,
name|FPREG
block|,
name|CONTROL
block|,
name|AINDR
block|,
name|AINC
block|,
name|ADEC
block|,
name|DISP
block|,
name|BASE
block|,
name|POST
block|,
name|PRE
block|,
name|LSH
block|,
comment|/* MAC/EMAC scalefactor '<<'.  */
name|RSH
block|,
comment|/* MAC/EMAC scalefactor '>>'.  */
name|REGLST
block|}
enum|;
end_enum

begin_comment
comment|/* The structure used to hold a parsed operand.  */
end_comment

begin_struct
struct|struct
name|m68k_op
block|{
comment|/* The type of operand.  */
name|enum
name|m68k_operand_type
name|mode
decl_stmt|;
comment|/* The main register.  */
name|enum
name|m68k_register
name|reg
decl_stmt|;
comment|/* The register mask for mode REGLST.  */
name|unsigned
name|long
name|mask
decl_stmt|;
comment|/* An error message.  */
specifier|const
name|char
modifier|*
name|error
decl_stmt|;
comment|/* The index register.  */
name|struct
name|m68k_indexreg
name|index
decl_stmt|;
comment|/* The displacement.  */
name|struct
name|m68k_exp
name|disp
decl_stmt|;
comment|/* The outer displacement.  */
name|struct
name|m68k_exp
name|odisp
decl_stmt|;
comment|/* Is a trailing '&' added to an<ea>? (for MAC/EMAC mask addressing).  */
name|int
name|trailing_ampersand
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (M68K_PARSE_H) */
end_comment

begin_comment
comment|/* The parsing function.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|m68k_ip_op
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|m68k_op
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Whether register prefixes are optional.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_reg_prefix_optional
decl_stmt|;
end_decl_stmt

end_unit

