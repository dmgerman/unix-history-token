begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* DWARF2 frame unwind data structure.    Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003    Free Software Foundation, Inc.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     In addition to the permissions in the GNU General Public License, the    Free Software Foundation gives you unlimited permission to link the    compiled version of this file into combinations with other programs,    and to distribute those combinations without any restriction coming    from the use of this file.  (The General Public License restrictions    do apply in other respects; for example, they cover modification of    the file, and distribution when not linked into a combined    executable.)     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_comment
comment|/* A target can override (perhaps for backward compatibility) how    many dwarf2 columns are unwound.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DWARF_FRAME_REGISTERS
end_ifndef

begin_define
define|#
directive|define
name|DWARF_FRAME_REGISTERS
value|FIRST_PSEUDO_REGISTER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The result of interpreting the frame unwind info for a frame.    This is all symbolic at this point, as none of the values can    be resolved until the target pc is located.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Each register save state can be described in terms of a CFA slot,      another register, or a location expression.  */
struct|struct
name|frame_state_reg_info
block|{
struct|struct
block|{
union|union
block|{
name|_Unwind_Word
name|reg
decl_stmt|;
name|_Unwind_Sword
name|offset
decl_stmt|;
specifier|const
name|unsigned
name|char
modifier|*
name|exp
decl_stmt|;
block|}
name|loc
union|;
enum|enum
block|{
name|REG_UNSAVED
block|,
name|REG_SAVED_OFFSET
block|,
name|REG_SAVED_REG
block|,
name|REG_SAVED_EXP
block|,
name|REG_SAVED_VAL_OFFSET
block|,
name|REG_SAVED_VAL_EXP
block|}
name|how
enum|;
block|}
name|reg
index|[
name|DWARF_FRAME_REGISTERS
operator|+
literal|1
index|]
struct|;
comment|/* Used to implement DW_CFA_remember_state.  */
name|struct
name|frame_state_reg_info
modifier|*
name|prev
decl_stmt|;
block|}
name|regs
struct|;
comment|/* The CFA can be described in terms of a reg+offset or a      location expression.  */
name|_Unwind_Sword
name|cfa_offset
decl_stmt|;
name|_Unwind_Word
name|cfa_reg
decl_stmt|;
specifier|const
name|unsigned
name|char
modifier|*
name|cfa_exp
decl_stmt|;
enum|enum
block|{
name|CFA_UNSET
block|,
name|CFA_REG_OFFSET
block|,
name|CFA_EXP
block|}
name|cfa_how
enum|;
comment|/* The PC described by the current frame state.  */
name|void
modifier|*
name|pc
decl_stmt|;
comment|/* The information we care about from the CIE/FDE.  */
name|_Unwind_Personality_Fn
name|personality
decl_stmt|;
name|_Unwind_Sword
name|data_align
decl_stmt|;
name|_Unwind_Word
name|code_align
decl_stmt|;
name|_Unwind_Word
name|retaddr_column
decl_stmt|;
name|unsigned
name|char
name|fde_encoding
decl_stmt|;
name|unsigned
name|char
name|lsda_encoding
decl_stmt|;
name|unsigned
name|char
name|saw_z
decl_stmt|;
name|unsigned
name|char
name|signal_frame
decl_stmt|;
name|void
modifier|*
name|eh_ptr
decl_stmt|;
block|}
name|_Unwind_FrameState
typedef|;
end_typedef

end_unit

