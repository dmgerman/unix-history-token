begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)err.c 4.1 %G%"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"sh.h"
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_comment
comment|/*  * C Shell  */
end_comment

begin_decl_stmt
name|bool
name|errspl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Argument to error was spliced by seterr2 */
end_comment

begin_decl_stmt
name|char
name|one
index|[
literal|2
index|]
init|=
block|{
literal|'1'
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|onev
index|[
literal|2
index|]
init|=
block|{
name|one
block|,
name|NOSTR
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Print error string s with optional argument arg.  * This routine always resets or exits.  The flag haderr  * is set so the routine who catches the unwind can propogate  * it if they want.  *  * Note that any open files at the point of error will eventually  * be closed in the routine process in sh.c which is the only  * place error unwinds are ever caught.  */
end_comment

begin_macro
name|error
argument_list|(
argument|s
argument_list|,
argument|arg
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
specifier|register
name|char
modifier|*
modifier|*
name|v
decl_stmt|;
specifier|register
name|char
modifier|*
name|ep
decl_stmt|;
comment|/* 	 * Must flush before we print as we wish output before the error 	 * to go on (some form of) standard output, while output after 	 * goes on (some form of) diagnostic output. 	 * If didfds then output will go to 1/2 else to FSHOUT/FSHDIAG. 	 * See flush in sh.print.c. 	 */
name|flush
argument_list|()
expr_stmt|;
name|haderr
operator|=
literal|1
expr_stmt|;
comment|/* Now to diagnostic output */
name|timflg
operator|=
literal|0
expr_stmt|;
comment|/* This isn't otherwise reset */
if|if
condition|(
name|v
operator|=
name|pargv
condition|)
name|pargv
operator|=
literal|0
operator|,
name|blkfree
argument_list|(
name|v
argument_list|)
expr_stmt|;
if|if
condition|(
name|v
operator|=
name|gargv
condition|)
name|gargv
operator|=
literal|0
operator|,
name|blkfree
argument_list|(
name|v
argument_list|)
expr_stmt|;
comment|/* 	 * A zero arguments causes no printing, else print 	 * an error diagnostic here. 	 */
if|if
condition|(
name|s
condition|)
name|printf
argument_list|(
name|s
argument_list|,
name|arg
argument_list|)
operator|,
name|printf
argument_list|(
literal|".\n"
argument_list|)
expr_stmt|;
name|didfds
operator|=
literal|0
expr_stmt|;
comment|/* Forget about 0,1,2 */
if|if
condition|(
operator|(
name|ep
operator|=
name|err
operator|)
operator|&&
name|errspl
condition|)
block|{
name|errspl
operator|=
literal|0
expr_stmt|;
name|xfree
argument_list|(
name|ep
argument_list|)
expr_stmt|;
block|}
name|errspl
operator|=
literal|0
expr_stmt|;
comment|/* 	 * Reset the state of the input. 	 * This buffered seek to end of file will also 	 * clear the while/foreach stack. 	 */
name|btoeof
argument_list|()
expr_stmt|;
comment|/* 	 * Go away if -e or we are a child shell 	 */
if|if
condition|(
name|exiterr
operator|||
name|child
condition|)
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|setq
argument_list|(
literal|"status"
argument_list|,
name|onev
argument_list|,
operator|&
name|shvhed
argument_list|)
expr_stmt|;
if|if
condition|(
name|tpgrp
operator|>
literal|0
condition|)
name|ioctl
argument_list|(
name|FSHTTY
argument_list|,
name|TIOCSPGRP
argument_list|,
operator|&
name|tpgrp
argument_list|)
expr_stmt|;
name|reset
argument_list|()
expr_stmt|;
comment|/* Unwind */
block|}
end_block

begin_comment
comment|/*  * Perror is the shells version of perror which should otherwise  * never be called.  */
end_comment

begin_macro
name|Perror
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
comment|/* 	 * Perror uses unit 2, thus if we didn't set up the fd's 	 * we must set up unit 2 now else the diagnostic will disappear 	 */
if|if
condition|(
operator|!
name|didfds
condition|)
block|{
specifier|register
name|int
name|oerrno
init|=
name|errno
decl_stmt|;
name|dcopy
argument_list|(
name|SHDIAG
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|errno
operator|=
name|oerrno
expr_stmt|;
block|}
name|perror
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|error
argument_list|(
name|NOSTR
argument_list|)
expr_stmt|;
comment|/* To exit or unwind */
block|}
end_block

begin_macro
name|bferr
argument_list|(
argument|cp
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|cp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|flush
argument_list|()
expr_stmt|;
name|haderr
operator|=
literal|1
expr_stmt|;
name|printf
argument_list|(
literal|"%s: "
argument_list|,
name|bname
argument_list|)
expr_stmt|;
name|error
argument_list|(
name|cp
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * The parser and scanner set up errors for later by calling seterr,  * which sets the variable err as a side effect; later to be tested,  * e.g. in process.  */
end_comment

begin_macro
name|seterr
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
if|if
condition|(
name|err
operator|==
literal|0
condition|)
name|err
operator|=
name|s
operator|,
name|errspl
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_comment
comment|/* Set err to a splice of cp and dp, to be freed later in error() */
end_comment

begin_macro
name|seterr2
argument_list|(
argument|cp
argument_list|,
argument|dp
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|cp
decl_stmt|,
modifier|*
name|dp
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|err
condition|)
return|return;
name|err
operator|=
name|strspl
argument_list|(
name|cp
argument_list|,
name|dp
argument_list|)
expr_stmt|;
name|errspl
operator|++
expr_stmt|;
block|}
end_block

begin_comment
comment|/* Set err to a splice of cp with a string form of character d */
end_comment

begin_macro
name|seterrc
argument_list|(
argument|cp
argument_list|,
argument|d
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|cp
decl_stmt|,
name|d
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|chbuf
index|[
literal|2
index|]
decl_stmt|;
name|chbuf
index|[
literal|0
index|]
operator|=
name|d
expr_stmt|;
name|chbuf
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
name|seterr2
argument_list|(
name|cp
argument_list|,
name|chbuf
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

