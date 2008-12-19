begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************************  Copyright (c) 2007, Chelsio Inc. All rights reserved.  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:   1. Redistributions of source code must retain the above copyright notice,     this list of conditions and the following disclaimer.   2. Neither the name of the Chelsio Corporation nor the names of its     contributors may be used to endorse or promote products derived from     this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  ***************************************************************************/
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
file|<sys/fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/limits.h>
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
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockopt.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockstate.h>
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
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_pcb.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_var.h>
end_include

begin_include
include|#
directive|include
file|<dev/cxgb/cxgb_osdep.h>
end_include

begin_include
include|#
directive|include
file|<dev/cxgb/sys/mbufq.h>
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
file|<netinet/tcp_fsm.h>
end_include

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_include
include|#
directive|include
file|<dev/cxgb/t3cdev.h>
end_include

begin_include
include|#
directive|include
file|<dev/cxgb/common/cxgb_firmware_exports.h>
end_include

begin_include
include|#
directive|include
file|<dev/cxgb/common/cxgb_tcb.h>
end_include

begin_include
include|#
directive|include
file|<dev/cxgb/common/cxgb_ctl_defs.h>
end_include

begin_include
include|#
directive|include
file|<dev/cxgb/common/cxgb_t3_cpl.h>
end_include

begin_include
include|#
directive|include
file|<dev/cxgb/cxgb_offload.h>
end_include

begin_include
include|#
directive|include
file|<dev/cxgb/cxgb_include.h>
end_include

begin_include
include|#
directive|include
file|<dev/cxgb/ulp/toecore/cxgb_toedev.h>
end_include

begin_include
include|#
directive|include
file|<dev/cxgb/ulp/tom/cxgb_tom.h>
end_include

begin_include
include|#
directive|include
file|<dev/cxgb/ulp/tom/cxgb_defs.h>
end_include

begin_include
include|#
directive|include
file|<dev/cxgb/ulp/tom/cxgb_t3_ddp.h>
end_include

begin_comment
comment|/* Avoid clutter in the hw.* space, keep all toe tunables within hw.cxgb */
end_comment

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_hw_cxgb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_hw_cxgb
argument_list|,
name|OID_AUTO
argument_list|,
name|toe
argument_list|,
name|CTLFLAG_RD
argument_list|,
literal|0
argument_list|,
literal|"TOE parameters"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|struct
name|tom_tunables
name|default_tunable_vals
init|=
block|{
operator|.
name|max_host_sndbuf
operator|=
literal|32
operator|*
literal|1024
block|,
operator|.
name|tx_hold_thres
operator|=
literal|0
block|,
operator|.
name|max_wrs
operator|=
literal|15
block|,
operator|.
name|rx_credit_thres
operator|=
literal|15
operator|*
literal|1024
block|,
operator|.
name|cong_alg
operator|=
operator|-
literal|1
block|,
operator|.
name|mss
operator|=
literal|16384
block|,
operator|.
name|delack
operator|=
literal|1
block|,
operator|.
name|max_conn
operator|=
operator|-
literal|1
block|,
operator|.
name|soft_backlog_limit
operator|=
literal|0
block|,
operator|.
name|ddp
operator|=
literal|1
block|,
operator|.
name|ddp_thres
operator|=
literal|14
operator|*
literal|4096
block|,
operator|.
name|ddp_copy_limit
operator|=
literal|13
operator|*
literal|4096
block|,
operator|.
name|ddp_push_wait
operator|=
literal|1
block|,
operator|.
name|ddp_rcvcoalesce
operator|=
literal|0
block|,
operator|.
name|zcopy_sosend_enabled
operator|=
literal|0
block|,
operator|.
name|zcopy_sosend_partial_thres
operator|=
literal|40960
block|,
operator|.
name|zcopy_sosend_partial_copy
operator|=
literal|4096
operator|*
literal|3
block|,
operator|.
name|zcopy_sosend_thres
operator|=
literal|128
operator|*
literal|1024
block|,
operator|.
name|zcopy_sosend_copy
operator|=
literal|4096
operator|*
literal|2
block|,
operator|.
name|zcopy_sosend_ret_pending_dma
operator|=
literal|1
block|,
operator|.
name|activated
operator|=
literal|1
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|activated
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|TUNABLE_INT
argument_list|(
literal|"hw.cxgb.toe.activated"
argument_list|,
operator|&
name|activated
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_UINT
argument_list|(
name|_hw_cxgb_toe
argument_list|,
name|OID_AUTO
argument_list|,
name|activated
argument_list|,
name|CTLFLAG_RDTUN
argument_list|,
operator|&
name|activated
argument_list|,
literal|0
argument_list|,
literal|"enable TOE at init time"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|int
name|ddp
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|TUNABLE_INT
argument_list|(
literal|"hw.cxgb.toe.ddp"
argument_list|,
operator|&
name|ddp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_UINT
argument_list|(
name|_hw_cxgb_toe
argument_list|,
name|OID_AUTO
argument_list|,
name|ddp
argument_list|,
name|CTLFLAG_RDTUN
argument_list|,
operator|&
name|ddp
argument_list|,
literal|0
argument_list|,
literal|"enable DDP"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|t3_init_tunables
parameter_list|(
name|struct
name|tom_data
modifier|*
name|t
parameter_list|)
block|{
name|t
operator|->
name|conf
operator|=
name|default_tunable_vals
expr_stmt|;
comment|/* Adjust tunables */
name|t
operator|->
name|conf
operator|.
name|activated
operator|=
name|activated
expr_stmt|;
name|t
operator|->
name|conf
operator|.
name|ddp
operator|=
name|ddp
expr_stmt|;
comment|/* Now apply device specific fixups. */
name|t
operator|->
name|conf
operator|.
name|mss
operator|=
name|T3C_DATA
argument_list|(
name|t
operator|->
name|cdev
argument_list|)
operator|->
name|tx_max_chunk
expr_stmt|;
name|t
operator|->
name|conf
operator|.
name|max_wrs
operator|=
name|T3C_DATA
argument_list|(
name|t
operator|->
name|cdev
argument_list|)
operator|->
name|max_wrs
expr_stmt|;
block|}
end_function

begin_function
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
block|{
name|struct
name|sysctl_ctx_list
modifier|*
name|ctx
decl_stmt|;
name|struct
name|sysctl_oid_list
modifier|*
name|children
decl_stmt|;
name|ctx
operator|=
name|device_get_sysctl_ctx
argument_list|(
name|sc
operator|->
name|dev
argument_list|)
expr_stmt|;
name|children
operator|=
name|SYSCTL_CHILDREN
argument_list|(
name|device_get_sysctl_tree
argument_list|(
name|sc
operator|->
name|dev
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

