begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Robert Paul Corbett.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)error.c	5.3 (Berkeley) 6/1/90"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/* routines for printing error messages  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_macro
name|fatal
argument_list|(
argument|msg
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|msg
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: f - %s\n"
argument_list|,
name|myname
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|done
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|no_space
argument_list|()
end_macro

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: f - out of space\n"
argument_list|,
name|myname
argument_list|)
expr_stmt|;
name|done
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|open_error
argument_list|(
argument|filename
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|filename
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: f - cannot open \"%s\"\n"
argument_list|,
name|myname
argument_list|,
name|filename
argument_list|)
expr_stmt|;
name|done
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|unexpected_EOF
argument_list|()
end_macro

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: e - line %d of \"%s\", unexpected end-of-file\n"
argument_list|,
name|myname
argument_list|,
name|lineno
argument_list|,
name|input_file_name
argument_list|)
expr_stmt|;
name|done
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|print_pos
argument_list|(
argument|st_line
argument_list|,
argument|st_cptr
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|st_line
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|st_cptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|s
decl_stmt|;
if|if
condition|(
name|st_line
operator|==
literal|0
condition|)
return|return;
for|for
control|(
name|s
operator|=
name|st_line
init|;
operator|*
name|s
operator|!=
literal|'\n'
condition|;
operator|++
name|s
control|)
block|{
if|if
condition|(
name|isprint
argument_list|(
operator|*
name|s
argument_list|)
operator|||
operator|*
name|s
operator|==
literal|'\t'
condition|)
name|putc
argument_list|(
operator|*
name|s
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
else|else
name|putc
argument_list|(
literal|'?'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
block|}
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
for|for
control|(
name|s
operator|=
name|st_line
init|;
name|s
operator|<
name|st_cptr
condition|;
operator|++
name|s
control|)
block|{
if|if
condition|(
operator|*
name|s
operator|==
literal|'\t'
condition|)
name|putc
argument_list|(
literal|'\t'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
else|else
name|putc
argument_list|(
literal|' '
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
block|}
name|putc
argument_list|(
literal|'^'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|syntax_error
argument_list|(
argument|st_lineno
argument_list|,
argument|st_line
argument_list|,
argument|st_cptr
argument_list|)
end_macro

begin_decl_stmt
name|int
name|st_lineno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|st_line
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|st_cptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: e - line %d of \"%s\", syntax error\n"
argument_list|,
name|myname
argument_list|,
name|st_lineno
argument_list|,
name|input_file_name
argument_list|)
expr_stmt|;
name|print_pos
argument_list|(
name|st_line
argument_list|,
name|st_cptr
argument_list|)
expr_stmt|;
name|done
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|unterminated_comment
argument_list|(
argument|c_lineno
argument_list|,
argument|c_line
argument_list|,
argument|c_cptr
argument_list|)
end_macro

begin_decl_stmt
name|int
name|c_lineno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|c_line
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|c_cptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: e - line %d of \"%s\", unmatched /*\n"
argument_list|,
name|myname
argument_list|,
name|c_lineno
argument_list|,
name|input_file_name
argument_list|)
expr_stmt|;
name|print_pos
argument_list|(
name|c_line
argument_list|,
name|c_cptr
argument_list|)
expr_stmt|;
name|done
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|unterminated_string
argument_list|(
argument|s_lineno
argument_list|,
argument|s_line
argument_list|,
argument|s_cptr
argument_list|)
end_macro

begin_decl_stmt
name|int
name|s_lineno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|s_line
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|s_cptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: e - line %d of \"%s\", unterminated string\n"
argument_list|,
name|myname
argument_list|,
name|s_lineno
argument_list|,
name|input_file_name
argument_list|)
expr_stmt|;
name|print_pos
argument_list|(
name|s_line
argument_list|,
name|s_cptr
argument_list|)
expr_stmt|;
name|done
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|unterminated_text
argument_list|(
argument|t_lineno
argument_list|,
argument|t_line
argument_list|,
argument|t_cptr
argument_list|)
end_macro

begin_decl_stmt
name|int
name|t_lineno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|t_line
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|t_cptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: e - line %d of \"%s\", unmatched %%{\n"
argument_list|,
name|myname
argument_list|,
name|t_lineno
argument_list|,
name|input_file_name
argument_list|)
expr_stmt|;
name|print_pos
argument_list|(
name|t_line
argument_list|,
name|t_cptr
argument_list|)
expr_stmt|;
name|done
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|unterminated_union
argument_list|(
argument|u_lineno
argument_list|,
argument|u_line
argument_list|,
argument|u_cptr
argument_list|)
end_macro

begin_decl_stmt
name|int
name|u_lineno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|u_line
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|u_cptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: e - line %d of \"%s\", unterminated %%union \ declaration\n"
argument_list|,
name|myname
argument_list|,
name|u_lineno
argument_list|,
name|input_file_name
argument_list|)
expr_stmt|;
name|print_pos
argument_list|(
name|u_line
argument_list|,
name|u_cptr
argument_list|)
expr_stmt|;
name|done
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|over_unionized
argument_list|(
argument|u_cptr
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|u_cptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: e - line %d of \"%s\", too many %%union \ declarations\n"
argument_list|,
name|myname
argument_list|,
name|lineno
argument_list|,
name|input_file_name
argument_list|)
expr_stmt|;
name|print_pos
argument_list|(
name|line
argument_list|,
name|u_cptr
argument_list|)
expr_stmt|;
name|done
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|illegal_tag
argument_list|(
argument|t_lineno
argument_list|,
argument|t_line
argument_list|,
argument|t_cptr
argument_list|)
end_macro

begin_decl_stmt
name|int
name|t_lineno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|t_line
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|t_cptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: e - line %d of \"%s\", illegal tag\n"
argument_list|,
name|myname
argument_list|,
name|t_lineno
argument_list|,
name|input_file_name
argument_list|)
expr_stmt|;
name|print_pos
argument_list|(
name|t_line
argument_list|,
name|t_cptr
argument_list|)
expr_stmt|;
name|done
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|illegal_character
argument_list|(
argument|c_cptr
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|c_cptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: e - line %d of \"%s\", illegal character\n"
argument_list|,
name|myname
argument_list|,
name|lineno
argument_list|,
name|input_file_name
argument_list|)
expr_stmt|;
name|print_pos
argument_list|(
name|line
argument_list|,
name|c_cptr
argument_list|)
expr_stmt|;
name|done
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|used_reserved
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: e - line %d of \"%s\", illegal use of reserved symbol \ %s\n"
argument_list|,
name|myname
argument_list|,
name|lineno
argument_list|,
name|input_file_name
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|done
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|tokenized_start
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: e - line %d of \"%s\", the start symbol %s cannot be \ declared to be a token\n"
argument_list|,
name|myname
argument_list|,
name|lineno
argument_list|,
name|input_file_name
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|done
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|retyped_warning
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: w - line %d of \"%s\", the type of %s has been \ redeclared\n"
argument_list|,
name|myname
argument_list|,
name|lineno
argument_list|,
name|input_file_name
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|reprec_warning
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: w - line %d of \"%s\", the precedence of %s has been \ redeclared\n"
argument_list|,
name|myname
argument_list|,
name|lineno
argument_list|,
name|input_file_name
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|revalued_warning
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: w - line %d of \"%s\", the value of %s has been \ redeclared\n"
argument_list|,
name|myname
argument_list|,
name|lineno
argument_list|,
name|input_file_name
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|terminal_start
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: e - line %d of \"%s\", the start symbol %s is a \ token\n"
argument_list|,
name|myname
argument_list|,
name|lineno
argument_list|,
name|input_file_name
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|done
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|restarted_warning
argument_list|()
end_macro

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: w - line %d of \"%s\", the start symbol has been \ redeclared\n"
argument_list|,
name|myname
argument_list|,
name|lineno
argument_list|,
name|input_file_name
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|no_grammar
argument_list|()
end_macro

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: e - line %d of \"%s\", no grammar has been \ specified\n"
argument_list|,
name|myname
argument_list|,
name|lineno
argument_list|,
name|input_file_name
argument_list|)
expr_stmt|;
name|done
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|terminal_lhs
argument_list|(
argument|s_lineno
argument_list|)
end_macro

