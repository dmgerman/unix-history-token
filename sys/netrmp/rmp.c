begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: Utah $Hdr: rmp.c 1.3 89/06/07$  *  *	From: @(#)rmp.c	7.1 (Berkeley) 5/8/90  *	$Id: rmp.c,v 1.2 1993/11/25 01:36:40 wollman Exp $  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"systm.h"
end_include

begin_include
include|#
directive|include
file|"mbuf.h"
end_include

begin_include
include|#
directive|include
file|"socket.h"
end_include

begin_include
include|#
directive|include
file|"socketvar.h"
end_include

begin_include
include|#
directive|include
file|"../net/if.h"
end_include

begin_include
include|#
directive|include
file|"../net/route.h"
end_include

begin_include
include|#
directive|include
file|"../net/raw_cb.h"
end_include

begin_include
include|#
directive|include
file|"../netrmp/rmp.h"
end_include

begin_include
include|#
directive|include
file|"../netrmp/rmp_var.h"
end_include

begin_comment
comment|/* **  rmp_output: route packet to proper network interface. */
end_comment

begin_function
name|int
name|rmp_output
parameter_list|(
name|m
parameter_list|,
name|so
parameter_list|)
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|struct
name|socket
modifier|*
name|so
decl_stmt|;
block|{
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|struct
name|rawcb
modifier|*
name|rp
init|=
name|sotorawcb
argument_list|(
name|so
argument_list|)
decl_stmt|;
name|struct
name|rmp_packet
modifier|*
name|rmp
decl_stmt|;
comment|/* 	 *  Convert the mbuf back to an RMP packet so we can get the 	 *  address of the "ifnet struct" specifying the interface it 	 *  should go out on. 	 */
name|rmp
operator|=
name|mtod
argument_list|(
name|m
argument_list|,
expr|struct
name|rmp_packet
operator|*
argument_list|)
expr_stmt|;
name|ifp
operator|=
name|rmp
operator|->
name|ifp
expr_stmt|;
comment|/* 	 *  Strip off the "ifnet struct ptr" from the packet leaving 	 *  us with a complete IEEE 802.2 packet. 	 */
name|m_adj
argument_list|(
name|m
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|ifnet
operator|*
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 	 *  Send the packet. 	 */
return|return
call|(
modifier|*
name|ifp
operator|->
name|if_output
call|)
argument_list|(
name|ifp
argument_list|,
name|m
argument_list|,
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
operator|&
name|rp
operator|->
name|rcb_faddr
argument_list|,
operator|(
expr|struct
name|rtentry
operator|*
operator|)
literal|0
argument_list|)
return|;
block|}
end_function

end_unit

