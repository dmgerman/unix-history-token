begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Define control and data flow tables, and regsets.    Copyright (C) 1987 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Number of bits in each actual element of a regset.  */
end_comment

begin_define
define|#
directive|define
name|REGSET_ELT_BITS
value|HOST_BITS_PER_WIDE_INT
end_define

begin_comment
comment|/* Type to use for a regset element.  Note that lots of code assumes    that the initial part of a regset that contains information on the    hard registers is the same format as a HARD_REG_SET.  */
end_comment

begin_define
define|#
directive|define
name|REGSET_ELT_TYPE
value|unsigned HOST_WIDE_INT
end_define

begin_comment
comment|/* Define the type for a pointer to a set with a bit for each    (hard or pseudo) register.  */
end_comment

begin_typedef
typedef|typedef
name|REGSET_ELT_TYPE
modifier|*
name|regset
typedef|;
end_typedef

begin_comment
comment|/* Size of a regset for the current function,    in (1) bytes and (2) elements.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|regset_bytes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|regset_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of basic blocks in the current function.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|n_basic_blocks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Index by basic block number, get first insn in the block.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
modifier|*
name|basic_block_head
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Index by basic block number, get last insn in the block.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
modifier|*
name|basic_block_end
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Index by basic block number, get address of regset    describing the registers live at the start of that block.  */
end_comment

begin_decl_stmt
specifier|extern
name|regset
modifier|*
name|basic_block_live_at_start
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Indexed by n, gives number of basic block that  (REG n) is used in.    If the value is REG_BLOCK_GLOBAL (-2),    it means (REG n) is used in more than one basic block.    REG_BLOCK_UNKNOWN (-1) means it hasn't been seen yet so we don't know.    This information remains valid for the rest of the compilation    of the current function; it is used to control register allocation.  */
end_comment

begin_define
define|#
directive|define
name|REG_BLOCK_UNKNOWN
value|-1
end_define

begin_define
define|#
directive|define
name|REG_BLOCK_GLOBAL
value|-2
end_define

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|reg_basic_block
decl_stmt|;
end_decl_stmt

end_unit

