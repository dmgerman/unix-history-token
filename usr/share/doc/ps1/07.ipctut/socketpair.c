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
literal|"@(#)socketpair.c	6.3 (Berkeley) 3/7/89"
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
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|DATA1
value|"In Xanadu, did Kublai Khan . . ."
end_define

begin_define
define|#
directive|define
name|DATA2
value|"A stately pleasure dome decree . . ."
end_define

begin_comment
comment|/*  * This program creates a pair of connected sockets then forks and  * communicates over them.  This is very similar to communication with pipes,  * however, socketpairs are two-way communications objects. Therefore I can  * send messages in both directions.   */
end_comment

begin_function
name|main
parameter_list|()
block|{
name|int
name|sockets
index|[
literal|2
index|]
decl_stmt|,
name|child
decl_stmt|;
name|char
name|buf
index|[
literal|1024
index|]
decl_stmt|;
if|if
condition|(
name|socketpair
argument_list|(
name|AF_UNIX
argument_list|,
name|SOCK_STREAM
argument_list|,
literal|0
argument_list|,
name|sockets
argument_list|)
operator|<
literal|0
condition|)
block|{
name|perror
argument_list|(
literal|"opening stream socket pair"
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
operator|(
name|child
operator|=
name|fork
argument_list|()
operator|)
operator|==
operator|-
literal|1
condition|)
name|perror
argument_list|(
literal|"fork"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|child
condition|)
block|{
comment|/* This is the parent. */
name|close
argument_list|(
name|sockets
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|read
argument_list|(
name|sockets
index|[
literal|1
index|]
argument_list|,
name|buf
argument_list|,
literal|1024
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
name|perror
argument_list|(
literal|"reading stream message"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"-->%s\en"
argument_list|,
name|buf
argument_list|)
expr_stmt|;
if|if
condition|(
name|write
argument_list|(
name|sockets
index|[
literal|1
index|]
argument_list|,
name|DATA2
argument_list|,
sizeof|sizeof
argument_list|(
name|DATA2
argument_list|)
argument_list|)
operator|<
literal|0
condition|)
name|perror
argument_list|(
literal|"writing stream message"
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|sockets
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* This is the child. */
name|close
argument_list|(
name|sockets
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|write
argument_list|(
name|sockets
index|[
literal|0
index|]
argument_list|,
name|DATA1
argument_list|,
sizeof|sizeof
argument_list|(
name|DATA1
argument_list|)
argument_list|)
operator|<
literal|0
condition|)
name|perror
argument_list|(
literal|"writing stream message"
argument_list|)
expr_stmt|;
if|if
condition|(
name|read
argument_list|(
name|sockets
index|[
literal|0
index|]
argument_list|,
name|buf
argument_list|,
literal|1024
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
name|perror
argument_list|(
literal|"reading stream message"
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
name|sockets
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

