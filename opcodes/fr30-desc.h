begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* CPU data header for fr30.  THIS FILE IS MACHINE GENERATED WITH CGEN.  Copyright 1996-2005 Free Software Foundation, Inc.  This file is part of the GNU Binutils and/or GDB, the GNU debugger.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FR30_CPU_H
end_ifndef

begin_define
define|#
directive|define
name|FR30_CPU_H
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
value|fr30
end_define

begin_comment
comment|/* Given symbol S, return fr30_cgen_<S>.  */
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
value|fr30##_cgen_##s
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
value|fr30
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
name|HAVE_CPU_FR30BF
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
value|6
end_define

begin_define
define|#
directive|define
name|CGEN_INT_INSN_P
value|0
end_define

begin_comment
comment|/* Maximum number of syntax elements in an instruction.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_ACTUAL_MAX_SYNTAX_ELEMENTS
value|15
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
value|7
end_define

begin_comment
comment|/* Enums.  */
end_comment

begin_comment
comment|/* Enum declaration for insn op1 enums.  */
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
comment|/* Enum declaration for insn op2 enums.  */
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
comment|/* Enum declaration for insn op3 enums.  */
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
comment|/* Enum declaration for insn op4 enums.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|insn_op4
block|{
name|OP4_0
block|}
name|INSN_OP4
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for insn op5 enums.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|insn_op5
block|{
name|OP5_0
block|,
name|OP5_1
block|}
name|INSN_OP5
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for insn cc enums.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|insn_cc
block|{
name|CC_RA
block|,
name|CC_NO
block|,
name|CC_EQ
block|,
name|CC_NE
block|,
name|CC_C
block|,
name|CC_NC
block|,
name|CC_N
block|,
name|CC_P
block|,
name|CC_V
block|,
name|CC_NV
block|,
name|CC_LT
block|,
name|CC_GE
block|,
name|CC_LE
block|,
name|CC_GT
block|,
name|CC_LS
block|,
name|CC_HI
block|}
name|INSN_CC
typedef|;
end_typedef

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
name|H_GR_AC
init|=
literal|13
block|,
name|H_GR_FP
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
name|cr_names
block|{
name|H_CR_CR0
block|,
name|H_CR_CR1
block|,
name|H_CR_CR2
block|,
name|H_CR_CR3
block|,
name|H_CR_CR4
block|,
name|H_CR_CR5
block|,
name|H_CR_CR6
block|,
name|H_CR_CR7
block|,
name|H_CR_CR8
block|,
name|H_CR_CR9
block|,
name|H_CR_CR10
block|,
name|H_CR_CR11
block|,
name|H_CR_CR12
block|,
name|H_CR_CR13
block|,
name|H_CR_CR14
block|,
name|H_CR_CR15
block|}
name|CR_NAMES
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for .  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|dr_names
block|{
name|H_DR_TBR
block|,
name|H_DR_RP
block|,
name|H_DR_SSP
block|,
name|H_DR_USP
block|,
name|H_DR_MDH
block|,
name|H_DR_MDL
block|}
name|DR_NAMES
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
name|MACH_FR30
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
name|ISA_FR30
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
comment|/* Enum declaration for fr30 ifield types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|ifield_type
block|{
name|FR30_F_NIL
block|,
name|FR30_F_ANYOF
block|,
name|FR30_F_OP1
block|,
name|FR30_F_OP2
block|,
name|FR30_F_OP3
block|,
name|FR30_F_OP4
block|,
name|FR30_F_OP5
block|,
name|FR30_F_CC
block|,
name|FR30_F_CCC
block|,
name|FR30_F_RJ
block|,
name|FR30_F_RI
block|,
name|FR30_F_RS1
block|,
name|FR30_F_RS2
block|,
name|FR30_F_RJC
block|,
name|FR30_F_RIC
block|,
name|FR30_F_CRJ
block|,
name|FR30_F_CRI
block|,
name|FR30_F_U4
block|,
name|FR30_F_U4C
block|,
name|FR30_F_I4
block|,
name|FR30_F_M4
block|,
name|FR30_F_U8
block|,
name|FR30_F_I8
block|,
name|FR30_F_I20_4
block|,
name|FR30_F_I20_16
block|,
name|FR30_F_I20
block|,
name|FR30_F_I32
block|,
name|FR30_F_UDISP6
block|,
name|FR30_F_DISP8
block|,
name|FR30_F_DISP9
block|,
name|FR30_F_DISP10
block|,
name|FR30_F_S10
block|,
name|FR30_F_U10
block|,
name|FR30_F_REL9
block|,
name|FR30_F_DIR8
block|,
name|FR30_F_DIR9
block|,
name|FR30_F_DIR10
block|,
name|FR30_F_REL12
block|,
name|FR30_F_REGLIST_HI_ST
block|,
name|FR30_F_REGLIST_LOW_ST
block|,
name|FR30_F_REGLIST_HI_LD
block|,
name|FR30_F_REGLIST_LOW_LD
block|,
name|FR30_F_MAX
block|}
name|IFIELD_TYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_IFLD
value|((int) FR30_F_MAX)
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
comment|/* Enum declaration for fr30 hardware types.  */
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
name|HW_H_CR
block|,
name|HW_H_DR
block|,
name|HW_H_PS
block|,
name|HW_H_R13
block|,
name|HW_H_R14
block|,
name|HW_H_R15
block|,
name|HW_H_NBIT
block|,
name|HW_H_ZBIT
block|,
name|HW_H_VBIT
block|,
name|HW_H_CBIT
block|,
name|HW_H_IBIT
block|,
name|HW_H_SBIT
block|,
name|HW_H_TBIT
block|,
name|HW_H_D0BIT
block|,
name|HW_H_D1BIT
block|,
name|HW_H_CCR
block|,
name|HW_H_SCR
block|,
name|HW_H_ILM
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
name|CGEN_OPERAND_HASH_PREFIX
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

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_OPERAND_HASH_PREFIX_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_OPERAND_HASH_PREFIX)) != 0)
end_define

