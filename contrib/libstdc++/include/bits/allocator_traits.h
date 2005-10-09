begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Allocators -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001, 2002, 2003 Free Software Foundation, Inc.
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
comment|/*  * Copyright (c) 1996-1997  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALLOCATOR_TRAITS_H
end_ifndef

begin_define
define|#
directive|define
name|_ALLOCATOR_TRAITS_H
value|1
end_define

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_decl_stmt
name|namespace
name|std
block|{
comment|/**    *  @if maint    *  This is used primarily (only?) in _Alloc_traits and other places to    *  help provide the _Alloc_type typedef.  All it does is forward the    *  requests after some minimal checking.    *    *  This is neither "standard"-conforming nor "SGI".  The _Alloc parameter    *  must be "SGI" style.    *  @endif    *  (See @link Allocators allocators info @endlink for more.)    */
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Alloc
operator|>
name|class
name|__simple_alloc
block|{
name|public
operator|:
specifier|static
name|_Tp
operator|*
name|allocate
argument_list|(
argument|size_t __n
argument_list|)
block|{
name|_Tp
operator|*
name|__ret
operator|=
literal|0
block|;
if|if
condition|(
name|__n
condition|)
name|__ret
operator|=
name|static_cast
operator|<
name|_Tp
operator|*
operator|>
operator|(
name|_Alloc
operator|::
name|allocate
argument_list|(
name|__n
operator|*
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
argument_list|)
operator|)
expr_stmt|;
return|return
name|__ret
return|;
block|}
specifier|static
name|_Tp
modifier|*
name|allocate
parameter_list|()
block|{
return|return
operator|(
name|_Tp
operator|*
operator|)
name|_Alloc
operator|::
name|allocate
argument_list|(
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|void
name|deallocate
parameter_list|(
name|_Tp
modifier|*
name|__p
parameter_list|,
name|size_t
name|__n
parameter_list|)
block|{
if|if
condition|(
literal|0
operator|!=
name|__n
condition|)
name|_Alloc
operator|::
name|deallocate
argument_list|(
name|__p
argument_list|,
name|__n
operator|*
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
argument_list|)
expr_stmt|;
block|}
specifier|static
name|void
name|deallocate
parameter_list|(
name|_Tp
modifier|*
name|__p
parameter_list|)
block|{
name|_Alloc
operator|::
name|deallocate
argument_list|(
name|__p
argument_list|,
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**    *  @if maint    *  Allocator adaptor to turn an "SGI" style allocator (e.g.,    *  __alloc, __malloc_alloc) into a "standard" conforming    *  allocator.  Note that this adaptor does *not* assume that all    *  objects of the underlying alloc class are identical, nor does it    *  assume that all of the underlying alloc's member functions are    *  static member functions.  Note, also, that __allocator<_Tp,    *  __alloc> is essentially the same thing as allocator<_Tp>.    *  @endif    *  (See @link Allocators allocators info @endlink for more.)    */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Alloc
operator|>
expr|struct
name|__allocator
block|{
name|_Alloc
name|__underlying_alloc
block|;
typedef|typedef
name|size_t
name|size_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|ptrdiff_t
name|difference_type
typedef|;
end_typedef

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
name|_Tp
name|value_type
typedef|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp1
operator|>
expr|struct
name|rebind
block|{
typedef|typedef
name|__allocator
operator|<
name|_Tp1
operator|,
name|_Alloc
operator|>
name|other
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|__allocator
argument_list|()
end_macro

begin_macro
name|throw
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_macro
name|__allocator
argument_list|(
argument|const __allocator& __a
argument_list|)
end_macro

begin_expr_stmt
name|throw
argument_list|()
operator|:
name|__underlying_alloc
argument_list|(
argument|__a.__underlying_alloc
argument_list|)
block|{ }
name|template
operator|<
name|typename
name|_Tp1
operator|>
name|__allocator
argument_list|(
argument|const __allocator<_Tp1
argument_list|,
argument|_Alloc>& __a
argument_list|)
name|throw
argument_list|()
operator|:
name|__underlying_alloc
argument_list|(
argument|__a.__underlying_alloc
argument_list|)
block|{ }
operator|~
name|__allocator
argument_list|()
name|throw
argument_list|()
block|{ }
name|pointer
name|address
argument_list|(
argument|reference __x
argument_list|)
specifier|const
block|{
return|return
operator|&
name|__x
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|const_pointer
name|address
argument_list|(
name|const_reference
name|__x
argument_list|)
decl|const
block|{
return|return
operator|&
name|__x
return|;
block|}
end_decl_stmt

begin_comment
comment|// NB: __n is permitted to be 0.  The C++ standard says nothing
end_comment

begin_comment
comment|// about what the return value is when __n == 0.
end_comment

begin_function
name|_Tp
modifier|*
name|allocate
parameter_list|(
name|size_type
name|__n
parameter_list|,
specifier|const
name|void
modifier|*
init|=
literal|0
parameter_list|)
block|{
name|_Tp
modifier|*
name|__ret
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|__n
condition|)
name|__ret
operator|=
name|static_cast
operator|<
name|_Tp
operator|*
operator|>
operator|(
name|_Alloc
operator|::
name|allocate
argument_list|(
name|__n
operator|*
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
argument_list|)
operator|)
expr_stmt|;
return|return
name|__ret
return|;
block|}
end_function

begin_comment
comment|// __p is not permitted to be a null pointer.
end_comment

begin_function
name|void
name|deallocate
parameter_list|(
name|pointer
name|__p
parameter_list|,
name|size_type
name|__n
parameter_list|)
block|{
name|__underlying_alloc
operator|.
name|deallocate
argument_list|(
name|__p
argument_list|,
name|__n
operator|*
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|size_type
name|max_size
argument_list|()
specifier|const
name|throw
argument_list|()
block|{
return|return
name|size_t
argument_list|(
operator|-
literal|1
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// _GLIBCXX_RESOLVE_LIB_DEFECTS
end_comment

begin_comment
comment|// 402. wrong new expression in [some_]allocator::construct
end_comment

begin_function
name|void
name|construct
parameter_list|(
name|pointer
name|__p
parameter_list|,
specifier|const
name|_Tp
modifier|&
name|__val
parameter_list|)
block|{
operator|::
name|new
argument_list|(
argument|__p
argument_list|)
name|_Tp
argument_list|(
name|__val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|destroy
parameter_list|(
name|pointer
name|__p
parameter_list|)
block|{
name|__p
operator|->
expr|~
name|_Tp
argument_list|()
expr_stmt|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_Alloc
operator|>
expr|struct
name|__allocator
operator|<
name|void
operator|,
name|_Alloc
operator|>
block|{
typedef|typedef
name|size_t
name|size_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|ptrdiff_t
name|difference_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|void
modifier|*
name|const_pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|value_type
typedef|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp1
operator|>
expr|struct
name|rebind
block|{
typedef|typedef
name|__allocator
operator|<
name|_Tp1
operator|,
name|_Alloc
operator|>
name|other
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Alloc
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|__allocator
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|&
name|__a1
operator|,
specifier|const
name|__allocator
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|&
name|__a2
operator|)
block|{
return|return
name|__a1
operator|.
name|__underlying_alloc
operator|==
name|__a2
operator|.
name|__underlying_alloc
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Alloc
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|__allocator
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|&
name|__a1
operator|,
specifier|const
name|__allocator
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|&
name|__a2
operator|)
block|{
return|return
name|__a1
operator|.
name|__underlying_alloc
operator|!=
name|__a2
operator|.
name|__underlying_alloc
return|;
block|}
end_expr_stmt

begin_comment
comment|/**    *  @if maint    *  Another allocator adaptor:  _Alloc_traits.  This serves two purposes.    *  First, make it possible to write containers that can use either "SGI"    *  style allocators or "standard" allocators.  Second, provide a mechanism    *  so that containers can query whether or not the allocator has distinct    *  instances.  If not, the container can avoid wasting a word of memory to    *  store an empty object.  For examples of use, see stl_vector.h, etc, or    *  any of the other classes derived from this one.    *    *  This adaptor uses partial specialization.  The general case of    *  _Alloc_traits<_Tp, _Alloc> assumes that _Alloc is a    *  standard-conforming allocator, possibly with non-equal instances and    *  non-static members.  (It still behaves correctly even if _Alloc has    *  static member and if all instances are equal.  Refinements affect    *  performance, not correctness.)    *    *  There are always two members:  allocator_type, which is a standard-    *  conforming allocator type for allocating objects of type _Tp, and    *  _S_instanceless, a static const member of type bool.  If    *  _S_instanceless is true, this means that there is no difference    *  between any two instances of type allocator_type.  Furthermore, if    *  _S_instanceless is true, then _Alloc_traits has one additional    *  member:  _Alloc_type.  This type encapsulates allocation and    *  deallocation of objects of type _Tp through a static interface; it    *  has two member functions, whose signatures are    *    *  -  static _Tp* allocate(size_t)    *  -  static void deallocate(_Tp*, size_t)    *    *  The size_t parameters are "standard" style (see top of    *  allocator.h) in that they take counts, not sizes.    *    *  @endif    *  (See @link Allocators allocators info @endlink for more.)    */
end_comment

begin_comment
comment|// The fully general version.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Allocator
operator|>
expr|struct
name|_Alloc_traits
block|{
specifier|static
specifier|const
name|bool
name|_S_instanceless
operator|=
name|false
block|;
typedef|typedef
name|typename
name|_Allocator
operator|::
name|template
name|rebind
operator|<
name|_Tp
operator|>
operator|::
name|other
name|allocator_type
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Allocator
operator|>
specifier|const
name|bool
name|_Alloc_traits
operator|<
name|_Tp
operator|,
name|_Allocator
operator|>
operator|::
name|_S_instanceless
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

