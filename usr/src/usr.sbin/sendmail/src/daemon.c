begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"sendmail.h"
end_include

begin_include
include|#
directive|include
file|<sys/mx.h>
end_include

begin_expr_stmt
name|SCCSID
argument_list|(
argument|@
operator|(
operator|#
operator|)
name|daemon
operator|.
name|c
literal|3.5
operator|%
name|G
operator|%
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* **  DAEMON.C -- routines to use when running as a daemon. */
end_comment

begin_decl_stmt
specifier|static
name|FILE
modifier|*
name|MailPort
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* port that mail comes in on */
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
name|char
modifier|*
name|portname
init|=
literal|"/dev/mailbox"
decl_stmt|;
name|struct
name|wh
name|wbuf
decl_stmt|;
name|wbuf
operator|.
name|index
operator|=
name|index
expr_stmt|;
name|wbuf
operator|.
name|count
operator|=
literal|0
expr_stmt|;
name|wbuf
operator|.
name|ccount
operator|=
name|cnt
expr_stmt|;
name|wbuf
operator|.
name|data
operator|=
name|buf
expr_stmt|;
name|write
argument_list|(
name|MailPort
argument_list|,
operator|&
name|wbuf
argument_list|,
sizeof|sizeof
name|wbuf
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

