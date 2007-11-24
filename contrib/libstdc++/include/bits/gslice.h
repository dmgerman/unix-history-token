begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// The template and inlines for the -*- C++ -*- gslice class.
end_comment

begin_comment
comment|// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2004
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
comment|/** @file gslice.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GSLICE_H
end_ifndef

begin_define
define|#
directive|define
name|_GSLICE_H
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
comment|/**    *  @brief  Class defining multi-dimensional subset of an array.    *    *  The slice class represents a multi-dimensional subset of an array,    *  specified by three parameter sets: start offset, size array, and stride    *  array.  The start offset is the index of the first element of the array    *  that is part of the subset.  The size and stride array describe each    *  dimension of the slice.  Size is the number of elements in that    *  dimension, and stride is the distance in the array between successive    *  elements in that dimension.  Each dimension's size and stride is taken    *  to begin at an array element described by the previous dimension.  The    *  size array and stride array must be the same size.    *    *  For example, if you have offset==3, stride[0]==11, size[1]==3,    *  stride[1]==3, then slice[0,0]==array[3], slice[0,1]==array[6],    *  slice[0,2]==array[9], slice[1,0]==array[14], slice[1,1]==array[17],    *  slice[1,2]==array[20].    */
name|class
name|gslice
block|{
name|public
label|:
comment|///  Construct an empty slice.
name|gslice
argument_list|()
expr_stmt|;
comment|/**        *  @brief  Construct a slice.        *        *  Constructs a slice with as many dimensions as the length of the @a l        *  and @a s arrays.        *        *  @param  o  Offset in array of first element.        *  @param  l  Array of dimension lengths.        *  @param  s  Array of dimension strides between array elements.        */
name|gslice
argument_list|(
name|size_t
argument_list|,
specifier|const
name|valarray
operator|<
name|size_t
operator|>
operator|&
argument_list|,
specifier|const
name|valarray
operator|<
name|size_t
operator|>
operator|&
argument_list|)
expr_stmt|;
comment|// XXX: the IS says the copy-ctor and copy-assignment operators are
comment|//      synthetized by the compiler but they are just unsuitable
comment|//      for a ref-counted semantic
comment|///  Copy constructor.
name|gslice
argument_list|(
specifier|const
name|gslice
operator|&
argument_list|)
expr_stmt|;
comment|///  Destructor.
operator|~
name|gslice
argument_list|()
expr_stmt|;
comment|// XXX: See the note above.
comment|///  Assignment operator.
name|gslice
modifier|&
name|operator
init|=
operator|(
specifier|const
name|gslice
operator|&
operator|)
decl_stmt|;
comment|///  Return array offset of first slice element.
name|size_t
name|start
argument_list|()
specifier|const
expr_stmt|;
comment|///  Return array of sizes of slice dimensions.
name|valarray
operator|<
name|size_t
operator|>
name|size
argument_list|()
specifier|const
expr_stmt|;
comment|///  Return array of array strides for each dimension.
name|valarray
operator|<
name|size_t
operator|>
name|stride
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
struct|struct
name|_Indexer
block|{
name|size_t
name|_M_count
decl_stmt|;
name|size_t
name|_M_start
decl_stmt|;
name|valarray
operator|<
name|size_t
operator|>
name|_M_size
expr_stmt|;
name|valarray
operator|<
name|size_t
operator|>
name|_M_stride
expr_stmt|;
name|valarray
operator|<
name|size_t
operator|>
name|_M_index
expr_stmt|;
comment|// Linear array of referenced indices
name|_Indexer
argument_list|(
name|size_t
argument_list|,
specifier|const
name|valarray
operator|<
name|size_t
operator|>
operator|&
argument_list|,
specifier|const
name|valarray
operator|<
name|size_t
operator|>
operator|&
argument_list|)
expr_stmt|;
name|void
name|_M_increment_use
parameter_list|()
block|{
operator|++
name|_M_count
expr_stmt|;
block|}
name|size_t
name|_M_decrement_use
parameter_list|()
block|{
return|return
operator|--
name|_M_count
return|;
block|}
block|}
struct|;
name|_Indexer
modifier|*
name|_M_index
decl_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
name|friend
name|class
name|valarray
expr_stmt|;
block|}
empty_stmt|;
specifier|inline
name|size_t
name|gslice
operator|::
name|start
argument_list|()
specifier|const
block|{
return|return
name|_M_index
operator|?
name|_M_index
operator|->
name|_M_start
operator|:
literal|0
return|;
block|}
specifier|inline
name|valarray
operator|<
name|size_t
operator|>
name|gslice
operator|::
name|size
argument_list|()
specifier|const
block|{
return|return
name|_M_index
operator|?
name|_M_index
operator|->
name|_M_size
operator|:
name|valarray
operator|<
name|size_t
operator|>
operator|(
operator|)
return|;
block|}
specifier|inline
name|valarray
operator|<
name|size_t
operator|>
name|gslice
operator|::
name|stride
argument_list|()
specifier|const
block|{
return|return
name|_M_index
operator|?
name|_M_index
operator|->
name|_M_stride
operator|:
name|valarray
operator|<
name|size_t
operator|>
operator|(
operator|)
return|;
block|}
specifier|inline
name|gslice
operator|::
name|gslice
argument_list|()
operator|:
name|_M_index
argument_list|(
literal|0
argument_list|)
block|{}
specifier|inline
name|gslice
operator|::
name|gslice
argument_list|(
argument|size_t __o
argument_list|,
argument|const valarray<size_t>& __l
argument_list|,
argument|const valarray<size_t>& __s
argument_list|)
operator|:
name|_M_index
argument_list|(
argument|new gslice::_Indexer(__o, __l, __s)
argument_list|)
block|{}
specifier|inline
name|gslice
operator|::
name|gslice
argument_list|(
specifier|const
name|gslice
operator|&
name|__g
argument_list|)
operator|:
name|_M_index
argument_list|(
argument|__g._M_index
argument_list|)
block|{
if|if
condition|(
name|_M_index
condition|)
name|_M_index
operator|->
name|_M_increment_use
argument_list|()
expr_stmt|;
block|}
specifier|inline
name|gslice
operator|::
operator|~
name|gslice
argument_list|()
block|{
if|if
condition|(
name|_M_index
operator|&&
name|_M_index
operator|->
name|_M_decrement_use
argument_list|()
operator|==
literal|0
condition|)
name|delete
name|_M_index
decl_stmt|;
block|}
specifier|inline
name|gslice
operator|&
name|gslice
operator|::
name|operator
operator|=
operator|(
specifier|const
name|gslice
operator|&
name|__g
operator|)
block|{
if|if
condition|(
name|__g
operator|.
name|_M_index
condition|)
name|__g
operator|.
name|_M_index
operator|->
name|_M_increment_use
argument_list|()
expr_stmt|;
if|if
condition|(
name|_M_index
operator|&&
name|_M_index
operator|->
name|_M_decrement_use
argument_list|()
operator|==
literal|0
condition|)
name|delete
name|_M_index
decl_stmt|;
name|_M_index
operator|=
name|__g
operator|.
name|_M_index
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_comment
unit|}
comment|// std::
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GSLICE_H */
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

