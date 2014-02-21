begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Utilities for ipa analysis.    Copyright (C) 2004-2005 Free Software Foundation, Inc.    Contributed by Kenneth Zadeck<zadeck@naturalbridge.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_IPA_UTILS_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_IPA_UTILS_H
end_define

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_include
include|#
directive|include
file|"cgraph.h"
end_include

begin_comment
comment|/* Used for parsing attributes of asm code.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|memory_identifier_string
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|ipa_dfs_info
block|{
name|int
name|dfn_number
decl_stmt|;
name|int
name|low_link
decl_stmt|;
name|bool
name|new
decl_stmt|;
name|bool
name|on_stack
decl_stmt|;
name|struct
name|cgraph_node
modifier|*
name|next_cycle
decl_stmt|;
name|PTR
name|aux
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* In ipa-utils.c  */
end_comment

begin_function_decl
name|void
name|ipa_utils_print_order
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|cgraph_node
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipa_utils_reduced_inorder
parameter_list|(
name|struct
name|cgraph_node
modifier|*
modifier|*
parameter_list|,
name|bool
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|get_base_var
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_IPA_UTILS_H  */
end_comment

end_unit

