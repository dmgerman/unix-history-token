begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Function-Based Exception Support -*- C++ -*-
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
comment|//
end_comment

begin_comment
comment|// ISO C++ 14882: 19.1  Exception classes
end_comment

begin_comment
comment|//
end_comment

begin_include
include|#
directive|include
file|<exception_defines.h>
end_include

begin_decl_stmt
name|namespace
name|std
block|{
comment|// Helper for exception objects in<except>
name|void
name|__throw_bad_exception
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// Helper for exception objects in<new>
name|void
name|__throw_bad_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// Helper for exception objects in<typeinfo>
name|void
name|__throw_bad_cast
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|__throw_bad_typeid
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// Helpers for exception objects in<stdexcept>
name|void
name|__throw_logic_error
parameter_list|(
specifier|const
name|char
modifier|*
name|__s
parameter_list|)
function_decl|;
name|void
name|__throw_domain_error
parameter_list|(
specifier|const
name|char
modifier|*
name|__s
parameter_list|)
function_decl|;
name|void
name|__throw_invalid_argument
parameter_list|(
specifier|const
name|char
modifier|*
name|__s
parameter_list|)
function_decl|;
name|void
name|__throw_length_error
parameter_list|(
specifier|const
name|char
modifier|*
name|__s
parameter_list|)
function_decl|;
name|void
name|__throw_out_of_range
parameter_list|(
specifier|const
name|char
modifier|*
name|__s
parameter_list|)
function_decl|;
name|void
name|__throw_runtime_error
parameter_list|(
specifier|const
name|char
modifier|*
name|__s
parameter_list|)
function_decl|;
name|void
name|__throw_range_error
parameter_list|(
specifier|const
name|char
modifier|*
name|__s
parameter_list|)
function_decl|;
name|void
name|__throw_overflow_error
parameter_list|(
specifier|const
name|char
modifier|*
name|__s
parameter_list|)
function_decl|;
name|void
name|__throw_underflow_error
parameter_list|(
specifier|const
name|char
modifier|*
name|__s
parameter_list|)
function_decl|;
comment|// Helpers for exception objects in basic_ios
name|void
name|__throw_ios_failure
parameter_list|(
specifier|const
name|char
modifier|*
name|__s
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace std
end_comment

end_unit

