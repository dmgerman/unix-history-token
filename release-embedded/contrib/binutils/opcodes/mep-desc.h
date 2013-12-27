begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* CPU data header for mep.  THIS FILE IS MACHINE GENERATED WITH CGEN.  Copyright 1996-2005 Free Software Foundation, Inc.  This file is part of the GNU Binutils and/or GDB, the GNU debugger.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MEP_CPU_H
end_ifndef

begin_define
define|#
directive|define
name|MEP_CPU_H
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
value|mep
end_define

begin_comment
comment|/* Given symbol S, return mep_cgen_<S>.  */
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
value|mep##_cgen_##s
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
value|mep
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
name|HAVE_CPU_MEPF
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
value|17
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
value|11
end_define

begin_comment
comment|/* Enums.  */
end_comment

begin_comment
comment|/* Enum declaration for major opcodes.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|major
block|{
name|MAJ_0
block|,
name|MAJ_1
block|,
name|MAJ_2
block|,
name|MAJ_3
block|,
name|MAJ_4
block|,
name|MAJ_5
block|,
name|MAJ_6
block|,
name|MAJ_7
block|,
name|MAJ_8
block|,
name|MAJ_9
block|,
name|MAJ_10
block|,
name|MAJ_11
block|,
name|MAJ_12
block|,
name|MAJ_13
block|,
name|MAJ_14
block|,
name|MAJ_15
block|}
name|MAJOR
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for condition opcode enum.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|fmax_cond
block|{
name|FMAX_F
block|,
name|FMAX_U
block|,
name|FMAX_E
block|,
name|FMAX_UE
block|,
name|FMAX_L
block|,
name|FMAX_UL
block|,
name|FMAX_LE
block|,
name|FMAX_ULE
block|,
name|FMAX_FI
block|,
name|FMAX_UI
block|,
name|FMAX_EI
block|,
name|FMAX_UEI
block|,
name|FMAX_LI
block|,
name|FMAX_ULI
block|,
name|FMAX_LEI
block|,
name|FMAX_ULEI
block|}
name|FMAX_COND
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
name|MACH_MEP
block|,
name|MACH_H1
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
name|ISA_MEP
block|,
name|ISA_EXT_CORE1
block|,
name|ISA_EXT_CORE2
block|,
name|ISA_EXT_COP2_16
block|,
name|ISA_EXT_COP2_32
block|,
name|ISA_EXT_COP2_48
block|,
name|ISA_EXT_COP2_64
block|,
name|ISA_MAX
block|}
name|ISA_ATTR
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for datatype to use for C intrinsics mapping.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|cdata_attr
block|{
name|CDATA_LABEL
block|,
name|CDATA_REGNUM
block|,
name|CDATA_FMAX_FLOAT
block|,
name|CDATA_FMAX_INT
block|,
name|CDATA_POINTER
block|,
name|CDATA_LONG
block|,
name|CDATA_ULONG
block|,
name|CDATA_SHORT
block|,
name|CDATA_USHORT
block|,
name|CDATA_CHAR
block|,
name|CDATA_UCHAR
block|,
name|CDATA_CP_DATA_BUS_INT
block|}
name|CDATA_ATTR
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for .  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|config_attr
block|{
name|CONFIG_NONE
block|,
name|CONFIG_SIMPLE
block|,
name|CONFIG_FMAX
block|}
name|CONFIG_ATTR
typedef|;
end_typedef

begin_comment
comment|/* Number of architecture variants.  */
end_comment

