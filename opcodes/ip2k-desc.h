begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* CPU data header for ip2k.  THIS FILE IS MACHINE GENERATED WITH CGEN.  Copyright 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.  This file is part of the GNU Binutils and/or GDB, the GNU debugger.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IP2K_CPU_H
end_ifndef

begin_define
define|#
directive|define
name|IP2K_CPU_H
end_define

begin_define
define|#
directive|define
name|CGEN_ARCH
value|ip2k
end_define

begin_comment
comment|/* Given symbol S, return ip2k_cgen_<S>.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|ALMOST_STDC
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_STRINGIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|CGEN_SYM
parameter_list|(
name|s
parameter_list|)
value|ip2k##_cgen_##s
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CGEN_SYM
parameter_list|(
name|s
parameter_list|)
value|ip2k
comment|/**/
value|_cgen_
comment|/**/
value|s
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Selected cpu families.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_CPU_IP2KBF
end_define

begin_define
define|#
directive|define
name|CGEN_INSN_LSB0_P
value|1
end_define

begin_comment
comment|/* Minimum size of any insn (in bytes).  */
end_comment

begin_define
define|#
directive|define
name|CGEN_MIN_INSN_SIZE
value|2
end_define

begin_comment
comment|/* Maximum size of any insn (in bytes).  */
end_comment

begin_define
define|#
directive|define
name|CGEN_MAX_INSN_SIZE
value|2
end_define

begin_define
define|#
directive|define
name|CGEN_INT_INSN_P
value|1
end_define

begin_comment
comment|/* Maximum number of syntax elements in an instruction.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_ACTUAL_MAX_SYNTAX_ELEMENTS
value|12
end_define

begin_comment
comment|/* CGEN_MNEMONIC_OPERANDS is defined if mnemonics have operands.    e.g. In "b,a foo" the ",a" is an operand.  If mnemonics have operands    we can't hash on everything up to the space.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_MNEMONIC_OPERANDS
end_define

begin_comment
comment|/* Maximum number of fields in an instruction.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_ACTUAL_MAX_IFMT_OPERANDS
value|3
end_define

begin_comment
comment|/* Enums.  */
end_comment

