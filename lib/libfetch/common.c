begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Dag-Erling Coïdan Smørgrav  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$Id$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"fetch.h"
end_include

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_comment
comment|/*** Local data **************************************************************/
end_comment

begin_comment
comment|/*  * Error messages for resolver errors  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|fetcherr
name|_netdb_errlist
index|[]
init|=
block|{
block|{
name|HOST_NOT_FOUND
block|,
literal|"Host not found"
block|}
block|,
block|{
name|TRY_AGAIN
block|,
literal|"Transient resolver failure"
block|}
block|,
block|{
name|NO_RECOVERY
block|,
literal|"Non-recoverable resolver failure"
block|}
block|,
block|{
name|NO_DATA
block|,
literal|"No address record"
block|}
block|,
block|{
operator|-
literal|1
block|,
literal|"Unknown resolver error"
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|_netdb_errstring
parameter_list|(
name|n
parameter_list|)
value|_fetch_errstring(_netdb_errlist, n)
end_define

begin_define
define|#
directive|define
name|_netdb_seterr
parameter_list|(
name|n
parameter_list|)
value|_fetch_seterr(_netdb_errlist, n)
end_define

begin_comment
comment|/*** Error-reporting functions ***********************************************/
end_comment

begin_comment
comment|/*  * Map error code to string  */
end_comment

begin_function
specifier|const
name|char
modifier|*
name|_fetch_errstring
parameter_list|(
name|struct
name|fetcherr
modifier|*
name|p
parameter_list|,
name|int
name|e
parameter_list|)
block|{
while|while
condition|(
operator|(
name|p
operator|->
name|num
operator|!=
operator|-
literal|1
operator|)
operator|&&
operator|(
name|p
operator|->
name|num
operator|!=
name|e
operator|)
condition|)
name|p
operator|++
expr_stmt|;
return|return
name|p
operator|->
name|string
return|;
block|}
end_function

begin_comment
comment|/*  * Set error code  */
end_comment

begin_function
name|void
name|_fetch_seterr
parameter_list|(
name|struct
name|fetcherr
modifier|*
name|p
parameter_list|,
name|int
name|e
parameter_list|)
block|{
name|fetchLastErrCode
operator|=
name|e
expr_stmt|;
name|fetchLastErrText
operator|=
name|_fetch_errstring
argument_list|(
name|p
argument_list|,
name|e
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Set error code according to errno  */
end_comment

begin_function
name|void
name|_fetch_syserr
parameter_list|(
name|void
parameter_list|)
block|{
name|fetchLastErrCode
operator|=
name|errno
expr_stmt|;
name|fetchLastErrText
operator|=
name|strerror
argument_list|(
name|errno
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*** Network-related utility functions ***************************************/
end_comment

begin_comment
comment|/*  * Establish a TCP connection to the specified port on the specified host.  */
end_comment

begin_function
name|int
name|fetchConnect
parameter_list|(
name|char
modifier|*
name|host
parameter_list|,
name|int
name|port
parameter_list|)
block|{
name|struct
name|sockaddr_in
name|sin
decl_stmt|;
name|struct
name|hostent
modifier|*
name|he
decl_stmt|;
name|int
name|sd
decl_stmt|;
ifndef|#
directive|ifndef
name|NDEBUG
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\033[1m---> %s:%d\033[m\n"
argument_list|,
name|host
argument_list|,
name|port
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* look up host name */
if|if
condition|(
operator|(
name|he
operator|=
name|gethostbyname
argument_list|(
name|host
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|_netdb_seterr
argument_list|(
name|h_errno
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
comment|/* set up socket address structure */
name|bzero
argument_list|(
operator|&
name|sin
argument_list|,
sizeof|sizeof
argument_list|(
name|sin
argument_list|)
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
name|he
operator|->
name|h_addr
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|sin
operator|.
name|sin_addr
argument_list|,
name|he
operator|->
name|h_length
argument_list|)
expr_stmt|;
name|sin
operator|.
name|sin_family
operator|=
name|he
operator|->
name|h_addrtype
expr_stmt|;
name|sin
operator|.
name|sin_port
operator|=
name|htons
argument_list|(
name|port
argument_list|)
expr_stmt|;
comment|/* try to connect */
if|if
condition|(
operator|(
name|sd
operator|=
name|socket
argument_list|(
name|sin
operator|.
name|sin_family
argument_list|,
name|SOCK_STREAM
argument_list|,
name|IPPROTO_TCP
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
block|{
name|_fetch_syserr
argument_list|()
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
if|if
condition|(
name|connect
argument_list|(
name|sd
argument_list|,
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
operator|&
name|sin
argument_list|,
sizeof|sizeof
name|sin
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|_fetch_syserr
argument_list|()
expr_stmt|;
name|close
argument_list|(
name|sd
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
return|return
name|sd
return|;
block|}
end_function

end_unit

