begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************************  Copyright (c) 2007, Chelsio Inc. All rights reserved.  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:   1. Redistributions of source code must retain the above copyright notice,     this list of conditions and the following disclaimer.   2. Neither the name of the Chelsio Corporation nor the names of its     contributors may be used to endorse or promote products derived from     this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.   $FreeBSD$  ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CXGB_TOM_H_
end_ifndef

begin_define
define|#
directive|define
name|CXGB_TOM_H_
end_define

begin_include
include|#
directive|include
file|<sys/protosw.h>
end_include

begin_define
define|#
directive|define
name|LISTEN_INFO_HASH_SIZE
value|32
end_define

begin_struct
struct|struct
name|listen_info
block|{
name|struct
name|listen_info
modifier|*
name|next
decl_stmt|;
comment|/* Link to next entry */
name|struct
name|socket
modifier|*
name|so
decl_stmt|;
comment|/* The listening socket */
name|unsigned
name|int
name|stid
decl_stmt|;
comment|/* The server TID */
block|}
struct|;
end_struct

begin_comment
comment|/*  * TOM tunable parameters.  They can be manipulated through sysctl(2) or /proc.  */
end_comment

begin_struct
struct|struct
name|tom_tunables
block|{
name|int
name|max_host_sndbuf
decl_stmt|;
comment|// max host RAM consumed by a sndbuf
name|int
name|tx_hold_thres
decl_stmt|;
comment|// push/pull threshold for non-full TX sk_buffs
name|int
name|max_wrs
decl_stmt|;
comment|// max # of outstanding WRs per connection
name|int
name|rx_credit_thres
decl_stmt|;
comment|// min # of RX credits needed for RX_DATA_ACK
name|int
name|cong_alg
decl_stmt|;
comment|// Congestion control algorithm
name|int
name|mss
decl_stmt|;
comment|// max TX_DATA WR payload size
name|int
name|delack
decl_stmt|;
comment|// delayed ACK control
name|int
name|max_conn
decl_stmt|;
comment|// maximum number of offloaded connections
name|int
name|soft_backlog_limit
decl_stmt|;
comment|// whether the listen backlog limit is soft
name|int
name|ddp
decl_stmt|;
comment|// whether to put new connections in DDP mode
name|int
name|ddp_thres
decl_stmt|;
comment|// min recvmsg size before activating DDP
name|int
name|ddp_copy_limit
decl_stmt|;
comment|// capacity of kernel DDP buffer
name|int
name|ddp_push_wait
decl_stmt|;
comment|// whether blocking DDP waits for PSH flag
name|int
name|ddp_rcvcoalesce
decl_stmt|;
comment|// whether receive coalescing is enabled
name|int
name|zcopy_sosend_enabled
decl_stmt|;
comment|//< is never zcopied
name|int
name|zcopy_sosend_partial_thres
decl_stmt|;
comment|//< is never zcopied
name|int
name|zcopy_sosend_partial_copy
decl_stmt|;
comment|// bytes copied in partial zcopy
name|int
name|zcopy_sosend_thres
decl_stmt|;
comment|//>= are mostly zcopied
name|int
name|zcopy_sosend_copy
decl_stmt|;
comment|// bytes coped in zcopied
name|int
name|zcopy_sosend_ret_pending_dma
decl_stmt|;
comment|// pot. return while pending DMA
name|int
name|activated
decl_stmt|;
comment|// TOE engine activation state
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tom_data
block|{
name|TAILQ_ENTRY
argument_list|(
argument|tom_data
argument_list|)
name|entry
expr_stmt|;
name|struct
name|t3cdev
modifier|*
name|cdev
decl_stmt|;
name|struct
name|pci_dev
modifier|*
name|pdev
decl_stmt|;
name|struct
name|toedev
name|tdev
decl_stmt|;
name|struct
name|cxgb_client
modifier|*
name|client
decl_stmt|;
name|struct
name|tom_tunables
name|conf
decl_stmt|;
name|struct
name|tom_sysctl_table
modifier|*
name|sysctl
decl_stmt|;
comment|/*          * The next three locks listen_lock, deferq.lock, and tid_release_lock          * are used rarely so we let them potentially share a cacheline.          */
name|struct
name|listen_info
modifier|*
name|listen_hash_tab
index|[
name|LISTEN_INFO_HASH_SIZE
index|]
decl_stmt|;
name|struct
name|mtx
name|listen_lock
decl_stmt|;
name|struct
name|mbuf_head
name|deferq
decl_stmt|;
name|struct
name|task
name|deferq_task
decl_stmt|;
name|struct
name|socket
modifier|*
modifier|*
name|tid_release_list
decl_stmt|;
name|struct
name|mtx
name|tid_release_lock
decl_stmt|;
name|struct
name|task
name|tid_release_task
decl_stmt|;
specifier|volatile
name|int
name|tx_dma_pending
decl_stmt|;
name|unsigned
name|int
name|ddp_llimit
decl_stmt|;
name|unsigned
name|int
name|ddp_ulimit
decl_stmt|;
name|unsigned
name|int
name|rx_page_size
decl_stmt|;
name|u8
modifier|*
name|ppod_map
decl_stmt|;
name|unsigned
name|int
name|nppods
decl_stmt|;
name|struct
name|mtx
name|ppod_map_lock
decl_stmt|;
name|struct
name|adap_ports
modifier|*
name|ports
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|tq
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|listen_ctx
block|{
name|struct
name|socket
modifier|*
name|lso
decl_stmt|;
name|struct
name|tom_data
modifier|*
name|tom_data
decl_stmt|;
name|int
name|ulp_mode
decl_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|toepcb
argument_list|)
name|synq_head
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TOM_DATA
parameter_list|(
name|dev
parameter_list|)
value|(*(struct tom_data **)&(dev)->tod_l4opt)
end_define

begin_define
define|#
directive|define
name|T3C_DEV
parameter_list|(
name|sk
parameter_list|)
value|((TOM_DATA(TOE_DEV(sk)))->cdev)
end_define

begin_define
define|#
directive|define
name|TOEP_T3C_DEV
parameter_list|(
name|toep
parameter_list|)
value|(TOM_DATA(toep->tp_toedev)->cdev)
end_define

begin_define
define|#
directive|define
name|TOM_TUNABLE
parameter_list|(
name|dev
parameter_list|,
name|param
parameter_list|)
value|(TOM_DATA(dev)->conf.param)
end_define

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
name|TP_CLOSE_CON_REQUESTED
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|TP_SYN_RCVD
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|TP_ESTABLISHED
value|(1<< 9)
end_define

begin_function_decl
name|void
name|t3_init_tunables
parameter_list|(
name|struct
name|tom_data
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|t3_sysctl_register
parameter_list|(
name|struct
name|adapter
modifier|*
name|sc
parameter_list|,
specifier|const
name|struct
name|tom_tunables
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|mbuf
operator|*
name|m_gethdr_nofail
argument_list|(
argument|int len
argument_list|)
block|{ 	struct
name|mbuf
operator|*
name|m
block|;
name|m
operator|=
name|m_gethdr
argument_list|(
name|M_NOWAIT
argument_list|,
name|MT_DATA
argument_list|)
block|;
if|if
condition|(
name|m
operator|==
name|NULL
condition|)
block|{
name|panic
argument_list|(
literal|"implement lowmem cache\n"
argument_list|)
expr_stmt|;
block|}
name|KASSERT
argument_list|(
name|len
operator|<
name|MHLEN
argument_list|,
operator|(
literal|"requested header size too large for mbuf"
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|m
operator|->
name|m_pkthdr
operator|.
name|len
operator|=
name|m
operator|->
name|m_len
operator|=
name|len
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
name|m
operator|)
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