begin_comment
comment|/* Enum declaration for op6 enums.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|insn_op6
block|{
name|OP6_OTHER1
block|,
name|OP6_OTHER2
block|,
name|OP6_SUB
block|,
name|OP6_DEC
block|,
name|OP6_OR
block|,
name|OP6_AND
block|,
name|OP6_XOR
block|,
name|OP6_ADD
block|,
name|OP6_TEST
block|,
name|OP6_NOT
block|,
name|OP6_INC
block|,
name|OP6_DECSZ
block|,
name|OP6_RR
block|,
name|OP6_RL
block|,
name|OP6_SWAP
block|,
name|OP6_INCSZ
block|,
name|OP6_CSE
block|,
name|OP6_POP
block|,
name|OP6_SUBC
block|,
name|OP6_DECSNZ
block|,
name|OP6_MULU
block|,
name|OP6_MULS
block|,
name|OP6_INCSNZ
block|,
name|OP6_ADDC
block|}
name|INSN_OP6
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for dir enums.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|insn_dir
block|{
name|DIR_TO_W
block|,
name|DIR_NOTTO_W
block|}
name|INSN_DIR
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for op4 enums.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|insn_op4
block|{
name|OP4_LITERAL
init|=
literal|7
block|,
name|OP4_CLRB
init|=
literal|8
block|,
name|OP4_SETB
init|=
literal|9
block|,
name|OP4_SNB
init|=
literal|10
block|,
name|OP4_SB
init|=
literal|11
block|}
name|INSN_OP4
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for op4mid enums.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|insn_op4mid
block|{
name|OP4MID_LOADH_L
init|=
literal|0
block|,
name|OP4MID_LOADL_L
init|=
literal|1
block|,
name|OP4MID_MULU_L
init|=
literal|2
block|,
name|OP4MID_MULS_L
init|=
literal|3
block|,
name|OP4MID_PUSH_L
init|=
literal|4
block|,
name|OP4MID_CSNE_L
init|=
literal|6
block|,
name|OP4MID_CSE_L
init|=
literal|7
block|,
name|OP4MID_RETW_L
init|=
literal|8
block|,
name|OP4MID_CMP_L
init|=
literal|9
block|,
name|OP4MID_SUB_L
init|=
literal|10
block|,
name|OP4MID_ADD_L
init|=
literal|11
block|,
name|OP4MID_MOV_L
init|=
literal|12
block|,
name|OP4MID_OR_L
init|=
literal|13
block|,
name|OP4MID_AND_L
init|=
literal|14
block|,
name|OP4MID_XOR_L
init|=
literal|15
block|}
name|INSN_OP4MID
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for op3 enums.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|insn_op3
block|{
name|OP3_CALL
init|=
literal|6
block|,
name|OP3_JMP
init|=
literal|7
block|}
name|INSN_OP3
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for .  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|register_names
block|{
name|H_REGISTERS_ADDRSEL
init|=
literal|2
block|,
name|H_REGISTERS_ADDRX
init|=
literal|3
block|,
name|H_REGISTERS_IPH
init|=
literal|4
block|,
name|H_REGISTERS_IPL
init|=
literal|5
block|,
name|H_REGISTERS_SPH
init|=
literal|6
block|,
name|H_REGISTERS_SPL
init|=
literal|7
block|,
name|H_REGISTERS_PCH
init|=
literal|8
block|,
name|H_REGISTERS_PCL
init|=
literal|9
block|,
name|H_REGISTERS_WREG
init|=
literal|10
block|,
name|H_REGISTERS_STATUS
init|=
literal|11
block|,
name|H_REGISTERS_DPH
init|=
literal|12
block|,
name|H_REGISTERS_DPL
init|=
literal|13
block|,
name|H_REGISTERS_SPDREG
init|=
literal|14
block|,
name|H_REGISTERS_MULH
init|=
literal|15
block|,
name|H_REGISTERS_ADDRH
init|=
literal|16
block|,
name|H_REGISTERS_ADDRL
init|=
literal|17
block|,
name|H_REGISTERS_DATAH
init|=
literal|18
block|,
name|H_REGISTERS_DATAL
init|=
literal|19
block|,
name|H_REGISTERS_INTVECH
init|=
literal|20
block|,
name|H_REGISTERS_INTVECL
init|=
literal|21
block|,
name|H_REGISTERS_INTSPD
init|=
literal|22
block|,
name|H_REGISTERS_INTF
init|=
literal|23
block|,
name|H_REGISTERS_INTE
init|=
literal|24
block|,
name|H_REGISTERS_INTED
init|=
literal|25
block|,
name|H_REGISTERS_FCFG
init|=
literal|26
block|,
name|H_REGISTERS_TCTRL
init|=
literal|27
block|,
name|H_REGISTERS_XCFG
init|=
literal|28
block|,
name|H_REGISTERS_EMCFG
init|=
literal|29
block|,
name|H_REGISTERS_IPCH
init|=
literal|30
block|,
name|H_REGISTERS_IPCL
init|=
literal|31
block|,
name|H_REGISTERS_RAIN
init|=
literal|32
block|,
name|H_REGISTERS_RAOUT
init|=
literal|33
block|,
name|H_REGISTERS_RADIR
init|=
literal|34
block|,
name|H_REGISTERS_LFSRH
init|=
literal|35
block|,
name|H_REGISTERS_RBIN
init|=
literal|36
block|,
name|H_REGISTERS_RBOUT
init|=
literal|37
block|,
name|H_REGISTERS_RBDIR
init|=
literal|38
block|,
name|H_REGISTERS_LFSRL
init|=
literal|39
block|,
name|H_REGISTERS_RCIN
init|=
literal|40
block|,
name|H_REGISTERS_RCOUT
init|=
literal|41
block|,
name|H_REGISTERS_RCDIR
init|=
literal|42
block|,
name|H_REGISTERS_LFSRA
init|=
literal|43
block|,
name|H_REGISTERS_RDIN
init|=
literal|44
block|,
name|H_REGISTERS_RDOUT
init|=
literal|45
block|,
name|H_REGISTERS_RDDIR
init|=
literal|46
block|,
name|H_REGISTERS_REIN
init|=
literal|48
block|,
name|H_REGISTERS_REOUT
init|=
literal|49
block|,
name|H_REGISTERS_REDIR
init|=
literal|50
block|,
name|H_REGISTERS_RFIN
init|=
literal|52
block|,
name|H_REGISTERS_RFOUT
init|=
literal|53
block|,
name|H_REGISTERS_RFDIR
init|=
literal|54
block|,
name|H_REGISTERS_RGOUT
init|=
literal|57
block|,
name|H_REGISTERS_RGDIR
init|=
literal|58
block|,
name|H_REGISTERS_RTTMR
init|=
literal|64
block|,
name|H_REGISTERS_RTCFG
init|=
literal|65
block|,
name|H_REGISTERS_T0TMR
init|=
literal|66
block|,
name|H_REGISTERS_T0CFG
init|=
literal|67
block|,
name|H_REGISTERS_T1CNTH
init|=
literal|68
block|,
name|H_REGISTERS_T1CNTL
init|=
literal|69
block|,
name|H_REGISTERS_T1CAP1H
init|=
literal|70
block|,
name|H_REGISTERS_T1CAP1L
init|=
literal|71
block|,
name|H_REGISTERS_T1CAP2H
init|=
literal|72
block|,
name|H_REGISTERS_T1CMP2H
init|=
literal|72
block|,
name|H_REGISTERS_T1CAP2L
init|=
literal|73
block|,
name|H_REGISTERS_T1CMP2L
init|=
literal|73
block|,
name|H_REGISTERS_T1CMP1H
init|=
literal|74
block|,
name|H_REGISTERS_T1CMP1L
init|=
literal|75
block|,
name|H_REGISTERS_T1CFG1H
init|=
literal|76
block|,
name|H_REGISTERS_T1CFG1L
init|=
literal|77
block|,
name|H_REGISTERS_T1CFG2H
init|=
literal|78
block|,
name|H_REGISTERS_T1CFG2L
init|=
literal|79
block|,
name|H_REGISTERS_ADCH
init|=
literal|80
block|,
name|H_REGISTERS_ADCL
init|=
literal|81
block|,
name|H_REGISTERS_ADCCFG
init|=
literal|82
block|,
name|H_REGISTERS_ADCTMR
init|=
literal|83
block|,
name|H_REGISTERS_T2CNTH
init|=
literal|84
block|,
name|H_REGISTERS_T2CNTL
init|=
literal|85
block|,
name|H_REGISTERS_T2CAP1H
init|=
literal|86
block|,
name|H_REGISTERS_T2CAP1L
init|=
literal|87
block|,
name|H_REGISTERS_T2CAP2H
init|=
literal|88
block|,
name|H_REGISTERS_T2CMP2H
init|=
literal|88
block|,
name|H_REGISTERS_T2CAP2L
init|=
literal|89
block|,
name|H_REGISTERS_T2CMP2L
init|=
literal|89
block|,
name|H_REGISTERS_T2CMP1H
init|=
literal|90
block|,
name|H_REGISTERS_T2CMP1L
init|=
literal|91
block|,
name|H_REGISTERS_T2CFG1H
init|=
literal|92
block|,
name|H_REGISTERS_T2CFG1L
init|=
literal|93
block|,
name|H_REGISTERS_T2CFG2H
init|=
literal|94
block|,
name|H_REGISTERS_T2CFG2L
init|=
literal|95
block|,
name|H_REGISTERS_S1TMRH
init|=
literal|96
block|,
name|H_REGISTERS_S1TMRL
init|=
literal|97
block|,
name|H_REGISTERS_S1TBUFH
init|=
literal|98
block|,
name|H_REGISTERS_S1TBUFL
init|=
literal|99
block|,
name|H_REGISTERS_S1TCFG
init|=
literal|100
block|,
name|H_REGISTERS_S1RCNT
init|=
literal|101
block|,
name|H_REGISTERS_S1RBUFH
init|=
literal|102
block|,
name|H_REGISTERS_S1RBUFL
init|=
literal|103
block|,
name|H_REGISTERS_S1RCFG
init|=
literal|104
block|,
name|H_REGISTERS_S1RSYNC
init|=
literal|105
block|,
name|H_REGISTERS_S1INTF
init|=
literal|106
block|,
name|H_REGISTERS_S1INTE
init|=
literal|107
block|,
name|H_REGISTERS_S1MODE
init|=
literal|108
block|,
name|H_REGISTERS_S1SMASK
init|=
literal|109
block|,
name|H_REGISTERS_PSPCFG
init|=
literal|110
block|,
name|H_REGISTERS_CMPCFG
init|=
literal|111
block|,
name|H_REGISTERS_S2TMRH
init|=
literal|112
block|,
name|H_REGISTERS_S2TMRL
init|=
literal|113
block|,
name|H_REGISTERS_S2TBUFH
init|=
literal|114
block|,
name|H_REGISTERS_S2TBUFL
init|=
literal|115
block|,
name|H_REGISTERS_S2TCFG
init|=
literal|116
block|,
name|H_REGISTERS_S2RCNT
init|=
literal|117
block|,
name|H_REGISTERS_S2RBUFH
init|=
literal|118
block|,
name|H_REGISTERS_S2RBUFL
init|=
literal|119
block|,
name|H_REGISTERS_S2RCFG
init|=
literal|120
block|,
name|H_REGISTERS_S2RSYNC
init|=
literal|121
block|,
name|H_REGISTERS_S2INTF
init|=
literal|122
block|,
name|H_REGISTERS_S2INTE
init|=
literal|123
block|,
name|H_REGISTERS_S2MODE
init|=
literal|124
block|,
name|H_REGISTERS_S2SMASK
init|=
literal|125
block|,
name|H_REGISTERS_CALLH
init|=
literal|126
block|,
name|H_REGISTERS_CALLL
init|=
literal|127
block|}
name|REGISTER_NAMES
typedef|;
end_typedef

begin_comment
comment|/* Attributes.  */
end_comment

