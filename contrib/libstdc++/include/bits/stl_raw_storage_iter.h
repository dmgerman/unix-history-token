begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
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
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  *  * Copyright (c) 1996  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/** @file stl_raw_storage_iter.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STL_RAW_STORAGE_ITERATOR_H
end_ifndef

begin_define
define|#
directive|define
name|_STL_RAW_STORAGE_ITERATOR_H
value|1
end_define

begin_decl_stmt
name|namespace
name|std
block|{
comment|/**    *  This iterator class lets algorithms store their results into    *  uninitialized memory.   */
name|template
operator|<
name|class
name|_ForwardIterator
operator|,
name|class
name|_Tp
operator|>
name|class
name|raw_storage_iterator
operator|:
name|public
name|iterator
operator|<
name|output_iterator_tag
operator|,
name|void
operator|,
name|void
operator|,
name|void
operator|,
name|void
operator|>
block|{
name|protected
operator|:
name|_ForwardIterator
name|_M_iter
block|;
name|public
operator|:
name|explicit
name|raw_storage_iterator
argument_list|(
argument|_ForwardIterator __x
argument_list|)
operator|:
name|_M_iter
argument_list|(
argument|__x
argument_list|)
block|{}
name|raw_storage_iterator
operator|&
name|operator
operator|*
operator|(
operator|)
block|{
return|return
operator|*
name|this
return|;
block|}
name|raw_storage_iterator
operator|&
name|operator
operator|=
operator|(
specifier|const
name|_Tp
operator|&
name|__element
operator|)
block|{
name|std
operator|::
name|_Construct
argument_list|(
operator|&
operator|*
name|_M_iter
argument_list|,
name|__element
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|raw_storage_iterator
operator|<
name|_ForwardIterator
block|,
name|_Tp
operator|>
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|_M_iter
block|;
return|return
operator|*
name|this
return|;
block|}
name|raw_storage_iterator
operator|<
name|_ForwardIterator
block|,
name|_Tp
operator|>
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|raw_storage_iterator
operator|<
name|_ForwardIterator
block|,
name|_Tp
operator|>
name|__tmp
operator|=
operator|*
name|this
block|;
operator|++
name|_M_iter
block|;
return|return
name|__tmp
return|;
block|}
expr|}
block|; }
end_decl_stmt

begin_comment
comment|// namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Local Variables:
end_comment

begin_comment
comment|// mode:C++
end_comment

begin_comment
comment|// End:
end_comment

end_unit

