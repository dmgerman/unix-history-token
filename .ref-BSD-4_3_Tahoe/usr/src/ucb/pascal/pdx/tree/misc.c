begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)misc.c	5.2 (Berkeley) 4/7/87"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * Miscellaneous commands "edit" and "help".  * Also, output redirection routine "setout" and "unsetout".  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_include
include|#
directive|include
file|"command.h"
end_include

begin_include
include|#
directive|include
file|"object.h"
end_include

begin_include
include|#
directive|include
file|"mappings.h"
end_include

begin_include
include|#
directive|include
file|"sym.h"
end_include

begin_include
include|#
directive|include
file|"symtab.h"
end_include

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DEF_EDITOR
value|"vi"
end_define

begin_comment
comment|/*  * Invoke an editor on the given file.  Which editor to use might change  * installation to installation.  For now, we use "vi".  In any event,  * the environment variable "EDITOR" overrides any default.  */
end_comment

begin_macro
name|edit
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
name|char
modifier|*
name|ed
decl_stmt|;
name|FILE
modifier|*
name|fp
decl_stmt|;
name|SYM
modifier|*
name|s
decl_stmt|;
name|ADDRESS
name|addr
decl_stmt|;
name|char
name|buff
index|[
literal|10
index|]
decl_stmt|;
if|if
condition|(
operator|(
name|ed
operator|=
name|getenv
argument_list|(
literal|"EDITOR"
argument_list|)
operator|)
operator|==
name|NIL
condition|)
block|{
name|ed
operator|=
name|DEF_EDITOR
expr_stmt|;
block|}
name|fp
operator|=
name|fopen
argument_list|(
name|filename
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
if|if
condition|(
name|fp
operator|==
name|NIL
condition|)
block|{
name|s
operator|=
name|st_lookup
argument_list|(
name|symtab
argument_list|,
name|filename
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|==
name|NIL
condition|)
block|{
name|error
argument_list|(
literal|"can't read \"%s\""
argument_list|,
name|filename
argument_list|)
expr_stmt|;
block|}
name|s
operator|=
name|which
argument_list|(
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|isblock
argument_list|(
name|s
argument_list|)
condition|)
block|{
name|error
argument_list|(
literal|"can't read \"%s\""
argument_list|,
name|filename
argument_list|)
expr_stmt|;
block|}
name|addr
operator|=
name|firstline
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|filename
operator|=
name|srcfilename
argument_list|(
name|addr
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|buff
argument_list|,
literal|"+%d"
argument_list|,
name|srcline
argument_list|(
name|addr
argument_list|)
argument_list|)
expr_stmt|;
name|call
argument_list|(
name|ed
argument_list|,
name|stdin
argument_list|,
name|stdout
argument_list|,
name|buff
argument_list|,
name|filename
argument_list|,
name|NIL
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|fclose
argument_list|(
name|fp
argument_list|)
expr_stmt|;
name|call
argument_list|(
name|ed
argument_list|,
name|stdin
argument_list|,
name|stdout
argument_list|,
name|filename
argument_list|,
name|NIL
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*  * Send some nasty mail to the current pdx support person.  */
end_comment

begin_macro
name|gripe
argument_list|()
end_macro

begin_block
block|{
name|char
modifier|*
name|maintainer
init|=
literal|"4bsd-bugs@Berkeley.EDU"
decl_stmt|;
name|puts
argument_list|(
literal|"Type control-D to end your message.  Be sure to include"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"your name and the name of the file you are debugging."
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
name|call
argument_list|(
literal|"Mail"
argument_list|,
name|stdin
argument_list|,
name|stdout
argument_list|,
name|maintainer
argument_list|,
name|NIL
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"Thank you."
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Give the user some help.  */
end_comment

begin_macro
name|help
argument_list|()
end_macro

begin_block
block|{
name|puts
argument_list|(
literal|"pdx command subset summary:"
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"run                    - begin execution of the program"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"cont                   - continue execution"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"step                   - single step one line"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"next                   - step to next line (skip over calls)"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"trace<line#>          - trace execution of the line"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"trace<proc>           - trace calls to the procedure"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"trace<var>            - trace changes to the variable"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"trace<exp> at<line#> - print<exp> when<line> is reached"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"stop at<line>         - suspend execution at the line"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"stop in<proc>         - suspend execution when<proc> is called"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"status                 - print trace/stop's in effect"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"delete<number>        - remove trace or stop of given number"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"call<proc>            - call the procedure"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"where                  - print currently active procedures"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"print<exp>            - print the value of the expression"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"whatis<name>          - print the declaration of the name"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"list<line>,<line>    - list source lines"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"edit<proc>            - edit file containing<proc>"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"gripe                  - send mail to the person in charge of pdx"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"quit                   - exit pdx"
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Divert output to the given file name.  * Cannot redirect to an existing file.  */
end_comment

begin_decl_stmt
name|LOCAL
name|int
name|so_fd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LOCAL
name|BOOLEAN
name|notstdout
decl_stmt|;
end_decl_stmt

begin_macro
name|setout
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
name|FILE
modifier|*
name|fp
decl_stmt|;
if|if
condition|(
operator|(
name|fp
operator|=
name|fopen
argument_list|(
name|filename
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|!=
name|NIL
condition|)
block|{
name|fclose
argument_list|(
name|fp
argument_list|)
expr_stmt|;
name|error
argument_list|(
literal|"%s: file already exists"
argument_list|,
name|filename
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|so_fd
operator|=
name|dup
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|close
argument_list|(
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|creat
argument_list|(
name|filename
argument_list|,
literal|0666
argument_list|)
operator|==
name|NIL
condition|)
block|{
name|unsetout
argument_list|()
expr_stmt|;
name|error
argument_list|(
literal|"can't create %s"
argument_list|,
name|filename
argument_list|)
expr_stmt|;
block|}
name|notstdout
operator|=
name|TRUE
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*  * Revert output to standard output.  */
end_comment

begin_macro
name|unsetout
argument_list|()
end_macro

begin_block
block|{
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
name|close
argument_list|(
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|dup
argument_list|(
name|so_fd
argument_list|)
operator|!=
literal|1
condition|)
block|{
name|panic
argument_list|(
literal|"standard out dup failed"
argument_list|)
expr_stmt|;
block|}
name|close
argument_list|(
name|so_fd
argument_list|)
expr_stmt|;
name|notstdout
operator|=
name|FALSE
expr_stmt|;
block|}
end_block

begin_function
name|BOOLEAN
name|isredirected
parameter_list|()
block|{
return|return
operator|(
name|notstdout
operator|)
return|;
block|}
end_function

end_unit

