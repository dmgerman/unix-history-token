begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Tree inlining hooks and declarations.    Copyright 2001 Free Software Foundation, Inc.    Contributed by Alexandre Oliva<aoliva@redhat.com>  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_TREE_INLINE_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_TREE_INLINE_H
end_define

begin_comment
comment|/* Function prototypes.  */
end_comment

begin_decl_stmt
name|void
name|optimize_inline_calls
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tree_inlinable_function_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tree
name|walk_tree
name|PARAMS
argument_list|(
operator|(
name|tree
operator|*
operator|,
name|walk_tree_fn
operator|,
name|void
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tree
name|walk_tree_without_duplicates
name|PARAMS
argument_list|(
operator|(
name|tree
operator|*
operator|,
name|walk_tree_fn
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tree
name|copy_tree_r
name|PARAMS
argument_list|(
operator|(
name|tree
operator|*
operator|,
name|int
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|clone_body
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|remap_save_expr
name|PARAMS
argument_list|(
operator|(
name|tree
operator|*
operator|,
name|void
operator|*
operator|,
name|tree
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0 if we should not perform inlining.    1 if we should expand functions calls inline at the tree level.      2 if we should consider *all* functions to be inline     candidates.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_inline_trees
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_TREE_INLINE_H */
end_comment

end_unit

