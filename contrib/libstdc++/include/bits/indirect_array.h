begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// The template and inlines for the -*- C++ -*- indirect_array class.
end_comment

begin_comment
comment|// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2004, 2005
end_comment

begin_comment
comment|//  Free Software Foundation, Inc.
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
comment|// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
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
comment|/** @file indirect_array.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_comment
comment|// Written by Gabriel Dos Reis<Gabriel.Dos-Reis@DPTMaths.ENS-Cachan.Fr>
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_INDIRECT_ARRAY_H
end_ifndef

begin_define
define|#
directive|define
name|_INDIRECT_ARRAY_H
value|1
end_define

begin_pragma
pragma|#
directive|pragma
name|GCC
name|system_header
end_pragma

begin_macro
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|std
argument_list|)
end_macro

begin_comment
comment|/**    *  @brief  Reference to arbitrary subset of an array.    *    *  An indirect_array is a reference to the actual elements of an array    *  specified by an ordered array of indices.  The way to get an    *  indirect_array is to call operator[](valarray<size_t>) on a valarray.    *  The returned indirect_array then permits carrying operations out on the    *  referenced subset of elements in the original valarray.    *    *  For example, if an indirect_array is obtained using the array (4,2,0) as    *  an argument, and then assigned to an array containing (1,2,3), then the    *  underlying array will have array[0]==3, array[2]==2, and array[4]==1.    *    *  @param  Tp  Element type.    */
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|>
name|class
name|indirect_array
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
name|indirect_array
argument_list|(
specifier|const
name|indirect_array
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|///  Assignment operator.  Assigns elements to corresponding elements
end_comment

begin_comment
comment|///  of @a a.
end_comment

begin_decl_stmt
name|indirect_array
modifier|&
name|operator
init|=
operator|(
specifier|const
name|indirect_array
operator|&
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|///  Assign slice elements to corresponding elements of @a v.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|///  Multiply slice elements by corresponding elements of @a v.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|///  Divide slice elements by corresponding elements of @a v.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|///  Modulo slice elements by corresponding elements of @a v.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|///  Add corresponding elements of @a v to slice elements.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|///  Subtract corresponding elements of @a v from slice elements.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|///  Logical xor slice elements with corresponding elements of @a v.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|///  Logical and slice elements with corresponding elements of @a v.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|///  Logical or slice elements with corresponding elements of @a v.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|///  Left shift slice elements by corresponding elements of @a v.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|///  Right shift slice elements by corresponding elements of @a v.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|///  Assign all slice elements to @a t.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|//    ~indirect_array();
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|///  Copy constructor.  Both slices refer to the same underlying array.
end_comment

begin_expr_stmt
name|indirect_array
argument_list|(
name|_Array
operator|<
name|_Tp
operator|>
argument_list|,
name|size_t
argument_list|,
name|_Array
operator|<
name|size_t
operator|>
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|friend
name|class
name|valarray
operator|<
name|_Tp
operator|>
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|friend
name|class
name|gslice_array
operator|<
name|_Tp
operator|>
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|const
name|size_t
name|_M_sz
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|const
name|_Array
operator|<
name|size_t
operator|>
name|_M_index
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|_Array
operator|<
name|_Tp
operator|>
name|_M_array
expr_stmt|;
end_expr_stmt

begin_comment
comment|// not implemented
end_comment

begin_expr_stmt
name|indirect_array
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|indirect_array
operator|<
name|_Tp
operator|>
operator|::
name|indirect_array
argument_list|(
specifier|const
name|indirect_array
operator|<
name|_Tp
operator|>
operator|&
name|__a
argument_list|)
operator|:
name|_M_sz
argument_list|(
name|__a
operator|.
name|_M_sz
argument_list|)
operator|,
name|_M_index
argument_list|(
name|__a
operator|.
name|_M_index
argument_list|)
operator|,
name|_M_array
argument_list|(
argument|__a._M_array
argument_list|)
block|{}
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|indirect_array
operator|<
name|_Tp
operator|>
operator|::
name|indirect_array
argument_list|(
argument|_Array<_Tp> __a
argument_list|,
argument|size_t __s
argument_list|,
argument|_Array<size_t> __i
argument_list|)
operator|:
name|_M_sz
argument_list|(
name|__s
argument_list|)
operator|,
name|_M_index
argument_list|(
name|__i
argument_list|)
operator|,
name|_M_array
argument_list|(
argument|__a
argument_list|)
block|{}
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|indirect_array
operator|<
name|_Tp
operator|>
operator|&
name|indirect_array
operator|<
name|_Tp
operator|>
operator|::
name|operator
operator|=
operator|(
specifier|const
name|indirect_array
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
name|_M_sz
argument_list|,
name|__a
operator|.
name|_M_index
argument_list|,
name|_M_array
argument_list|,
name|_M_index
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
name|indirect_array
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
name|_M_index
argument_list|,
name|_M_sz
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
name|indirect_array
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
name|_M_sz
argument_list|,
name|_M_array
argument_list|,
name|_M_index
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
name|indirect_array
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
name|_M_index
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
value|template<typename _Tp>						\     inline void								\     indirect_array<_Tp>::operator _Op##=(const valarray<_Tp>& __v) const\     {									\       _Array_augmented_##_Name(_M_array, _M_index, _Array<_Tp>(__v), _M_sz); \     }									\ 									\   template<typename _Tp>                                                \     template<class _Dom>				                \       inline void							\       indirect_array<_Tp>::operator _Op##=(const _Expr<_Dom,_Tp>& __e) const\       {									\ 	_Array_augmented_##_Name(_M_array, _M_index, __e, _M_sz);	\       }
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
undef|#
directive|undef
name|_DEFINE_VALARRAY_OPERATOR
name|_GLIBCXX_END_NAMESPACE
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _INDIRECT_ARRAY_H */
end_comment

end_unit

