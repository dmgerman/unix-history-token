begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This may look like C code, but it is really -*- C++ -*-
end_comment

begin_comment
comment|/*  Copyright (C) 1989 Free Software Foundation     written by Doug Lea (dl@rocky.oswego.edu)  This file is part of GNU CC.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU CC General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU CC, but only under the conditions described in the GNU CC General Public License.   A copy of this license is supposed to have been given to you along with GNU CC so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.   */
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
name|once
end_pragma

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