begin_comment
comment|/* Enum declaration for machine type selection.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|mach_attr
block|{
name|MACH_BASE
block|,
name|MACH_IP2022
block|,
name|MACH_IP2022EXT
block|,
name|MACH_MAX
block|}
name|MACH_ATTR
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for instruction set selection.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|isa_attr
block|{
name|ISA_IP2K
block|,
name|ISA_MAX
block|}
name|ISA_ATTR
typedef|;
end_typedef

begin_comment
comment|/* Number of architecture variants.  */
end_comment

begin_define
define|#
directive|define
name|MAX_ISAS
value|1
end_define

begin_define
define|#
directive|define
name|MAX_MACHS
value|((int) MACH_MAX)
end_define

begin_comment
comment|/* Ifield support.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|cgen_ifld
name|ip2k_cgen_ifld_table
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Ifield attribute indices.  */
end_comment

begin_comment
comment|/* Enum declaration for cgen_ifld attrs.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|cgen_ifld_attr
block|{
name|CGEN_IFLD_VIRTUAL
block|,
name|CGEN_IFLD_PCREL_ADDR
block|,
name|CGEN_IFLD_ABS_ADDR
block|,
name|CGEN_IFLD_RESERVED
block|,
name|CGEN_IFLD_SIGN_OPT
block|,
name|CGEN_IFLD_SIGNED
block|,
name|CGEN_IFLD_END_BOOLS
block|,
name|CGEN_IFLD_START_NBOOLS
init|=
literal|31
block|,
name|CGEN_IFLD_MACH
block|,
name|CGEN_IFLD_END_NBOOLS
block|}
name|CGEN_IFLD_ATTR
typedef|;
end_typedef

begin_comment
comment|/* Number of non-boolean elements in cgen_ifld_attr.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_IFLD_NBOOL_ATTRS
value|(CGEN_IFLD_END_NBOOLS - CGEN_IFLD_START_NBOOLS - 1)
end_define

begin_comment
comment|/* Enum declaration for ip2k ifield types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|ifield_type
block|{
name|IP2K_F_NIL
block|,
name|IP2K_F_ANYOF
block|,
name|IP2K_F_IMM8
block|,
name|IP2K_F_REG
block|,
name|IP2K_F_ADDR16CJP
block|,
name|IP2K_F_DIR
block|,
name|IP2K_F_BITNO
block|,
name|IP2K_F_OP3
block|,
name|IP2K_F_OP4
block|,
name|IP2K_F_OP4MID
block|,
name|IP2K_F_OP6
block|,
name|IP2K_F_OP8
block|,
name|IP2K_F_OP6_10LOW
block|,
name|IP2K_F_OP6_7LOW
block|,
name|IP2K_F_RETI3
block|,
name|IP2K_F_SKIPB
block|,
name|IP2K_F_PAGE3
block|,
name|IP2K_F_MAX
block|}
name|IFIELD_TYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_IFLD
value|((int) IP2K_F_MAX)
end_define

begin_comment
comment|/* Hardware attribute indices.  */
end_comment