begin_decl_stmt
name|int
name|s_lineno
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: e - line %d of \"%s\", a token appears on the lhs \ of a production\n"
argument_list|,
name|myname
argument_list|,
name|s_lineno
argument_list|,
name|input_file_name
argument_list|)
expr_stmt|;
name|done
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|prec_redeclared
argument_list|()
end_macro

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: w - line %d of  \"%s\", conflicting %%prec \ specifiers\n"
argument_list|,
name|myname
argument_list|,
name|lineno
argument_list|,
name|input_file_name
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|unterminated_action
argument_list|(
argument|a_lineno
argument_list|,
argument|a_line
argument_list|,
argument|a_cptr
argument_list|)
end_macro

begin_decl_stmt
name|int
name|a_lineno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|a_line
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|a_cptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: e - line %d of \"%s\", unterminated action\n"
argument_list|,
name|myname
argument_list|,
name|a_lineno
argument_list|,
name|input_file_name
argument_list|)
expr_stmt|;
name|print_pos
argument_list|(
name|a_line
argument_list|,
name|a_cptr
argument_list|)
expr_stmt|;
name|done
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|dollar_warning
argument_list|(
argument|a_lineno
argument_list|,
argument|i
argument_list|)
end_macro

begin_decl_stmt
name|int
name|a_lineno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|i
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: w - line %d of \"%s\", $%d references beyond the \ end of the current rule\n"
argument_list|,
name|myname
argument_list|,
name|a_lineno
argument_list|,
name|input_file_name
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|dollar_error
argument_list|(
argument|a_lineno
argument_list|,
argument|a_line
argument_list|,
argument|a_cptr
argument_list|)
end_macro

