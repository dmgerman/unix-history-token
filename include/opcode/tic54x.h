begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tic54x.h -- Header file for TI TMS320C54X opcode table    Copyright 1999, 2000 Free Software Foundation, Inc.    Written by Timothy Wall (twall@cygnus.com)  This file is part of GDB, GAS, and the GNU binutils.  GDB, GAS, and the GNU binutils are free software; you can redistribute them and/or modify them under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB, GAS, and the GNU binutils are distributed in the hope that they will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this file; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_opcode_tic54x_h_
end_ifndef

begin_define
define|#
directive|define
name|_opcode_tic54x_h_
end_define

begin_typedef
typedef|typedef
struct|struct
name|_symbol
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|unsigned
name|short
name|value
decl_stmt|;
block|}
name|symbol
typedef|;
end_typedef

begin_enum
enum|enum
name|optype
block|{
name|OPT
init|=
literal|0x8000
block|,
name|OP_None
init|=
literal|0x0
block|,
name|OP_Xmem
block|,
comment|/* AR3 or AR4, indirect */
name|OP_Ymem
block|,
comment|/* AR3 or AR4, indirect */
name|OP_pmad
block|,
comment|/* PROG mem, direct */
name|OP_dmad
block|,
comment|/* DATA mem, direct */
name|OP_Smem
block|,
name|OP_Lmem
block|,
comment|/* 32-bit single-addressed (direct/indirect) */
name|OP_MMR
block|,
name|OP_PA
block|,
name|OP_Sind
block|,
name|OP_xpmad
block|,
name|OP_xpmad_ms7
block|,
name|OP_MMRX
block|,
name|OP_MMRY
block|,
name|OP_SRC1
block|,
comment|/* src accumulator in bit 8 */
name|OP_SRC
block|,
comment|/* src accumulator in bit 9 */
name|OP_RND
block|,
comment|/* rounded result dst accumulator, opposite of bit 8 */
name|OP_DST
block|,
comment|/* dst accumulator in bit 8 */
name|OP_ARX
block|,
comment|/* arX in bits 0-3 */
name|OP_SHIFT
block|,
comment|/* -16 to 15 (SHIFT), bits 0-4 */
name|OP_SHFT
block|,
comment|/*   0 to 15 (SHIFT1 in summary), bits 0-3 */
name|OP_B
block|,
comment|/* ACC B only */
name|OP_A
block|,
comment|/* ACC A only */
name|OP_lk
block|,
comment|/* 16-bit immediate, '#' optional */
name|OP_TS
block|,
name|OP_k8
block|,
comment|/* -128<= k<= 128 */
name|OP_16
block|,
comment|/* literal "16" */
name|OP_BITC
block|,
comment|/* 0 to 16 */
name|OP_CC
block|,
comment|/* condition code */
name|OP_CC2
block|,
comment|/* 4-bit condition code */
name|OP_CC3
block|,
comment|/* 2-bit condition code */
name|OP_123
block|,
comment|/* 1, 2, or 3 */
name|OP_031
block|,
comment|/* 0-31, numeric */
name|OP_k5
block|,
comment|/* 0 to 31 */
name|OP_k8u
block|,
comment|/* 0 to 255 */
name|OP_ASM
block|,
comment|/* "ASM" */
name|OP_T
block|,
comment|/* "T" */
name|OP_DP
block|,
comment|/* "DP" */
name|OP_ARP
block|,
comment|/* "ARP" */
name|OP_k3
block|,
comment|/* 0-7 */
name|OP_lku
block|,
comment|/* 0 to 65535 */
name|OP_N
block|,
comment|/* 0/1 or ST0/ST1 */
name|OP_SBIT
block|,
comment|/* status bit or 0-15 */
name|OP_12
block|,
comment|/* one or two */
name|OP_k9
block|,
comment|/* 9 bits of data page (DP) address */
name|OP_TRN
block|,
comment|/* "TRN" */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
name|_template
block|{
comment|/* The opcode mnemonic */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|unsigned
name|int
name|words
decl_stmt|;
comment|/* insn size in words */
name|int
name|minops
decl_stmt|,
name|maxops
decl_stmt|;
comment|/* min/max operand count */
comment|/* The significant bits in the opcode.  Other bits are zero.       Instructions with more than 16 bits of opcode store the rest in the upper      16 bits.    */
name|unsigned
name|short
name|opcode
decl_stmt|;
define|#
directive|define
name|INDIRECT
parameter_list|(
name|OP
parameter_list|)
value|((OP)&0x80)
define|#
directive|define
name|MOD
parameter_list|(
name|OP
parameter_list|)
value|(((OP)>>3)&0xF)
define|#
directive|define
name|ARF
parameter_list|(
name|OP
parameter_list|)
value|((OP)&0x7)
define|#
directive|define
name|IS_LKADDR
parameter_list|(
name|OP
parameter_list|)
value|(INDIRECT(OP)&& MOD(OP)>=12)
define|#
directive|define
name|SRC
parameter_list|(
name|OP
parameter_list|)
value|((OP)&0x200)
define|#
directive|define
name|DST
parameter_list|(
name|OP
parameter_list|)
value|((OP)&0x100)
define|#
directive|define
name|SRC1
parameter_list|(
name|OP
parameter_list|)
value|((OP)&0x100)
define|#
directive|define
name|SHIFT
parameter_list|(
name|OP
parameter_list|)
value|(((OP)&0x10)?(((OP)&0x1F)-32):((OP)&0x1F))
define|#
directive|define
name|SHFT
parameter_list|(
name|OP
parameter_list|)
value|((OP)&0xF)
define|#
directive|define
name|ARX
parameter_list|(
name|OP
parameter_list|)
value|((OP)&0x7)
define|#
directive|define
name|XMEM
parameter_list|(
name|OP
parameter_list|)
value|(((OP)&0x00F0)>>4)
define|#
directive|define
name|YMEM
parameter_list|(
name|OP
parameter_list|)
value|((OP)&0x000F)
define|#
directive|define
name|XMOD
parameter_list|(
name|C
parameter_list|)
value|(((C)&0xC)>>2)
define|#
directive|define
name|XARX
parameter_list|(
name|C
parameter_list|)
value|(((C)&0x3)+2)
define|#
directive|define
name|CC3
parameter_list|(
name|OP
parameter_list|)
value|(((OP)>>8)&0x3)
define|#
directive|define
name|SBIT
parameter_list|(
name|OP
parameter_list|)
value|((OP)&0xF)
define|#
directive|define
name|MMR
parameter_list|(
name|OP
parameter_list|)
value|((OP)&0x7F)
define|#
directive|define
name|MMRX
parameter_list|(
name|OP
parameter_list|)
value|((((OP)>>4)&0xF)+16)
define|#
directive|define
name|MMRY
parameter_list|(
name|OP
parameter_list|)
value|(((OP)&0xF)+16)
define|#
directive|define
name|OPTYPE
parameter_list|(
name|X
parameter_list|)
value|((X)&~OPT)
comment|/* Ones in this mask indicate which bits must match the opcode field.      Zeroes indicate don't care bits (operands and/or opcode options) */
name|unsigned
name|short
name|mask
decl_stmt|;
comment|/* An array of operand codes (at most 4 operands) */
define|#
directive|define
name|MAX_OPERANDS
value|4
name|enum
name|optype
name|operand_types
index|[
name|MAX_OPERANDS
index|]
decl_stmt|;
comment|/* Special purpose flags (e.g. branch type, parallel, delay, etc)     */
name|unsigned
name|short
name|flags
decl_stmt|;
define|#
directive|define
name|B_NEXT
value|0
comment|/* normal execution, next insn is next address */
define|#
directive|define
name|B_BRANCH
value|1
comment|/* next insn is in opcode */
define|#
directive|define
name|B_RET
value|2
comment|/* next insn is on stack */
define|#
directive|define
name|B_BACC
value|3
comment|/* next insn is in acc */
define|#
directive|define
name|B_REPEAT
value|4
comment|/* next insn repeats */
define|#
directive|define
name|FL_BMASK
value|0x07
define|#
directive|define
name|FL_DELAY
value|0x10
comment|/* instruction uses delay slots */
define|#
directive|define
name|FL_EXT
value|0x20
comment|/* instruction takes two words */
define|#
directive|define
name|FL_FAR
value|0x40
comment|/* far mode addressing */
define|#
directive|define
name|FL_LP
value|0x80
comment|/* LP-only instruction */
define|#
directive|define
name|FL_NR
value|0x100
comment|/* no repeat allowed */
define|#
directive|define
name|FL_SMR
value|0x200
comment|/* Smem read (for flagging write-only *+ARx */
define|#
directive|define
name|FL_PAR
value|0x400
comment|/* Parallel instruction. */
name|unsigned
name|short
name|opcode2
decl_stmt|,
name|mask2
decl_stmt|;
comment|/* some insns have an extended opcode */
specifier|const
name|char
modifier|*
name|parname
decl_stmt|;
name|enum
name|optype
name|paroperand_types
index|[
name|MAX_OPERANDS
index|]
decl_stmt|;
block|}
name|template
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
specifier|const
name|template
name|tic54x_unknown_opcode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|template
name|tic54x_optab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|template
name|tic54x_paroptab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|symbol
name|mmregs
index|[]
decl_stmt|,
name|regs
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|symbol
name|condition_codes
index|[]
decl_stmt|,
name|cc2_codes
index|[]
decl_stmt|,
name|status_bits
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|symbol
name|cc3_codes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|misc_symbols
index|[]
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|disassemble_info
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
specifier|const
name|template
modifier|*
name|tic54x_get_insn
parameter_list|(
name|struct
name|disassemble_info
modifier|*
parameter_list|,
name|bfd_vma
parameter_list|,
name|unsigned
name|short
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _opcode_tic54x_h_ */
end_comment

end_unit

