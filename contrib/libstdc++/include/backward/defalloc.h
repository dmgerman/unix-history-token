begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Backward-compat support -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001 Free Software Foundation, Inc.
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
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  */
end_comment

begin_comment
comment|// Inclusion of this file is DEPRECATED.  This is the original HP
end_comment

begin_comment
comment|// default allocator.  It is provided only for backward compatibility.
end_comment

begin_comment
comment|// This file WILL BE REMOVED in a future release.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// DO NOT USE THIS FILE unless you have an old container implementation
end_comment

begin_comment
comment|// that requires an allocator with the HP-style interface.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Standard-conforming allocators have a very different interface.  The
end_comment

begin_comment
comment|// standard default allocator is declared in the header<memory>.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BACKWARD_DEFALLOC_H
end_ifndef

begin_define
define|#
directive|define
name|_BACKWARD_DEFALLOC_H
value|1
end_define

begin_include
include|#
directive|include
file|"backward_warning.h"
end_include

begin_include
include|#
directive|include
file|"new.h"
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|"iostream.h"
end_include

begin_include
include|#
directive|include
file|"algobase.h"
end_include

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|>
specifier|inline
name|_Tp
operator|*
name|allocate
argument_list|(
argument|ptrdiff_t __size
argument_list|,
argument|_Tp*
argument_list|)
block|{
name|set_new_handler
argument_list|(
literal|0
argument_list|)
block|;
name|_Tp
operator|*
name|__tmp
operator|=
operator|(
name|_Tp
operator|*
operator|)
operator|(
operator|::
name|operator
name|new
argument_list|(
call|(
name|size_t
call|)
argument_list|(
name|__size
operator|*
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
argument_list|)
argument_list|)
operator|)
block|;
if|if
condition|(
name|__tmp
operator|==
literal|0
condition|)
block|{
name|cerr
operator|<<
literal|"out of memory"
operator|<<
name|endl
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|__tmp
return|;
end_return

begin_expr_stmt
unit|}   template
operator|<
name|class
name|_Tp
operator|>
specifier|inline
name|void
name|deallocate
argument_list|(
argument|_Tp* __buffer
argument_list|)
block|{
operator|::
name|operator
name|delete
argument_list|(
name|__buffer
argument_list|)
block|; }
name|template
operator|<
name|class
name|_Tp
operator|>
name|class
name|allocator
block|{
name|public
operator|:
typedef|typedef
name|_Tp
name|value_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_Tp
modifier|*
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|_Tp
modifier|*
name|const_pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Tp
modifier|&
name|reference
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|_Tp
modifier|&
name|const_reference
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|size_t
name|size_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ptrdiff_t
name|difference_type
typedef|;
end_typedef

begin_function
name|pointer
name|allocate
parameter_list|(
name|size_type
name|__n
parameter_list|)
block|{
return|return
operator|::
name|allocate
argument_list|(
operator|(
name|difference_type
operator|)
name|__n
argument_list|,
operator|(
name|pointer
operator|)
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|deallocate
parameter_list|(
name|pointer
name|__p
parameter_list|)
block|{
operator|::
name|deallocate
argument_list|(
name|__p
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|pointer
name|address
parameter_list|(
name|reference
name|__x
parameter_list|)
block|{
return|return
operator|(
name|pointer
operator|)
operator|&
name|__x
return|;
block|}
end_function

begin_function
name|const_pointer
name|const_address
parameter_list|(
name|const_reference
name|__x
parameter_list|)
block|{
return|return
operator|(
name|const_pointer
operator|)
operator|&
name|__x
return|;
block|}
end_function

begin_function
name|size_type
name|init_page_size
parameter_list|()
block|{
return|return
name|max
argument_list|(
name|size_type
argument_list|(
literal|1
argument_list|)
argument_list|,
name|size_type
argument_list|(
literal|4096
operator|/
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|size_type
name|max_size
argument_list|()
specifier|const
block|{
return|return
name|max
argument_list|(
name|size_type
argument_list|(
literal|1
argument_list|)
argument_list|,
name|size_type
argument_list|(
name|UINT_MAX
operator|/
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|class
name|allocator
operator|<
name|void
operator|>
block|{
name|public
operator|:
typedef|typedef
name|void
modifier|*
name|pointer
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BACKWARD_DEFALLOC_H */
end_comment

end_unit

