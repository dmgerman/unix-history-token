begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"sendmail.h"
end_include

begin_decl_stmt
specifier|static
name|char
name|SccsId
index|[]
init|=
literal|"@(#)daemon.c	3.2	%G%"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **  DAEMON.C -- routines to use when running as a daemon. */
end_comment

begin_escape
end_escape

begin_comment
comment|/* **  GETREQUESTS -- open mail IPC port and get requests. ** **	Parameters: **		none. ** **	Returns: **		none. ** **	Side Effects: **		Waits until some interesting activity occurs.  When **		it does, a child is created to process it, and the **		parent waits for completion.  Return from this **		routine is always in the child. */
end_comment

begin_macro
name|getrequests
argument_list|()
end_macro

begin_block
block|{
name|syserr
argument_list|(
literal|"Daemon mode not yet implemented"
argument_list|)
expr_stmt|;
name|getrecipients
argument_list|()
expr_stmt|;
name|exit
argument_list|(
name|EX_USAGE
argument_list|)
expr_stmt|;
comment|/* initsys(); */
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **  GETRECIPIENTS -- do a sendto to all recipients. ** **	Parameters: **		none. ** **	Returns: **		none. ** **	Side Effects: **		The set of recipients for this request are **		collected and designated as recipients. */
end_comment

begin_macro
name|getrecipients
argument_list|()
end_macro

begin_block
block|{
return|return;
block|}
end_block

end_unit

