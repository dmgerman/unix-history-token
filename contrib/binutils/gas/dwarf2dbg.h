begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dwarf2dbg.h - DWARF2 debug support    Copyright 1999, 2000 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AS_DWARF2DBG_H
end_ifndef

begin_define
define|#
directive|define
name|AS_DWARF2DBG_H
end_define

begin_include
include|#
directive|include
file|"as.h"
end_include

begin_define
define|#
directive|define
name|DWARF2_FLAG_BEGIN_STMT
value|(1<< 0)
end_define

begin_comment
comment|/* beginning of statement */
end_comment

begin_define
define|#
directive|define
name|DWARF2_FLAG_BEGIN_BLOCK
value|(1<< 1)
end_define

begin_comment
comment|/* beginning of basic block */
end_comment

begin_struct
struct|struct
name|dwarf2_line_info
block|{
name|unsigned
name|int
name|filenum
decl_stmt|;
name|unsigned
name|int
name|line
decl_stmt|;
name|unsigned
name|int
name|column
decl_stmt|;
name|unsigned
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Implements the .file FILENO "FILENAME" directive.  FILENO can be 0    to indicate that no file number has been assigned.  All real file    number must be>0.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|dwarf2_directive_file
name|PARAMS
argument_list|(
operator|(
name|int
name|dummy
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Implements the .loc FILENO LINENO [COLUMN] directive.  FILENO is    the file number, LINENO the line number and the (optional) COLUMN    the column of the source code that the following instruction    corresponds to.  FILENO can be 0 to indicate that the filename    specified by the textually most recent .file directive should be    used.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|dwarf2_directive_loc
name|PARAMS
argument_list|(
operator|(
name|int
name|dummy
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Returns the current source information.  If .file directives have    been encountered, the info for the corresponding source file is    returned.  Otherwise, the info for the assembly source file is    returned.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|dwarf2_where
name|PARAMS
argument_list|(
operator|(
expr|struct
name|dwarf2_line_info
operator|*
name|l
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This function generates .debug_line info based on the address and    source information passed in the arguments.  ADDR should be the    frag-relative offset of the instruction the information is for and    L is the source information that should be associated with that    address.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|dwarf2_gen_line_info
name|PARAMS
argument_list|(
operator|(
name|addressT
name|addr
operator|,
expr|struct
name|dwarf2_line_info
operator|*
name|l
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Must be called for each generated instruction.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|dwarf2_emit_insn
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dwarf2_finish
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dwarf2dbg_estimate_size_before_relax
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dwarf2dbg_relax_frag
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dwarf2dbg_convert_frag
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AS_DWARF2DBG_H */
end_comment

end_unit

