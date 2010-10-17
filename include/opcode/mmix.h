begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mmix.h -- Header file for MMIX opcode table    Copyright (C) 2001, 2003 Free Software Foundation, Inc.    Written by Hans-Peter Nilsson (hp@bitrange.com)  This file is part of GDB, GAS, and the GNU binutils.  GDB, GAS, and the GNU binutils are free software; you can redistribute them and/or modify them under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GDB, GAS, and the GNU binutils are distributed in the hope that they will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this file; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* We could have just a char*[] table indexed by the register number, but    that would not allow for synonyms.  The table is terminated with an    entry with a NULL name.  */
end_comment

begin_struct
struct|struct
name|mmix_spec_reg
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|unsigned
name|int
name|number
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* General indication of the type of instruction.  */
end_comment

begin_enum
enum|enum
name|mmix_insn_type
block|{
name|mmix_type_pseudo
block|,
name|mmix_type_normal
block|,
name|mmix_type_branch
block|,
name|mmix_type_condbranch
block|,
name|mmix_type_memaccess_octa
block|,
name|mmix_type_memaccess_tetra
block|,
name|mmix_type_memaccess_wyde
block|,
name|mmix_type_memaccess_byte
block|,
name|mmix_type_memaccess_block
block|,
name|mmix_type_jsr
block|}
enum|;
end_enum

begin_comment
comment|/* Type of operands an instruction takes.  Use when parsing assembly code    and disassembling.  */
end_comment

begin_enum
enum|enum
name|mmix_operands_type
block|{
name|mmix_operands_none
init|=
literal|0
block|,
comment|/* All operands are registers: "$X,$Y,$Z".  */
name|mmix_operands_regs
block|,
comment|/* "$X,YZ", like SETH.  */
name|mmix_operands_reg_yz
block|,
comment|/* The regular "$X,$Y,$Z|Z".       The Z is optional; if only "$X,$Y" is given, then "$X,$Y,0" is       assumed.  */
name|mmix_operands_regs_z_opt
block|,
comment|/* The regular "$X,$Y,$Z|Z".  */
name|mmix_operands_regs_z
block|,
comment|/* "Address"; only JMP.  Zero operands allowed unless GNU syntax.  */
name|mmix_operands_jmp
block|,
comment|/* "$X|X,$Y,$Z|Z": PUSHGO; like "3", but X can be expressed as an       integer.  */
name|mmix_operands_pushgo
block|,
comment|/* Two registers or a register and a byte, like FLOT, possibly with       rounding: "$X,$Z|Z" or "$X,ROUND_MODE,$Z|Z".  */
name|mmix_operands_roundregs_z
block|,
comment|/* "X,YZ", POP.  Unless GNU syntax, zero or one operand is allowed.  */
name|mmix_operands_pop
block|,
comment|/* Two registers, possibly with rounding: "$X,$Z" or       "$X,ROUND_MODE,$Z".  */
name|mmix_operands_roundregs
block|,
comment|/* "XYZ", like SYNC.  */
name|mmix_operands_sync
block|,
comment|/* "X,$Y,$Z|Z", like SYNCD.  */
name|mmix_operands_x_regs_z
block|,
comment|/* "$X,Y,$Z|Z", like NEG and NEGU.  The Y field is optional, default 0.  */
name|mmix_operands_neg
block|,
comment|/* "$X,Address, like GETA or branches.  */
name|mmix_operands_regaddr
block|,
comment|/* "$X|X,Address, like PUSHJ.  */
name|mmix_operands_pushj
block|,
comment|/* "$X,spec_reg"; GET.  */
name|mmix_operands_get
block|,
comment|/* "spec_reg,$Z|Z"; PUT.  */
name|mmix_operands_put
block|,
comment|/* Two registers, "$X,$Y".  */
name|mmix_operands_set
block|,
comment|/* "$X,0"; SAVE.  */
name|mmix_operands_save
block|,
comment|/* "0,$Z"; UNSAVE. */
name|mmix_operands_unsave
block|,
comment|/* "X,Y,Z"; like SWYM or TRAP.  Zero (or 1 if GNU syntax) to three       operands, interpreted as 0; XYZ; X, YZ and X, Y, Z.  */
name|mmix_operands_xyz_opt
block|,
comment|/* Just "Z", like RESUME.  Unless GNU syntax, the operand can be omitted       and will then be assumed zero.  */
name|mmix_operands_resume
block|,
comment|/* These are specials to handle that pseudo-directives are specified       like ordinary insns when being mmixal-compatible.  They signify the       specific pseudo-directive rather than the operands type.  */
comment|/* LOC.  */
name|mmix_operands_loc
block|,
comment|/* PREFIX.  */
name|mmix_operands_prefix
block|,
comment|/* BYTE.  */
name|mmix_operands_byte
block|,
comment|/* WYDE.  */
name|mmix_operands_wyde
block|,
comment|/* TETRA.  */
name|mmix_operands_tetra
block|,
comment|/* OCTA.  */
name|mmix_operands_octa
block|,
comment|/* LOCAL.  */
name|mmix_operands_local
block|,
comment|/* BSPEC.  */
name|mmix_operands_bspec
block|,
comment|/* ESPEC.  */
name|mmix_operands_espec
block|,  }
enum|;
end_enum

begin_struct
struct|struct
name|mmix_opcode
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|unsigned
name|long
name|match
decl_stmt|;
name|unsigned
name|long
name|lose
decl_stmt|;
name|enum
name|mmix_operands_type
name|operands
decl_stmt|;
comment|/* This is used by the disassembly function.  */
name|enum
name|mmix_insn_type
name|type
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Declare the actual tables.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|mmix_opcode
name|mmix_opcodes
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This one is terminated with an entry with a NULL name.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|mmix_spec_reg
name|mmix_spec_regs
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Some insn values we use when padding and synthesizing address loads.  */
end_comment

begin_define
define|#
directive|define
name|IMM_OFFSET_BIT
value|1
end_define

begin_define
define|#
directive|define
name|COND_INV_BIT
value|0x8
end_define

begin_define
define|#
directive|define
name|PRED_INV_BIT
value|0x10
end_define

begin_define
define|#
directive|define
name|PUSHGO_INSN_BYTE
value|0xbe
end_define

begin_define
define|#
directive|define
name|GO_INSN_BYTE
value|0x9e
end_define

begin_define
define|#
directive|define
name|SETL_INSN_BYTE
value|0xe3
end_define

begin_define
define|#
directive|define
name|INCML_INSN_BYTE
value|0xe6
end_define

begin_define
define|#
directive|define
name|INCMH_INSN_BYTE
value|0xe5
end_define

begin_define
define|#
directive|define
name|INCH_INSN_BYTE
value|0xe4
end_define

begin_define
define|#
directive|define
name|SWYM_INSN_BYTE
value|0xfd
end_define

begin_define
define|#
directive|define
name|JMP_INSN_BYTE
value|0xf0
end_define

begin_comment
comment|/* We can have 256 - 32 (local registers) - 1 ($255 is not allocatable)    global registers.  */
end_comment

begin_define
define|#
directive|define
name|MAX_GREGS
value|223
end_define

end_unit

