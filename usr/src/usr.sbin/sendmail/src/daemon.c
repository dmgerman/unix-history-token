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

begin_ifndef
ifndef|#
directive|ifndef
name|DAEMON
end_ifndef

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
literal|3.6
operator|%
name|G
operator|%
operator|(
name|w
operator|/
name|o
name|daemon
name|mode
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<wellknown.h>
end_include

begin_include
include|#
directive|include
file|<net/in.h>
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
literal|3.6
operator|%
name|G
operator|%
operator|(
name|with
name|daemon
name|mode
operator|)
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

begin_escape
end_escape

begin_comment
comment|/* **  GETCONNECTION -- make a connection with the outside world ** **	Parameters: **		none. ** **	Returns: **		The port for mail traffic. ** **	Side Effects: **		Waits for a connection. */
end_comment

begin_decl_stmt
name|struct
name|sockaddr_in
name|SendmailAddress
init|=
block|{
name|AF_INET
block|,
name|IPPORT_SENDMAIL
block|}
decl_stmt|;
end_decl_stmt

begin_macro
name|getconnection
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|int
name|s
decl_stmt|;
name|char
modifier|*
name|host
init|=
literal|"localhost"
decl_stmt|;
name|struct
name|sockaddr
name|otherend
decl_stmt|;
comment|/* 	**  Set up the address for the mailer. 	*/
name|SendmailAddress
operator|.
name|sin_addr
operator|.
name|s_addr
operator|=
name|rhost
argument_list|(
operator|&
name|host
argument_list|)
expr_stmt|;
comment|/* 	**  Try to actually open the connection. 	*/
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|Debug
condition|)
name|printf
argument_list|(
literal|"getconnection (%s)\n"
argument_list|,
name|host
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|DEBUG
name|s
operator|=
name|socket
argument_list|(
name|SOCK_STREAM
argument_list|,
literal|0
argument_list|,
operator|&
name|SendmailAddress
argument_list|,
name|SO_ACCEPTCONN
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|Debug
condition|)
name|printf
argument_list|(
literal|"getconnection: %d\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|DEBUG
name|accept
argument_list|(
name|s
argument_list|,
operator|&
name|otherend
argument_list|)
expr_stmt|;
return|return
operator|(
name|s
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
endif|DAEMON
end_endif

end_unit

