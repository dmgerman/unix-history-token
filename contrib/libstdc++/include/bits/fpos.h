begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// File position object and stream types
end_comment

begin_comment
comment|// Copyright (C) 1997, 1998, 1999, 2000, 2001 Free Software Foundation, Inc.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is part of the GNU ISO C++ Library.  This library is free
end_comment

begin_comment
comment|// software; you can redistribute it and/or modify it under the
end_comment

begin_comment
comment|// terms of the GNU General Public License as published by the
end_comment

begin_comment
comment|// Free Software Foundation; either version 2, or (at your option)
end_comment

begin_comment
comment|// any later version.
end_comment

begin_comment
comment|// This library is distributed in the hope that it will be useful,
end_comment

begin_comment
comment|// but WITHOUT ANY WARRANTY; without even the implied warranty of
end_comment

begin_comment
comment|// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
end_comment

begin_comment
comment|// GNU General Public License for more details.
end_comment

begin_comment
comment|// You should have received a copy of the GNU General Public License along
end_comment

begin_comment
comment|// with this library; see the file COPYING.  If not, write to the Free
end_comment

begin_comment
comment|// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
end_comment

begin_comment
comment|// USA.
end_comment

begin_comment
comment|// As a special exception, you may use this file as part of a free software
end_comment

begin_comment
comment|// library without restriction.  Specifically, if other files instantiate
end_comment

begin_comment
comment|// templates or use macros or inline functions from this file, or you compile
end_comment

begin_comment
comment|// this file and link it with other files to produce an executable, this
end_comment

begin_comment
comment|// file does not by itself cause the resulting executable to be covered by
end_comment

begin_comment
comment|// the GNU General Public License.  This exception does not however
end_comment

begin_comment
comment|// invalidate any other reasons why the executable file might be covered by
end_comment

begin_comment
comment|// the GNU General Public License.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ISO C++ 14882: 27 Input/output library
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/** @file fpos.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPP_BITS_FPOS_H
end_ifndef

begin_define
define|#
directive|define
name|_CPP_BITS_FPOS_H
value|1
end_define

begin_pragma
pragma|#
directive|pragma
name|GCC
name|system_header
end_pragma

begin_include
include|#
directive|include
file|<bits/c++io.h>
end_include

begin_include
include|#
directive|include
file|<cwchar>
end_include

begin_comment
comment|// For mbstate_t.
end_comment

begin_decl_stmt
name|namespace
name|std
block|{
comment|// 27.4.1  Types
comment|// [27.4.3] template class fpos
comment|/**    *  @doctodo   */
name|template
operator|<
name|typename
name|_StateT
operator|>
name|class
name|fpos
block|{
name|public
operator|:
comment|// Types:
typedef|typedef
name|_StateT
name|__state_type
typedef|;
name|private
operator|:
name|streamoff
name|_M_off
expr_stmt|;
name|__state_type
name|_M_st
decl_stmt|;
name|public
label|:
name|__state_type
name|state
argument_list|()
specifier|const
block|{
return|return
name|_M_st
return|;
block|}
name|void
name|state
parameter_list|(
name|__state_type
name|__st
parameter_list|)
block|{
name|_M_st
operator|=
name|__st
expr_stmt|;
block|}
comment|// NB: The standard defines only the implicit copy ctor and the
comment|// previous two members.  The rest is a "conforming extension".
name|fpos
argument_list|()
operator|:
name|_M_off
argument_list|(
name|streamoff
argument_list|()
argument_list|)
operator|,
name|_M_st
argument_list|(
argument|__state_type()
argument_list|)
block|{ }
name|fpos
argument_list|(
argument|streamoff __off
argument_list|,
argument|__state_type __st = __state_type()
argument_list|)
operator|:
name|_M_off
argument_list|(
name|__off
argument_list|)
operator|,
name|_M_st
argument_list|(
argument|__st
argument_list|)
block|{ }
name|operator
name|streamoff
argument_list|()
specifier|const
block|{
return|return
name|_M_off
return|;
block|}
name|fpos
operator|&
name|operator
operator|+=
operator|(
name|streamoff
name|__off
operator|)
block|{
name|_M_off
operator|+=
name|__off
block|;
return|return
operator|*
name|this
return|;
block|}
name|fpos
operator|&
name|operator
operator|-=
operator|(
name|streamoff
name|__off
operator|)
block|{
name|_M_off
operator|-=
name|__off
block|;
return|return
operator|*
name|this
return|;
block|}
name|fpos
name|operator
operator|+
operator|(
name|streamoff
name|__off
operator|)
block|{
name|fpos
name|__t
argument_list|(
operator|*
name|this
argument_list|)
block|;
name|__t
operator|+=
name|__off
block|;
return|return
name|__t
return|;
block|}
name|fpos
name|operator
operator|-
operator|(
name|streamoff
name|__off
operator|)
block|{
name|fpos
name|__t
argument_list|(
operator|*
name|this
argument_list|)
block|;
name|__t
operator|-=
name|__off
block|;
return|return
name|__t
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|fpos
operator|&
name|__pos
operator|)
specifier|const
block|{
return|return
name|_M_off
operator|==
name|__pos
operator|.
name|_M_off
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|fpos
operator|&
name|__pos
operator|)
specifier|const
block|{
return|return
name|_M_off
operator|!=
name|__pos
operator|.
name|_M_off
return|;
block|}
name|streamoff
name|_M_position
argument_list|()
specifier|const
block|{
return|return
name|_M_off
return|;
block|}
name|void
name|_M_position
parameter_list|(
name|streamoff
name|__off
parameter_list|)
block|{
name|_M_off
operator|=
name|__off
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// 27.2, paragraph 10 about fpos/char_traits circularity
end_comment

begin_typedef
typedef|typedef
name|fpos
operator|<
name|mbstate_t
operator|>
name|streampos
expr_stmt|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_WCHAR_T
end_ifdef

begin_comment
comment|/// 27.2, paragraph 10 about fpos/char_traits circularity
end_comment

begin_typedef
typedef|typedef
name|fpos
operator|<
name|mbstate_t
operator|>
name|wstreampos
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
unit|}
comment|// namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