begin_decl_stmt
name|int
name|a_lineno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|a_line
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|a_cptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: e - line %d of \"%s\", illegal $-name\n"
argument_list|,
name|myname
argument_list|,
name|a_lineno
argument_list|,
name|input_file_name
argument_list|)
expr_stmt|;
name|print_pos
argument_list|(
name|a_line
argument_list|,
name|a_cptr
argument_list|)
expr_stmt|;
name|done
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|untyped_lhs
argument_list|()
end_macro

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: e - line %d of \"%s\", $$ is untyped\n"
argument_list|,
name|myname
argument_list|,
name|lineno
argument_list|,
name|input_file_name
argument_list|)
expr_stmt|;
name|done
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|untyped_rhs
argument_list|(
argument|i
argument_list|,
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|int
name|i
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: e - line %d of \"%s\", $%d (%s) is untyped\n"
argument_list|,
name|myname
argument_list|,
name|lineno
argument_list|,
name|input_file_name
argument_list|,
name|i
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|done
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|unknown_rhs
argument_list|(
argument|i
argument_list|)
end_macro

begin_decl_stmt
name|int
name|i
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: e - line %d of \"%s\", $%d is untyped\n"
argument_list|,
name|myname
argument_list|,
name|lineno
argument_list|,
name|input_file_name
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|done
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|default_action_warning
argument_list|()
end_macro

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: w - line %d of \"%s\", the default action assigns an \ undefined value to $$\n"
argument_list|,
name|myname
argument_list|,
name|lineno
argument_list|,
name|input_file_name
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|undefined_goal
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: e - the start symbol %s is undefined\n"
argument_list|,
name|myname
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|done
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|undefined_symbol_warning
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: w - the symbol %s is undefined\n"
argument_list|,
name|myname
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

