begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_include
include|#
directive|include
file|<ingres.h>
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)set_so_buf.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  SET_SO_BUF -- set standard output buffer conditionally ** **	This routine sets the standard output buffer conditionally, **	based on whether or not it is a terminal.  If it is, it **	does not set the output; otherwise, it buffers the output. **	The buffer is contained internally. ** **	Parameters: **		none ** **	Returns: **		TRUE -- if buffer was set **		FALSE -- otherwise ** **	Side Effects: **		The standard output is left buffered or unchanged. */
end_comment

begin_macro
name|set_so_buf
argument_list|()
end_macro

begin_block
block|{
specifier|extern
name|int
name|errno
decl_stmt|;
name|struct
name|sgttyb
name|gttybuf
decl_stmt|;
specifier|static
name|char
name|buffer
index|[
name|BUFSIZ
index|]
decl_stmt|;
comment|/* check for standard output is tty */
if|if
condition|(
name|gtty
argument_list|(
name|fileno
argument_list|(
name|stdout
argument_list|)
argument_list|,
operator|&
name|gttybuf
argument_list|)
condition|)
block|{
comment|/* no: reset errno and buffer */
name|errno
operator|=
literal|0
expr_stmt|;
name|setbuf
argument_list|(
name|stdout
argument_list|,
name|buffer
argument_list|)
expr_stmt|;
return|return
operator|(
name|TRUE
operator|)
return|;
block|}
return|return
operator|(
name|FALSE
operator|)
return|;
block|}
end_block

end_unit

