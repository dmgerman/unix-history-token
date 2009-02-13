begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Stack protector support.    Copyright (C) 2005 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  In addition to the permissions in the GNU General Public License, the Free Software Foundation gives you unlimited permission to link the compiled version of this file into combinations with other programs, and to distribute those combinations without any restriction coming from the use of this file.  (The General Public License restrictions do apply in other respects; for example, they cover modification of the file, and distribution when not linked into a combine executable.)  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with files compiled with    GCC to produce an executable, this does not cause the resulting executable    to be covered by the GNU General Public License. This exception does not    however invalidate any other reasons why the executable file might be    covered by the GNU General Public License.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_function_decl
specifier|extern
name|void
name|__stack_chk_fail
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Some targets can avoid loading a GP for calls to hidden functions.    Using this entry point may avoid the load of a GP entirely for the    function, making the overall code smaller.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_HIDDEN_VISIBILITY
end_ifdef

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|visibility
argument_list|(
literal|"hidden"
argument_list|)
operator|)
argument_list|)
name|__stack_chk_fail_local
argument_list|(
name|void
argument_list|)
block|{
name|__stack_chk_fail
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

