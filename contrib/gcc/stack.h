begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* stack.h - structed access to object stacks    Copyright (C) 1988 Free Software Foundation, Inc.    Contributed by Michael Tiemann (tiemann@cygnus.com).  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Summary: this file contains additional structures that layer    on top of obstacks for GNU C++.  */
end_comment

begin_comment
comment|/* Stack of data placed on obstacks.  */
end_comment

begin_struct
struct|struct
name|stack_level
block|{
comment|/* Pointer back to previous such level.  */
name|struct
name|stack_level
modifier|*
name|prev
decl_stmt|;
comment|/* Point to obstack we should return to.  */
name|struct
name|obstack
modifier|*
name|obstack
decl_stmt|;
comment|/* First place we start putting data.  */
name|tree
modifier|*
name|first
decl_stmt|;
comment|/* Number of entries we can have from `first'.      Right now we are dumb: if we overflow, abort.  */
name|int
name|limit
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|stack_level
modifier|*
name|push_stack_level
name|PROTO
argument_list|(
operator|(
expr|struct
name|obstack
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|stack_level
modifier|*
name|pop_stack_level
name|PROTO
argument_list|(
operator|(
expr|struct
name|stack_level
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

