begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Position types -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2003, 2004
end_comment

begin_comment
comment|// Free Software Foundation, Inc.
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
comment|// ISO C++ 14882: 27.4.1 - Types
end_comment

begin_comment
comment|// ISO C++ 14882: 27.4.3 - Template class fpos
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/** @file postypes.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_POSTYPES_H
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_POSTYPES_H
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
file|<cwchar>
end_include

begin_comment
comment|// For mbstate_t
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCXX_HAVE_STDINT_H
end_ifdef

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// For int64_t
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|std
block|{
comment|// The types streamoff, streampos and wstreampos and the class
comment|// template fpos<> are described in clauses 21.1.2, 21.1.3, 27.1.2,
comment|// 27.2, 27.4.1, 27.4.3 and D.6. Despite all this verbage, the
comment|// behaviour of these types is mostly implementation defined or
comment|// unspecified. The behaviour in this implementation is as noted
comment|// below.
comment|/**    *  @brief  Type used by fpos, char_traits<char>, and char_traits<wchar_t>.    *    *  @if maint    *  In clauses 21.1.3.1 and 27.4.1 streamoff is described as an    *  implementation defined type.    *  Note: In versions of GCC up to and including GCC 3.3, streamoff    *  was typedef long.    *  @endif   */
ifdef|#
directive|ifdef
name|_GLIBCXX_HAVE_INT64_T
typedef|typedef
name|int64_t
name|streamoff
typedef|;
else|#
directive|else
typedef|typedef
name|long
name|long
name|streamoff
typedef|;
endif|#
directive|endif
comment|/// Integral type for I/O operation counts and buffer sizes.
typedef|typedef
name|ptrdiff_t
name|streamsize
typedef|;
comment|// Signed integral type
name|template
operator|<
name|typename
name|_StateT
operator|>
name|class
name|fpos
expr_stmt|;
comment|/**    *  @brief  Class representing stream positions.    *    *  The standard places no requirements upon the template parameter StateT.    *  In this implementation StateT must be DefaultConstructible,    *  CopyConstructible and Assignable.  The standard only requires that fpos    *  should contain a member of type StateT. In this implementation it also    *  contains an offset stored as a signed integer.    *    *  @param  StateT  Type passed to and returned from state().    */
name|template
operator|<
name|typename
name|_StateT
operator|>
name|class
name|fpos
block|{
name|private
operator|:
name|streamoff
name|_M_off
block|;
name|_StateT
name|_M_state
block|;
name|public
operator|:
comment|// The standard doesn't require that fpos objects can be default
comment|// constructed. This implementation provides a default
comment|// constructor that initializes the offset to 0 and default
comment|// constructs the state.
name|fpos
argument_list|()
operator|:
name|_M_off
argument_list|(
literal|0
argument_list|)
block|,
name|_M_state
argument_list|()
block|{ }
comment|// The standard requires that fpos objects can be constructed
comment|// from streamoff objects using the constructor syntax, and
comment|// fails to give any meaningful semantics. In this
comment|// implementation implicit conversion is also allowed, and this
comment|// constructor stores the streamoff as the offset and default
comment|// constructs the state.
comment|/// Construct position from offset.
name|fpos
argument_list|(
argument|streamoff __off
argument_list|)
operator|:
name|_M_off
argument_list|(
name|__off
argument_list|)
block|,
name|_M_state
argument_list|()
block|{ }
comment|/// Convert to streamoff.
name|operator
name|streamoff
argument_list|()
specifier|const
block|{
return|return
name|_M_off
return|;
block|}
comment|/// Remember the value of @a st.
name|void
name|state
argument_list|(
argument|_StateT __st
argument_list|)
block|{
name|_M_state
operator|=
name|__st
block|; }
comment|/// Return the last set value of @a st.
name|_StateT
name|state
argument_list|()
specifier|const
block|{
return|return
name|_M_state
return|;
block|}
comment|// The standard only requires that operator== must be an
comment|// equivalence relation. In this implementation two fpos<StateT>
comment|// objects belong to the same equivalence class if the contained
comment|// offsets compare equal.
comment|/// Test if equivalent to another position.
name|bool
name|operator
operator|==
operator|(
specifier|const
name|fpos
operator|&
name|__other
operator|)
specifier|const
block|{
return|return
name|_M_off
operator|==
name|__other
operator|.
name|_M_off
return|;
block|}
comment|/// Test if not equivalent to another position.
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|fpos
operator|&
name|__other
operator|)
specifier|const
block|{
return|return
name|_M_off
operator|!=
name|__other
operator|.
name|_M_off
return|;
block|}
comment|// The standard requires that this operator must be defined, but
comment|// gives no semantics. In this implemenation it just adds it's
comment|// argument to the stored offset and returns *this.
comment|/// Add offset to this position.
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
comment|// The standard requires that this operator must be defined, but
comment|// gives no semantics. In this implemenation it just subtracts
comment|// it's argument from the stored offset and returns *this.
comment|/// Subtract offset from this position.
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
comment|// The standard requires that this operator must be defined, but
comment|// defines it's semantics only in terms of operator-. In this
comment|// implementation it constructs a copy of *this, adds the
comment|// argument to that copy using operator+= and then returns the
comment|// copy.
comment|/// Add position and offset.
name|fpos
name|operator
operator|+
operator|(
name|streamoff
name|__off
operator|)
specifier|const
block|{
name|fpos
name|__pos
argument_list|(
operator|*
name|this
argument_list|)
block|;
name|__pos
operator|+=
name|__off
block|;
return|return
name|__pos
return|;
block|}
comment|// The standard requires that this operator must be defined, but
comment|// defines it's semantics only in terms of operator+. In this
comment|// implementation it constructs a copy of *this, subtracts the
comment|// argument from that copy using operator-= and then returns the
comment|// copy.
comment|/// Subtract offset from position.
name|fpos
name|operator
operator|-
operator|(
name|streamoff
name|__off
operator|)
specifier|const
block|{
name|fpos
name|__pos
argument_list|(
operator|*
name|this
argument_list|)
block|;
name|__pos
operator|-=
name|__off
block|;
return|return
name|__pos
return|;
block|}
comment|// The standard requires that this operator must be defined, but
comment|// defines it's semantics only in terms of operator+. In this
comment|// implementation it returns the difference between the offset
comment|// stored in *this and in the argument.
comment|/// Subtract position to return offset.
name|streamoff
name|operator
operator|-
operator|(
specifier|const
name|fpos
operator|&
name|__other
operator|)
specifier|const
block|{
return|return
name|_M_off
operator|-
name|__other
operator|.
name|_M_off
return|;
block|}
expr|}
block|;
comment|// Clauses 21.1.3.1 and 21.1.3.2 describe streampos and wstreampos
comment|// as implementation defined types, but clause 27.2 requires that
comment|// they must both be typedefs for fpos<mbstate_t>
comment|/// File position for char streams.
typedef|typedef
name|fpos
operator|<
name|mbstate_t
operator|>
name|streampos
expr_stmt|;
comment|/// File position for wchar_t streams.
typedef|typedef
name|fpos
operator|<
name|mbstate_t
operator|>
name|wstreampos
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

