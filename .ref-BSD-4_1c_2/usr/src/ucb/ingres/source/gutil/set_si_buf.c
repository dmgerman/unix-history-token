begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
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
argument|@(#)set_si_buf.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  SET_SI_BUF -- set standard input buffer unconditionally ** **	This routine sets the standard input buffer to give **	buffered input.  The buffer is contained internally. ** **	Parameters: **		none ** **	Returns: **		TRUE. ** **	Side Effects: **		The standard input is left buffered. ** **	Trace Flags: **		none */
end_comment

begin_macro
name|set_si_buf
argument_list|()
end_macro

begin_block
block|{
specifier|static
name|char
name|buffer
index|[
name|BUFSIZ
index|]
decl_stmt|;
name|setbuf
argument_list|(
name|stdin
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
end_block

end_unit

