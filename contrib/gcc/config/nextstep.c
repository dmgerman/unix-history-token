begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Functions for generic NeXT as target machine for GNU C compiler.    Copyright (C) 1989, 90-93, 96, 1997 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"flags.h"
end_include

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_comment
comment|/* Make everything that used to go in the text section really go there.  */
end_comment

begin_decl_stmt
name|int
name|flag_no_mach_text_sections
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|OPT_STRCMP
parameter_list|(
name|opt
parameter_list|)
value|(!strncmp (opt, p, sizeof (opt)-1))
end_define

begin_comment
comment|/* 1 if handle_pragma has been called yet.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|pragma_initialized
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initial setting of `optimize'.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|initial_optimize_flag
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|get_directive_line
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Called from check_newline via the macro HANDLE_PRAGMA.    FINPUT is the source file input stream.    CH is the first character after `#pragma'.    The result is 1 if the pragma was handled.  */
end_comment

begin_function_decl
name|int
name|handle_pragma
parameter_list|(
name|p_getc
parameter_list|,
name|p_ungetc
parameter_list|,
name|pname
parameter_list|)
function_decl|int
parameter_list|(
function_decl|*  p_getc
end_function_decl

begin_expr_stmt
unit|)
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|void
argument_list|(
argument|* p_ungetc
argument_list|)
end_macro

begin_expr_stmt
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|char
modifier|*
name|pname
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|retval
init|=
literal|0
decl_stmt|;
comment|/* Record initial setting of optimize flag, so we can restore it.  */
if|if
condition|(
operator|!
name|pragma_initialized
condition|)
block|{
name|pragma_initialized
operator|=
literal|1
expr_stmt|;
name|initial_optimize_flag
operator|=
name|optimize
expr_stmt|;
block|}
if|if
condition|(
name|strcmp
argument_list|(
name|pname
argument_list|,
literal|"CC_OPT_ON"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|optimize
operator|=
literal|1
operator|,
name|obey_regdecls
operator|=
literal|0
expr_stmt|;
name|warning
argument_list|(
literal|"optimization turned on"
argument_list|)
expr_stmt|;
name|retval
operator|=
literal|1
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|pname
argument_list|,
literal|"CC_OPT_OFF"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|optimize
operator|=
literal|0
operator|,
name|obey_regdecls
operator|=
literal|1
expr_stmt|;
name|warning
argument_list|(
literal|"optimization turned off"
argument_list|)
expr_stmt|;
name|retval
operator|=
literal|1
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|pname
argument_list|,
literal|"CC_OPT_RESTORE"
argument_list|)
operator|==
literal|0
condition|)
block|{
specifier|extern
name|int
name|initial_optimize_flag
decl_stmt|;
if|if
condition|(
name|optimize
operator|!=
name|initial_optimize_flag
condition|)
block|{
if|if
condition|(
name|initial_optimize_flag
condition|)
name|obey_regdecls
operator|=
literal|0
expr_stmt|;
else|else
name|obey_regdecls
operator|=
literal|1
expr_stmt|;
name|optimize
operator|=
name|initial_optimize_flag
expr_stmt|;
block|}
name|warning
argument_list|(
literal|"optimization level restored"
argument_list|)
expr_stmt|;
name|retval
operator|=
literal|1
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|pname
argument_list|,
literal|"CC_WRITABLE_STRINGS"
argument_list|)
operator|==
literal|0
condition|)
name|flag_writable_strings
operator|=
name|retval
operator|=
literal|1
expr_stmt|;
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|pname
argument_list|,
literal|"CC_NON_WRITABLE_STRINGS"
argument_list|)
operator|==
literal|0
condition|)
name|flag_writable_strings
operator|=
literal|0
operator|,
name|retval
operator|=
literal|1
expr_stmt|;
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|pname
argument_list|,
literal|"CC_NO_MACH_TEXT_SECTIONS"
argument_list|)
operator|==
literal|0
condition|)
name|flag_no_mach_text_sections
operator|=
name|retval
operator|=
literal|1
expr_stmt|;
return|return
name|retval
return|;
block|}
end_block

end_unit

