begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Exception Handling header for -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 1995 Free Software Foundation
end_comment

begin_comment
comment|// This file is part of the GNU ANSI C++ Library.  This library is free
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
comment|// You should have received a copy of the GNU General Public License
end_comment

begin_comment
comment|// along with this library; see the file COPYING.  If not, write to the Free
end_comment

begin_comment
comment|// Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
end_comment

begin_comment
comment|// As a special exception, if you link this library with files
end_comment

begin_comment
comment|// compiled with a GNU compiler to produce an executable, this does not cause
end_comment

begin_comment
comment|// the resulting executable to be covered by the GNU General Public License.
end_comment

begin_comment
comment|// This exception does not however invalidate any other reasons why
end_comment

begin_comment
comment|// the executable file might be covered by the GNU General Public License.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EXCEPTION__
end_ifndef

begin_define
define|#
directive|define
name|__EXCEPTION__
end_define

begin_extern
extern|extern
literal|"C++"
block|{
comment|// class XUNEXPECTED { to be specified };
typedef|typedef
name|void
function_decl|(
modifier|*
name|terminate_handler
function_decl|)
parameter_list|()
function_decl|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|unexpected_handler
function_decl|)
parameter_list|()
function_decl|;
name|terminate_handler
name|set_terminate
parameter_list|(
name|terminate_handler
parameter_list|)
function_decl|;
name|void
name|terminate
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|unexpected_handler
name|set_unexpected
parameter_list|(
name|unexpected_handler
parameter_list|)
function_decl|;
name|void
name|unexpected
parameter_list|(
name|void
parameter_list|)
function_decl|;
block|}
end_extern

begin_comment
comment|// extern "C++"
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

