begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010-2011 Monthadar Al Jaberi, TerraNet AB  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_WTAP_WTAPVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_WTAP_WTAPVAR_H
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
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
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
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
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/kthread.h>
end_include

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<sys/priv.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_dl.h>
end_include

begin_include
include|#
directive|include
file|<net/if_media.h>
end_include

begin_include
include|#
directive|include
file|<net/if_types.h>
end_include

begin_include
include|#
directive|include
file|<net/if_arp.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/if_llc.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_var.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_regdomain.h>
end_include

begin_include
include|#
directive|include
file|<net/bpf.h>
end_include

begin_include
include|#
directive|include
file|<net/vnet.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/if_ether.h>
end_include

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|DWTAP_PRINTF
parameter_list|(
modifier|...
parameter_list|)
value|printf(__VA_ARGS__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DWTAP_PRINTF
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"if_wtapioctl.h"
end_include

begin_define
define|#
directive|define
name|MAX_NBR_WTAP
value|(64)
end_define

begin_define
define|#
directive|define
name|BEACON_INTRERVAL
value|(1000)
end_define

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_WTAP
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_WTAP_PACKET
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_WTAP_BEACON
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_WTAP_RXBUF
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_WTAP_PLUGIN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* driver-specific node state */
end_comment

begin_struct
struct|struct
name|wtap_node
block|{
name|struct
name|ieee80211_node
name|an_node
decl_stmt|;
comment|/* base class */
comment|/* future addons */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WTAP_NODE
parameter_list|(
name|ni
parameter_list|)
value|((struct ath_node *)(ni))
end_define

begin_define
define|#
directive|define
name|WTAP_NODE_CONST
parameter_list|(
name|ni
parameter_list|)
value|((const struct ath_node *)(ni))
end_define

begin_struct
struct|struct
name|wtap_buf
block|{
name|STAILQ_ENTRY
argument_list|(
argument|wtap_buf
argument_list|)
name|bf_list
expr_stmt|;
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
comment|/* mbuf for buf */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|wtap_buf
argument_list|)
name|wtap_bufhead
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|WTAP_BUF_BUSY
value|0x00000002
end_define

begin_comment
comment|/* (tx) desc owned by h/w */
end_comment

begin_struct
struct|struct
name|wtap_vap
block|{
name|struct
name|ieee80211vap
name|av_vap
decl_stmt|;
comment|/* base class */
name|int32_t
name|id
decl_stmt|;
comment|/* wtap id */
name|struct
name|cdev
modifier|*
name|av_dev
decl_stmt|;
comment|/* userspace injecting frames */
name|struct
name|wtap_medium
modifier|*
name|av_md
decl_stmt|;
comment|/* back pointer */
name|struct
name|mbuf
modifier|*
name|beacon
decl_stmt|;
comment|/* beacon */
name|struct
name|ieee80211_node
modifier|*
name|bf_node
decl_stmt|;
comment|/* pointer to the node */
name|struct
name|ieee80211_beacon_offsets
name|av_boff
decl_stmt|;
comment|/* dynamic update state */
name|struct
name|callout
name|av_swba
decl_stmt|;
comment|/* software beacon alert */
name|uint32_t
name|av_bcinterval
decl_stmt|;
comment|/* beacon interval */
name|void
function_decl|(
modifier|*
name|av_recv_mgmt
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|av_newstate
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|enum
name|ieee80211_state
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|av_bmiss
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WTAP_VAP
parameter_list|(
name|vap
parameter_list|)
value|((struct wtap_vap *)(vap))
end_define

begin_struct_decl
struct_decl|struct
name|taskqueue
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|wtap_softc
block|{
name|int32_t
name|id
decl_stmt|;
name|int32_t
name|up
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|sc_ifp
decl_stmt|;
comment|/* interface common */
name|struct
name|wtap_medium
modifier|*
name|sc_md
decl_stmt|;
comment|/* interface medium */
name|struct
name|ieee80211_node
modifier|*
function_decl|(
modifier|*
name|sc_node_alloc
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
specifier|const
name|uint8_t
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_node_free
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|if_output
function_decl|)
comment|/* output routine (enqueue) */
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|route
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|if_input
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
comment|/* from h/w driver */
name|int
function_decl|(
modifier|*
name|if_transmit
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
comment|/* output routine */
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
comment|/* master lock (recursive) */
name|struct
name|taskqueue
modifier|*
name|sc_tq
decl_stmt|;
comment|/* private task queue */
name|wtap_bufhead
name|sc_rxbuf
decl_stmt|;
comment|/* receive buffer */
name|struct
name|task
name|sc_rxtask
decl_stmt|;
comment|/* rx int processing */
name|struct
name|wtap_tx_radiotap_header
name|sc_tx_th
decl_stmt|;
name|int
name|sc_tx_th_len
decl_stmt|;
name|struct
name|wtap_rx_radiotap_header
name|sc_rx_th
decl_stmt|;
name|int
name|sc_rx_th_len
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int32_t
name|wtap_attach
parameter_list|(
name|struct
name|wtap_softc
modifier|*
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|macaddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|wtap_detach
parameter_list|(
name|struct
name|wtap_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wtap_resume
parameter_list|(
name|struct
name|wtap_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wtap_suspend
parameter_list|(
name|struct
name|wtap_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wtap_shutdown
parameter_list|(
name|struct
name|wtap_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wtap_intr
parameter_list|(
name|struct
name|wtap_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wtap_inject
parameter_list|(
name|struct
name|wtap_softc
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wtap_rx_deliver
parameter_list|(
name|struct
name|wtap_softc
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