begin_comment
comment|/* Enum declaration for fr30 operand types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|cgen_operand_type
block|{
name|FR30_OPERAND_PC
block|,
name|FR30_OPERAND_RI
block|,
name|FR30_OPERAND_RJ
block|,
name|FR30_OPERAND_RIC
block|,
name|FR30_OPERAND_RJC
block|,
name|FR30_OPERAND_CRI
block|,
name|FR30_OPERAND_CRJ
block|,
name|FR30_OPERAND_RS1
block|,
name|FR30_OPERAND_RS2
block|,
name|FR30_OPERAND_R13
block|,
name|FR30_OPERAND_R14
block|,
name|FR30_OPERAND_R15
block|,
name|FR30_OPERAND_PS
block|,
name|FR30_OPERAND_U4
block|,
name|FR30_OPERAND_U4C
block|,
name|FR30_OPERAND_U8
block|,
name|FR30_OPERAND_I8
block|,
name|FR30_OPERAND_UDISP6
block|,
name|FR30_OPERAND_DISP8
block|,
name|FR30_OPERAND_DISP9
block|,
name|FR30_OPERAND_DISP10
block|,
name|FR30_OPERAND_S10
block|,
name|FR30_OPERAND_U10
block|,
name|FR30_OPERAND_I32
block|,
name|FR30_OPERAND_M4
block|,
name|FR30_OPERAND_I20
block|,
name|FR30_OPERAND_DIR8
block|,
name|FR30_OPERAND_DIR9
block|,
name|FR30_OPERAND_DIR10
block|,
name|FR30_OPERAND_LABEL9
block|,
name|FR30_OPERAND_LABEL12
block|,
name|FR30_OPERAND_REGLIST_LOW_LD
block|,
name|FR30_OPERAND_REGLIST_HI_LD
block|,
name|FR30_OPERAND_REGLIST_LOW_ST
block|,
name|FR30_OPERAND_REGLIST_HI_ST
block|,
name|FR30_OPERAND_CC
block|,
name|FR30_OPERAND_CCC
block|,
name|FR30_OPERAND_NBIT
block|,
name|FR30_OPERAND_VBIT
block|,
name|FR30_OPERAND_ZBIT
block|,
name|FR30_OPERAND_CBIT
block|,
name|FR30_OPERAND_IBIT
block|,
name|FR30_OPERAND_SBIT
block|,
name|FR30_OPERAND_TBIT
block|,
name|FR30_OPERAND_D0BIT
block|,
name|FR30_OPERAND_D1BIT
block|,
name|FR30_OPERAND_CCR
block|,
name|FR30_OPERAND_SCR
block|,
name|FR30_OPERAND_ILM
block|,
name|FR30_OPERAND_MAX
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
value|49
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
name|CGEN_INSN_NOT_IN_DELAY_SLOT
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

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_NOT_IN_DELAY_SLOT_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_NOT_IN_DELAY_SLOT)) != 0)
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
name|fr30_cgen_ifld_table
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
name|fr30_cgen_hardware_attr_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_ATTR_TABLE
name|fr30_cgen_ifield_attr_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_ATTR_TABLE
name|fr30_cgen_operand_attr_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_ATTR_TABLE
name|fr30_cgen_insn_attr_table
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hardware decls.  */
end_comment

begin_decl_stmt
specifier|extern
name|CGEN_KEYWORD
name|fr30_cgen_opval_gr_names
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CGEN_KEYWORD
name|fr30_cgen_opval_cr_names
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CGEN_KEYWORD
name|fr30_cgen_opval_dr_names
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CGEN_KEYWORD
name|fr30_cgen_opval_h_ps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CGEN_KEYWORD
name|fr30_cgen_opval_h_r13
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CGEN_KEYWORD
name|fr30_cgen_opval_h_r14
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CGEN_KEYWORD
name|fr30_cgen_opval_h_r15
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_HW_ENTRY
name|fr30_cgen_hw_table
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FR30_CPU_H */
end_comment

end_unit

