begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|sccsid
index|[]
init|=
literal|"@(#)tftpsubs.c	8.1 (Berkeley) 6/6/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Simple minded read-ahead/write-behind subroutines for tftp user and    server.  Written originally with multiple buffers in mind, but current    implementation has two buffer logic wired in.     Todo:  add some sort of final error check so when the write-buffer    is finally flushed, the caller can detect if the disk filled up    (or had an i/o error) and return a nak to the other side.  			Jim Guyton 10/85  */
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
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<arpa/tftp.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"tftpsubs.h"
end_include

begin_define
define|#
directive|define
name|PKTSIZE
value|SEGSIZE+4
end_define

begin_comment
comment|/* should be moved to tftp.h */
end_comment

begin_struct
struct|struct
name|bf
block|{
name|int
name|counter
decl_stmt|;
comment|/* size of data in buffer, or flag */
name|char
name|buf
index|[
name|PKTSIZE
index|]
decl_stmt|;
comment|/* room for data packet */
block|}
name|bfs
index|[
literal|2
index|]
struct|;
end_struct

begin_comment
comment|/* Values for bf.counter  */
end_comment

begin_define
define|#
directive|define
name|BF_ALLOC
value|-3
end_define

begin_comment
comment|/* alloc'd but not yet filled */
end_comment

begin_define
define|#
directive|define
name|BF_FREE
value|-2
end_define

begin_comment
comment|/* free */
end_comment

begin_comment
comment|/* [-1 .. SEGSIZE] = size of data in the data buffer */
end_comment

begin_decl_stmt
specifier|static
name|int
name|nextone
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* index of next buffer to use */
end_comment

begin_decl_stmt
specifier|static
name|int
name|current
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* index of buffer in use */
end_comment

begin_comment
comment|/* control flags for crlf conversions */
end_comment

begin_decl_stmt
name|int
name|newline
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fillbuf: in middle of newline expansion */
end_comment

begin_decl_stmt
name|int
name|prevchar
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* putbuf: previous char (cr check) */
end_comment

