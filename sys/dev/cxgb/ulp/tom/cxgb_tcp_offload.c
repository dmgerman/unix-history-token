begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007, Chelsio Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * 1. Redistributions of source code must retain the above copyright notice,  *    this list of conditions and the following disclaimer.  *  * 2. Neither the name of the Chelsio Corporation nor the names of its  *    contributors may be used to endorse or promote products derived from  *    this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
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

begin_comment
comment|/*  * grab bag of accessor routines that will either be moved to netinet  * or removed  */
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockopt.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
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
file|<net/if_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_pcb.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp_offload.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp_syncache.h>
end_include

begin_include
include|#
directive|include
file|<netinet/toedev.h>
end_include

begin_include
include|#
directive|include
file|<dev/cxgb/ulp/tom/cxgb_tcp_offload.h>
end_include

begin_comment
comment|/*  * This file contains code as a short-term staging area before it is moved in   * to sys/netinet/tcp_offload.c  */
end_comment

begin_function
name|void
name|sockbuf_lock
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|)
block|{
name|SOCKBUF_LOCK
argument_list|(
name|sb
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|sockbuf_lock_assert
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|)
block|{
name|SOCKBUF_LOCK_ASSERT
argument_list|(
name|sb
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|sockbuf_unlock
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|)
block|{
name|SOCKBUF_UNLOCK
argument_list|(
name|sb
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|sockbuf_sbspace
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|)
block|{
return|return
operator|(
name|sbspace
argument_list|(
name|sb
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

