begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* CPU data header for m32r.  THIS FILE IS MACHINE GENERATED WITH CGEN.  Copyright 1996-2005 Free Software Foundation, Inc.  This file is part of the GNU Binutils and/or GDB, the GNU debugger.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|M32R_CPU_H
end_ifndef

begin_define
define|#
directive|define
name|M32R_CPU_H
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
value|m32r
end_define

begin_comment
comment|/* Given symbol S, return m32r_cgen_<S>.  */
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
value|m32r##_cgen_##s
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
value|m32r
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
name|HAVE_CPU_M32RBF
end_define

begin_define
define|#
directive|define
name|HAVE_CPU_M32RXF
end_define

begin_define
define|#
directive|define
name|HAVE_CPU_M32R2F
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
comment|/* Enum declaration for insn format enums.  */
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
name|OP1_10
block|,
name|OP1_11
block|,
name|OP1_12
block|,
name|OP1_13
block|,
name|OP1_14
block|,
name|OP1_15
block|}
name|INSN_OP1
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for op2 enums.  */
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
name|OP2_10
block|,
name|OP2_11
block|,
name|OP2_12
block|,
name|OP2_13
block|,
name|OP2_14
block|,
name|OP2_15
block|}
name|INSN_OP2
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
name|H_GR_FP
init|=
literal|13
block|,
name|H_GR_LR
init|=
literal|14
block|,
name|H_GR_SP
init|=
literal|15
block|,
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
name|H_CR_PSW
init|=
literal|0
block|,
name|H_CR_CBR
init|=
literal|1
block|,
name|H_CR_SPI
init|=
literal|2
block|,
name|H_CR_SPU
init|=
literal|3
block|,
name|H_CR_BPC
init|=
literal|6
block|,
name|H_CR_BBPSW
init|=
literal|8
block|,
name|H_CR_BBPC
init|=
literal|14
block|,
name|H_CR_EVB
init|=
literal|5
block|,
name|H_CR_CR0
init|=
literal|0
block|,
name|H_CR_CR1
init|=
literal|1
block|,
name|H_CR_CR2
init|=
literal|2
block|,
name|H_CR_CR3
init|=
literal|3
block|,
name|H_CR_CR4
init|=
literal|4
block|,
name|H_CR_CR5
init|=
literal|5
block|,
name|H_CR_CR6
init|=
literal|6
block|,
name|H_CR_CR7
init|=
literal|7
block|,
name|H_CR_CR8
init|=
literal|8
block|,
name|H_CR_CR9
init|=
literal|9
block|,
name|H_CR_CR10
init|=
literal|10
block|,
name|H_CR_CR11
init|=
literal|11
block|,
name|H_CR_CR12
init|=
literal|12
block|,
name|H_CR_CR13
init|=
literal|13
block|,
name|H_CR_CR14
init|=
literal|14
block|,
name|H_CR_CR15
init|=
literal|15
block|}
name|CR_NAMES
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
name|MACH_M32R
block|,
name|MACH_M32RX
block|,
name|MACH_M32R2
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
name|ISA_M32R
block|,
name|ISA_MAX
block|}
name|ISA_ATTR
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for parallel execution pipeline selection.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|pipe_attr
block|{
name|PIPE_NONE
block|,
name|PIPE_O
block|,
name|PIPE_S
block|,
name|PIPE_OS
block|,
name|PIPE_O_OS
block|}
name|PIPE_ATTR
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
name|CGEN_IFLD_RELOC
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

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_IFLD_RELOC_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_IFLD_RELOC)) != 0)
end_define

