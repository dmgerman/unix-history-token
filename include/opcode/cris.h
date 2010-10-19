begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* cris.h -- Header file for CRIS opcode and register tables.    Copyright (C) 2000, 2001, 2004 Free Software Foundation, Inc.    Contributed by Axis Communications AB, Lund, Sweden.    Originally written for GAS 1.38.1 by Mikael Asker.    Updated, BFDized and GNUified by Hans-Peter Nilsson.  This file is part of GAS, GDB and the GNU binutils.  GAS, GDB, and GNU binutils is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GAS, GDB, and GNU binutils are distributed in the hope that they will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CRIS_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|__CRIS_H_INCLUDED_
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
specifier|const
argument_list|)
end_if

begin_define
define|#
directive|define
name|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Registers.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REG
value|(15)
end_define

begin_define
define|#
directive|define
name|REG_SP
value|(14)
end_define

begin_define
define|#
directive|define
name|REG_PC
value|(15)
end_define

begin_comment
comment|/* CPU version control of disassembly and assembly of instructions.    May affect how the instruction is assembled, at least the size of    immediate operands.  */
end_comment

begin_enum
enum|enum
name|cris_insn_version_usage
block|{
comment|/* Any version.  */
name|cris_ver_version_all
init|=
literal|0
block|,
comment|/* Indeterminate (intended for disassembly only, or obsolete).  */
name|cris_ver_warning
block|,
comment|/* Only for v0..3 (Etrax 1..4).  */
name|cris_ver_v0_3
block|,
comment|/* Only for v3 or higher (ETRAX 4 and beyond).  */
name|cris_ver_v3p
block|,
comment|/* Only for v8 (Etrax 100).  */
name|cris_ver_v8
block|,
comment|/* Only for v8 or higher (ETRAX 100, ETRAX 100 LX).  */
name|cris_ver_v8p
block|,
comment|/* Only for v0..10.  FIXME: Not sure what to do with this.  */
name|cris_ver_sim_v0_10
block|,
comment|/* Only for v0..10.  */
name|cris_ver_v0_10
block|,
comment|/* Only for v3..10.  (ETRAX 4, ETRAX 100 and ETRAX 100 LX).  */
name|cris_ver_v3_10
block|,
comment|/* Only for v8..10 (ETRAX 100 and ETRAX 100 LX).  */
name|cris_ver_v8_10
block|,
comment|/* Only for v10 (ETRAX 100 LX) and same series.  */
name|cris_ver_v10
block|,
comment|/* Only for v10 (ETRAX 100 LX) and same series.  */
name|cris_ver_v10p
block|,
comment|/* Only for v32 or higher (codename GUINNESS).      Of course some or all these of may change to cris_ver_v32p if/when      there's a new revision. */
name|cris_ver_v32p
block|}
enum|;
end_enum

begin_comment
comment|/* Special registers.  */
end_comment

