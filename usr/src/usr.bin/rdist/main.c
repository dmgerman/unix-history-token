begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)main.c	4.1 (Berkeley) 83/09/07"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_comment
comment|/*  * Remote distribution program.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|distfile
init|=
literal|"distfile"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|tmpfile
init|=
literal|"/tmp/rdistXXXXXX"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debugging flag */
end_comment

begin_decl_stmt
name|int
name|nflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NOP flag, just print commands without executing */
end_comment

begin_decl_stmt
name|int
name|qflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Quiet. Don't print messages */
end_comment

begin_decl_stmt
name|int
name|vflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* verify only */
end_comment

begin_decl_stmt
name|int
name|yflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* update iff remote younger than master */
end_comment

begin_decl_stmt
name|int
name|iamremote
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* act as remote server for transfering files */
end_comment

begin_decl_stmt
name|int
name|filec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of files to update */
end_comment

begin_decl_stmt
name|char
modifier|*
modifier|*
name|filev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of files/directories to update */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|fin
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input file pointer */
end_comment

begin_decl_stmt
name|int
name|rem
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file descriptor to remote source/sink process */
end_comment

begin_decl_stmt
name|char
name|host
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* host name */
end_comment

begin_decl_stmt
name|int
name|errs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of errors while sending/receiving */
end_comment

begin_decl_stmt
name|char
name|user
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user's name */
end_comment

begin_decl_stmt
name|char
name|homedir
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user's home directory */
end_comment

begin_decl_stmt
name|int
name|userid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user's user ID */
end_comment

begin_decl_stmt
name|int
name|usergid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user's group ID */
end_comment

begin_function_decl
name|int
name|cleanup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lostconn
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|arg
decl_stmt|;
specifier|register
name|struct
name|passwd
modifier|*
name|pw
decl_stmt|;
name|setpwent
argument_list|()
expr_stmt|;
name|pw
operator|=
name|getpwuid
argument_list|(
name|userid
operator|=
name|getuid
argument_list|()
argument_list|)
expr_stmt|;
name|endpwent
argument_list|()
expr_stmt|;
if|if
condition|(
name|pw
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"rdist: Who are you?\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|strcpy
argument_list|(
name|user
argument_list|,
name|pw
operator|->
name|pw_name
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|homedir
argument_list|,
name|pw
operator|->
name|pw_dir
argument_list|)
expr_stmt|;
name|usergid
operator|=
name|pw
operator|->
name|pw_gid
expr_stmt|;
name|gethostname
argument_list|(
name|host
argument_list|,
sizeof|sizeof
argument_list|(
name|host
argument_list|)
argument_list|)
expr_stmt|;
while|while
condition|(
operator|--
name|argc
operator|>
literal|0
condition|)
block|{
if|if
condition|(
operator|(
name|arg
operator|=
operator|*
operator|++
name|argv
operator|)
index|[
literal|0
index|]
operator|!=
literal|'-'
condition|)
break|break;
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|arg
argument_list|,
literal|"-Server"
argument_list|)
condition|)
name|iamremote
operator|++
expr_stmt|;
else|else
while|while
condition|(
operator|*
operator|++
name|arg
condition|)
switch|switch
condition|(
operator|*
name|arg
condition|)
block|{
case|case
literal|'f'
case|:
if|if
condition|(
operator|--
name|argc
operator|<=
literal|0
condition|)
name|usage
argument_list|()
expr_stmt|;
name|distfile
operator|=
operator|*
operator|++
name|argv
expr_stmt|;
if|if
condition|(
name|distfile
index|[
literal|0
index|]
operator|==
literal|'-'
operator|&&
name|distfile
index|[
literal|1
index|]
operator|==
literal|'\0'
condition|)
name|fin
operator|=
name|stdin
expr_stmt|;
break|break;
case|case
literal|'d'
case|:
name|debug
operator|++
expr_stmt|;
break|break;
case|case
literal|'n'
case|:
name|nflag
operator|++
expr_stmt|;
break|break;
case|case
literal|'q'
case|:
name|qflag
operator|++
expr_stmt|;
break|break;
case|case
literal|'v'
case|:
name|vflag
operator|++
expr_stmt|;
break|break;
case|case
literal|'y'
case|:
name|yflag
operator|++
expr_stmt|;
break|break;
default|default:
name|usage
argument_list|()
expr_stmt|;
block|}
block|}
name|signal
argument_list|(
name|SIGPIPE
argument_list|,
name|lostconn
argument_list|)
expr_stmt|;
if|if
condition|(
name|iamremote
condition|)
block|{
name|server
argument_list|()
expr_stmt|;
name|exit
argument_list|(
name|errs
argument_list|)
expr_stmt|;
block|}
name|filec
operator|=
name|argc
expr_stmt|;
name|filev
operator|=
name|argv
expr_stmt|;
if|if
condition|(
name|fin
operator|==
name|NULL
operator|&&
operator|(
name|fin
operator|=
name|fopen
argument_list|(
name|distfile
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|perror
argument_list|(
name|distfile
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|mktemp
argument_list|(
name|tmpfile
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGHUP
argument_list|,
name|cleanup
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|cleanup
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|cleanup
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGTERM
argument_list|,
name|cleanup
argument_list|)
expr_stmt|;
name|yyparse
argument_list|()
expr_stmt|;
name|exit
argument_list|(
name|errs
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|usage
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"Usage: rdist [-f distfile] [-n] [-q] [-y] [-d] [file ...]\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Remove temporary files and do any cleanup operations before exiting.  */
end_comment

begin_macro
name|cleanup
argument_list|()
end_macro

begin_block
block|{
operator|(
name|void
operator|)
name|unlink
argument_list|(
name|tmpfile
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Print a list of NAME blocks (mostly for debugging).  */
end_comment

begin_expr_stmt
name|prnames
argument_list|(
name|bp
argument_list|)
specifier|register
expr|struct
name|block
operator|*
name|bp
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"( "
argument_list|)
expr_stmt|;
while|while
condition|(
name|bp
operator|!=
name|NULL
condition|)
block|{
name|printf
argument_list|(
literal|"%s "
argument_list|,
name|bp
operator|->
name|b_name
argument_list|)
expr_stmt|;
name|bp
operator|=
name|bp
operator|->
name|b_next
expr_stmt|;
block|}
name|printf
argument_list|(
literal|")\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*VARARGS*/
end_comment

begin_macro
name|warn
argument_list|(
argument|fmt
argument_list|,
argument|a1
argument_list|,
argument|a2
argument_list|,
argument|a3
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|fmt
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|extern
name|int
name|yylineno
decl_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"rdist: line %d: Warning: "
argument_list|,
name|yylineno
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|fmt
argument_list|,
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|)
expr_stmt|;
name|fputc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

