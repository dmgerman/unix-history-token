begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Functions for generic NeXT as target machine for GNU C compiler.    Copyright (C) 1989, 1990, 1991, 1992, 1993 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

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
comment|/* Called from check_newline via the macro HANDLE_PRAGMA.    FINPUT is the source file input stream.  */
end_comment

begin_function
name|void
name|handle_pragma
parameter_list|(
name|finput
parameter_list|,
name|get_line_function
parameter_list|)
name|FILE
modifier|*
name|finput
decl_stmt|;
function|char *
parameter_list|(
function|*get_line_function
end_function

begin_expr_stmt
unit|)
operator|(
operator|)
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|p
init|=
call|(
modifier|*
name|get_line_function
call|)
argument_list|(
name|finput
argument_list|)
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
name|OPT_STRCMP
argument_list|(
literal|"CC_OPT_ON"
argument_list|)
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
block|}
elseif|else
if|if
condition|(
name|OPT_STRCMP
argument_list|(
literal|"CC_OPT_OFF"
argument_list|)
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
block|}
elseif|else
if|if
condition|(
name|OPT_STRCMP
argument_list|(
literal|"CC_OPT_RESTORE"
argument_list|)
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
block|}
elseif|else
if|if
condition|(
name|OPT_STRCMP
argument_list|(
literal|"CC_WRITABLE_STRINGS"
argument_list|)
condition|)
name|flag_writable_strings
operator|=
literal|1
expr_stmt|;
elseif|else
if|if
condition|(
name|OPT_STRCMP
argument_list|(
literal|"CC_NON_WRITABLE_STRINGS"
argument_list|)
condition|)
name|flag_writable_strings
operator|=
literal|0
expr_stmt|;
elseif|else
if|if
condition|(
name|OPT_STRCMP
argument_list|(
literal|"CC_NO_MACH_TEXT_SECTIONS"
argument_list|)
condition|)
name|flag_no_mach_text_sections
operator|=
literal|1
expr_stmt|;
block|}
end_block

end_unit

