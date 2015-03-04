begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2009, Chelsio Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * 1. Redistributions of source code must retain the above copyright notice,  *    this list of conditions and the following disclaimer.  *  * 2. Neither the name of the Chelsio Corporation nor the names of its  *    contributors may be used to endorse or promote products derived from  *    this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CXGB_TOEPCB_H_
end_ifndef

begin_define
define|#
directive|define
name|CXGB_TOEPCB_H_
end_define

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/condvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/limits.h>
end_include

begin_define
define|#
directive|define
name|TP_DATASENT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|TP_TX_WAIT_IDLE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|TP_FIN_SENT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|TP_ABORT_RPL_PENDING
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|TP_ABORT_SHUTDOWN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|TP_ABORT_RPL_RCVD
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|TP_ABORT_REQ_RCVD
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|TP_ATTACHED
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|TP_CPL_DONE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|TP_IS_A_SYNQ_ENTRY
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|TP_ABORT_RPL_SENT
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|TP_SEND_FIN
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|TP_SYNQE_EXPANDED
value|(1<< 12)
end_define

begin_struct
struct|struct
name|toepcb
block|{
name|TAILQ_ENTRY
argument_list|(
argument|toepcb
argument_list|)
name|link
expr_stmt|;
comment|/* toep_list */
name|int
name|tp_flags
decl_stmt|;
name|struct
name|toedev
modifier|*
name|tp_tod
decl_stmt|;
name|struct
name|l2t_entry
modifier|*
name|tp_l2t
decl_stmt|;
name|int
name|tp_tid
decl_stmt|;
name|int
name|tp_wr_max
decl_stmt|;
name|int
name|tp_wr_avail
decl_stmt|;
name|int
name|tp_wr_unacked
decl_stmt|;
name|int
name|tp_delack_mode
decl_stmt|;
name|int
name|tp_ulp_mode
decl_stmt|;
name|int
name|tp_qset
decl_stmt|;
name|int
name|tp_enqueued
decl_stmt|;
name|int
name|tp_rx_credits
decl_stmt|;
name|struct
name|inpcb
modifier|*
name|tp_inp
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|tp_m_last
decl_stmt|;
name|struct
name|mbufq
name|wr_list
decl_stmt|;
name|struct
name|mbufq
name|out_of_order_queue
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
specifier|inline
name|void
name|reset_wr_list
parameter_list|(
name|struct
name|toepcb
modifier|*
name|toep
parameter_list|)
block|{
name|mbufq_init
argument_list|(
operator|&
name|toep
operator|->
name|wr_list
argument_list|,
name|INT_MAX
argument_list|)
expr_stmt|;
comment|/* XXX: sane limit needed */
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|enqueue_wr
parameter_list|(
name|struct
name|toepcb
modifier|*
name|toep
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
block|{
operator|(
name|void
operator|)
name|mbufq_enqueue
argument_list|(
operator|&
name|toep
operator|->
name|wr_list
argument_list|,
name|m
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|struct
name|mbuf
modifier|*
name|peek_wr
parameter_list|(
specifier|const
name|struct
name|toepcb
modifier|*
name|toep
parameter_list|)
block|{
return|return
operator|(
name|mbufq_first
argument_list|(
operator|&
name|toep
operator|->
name|wr_list
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|struct
name|mbuf
modifier|*
name|dequeue_wr
parameter_list|(
name|struct
name|toepcb
modifier|*
name|toep
parameter_list|)
block|{
return|return
operator|(
name|mbufq_dequeue
argument_list|(
operator|&
name|toep
operator|->
name|wr_list
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

