begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ternary.h - Ternary Search Trees    Copyright 2001 Free Software Foundation, Inc.     Contributed by Daniel Berlin (dan@cgsoftware.com)      This program is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by the    Free Software Foundation; either version 2, or (at your option) any    later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307,    USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TERNARY_H_
end_ifndef

begin_define
define|#
directive|define
name|TERNARY_H_
end_define

begin_comment
comment|/* Ternary search trees */
end_comment

begin_typedef
typedef|typedef
name|struct
name|ternary_node_def
modifier|*
name|ternary_tree
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ternary_node_def
block|{
name|char
name|splitchar
decl_stmt|;
name|ternary_tree
name|lokid
decl_stmt|;
name|ternary_tree
name|eqkid
decl_stmt|;
name|ternary_tree
name|hikid
decl_stmt|;
block|}
name|ternary_node
typedef|;
end_typedef

begin_comment
comment|/* Insert string S into tree P, associating it with DATA.     Return the data in the tree associated with the string if it's    already there, and replace is 0.    Otherwise, replaces if it it exists, inserts if it doesn't, and    returns the data you passed in. */
end_comment

begin_decl_stmt
name|PTR
name|ternary_insert
name|PARAMS
argument_list|(
operator|(
name|ternary_tree
operator|*
name|p
operator|,
specifier|const
name|char
operator|*
name|s
operator|,
name|PTR
name|data
operator|,
name|int
name|replace
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Delete the ternary search tree rooted at P.     Does NOT delete the data you associated with the strings. */
end_comment

begin_decl_stmt
name|void
name|ternary_cleanup
name|PARAMS
argument_list|(
operator|(
name|ternary_tree
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Search the ternary tree for string S, returning the data associated    with it if found. */
end_comment

begin_decl_stmt
name|PTR
name|ternary_search
name|PARAMS
argument_list|(
operator|(
specifier|const
name|ternary_node
operator|*
name|p
operator|,
specifier|const
name|char
operator|*
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