begin_comment
comment|/* Enum declaration for cgen_hw attrs.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|cgen_hw_attr
block|{
name|CGEN_HW_VIRTUAL
block|,
name|CGEN_HW_CACHE_ADDR
block|,
name|CGEN_HW_PC
block|,
name|CGEN_HW_PROFILE
block|,
name|CGEN_HW_END_BOOLS
block|,
name|CGEN_HW_START_NBOOLS
init|=
literal|31
block|,
name|CGEN_HW_MACH
block|,
name|CGEN_HW_END_NBOOLS
block|}
name|CGEN_HW_ATTR
typedef|;
end_typedef

begin_comment
comment|/* Number of non-boolean elements in cgen_hw_attr.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_HW_NBOOL_ATTRS
value|(CGEN_HW_END_NBOOLS - CGEN_HW_START_NBOOLS - 1)
end_define

begin_comment
comment|/* Enum declaration for ip2k hardware types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|cgen_hw_type
block|{
name|HW_H_MEMORY
block|,
name|HW_H_SINT
block|,
name|HW_H_UINT
block|,
name|HW_H_ADDR
block|,
name|HW_H_IADDR
block|,
name|HW_H_SPR
block|,
name|HW_H_REGISTERS
block|,
name|HW_H_STACK
block|,
name|HW_H_PABITS
block|,
name|HW_H_ZBIT
block|,
name|HW_H_CBIT
block|,
name|HW_H_DCBIT
block|,
name|HW_H_PC
block|,
name|HW_MAX
block|}
name|CGEN_HW_TYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_HW
value|((int) HW_MAX)
end_define

begin_comment
comment|/* Operand attribute indices.  */
end_comment

