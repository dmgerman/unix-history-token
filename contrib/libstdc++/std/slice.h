begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// The template and inlines for the -*- C++ -*- slice class.
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
name|__SLICE__
end_ifndef

begin_define
define|#
directive|define
name|__SLICE__
end_define

begin_extern
extern|extern
literal|"C++"
block|{
name|class
name|slice
block|{
name|public
label|:
name|slice
argument_list|()
expr_stmt|;
name|slice
argument_list|(
name|size_t
argument_list|,
name|size_t
argument_list|,
name|size_t
argument_list|)
expr_stmt|;
name|size_t
name|start
argument_list|()
specifier|const
expr_stmt|;
name|size_t
name|size
argument_list|()
specifier|const
expr_stmt|;
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
block|}
end_extern

begin_comment
comment|// extern "C++"
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __SLICE__
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

