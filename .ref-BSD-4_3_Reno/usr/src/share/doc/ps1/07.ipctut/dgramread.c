begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1986 The Regents of the University of California.\n\  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
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
literal|"@(#)dgramread.c	6.4 (Berkeley) 3/7/89"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
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
file|<stdio.h>
end_include

begin_comment
comment|/*  * In the included file<netinet/in.h> a sockaddr_in is defined as follows:  * struct sockaddr_in {  *	short	sin_family;  *	u_short	sin_port;  *	struct in_addr sin_addr;  *	char	sin_zero[8];  * };   *  * This program creates a datagram socket, binds a name to it, then reads  * from the socket.  */
end_comment

begin_function
name|main
parameter_list|()
block|{
name|int
name|sock
decl_stmt|,
name|length
decl_stmt|;
name|struct
name|sockaddr_in
name|name
decl_stmt|;
name|char
name|buf
index|[
literal|1024
index|]
decl_stmt|;
comment|/* Create socket from which to read. */
name|sock
operator|=
name|socket
argument_list|(
name|AF_INET
argument_list|,
name|SOCK_DGRAM
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|sock
operator|<
literal|0
condition|)
block|{
name|perror
argument_list|(
literal|"opening datagram socket"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* Create name with wildcards. */
name|name
operator|.
name|sin_family
operator|=
name|AF_INET
expr_stmt|;
name|name
operator|.
name|sin_addr
operator|.
name|s_addr
operator|=
name|INADDR_ANY
expr_stmt|;
name|name
operator|.
name|sin_port
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|bind
argument_list|(
name|sock
argument_list|,
operator|&
name|name
argument_list|,
sizeof|sizeof
argument_list|(
name|name
argument_list|)
argument_list|)
condition|)
block|{
name|perror
argument_list|(
literal|"binding datagram socket"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* Find assigned port value and print it out. */
name|length
operator|=
sizeof|sizeof
argument_list|(
name|name
argument_list|)
expr_stmt|;
if|if
condition|(
name|getsockname
argument_list|(
name|sock
argument_list|,
operator|&
name|name
argument_list|,
operator|&
name|length
argument_list|)
condition|)
block|{
name|perror
argument_list|(
literal|"getting socket name"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"Socket has port #%d\en"
argument_list|,
name|ntohs
argument_list|(
name|name
operator|.
name|sin_port
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Read from the socket */
if|if
condition|(
name|read
argument_list|(
name|sock
argument_list|,
name|buf
argument_list|,
literal|1024
argument_list|)
operator|<
literal|0
condition|)
name|perror
argument_list|(
literal|"receiving datagram packet"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"-->%s\en"
argument_list|,
name|buf
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|sock
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

