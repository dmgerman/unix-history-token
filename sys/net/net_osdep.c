begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: net_osdep.c,v 1.10 2001/07/26 19:08:37 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_types.h>
end_include

begin_include
include|#
directive|include
file|<net/netisr.h>
end_include

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_include
include|#
directive|include
file|<net/bpf.h>
end_include

begin_include
include|#
directive|include
file|<net/net_osdep.h>
end_include

begin_function
specifier|const
name|char
modifier|*
name|if_name
parameter_list|(
name|ifp
parameter_list|)
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
block|{
define|#
directive|define
name|MAXNUMBUF
value|8
specifier|static
name|char
name|nam
index|[
name|MAXNUMBUF
index|]
index|[
name|IFNAMSIZ
operator|+
literal|10
index|]
decl_stmt|;
comment|/*enough?*/
specifier|static
name|int
name|ifbufround
init|=
literal|0
decl_stmt|;
name|char
modifier|*
name|cp
decl_stmt|;
name|ifbufround
operator|=
operator|(
name|ifbufround
operator|+
literal|1
operator|)
operator|%
name|MAXNUMBUF
expr_stmt|;
name|cp
operator|=
name|nam
index|[
name|ifbufround
index|]
expr_stmt|;
name|snprintf
argument_list|(
name|cp
argument_list|,
name|IFNAMSIZ
operator|+
literal|10
argument_list|,
literal|"%s%d"
argument_list|,
name|ifp
operator|->
name|if_name
argument_list|,
name|ifp
operator|->
name|if_unit
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
specifier|const
name|char
operator|*
operator|)
name|cp
operator|)
return|;
undef|#
directive|undef
name|MAXNUMBUF
block|}
end_function

end_unit