begin_function_decl
specifier|static
name|struct
name|tftphdr
modifier|*
name|rw_init
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|struct
name|tftphdr
modifier|*
name|w_init
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|rw_init
argument_list|(
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* write-behind */
end_comment

begin_function
name|struct
name|tftphdr
modifier|*
name|r_init
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|rw_init
argument_list|(
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* read-ahead */
end_comment

begin_function
specifier|static
name|struct
name|tftphdr
modifier|*
name|rw_init
parameter_list|(
name|x
parameter_list|)
comment|/* init for either read-ahead or write-behind */
name|int
name|x
decl_stmt|;
comment|/* zero for write-behind, one for read-head */
block|{
name|newline
operator|=
literal|0
expr_stmt|;
comment|/* init crlf flag */
name|prevchar
operator|=
operator|-
literal|1
expr_stmt|;
name|bfs
index|[
literal|0
index|]
operator|.
name|counter
operator|=
name|BF_ALLOC
expr_stmt|;
comment|/* pass out the first buffer */
name|current
operator|=
literal|0
expr_stmt|;
name|bfs
index|[
literal|1
index|]
operator|.
name|counter
operator|=
name|BF_FREE
expr_stmt|;
name|nextone
operator|=
name|x
expr_stmt|;
comment|/* ahead or behind? */
return|return
operator|(
expr|struct
name|tftphdr
operator|*
operator|)
name|bfs
index|[
literal|0
index|]
operator|.
name|buf
return|;
block|}
end_function

begin_comment
comment|/* Have emptied current buffer by sending to net and getting ack.    Free it and return next buffer filled with data.  */
end_comment

begin_function
name|int
name|readit
parameter_list|(
name|file
parameter_list|,
name|dpp
parameter_list|,
name|convert
parameter_list|)
name|FILE
modifier|*
name|file
decl_stmt|;
comment|/* file opened for read */
name|struct
name|tftphdr
modifier|*
modifier|*
name|dpp
decl_stmt|;
name|int
name|convert
decl_stmt|;
comment|/* if true, convert to ascii */
block|{
name|struct
name|bf
modifier|*
name|b
decl_stmt|;
name|bfs
index|[
name|current
index|]
operator|.
name|counter
operator|=
name|BF_FREE
expr_stmt|;
comment|/* free old one */
name|current
operator|=
operator|!
name|current
expr_stmt|;
comment|/* "incr" current */
name|b
operator|=
operator|&
name|bfs
index|[
name|current
index|]
expr_stmt|;
comment|/* look at new buffer */
if|if
condition|(
name|b
operator|->
name|counter
operator|==
name|BF_FREE
condition|)
comment|/* if it's empty */
name|read_ahead
argument_list|(
name|file
argument_list|,
name|convert
argument_list|)
expr_stmt|;
comment|/* fill it */
comment|/*      assert(b->counter != BF_FREE);*/
comment|/* check */
operator|*
name|dpp
operator|=
operator|(
expr|struct
name|tftphdr
operator|*
operator|)
name|b
operator|->
name|buf
expr_stmt|;
comment|/* set caller's ptr */
return|return
name|b
operator|->
name|counter
return|;
block|}
end_function

begin_comment
comment|/*  * fill the input buffer, doing ascii conversions if requested  * conversions are  lf -> cr,lf  and cr -> cr, nul  */
end_comment

begin_function
name|void
name|read_ahead
parameter_list|(
name|file
parameter_list|,
name|convert
parameter_list|)
name|FILE
modifier|*
name|file
decl_stmt|;
comment|/* file opened for read */
name|int
name|convert
decl_stmt|;
comment|/* if true, convert to ascii */
block|{
specifier|register
name|int
name|i
decl_stmt|;
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
specifier|register
name|int
name|c
decl_stmt|;
name|struct
name|bf
modifier|*
name|b
decl_stmt|;
name|struct
name|tftphdr
modifier|*
name|dp
decl_stmt|;
name|b
operator|=
operator|&
name|bfs
index|[
name|nextone
index|]
expr_stmt|;
comment|/* look at "next" buffer */
if|if
condition|(
name|b
operator|->
name|counter
operator|!=
name|BF_FREE
condition|)
comment|/* nop if not free */
return|return;
name|nextone
operator|=
operator|!
name|nextone
expr_stmt|;
comment|/* "incr" next buffer ptr */
name|dp
operator|=
operator|(
expr|struct
name|tftphdr
operator|*
operator|)
name|b
operator|->
name|buf
expr_stmt|;
if|if
condition|(
name|convert
operator|==
literal|0
condition|)
block|{
name|b
operator|->
name|counter
operator|=
name|read
argument_list|(
name|fileno
argument_list|(
name|file
argument_list|)
argument_list|,
name|dp
operator|->
name|th_data
argument_list|,
name|SEGSIZE
argument_list|)
expr_stmt|;
return|return;
block|}
name|p
operator|=
name|dp
operator|->
name|th_data
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|SEGSIZE
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|newline
condition|)
block|{
if|if
condition|(
name|prevchar
operator|==
literal|'\n'
condition|)
name|c
operator|=
literal|'\n'
expr_stmt|;
comment|/* lf to cr,lf */
else|else
name|c
operator|=
literal|'\0'
expr_stmt|;
comment|/* cr to cr,nul */
name|newline
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|c
operator|=
name|getc
argument_list|(
name|file
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
operator|==
name|EOF
condition|)
break|break;
if|if
condition|(
name|c
operator|==
literal|'\n'
operator|||
name|c
operator|==
literal|'\r'
condition|)
block|{
name|prevchar
operator|=
name|c
expr_stmt|;
name|c
operator|=
literal|'\r'
expr_stmt|;
name|newline
operator|=
literal|1
expr_stmt|;
block|}
block|}
operator|*
name|p
operator|++
operator|=
name|c
expr_stmt|;
block|}
name|b
operator|->
name|counter
operator|=
call|(
name|int
call|)
argument_list|(
name|p
operator|-
name|dp
operator|->
name|th_data
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Update count associated with the buffer, get new buffer    from the queue.  Calls write_behind only if next buffer not    available.  */
end_comment

begin_function
name|int
name|writeit
parameter_list|(
name|file
parameter_list|,
name|dpp
parameter_list|,
name|ct
parameter_list|,
name|convert
parameter_list|)
name|FILE
modifier|*
name|file
decl_stmt|;
name|struct
name|tftphdr
modifier|*
modifier|*
name|dpp
decl_stmt|;
name|int
name|ct
decl_stmt|,
name|convert
decl_stmt|;
block|{
name|bfs
index|[
name|current
index|]
operator|.
name|counter
operator|=
name|ct
expr_stmt|;
comment|/* set size of data to write */
name|current
operator|=
operator|!
name|current
expr_stmt|;
comment|/* switch to other buffer */
if|if
condition|(
name|bfs
index|[
name|current
index|]
operator|.
name|counter
operator|!=
name|BF_FREE
condition|)
comment|/* if not free */
operator|(
name|void
operator|)
name|write_behind
argument_list|(
name|file
argument_list|,
name|convert
argument_list|)
expr_stmt|;
comment|/* flush it */
name|bfs
index|[
name|current
index|]
operator|.
name|counter
operator|=
name|BF_ALLOC
expr_stmt|;
comment|/* mark as alloc'd */
operator|*
name|dpp
operator|=
operator|(
expr|struct
name|tftphdr
operator|*
operator|)
name|bfs
index|[
name|current
index|]
operator|.
name|buf
expr_stmt|;
return|return
name|ct
return|;
comment|/* this is a lie of course */
block|}
end_function

begin_comment
comment|/*  * Output a buffer to a file, converting from netascii if requested.  * CR,NUL -> CR  and CR,LF => LF.  * Note spec is undefined if we get CR as last byte of file or a  * CR followed by anything else.  In this case we leave it alone.  */
end_comment

begin_function
name|int
name|write_behind
parameter_list|(
name|file
parameter_list|,
name|convert
parameter_list|)
name|FILE
modifier|*
name|file
decl_stmt|;
name|int
name|convert
decl_stmt|;
block|{
name|char
modifier|*
name|buf
decl_stmt|;
name|int
name|count
decl_stmt|;
specifier|register
name|int
name|ct
decl_stmt|;
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
specifier|register
name|int
name|c
decl_stmt|;
comment|/* current character */
name|struct
name|bf
modifier|*
name|b
decl_stmt|;
name|struct
name|tftphdr
modifier|*
name|dp
decl_stmt|;
name|b
operator|=
operator|&
name|bfs
index|[
name|nextone
index|]
expr_stmt|;
if|if
condition|(
name|b
operator|->
name|counter
operator|<
operator|-
literal|1
condition|)
comment|/* anything to flush? */
return|return
literal|0
return|;
comment|/* just nop if nothing to do */
name|count
operator|=
name|b
operator|->
name|counter
expr_stmt|;
comment|/* remember byte count */
name|b
operator|->
name|counter
operator|=
name|BF_FREE
expr_stmt|;
comment|/* reset flag */
name|dp
operator|=
operator|(
expr|struct
name|tftphdr
operator|*
operator|)
name|b
operator|->
name|buf
expr_stmt|;
name|nextone
operator|=
operator|!
name|nextone
expr_stmt|;
comment|/* incr for next time */
name|buf
operator|=
name|dp
operator|->
name|th_data
expr_stmt|;
if|if
condition|(
name|count
operator|<=
literal|0
condition|)
return|return
operator|-
literal|1
return|;
comment|/* nak logic? */
if|if
condition|(
name|convert
operator|==
literal|0
condition|)
return|return
name|write
argument_list|(
name|fileno
argument_list|(
name|file
argument_list|)
argument_list|,
name|buf
argument_list|,
name|count
argument_list|)
return|;
name|p
operator|=
name|buf
expr_stmt|;
name|ct
operator|=
name|count
expr_stmt|;
while|while
condition|(
name|ct
operator|--
condition|)
block|{
comment|/* loop over the buffer */
name|c
operator|=
operator|*
name|p
operator|++
expr_stmt|;
comment|/* pick up a character */
if|if
condition|(
name|prevchar
operator|==
literal|'\r'
condition|)
block|{
comment|/* if prev char was cr */
if|if
condition|(
name|c
operator|==
literal|'\n'
condition|)
comment|/* if have cr,lf then just */
name|fseek
argument_list|(
name|file
argument_list|,
operator|-
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* smash lf on top of the cr */
elseif|else
if|if
condition|(
name|c
operator|==
literal|'\0'
condition|)
comment|/* if have cr,nul then */
goto|goto
name|skipit
goto|;
comment|/* just skip over the putc */
comment|/* else just fall through and allow it */
block|}
name|putc
argument_list|(
name|c
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|skipit
label|:
name|prevchar
operator|=
name|c
expr_stmt|;
block|}
return|return
name|count
return|;
block|}
end_function

begin_comment
comment|/* When an error has occurred, it is possible that the two sides  * are out of synch.  Ie: that what I think is the other side's  * response to packet N is really their response to packet N-1.  *  * So, to try to prevent that, we flush all the input queued up  * for us on the network connection on our host.  *  * We return the number of packets we flushed (mostly for reporting  * when trace is active).  */
end_comment

begin_function
name|int
name|synchnet
parameter_list|(
name|f
parameter_list|)
name|int
name|f
decl_stmt|;
comment|/* socket to flush */
block|{
name|int
name|i
decl_stmt|,
name|j
init|=
literal|0
decl_stmt|;
name|char
name|rbuf
index|[
name|PKTSIZE
index|]
decl_stmt|;
name|struct
name|sockaddr_storage
name|from
decl_stmt|;
name|int
name|fromlen
decl_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
operator|(
name|void
operator|)
name|ioctl
argument_list|(
name|f
argument_list|,
name|FIONREAD
argument_list|,
operator|&
name|i
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
condition|)
block|{
name|j
operator|++
expr_stmt|;
name|fromlen
operator|=
sizeof|sizeof
name|from
expr_stmt|;
operator|(
name|void
operator|)
name|recvfrom
argument_list|(
name|f
argument_list|,
name|rbuf
argument_list|,
sizeof|sizeof
argument_list|(
name|rbuf
argument_list|)
argument_list|,
literal|0
argument_list|,
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
operator|&
name|from
argument_list|,
operator|&
name|fromlen
argument_list|)
expr_stmt|;
block|}
else|else
block|{
return|return
operator|(
name|j
operator|)
return|;
block|}
block|}
block|}
end_function

end_unit

