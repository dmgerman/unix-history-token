begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* CPU data header for mt.  THIS FILE IS MACHINE GENERATED WITH CGEN.  Copyright 1996-2005 Free Software Foundation, Inc.  This file is part of the GNU Binutils and/or GDB, the GNU debugger.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MT_CPU_H
end_ifndef

begin_define
define|#
directive|define
name|MT_CPU_H
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
value|mt
end_define

begin_comment
comment|/* Given symbol S, return mt_cgen_<S>.  */
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
value|mt##_cgen_##s
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
value|mt
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
name|HAVE_CPU_MS1BF
end_define

begin_define
define|#
directive|define
name|HAVE_CPU_MS1_003BF
end_define

begin_define
define|#
directive|define
name|HAVE_CPU_MS2BF
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
value|40
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
value|14
end_define

begin_comment
comment|/* Enums.  */
end_comment

begin_comment
comment|/* Enum declaration for msys enums.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|insn_msys
block|{
name|MSYS_NO
block|,
name|MSYS_YES
block|}
name|INSN_MSYS
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for opc enums.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|insn_opc
block|{
name|OPC_ADD
init|=
literal|0
block|,
name|OPC_ADDU
init|=
literal|1
block|,
name|OPC_SUB
init|=
literal|2
block|,
name|OPC_SUBU
init|=
literal|3
block|,
name|OPC_MUL
init|=
literal|4
block|,
name|OPC_AND
init|=
literal|8
block|,
name|OPC_OR
init|=
literal|9
block|,
name|OPC_XOR
init|=
literal|10
block|,
name|OPC_NAND
init|=
literal|11
block|,
name|OPC_NOR
init|=
literal|12
block|,
name|OPC_XNOR
init|=
literal|13
block|,
name|OPC_LDUI
init|=
literal|14
block|,
name|OPC_LSL
init|=
literal|16
block|,
name|OPC_LSR
init|=
literal|17
block|,
name|OPC_ASR
init|=
literal|18
block|,
name|OPC_BRLT
init|=
literal|24
block|,
name|OPC_BRLE
init|=
literal|25
block|,
name|OPC_BREQ
init|=
literal|26
block|,
name|OPC_JMP
init|=
literal|27
block|,
name|OPC_JAL
init|=
literal|28
block|,
name|OPC_BRNEQ
init|=
literal|29
block|,
name|OPC_DBNZ
init|=
literal|30
block|,
name|OPC_LOOP
init|=
literal|31
block|,
name|OPC_LDW
init|=
literal|32
block|,
name|OPC_STW
init|=
literal|33
block|,
name|OPC_EI
init|=
literal|48
block|,
name|OPC_DI
init|=
literal|49
block|,
name|OPC_SI
init|=
literal|50
block|,
name|OPC_RETI
init|=
literal|51
block|,
name|OPC_BREAK
init|=
literal|52
block|,
name|OPC_IFLUSH
init|=
literal|53
block|}
name|INSN_OPC
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for msopc enums.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|insn_msopc
block|{
name|MSOPC_LDCTXT
block|,
name|MSOPC_LDFB
block|,
name|MSOPC_STFB
block|,
name|MSOPC_FBCB
block|,
name|MSOPC_MFBCB
block|,
name|MSOPC_FBCCI
block|,
name|MSOPC_FBRCI
block|,
name|MSOPC_FBCRI
block|,
name|MSOPC_FBRRI
block|,
name|MSOPC_MFBCCI
block|,
name|MSOPC_MFBRCI
block|,
name|MSOPC_MFBCRI
block|,
name|MSOPC_MFBRRI
block|,
name|MSOPC_FBCBDR
block|,
name|MSOPC_RCFBCB
block|,
name|MSOPC_MRCFBCB
block|,
name|MSOPC_CBCAST
block|,
name|MSOPC_DUPCBCAST
block|,
name|MSOPC_WFBI
block|,
name|MSOPC_WFB
block|,
name|MSOPC_RCRISC
block|,
name|MSOPC_FBCBINC
block|,
name|MSOPC_RCXMODE
block|,
name|MSOPC_INTLVR
block|,
name|MSOPC_WFBINC
block|,
name|MSOPC_MWFBINC
block|,
name|MSOPC_WFBINCR
block|,
name|MSOPC_MWFBINCR
block|,
name|MSOPC_FBCBINCS
block|,
name|MSOPC_MFBCBINCS
block|,
name|MSOPC_FBCBINCRS
block|,
name|MSOPC_MFBCBINCRS
block|}
name|INSN_MSOPC
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for imm enums.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|insn_imm
block|{
name|IMM_NO
block|,
name|IMM_YES
block|}
name|INSN_IMM
typedef|;
end_typedef

begin_comment
comment|/* Enum declaration for .  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|msys_syms
block|{
name|H_NIL_DUP
init|=
literal|1
block|,
name|H_NIL_XX
init|=
literal|0
block|}
name|MSYS_SYMS
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
name|MACH_MS1
block|,
name|MACH_MS1_003
block|,
name|MACH_MS2
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
name|ISA_MT
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
comment|/* Enum declaration for mt ifield types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|ifield_type
block|{
name|MT_F_NIL
block|,
name|MT_F_ANYOF
block|,
name|MT_F_MSYS
block|,
name|MT_F_OPC
block|,
name|MT_F_IMM
block|,
name|MT_F_UU24
block|,
name|MT_F_SR1
block|,
name|MT_F_SR2
block|,
name|MT_F_DR
block|,
name|MT_F_DRRR
block|,
name|MT_F_IMM16U
block|,
name|MT_F_IMM16S
block|,
name|MT_F_IMM16A
block|,
name|MT_F_UU4A
block|,
name|MT_F_UU4B
block|,
name|MT_F_UU12
block|,
name|MT_F_UU8
block|,
name|MT_F_UU16
block|,
name|MT_F_UU1
block|,
name|MT_F_MSOPC
block|,
name|MT_F_UU_26_25
block|,
name|MT_F_MASK
block|,
name|MT_F_BANKADDR
block|,
name|MT_F_RDA
block|,
name|MT_F_UU_2_25
block|,
name|MT_F_RBBC
block|,
name|MT_F_PERM
block|,
name|MT_F_MODE
block|,
name|MT_F_UU_1_24
block|,
name|MT_F_WR
block|,
name|MT_F_FBINCR
block|,
name|MT_F_UU_2_23
block|,
name|MT_F_XMODE
block|,
name|MT_F_A23
block|,
name|MT_F_MASK1
block|,
name|MT_F_CR
block|,
name|MT_F_TYPE
block|,
name|MT_F_INCAMT
block|,
name|MT_F_CBS
block|,
name|MT_F_UU_1_19
block|,
name|MT_F_BALL
block|,
name|MT_F_COLNUM
block|,
name|MT_F_BRC
block|,
name|MT_F_INCR
block|,
name|MT_F_FBDISP
block|,
name|MT_F_UU_4_15
block|,
name|MT_F_LENGTH
block|,
name|MT_F_UU_1_15
block|,
name|MT_F_RC
block|,
name|MT_F_RCNUM
block|,
name|MT_F_ROWNUM
block|,
name|MT_F_CBX
block|,
name|MT_F_ID
block|,
name|MT_F_SIZE
block|,
name|MT_F_ROWNUM1
block|,
name|MT_F_UU_3_11
block|,
name|MT_F_RC1
block|,
name|MT_F_CCB
block|,
name|MT_F_CBRB
block|,
name|MT_F_CDB
block|,
name|MT_F_ROWNUM2
block|,
name|MT_F_CELL
block|,
name|MT_F_UU_3_9
block|,
name|MT_F_CONTNUM
block|,
name|MT_F_UU_1_6
block|,
name|MT_F_DUP
block|,
name|MT_F_RC2
block|,
name|MT_F_CTXDISP
block|,
name|MT_F_IMM16L
block|,
name|MT_F_LOOPO
block|,
name|MT_F_CB1SEL
block|,
name|MT_F_CB2SEL
block|,
name|MT_F_CB1INCR
block|,
name|MT_F_CB2INCR
block|,
name|MT_F_RC3
block|,
name|MT_F_MSYSFRSR2
block|,
name|MT_F_BRC2
block|,
name|MT_F_BALL2
block|,
name|MT_F_MAX
block|}
name|IFIELD_TYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_IFLD
value|((int) MT_F_MAX)
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
comment|/* Enum declaration for mt hardware types.  */
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
comment|/* Enum declaration for mt operand types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|cgen_operand_type
block|{
name|MT_OPERAND_PC
block|,
name|MT_OPERAND_FRSR1
block|,
name|MT_OPERAND_FRSR2
block|,
name|MT_OPERAND_FRDR
block|,
name|MT_OPERAND_FRDRRR
block|,
name|MT_OPERAND_IMM16
block|,
name|MT_OPERAND_IMM16Z
block|,
name|MT_OPERAND_IMM16O
block|,
name|MT_OPERAND_RC
block|,
name|MT_OPERAND_RCNUM
block|,
name|MT_OPERAND_CONTNUM
block|,
name|MT_OPERAND_RBBC
block|,
name|MT_OPERAND_COLNUM
block|,
name|MT_OPERAND_ROWNUM
block|,
name|MT_OPERAND_ROWNUM1
block|,
name|MT_OPERAND_ROWNUM2
block|,
name|MT_OPERAND_RC1
block|,
name|MT_OPERAND_RC2
block|,
name|MT_OPERAND_CBRB
block|,
name|MT_OPERAND_CELL
block|,
name|MT_OPERAND_DUP
block|,
name|MT_OPERAND_CTXDISP
block|,
name|MT_OPERAND_FBDISP
block|,
name|MT_OPERAND_TYPE
block|,
name|MT_OPERAND_MASK
block|,
name|MT_OPERAND_BANKADDR
block|,
name|MT_OPERAND_INCAMT
block|,
name|MT_OPERAND_XMODE
block|,
name|MT_OPERAND_MASK1
block|,
name|MT_OPERAND_BALL
block|,
name|MT_OPERAND_BRC
block|,
name|MT_OPERAND_RDA
block|,
name|MT_OPERAND_WR
block|,
name|MT_OPERAND_BALL2
block|,
name|MT_OPERAND_BRC2
block|,
name|MT_OPERAND_PERM
block|,
name|MT_OPERAND_A23
block|,
name|MT_OPERAND_CR
block|,
name|MT_OPERAND_CBS
block|,
name|MT_OPERAND_INCR
block|,
name|MT_OPERAND_LENGTH
block|,
name|MT_OPERAND_CBX
block|,
name|MT_OPERAND_CCB
block|,
name|MT_OPERAND_CDB
block|,
name|MT_OPERAND_MODE
block|,
name|MT_OPERAND_ID
block|,
name|MT_OPERAND_SIZE
block|,
name|MT_OPERAND_FBINCR
block|,
name|MT_OPERAND_LOOPSIZE
block|,
name|MT_OPERAND_IMM16L
block|,
name|MT_OPERAND_RC3
block|,
name|MT_OPERAND_CB1SEL
block|,
name|MT_OPERAND_CB2SEL
block|,
name|MT_OPERAND_CB1INCR
block|,
name|MT_OPERAND_CB2INCR
block|,
name|MT_OPERAND_MAX
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
value|55
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
name|CGEN_INSN_LOAD_DELAY
block|,
name|CGEN_INSN_MEMORY_ACCESS
block|,
name|CGEN_INSN_AL_INSN
block|,
name|CGEN_INSN_IO_INSN
block|,
name|CGEN_INSN_BR_INSN
block|,
name|CGEN_INSN_JAL_HAZARD
block|,
name|CGEN_INSN_USES_FRDR
block|,
name|CGEN_INSN_USES_FRDRRR
block|,
name|CGEN_INSN_USES_FRSR1
block|,
name|CGEN_INSN_USES_FRSR2
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
name|CGEN_ATTR_CGEN_INSN_LOAD_DELAY_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_LOAD_DELAY)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_MEMORY_ACCESS_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_MEMORY_ACCESS)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_AL_INSN_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_AL_INSN)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_IO_INSN_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_IO_INSN)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_BR_INSN_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_BR_INSN)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_JAL_HAZARD_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_JAL_HAZARD)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_USES_FRDR_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_USES_FRDR)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_USES_FRDRRR_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_USES_FRDRRR)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_USES_FRSR1_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_USES_FRSR1)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_USES_FRSR2_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_USES_FRSR2)) != 0)
end_define

begin_define
define|#
directive|define
name|CGEN_ATTR_CGEN_INSN_SKIPA_VALUE
parameter_list|(
name|attrs
parameter_list|)
value|(((attrs)->bool& (1<< CGEN_INSN_SKIPA)) != 0)
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
name|mt_cgen_ifld_table
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
name|mt_cgen_hardware_attr_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_ATTR_TABLE
name|mt_cgen_ifield_attr_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_ATTR_TABLE
name|mt_cgen_operand_attr_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_ATTR_TABLE
name|mt_cgen_insn_attr_table
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hardware decls.  */
end_comment

begin_decl_stmt
specifier|extern
name|CGEN_KEYWORD
name|mt_cgen_opval_h_spr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_HW_ENTRY
name|mt_cgen_hw_table
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MT_CPU_H */
end_comment

end_unit

