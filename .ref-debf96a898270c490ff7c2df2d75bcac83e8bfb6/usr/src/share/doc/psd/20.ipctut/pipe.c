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
literal|"@(#)pipe.c	6.3 (Berkeley) %G%"
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
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|DATA
value|"Bright star, would I were steadfast as thou art . . ."
end_define

begin_comment
comment|/*  * This program creates a pipe, then forks.  The child communicates to the  * parent over the pipe. Notice that a pipe is a one-way communications  * device.  I can write to the output socket (sockets[1], the second socket  * of the array returned by pipe()) and read from the input socket  * (sockets[0]), but not vice versa.   */
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
comment|/* Create a pipe */
if|if
condition|(
name|pipe
argument_list|(
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
literal|10
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
name|char
name|buf
index|[
literal|1024
index|]
decl_stmt|;
comment|/* This is still the parent.  It reads the child's message. */
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
argument_list|)
operator|<
literal|0
condition|)
name|perror
argument_list|(
literal|"reading message"
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
else|else
block|{
comment|/* This is the child.  It writes a message to its parent. */
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
name|write
argument_list|(
name|sockets
index|[
literal|1
index|]
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
literal|"writing message"
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
block|}
end_function

end_unit

