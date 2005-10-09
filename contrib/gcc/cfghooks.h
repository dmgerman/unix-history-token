begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Hooks for cfg representation specific functions.    Copyright (C) 2003 Free Software Foundation, Inc.    Contributed by Sebastian Pop<s.pop@laposte.net>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_CFGHOOKS_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_CFGHOOKS_H
end_define

begin_struct
struct|struct
name|cfg_hooks
block|{
comment|/* Debugging.  Do not use macros to hook these so they can be called from      debugger!  */
name|int
function_decl|(
modifier|*
name|cfgh_verify_flow_info
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|dump_bb
function_decl|)
parameter_list|(
name|basic_block
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
comment|/* Basic CFG manipulation.  */
comment|/* Return new basic block.  */
name|basic_block
function_decl|(
modifier|*
name|create_basic_block
function_decl|)
parameter_list|(
name|void
modifier|*
name|head
parameter_list|,
name|void
modifier|*
name|end
parameter_list|,
name|basic_block
name|after
parameter_list|)
function_decl|;
comment|/* Redirect edge E to the given basic block B and update underlying program      representation.  Returns false when edge is not easily redirectable for      whatever reason.  */
name|bool
function_decl|(
modifier|*
name|redirect_edge_and_branch
function_decl|)
parameter_list|(
name|edge
name|e
parameter_list|,
name|basic_block
name|b
parameter_list|)
function_decl|;
comment|/* Same as the above but allows redirecting of fallthru edges.  In that case      newly created forwarder basic block is returned.  It aborts when called      on abnormal edge.  */
name|basic_block
function_decl|(
modifier|*
name|redirect_edge_and_branch_force
function_decl|)
parameter_list|(
name|edge
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
comment|/* Remove given basic block and all edges possibly pointing into it.  */
name|void
function_decl|(
modifier|*
name|delete_block
function_decl|)
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
comment|/* Split basic block B after specified instruction I.  */
name|edge
function_decl|(
modifier|*
name|split_block
function_decl|)
parameter_list|(
name|basic_block
name|b
parameter_list|,
name|void
modifier|*
name|i
parameter_list|)
function_decl|;
comment|/* Return true when blocks A and B can be merged into single basic block.  */
name|bool
function_decl|(
modifier|*
name|can_merge_blocks_p
function_decl|)
parameter_list|(
name|basic_block
name|a
parameter_list|,
name|basic_block
name|b
parameter_list|)
function_decl|;
comment|/* Merge blocks A and B.  */
name|void
function_decl|(
modifier|*
name|merge_blocks
function_decl|)
parameter_list|(
name|basic_block
name|a
parameter_list|,
name|basic_block
name|b
parameter_list|)
function_decl|;
comment|/* Higher level functions representable by primitive operations above if      we didn't have some oddities in RTL and Tree representations.  */
name|basic_block
function_decl|(
modifier|*
name|cfgh_split_edge
function_decl|)
parameter_list|(
name|edge
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|redirect_edge_and_branch
parameter_list|(
name|e
parameter_list|,
name|b
parameter_list|)
value|cfg_hooks->redirect_edge_and_branch (e,b)
end_define

begin_define
define|#
directive|define
name|redirect_edge_and_branch_force
parameter_list|(
name|e
parameter_list|,
name|b
parameter_list|)
value|cfg_hooks->redirect_edge_and_branch_force (e,b)
end_define

begin_define
define|#
directive|define
name|split_block
parameter_list|(
name|e
parameter_list|,
name|i
parameter_list|)
value|cfg_hooks->split_block (e,i)
end_define

begin_define
define|#
directive|define
name|delete_block
parameter_list|(
name|b
parameter_list|)
value|cfg_hooks->delete_block (b)
end_define

begin_define
define|#
directive|define
name|split_edge
parameter_list|(
name|e
parameter_list|)
value|cfg_hooks->cfgh_split_edge (e)
end_define

begin_define
define|#
directive|define
name|create_basic_block
parameter_list|(
name|h
parameter_list|,
name|e
parameter_list|,
name|a
parameter_list|)
value|cfg_hooks->create_basic_block (h,e,a)
end_define

begin_define
define|#
directive|define
name|can_merge_blocks_p
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|cfg_hooks->can_merge_blocks_p (a,b)
end_define

begin_define
define|#
directive|define
name|merge_blocks
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|cfg_hooks->merge_blocks (a,b)
end_define

begin_comment
comment|/* Hooks containers.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|cfg_hooks
name|rtl_cfg_hooks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A pointer to one of the hooks containers.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|cfg_hooks
modifier|*
name|cfg_hooks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Declarations.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|rtl_register_cfg_hooks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfg_layout_rtl_register_cfg_hooks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_CFGHOOKS_H */
end_comment

end_unit

