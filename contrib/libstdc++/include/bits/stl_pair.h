begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Pair implementation -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001, 2004 Free Software Foundation, Inc.
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
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  *  * Copyright (c) 1996,1997  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/** @file stl_pair.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PAIR_H
end_ifndef

begin_define
define|#
directive|define
name|_PAIR_H
value|1
end_define

begin_decl_stmt
name|namespace
name|std
block|{
comment|/// pair holds two objects of arbitrary type.
name|template
operator|<
name|class
name|_T1
operator|,
name|class
name|_T2
operator|>
expr|struct
name|pair
block|{
typedef|typedef
name|_T1
name|first_type
typedef|;
comment|///<  @c first_type is the first bound type
typedef|typedef
name|_T2
name|second_type
typedef|;
comment|///<  @c second_type is the second bound type
name|_T1
name|first
decl_stmt|;
comment|///< @c first is a copy of the first object
name|_T2
name|second
decl_stmt|;
comment|///< @c second is a copy of the second object
comment|// _GLIBCXX_RESOLVE_LIB_DEFECTS
comment|// 265.  std::pair::pair() effects overly restrictive
comment|/** The default constructor creates @c first and @c second using their        *  respective default constructors.  */
name|pair
argument_list|()
operator|:
name|first
argument_list|()
operator|,
name|second
argument_list|()
block|{ }
comment|/** Two objects may be passed to a @c pair constructor to be copied.  */
name|pair
argument_list|(
specifier|const
name|_T1
operator|&
name|__a
argument_list|,
specifier|const
name|_T2
operator|&
name|__b
argument_list|)
operator|:
name|first
argument_list|(
name|__a
argument_list|)
operator|,
name|second
argument_list|(
argument|__b
argument_list|)
block|{ }
comment|/** There is also a templated copy ctor for the @c pair class itself.  */
name|template
operator|<
name|class
name|_U1
operator|,
name|class
name|_U2
operator|>
name|pair
argument_list|(
specifier|const
name|pair
operator|<
name|_U1
argument_list|,
name|_U2
operator|>
operator|&
name|__p
argument_list|)
operator|:
name|first
argument_list|(
name|__p
operator|.
name|first
argument_list|)
operator|,
name|second
argument_list|(
argument|__p.second
argument_list|)
block|{ }
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Two pairs of the same type are equal iff their members are equal.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_T1
operator|,
name|class
name|_T2
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|pair
operator|<
name|_T1
operator|,
name|_T2
operator|>
operator|&
name|__x
operator|,
specifier|const
name|pair
operator|<
name|_T1
operator|,
name|_T2
operator|>
operator|&
name|__y
operator|)
block|{
return|return
name|__x
operator|.
name|first
operator|==
name|__y
operator|.
name|first
operator|&&
name|__x
operator|.
name|second
operator|==
name|__y
operator|.
name|second
return|;
block|}
end_expr_stmt

begin_comment
comment|///<http://gcc.gnu.org/onlinedocs/libstdc++/20_util/howto.html#pairlt>
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_T1
operator|,
name|class
name|_T2
operator|>
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|pair
operator|<
name|_T1
operator|,
name|_T2
operator|>
operator|&
name|__x
operator|,
specifier|const
name|pair
operator|<
name|_T1
operator|,
name|_T2
operator|>
operator|&
name|__y
operator|)
block|{
return|return
name|__x
operator|.
name|first
operator|<
name|__y
operator|.
name|first
operator|||
operator|(
operator|!
operator|(
name|__y
operator|.
name|first
operator|<
name|__x
operator|.
name|first
operator|)
operator|&&
name|__x
operator|.
name|second
operator|<
name|__y
operator|.
name|second
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Uses @c operator== to find the result.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_T1
operator|,
name|class
name|_T2
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|pair
operator|<
name|_T1
operator|,
name|_T2
operator|>
operator|&
name|__x
operator|,
specifier|const
name|pair
operator|<
name|_T1
operator|,
name|_T2
operator|>
operator|&
name|__y
operator|)
block|{
return|return
operator|!
operator|(
name|__x
operator|==
name|__y
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Uses @c operator< to find the result.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_T1
operator|,
name|class
name|_T2
operator|>
specifier|inline
name|bool
name|operator
operator|>
operator|(
specifier|const
name|pair
operator|<
name|_T1
operator|,
name|_T2
operator|>
operator|&
name|__x
operator|,
specifier|const
name|pair
operator|<
name|_T1
operator|,
name|_T2
operator|>
operator|&
name|__y
operator|)
block|{
return|return
name|__y
operator|<
name|__x
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Uses @c operator< to find the result.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_T1
operator|,
name|class
name|_T2
operator|>
specifier|inline
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|pair
operator|<
name|_T1
operator|,
name|_T2
operator|>
operator|&
name|__x
operator|,
specifier|const
name|pair
operator|<
name|_T1
operator|,
name|_T2
operator|>
operator|&
name|__y
operator|)
block|{
return|return
operator|!
operator|(
name|__y
operator|<
name|__x
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Uses @c operator< to find the result.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_T1
operator|,
name|class
name|_T2
operator|>
specifier|inline
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|pair
operator|<
name|_T1
operator|,
name|_T2
operator|>
operator|&
name|__x
operator|,
specifier|const
name|pair
operator|<
name|_T1
operator|,
name|_T2
operator|>
operator|&
name|__y
operator|)
block|{
return|return
operator|!
operator|(
name|__x
operator|<
name|__y
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**    *  @brief A convenience wrapper for creating a pair from two objects.    *  @param  x  The first object.    *  @param  y  The second object.    *  @return   A newly-constructed pair<> object of the appropriate type.    *    *  The standard requires that the objects be passed by reference-to-const,    *  but LWG issue #181 says they should be passed by const value.  We follow    *  the LWG by default.    */
end_comment

begin_comment
comment|// _GLIBCXX_RESOLVE_LIB_DEFECTS
end_comment

begin_comment
comment|// 181.  make_pair() unintended behavior
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_T1
operator|,
name|class
name|_T2
operator|>
specifier|inline
name|pair
operator|<
name|_T1
operator|,
name|_T2
operator|>
name|make_pair
argument_list|(
argument|_T1 __x
argument_list|,
argument|_T2 __y
argument_list|)
block|{
return|return
name|pair
operator|<
name|_T1
operator|,
name|_T2
operator|>
operator|(
name|__x
operator|,
name|__y
operator|)
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PAIR_H */
end_comment

end_unit

