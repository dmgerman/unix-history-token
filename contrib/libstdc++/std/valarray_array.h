begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// The template and inlines for the -*- C++ -*- internal _Array helper class.
end_comment

begin_comment
comment|// Copyright (C) 1997-1999 Cygnus Solutions
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

begin_ifndef
ifndef|#
directive|ifndef
name|__VALARRAY_ARRAY__
end_ifndef

begin_define
define|#
directive|define
name|__VALARRAY_ARRAY__
end_define

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

begin_extern
extern|extern
literal|"C++"
block|{
comment|//
comment|// Helper functions on raw pointers
comment|//
comment|// fill plain array __a[<__n>] with __t
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
comment|// fill indirect array __a[__i[<__n>]] with __i
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
comment|// copy strided array __a[<__n : __s>] in plain __b[<__n>]
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
comment|// copy plain __a[<__n>] in strided __b[<__n : __s>]
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
comment|// copy indexed __a[__i[<__n>]] in plain __b[<__n>]
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
comment|// copy plain __a[<__n>] in indexed __b[__i[<__n>]]
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
name|void
name|free_data
argument_list|()
specifier|const
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
block|; }
expr_stmt|;
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
argument|new _Tp[__n]
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
argument|new _Tp[__s]
argument_list|)
block|{
name|__valarray_copy
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
name|void
name|_Array
operator|<
name|_Tp
operator|>
operator|::
name|free_data
argument_list|()
specifier|const
block|{
name|delete
index|[]
name|_M_data
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
value|template<typename _Tp>							\ inline void								\ _Array_augmented_##_Name (_Array<_Tp> __a, size_t __n, const _Tp& __t)	\ {									\     for (_Tp* __p=__a._M_data; __p<__a._M_data+__n; ++__p) 		\       *__p _Op##= __t;							\ }									\ 									\ template<typename _Tp>							\ inline void								\ _Array_augmented_##_Name (_Array<_Tp> __a, size_t __n, _Array<_Tp> __b)	\ {									\     _Tp* __p (__a._M_data);						\     for (_Tp* __q=__b._M_data; __q<__b._M_data+__n; ++__p, ++__q) 	\       *__p _Op##= *__q;							\ }									\ 									\ template<typename _Tp, class _Dom>					\ void									\ _Array_augmented_##_Name (_Array<_Tp> __a, 				\                          const _Expr<_Dom,_Tp>& __e, size_t __n)	\ {									\     _Tp* __p (__a._M_data);						\     for (size_t __i=0; __i<__n; ++__i, ++__p) *__p _Op##= __e[__i];	\ }									\ 									\ template<typename _Tp>							\ inline void								\ _Array_augmented_##_Name (_Array<_Tp> __a, size_t __n, size_t __s, 	\ 			 _Array<_Tp> __b)				\ {					       				\     _Tp* __q (__b._M_data);						\     for (_Tp* __p=__a._M_data; __p<__a._M_data+__s*__n; __p+=__s, ++__q) \       *__p _Op##= *__q;							\ }									\ 									\ template<typename _Tp>							\ inline void								\ _Array_augmented_##_Name (_Array<_Tp> __a, _Array<_Tp> __b, 		\ 			 size_t __n, size_t __s)			\ {									\     _Tp* __q (__b._M_data);						\     for (_Tp* __p=__a._M_data; __p<__a._M_data+__n; ++__p, __q+=__s)	\       *__p _Op##= *__q;							\ }									\ 									\ template<typename _Tp, class _Dom>					\ void									\ _Array_augmented_##_Name (_Array<_Tp> __a, size_t __s,			\                           const _Expr<_Dom,_Tp>& __e, size_t __n)	\ {									\     _Tp* __p (__a._M_data);						\     for (size_t __i=0; __i<__n; ++__i, __p+=__s) *__p _Op##= __e[__i];	\ }									\ 									\ template<typename _Tp>							\ inline void								\ _Array_augmented_##_Name (_Array<_Tp> __a, _Array<size_t> __i,		\                           _Array<_Tp> __b, size_t __n)			\ {									\     _Tp* __q (__b._M_data);						\     for (size_t* __j=__i._M_data; __j<__i._M_data+__n; ++__j, ++__q)	\         __a._M_data[*__j] _Op##= *__q;					\ }									\ 									\ template<typename _Tp>							\ inline void								\ _Array_augmented_##_Name (_Array<_Tp> __a, size_t __n,			\                           _Array<_Tp> __b, _Array<size_t> __i)		\ {									\     _Tp* __p (__a._M_data);						\     for (size_t* __j=__i._M_data; __j<__i._M_data+__n; ++__j, ++__p)	\         *__p _Op##= __b._M_data[*__j];					\ }									\ 									\ template<typename _Tp, class _Dom>					\ void									\ _Array_augmented_##_Name (_Array<_Tp> __a, _Array<size_t> __i,		\                           const _Expr<_Dom, _Tp>& __e, size_t __n)	\ {									\     size_t* __j (__i._M_data);						\     for (size_t __k=0; __k<__n; ++__k, ++__j) 				\       __a._M_data[*__j] _Op##= __e[__k];				\ }									\ 									\ template<typename _Tp>							\ void									\ _Array_augmented_##_Name (_Array<_Tp> __a, _Array<bool> __m,		\                           _Array<_Tp> __b, size_t __n)			\ {									\     bool* ok (__m._M_data);						\     _Tp* __p (__a._M_data);						\     for (_Tp* __q=__b._M_data; __q<__b._M_data+__n; ++__q, ++ok, ++__p) { \         while (! *ok) {							\             ++ok;							\             ++__p;							\         }								\         *__p _Op##= *__q;						\     }									\ }									\ 									\ template<typename _Tp>							\ void									\ _Array_augmented_##_Name (_Array<_Tp> __a, size_t __n,			\                          _Array<_Tp> __b, _Array<bool> __m)		\ {									\     bool* ok (__m._M_data);						\     _Tp* __q (__b._M_data);						\     for (_Tp* __p=__a._M_data; __p<__a._M_data+__n; ++__p, ++ok, ++__q) { \         while (! *ok) {							\             ++ok;							\             ++__q;							\         }								\         *__p _Op##= *__q;						\     }									\ }									\ 									\ template<typename _Tp, class _Dom>					\ void									\ _Array_augmented_##_Name (_Array<_Tp> __a, _Array<bool> __m,		\                           const _Expr<_Dom, _Tp>& __e, size_t __n)	\ {									\     bool* ok(__m._M_data);						\     _Tp* __p (__a._M_data);						\     for (size_t __i=0; __i<__n; ++__i, ++ok, ++__p) {			\         while (! *ok) {							\             ++ok;							\             ++__p;							\         }								\         *__p _Op##= __e[__i];						\     }									\ }
name|_DEFINE_ARRAY_FUNCTION
argument_list|(
argument|+
argument_list|,
argument|plus
argument_list|)
name|_DEFINE_ARRAY_FUNCTION
argument_list|(
argument|-
argument_list|,
argument|minus
argument_list|)
name|_DEFINE_ARRAY_FUNCTION
argument_list|(
argument|*
argument_list|,
argument|multiplies
argument_list|)
name|_DEFINE_ARRAY_FUNCTION
argument_list|(
argument|/
argument_list|,
argument|divides
argument_list|)
name|_DEFINE_ARRAY_FUNCTION
argument_list|(
argument|%
argument_list|,
argument|modulus
argument_list|)
name|_DEFINE_ARRAY_FUNCTION
argument_list|(
argument|^
argument_list|,
argument|xor
argument_list|)
name|_DEFINE_ARRAY_FUNCTION
argument_list|(
argument||
argument_list|,
argument|or
argument_list|)
name|_DEFINE_ARRAY_FUNCTION
argument_list|(
argument|&
argument_list|,
argument|and
argument_list|)
name|_DEFINE_ARRAY_FUNCTION
argument_list|(
argument|<<
argument_list|,
argument|shift_left
argument_list|)
name|_DEFINE_ARRAY_FUNCTION
argument_list|(
argument|>>
argument_list|,
argument|shift_right
argument_list|)
undef|#
directive|undef
name|_DEFINE_ARRAY_FUNCTION
block|}
end_extern

begin_comment
comment|// extern "C++"
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_G_NO_VALARRAY_TEMPLATE_EXPORT
end_ifdef

begin_define
define|#
directive|define
name|export
end_define

begin_include
include|#
directive|include
file|<std/valarray_array.tcc>
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
comment|// __VALARRAY_ARRAY__
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

