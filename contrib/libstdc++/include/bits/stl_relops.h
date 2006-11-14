begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// std::rel_ops implementation -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001, 2002, 2004 Free Software Foundation, Inc.
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
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  * Copyright (c) 1996,1997  * Silicon Graphics  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  */
end_comment

begin_comment
comment|/** @file stl_relops.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  *  *  @if maint  *  Inclusion of this file has been removed from  *  all of the other STL headers for safety reasons, except std_utility.h.  *  For more information, see the thread of about twenty messages starting  *  with http://gcc.gnu.org/ml/libstdc++/2001-01/msg00223.html , or the  *  FAQ at http://gcc.gnu.org/onlinedocs/libstdc++/faq/index.html#4_4 .  *  *  Short summary:  the rel_ops operators should be avoided for the present.  *  @endif  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STL_RELOPS_H
end_ifndef

begin_define
define|#
directive|define
name|_STL_RELOPS_H
value|1
end_define

begin_decl_stmt
name|namespace
name|std
block|{
name|namespace
name|rel_ops
block|{
comment|/** @namespace std::rel_ops      *  @brief  The generated relational operators are sequestered here.      */
comment|/**      *  @brief Defines @c != for arbitrary types, in terms of @c ==.      *  @param  x  A thing.      *  @param  y  Another thing.      *  @return   x != y      *      *  This function uses @c == to determine its result.      */
name|template
operator|<
name|class
name|_Tp
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|_Tp
operator|&
name|__x
operator|,
specifier|const
name|_Tp
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
comment|/**      *  @brief Defines @c> for arbitrary types, in terms of @c<.      *  @param  x  A thing.      *  @param  y  Another thing.      *  @return   x> y      *      *  This function uses @c< to determine its result.      */
name|template
operator|<
name|class
name|_Tp
operator|>
specifier|inline
name|bool
name|operator
operator|>
operator|(
specifier|const
name|_Tp
operator|&
name|__x
operator|,
specifier|const
name|_Tp
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
comment|/**      *  @brief Defines @c<= for arbitrary types, in terms of @c<.      *  @param  x  A thing.      *  @param  y  Another thing.      *  @return   x<= y      *      *  This function uses @c< to determine its result.      */
name|template
operator|<
name|class
name|_Tp
operator|>
specifier|inline
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|_Tp
operator|&
name|__x
operator|,
specifier|const
name|_Tp
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
comment|/**      *  @brief Defines @c>= for arbitrary types, in terms of @c<.      *  @param  x  A thing.      *  @param  y  Another thing.      *  @return   x>= y      *      *  This function uses @c< to determine its result.      */
name|template
operator|<
name|class
name|_Tp
operator|>
specifier|inline
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|_Tp
operator|&
name|__x
operator|,
specifier|const
name|_Tp
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
block|}
comment|// namespace rel_ops
block|}
end_decl_stmt

begin_comment
comment|// namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STL_RELOPS_H */
end_comment

end_unit