begin_define
define|#
directive|define
name|MAX_ISAS
value|((int) ISA_MAX)
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
name|CGEN_IFLD_ISA
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
name|CGEN_ATTR_CGEN_IFLD_ISA_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|((attrs)->nonbool[CGEN_IFLD_ISA-CGEN_IFLD_START_NBOOLS-1].bitset)
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
comment|/* Enum declaration for mep ifield types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|ifield_type
block|{
name|MEP_F_NIL
block|,
name|MEP_F_ANYOF
block|,
name|MEP_F_MAJOR
block|,
name|MEP_F_RN
block|,
name|MEP_F_RN3
block|,
name|MEP_F_RM
block|,
name|MEP_F_RL
block|,
name|MEP_F_SUB2
block|,
name|MEP_F_SUB3
block|,
name|MEP_F_SUB4
block|,
name|MEP_F_EXT
block|,
name|MEP_F_CRN
block|,
name|MEP_F_CSRN_HI
block|,
name|MEP_F_CSRN_LO
block|,
name|MEP_F_CSRN
block|,
name|MEP_F_CRNX_HI
block|,
name|MEP_F_CRNX_LO
block|,
name|MEP_F_CRNX
block|,
name|MEP_F_0
block|,
name|MEP_F_1
block|,
name|MEP_F_2
block|,
name|MEP_F_3
block|,
name|MEP_F_4
block|,
name|MEP_F_5
block|,
name|MEP_F_6
block|,
name|MEP_F_7
block|,
name|MEP_F_8
block|,
name|MEP_F_9
block|,
name|MEP_F_10
block|,
name|MEP_F_11
block|,
name|MEP_F_12
block|,
name|MEP_F_13
block|,
name|MEP_F_14
block|,
name|MEP_F_15
block|,
name|MEP_F_16
block|,
name|MEP_F_17
block|,
name|MEP_F_18
block|,
name|MEP_F_19
block|,
name|MEP_F_20
block|,
name|MEP_F_21
block|,
name|MEP_F_22
block|,
name|MEP_F_23
block|,
name|MEP_F_24
block|,
name|MEP_F_25
block|,
name|MEP_F_26
block|,
name|MEP_F_27
block|,
name|MEP_F_28
block|,
name|MEP_F_29
block|,
name|MEP_F_30
block|,
name|MEP_F_31
block|,
name|MEP_F_8S8A2
block|,
name|MEP_F_12S4A2
block|,
name|MEP_F_17S16A2
block|,
name|MEP_F_24S5A2N_HI
block|,
name|MEP_F_24S5A2N_LO
block|,
name|MEP_F_24S5A2N
block|,
name|MEP_F_24U5A2N_HI
block|,
name|MEP_F_24U5A2N_LO
block|,
name|MEP_F_24U5A2N
block|,
name|MEP_F_2U6
block|,
name|MEP_F_7U9
block|,
name|MEP_F_7U9A2
block|,
name|MEP_F_7U9A4
block|,
name|MEP_F_16S16
block|,
name|MEP_F_2U10
block|,
name|MEP_F_3U5
block|,
name|MEP_F_4U8
block|,
name|MEP_F_5U8
block|,
name|MEP_F_5U24
block|,
name|MEP_F_6S8
block|,
name|MEP_F_8S8
block|,
name|MEP_F_16U16
block|,
name|MEP_F_12U16
block|,
name|MEP_F_3U29
block|,
name|MEP_F_8S24
block|,
name|MEP_F_8S24A2
block|,
name|MEP_F_8S24A4
block|,
name|MEP_F_8S24A8
block|,
name|MEP_F_24U8A4N_HI
block|,
name|MEP_F_24U8A4N_LO
block|,
name|MEP_F_24U8A4N
block|,
name|MEP_F_24U8N_HI
block|,
name|MEP_F_24U8N_LO
block|,
name|MEP_F_24U8N
block|,
name|MEP_F_24U4N_HI
block|,
name|MEP_F_24U4N_LO
block|,
name|MEP_F_24U4N
block|,
name|MEP_F_CALLNUM
block|,
name|MEP_F_CCRN_HI
block|,
name|MEP_F_CCRN_LO
block|,
name|MEP_F_CCRN
block|,
name|MEP_F_FMAX_0_4
block|,
name|MEP_F_FMAX_4_4
block|,
name|MEP_F_FMAX_8_4
block|,
name|MEP_F_FMAX_12_4
block|,
name|MEP_F_FMAX_16_4
block|,
name|MEP_F_FMAX_20_4
block|,
name|MEP_F_FMAX_24_4
block|,
name|MEP_F_FMAX_28_1
block|,
name|MEP_F_FMAX_29_1
block|,
name|MEP_F_FMAX_30_1
block|,
name|MEP_F_FMAX_31_1
block|,
name|MEP_F_FMAX_FRD
block|,
name|MEP_F_FMAX_FRN
block|,
name|MEP_F_FMAX_FRM
block|,
name|MEP_F_FMAX_RM
block|,
name|MEP_F_MAX
block|}
name|IFIELD_TYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_IFLD
value|((int) MEP_F_MAX)
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
name|CGEN_HW_IS_FLOAT
block|,
name|CGEN_HW_END_BOOLS
block|,
name|CGEN_HW_START_NBOOLS
init|=
literal|31
block|,
name|CGEN_HW_MACH
block|,
name|CGEN_HW_ISA
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
name|CGEN_ATTR_CGEN_HW_ISA_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|((attrs)->nonbool[CGEN_HW_ISA-CGEN_HW_START_NBOOLS-1].bitset)
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

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_HW_IS_FLOAT_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_HW_IS_FLOAT)) != 0)
end_define

begin_comment
comment|/* Enum declaration for mep hardware types.  */
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
name|HW_H_GPR
block|,
name|HW_H_CSR
block|,
name|HW_H_CR64
block|,
name|HW_H_CR
block|,
name|HW_H_CCR
block|,
name|HW_H_CR_FMAX
block|,
name|HW_H_CCR_FMAX
block|,
name|HW_H_FMAX_COMPARE_I_P
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
name|CGEN_OPERAND_RELOC_IMPLIES_OVERFLOW
block|,
name|CGEN_OPERAND_END_BOOLS
block|,
name|CGEN_OPERAND_START_NBOOLS
init|=
literal|31
block|,
name|CGEN_OPERAND_MACH
block|,
name|CGEN_OPERAND_ISA
block|,
name|CGEN_OPERAND_CDATA
block|,
name|CGEN_OPERAND_ALIGN
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
name|CGEN_ATTR_CGEN_OPERAND_ISA_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|((attrs)->nonbool[CGEN_OPERAND_ISA-CGEN_OPERAND_START_NBOOLS-1].bitset)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_OPERAND_CDATA_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|((attrs)->nonbool[CGEN_OPERAND_CDATA-CGEN_OPERAND_START_NBOOLS-1].nonbitset)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_OPERAND_ALIGN_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|((attrs)->nonbool[CGEN_OPERAND_ALIGN-CGEN_OPERAND_START_NBOOLS-1].nonbitset)
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
name|CGEN_ATTR_CGEN_OPERAND_RELOC_IMPLIES_OVERFLOW_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_OPERAND_RELOC_IMPLIES_OVERFLOW)) != 0)
end_define