begin_comment
comment|/* Enum declaration for m32r ifield types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|ifield_type
block|{
name|M32R_F_NIL
block|,
name|M32R_F_ANYOF
block|,
name|M32R_F_OP1
block|,
name|M32R_F_OP2
block|,
name|M32R_F_COND
block|,
name|M32R_F_R1
block|,
name|M32R_F_R2
block|,
name|M32R_F_SIMM8
block|,
name|M32R_F_SIMM16
block|,
name|M32R_F_SHIFT_OP2
block|,
name|M32R_F_UIMM3
block|,
name|M32R_F_UIMM4
block|,
name|M32R_F_UIMM5
block|,
name|M32R_F_UIMM8
block|,
name|M32R_F_UIMM16
block|,
name|M32R_F_UIMM24
block|,
name|M32R_F_HI16
block|,
name|M32R_F_DISP8
block|,
name|M32R_F_DISP16
block|,
name|M32R_F_DISP24
block|,
name|M32R_F_OP23
block|,
name|M32R_F_OP3
block|,
name|M32R_F_ACC
block|,
name|M32R_F_ACCS
block|,
name|M32R_F_ACCD
block|,
name|M32R_F_BITS67
block|,
name|M32R_F_BIT4
block|,
name|M32R_F_BIT14
block|,
name|M32R_F_IMM1
block|,
name|M32R_F_MAX
block|}
name|IFIELD_TYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_IFLD
value|((int) M32R_F_MAX)
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
comment|/* Enum declaration for m32r hardware types.  */
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
name|HW_H_HI16
block|,
name|HW_H_SLO16
block|,
name|HW_H_ULO16
block|,
name|HW_H_GR
block|,
name|HW_H_CR
block|,
name|HW_H_ACCUM
block|,
name|HW_H_ACCUMS
block|,
name|HW_H_COND
block|,
name|HW_H_PSW
block|,
name|HW_H_BPSW
block|,
name|HW_H_BBPSW
block|,
name|HW_H_LOCK
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
name|CGEN_OPERAND_RELOC
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
name|CGEN_ATTR_CGEN_OPERAND_RELOC_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_OPERAND_RELOC)) != 0)
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
comment|/* Enum declaration for m32r operand types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|cgen_operand_type
block|{
name|M32R_OPERAND_PC
block|,
name|M32R_OPERAND_SR
block|,
name|M32R_OPERAND_DR
block|,
name|M32R_OPERAND_SRC1
block|,
name|M32R_OPERAND_SRC2
block|,
name|M32R_OPERAND_SCR
block|,
name|M32R_OPERAND_DCR
block|,
name|M32R_OPERAND_SIMM8
block|,
name|M32R_OPERAND_SIMM16
block|,
name|M32R_OPERAND_UIMM3
block|,
name|M32R_OPERAND_UIMM4
block|,
name|M32R_OPERAND_UIMM5
block|,
name|M32R_OPERAND_UIMM8
block|,
name|M32R_OPERAND_UIMM16
block|,
name|M32R_OPERAND_IMM1
block|,
name|M32R_OPERAND_ACCD
block|,
name|M32R_OPERAND_ACCS
block|,
name|M32R_OPERAND_ACC
block|,
name|M32R_OPERAND_HASH
block|,
name|M32R_OPERAND_HI16
block|,
name|M32R_OPERAND_SLO16
block|,
name|M32R_OPERAND_ULO16
block|,
name|M32R_OPERAND_UIMM24
block|,
name|M32R_OPERAND_DISP8
block|,
name|M32R_OPERAND_DISP16
block|,
name|M32R_OPERAND_DISP24
block|,
name|M32R_OPERAND_CONDBIT
block|,
name|M32R_OPERAND_ACCUM
block|,
name|M32R_OPERAND_MAX
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
value|28
end_define

begin_comment
comment|/* Maximum number of operands referenced by any insn.  */
end_comment

begin_define
define|#
directive|define
name|MAX_OPERAND_INSTANCES
value|11
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
name|CGEN_INSN_FILL_SLOT
block|,
name|CGEN_INSN_SPECIAL
block|,
name|CGEN_INSN_SPECIAL_M32R
block|,
name|CGEN_INSN_SPECIAL_FLOAT
block|,
name|CGEN_INSN_END_BOOLS
block|,
name|CGEN_INSN_START_NBOOLS
init|=
literal|31
block|,
name|CGEN_INSN_MACH
block|,
name|CGEN_INSN_PIPE
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
name|CGEN_ATTR_CGEN_INSN_PIPE_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|((attrs)->nonbool[CGEN_INSN_PIPE-CGEN_INSN_START_NBOOLS-1].nonbitset)
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
name|CGEN_ATTR_CGEN_INSN_FILL_SLOT_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_FILL_SLOT)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_SPECIAL_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_SPECIAL)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_SPECIAL_M32R_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_SPECIAL_M32R)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_SPECIAL_FLOAT_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_SPECIAL_FLOAT)) != 0)
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
name|m32r_cgen_ifld_table
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
name|m32r_cgen_hardware_attr_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_ATTR_TABLE
name|m32r_cgen_ifield_attr_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_ATTR_TABLE
name|m32r_cgen_operand_attr_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_ATTR_TABLE
name|m32r_cgen_insn_attr_table
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hardware decls.  */
end_comment

begin_decl_stmt
specifier|extern
name|CGEN_KEYWORD
name|m32r_cgen_opval_gr_names
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CGEN_KEYWORD
name|m32r_cgen_opval_cr_names
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CGEN_KEYWORD
name|m32r_cgen_opval_h_accums
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_HW_ENTRY
name|m32r_cgen_hw_table
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* M32R_CPU_H */
end_comment

end_unit

