begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This may look like C code, but it is really -*- C++ -*-
end_comment

begin_comment
comment|/*  Copyright (C) 1989 Free Software Foundation     written by Doug Lea (dl@rocky.oswego.edu)  This file is part of the GNU C++ Library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details. You should have received a copy of the GNU Library General Public License along with this library; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AllocRing_h
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|interface
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_AllocRing_h
value|1
end_define

begin_comment
comment|/*   An AllocRing holds the last n malloc'ed strings, reallocating/reusing    one only when the queue wraps around. It thus guarantees that the   last n allocations are intact. It is useful for things like I/O   formatting where reasonable restrictions may be made about the   number of allowable live allocations before auto-deletion. */
end_comment

begin_decl_stmt
name|class
name|AllocRing
block|{
struct|struct
name|AllocQNode
block|{
name|void
modifier|*
name|ptr
decl_stmt|;
name|int
name|sz
decl_stmt|;
block|}
struct|;
name|AllocQNode
modifier|*
name|nodes
decl_stmt|;
name|int
name|n
decl_stmt|;
name|int
name|current
decl_stmt|;
name|int
name|find
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
name|public
label|:
name|AllocRing
argument_list|(
argument|int max
argument_list|)
empty_stmt|;
operator|~
name|AllocRing
argument_list|()
expr_stmt|;
name|void
modifier|*
name|alloc
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
name|int
name|contains
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
name|void
name|clear
parameter_list|()
function_decl|;
name|void
name|free
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

