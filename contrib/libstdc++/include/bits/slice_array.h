begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// The template and inlines for the -*- C++ -*- slice_array class.
end_comment

begin_comment
comment|// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2004
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
comment|// Written by Gabriel Dos Reis<Gabriel.Dos-Reis@DPTMaths.ENS-Cachan.Fr>
end_comment

begin_comment
comment|/** @file slice_array.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SLICE_ARRAY_H
end_ifndef

begin_define
define|#
directive|define
name|_SLICE_ARRAY_H
value|1
end_define

begin_pragma
pragma|#
directive|pragma
name|GCC
name|system_header
end_pragma

begin_decl_stmt
name|namespace
name|std
block|{
comment|/**    *  @brief  Class defining one-dimensional subset of an array.    *    *  The slice class represents a one-dimensional subset of an array,    *  specified by three parameters: start offset, size, and stride.  The    *  start offset is the index of the first element of the array that is part    *  of the subset.  The size is the total number of elements in the subset.    *  Stride is the distance between each successive array element to include    *  in the subset.    *    *  For example, with an array of size 10, and a slice with offset 1, size 3    *  and stride 2, the subset consists of array elements 1, 3, and 5.    */
name|class
name|slice
block|{
name|public
label|:
comment|///  Construct an empty slice.
name|slice
argument_list|()
expr_stmt|;
comment|/**      *  @brief  Construct a slice.      *      *  @param  o  Offset in array of first element.      *  @param  d  Number of elements in slice.      *  @param  s  Stride between array elements.      */
name|slice
argument_list|(
name|size_t
argument_list|,
name|size_t
argument_list|,
name|size_t
argument_list|)
expr_stmt|;
comment|///  Return array offset of first slice element.
name|size_t
name|start
argument_list|()
specifier|const
expr_stmt|;
comment|///  Return size of slice.
name|size_t
name|size
argument_list|()
specifier|const
expr_stmt|;
comment|///  Return array stride of slice.
name|size_t
name|stride
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|size_t
name|_M_off
decl_stmt|;
comment|// offset
name|size_t
name|_M_sz
decl_stmt|;
comment|// size
name|size_t
name|_M_st
decl_stmt|;
comment|// stride unit
block|}
empty_stmt|;
comment|// The default constructor constructor is not required to initialize
comment|// data members with any meaningful values, so we choose to do nothing.
specifier|inline
name|slice
operator|::
name|slice
argument_list|()
block|{}
specifier|inline
name|slice
operator|::
name|slice
argument_list|(
argument|size_t __o
argument_list|,
argument|size_t __d
argument_list|,
argument|size_t __s
argument_list|)
operator|:
name|_M_off
argument_list|(
name|__o
argument_list|)
operator|,
name|_M_sz
argument_list|(
name|__d
argument_list|)
operator|,
name|_M_st
argument_list|(
argument|__s
argument_list|)
block|{}
specifier|inline
name|size_t
name|slice
operator|::
name|start
argument_list|()
specifier|const
block|{
return|return
name|_M_off
return|;
block|}
specifier|inline
name|size_t
name|slice
operator|::
name|size
argument_list|()
specifier|const
block|{
return|return
name|_M_sz
return|;
block|}
specifier|inline
name|size_t
name|slice
operator|::
name|stride
argument_list|()
specifier|const
block|{
return|return
name|_M_st
return|;
block|}
comment|/**    *  @brief  Reference to one-dimensional subset of an array.    *    *  A slice_array is a reference to the actual elements of an array    *  specified by a slice.  The way to get a slice_array is to call    *  operator[](slice) on a valarray.  The returned slice_array then permits    *  carrying operations out on the referenced subset of elements in the    *  original valarray.  For example, operator+=(valarray) will add values    *  to the subset of elements in the underlying valarray this slice_array    *  refers to.    *    *  @param  Tp  Element type.    */
name|template
operator|<
name|typename
name|_Tp
operator|>
name|class
name|slice_array
block|{
name|public
operator|:
typedef|typedef
name|_Tp
name|value_type
typedef|;
comment|// _GLIBCXX_RESOLVE_LIB_DEFECTS
comment|// 253. valarray helper functions are almost entirely useless
comment|///  Copy constructor.  Both slices refer to the same underlying array.
name|slice_array
argument_list|(
specifier|const
name|slice_array
operator|&
argument_list|)
expr_stmt|;
comment|///  Assignment operator.  Assigns slice elements to corresponding
comment|///  elements of @a a.
name|slice_array
modifier|&
name|operator
init|=
operator|(
specifier|const
name|slice_array
operator|&
operator|)
decl_stmt|;
comment|///  Assign slice elements to corresponding elements of @a v.
name|void
name|operator
init|=
operator|(
specifier|const
name|valarray
operator|<
name|_Tp
operator|>
operator|&
operator|)
specifier|const
decl_stmt|;
comment|///  Multiply slice elements by corresponding elements of @a v.
name|void
name|operator
operator|*=
operator|(
specifier|const
name|valarray
operator|<
name|_Tp
operator|>
operator|&
operator|)
specifier|const
expr_stmt|;
comment|///  Divide slice elements by corresponding elements of @a v.
name|void
name|operator
operator|/=
operator|(
specifier|const
name|valarray
operator|<
name|_Tp
operator|>
operator|&
operator|)
specifier|const
expr_stmt|;
comment|///  Modulo slice elements by corresponding elements of @a v.
name|void
name|operator
operator|%=
operator|(
specifier|const
name|valarray
operator|<
name|_Tp
operator|>
operator|&
operator|)
specifier|const
expr_stmt|;
comment|///  Add corresponding elements of @a v to slice elements.
name|void
name|operator
operator|+=
operator|(
specifier|const
name|valarray
operator|<
name|_Tp
operator|>
operator|&
operator|)
specifier|const
expr_stmt|;
comment|///  Subtract corresponding elements of @a v from slice elements.
name|void
name|operator
operator|-=
operator|(
specifier|const
name|valarray
operator|<
name|_Tp
operator|>
operator|&
operator|)
specifier|const
expr_stmt|;
comment|///  Logical xor slice elements with corresponding elements of @a v.
name|void
name|operator
operator|^=
operator|(
specifier|const
name|valarray
operator|<
name|_Tp
operator|>
operator|&
operator|)
specifier|const
expr_stmt|;
comment|///  Logical and slice elements with corresponding elements of @a v.
name|void
name|operator
operator|&=
operator|(
specifier|const
name|valarray
operator|<
name|_Tp
operator|>
operator|&
operator|)
specifier|const
expr_stmt|;
comment|///  Logical or slice elements with corresponding elements of @a v.
name|void
name|operator
operator||=
operator|(
specifier|const
name|valarray
operator|<
name|_Tp
operator|>
operator|&
operator|)
specifier|const
expr_stmt|;
comment|///  Left shift slice elements by corresponding elements of @a v.
name|void
name|operator
operator|<<=
operator|(
specifier|const
name|valarray
operator|<
name|_Tp
operator|>
operator|&
operator|)
specifier|const
expr_stmt|;
comment|///  Right shift slice elements by corresponding elements of @a v.
name|void
name|operator
operator|>>=
operator|(
specifier|const
name|valarray
operator|<
name|_Tp
operator|>
operator|&
operator|)
specifier|const
expr_stmt|;
comment|///  Assign all slice elements to @a t.
name|void
name|operator
init|=
operator|(
specifier|const
name|_Tp
operator|&
operator|)
specifier|const
decl_stmt|;
comment|//        ~slice_array ();
name|template
operator|<
name|class
name|_Dom
operator|>
name|void
name|operator
operator|=
operator|(
specifier|const
name|_Expr
operator|<
name|_Dom
operator|,
name|_Tp
operator|>
operator|&
operator|)
specifier|const
expr_stmt|;
name|template
operator|<
name|class
name|_Dom
operator|>
name|void
name|operator
operator|*=
operator|(
specifier|const
name|_Expr
operator|<
name|_Dom
operator|,
name|_Tp
operator|>
operator|&
operator|)
specifier|const
expr_stmt|;
name|template
operator|<
name|class
name|_Dom
operator|>
name|void
name|operator
operator|/=
operator|(
specifier|const
name|_Expr
operator|<
name|_Dom
operator|,
name|_Tp
operator|>
operator|&
operator|)
specifier|const
expr_stmt|;
name|template
operator|<
name|class
name|_Dom
operator|>
name|void
name|operator
operator|%=
operator|(
specifier|const
name|_Expr
operator|<
name|_Dom
operator|,
name|_Tp
operator|>
operator|&
operator|)
specifier|const
expr_stmt|;
name|template
operator|<
name|class
name|_Dom
operator|>
name|void
name|operator
operator|+=
operator|(
specifier|const
name|_Expr
operator|<
name|_Dom
operator|,
name|_Tp
operator|>
operator|&
operator|)
specifier|const
expr_stmt|;
name|template
operator|<
name|class
name|_Dom
operator|>
name|void
name|operator
operator|-=
operator|(
specifier|const
name|_Expr
operator|<
name|_Dom
operator|,
name|_Tp
operator|>
operator|&
operator|)
specifier|const
expr_stmt|;
name|template
operator|<
name|class
name|_Dom
operator|>
name|void
name|operator
operator|^=
operator|(
specifier|const
name|_Expr
operator|<
name|_Dom
operator|,
name|_Tp
operator|>
operator|&
operator|)
specifier|const
expr_stmt|;
name|template
operator|<
name|class
name|_Dom
operator|>
name|void
name|operator
operator|&=
operator|(
specifier|const
name|_Expr
operator|<
name|_Dom
operator|,
name|_Tp
operator|>
operator|&
operator|)
specifier|const
expr_stmt|;
name|template
operator|<
name|class
name|_Dom
operator|>
name|void
name|operator
operator||=
operator|(
specifier|const
name|_Expr
operator|<
name|_Dom
operator|,
name|_Tp
operator|>
operator|&
operator|)
specifier|const
expr_stmt|;
name|template
operator|<
name|class
name|_Dom
operator|>
name|void
name|operator
operator|<<=
operator|(
specifier|const
name|_Expr
operator|<
name|_Dom
operator|,
name|_Tp
operator|>
operator|&
operator|)
specifier|const
expr_stmt|;
name|template
operator|<
name|class
name|_Dom
operator|>
name|void
name|operator
operator|>>=
operator|(
specifier|const
name|_Expr
operator|<
name|_Dom
operator|,
name|_Tp
operator|>
operator|&
operator|)
specifier|const
expr_stmt|;
name|private
label|:
name|friend
name|class
name|valarray
operator|<
name|_Tp
operator|>
expr_stmt|;
name|slice_array
argument_list|(
name|_Array
operator|<
name|_Tp
operator|>
argument_list|,
specifier|const
name|slice
operator|&
argument_list|)
expr_stmt|;
specifier|const
name|size_t
name|_M_sz
decl_stmt|;
specifier|const
name|size_t
name|_M_stride
decl_stmt|;
specifier|const
name|_Array
operator|<
name|_Tp
operator|>
name|_M_array
expr_stmt|;
comment|// not implemented
name|slice_array
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|slice_array
operator|<
name|_Tp
operator|>
operator|::
name|slice_array
argument_list|(
name|_Array
operator|<
name|_Tp
operator|>
name|__a
argument_list|,
specifier|const
name|slice
operator|&
name|__s
argument_list|)
operator|:
name|_M_sz
argument_list|(
name|__s
operator|.
name|size
argument_list|()
argument_list|)
operator|,
name|_M_stride
argument_list|(
name|__s
operator|.
name|stride
argument_list|()
argument_list|)
operator|,
name|_M_array
argument_list|(
argument|__a.begin() + __s.start()
argument_list|)
block|{}
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|slice_array
operator|<
name|_Tp
operator|>
operator|::
name|slice_array
argument_list|(
specifier|const
name|slice_array
operator|<
name|_Tp
operator|>
operator|&
name|a
argument_list|)
operator|:
name|_M_sz
argument_list|(
name|a
operator|.
name|_M_sz
argument_list|)
operator|,
name|_M_stride
argument_list|(
name|a
operator|.
name|_M_stride
argument_list|)
operator|,
name|_M_array
argument_list|(
argument|a._M_array
argument_list|)
block|{}
comment|//    template<typename _Tp>
comment|//    inline slice_array<_Tp>::~slice_array () {}
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|slice_array
operator|<
name|_Tp
operator|>
operator|&
name|slice_array
operator|<
name|_Tp
operator|>
operator|::
name|operator
operator|=
operator|(
specifier|const
name|slice_array
operator|<
name|_Tp
operator|>
operator|&
name|__a
operator|)
block|{
name|std
operator|::
name|__valarray_copy
argument_list|(
name|__a
operator|.
name|_M_array
argument_list|,
name|__a
operator|.
name|_M_sz
argument_list|,
name|__a
operator|.
name|_M_stride
argument_list|,
name|_M_array
argument_list|,
name|_M_stride
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|slice_array
operator|<
name|_Tp
operator|>
operator|::
name|operator
operator|=
operator|(
specifier|const
name|_Tp
operator|&
name|__t
operator|)
specifier|const
block|{
name|std
operator|::
name|__valarray_fill
argument_list|(
name|_M_array
argument_list|,
name|_M_sz
argument_list|,
name|_M_stride
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
name|slice_array
operator|<
name|_Tp
operator|>
operator|::
name|operator
operator|=
operator|(
specifier|const
name|valarray
operator|<
name|_Tp
operator|>
operator|&
name|__v
operator|)
specifier|const
block|{
name|std
operator|::
name|__valarray_copy
argument_list|(
name|_Array
operator|<
name|_Tp
operator|>
operator|(
name|__v
operator|)
argument_list|,
name|_M_array
argument_list|,
name|_M_sz
argument_list|,
name|_M_stride
argument_list|)
block|; }
name|template
operator|<
name|typename
name|_Tp
operator|>
name|template
operator|<
name|class
name|_Dom
operator|>
specifier|inline
name|void
name|slice_array
operator|<
name|_Tp
operator|>
operator|::
name|operator
operator|=
operator|(
specifier|const
name|_Expr
operator|<
name|_Dom
operator|,
name|_Tp
operator|>
operator|&
name|__e
operator|)
specifier|const
block|{
name|std
operator|::
name|__valarray_copy
argument_list|(
name|__e
argument_list|,
name|_M_sz
argument_list|,
name|_M_array
argument_list|,
name|_M_stride
argument_list|)
block|; }
undef|#
directive|undef
name|_DEFINE_VALARRAY_OPERATOR
define|#
directive|define
name|_DEFINE_VALARRAY_OPERATOR
parameter_list|(
name|_Op
parameter_list|,
name|_Name
parameter_list|)
define|\
value|template<typename _Tp>						\     inline void								\     slice_array<_Tp>::operator _Op##=(const valarray<_Tp>& __v) const	\     {									\       _Array_augmented_##_Name(_M_array, _M_sz, _M_stride, _Array<_Tp>(__v));\     }									\ 									\   template<typename _Tp>                                                \     template<class _Dom>				                \       inline void							\       slice_array<_Tp>::operator _Op##=(const _Expr<_Dom,_Tp>& __e) const\       {									\ 	  _Array_augmented_##_Name(_M_array, _M_stride, __e, _M_sz);	\       }
name|_DEFINE_VALARRAY_OPERATOR
argument_list|(
argument|*
argument_list|,
argument|__multiplies
argument_list|)
name|_DEFINE_VALARRAY_OPERATOR
argument_list|(
argument|/
argument_list|,
argument|__divides
argument_list|)
name|_DEFINE_VALARRAY_OPERATOR
argument_list|(
argument|%
argument_list|,
argument|__modulus
argument_list|)
name|_DEFINE_VALARRAY_OPERATOR
argument_list|(
argument|+
argument_list|,
argument|__plus
argument_list|)
name|_DEFINE_VALARRAY_OPERATOR
argument_list|(
argument|-
argument_list|,
argument|__minus
argument_list|)
name|_DEFINE_VALARRAY_OPERATOR
argument_list|(
argument|^
argument_list|,
argument|__bitwise_xor
argument_list|)
name|_DEFINE_VALARRAY_OPERATOR
argument_list|(
argument|&
argument_list|,
argument|__bitwise_and
argument_list|)
name|_DEFINE_VALARRAY_OPERATOR
argument_list|(
argument||
argument_list|,
argument|__bitwise_or
argument_list|)
name|_DEFINE_VALARRAY_OPERATOR
argument_list|(
argument|<<
argument_list|,
argument|__shift_left
argument_list|)
name|_DEFINE_VALARRAY_OPERATOR
argument_list|(
argument|>>
argument_list|,
argument|__shift_right
argument_list|)
end_expr_stmt

begin_undef
undef|#
directive|undef
name|_DEFINE_VALARRAY_OPERATOR
end_undef

begin_comment
unit|}
comment|// std::
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SLICE_ARRAY_H */
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

