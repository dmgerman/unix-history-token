begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// The template and inlines for the -*- C++ -*- internal _Array helper class.
end_comment

begin_comment
comment|// Copyright (C) 1997, 1998, 1999, 2000 Free Software Foundation, Inc.
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
comment|// Written by Gabriel Dos Reis<Gabriel.Dos-Reis@DPTMaths.ENS-Cachan.Fr>
end_comment

begin_comment
comment|/** @file valarray_array.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPP_BITS_ARRAY_H
end_ifndef

begin_define
define|#
directive|define
name|_CPP_BITS_ARRAY_H
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
file|<bits/c++config.h>
end_include

begin_include
include|#
directive|include
file|<bits/cpp_type_traits.h>
end_include

begin_include
include|#
directive|include
file|<cstdlib>
end_include

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_include
include|#
directive|include
file|<new>
end_include

begin_decl_stmt
name|namespace
name|std
block|{
comment|//
comment|// Helper functions on raw pointers
comment|//
comment|// We get memory by the old fashion way
specifier|inline
name|void
modifier|*
name|__valarray_get_memory
parameter_list|(
name|size_t
name|__n
parameter_list|)
block|{
return|return
name|operator
name|new
argument_list|(
name|__n
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|_Tp
operator|*
name|__restrict__
name|__valarray_get_storage
argument_list|(
argument|size_t __n
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|_Tp
operator|*
name|__restrict__
operator|>
operator|(
name|__valarray_get_memory
argument_list|(
name|__n
operator|*
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
argument_list|)
operator|)
return|;
block|}
comment|// Return memory to the system
specifier|inline
name|void
name|__valarray_release_memory
parameter_list|(
name|void
modifier|*
name|__p
parameter_list|)
block|{
name|operator
name|delete
argument_list|(
name|__p
argument_list|)
decl_stmt|;
block|}
comment|// Turn a raw-memory into an array of _Tp filled with _Tp()
comment|// This is required in 'valarray<T> v(n);'
name|template
operator|<
name|typename
name|_Tp
operator|,
name|bool
operator|>
expr|struct
name|_Array_default_ctor
block|{
comment|// Please note that this isn't exception safe.  But
comment|// valarrays aren't required to be exception safe.
specifier|inline
specifier|static
name|void
name|_S_do_it
argument_list|(
argument|_Tp* __restrict__ __b
argument_list|,
argument|_Tp* __restrict__ __e
argument_list|)
block|{
while|while
condition|(
name|__b
operator|!=
name|__e
condition|)
name|new
argument_list|(
argument|__b++
argument_list|)
name|_Tp
argument_list|()
expr_stmt|;
block|}
expr|}
block|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|_Array_default_ctor
operator|<
name|_Tp
block|,
name|true
operator|>
block|{
comment|// For fundamental types, it suffices to say 'memset()'
specifier|inline
specifier|static
name|void
name|_S_do_it
argument_list|(
argument|_Tp* __restrict__ __b
argument_list|,
argument|_Tp* __restrict__ __e
argument_list|)
block|{
name|memset
argument_list|(
name|__b
argument_list|,
literal|0
argument_list|,
operator|(
name|__e
operator|-
name|__b
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
argument_list|)
block|; }
block|}
block|;
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|__valarray_default_construct
argument_list|(
argument|_Tp* __restrict__ __b
argument_list|,
argument|_Tp* __restrict__ __e
argument_list|)
block|{
name|_Array_default_ctor
operator|<
name|_Tp
block|,
name|__is_fundamental
operator|<
name|_Tp
operator|>
operator|::
name|_M_type
operator|>
operator|::
name|_S_do_it
argument_list|(
name|__b
argument_list|,
name|__e
argument_list|)
block|;      }
comment|// Turn a raw-memory into an array of _Tp filled with __t
comment|// This is the required in valarray<T> v(n, t).  Also
comment|// used in valarray<>::resize().
name|template
operator|<
name|typename
name|_Tp
block|,
name|bool
operator|>
expr|struct
name|_Array_init_ctor
block|{
comment|// Please note that this isn't exception safe.  But
comment|// valarrays aren't required to be exception safe.
specifier|inline
specifier|static
name|void
name|_S_do_it
argument_list|(
argument|_Tp* __restrict__ __b
argument_list|,
argument|_Tp* __restrict__ __e
argument_list|,
argument|const _Tp __t
argument_list|)
block|{
while|while
condition|(
name|__b
operator|!=
name|__e
condition|)
name|new
argument_list|(
argument|__b++
argument_list|)
name|_Tp
argument_list|(
name|__t
argument_list|)
expr_stmt|;
block|}
expr|}
block|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|_Array_init_ctor
operator|<
name|_Tp
block|,
name|true
operator|>
block|{
specifier|inline
specifier|static
name|void
name|_S_do_it
argument_list|(
argument|_Tp* __restrict__ __b
argument_list|,
argument|_Tp* __restrict__ __e
argument_list|,
argument|const _Tp __t
argument_list|)
block|{
while|while
condition|(
name|__b
operator|!=
name|__e
condition|)
operator|*
name|__b
operator|++
operator|=
name|__t
expr_stmt|;
block|}
expr|}
block|;
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|__valarray_fill_construct
argument_list|(
argument|_Tp* __restrict__ __b
argument_list|,
argument|_Tp* __restrict__ __e
argument_list|,
argument|const _Tp __t
argument_list|)
block|{
name|_Array_init_ctor
operator|<
name|_Tp
block|,
name|__is_fundamental
operator|<
name|_Tp
operator|>
operator|::
name|_M_type
operator|>
operator|::
name|_S_do_it
argument_list|(
name|__b
argument_list|,
name|__e
argument_list|,
name|__t
argument_list|)
block|;      }
comment|//
comment|// copy-construct raw array [__o, *) from plain array [__b, __e)
comment|// We can't just say 'memcpy()'
comment|//
name|template
operator|<
name|typename
name|_Tp
block|,
name|bool
operator|>
expr|struct
name|_Array_copy_ctor
block|{
comment|// Please note that this isn't exception safe.  But
comment|// valarrays aren't required to be exception safe.
specifier|inline
specifier|static
name|void
name|_S_do_it
argument_list|(
argument|const _Tp* __restrict__ __b
argument_list|,
argument|const _Tp* __restrict__ __e
argument_list|,
argument|_Tp* __restrict__ __o
argument_list|)
block|{
while|while
condition|(
name|__b
operator|!=
name|__e
condition|)
name|new
argument_list|(
argument|__o++
argument_list|)
name|_Tp
argument_list|(
operator|*
name|__b
operator|++
argument_list|)
expr_stmt|;
block|}
expr|}
block|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|_Array_copy_ctor
operator|<
name|_Tp
block|,
name|true
operator|>
block|{
specifier|inline
specifier|static
name|void
name|_S_do_it
argument_list|(
argument|const _Tp* __restrict__ __b
argument_list|,
argument|const _Tp* __restrict__ __e
argument_list|,
argument|_Tp* __restrict__ __o
argument_list|)
block|{
name|memcpy
argument_list|(
name|__o
argument_list|,
name|__b
argument_list|,
operator|(
name|__e
operator|-
name|__b
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
argument_list|)
block|; }
block|}
block|;
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|__valarray_copy_construct
argument_list|(
argument|const _Tp* __restrict__ __b
argument_list|,
argument|const _Tp* __restrict__ __e
argument_list|,
argument|_Tp* __restrict__ __o
argument_list|)
block|{
name|_Array_copy_ctor
operator|<
name|_Tp
block|,
name|__is_fundamental
operator|<
name|_Tp
operator|>
operator|::
name|_M_type
operator|>
operator|::
name|_S_do_it
argument_list|(
name|__b
argument_list|,
name|__e
argument_list|,
name|__o
argument_list|)
block|;      }
comment|// copy-construct raw array [__o, *) from strided array __a[<__n : __s>]
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|__valarray_copy_construct
argument_list|(
argument|const _Tp* __restrict__ __a
argument_list|,
argument|size_t __n
argument_list|,
argument|size_t __s
argument_list|,
argument|_Tp* __restrict__ __o
argument_list|)
block|{
if|if
condition|(
name|__is_fundamental
operator|<
name|_Tp
operator|>
operator|::
name|_M_type
condition|)
while|while
condition|(
name|__n
operator|--
condition|)
block|{
operator|*
name|__o
operator|++
operator|=
operator|*
name|__a
expr_stmt|;
name|__a
operator|+=
name|__s
expr_stmt|;
block|}
else|else
while|while
condition|(
name|__n
operator|--
condition|)
block|{
name|new
argument_list|(
argument|__o++
argument_list|)
name|_Tp
argument_list|(
operator|*
name|__a
argument_list|)
expr_stmt|;
name|__a
operator|+=
name|__s
expr_stmt|;
block|}
block|}
comment|// copy-construct raw array [__o, *) from indexed array __a[__i[<__n>]]
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|__valarray_copy_construct
argument_list|(
argument|const _Tp* __restrict__ __a
argument_list|,
argument|const size_t* __restrict__ __i
argument_list|,
argument|_Tp* __restrict__ __o
argument_list|,
argument|size_t __n
argument_list|)
block|{
if|if
condition|(
name|__is_fundamental
operator|<
name|_Tp
operator|>
operator|::
name|_M_type
condition|)
while|while
condition|(
name|__n
operator|--
condition|)
operator|*
name|__o
operator|++
operator|=
name|__a
index|[
operator|*
name|__i
operator|++
index|]
expr_stmt|;
else|else
while|while
condition|(
name|__n
operator|--
condition|)
name|new
argument_list|(
argument|__o++
argument_list|)
name|_Tp
argument_list|(
name|__a
index|[
operator|*
name|__i
operator|++
index|]
argument_list|)
expr_stmt|;
block|}
comment|// Do the necessary cleanup when we're done with arrays.
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|__valarray_destroy_elements
argument_list|(
argument|_Tp* __restrict__ __b
argument_list|,
argument|_Tp* __restrict__ __e
argument_list|)
block|{
if|if
condition|(
operator|!
name|__is_fundamental
operator|<
name|_Tp
operator|>
operator|::
name|_M_type
condition|)
while|while
condition|(
name|__b
operator|!=
name|__e
condition|)
block|{
name|__b
operator|->
expr|~
name|_Tp
argument_list|()
expr_stmt|;
operator|++
name|__b
expr_stmt|;
block|}
block|}
comment|// Fill a plain array __a[<__n>] with __t
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|__valarray_fill
argument_list|(
argument|_Tp* __restrict__ __a
argument_list|,
argument|size_t __n
argument_list|,
argument|const _Tp& __t
argument_list|)
block|{
while|while
condition|(
name|__n
operator|--
condition|)
operator|*
name|__a
operator|++
operator|=
name|__t
expr_stmt|;
block|}
comment|// fill strided array __a[<__n-1 : __s>] with __t
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|__valarray_fill
argument_list|(
argument|_Tp* __restrict__ __a
argument_list|,
argument|size_t __n
argument_list|,
argument|size_t __s
argument_list|,
argument|const _Tp& __t
argument_list|)
block|{
for|for
control|(
name|size_t
name|__i
init|=
literal|0
init|;
name|__i
operator|<
name|__n
condition|;
operator|++
name|__i
operator|,
name|__a
operator|+=
name|__s
control|)
operator|*
name|__a
operator|=
name|__t
expr_stmt|;
block|}
comment|// fill indir   ect array __a[__i[<__n>]] with __i
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|__valarray_fill
argument_list|(
argument|_Tp* __restrict__ __a
argument_list|,
argument|const size_t* __restrict__ __i
argument_list|,
argument|size_t __n
argument_list|,
argument|const _Tp& __t
argument_list|)
block|{
for|for
control|(
name|size_t
name|__j
init|=
literal|0
init|;
name|__j
operator|<
name|__n
condition|;
operator|++
name|__j
operator|,
operator|++
name|__i
control|)
name|__a
index|[
operator|*
name|__i
index|]
operator|=
name|__t
expr_stmt|;
block|}
comment|// copy plain array __a[<__n>] in __b[<__n>]
comment|// For non-fundamental types, it is wrong to say 'memcpy()'
name|template
operator|<
name|typename
name|_Tp
block|,
name|bool
operator|>
expr|struct
name|_Array_copier
block|{
specifier|inline
specifier|static
name|void
name|_S_do_it
argument_list|(
argument|const _Tp* __restrict__ __a
argument_list|,
argument|size_t __n
argument_list|,
argument|_Tp* __restrict__ __b
argument_list|)
block|{
while|while
condition|(
name|__n
operator|--
condition|)
operator|*
name|__b
operator|++
operator|=
operator|*
name|__a
operator|++
expr_stmt|;
block|}
expr|}
block|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|_Array_copier
operator|<
name|_Tp
block|,
name|true
operator|>
block|{
specifier|inline
specifier|static
name|void
name|_S_do_it
argument_list|(
argument|const _Tp* __restrict__ __a
argument_list|,
argument|size_t __n
argument_list|,
argument|_Tp* __restrict__ __b
argument_list|)
block|{
name|memcpy
argument_list|(
name|__b
argument_list|,
name|__a
argument_list|,
name|__n
operator|*
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
argument_list|)
block|; }
block|}
block|;
comment|// Copy a plain array __a[<__n>] into a play array __b[<>]
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|__valarray_copy
argument_list|(
argument|const _Tp* __restrict__ __a
argument_list|,
argument|size_t __n
argument_list|,
argument|_Tp* __restrict__ __b
argument_list|)
block|{
name|_Array_copier
operator|<
name|_Tp
block|,
name|__is_fundamental
operator|<
name|_Tp
operator|>
operator|::
name|_M_type
operator|>
operator|::
name|_S_do_it
argument_list|(
name|__a
argument_list|,
name|__n
argument_list|,
name|__b
argument_list|)
block|;      }
comment|// Copy strided array __a[<__n : __s>] in plain __b[<__n>]
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|__valarray_copy
argument_list|(
argument|const _Tp* __restrict__ __a
argument_list|,
argument|size_t __n
argument_list|,
argument|size_t __s
argument_list|,
argument|_Tp* __restrict__ __b
argument_list|)
block|{
for|for
control|(
name|size_t
name|__i
init|=
literal|0
init|;
name|__i
operator|<
name|__n
condition|;
operator|++
name|__i
operator|,
operator|++
name|__b
operator|,
name|__a
operator|+=
name|__s
control|)
operator|*
name|__b
operator|=
operator|*
name|__a
expr_stmt|;
block|}
comment|// Copy a plain array  __a[<__n>] into a strided array __b[<__n : __s>]
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|__valarray_copy
argument_list|(
argument|const _Tp* __restrict__ __a
argument_list|,
argument|_Tp* __restrict__ __b
argument_list|,
argument|size_t __n
argument_list|,
argument|size_t __s
argument_list|)
block|{
for|for
control|(
name|size_t
name|__i
init|=
literal|0
init|;
name|__i
operator|<
name|__n
condition|;
operator|++
name|__i
operator|,
operator|++
name|__a
operator|,
name|__b
operator|+=
name|__s
control|)
operator|*
name|__b
operator|=
operator|*
name|__a
expr_stmt|;
block|}
comment|// Copy strided array __src[<__n : __s1>] into another
comment|// strided array __dst[< : __s2>].  Their sizes must match.
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|__valarray_copy
argument_list|(
argument|const _Tp* __restrict__ __src
argument_list|,
argument|size_t __n
argument_list|,
argument|size_t __s1
argument_list|,
argument|_Tp* __restrict__ __dst
argument_list|,
argument|size_t __s2
argument_list|)
block|{
for|for
control|(
name|size_t
name|__i
init|=
literal|0
init|;
name|__i
operator|<
name|__n
condition|;
operator|++
name|__i
control|)
name|__dst
index|[
name|__i
operator|*
name|__s2
index|]
operator|=
name|__src
index|[
name|__i
operator|*
name|__s1
index|]
expr_stmt|;
block|}
comment|// Copy an indexed array __a[__i[<__n>]] in plain array __b[<__n>]
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|__valarray_copy
argument_list|(
argument|const _Tp* __restrict__ __a
argument_list|,
argument|const size_t* __restrict__ __i
argument_list|,
argument|_Tp* __restrict__ __b
argument_list|,
argument|size_t __n
argument_list|)
block|{
for|for
control|(
name|size_t
name|__j
init|=
literal|0
init|;
name|__j
operator|<
name|__n
condition|;
operator|++
name|__j
operator|,
operator|++
name|__b
operator|,
operator|++
name|__i
control|)
operator|*
name|__b
operator|=
name|__a
index|[
operator|*
name|__i
index|]
expr_stmt|;
block|}
comment|// Copy a plain array __a[<__n>] in an indexed array __b[__i[<__n>]]
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|__valarray_copy
argument_list|(
argument|const _Tp* __restrict__ __a
argument_list|,
argument|size_t __n
argument_list|,
argument|_Tp* __restrict__ __b
argument_list|,
argument|const size_t* __restrict__ __i
argument_list|)
block|{
for|for
control|(
name|size_t
name|__j
init|=
literal|0
init|;
name|__j
operator|<
name|__n
condition|;
operator|++
name|__j
operator|,
operator|++
name|__a
operator|,
operator|++
name|__i
control|)
name|__b
index|[
operator|*
name|__i
index|]
operator|=
operator|*
name|__a
expr_stmt|;
block|}
comment|// Copy the __n first elements of an indexed array __src[<__i>] into
comment|// another indexed array __dst[<__j>].
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|__valarray_copy
argument_list|(
argument|const _Tp* __restrict__ __src
argument_list|,
argument|size_t __n
argument_list|,
argument|const size_t* __restrict__ __i
argument_list|,
argument|_Tp* __restrict__ __dst
argument_list|,
argument|const size_t* __restrict__ __j
argument_list|)
block|{
for|for
control|(
name|size_t
name|__k
init|=
literal|0
init|;
name|__k
operator|<
name|__n
condition|;
operator|++
name|__k
control|)
name|__dst
index|[
operator|*
name|__j
operator|++
index|]
operator|=
name|__src
index|[
operator|*
name|__i
operator|++
index|]
expr_stmt|;
block|}
comment|//
comment|// Compute the sum of elements in range [__f, __l)
comment|// This is a naive algorithm.  It suffers from cancelling.
comment|// In the future try to specialize
comment|// for _Tp = float, double, long double using a more accurate
comment|// algorithm.
comment|//
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|_Tp
name|__valarray_sum
argument_list|(
argument|const _Tp* __restrict__ __f
argument_list|,
argument|const _Tp* __restrict__ __l
argument_list|)
block|{
name|_Tp
name|__r
operator|=
name|_Tp
argument_list|()
block|;
while|while
condition|(
name|__f
operator|!=
name|__l
condition|)
name|__r
operator|+=
operator|*
name|__f
operator|++
expr_stmt|;
return|return
name|__r
return|;
block|}
comment|// Compute the product of all elements in range [__f, __l)
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|_Tp
name|__valarray_product
argument_list|(
argument|const _Tp* __restrict__ __f
argument_list|,
argument|const _Tp* __restrict__ __l
argument_list|)
block|{
name|_Tp
name|__r
operator|=
name|_Tp
argument_list|(
literal|1
argument_list|)
block|;
while|while
condition|(
name|__f
operator|!=
name|__l
condition|)
name|__r
operator|=
name|__r
operator|*
operator|*
name|__f
operator|++
expr_stmt|;
return|return
name|__r
return|;
block|}
comment|// Compute the min/max of an array-expression
name|template
operator|<
name|typename
name|_Ta
operator|>
specifier|inline
name|typename
name|_Ta
operator|::
name|value_type
name|__valarray_min
argument_list|(
argument|const _Ta& __a
argument_list|)
block|{
name|size_t
name|__s
operator|=
name|__a
operator|.
name|size
argument_list|()
block|;
typedef|typedef
name|typename
name|_Ta
operator|::
name|value_type
name|_Value_type
expr_stmt|;
name|_Value_type
name|__r
operator|=
name|__s
operator|==
literal|0
condition|?
name|_Value_type
argument_list|()
else|:
name|__a
index|[
literal|0
index|]
block|;
for|for
control|(
name|size_t
name|__i
init|=
literal|1
init|;
name|__i
operator|<
name|__s
condition|;
operator|++
name|__i
control|)
block|{
name|_Value_type
name|__t
init|=
name|__a
index|[
name|__i
index|]
decl_stmt|;
if|if
condition|(
name|__t
operator|<
name|__r
condition|)
name|__r
operator|=
name|__t
expr_stmt|;
block|}
return|return
name|__r
return|;
block|}
name|template
operator|<
name|typename
name|_Ta
operator|>
specifier|inline
name|typename
name|_Ta
operator|::
name|value_type
name|__valarray_max
argument_list|(
argument|const _Ta& __a
argument_list|)
block|{
name|size_t
name|__s
operator|=
name|__a
operator|.
name|size
argument_list|()
block|;
typedef|typedef
name|typename
name|_Ta
operator|::
name|value_type
name|_Value_type
expr_stmt|;
name|_Value_type
name|__r
operator|=
name|__s
operator|==
literal|0
condition|?
name|_Value_type
argument_list|()
else|:
name|__a
index|[
literal|0
index|]
block|;
for|for
control|(
name|size_t
name|__i
init|=
literal|1
init|;
name|__i
operator|<
name|__s
condition|;
operator|++
name|__i
control|)
block|{
name|_Value_type
name|__t
init|=
name|__a
index|[
name|__i
index|]
decl_stmt|;
if|if
condition|(
name|__t
operator|>
name|__r
condition|)
name|__r
operator|=
name|__t
expr_stmt|;
block|}
return|return
name|__r
return|;
block|}
comment|//
comment|// Helper class _Array, first layer of valarray abstraction.
comment|// All operations on valarray should be forwarded to this class
comment|// whenever possible. -- gdr
comment|//
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|_Array
block|{
name|explicit
name|_Array
argument_list|(
name|size_t
argument_list|)
block|;
name|explicit
name|_Array
argument_list|(
name|_Tp
operator|*
specifier|const
name|__restrict__
argument_list|)
block|;
name|explicit
name|_Array
argument_list|(
specifier|const
name|valarray
operator|<
name|_Tp
operator|>
operator|&
argument_list|)
block|;
name|_Array
argument_list|(
specifier|const
name|_Tp
operator|*
name|__restrict__
argument_list|,
name|size_t
argument_list|)
block|;
name|_Tp
operator|*
name|begin
argument_list|()
specifier|const
block|;
name|_Tp
operator|*
specifier|const
name|__restrict__
name|_M_data
block|;      }
block|;
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|__valarray_fill
argument_list|(
argument|_Array<_Tp> __a
argument_list|,
argument|size_t __n
argument_list|,
argument|const _Tp& __t
argument_list|)
block|{
name|__valarray_fill
argument_list|(
name|__a
operator|.
name|_M_data
argument_list|,
name|__n
argument_list|,
name|__t
argument_list|)
block|; }
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|__valarray_fill
argument_list|(
argument|_Array<_Tp> __a
argument_list|,
argument|size_t __n
argument_list|,
argument|size_t __s
argument_list|,
argument|const _Tp& __t
argument_list|)
block|{
name|__valarray_fill
argument_list|(
name|__a
operator|.
name|_M_data
argument_list|,
name|__n
argument_list|,
name|__s
argument_list|,
name|__t
argument_list|)
block|; }
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|__valarray_fill
argument_list|(
argument|_Array<_Tp> __a
argument_list|,
argument|_Array<size_t> __i
argument_list|,
argument|size_t __n
argument_list|,
argument|const _Tp& __t
argument_list|)
block|{
name|__valarray_fill
argument_list|(
name|__a
operator|.
name|_M_data
argument_list|,
name|__i
operator|.
name|_M_data
argument_list|,
name|__n
argument_list|,
name|__t
argument_list|)
block|; }
comment|// Copy a plain array __a[<__n>] into a play array __b[<>]
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|__valarray_copy
argument_list|(
argument|_Array<_Tp> __a
argument_list|,
argument|size_t __n
argument_list|,
argument|_Array<_Tp> __b
argument_list|)
block|{
name|__valarray_copy
argument_list|(
name|__a
operator|.
name|_M_data
argument_list|,
name|__n
argument_list|,
name|__b
operator|.
name|_M_data
argument_list|)
block|; }
comment|// Copy strided array __a[<__n : __s>] in plain __b[<__n>]
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|__valarray_copy
argument_list|(
argument|_Array<_Tp> __a
argument_list|,
argument|size_t __n
argument_list|,
argument|size_t __s
argument_list|,
argument|_Array<_Tp> __b
argument_list|)
block|{
name|__valarray_copy
argument_list|(
name|__a
operator|.
name|_M_data
argument_list|,
name|__n
argument_list|,
name|__s
argument_list|,
name|__b
operator|.
name|_M_data
argument_list|)
block|; }
comment|// Copy a plain array  __a[<__n>] into a strided array __b[<__n : __s>]
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|__valarray_copy
argument_list|(
argument|_Array<_Tp> __a
argument_list|,
argument|_Array<_Tp> __b
argument_list|,
argument|size_t __n
argument_list|,
argument|size_t __s
argument_list|)
block|{
name|__valarray_copy
argument_list|(
name|__a
operator|.
name|_M_data
argument_list|,
name|__b
operator|.
name|_M_data
argument_list|,
name|__n
argument_list|,
name|__s
argument_list|)
block|; }
comment|// Copy strided array __src[<__n : __s1>] into another
comment|// strided array __dst[< : __s2>].  Their sizes must match.
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|__valarray_copy
argument_list|(
argument|_Array<_Tp> __a
argument_list|,
argument|size_t __n
argument_list|,
argument|size_t __s1
argument_list|,
argument|_Array<_Tp> __b
argument_list|,
argument|size_t __s2
argument_list|)
block|{
name|__valarray_copy
argument_list|(
name|__a
operator|.
name|_M_data
argument_list|,
name|__n
argument_list|,
name|__s1
argument_list|,
name|__b
operator|.
name|_M_data
argument_list|,
name|__s2
argument_list|)
block|; }
comment|// Copy an indexed array __a[__i[<__n>]] in plain array __b[<__n>]
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|__valarray_copy
argument_list|(
argument|_Array<_Tp> __a
argument_list|,
argument|_Array<size_t> __i
argument_list|,
argument|_Array<_Tp> __b
argument_list|,
argument|size_t __n
argument_list|)
block|{
name|__valarray_copy
argument_list|(
name|__a
operator|.
name|_M_data
argument_list|,
name|__i
operator|.
name|_M_data
argument_list|,
name|__b
operator|.
name|_M_data
argument_list|,
name|__n
argument_list|)
block|; }
comment|// Copy a plain array __a[<__n>] in an indexed array __b[__i[<__n>]]
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|__valarray_copy
argument_list|(
argument|_Array<_Tp> __a
argument_list|,
argument|size_t __n
argument_list|,
argument|_Array<_Tp> __b
argument_list|,
argument|_Array<size_t> __i
argument_list|)
block|{
name|__valarray_copy
argument_list|(
name|__a
operator|.
name|_M_data
argument_list|,
name|__n
argument_list|,
name|__b
operator|.
name|_M_data
argument_list|,
name|__i
operator|.
name|_M_data
argument_list|)
block|; }
comment|// Copy the __n first elements of an indexed array __src[<__i>] into
comment|// another indexed array __dst[<__j>].
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|__valarray_copy
argument_list|(
argument|_Array<_Tp> __src
argument_list|,
argument|size_t __n
argument_list|,
argument|_Array<size_t> __i
argument_list|,
argument|_Array<_Tp> __dst
argument_list|,
argument|_Array<size_t> __j
argument_list|)
block|{
name|__valarray_copy
argument_list|(
name|__src
operator|.
name|_M_data
argument_list|,
name|__n
argument_list|,
name|__i
operator|.
name|_M_data
argument_list|,
name|__dst
operator|.
name|_M_data
argument_list|,
name|__j
operator|.
name|_M_data
argument_list|)
block|;      }
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|_Array
operator|<
name|_Tp
operator|>
operator|::
name|_Array
argument_list|(
argument|size_t __n
argument_list|)
operator|:
name|_M_data
argument_list|(
argument|__valarray_get_storage<_Tp>(__n)
argument_list|)
block|{
name|__valarray_default_construct
argument_list|(
name|_M_data
argument_list|,
name|_M_data
operator|+
name|__n
argument_list|)
block|; }
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|_Array
operator|<
name|_Tp
operator|>
operator|::
name|_Array
argument_list|(
argument|_Tp* const __restrict__ __p
argument_list|)
operator|:
name|_M_data
argument_list|(
argument|__p
argument_list|)
block|{}
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|_Array
operator|<
name|_Tp
operator|>
operator|::
name|_Array
argument_list|(
specifier|const
name|valarray
operator|<
name|_Tp
operator|>
operator|&
name|__v
argument_list|)
operator|:
name|_M_data
argument_list|(
argument|__v._M_data
argument_list|)
block|{}
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|_Array
operator|<
name|_Tp
operator|>
operator|::
name|_Array
argument_list|(
argument|const _Tp* __restrict__ __b
argument_list|,
argument|size_t __s
argument_list|)
operator|:
name|_M_data
argument_list|(
argument|__valarray_get_storage<_Tp>(__s)
argument_list|)
block|{
name|__valarray_copy_construct
argument_list|(
name|__b
argument_list|,
name|__s
argument_list|,
name|_M_data
argument_list|)
block|; }
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|_Tp
operator|*
name|_Array
operator|<
name|_Tp
operator|>
operator|::
name|begin
argument_list|()
specifier|const
block|{
return|return
name|_M_data
return|;
block|}
define|#
directive|define
name|_DEFINE_ARRAY_FUNCTION
parameter_list|(
name|_Op
parameter_list|,
name|_Name
parameter_list|)
define|\
value|template<typename _Tp>							\ inline void								\ _Array_augmented_##_Name (_Array<_Tp> __a, size_t __n, const _Tp& __t)	\ {									\   for (_Tp* __p=__a._M_data; __p<__a._M_data+__n; ++__p)		\     *__p _Op##= __t;							\ }									\ 									\ template<typename _Tp>							\ inline void								\ _Array_augmented_##_Name (_Array<_Tp> __a, size_t __n, _Array<_Tp> __b)	\ {									\   _Tp* __p = __a._M_data;						\   for (_Tp* __q=__b._M_data; __q<__b._M_data+__n; ++__p, ++__q)		\     *__p _Op##= *__q;							\ }									\ 									\ template<typename _Tp, class _Dom>					\ void									\ _Array_augmented_##_Name (_Array<_Tp> __a, 				\                          const _Expr<_Dom,_Tp>& __e, size_t __n)	\ {									\     _Tp* __p (__a._M_data);						\     for (size_t __i=0; __i<__n; ++__i, ++__p) *__p _Op##= __e[__i];	\ }									\ 									\ template<typename _Tp>							\ inline void								\ _Array_augmented_##_Name (_Array<_Tp> __a, size_t __n, size_t __s, 	\ 			 _Array<_Tp> __b)				\ {					       				\     _Tp* __q (__b._M_data);						\     for (_Tp* __p=__a._M_data; __p<__a._M_data+__s*__n; __p+=__s, ++__q) \       *__p _Op##= *__q;							\ }									\ 									\ template<typename _Tp>							\ inline void								\ _Array_augmented_##_Name (_Array<_Tp> __a, _Array<_Tp> __b, 		\ 			 size_t __n, size_t __s)			\ {									\     _Tp* __q (__b._M_data);						\     for (_Tp* __p=__a._M_data; __p<__a._M_data+__n; ++__p, __q+=__s)	\       *__p _Op##= *__q;							\ }									\ 									\ template<typename _Tp, class _Dom>					\ void									\ _Array_augmented_##_Name (_Array<_Tp> __a, size_t __s,			\                           const _Expr<_Dom,_Tp>& __e, size_t __n)	\ {									\     _Tp* __p (__a._M_data);						\     for (size_t __i=0; __i<__n; ++__i, __p+=__s) *__p _Op##= __e[__i];	\ }									\ 									\ template<typename _Tp>							\ inline void								\ _Array_augmented_##_Name (_Array<_Tp> __a, _Array<size_t> __i,		\                           _Array<_Tp> __b, size_t __n)			\ {									\     _Tp* __q (__b._M_data);						\     for (size_t* __j=__i._M_data; __j<__i._M_data+__n; ++__j, ++__q)	\         __a._M_data[*__j] _Op##= *__q;					\ }									\ 									\ template<typename _Tp>							\ inline void								\ _Array_augmented_##_Name (_Array<_Tp> __a, size_t __n,			\                           _Array<_Tp> __b, _Array<size_t> __i)		\ {									\     _Tp* __p (__a._M_data);						\     for (size_t* __j=__i._M_data; __j<__i._M_data+__n; ++__j, ++__p)	\         *__p _Op##= __b._M_data[*__j];					\ }									\ 									\ template<typename _Tp, class _Dom>					\ void									\ _Array_augmented_##_Name (_Array<_Tp> __a, _Array<size_t> __i,		\                           const _Expr<_Dom, _Tp>& __e, size_t __n)	\ {									\     size_t* __j (__i._M_data);						\     for (size_t __k=0; __k<__n; ++__k, ++__j) 				\       __a._M_data[*__j] _Op##= __e[__k];				\ }									\ 									\ template<typename _Tp>							\ void									\ _Array_augmented_##_Name (_Array<_Tp> __a, _Array<bool> __m,		\                           _Array<_Tp> __b, size_t __n)			\ {									\     bool* ok (__m._M_data);						\     _Tp* __p (__a._M_data);						\     for (_Tp* __q=__b._M_data; __q<__b._M_data+__n; ++__q, ++ok, ++__p) { \         while (! *ok) {							\             ++ok;							\             ++__p;							\         }								\         *__p _Op##= *__q;						\     }									\ }									\ 									\ template<typename _Tp>							\ void									\ _Array_augmented_##_Name (_Array<_Tp> __a, size_t __n,			\                          _Array<_Tp> __b, _Array<bool> __m)		\ {									\     bool* ok (__m._M_data);						\     _Tp* __q (__b._M_data);						\     for (_Tp* __p=__a._M_data; __p<__a._M_data+__n; ++__p, ++ok, ++__q) { \         while (! *ok) {							\             ++ok;							\             ++__q;							\         }								\         *__p _Op##= *__q;						\     }									\ }									\ 									\ template<typename _Tp, class _Dom>					\ void									\ _Array_augmented_##_Name (_Array<_Tp> __a, _Array<bool> __m,		\                           const _Expr<_Dom, _Tp>& __e, size_t __n)	\ {									\     bool* ok(__m._M_data);						\     _Tp* __p (__a._M_data);						\     for (size_t __i=0; __i<__n; ++__i, ++ok, ++__p) {			\         while (! *ok) {							\             ++ok;							\             ++__p;							\         }								\         *__p _Op##= __e[__i];						\     }									\ }
name|_DEFINE_ARRAY_FUNCTION
argument_list|(
argument|+
argument_list|,
argument|__plus
argument_list|)
name|_DEFINE_ARRAY_FUNCTION
argument_list|(
argument|-
argument_list|,
argument|__minus
argument_list|)
name|_DEFINE_ARRAY_FUNCTION
argument_list|(
argument|*
argument_list|,
argument|__multiplies
argument_list|)
name|_DEFINE_ARRAY_FUNCTION
argument_list|(
argument|/
argument_list|,
argument|__divides
argument_list|)
name|_DEFINE_ARRAY_FUNCTION
argument_list|(
argument|%
argument_list|,
argument|__modulus
argument_list|)
name|_DEFINE_ARRAY_FUNCTION
argument_list|(
argument|^
argument_list|,
argument|__bitwise_xor
argument_list|)
name|_DEFINE_ARRAY_FUNCTION
argument_list|(
argument||
argument_list|,
argument|__bitwise_or
argument_list|)
name|_DEFINE_ARRAY_FUNCTION
argument_list|(
argument|&
argument_list|,
argument|__bitwise_and
argument_list|)
name|_DEFINE_ARRAY_FUNCTION
argument_list|(
argument|<<
argument_list|,
argument|__shift_left
argument_list|)
name|_DEFINE_ARRAY_FUNCTION
argument_list|(
argument|>>
argument_list|,
argument|__shift_right
argument_list|)
undef|#
directive|undef
name|_DEFINE_VALARRAY_FUNCTION
expr|}
end_decl_stmt

begin_comment
comment|// std::
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCPP_NO_TEMPLATE_EXPORT
end_ifdef

begin_define
define|#
directive|define
name|export
end_define

begin_include
include|#
directive|include
file|<bits/valarray_array.tcc>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CPP_BITS_ARRAY_H */
end_comment

begin_comment
comment|// Local Variables:
end_comment

begin_comment
comment|// mode:c++
end_comment

begin_comment
comment|// End:
end_comment

end_unit

