begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * derived from  *	@(#)if_loop.c	8.1 (Berkeley) 6/10/93  * Id: if_loop.c,v 1.22 1996/06/19 16:24:10 wollman Exp  */
end_comment

begin_comment
comment|/*  * Loopback interface driver for protocol testing and timing.  */
end_comment

begin_include
include|#
directive|include
file|"faith.h"
end_include

begin_if
if|#
directive|if
name|NFAITH
operator|>
literal|0
end_if

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

begin_decl_stmt
specifier|extern
name|int
name|loioctl
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
name|u_long
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|looutput
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
name|ifp
operator|,
expr|struct
name|mbuf
operator|*
name|m
operator|,
expr|struct
name|sockaddr
operator|*
name|dst
operator|,
expr|struct
name|rtentry
operator|*
name|rt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|faithattach
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|PSEUDO_SET
argument_list|(
name|faithattach
argument_list|,
name|if_faith
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|struct
name|ifnet
name|faithif
index|[
name|NFAITH
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FAITHMTU
value|1500
end_define

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|void
name|faithattach
parameter_list|(
name|faith
parameter_list|)
name|void
modifier|*
name|faith
decl_stmt|;
block|{
specifier|register
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|NFAITH
condition|;
name|i
operator|++
control|)
block|{
name|ifp
operator|=
operator|&
name|faithif
index|[
name|i
index|]
expr_stmt|;
name|bzero
argument_list|(
name|ifp
argument_list|,
sizeof|sizeof
argument_list|(
name|faithif
index|[
name|i
index|]
argument_list|)
argument_list|)
expr_stmt|;
name|ifp
operator|->
name|if_name
operator|=
literal|"faith"
expr_stmt|;
name|ifp
operator|->
name|if_unit
operator|=
name|i
expr_stmt|;
name|ifp
operator|->
name|if_mtu
operator|=
name|FAITHMTU
expr_stmt|;
comment|/* Change to BROADCAST experimentaly to announce its prefix. */
name|ifp
operator|->
name|if_flags
operator|=
comment|/* IFF_LOOPBACK */
name|IFF_BROADCAST
operator||
name|IFF_MULTICAST
expr_stmt|;
name|ifp
operator|->
name|if_ioctl
operator|=
name|loioctl
expr_stmt|;
name|ifp
operator|->
name|if_output
operator|=
name|looutput
expr_stmt|;
name|ifp
operator|->
name|if_type
operator|=
name|IFT_FAITH
expr_stmt|;
name|ifp
operator|->
name|if_snd
operator|.
name|ifq_maxlen
operator|=
name|ifqmaxlen
expr_stmt|;
name|ifp
operator|->
name|if_hdrlen
operator|=
literal|0
expr_stmt|;
name|ifp
operator|->
name|if_addrlen
operator|=
literal|0
expr_stmt|;
name|if_attach
argument_list|(
name|ifp
argument_list|)
expr_stmt|;
name|bpfattach
argument_list|(
name|ifp
argument_list|,
name|DLT_NULL
argument_list|,
sizeof|sizeof
argument_list|(
name|u_int
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NFAITH> 0 */
end_comment

end_unit

