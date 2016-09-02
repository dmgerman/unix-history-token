begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012, 2015 Chelsio Communications, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CXGBEI_OFLD_H__
end_ifndef

begin_define
define|#
directive|define
name|__CXGBEI_OFLD_H__
end_define

begin_include
include|#
directive|include
file|<dev/iscsi/icl.h>
end_include

begin_enum
enum|enum
block|{
name|CWT_SLEEPING
init|=
literal|1
block|,
name|CWT_RUNNING
init|=
literal|2
block|,
name|CWT_STOP
init|=
literal|3
block|,
name|CWT_STOPPED
init|=
literal|4
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|cxgbei_worker_thread_softc
block|{
name|struct
name|mtx
name|cwt_lock
decl_stmt|;
name|struct
name|cv
name|cwt_cv
decl_stmt|;
specifier|volatile
name|int
name|cwt_state
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|icl_cxgbei_conn
argument_list|)
name|rx_head
expr_stmt|;
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|CXGBEI_CONN_SIGNATURE
value|0x56788765
end_define

begin_enum
enum|enum
block|{
name|RXF_ACTIVE
init|=
literal|1
operator|<<
literal|0
block|,
comment|/* In the worker thread's queue */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|icl_cxgbei_conn
block|{
name|struct
name|icl_conn
name|ic
decl_stmt|;
comment|/* cxgbei specific stuff goes here. */
name|uint32_t
name|icc_signature
decl_stmt|;
name|int
name|ulp_submode
decl_stmt|;
name|struct
name|adapter
modifier|*
name|sc
decl_stmt|;
name|struct
name|toepcb
modifier|*
name|toep
decl_stmt|;
comment|/* Receive related. */
name|u_int
name|rx_flags
decl_stmt|;
comment|/* protected by so_rcv lock */
name|u_int
name|cwt
decl_stmt|;
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|icl_pdu
argument_list|)
name|rcvd_pdus
expr_stmt|;
comment|/* protected by so_rcv lock */
name|TAILQ_ENTRY
argument_list|(
argument|icl_cxgbei_conn
argument_list|)
name|rx_link
expr_stmt|;
comment|/* protected by cwt lock */
block|}
struct|;
end_struct

begin_function
specifier|static
specifier|inline
name|struct
name|icl_cxgbei_conn
modifier|*
name|ic_to_icc
parameter_list|(
name|struct
name|icl_conn
modifier|*
name|ic
parameter_list|)
block|{
return|return
operator|(
name|__containerof
argument_list|(
name|ic
argument_list|,
expr|struct
name|icl_cxgbei_conn
argument_list|,
name|ic
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* PDU flags and signature. */
end_comment

begin_enum
enum|enum
block|{
name|ICPF_RX_HDR
init|=
literal|1
operator|<<
literal|0
block|,
comment|/* PDU header received. */
name|ICPF_RX_FLBUF
init|=
literal|1
operator|<<
literal|1
block|,
comment|/* PDU payload received in a freelist. */
name|ICPF_RX_DDP
init|=
literal|1
operator|<<
literal|2
block|,
comment|/* PDU payload DDP'd. */
name|ICPF_RX_STATUS
init|=
literal|1
operator|<<
literal|3
block|,
comment|/* Rx status received. */
name|ICPF_HCRC_ERR
init|=
literal|1
operator|<<
literal|4
block|,
comment|/* Header digest error. */
name|ICPF_DCRC_ERR
init|=
literal|1
operator|<<
literal|5
block|,
comment|/* Data digest error. */
name|ICPF_PAD_ERR
init|=
literal|1
operator|<<
literal|6
block|,
comment|/* Padding error. */
name|CXGBEI_PDU_SIGNATURE
init|=
literal|0x12344321
block|}
enum|;
end_enum

begin_struct
struct|struct
name|icl_cxgbei_pdu
block|{
name|struct
name|icl_pdu
name|ip
decl_stmt|;
comment|/* cxgbei specific stuff goes here. */
name|uint32_t
name|icp_signature
decl_stmt|;
name|uint32_t
name|icp_seq
decl_stmt|;
comment|/* For debug only */
name|u_int
name|icp_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
specifier|inline
name|struct
name|icl_cxgbei_pdu
modifier|*
name|ip_to_icp
parameter_list|(
name|struct
name|icl_pdu
modifier|*
name|ip
parameter_list|)
block|{
return|return
operator|(
name|__containerof
argument_list|(
name|ip
argument_list|,
expr|struct
name|icl_cxgbei_pdu
argument_list|,
name|ip
argument_list|)
operator|)
return|;
block|}
end_function

begin_struct
struct|struct
name|cxgbei_data
block|{
name|u_int
name|max_tx_pdu_len
decl_stmt|;
name|u_int
name|max_rx_pdu_len
decl_stmt|;
name|u_int
name|ddp_threshold
decl_stmt|;
name|struct
name|ppod_region
name|pr
decl_stmt|;
name|struct
name|sysctl_ctx_list
name|ctx
decl_stmt|;
comment|/* from uld_activate to deactivate */
name|counter_u64_t
name|ddp_setup_ok
decl_stmt|;
name|counter_u64_t
name|ddp_setup_error
decl_stmt|;
name|counter_u64_t
name|ddp_bytes
decl_stmt|;
name|counter_u64_t
name|ddp_pdus
decl_stmt|;
name|counter_u64_t
name|fl_bytes
decl_stmt|;
name|counter_u64_t
name|fl_pdus
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cxgbei.c */
end_comment

begin_function_decl
name|u_int
name|cxgbei_select_worker_thread
parameter_list|(
name|struct
name|icl_cxgbei_conn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* icl_cxgbei.c */
end_comment

begin_function_decl
name|int
name|icl_cxgbei_mod_load
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|icl_cxgbei_mod_unload
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

