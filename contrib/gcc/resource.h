begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for computing resource usage of specific insns.    Copyright (C) 1999, 2003 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Macro to clear all resources.  */
end_comment

begin_define
define|#
directive|define
name|CLEAR_RESOURCE
parameter_list|(
name|RES
parameter_list|)
define|\
value|do { (RES)->memory = (RES)->unch_memory = (RES)->volatil = (RES)->cc = 0; \       CLEAR_HARD_REG_SET ((RES)->regs); } while (0)
end_define

begin_comment
comment|/* The resources used by a given insn.  */
end_comment

begin_struct
struct|struct
name|resources
block|{
name|char
name|memory
decl_stmt|;
comment|/* Insn sets or needs a memory location.  */
name|char
name|unch_memory
decl_stmt|;
comment|/* Insn sets of needs a "unchanging" MEM.  */
name|char
name|volatil
decl_stmt|;
comment|/* Insn sets or needs a volatile memory loc.  */
name|char
name|cc
decl_stmt|;
comment|/* Insn sets or needs the condition codes.  */
name|HARD_REG_SET
name|regs
decl_stmt|;
comment|/* Which registers are set or needed.  */
block|}
struct|;
end_struct

begin_comment
comment|/* The kinds of rtl mark_*_resources will consider */
end_comment

begin_enum
enum|enum
name|mark_resource_type
block|{
name|MARK_SRC_DEST
init|=
literal|0
block|,
name|MARK_SRC_DEST_CALL
init|=
literal|1
block|}
enum|;
end_enum

begin_function_decl
specifier|extern
name|void
name|mark_target_live_regs
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|struct
name|resources
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mark_set_resources
parameter_list|(
name|rtx
parameter_list|,
name|struct
name|resources
modifier|*
parameter_list|,
name|int
parameter_list|,
name|enum
name|mark_resource_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mark_referenced_resources
parameter_list|(
name|rtx
parameter_list|,
name|struct
name|resources
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|clear_hashed_info_for_insn
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|incr_ticks_for_insn
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mark_end_of_function_resources
parameter_list|(
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_resource_info
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_resource_info
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

