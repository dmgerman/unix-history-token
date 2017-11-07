begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2010 Riccardo Panicucci, Universita` di Pisa  * All rights reserved  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/socketvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/rwlock.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_comment
comment|/* IFNAMSIZ */
end_comment

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip_var.h>
end_include

begin_comment
comment|/* ipfw_rule_ref */
end_comment

begin_include
include|#
directive|include
file|<netinet/ip_fw.h>
end_include

begin_comment
comment|/* flow_id */
end_comment

begin_include
include|#
directive|include
file|<netinet/ip_dummynet.h>
end_include

begin_include
include|#
directive|include
file|<netpfil/ipfw/ip_fw_private.h>
end_include

begin_include
include|#
directive|include
file|<netpfil/ipfw/dn_heap.h>
end_include

begin_include
include|#
directive|include
file|<netpfil/ipfw/ip_dn_private.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NEW_AQM
end_ifdef

begin_include
include|#
directive|include
file|<netpfil/ipfw/dn_aqm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netpfil/ipfw/dn_sched.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<dn_test.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This file implements a FIFO scheduler for a single queue.  * The queue is allocated as part of the scheduler instance,  * and there is a single flowset is in the template which stores  * queue size and policy.  * Enqueue and dequeue use the default library functions.  */
end_comment

begin_function
specifier|static
name|int
name|fifo_enqueue
parameter_list|(
name|struct
name|dn_sch_inst
modifier|*
name|si
parameter_list|,
name|struct
name|dn_queue
modifier|*
name|q
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
block|{
comment|/* XXX if called with q != NULL and m=NULL, this is a 	 * re-enqueue from an existing scheduler, which we should 	 * handle. 	 */
operator|(
name|void
operator|)
name|q
expr_stmt|;
return|return
name|dn_enqueue
argument_list|(
operator|(
expr|struct
name|dn_queue
operator|*
operator|)
operator|(
name|si
operator|+
literal|1
operator|)
argument_list|,
name|m
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|struct
name|mbuf
modifier|*
name|fifo_dequeue
parameter_list|(
name|struct
name|dn_sch_inst
modifier|*
name|si
parameter_list|)
block|{
return|return
name|dn_dequeue
argument_list|(
operator|(
expr|struct
name|dn_queue
operator|*
operator|)
operator|(
name|si
operator|+
literal|1
operator|)
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|fifo_new_sched
parameter_list|(
name|struct
name|dn_sch_inst
modifier|*
name|si
parameter_list|)
block|{
comment|/* This scheduler instance contains the queue */
name|struct
name|dn_queue
modifier|*
name|q
init|=
operator|(
expr|struct
name|dn_queue
operator|*
operator|)
operator|(
name|si
operator|+
literal|1
operator|)
decl_stmt|;
name|set_oid
argument_list|(
operator|&
name|q
operator|->
name|ni
operator|.
name|oid
argument_list|,
name|DN_QUEUE
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|q
argument_list|)
argument_list|)
expr_stmt|;
name|q
operator|->
name|_si
operator|=
name|si
expr_stmt|;
name|q
operator|->
name|fs
operator|=
name|si
operator|->
name|sched
operator|->
name|fs
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|fifo_free_sched
parameter_list|(
name|struct
name|dn_sch_inst
modifier|*
name|si
parameter_list|)
block|{
name|struct
name|dn_queue
modifier|*
name|q
init|=
operator|(
expr|struct
name|dn_queue
operator|*
operator|)
operator|(
name|si
operator|+
literal|1
operator|)
decl_stmt|;
name|dn_free_pkts
argument_list|(
name|q
operator|->
name|mq
operator|.
name|head
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|q
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|q
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * FIFO scheduler descriptor  * contains the type of the scheduler, the name, the size of extra  * data structures, and function pointers.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|dn_alg
name|fifo_desc
init|=
block|{
name|_SI
argument_list|(
argument|.type =
argument_list|)
name|DN_SCHED_FIFO
block|,
name|_SI
argument_list|(
operator|.
name|name
operator|=
argument_list|)
literal|"FIFO"
block|,
name|_SI
argument_list|(
operator|.
name|flags
operator|=
argument_list|)
literal|0
block|,
name|_SI
argument_list|(
operator|.
name|schk_datalen
operator|=
argument_list|)
literal|0
block|,
name|_SI
argument_list|(
operator|.
name|si_datalen
operator|=
argument_list|)
sizeof|sizeof
argument_list|(
expr|struct
name|dn_queue
argument_list|)
block|,
name|_SI
argument_list|(
operator|.
name|q_datalen
operator|=
argument_list|)
literal|0
block|,
name|_SI
argument_list|(
argument|.enqueue =
argument_list|)
name|fifo_enqueue
block|,
name|_SI
argument_list|(
argument|.dequeue =
argument_list|)
name|fifo_dequeue
block|,
name|_SI
argument_list|(
argument|.config =
argument_list|)
name|NULL
block|,
name|_SI
argument_list|(
argument|.destroy =
argument_list|)
name|NULL
block|,
name|_SI
argument_list|(
argument|.new_sched =
argument_list|)
name|fifo_new_sched
block|,
name|_SI
argument_list|(
argument|.free_sched =
argument_list|)
name|fifo_free_sched
block|,
name|_SI
argument_list|(
argument|.new_fsk =
argument_list|)
name|NULL
block|,
name|_SI
argument_list|(
argument|.free_fsk =
argument_list|)
name|NULL
block|,
name|_SI
argument_list|(
argument|.new_queue =
argument_list|)
name|NULL
block|,
name|_SI
argument_list|(
argument|.free_queue =
argument_list|)
name|NULL
block|,
ifdef|#
directive|ifdef
name|NEW_AQM
name|_SI
argument_list|(
argument|.getconfig =
argument_list|)
name|NULL
block|,
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DECLARE_DNSCHED_MODULE
argument_list|(
name|dn_fifo
argument_list|,
operator|&
name|fifo_desc
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