begin_comment
comment|/* Enum declaration for cgen_operand attrs.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|cgen_operand_attr
block|{
name|CGEN_OPERAND_VIRTUAL
block|,
name|CGEN_OPERAND_PCREL_ADDR
block|,
name|CGEN_OPERAND_ABS_ADDR
block|,
name|CGEN_OPERAND_SIGN_OPT
block|,
name|CGEN_OPERAND_SIGNED
block|,
name|CGEN_OPERAND_NEGATIVE
block|,
name|CGEN_OPERAND_RELAX
block|,
name|CGEN_OPERAND_SEM_ONLY
block|,
name|CGEN_OPERAND_END_BOOLS
block|,
name|CGEN_OPERAND_START_NBOOLS
init|=
literal|31
block|,
name|CGEN_OPERAND_MACH
block|,
name|CGEN_OPERAND_END_NBOOLS
block|}
name|CGEN_OPERAND_ATTR
typedef|;
end_typedef

begin_comment
comment|/* Number of non-boolean elements in cgen_operand_attr.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_OPERAND_NBOOL_ATTRS
value|(CGEN_OPERAND_END_NBOOLS - CGEN_OPERAND_START_NBOOLS - 1)
end_define

begin_comment
comment|/* Enum declaration for ip2k operand types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|cgen_operand_type
block|{
name|IP2K_OPERAND_PC
block|,
name|IP2K_OPERAND_ADDR16CJP
block|,
name|IP2K_OPERAND_FR
block|,
name|IP2K_OPERAND_LIT8
block|,
name|IP2K_OPERAND_BITNO
block|,
name|IP2K_OPERAND_ADDR16P
block|,
name|IP2K_OPERAND_ADDR16H
block|,
name|IP2K_OPERAND_ADDR16L
block|,
name|IP2K_OPERAND_RETI3
block|,
name|IP2K_OPERAND_PABITS
block|,
name|IP2K_OPERAND_ZBIT
block|,
name|IP2K_OPERAND_CBIT
block|,
name|IP2K_OPERAND_DCBIT
block|,
name|IP2K_OPERAND_MAX
block|}
name|CGEN_OPERAND_TYPE
typedef|;
end_typedef

begin_comment
comment|/* Number of operands types.  */
end_comment

