begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* CPU data header for xstormy16.  THIS FILE IS MACHINE GENERATED WITH CGEN.  Copyright 1996-2005 Free Software Foundation, Inc.  This file is part of the GNU Binutils and/or GDB, the GNU debugger.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XSTORMY16_CPU_H
end_ifndef

begin_define
define|#
directive|define
name|XSTORMY16_CPU_H
end_define

begin_include
include|#
directive|include
file|"opcode/cgen-bitset.h"
end_include

begin_define
define|#
directive|define
name|CGEN_ARCH
value|xstormy16
end_define

begin_comment
comment|/* Given symbol S, return xstormy16_cgen_<S>.  */
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
value|xstormy16##_cgen_##s
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
value|xstormy16
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
name|HAVE_CPU_XSTORMY16
end_define

begin_define
define|#
directive|define
name|CGEN_INSN_LSB0_P
value|0
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
value|4
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
value|19
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
value|9
end_define

begin_comment
comment|/* Enums.  */
end_comment

begin_comment
comment|/* Enum declaration for .  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|gr_names
block|{
name|H_GR_R0
init|=
literal|0
block|,
name|H_GR_R1
init|=
literal|1
block|,
name|H_GR_R2
init|=
literal|2
block|,
name|H_GR_R3
init|=
literal|3
block|,
name|H_GR_R4
init|=
literal|4
block|,
name|H_GR_R5
init|=
literal|5
block|,
name|H_GR_R6
init|=
literal|6
block|,
name|H_GR_R7
init|=
literal|7
block|,
name|H_GR_R8
init|=
literal|8
block|,
name|H_GR_R9
init|=
literal|9
block|,
name|H_GR_R10
init|=
literal|10
block|,
name|H_GR_R11
init|=
literal|11
block|,
name|H_GR_R12
init|=
literal|12
block|,
name|H_GR_R13
init|=
literal|13
block|,
name|H_GR_R14
init|=
literal|14
block|,
name|H_GR_R15
init|=
literal|15
block|,
name|H_GR_PSW
init|=
literal|14
block|,
name|H_GR_SP
init|=
literal|15
block|}
name|GR_NAMES
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for .  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|gr_rb_names
block|{
name|H_RBJ_R8
init|=
literal|0
block|,
name|H_RBJ_R9
init|=
literal|1
block|,
name|H_RBJ_R10
init|=
literal|2
block|,
name|H_RBJ_R11
init|=
literal|3
block|,
name|H_RBJ_R12
init|=
literal|4
block|,
name|H_RBJ_R13
init|=
literal|5
block|,
name|H_RBJ_R14
init|=
literal|6
block|,
name|H_RBJ_R15
init|=
literal|7
block|,
name|H_RBJ_PSW
init|=
literal|6
block|,
name|H_RBJ_SP
init|=
literal|7
block|}
name|GR_RB_NAMES
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for insn op enums.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|insn_op1
block|{
name|OP1_0
block|,
name|OP1_1
block|,
name|OP1_2
block|,
name|OP1_3
block|,
name|OP1_4
block|,
name|OP1_5
block|,
name|OP1_6
block|,
name|OP1_7
block|,
name|OP1_8
block|,
name|OP1_9
block|,
name|OP1_A
block|,
name|OP1_B
block|,
name|OP1_C
block|,
name|OP1_D
block|,
name|OP1_E
block|,
name|OP1_F
block|}
name|INSN_OP1
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for insn op enums.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|insn_op2
block|{
name|OP2_0
block|,
name|OP2_1
block|,
name|OP2_2
block|,
name|OP2_3
block|,
name|OP2_4
block|,
name|OP2_5
block|,
name|OP2_6
block|,
name|OP2_7
block|,
name|OP2_8
block|,
name|OP2_9
block|,
name|OP2_A
block|,
name|OP2_B
block|,
name|OP2_C
block|,
name|OP2_D
block|,
name|OP2_E
block|,
name|OP2_F
block|}
name|INSN_OP2
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for insn op enums.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|insn_op2a
block|{
name|OP2A_0
block|,
name|OP2A_2
block|,
name|OP2A_4
block|,
name|OP2A_6
block|,
name|OP2A_8
block|,
name|OP2A_A
block|,
name|OP2A_C
block|,
name|OP2A_E
block|}
name|INSN_OP2A
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for insn op enums.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|insn_op2m
block|{
name|OP2M_0
block|,
name|OP2M_1
block|}
name|INSN_OP2M
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for insn op enums.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|insn_op3
block|{
name|OP3_0
block|,
name|OP3_1
block|,
name|OP3_2
block|,
name|OP3_3
block|,
name|OP3_4
block|,
name|OP3_5
block|,
name|OP3_6
block|,
name|OP3_7
block|,
name|OP3_8
block|,
name|OP3_9
block|,
name|OP3_A
block|,
name|OP3_B
block|,
name|OP3_C
block|,
name|OP3_D
block|,
name|OP3_E
block|,
name|OP3_F
block|}
name|INSN_OP3
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for insn op enums.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|insn_op3a
block|{
name|OP3A_0
block|,
name|OP3A_1
block|,
name|OP3A_2
block|,
name|OP3A_3
block|}
name|INSN_OP3A
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for insn op enums.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|insn_op3b
block|{
name|OP3B_0
block|,
name|OP3B_2
block|,
name|OP3B_4
block|,
name|OP3B_6
block|,
name|OP3B_8
block|,
name|OP3B_A
block|,
name|OP3B_C
block|,
name|OP3B_E
block|}
name|INSN_OP3B
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for insn op enums.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|insn_op4
block|{
name|OP4_0
block|,
name|OP4_1
block|,
name|OP4_2
block|,
name|OP4_3
block|,
name|OP4_4
block|,
name|OP4_5
block|,
name|OP4_6
block|,
name|OP4_7
block|,
name|OP4_8
block|,
name|OP4_9
block|,
name|OP4_A
block|,
name|OP4_B
block|,
name|OP4_C
block|,
name|OP4_D
block|,
name|OP4_E
block|,
name|OP4_F
block|}
name|INSN_OP4
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for insn op enums.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|insn_op4m
block|{
name|OP4M_0
block|,
name|OP4M_1
block|}
name|INSN_OP4M
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for insn op enums.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|insn_op4b
block|{
name|OP4B_0
block|,
name|OP4B_1
block|}
name|INSN_OP4B
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for insn op enums.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|insn_op5
block|{
name|OP5_0
block|,
name|OP5_1
block|,
name|OP5_2
block|,
name|OP5_3
block|,
name|OP5_4
block|,
name|OP5_5
block|,
name|OP5_6
block|,
name|OP5_7
block|,
name|OP5_8
block|,
name|OP5_9
block|,
name|OP5_A
block|,
name|OP5_B
block|,
name|OP5_C
block|,
name|OP5_D
block|,
name|OP5_E
block|,
name|OP5_F
block|}
name|INSN_OP5
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for insn op enums.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|insn_op5a
block|{
name|OP5A_0
block|,
name|OP5A_1
block|}
name|INSN_OP5A
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
name|MACH_XSTORMY16
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
name|ISA_XSTORMY16
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
comment|/* cgen_ifld attribute accessor macros.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_IFLD_MACH_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|((attrs)->nonbool[CGEN_IFLD_MACH-CGEN_IFLD_START_NBOOLS-1].nonbitset)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_IFLD_VIRTUAL_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_IFLD_VIRTUAL)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_IFLD_PCREL_ADDR_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_IFLD_PCREL_ADDR)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_IFLD_ABS_ADDR_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_IFLD_ABS_ADDR)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_IFLD_RESERVED_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_IFLD_RESERVED)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_IFLD_SIGN_OPT_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_IFLD_SIGN_OPT)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_IFLD_SIGNED_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_IFLD_SIGNED)) != 0)
end_define

begin_comment
comment|/* Enum declaration for xstormy16 ifield types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|ifield_type
block|{
name|XSTORMY16_F_NIL
block|,
name|XSTORMY16_F_ANYOF
block|,
name|XSTORMY16_F_RD
block|,
name|XSTORMY16_F_RDM
block|,
name|XSTORMY16_F_RM
block|,
name|XSTORMY16_F_RS
block|,
name|XSTORMY16_F_RB
block|,
name|XSTORMY16_F_RBJ
block|,
name|XSTORMY16_F_OP1
block|,
name|XSTORMY16_F_OP2
block|,
name|XSTORMY16_F_OP2A
block|,
name|XSTORMY16_F_OP2M
block|,
name|XSTORMY16_F_OP3
block|,
name|XSTORMY16_F_OP3A
block|,
name|XSTORMY16_F_OP3B
block|,
name|XSTORMY16_F_OP4
block|,
name|XSTORMY16_F_OP4M
block|,
name|XSTORMY16_F_OP4B
block|,
name|XSTORMY16_F_OP5
block|,
name|XSTORMY16_F_OP5A
block|,
name|XSTORMY16_F_OP
block|,
name|XSTORMY16_F_IMM2
block|,
name|XSTORMY16_F_IMM3
block|,
name|XSTORMY16_F_IMM3B
block|,
name|XSTORMY16_F_IMM4
block|,
name|XSTORMY16_F_IMM8
block|,
name|XSTORMY16_F_IMM12
block|,
name|XSTORMY16_F_IMM16
block|,
name|XSTORMY16_F_LMEM8
block|,
name|XSTORMY16_F_HMEM8
block|,
name|XSTORMY16_F_REL8_2
block|,
name|XSTORMY16_F_REL8_4
block|,
name|XSTORMY16_F_REL12
block|,
name|XSTORMY16_F_REL12A
block|,
name|XSTORMY16_F_ABS24_1
block|,
name|XSTORMY16_F_ABS24_2
block|,
name|XSTORMY16_F_ABS24
block|,
name|XSTORMY16_F_MAX
block|}
name|IFIELD_TYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_IFLD
value|((int) XSTORMY16_F_MAX)
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
comment|/* cgen_hw attribute accessor macros.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_HW_MACH_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|((attrs)->nonbool[CGEN_HW_MACH-CGEN_HW_START_NBOOLS-1].nonbitset)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_HW_VIRTUAL_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_HW_VIRTUAL)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_HW_CACHE_ADDR_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_HW_CACHE_ADDR)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_HW_PC_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_HW_PC)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_HW_PROFILE_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_HW_PROFILE)) != 0)
end_define

begin_comment
comment|/* Enum declaration for xstormy16 hardware types.  */
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
name|HW_H_PC
block|,
name|HW_H_GR
block|,
name|HW_H_RB
block|,
name|HW_H_RBJ
block|,
name|HW_H_RPSW
block|,
name|HW_H_Z8
block|,
name|HW_H_Z16
block|,
name|HW_H_CY
block|,
name|HW_H_HC
block|,
name|HW_H_OV
block|,
name|HW_H_PT
block|,
name|HW_H_S
block|,
name|HW_H_BRANCHCOND
block|,
name|HW_H_WORDSIZE
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
comment|/* cgen_operand attribute accessor macros.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_OPERAND_MACH_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|((attrs)->nonbool[CGEN_OPERAND_MACH-CGEN_OPERAND_START_NBOOLS-1].nonbitset)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_OPERAND_VIRTUAL_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_OPERAND_VIRTUAL)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_OPERAND_PCREL_ADDR_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_OPERAND_PCREL_ADDR)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_OPERAND_ABS_ADDR_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_OPERAND_ABS_ADDR)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_OPERAND_SIGN_OPT_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_OPERAND_SIGN_OPT)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_OPERAND_SIGNED_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_OPERAND_SIGNED)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_OPERAND_NEGATIVE_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_OPERAND_NEGATIVE)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_OPERAND_RELAX_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_OPERAND_RELAX)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_OPERAND_SEM_ONLY_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_OPERAND_SEM_ONLY)) != 0)
end_define

begin_comment
comment|/* Enum declaration for xstormy16 operand types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|cgen_operand_type
block|{
name|XSTORMY16_OPERAND_PC
block|,
name|XSTORMY16_OPERAND_PSW_Z8
block|,
name|XSTORMY16_OPERAND_PSW_Z16
block|,
name|XSTORMY16_OPERAND_PSW_CY
block|,
name|XSTORMY16_OPERAND_PSW_HC
block|,
name|XSTORMY16_OPERAND_PSW_OV
block|,
name|XSTORMY16_OPERAND_PSW_PT
block|,
name|XSTORMY16_OPERAND_PSW_S
block|,
name|XSTORMY16_OPERAND_RD
block|,
name|XSTORMY16_OPERAND_RDM
block|,
name|XSTORMY16_OPERAND_RM
block|,
name|XSTORMY16_OPERAND_RS
block|,
name|XSTORMY16_OPERAND_RB
block|,
name|XSTORMY16_OPERAND_RBJ
block|,
name|XSTORMY16_OPERAND_BCOND2
block|,
name|XSTORMY16_OPERAND_WS2
block|,
name|XSTORMY16_OPERAND_BCOND5
block|,
name|XSTORMY16_OPERAND_IMM2
block|,
name|XSTORMY16_OPERAND_IMM3
block|,
name|XSTORMY16_OPERAND_IMM3B
block|,
name|XSTORMY16_OPERAND_IMM4
block|,
name|XSTORMY16_OPERAND_IMM8
block|,
name|XSTORMY16_OPERAND_IMM8SMALL
block|,
name|XSTORMY16_OPERAND_IMM12
block|,
name|XSTORMY16_OPERAND_IMM16
block|,
name|XSTORMY16_OPERAND_LMEM8
block|,
name|XSTORMY16_OPERAND_HMEM8
block|,
name|XSTORMY16_OPERAND_REL8_2
block|,
name|XSTORMY16_OPERAND_REL8_4
block|,
name|XSTORMY16_OPERAND_REL12
block|,
name|XSTORMY16_OPERAND_REL12A
block|,
name|XSTORMY16_OPERAND_ABS24
block|,
name|XSTORMY16_OPERAND_PSW
block|,
name|XSTORMY16_OPERAND_RPSW
block|,
name|XSTORMY16_OPERAND_SP
block|,
name|XSTORMY16_OPERAND_R0
block|,
name|XSTORMY16_OPERAND_R1
block|,
name|XSTORMY16_OPERAND_R2
block|,
name|XSTORMY16_OPERAND_R8
block|,
name|XSTORMY16_OPERAND_MAX
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
value|39
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
comment|/* cgen_insn attribute accessor macros.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_MACH_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|((attrs)->nonbool[CGEN_INSN_MACH-CGEN_INSN_START_NBOOLS-1].nonbitset)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_ALIAS_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_ALIAS)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_VIRTUAL_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_VIRTUAL)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_UNCOND_CTI_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_UNCOND_CTI)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_COND_CTI_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_COND_CTI)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_SKIP_CTI_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_SKIP_CTI)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_DELAY_SLOT_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_DELAY_SLOT)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_RELAXABLE_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_RELAXABLE)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_RELAXED_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_RELAXED)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_NO_DIS_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_NO_DIS)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_PBB_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_PBB)) != 0)
end_define

begin_comment
comment|/* cgen.h uses things we just defined.  */
end_comment

begin_include
include|#
directive|include
file|"opcode/cgen.h"
end_include

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|cgen_ifld
name|xstormy16_cgen_ifld_table
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Attributes.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_ATTR_TABLE
name|xstormy16_cgen_hardware_attr_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_ATTR_TABLE
name|xstormy16_cgen_ifield_attr_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_ATTR_TABLE
name|xstormy16_cgen_operand_attr_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_ATTR_TABLE
name|xstormy16_cgen_insn_attr_table
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hardware decls.  */
end_comment

begin_decl_stmt
specifier|extern
name|CGEN_KEYWORD
name|xstormy16_cgen_opval_gr_names
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CGEN_KEYWORD
name|xstormy16_cgen_opval_gr_Rb_names
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CGEN_KEYWORD
name|xstormy16_cgen_opval_gr_Rb_names
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CGEN_KEYWORD
name|xstormy16_cgen_opval_h_branchcond
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CGEN_KEYWORD
name|xstormy16_cgen_opval_h_wordsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_HW_ENTRY
name|xstormy16_cgen_hw_table
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XSTORMY16_CPU_H */
end_comment

end_unit