begin_struct
struct|struct
name|cris_spec_reg
block|{
specifier|const
name|char
modifier|*
specifier|const
name|name
decl_stmt|;
name|unsigned
name|int
name|number
decl_stmt|;
comment|/* The size of the register.  */
name|unsigned
name|int
name|reg_size
decl_stmt|;
comment|/* What CPU version the special register of that name is implemented      in.  If cris_ver_warning, emit an unimplemented-warning.  */
name|enum
name|cris_insn_version_usage
name|applicable_version
decl_stmt|;
comment|/* There might be a specific warning for using a special register      here.  */
specifier|const
name|char
modifier|*
specifier|const
name|warning
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|cris_spec_reg
name|cris_spec_regs
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Support registers (kind of special too, but not named as such).  */
end_comment

begin_struct
struct|struct
name|cris_support_reg
block|{
specifier|const
name|char
modifier|*
specifier|const
name|name
decl_stmt|;
name|unsigned
name|int
name|number
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|cris_support_reg
name|cris_support_regs
index|[]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|cris_cond15
block|{
comment|/* The name of the condition.  */
specifier|const
name|char
modifier|*
specifier|const
name|name
decl_stmt|;
comment|/* What CPU version this condition name applies to.  */
name|enum
name|cris_insn_version_usage
name|applicable_version
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|cris_cond15
name|cris_conds15
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Opcode-dependent constants.  */
end_comment

begin_define
define|#
directive|define
name|AUTOINCR_BIT
value|(0x04)
end_define

begin_comment
comment|/* Prefixes.  */
end_comment

begin_define
define|#
directive|define
name|BDAP_QUICK_OPCODE
value|(0x0100)
end_define

begin_define
define|#
directive|define
name|BDAP_QUICK_Z_BITS
value|(0x0e00)
end_define

begin_define
define|#
directive|define
name|BIAP_OPCODE
value|(0x0540)
end_define

begin_define
define|#
directive|define
name|BIAP_Z_BITS
value|(0x0a80)
end_define

begin_define
define|#
directive|define
name|DIP_OPCODE
value|(0x0970)
end_define

begin_define
define|#
directive|define
name|DIP_Z_BITS
value|(0xf280)
end_define

begin_define
define|#
directive|define
name|BDAP_INDIR_LOW
value|(0x40)
end_define

begin_define
define|#
directive|define
name|BDAP_INDIR_LOW_Z
value|(0x80)
end_define

begin_define
define|#
directive|define
name|BDAP_INDIR_HIGH
value|(0x09)
end_define

begin_define
define|#
directive|define
name|BDAP_INDIR_HIGH_Z
value|(0x02)
end_define

begin_define
define|#
directive|define
name|BDAP_INDIR_OPCODE
value|(BDAP_INDIR_HIGH * 0x0100 + BDAP_INDIR_LOW)
end_define

begin_define
define|#
directive|define
name|BDAP_INDIR_Z_BITS
value|(BDAP_INDIR_HIGH_Z * 0x100 + BDAP_INDIR_LOW_Z)
end_define

begin_define
define|#
directive|define
name|BDAP_PC_LOW
value|(BDAP_INDIR_LOW + REG_PC)
end_define

begin_define
define|#
directive|define
name|BDAP_INCR_HIGH
value|(BDAP_INDIR_HIGH + AUTOINCR_BIT)
end_define

begin_comment
comment|/* No prefix must have this code for its "match" bits in the    opcode-table.  "BCC .+2" will do nicely.  */
end_comment

begin_define
define|#
directive|define
name|NO_CRIS_PREFIX
value|0
end_define

begin_comment
comment|/* Definitions for condition codes.  */
end_comment

begin_define
define|#
directive|define
name|CC_CC
value|0x0
end_define

begin_define
define|#
directive|define
name|CC_HS
value|0x0
end_define

begin_define
define|#
directive|define
name|CC_CS
value|0x1
end_define

begin_define
define|#
directive|define
name|CC_LO
value|0x1
end_define

begin_define
define|#
directive|define
name|CC_NE
value|0x2
end_define

begin_define
define|#
directive|define
name|CC_EQ
value|0x3
end_define

begin_define
define|#
directive|define
name|CC_VC
value|0x4
end_define

begin_define
define|#
directive|define
name|CC_VS
value|0x5
end_define

begin_define
define|#
directive|define
name|CC_PL
value|0x6
end_define

begin_define
define|#
directive|define
name|CC_MI
value|0x7
end_define

begin_define
define|#
directive|define
name|CC_LS
value|0x8
end_define

begin_define
define|#
directive|define
name|CC_HI
value|0x9
end_define

begin_define
define|#
directive|define
name|CC_GE
value|0xA
end_define

begin_define
define|#
directive|define
name|CC_LT
value|0xB
end_define

begin_define
define|#
directive|define
name|CC_GT
value|0xC
end_define

begin_define
define|#
directive|define
name|CC_LE
value|0xD
end_define

begin_define
define|#
directive|define
name|CC_A
value|0xE
end_define

begin_define
define|#
directive|define
name|CC_EXT
value|0xF
end_define

begin_comment
comment|/* A table of strings "cc", "cs"... indexed with condition code    values as above.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|cris_cc_strings
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Bcc quick.  */
end_comment

begin_define
define|#
directive|define
name|BRANCH_QUICK_LOW
value|(0)
end_define

begin_define
define|#
directive|define
name|BRANCH_QUICK_HIGH
value|(0)
end_define

begin_define
define|#
directive|define
name|BRANCH_QUICK_OPCODE
value|(BRANCH_QUICK_HIGH * 0x0100 + BRANCH_QUICK_LOW)
end_define

begin_define
define|#
directive|define
name|BRANCH_QUICK_Z_BITS
value|(0x0F00)
end_define

begin_comment
comment|/* BA quick.  */
end_comment

begin_define
define|#
directive|define
name|BA_QUICK_HIGH
value|(BRANCH_QUICK_HIGH + CC_A * 0x10)
end_define

begin_define
define|#
directive|define
name|BA_QUICK_OPCODE
value|(BA_QUICK_HIGH * 0x100 + BRANCH_QUICK_LOW)
end_define

begin_comment
comment|/* Bcc [PC+].  */
end_comment

begin_define
define|#
directive|define
name|BRANCH_PC_LOW
value|(0xFF)
end_define

begin_define
define|#
directive|define
name|BRANCH_INCR_HIGH
value|(0x0D)
end_define

begin_define
define|#
directive|define
name|BA_PC_INCR_OPCODE
define|\
value|((BRANCH_INCR_HIGH + CC_A * 0x10) * 0x0100 + BRANCH_PC_LOW)
end_define

begin_comment
comment|/* Jump.  */
end_comment

begin_comment
comment|/* Note that old versions generated special register 8 (in high bits)    and not-that-old versions recognized it as a jump-instruction.    That opcode now belongs to JUMPU.  */
end_comment

begin_define
define|#
directive|define
name|JUMP_INDIR_OPCODE
value|(0x0930)
end_define

begin_define
define|#
directive|define
name|JUMP_INDIR_Z_BITS
value|(0xf2c0)
end_define

begin_define
define|#
directive|define
name|JUMP_PC_INCR_OPCODE
define|\
value|(JUMP_INDIR_OPCODE + AUTOINCR_BIT * 0x0100 + REG_PC)
end_define

begin_define
define|#
directive|define
name|MOVE_M_TO_PREG_OPCODE
value|0x0a30
end_define

begin_define
define|#
directive|define
name|MOVE_M_TO_PREG_ZBITS
value|0x01c0
end_define

begin_comment
comment|/* BDAP.D N,PC.  */
end_comment

begin_define
define|#
directive|define
name|MOVE_PC_INCR_OPCODE_PREFIX
define|\
value|(((BDAP_INCR_HIGH | (REG_PC<< 4))<< 8) | BDAP_PC_LOW | (2<< 4))
end_define

begin_define
define|#
directive|define
name|MOVE_PC_INCR_OPCODE_SUFFIX
define|\
value|(MOVE_M_TO_PREG_OPCODE | REG_PC | (AUTOINCR_BIT<< 8))
end_define

begin_define
define|#
directive|define
name|JUMP_PC_INCR_OPCODE_V32
value|(0x0DBF)
end_define

begin_comment
comment|/* BA DWORD (V32).  */
end_comment

begin_define
define|#
directive|define
name|BA_DWORD_OPCODE
value|(0x0EBF)
end_define

begin_comment
comment|/* Nop.  */
end_comment

begin_define
define|#
directive|define
name|NOP_OPCODE
value|(0x050F)
end_define

begin_define
define|#
directive|define
name|NOP_Z_BITS
value|(0xFFFF ^ NOP_OPCODE)
end_define

begin_define
define|#
directive|define
name|NOP_OPCODE_V32
value|(0x05B0)
end_define

begin_define
define|#
directive|define
name|NOP_Z_BITS_V32
value|(0xFFFF ^ NOP_OPCODE_V32)
end_define

begin_comment
comment|/* For the compatibility mode, let's use "MOVE R0,P0".  Doesn't affect    registers or flags.  Unfortunately shuts off interrupts for one cycle    for< v32, but there doesn't seem to be any alternative without that    effect.  */
end_comment

begin_define
define|#
directive|define
name|NOP_OPCODE_COMMON
value|(0x630)
end_define

begin_define
define|#
directive|define
name|NOP_OPCODE_ZBITS_COMMON
value|(0xffff& ~NOP_OPCODE_COMMON)
end_define

begin_comment
comment|/* LAPC.D  */
end_comment

begin_define
define|#
directive|define
name|LAPC_DWORD_OPCODE
value|(0x0D7F)
end_define

begin_define
define|#
directive|define
name|LAPC_DWORD_Z_BITS
value|(0x0fff& ~LAPC_DWORD_OPCODE)
end_define

begin_comment
comment|/* Structure of an opcode table entry.  */
end_comment

begin_enum
enum|enum
name|cris_imm_oprnd_size_type
block|{
comment|/* No size is applicable.  */
name|SIZE_NONE
block|,
comment|/* Always 32 bits.  */
name|SIZE_FIX_32
block|,
comment|/* Indicated by size of special register.  */
name|SIZE_SPEC_REG
block|,
comment|/* Indicated by size field, signed.  */
name|SIZE_FIELD_SIGNED
block|,
comment|/* Indicated by size field, unsigned.  */
name|SIZE_FIELD_UNSIGNED
block|,
comment|/* Indicated by size field, no sign implied.  */
name|SIZE_FIELD
block|}
enum|;
end_enum

begin_comment
comment|/* For GDB.  FIXME: Is this the best way to handle opcode    interpretation?  */
end_comment

begin_enum
enum|enum
name|cris_op_type
block|{
name|cris_not_implemented_op
init|=
literal|0
block|,
name|cris_abs_op
block|,
name|cris_addi_op
block|,
name|cris_asr_op
block|,
name|cris_asrq_op
block|,
name|cris_ax_ei_setf_op
block|,
name|cris_bdap_prefix
block|,
name|cris_biap_prefix
block|,
name|cris_break_op
block|,
name|cris_btst_nop_op
block|,
name|cris_clearf_di_op
block|,
name|cris_dip_prefix
block|,
name|cris_dstep_logshift_mstep_neg_not_op
block|,
name|cris_eight_bit_offset_branch_op
block|,
name|cris_move_mem_to_reg_movem_op
block|,
name|cris_move_reg_to_mem_movem_op
block|,
name|cris_move_to_preg_op
block|,
name|cris_muls_op
block|,
name|cris_mulu_op
block|,
name|cris_none_reg_mode_add_sub_cmp_and_or_move_op
block|,
name|cris_none_reg_mode_clear_test_op
block|,
name|cris_none_reg_mode_jump_op
block|,
name|cris_none_reg_mode_move_from_preg_op
block|,
name|cris_quick_mode_add_sub_op
block|,
name|cris_quick_mode_and_cmp_move_or_op
block|,
name|cris_quick_mode_bdap_prefix
block|,
name|cris_reg_mode_add_sub_cmp_and_or_move_op
block|,
name|cris_reg_mode_clear_op
block|,
name|cris_reg_mode_jump_op
block|,
name|cris_reg_mode_move_from_preg_op
block|,
name|cris_reg_mode_test_op
block|,
name|cris_scc_op
block|,
name|cris_sixteen_bit_offset_branch_op
block|,
name|cris_three_operand_add_sub_cmp_and_or_op
block|,
name|cris_three_operand_bound_op
block|,
name|cris_two_operand_bound_op
block|,
name|cris_xor_op
block|}
enum|;
end_enum

begin_struct
struct|struct
name|cris_opcode
block|{
comment|/* The name of the insn.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Bits that must be 1 for a match.  */
name|unsigned
name|int
name|match
decl_stmt|;
comment|/* Bits that must be 0 for a match.  */
name|unsigned
name|int
name|lose
decl_stmt|;
comment|/* See the table in "opcodes/cris-opc.c".  */
specifier|const
name|char
modifier|*
name|args
decl_stmt|;
comment|/* Nonzero if this is a delayed branch instruction.  */
name|char
name|delayed
decl_stmt|;
comment|/* Size of immediate operands.  */
name|enum
name|cris_imm_oprnd_size_type
name|imm_oprnd_size
decl_stmt|;
comment|/* Indicates which version this insn was first implemented in.  */
name|enum
name|cris_insn_version_usage
name|applicable_version
decl_stmt|;
comment|/* What kind of operation this is.  */
name|enum
name|cris_op_type
name|op
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|cris_opcode
name|cris_opcodes
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* These macros are for the target-specific flags in disassemble_info    used at disassembly.  */
end_comment

begin_comment
comment|/* This insn accesses memory.  This flag is more trustworthy than    checking insn_type for "dis_dref" which does not work for    e.g. "JSR [foo]".  */
end_comment

begin_define
define|#
directive|define
name|CRIS_DIS_FLAG_MEMREF
value|(1<< 0)
end_define

begin_comment
comment|/* The "target" field holds a register number.  */
end_comment

begin_define
define|#
directive|define
name|CRIS_DIS_FLAG_MEM_TARGET_IS_REG
value|(1<< 1)
end_define

begin_comment
comment|/* The "target2" field holds a register number; add it to "target".  */
end_comment

begin_define
define|#
directive|define
name|CRIS_DIS_FLAG_MEM_TARGET2_IS_REG
value|(1<< 2)
end_define

begin_comment
comment|/* Yet another add-on: the register in "target2" must be multiplied    by 2 before adding to "target".  */
end_comment

begin_define
define|#
directive|define
name|CRIS_DIS_FLAG_MEM_TARGET2_MULT2
value|(1<< 3)
end_define

begin_comment
comment|/* Yet another add-on: the register in "target2" must be multiplied    by 4 (mutually exclusive with .._MULT2).  */
end_comment

begin_define
define|#
directive|define
name|CRIS_DIS_FLAG_MEM_TARGET2_MULT4
value|(1<< 4)
end_define

begin_comment
comment|/* The register in "target2" is an indirect memory reference (of the    register there), add to "target".  Assumed size is dword (mutually    exclusive with .._MULT[24]).  */
end_comment

begin_define
define|#
directive|define
name|CRIS_DIS_FLAG_MEM_TARGET2_MEM
value|(1<< 5)
end_define

begin_comment
comment|/* Add-on to CRIS_DIS_FLAG_MEM_TARGET2_MEM; the memory access is "byte";    sign-extended before adding to "target".  */
end_comment

begin_define
define|#
directive|define
name|CRIS_DIS_FLAG_MEM_TARGET2_MEM_BYTE
value|(1<< 6)
end_define

begin_comment
comment|/* Add-on to CRIS_DIS_FLAG_MEM_TARGET2_MEM; the memory access is "word";    sign-extended before adding to "target".  */
end_comment

begin_define
define|#
directive|define
name|CRIS_DIS_FLAG_MEM_TARGET2_MEM_WORD
value|(1<< 7)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CRIS_H_INCLUDED_ */
end_comment

begin_comment
comment|/*  * Local variables:  * eval: (c-set-style "gnu")  * indent-tabs-mode: t  * End:  */
end_comment

end_unit

