begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* CPU data header for openrisc.  THIS FILE IS MACHINE GENERATED WITH CGEN.  Copyright 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.  This file is part of the GNU Binutils and/or GDB, the GNU debugger.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OPENRISC_CPU_H
end_ifndef

begin_define
define|#
directive|define
name|OPENRISC_CPU_H
end_define

begin_define
define|#
directive|define
name|CGEN_ARCH
value|openrisc
end_define

begin_comment
comment|/* Given symbol S, return openrisc_cgen_<S>.  */
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
value|openrisc##_cgen_##s
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
value|openrisc
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
name|HAVE_CPU_OPENRISCBF
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
value|4
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
value|14
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
comment|/* Enum declaration for exception vectors.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_exception
block|{
name|E_RESET
block|,
name|E_BUSERR
block|,
name|E_DPF
block|,
name|E_IPF
block|,
name|E_EXTINT
block|,
name|E_ALIGN
block|,
name|E_ILLEGAL
block|,
name|E_PEINT
block|,
name|E_DTLBMISS
block|,
name|E_ITLBMISS
block|,
name|E_RRANGE
block|,
name|E_SYSCALL
block|,
name|E_BREAK
block|,
name|E_RESERVED
block|}
name|E_EXCEPTION
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for FIXME.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|insn_class
block|{
name|OP1_0
block|,
name|OP1_1
block|,
name|OP1_2
block|,
name|OP1_3
block|}
name|INSN_CLASS
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for FIXME.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|insn_sub
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
name|INSN_SUB
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for FIXME.  */
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
block|}
name|INSN_OP3
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for FIXME.  */
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
block|}
name|INSN_OP4
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for FIXME.  */
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
name|OP5_10
block|,
name|OP5_11
block|,
name|OP5_12
block|,
name|OP5_13
block|,
name|OP5_14
block|,
name|OP5_15
block|,
name|OP5_16
block|,
name|OP5_17
block|,
name|OP5_18
block|,
name|OP5_19
block|,
name|OP5_20
block|,
name|OP5_21
block|,
name|OP5_22
block|,
name|OP5_23
block|,
name|OP5_24
block|,
name|OP5_25
block|,
name|OP5_26
block|,
name|OP5_27
block|,
name|OP5_28
block|,
name|OP5_29
block|,
name|OP5_30
block|,
name|OP5_31
block|}
name|INSN_OP5
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for FIXME.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|insn_op6
block|{
name|OP6_0
block|,
name|OP6_1
block|,
name|OP6_2
block|,
name|OP6_3
block|,
name|OP6_4
block|,
name|OP6_5
block|,
name|OP6_6
block|,
name|OP6_7
block|}
name|INSN_OP6
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for FIXME.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|insn_op7
block|{
name|OP7_0
block|,
name|OP7_1
block|,
name|OP7_2
block|,
name|OP7_3
block|,
name|OP7_4
block|,
name|OP7_5
block|,
name|OP7_6
block|,
name|OP7_7
block|,
name|OP7_8
block|,
name|OP7_9
block|,
name|OP7_10
block|,
name|OP7_11
block|,
name|OP7_12
block|,
name|OP7_13
block|,
name|OP7_14
block|,
name|OP7_15
block|}
name|INSN_OP7
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
name|MACH_OPENRISC
block|,
name|MACH_OR1300
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
name|ISA_OR32
block|,
name|ISA_MAX
block|}
name|ISA_ATTR
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for if this model has caches.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|has_cache_attr
block|{
name|HAS_CACHE_DATA_CACHE
block|,
name|HAS_CACHE_INSN_CACHE
block|}
name|HAS_CACHE_ATTR
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
name|openrisc_cgen_ifld_table
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
comment|/* Enum declaration for openrisc ifield types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|ifield_type
block|{
name|OPENRISC_F_NIL
block|,
name|OPENRISC_F_ANYOF
block|,
name|OPENRISC_F_CLASS
block|,
name|OPENRISC_F_SUB
block|,
name|OPENRISC_F_R1
block|,
name|OPENRISC_F_R2
block|,
name|OPENRISC_F_R3
block|,
name|OPENRISC_F_SIMM16
block|,
name|OPENRISC_F_UIMM16
block|,
name|OPENRISC_F_UIMM5
block|,
name|OPENRISC_F_HI16
block|,
name|OPENRISC_F_LO16
block|,
name|OPENRISC_F_OP1
block|,
name|OPENRISC_F_OP2
block|,
name|OPENRISC_F_OP3
block|,
name|OPENRISC_F_OP4
block|,
name|OPENRISC_F_OP5
block|,
name|OPENRISC_F_OP6
block|,
name|OPENRISC_F_OP7
block|,
name|OPENRISC_F_I16_1
block|,
name|OPENRISC_F_I16_2
block|,
name|OPENRISC_F_DISP26
block|,
name|OPENRISC_F_ABS26
block|,
name|OPENRISC_F_I16NC
block|,
name|OPENRISC_F_F_15_8
block|,
name|OPENRISC_F_F_10_3
block|,
name|OPENRISC_F_F_4_1
block|,
name|OPENRISC_F_F_7_3
block|,
name|OPENRISC_F_F_10_7
block|,
name|OPENRISC_F_F_10_11
block|,
name|OPENRISC_F_MAX
block|}
name|IFIELD_TYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_IFLD
value|((int) OPENRISC_F_MAX)
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
comment|/* Enum declaration for openrisc hardware types.  */
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
name|HW_H_SR
block|,
name|HW_H_HI16
block|,
name|HW_H_LO16
block|,
name|HW_H_CBIT
block|,
name|HW_H_DELAY_INSN
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
comment|/* Enum declaration for openrisc operand types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|cgen_operand_type
block|{
name|OPENRISC_OPERAND_PC
block|,
name|OPENRISC_OPERAND_SR
block|,
name|OPENRISC_OPERAND_CBIT
block|,
name|OPENRISC_OPERAND_SIMM_16
block|,
name|OPENRISC_OPERAND_UIMM_16
block|,
name|OPENRISC_OPERAND_DISP_26
block|,
name|OPENRISC_OPERAND_ABS_26
block|,
name|OPENRISC_OPERAND_UIMM_5
block|,
name|OPENRISC_OPERAND_RD
block|,
name|OPENRISC_OPERAND_RA
block|,
name|OPENRISC_OPERAND_RB
block|,
name|OPENRISC_OPERAND_OP_F_23
block|,
name|OPENRISC_OPERAND_OP_F_3
block|,
name|OPENRISC_OPERAND_HI16
block|,
name|OPENRISC_OPERAND_LO16
block|,
name|OPENRISC_OPERAND_UI16NC
block|,
name|OPENRISC_OPERAND_MAX
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
value|16
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
name|openrisc_cgen_hardware_attr_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_ATTR_TABLE
name|openrisc_cgen_ifield_attr_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_ATTR_TABLE
name|openrisc_cgen_operand_attr_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_ATTR_TABLE
name|openrisc_cgen_insn_attr_table
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hardware decls.  */
end_comment

begin_decl_stmt
specifier|extern
name|CGEN_KEYWORD
name|openrisc_cgen_opval_h_gr
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENRISC_CPU_H */
end_comment

end_unit