begin_comment
comment|/* Enum declaration for mep operand types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|cgen_operand_type
block|{
name|MEP_OPERAND_PC
block|,
name|MEP_OPERAND_R0
block|,
name|MEP_OPERAND_RN
block|,
name|MEP_OPERAND_RM
block|,
name|MEP_OPERAND_RL
block|,
name|MEP_OPERAND_RN3
block|,
name|MEP_OPERAND_RMA
block|,
name|MEP_OPERAND_RNC
block|,
name|MEP_OPERAND_RNUC
block|,
name|MEP_OPERAND_RNS
block|,
name|MEP_OPERAND_RNUS
block|,
name|MEP_OPERAND_RNL
block|,
name|MEP_OPERAND_RNUL
block|,
name|MEP_OPERAND_RN3C
block|,
name|MEP_OPERAND_RN3UC
block|,
name|MEP_OPERAND_RN3S
block|,
name|MEP_OPERAND_RN3US
block|,
name|MEP_OPERAND_RN3L
block|,
name|MEP_OPERAND_RN3UL
block|,
name|MEP_OPERAND_LP
block|,
name|MEP_OPERAND_SAR
block|,
name|MEP_OPERAND_HI
block|,
name|MEP_OPERAND_LO
block|,
name|MEP_OPERAND_MB0
block|,
name|MEP_OPERAND_ME0
block|,
name|MEP_OPERAND_MB1
block|,
name|MEP_OPERAND_ME1
block|,
name|MEP_OPERAND_PSW
block|,
name|MEP_OPERAND_EPC
block|,
name|MEP_OPERAND_EXC
block|,
name|MEP_OPERAND_NPC
block|,
name|MEP_OPERAND_DBG
block|,
name|MEP_OPERAND_DEPC
block|,
name|MEP_OPERAND_OPT
block|,
name|MEP_OPERAND_R1
block|,
name|MEP_OPERAND_TP
block|,
name|MEP_OPERAND_SP
block|,
name|MEP_OPERAND_TPR
block|,
name|MEP_OPERAND_SPR
block|,
name|MEP_OPERAND_CSRN
block|,
name|MEP_OPERAND_CSRN_IDX
block|,
name|MEP_OPERAND_CRN64
block|,
name|MEP_OPERAND_CRN
block|,
name|MEP_OPERAND_CRNX64
block|,
name|MEP_OPERAND_CRNX
block|,
name|MEP_OPERAND_CCRN
block|,
name|MEP_OPERAND_CCCC
block|,
name|MEP_OPERAND_PCREL8A2
block|,
name|MEP_OPERAND_PCREL12A2
block|,
name|MEP_OPERAND_PCREL17A2
block|,
name|MEP_OPERAND_PCREL24A2
block|,
name|MEP_OPERAND_PCABS24A2
block|,
name|MEP_OPERAND_SDISP16
block|,
name|MEP_OPERAND_SIMM16
block|,
name|MEP_OPERAND_UIMM16
block|,
name|MEP_OPERAND_CODE16
block|,
name|MEP_OPERAND_UDISP2
block|,
name|MEP_OPERAND_UIMM2
block|,
name|MEP_OPERAND_SIMM6
block|,
name|MEP_OPERAND_SIMM8
block|,
name|MEP_OPERAND_ADDR24A4
block|,
name|MEP_OPERAND_CODE24
block|,
name|MEP_OPERAND_CALLNUM
block|,
name|MEP_OPERAND_UIMM3
block|,
name|MEP_OPERAND_UIMM4
block|,
name|MEP_OPERAND_UIMM5
block|,
name|MEP_OPERAND_UDISP7
block|,
name|MEP_OPERAND_UDISP7A2
block|,
name|MEP_OPERAND_UDISP7A4
block|,
name|MEP_OPERAND_UIMM7A4
block|,
name|MEP_OPERAND_UIMM24
block|,
name|MEP_OPERAND_CIMM4
block|,
name|MEP_OPERAND_CIMM5
block|,
name|MEP_OPERAND_CDISP8
block|,
name|MEP_OPERAND_CDISP8A2
block|,
name|MEP_OPERAND_CDISP8A4
block|,
name|MEP_OPERAND_CDISP8A8
block|,
name|MEP_OPERAND_ZERO
block|,
name|MEP_OPERAND_CP_FLAG
block|,
name|MEP_OPERAND_FMAX_FRD
block|,
name|MEP_OPERAND_FMAX_FRN
block|,
name|MEP_OPERAND_FMAX_FRM
block|,
name|MEP_OPERAND_FMAX_FRD_INT
block|,
name|MEP_OPERAND_FMAX_FRN_INT
block|,
name|MEP_OPERAND_FMAX_CCRN
block|,
name|MEP_OPERAND_FMAX_CIRR
block|,
name|MEP_OPERAND_FMAX_CBCR
block|,
name|MEP_OPERAND_FMAX_CERR
block|,
name|MEP_OPERAND_FMAX_RM
block|,
name|MEP_OPERAND_FMAX_COMPARE_I_P
block|,
name|MEP_OPERAND_MAX
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
value|90
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
name|CGEN_INSN_OPTIONAL_BIT_INSN
block|,
name|CGEN_INSN_OPTIONAL_MUL_INSN
block|,
name|CGEN_INSN_OPTIONAL_DIV_INSN
block|,
name|CGEN_INSN_OPTIONAL_DEBUG_INSN
block|,
name|CGEN_INSN_OPTIONAL_LDZ_INSN
block|,
name|CGEN_INSN_OPTIONAL_ABS_INSN
block|,
name|CGEN_INSN_OPTIONAL_AVE_INSN
block|,
name|CGEN_INSN_OPTIONAL_MINMAX_INSN
block|,
name|CGEN_INSN_OPTIONAL_CLIP_INSN
block|,
name|CGEN_INSN_OPTIONAL_SAT_INSN
block|,
name|CGEN_INSN_OPTIONAL_UCI_INSN
block|,
name|CGEN_INSN_OPTIONAL_DSP_INSN
block|,
name|CGEN_INSN_OPTIONAL_CP_INSN
block|,
name|CGEN_INSN_OPTIONAL_CP64_INSN
block|,
name|CGEN_INSN_OPTIONAL_VLIW64
block|,
name|CGEN_INSN_MAY_TRAP
block|,
name|CGEN_INSN_VLIW_ALONE
block|,
name|CGEN_INSN_VLIW_NO_CORE_NOP
block|,
name|CGEN_INSN_VLIW_NO_COP_NOP
block|,
name|CGEN_INSN_VLIW64_NO_MATCHING_NOP
block|,
name|CGEN_INSN_VLIW32_NO_MATCHING_NOP
block|,
name|CGEN_INSN_VOLATILE
block|,
name|CGEN_INSN_END_BOOLS
block|,
name|CGEN_INSN_START_NBOOLS
init|=
literal|31
block|,
name|CGEN_INSN_MACH
block|,
name|CGEN_INSN_ISA
block|,
name|CGEN_INSN_LATENCY
block|,
name|CGEN_INSN_CONFIG
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
name|CGEN_ATTR_CGEN_INSN_ISA_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|((attrs)->nonbool[CGEN_INSN_ISA-CGEN_INSN_START_NBOOLS-1].bitset)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_LATENCY_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|((attrs)->nonbool[CGEN_INSN_LATENCY-CGEN_INSN_START_NBOOLS-1].nonbitset)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_CONFIG_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|((attrs)->nonbool[CGEN_INSN_CONFIG-CGEN_INSN_START_NBOOLS-1].nonbitset)
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
name|CGEN_ATTR_CGEN_INSN_OPTIONAL_BIT_INSN_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_OPTIONAL_BIT_INSN)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_OPTIONAL_MUL_INSN_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_OPTIONAL_MUL_INSN)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_OPTIONAL_DIV_INSN_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_OPTIONAL_DIV_INSN)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_OPTIONAL_DEBUG_INSN_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_OPTIONAL_DEBUG_INSN)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_OPTIONAL_LDZ_INSN_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_OPTIONAL_LDZ_INSN)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_OPTIONAL_ABS_INSN_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_OPTIONAL_ABS_INSN)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_OPTIONAL_AVE_INSN_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_OPTIONAL_AVE_INSN)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_OPTIONAL_MINMAX_INSN_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_OPTIONAL_MINMAX_INSN)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_OPTIONAL_CLIP_INSN_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_OPTIONAL_CLIP_INSN)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_OPTIONAL_SAT_INSN_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_OPTIONAL_SAT_INSN)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_OPTIONAL_UCI_INSN_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_OPTIONAL_UCI_INSN)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_OPTIONAL_DSP_INSN_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_OPTIONAL_DSP_INSN)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_OPTIONAL_CP_INSN_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_OPTIONAL_CP_INSN)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_OPTIONAL_CP64_INSN_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_OPTIONAL_CP64_INSN)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_OPTIONAL_VLIW64_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_OPTIONAL_VLIW64)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_MAY_TRAP_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_MAY_TRAP)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_VLIW_ALONE_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_VLIW_ALONE)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_VLIW_NO_CORE_NOP_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_VLIW_NO_CORE_NOP)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_VLIW_NO_COP_NOP_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_VLIW_NO_COP_NOP)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_VLIW64_NO_MATCHING_NOP_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_VLIW64_NO_MATCHING_NOP)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_VLIW32_NO_MATCHING_NOP_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_VLIW32_NO_MATCHING_NOP)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_VOLATILE_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_VOLATILE)) != 0)
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
name|mep_cgen_ifld_table
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
name|mep_cgen_hardware_attr_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_ATTR_TABLE
name|mep_cgen_ifield_attr_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_ATTR_TABLE
name|mep_cgen_operand_attr_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_ATTR_TABLE
name|mep_cgen_insn_attr_table
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hardware decls.  */
end_comment

begin_decl_stmt
specifier|extern
name|CGEN_KEYWORD
name|mep_cgen_opval_h_gpr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CGEN_KEYWORD
name|mep_cgen_opval_h_csr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CGEN_KEYWORD
name|mep_cgen_opval_h_cr64
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CGEN_KEYWORD
name|mep_cgen_opval_h_cr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CGEN_KEYWORD
name|mep_cgen_opval_h_ccr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CGEN_KEYWORD
name|mep_cgen_opval_h_cr_fmax
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CGEN_KEYWORD
name|mep_cgen_opval_h_ccr_fmax
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_HW_ENTRY
name|mep_cgen_hw_table
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MEP_CPU_H */
end_comment

end_unit

