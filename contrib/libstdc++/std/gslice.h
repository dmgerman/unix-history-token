begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// The template and inlines for the -*- C++ -*- gslice class.
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
name|__GSLICE__
end_ifndef

begin_define
define|#
directive|define
name|__GSLICE__
end_define

begin_extern
extern|extern
literal|"C++"
block|{
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
name|class
name|gslice
block|{
name|public
label|:
name|gslice
argument_list|()
expr_stmt|;
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
name|gslice
argument_list|(
specifier|const
name|gslice
operator|&
argument_list|)
expr_stmt|;
operator|~
name|gslice
argument_list|()
expr_stmt|;
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
name|size_t
name|start
argument_list|()
specifier|const
expr_stmt|;
name|valarray
operator|<
name|size_t
operator|>
name|size
argument_list|()
specifier|const
expr_stmt|;
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
argument|new _Indexer(__o, __l, __s)
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
end_extern

begin_comment
unit|}
comment|// extern "C++"
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __GSLICE__
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

