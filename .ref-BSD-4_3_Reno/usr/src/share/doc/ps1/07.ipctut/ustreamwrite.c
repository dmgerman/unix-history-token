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
literal|"@(#)ustreamwrite.c	6.4 (Berkeley) 3/7/89"
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
file|<sys/un.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|DATA
value|"Half a league, half a league . . ."
end_define

begin_comment
comment|/*  * This program connects to the socket named in the command line and sends a  * one line message to that socket. The form of the command line is  * ustreamwrite pathname   */
end_comment

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
name|int
name|sock
decl_stmt|;
name|struct
name|sockaddr_un
name|server
decl_stmt|;
name|char
name|buf
index|[
literal|1024
index|]
decl_stmt|;
comment|/* Create socket */
name|sock
operator|=
name|socket
argument_list|(
name|AF_UNIX
argument_list|,
name|SOCK_STREAM
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
literal|"opening stream socket"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* Connect socket using name specified by command line. */
name|server
operator|.
name|sun_family
operator|=
name|AF_UNIX
expr_stmt|;
name|strcpy
argument_list|(
name|server
operator|.
name|sun_path
argument_list|,
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|connect
argument_list|(
name|sock
argument_list|,
operator|&
name|server
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|sockaddr_un
argument_list|)
argument_list|)
operator|<
literal|0
condition|)
block|{
name|close
argument_list|(
name|sock
argument_list|)
expr_stmt|;
name|perror
argument_list|(
literal|"connecting stream socket"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|write
argument_list|(
name|sock
argument_list|,
name|DATA
argument_list|,
sizeof|sizeof
argument_list|(
name|DATA
argument_list|)
argument_list|)
operator|<
literal|0
condition|)
name|perror
argument_list|(
literal|"writing on stream socket"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