begin_define
define|#
directive|define
name|MAX_OPERANDS
value|13
end_define

begin_comment
comment|/* Maximum number of operands referenced by any insn.  */
end_comment

begin_define
define|#
directive|define
name|MAX_OPERAND_INSTANCES
value|8
end_define

begin_comment
comment|/* Insn attribute indices.  */
end_comment

begin_comment
comment|/* Enum declaration for cgen_insn attrs.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|cgen_insn_attr
block|{
name|CGEN_INSN_ALIAS
block|,
name|CGEN_INSN_VIRTUAL
block|,
name|CGEN_INSN_UNCOND_CTI
block|,
name|CGEN_INSN_COND_CTI
block|,
name|CGEN_INSN_SKIP_CTI
block|,
name|CGEN_INSN_DELAY_SLOT
block|,
name|CGEN_INSN_RELAXABLE
block|,
name|CGEN_INSN_RELAXED
block|,
name|CGEN_INSN_NO_DIS
block|,
name|CGEN_INSN_PBB
block|,
name|CGEN_INSN_EXT_SKIP_INSN
block|,
name|CGEN_INSN_SKIPA
block|,
name|CGEN_INSN_END_BOOLS
block|,
name|CGEN_INSN_START_NBOOLS
init|=
literal|31
block|,
name|CGEN_INSN_MACH
block|,
name|CGEN_INSN_END_NBOOLS
block|}
name|CGEN_INSN_ATTR
typedef|;
end_typedef

begin_comment
comment|/* Number of non-boolean elements in cgen_insn_attr.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_INSN_NBOOL_ATTRS
value|(CGEN_INSN_END_NBOOLS - CGEN_INSN_START_NBOOLS - 1)
end_define

begin_comment
comment|/* cgen.h uses things we just defined.  */
end_comment

begin_include
include|#
directive|include
file|"opcode/cgen.h"
end_include

begin_comment
comment|/* Attributes.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_ATTR_TABLE
name|ip2k_cgen_hardware_attr_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_ATTR_TABLE
name|ip2k_cgen_ifield_attr_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_ATTR_TABLE
name|ip2k_cgen_operand_attr_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_ATTR_TABLE
name|ip2k_cgen_insn_attr_table
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hardware decls.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IP2K_CPU_H */
end_comment

end_unit

