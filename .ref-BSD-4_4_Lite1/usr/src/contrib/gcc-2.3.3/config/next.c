begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* next.c:  Functions for NeXT as target machine for GNU C compiler.  */
end_comment

begin_comment
comment|/* Note that the include below means that we can't debug routines in    m68k.c when running on a COFF system.  */
end_comment

begin_include
include|#
directive|include
file|"m68k.c"
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
comment|/* Called from check_newline via the macro HANDLE_PRAGMA.    FINPUT is the source file input stream.  */
end_comment

begin_function
name|void
name|handle_pragma
parameter_list|(
name|finput
parameter_list|)
name|FILE
modifier|*
name|finput
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|p
init|=
name|get_directive_line
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
name|optimize
operator|=
literal|1
operator|,
name|obey_regdecls
operator|=
literal|0
expr_stmt|;
elseif|else
if|if
condition|(
name|OPT_STRCMP
argument_list|(
literal|"CC_OPT_OFF"
argument_list|)
condition|)
name|optimize
operator|=
literal|0
operator|,
name|obey_regdecls
operator|=
literal|1
expr_stmt|;
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
end_function

end_unit

