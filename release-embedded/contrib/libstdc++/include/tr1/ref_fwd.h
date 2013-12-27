begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// class template reference_wrapper forwarding header -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2004, 2005 Free Software Foundation, Inc.
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
comment|/** @file tr1/ref_fwd.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_comment
comment|// Douglas Gregor<doug.gregor -at- gmail.com>
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TR1_REF_FWD
end_ifndef

begin_define
define|#
directive|define
name|_TR1_REF_FWD
end_define

begin_decl_stmt
name|namespace
name|std
block|{
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|tr1
argument_list|)
name|template
operator|<
name|typename
name|_Tp
operator|>
name|class
name|reference_wrapper
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
name|reference_wrapper
operator|<
name|_Tp
operator|>
name|ref
argument_list|(
name|_Tp
operator|&
name|__t
argument_list|)
expr_stmt|;
comment|// Denotes a const reference should be taken to a variable.
name|template
operator|<
name|typename
name|_Tp
operator|>
name|reference_wrapper
operator|<
specifier|const
name|_Tp
operator|>
name|cref
argument_list|(
specifier|const
name|_Tp
operator|&
name|__t
argument_list|)
expr_stmt|;
name|_GLIBCXX_END_NAMESPACE
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

