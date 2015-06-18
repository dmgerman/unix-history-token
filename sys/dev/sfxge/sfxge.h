begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010-2015 Solarflare Communications Inc.  * All rights reserved.  *  * This software was developed in part by Philip Paeps under contract for  * Solarflare Communications, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * 1. Redistributions of source code must retain the above copyright notice,  *    this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright notice,  *    this list of conditions and the following disclaimer in the documentation  *    and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * The views and conclusions contained in the software and documentation are  * those of the authors and should not be interpreted as representing official  * policies, either expressed or implied, of the FreeBSD Project.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SFXGE_H
end_ifndef

begin_define
define|#
directive|define
name|_SFXGE_H
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
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
file|<sys/sx.h>
end_include

begin_include
include|#
directive|include
file|<vm/uma.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
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
file|"sfxge_ioc.h"
end_include

begin_comment
comment|/*  * Debugging  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|DBGPRINT
parameter_list|(
name|dev
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|device_printf(dev, "%s: " fmt "\n", __func__, ## args)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DBGPRINT
parameter_list|(
name|dev
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Backward-compatibility  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CACHE_LINE_SIZE
end_ifndef

begin_comment
comment|/* This should be right on most machines the driver will be used on, and  * we needn't care too much about wasting a few KB per interface.  */
end_comment

begin_define
define|#
directive|define
name|CACHE_LINE_SIZE
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IFCAP_LINKSTATE
end_ifndef

begin_define
define|#
directive|define
name|IFCAP_LINKSTATE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IFCAP_VLAN_HWTSO
end_ifndef

begin_define
define|#
directive|define
name|IFCAP_VLAN_HWTSO
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IFM_10G_T
end_ifndef

begin_define
define|#
directive|define
name|IFM_10G_T
value|IFM_UNKNOWN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IFM_10G_KX4
end_ifndef

begin_define
define|#
directive|define
name|IFM_10G_KX4
value|IFM_10G_CX4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IFM_40G_CR4
end_ifndef

begin_define
define|#
directive|define
name|IFM_40G_CR4
value|IFM_UNKNOWN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|800501
operator|&&
name|__FreeBSD_version
operator|<
literal|900000
operator|)
operator|||
expr|\
name|__FreeBSD_version
operator|>=
literal|900003
end_if

begin_define
define|#
directive|define
name|SFXGE_HAVE_DESCRIBE_INTR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IFM_ETH_RXPAUSE
end_ifdef

begin_define
define|#
directive|define
name|SFXGE_HAVE_PAUSE_MEDIAOPTS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CTLTYPE_U64
end_ifndef

begin_define
define|#
directive|define
name|CTLTYPE_U64
value|CTLTYPE_QUAD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sfxge_rx.h"
end_include

begin_include
include|#
directive|include
file|"sfxge_tx.h"
end_include

begin_define
define|#
directive|define
name|ROUNDUP_POW_OF_TWO
parameter_list|(
name|_n
parameter_list|)
value|(1ULL<< flsl((_n) - 1))
end_define

begin_define
define|#
directive|define
name|SFXGE_IP_ALIGN
value|2
end_define

begin_define
define|#
directive|define
name|SFXGE_ETHERTYPE_LOOPBACK
value|0x9000
end_define

begin_comment
comment|/* Xerox loopback */
end_comment

begin_enum
enum|enum
name|sfxge_evq_state
block|{
name|SFXGE_EVQ_UNINITIALIZED
init|=
literal|0
block|,
name|SFXGE_EVQ_INITIALIZED
block|,
name|SFXGE_EVQ_STARTING
block|,
name|SFXGE_EVQ_STARTED
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|SFXGE_EV_BATCH
value|16384
end_define

begin_struct
struct|struct
name|sfxge_evq
block|{
comment|/* Structure members below are sorted by usage order */
name|struct
name|sfxge_softc
modifier|*
name|sc
decl_stmt|;
name|struct
name|mtx
name|lock
decl_stmt|;
name|unsigned
name|int
name|index
decl_stmt|;
name|enum
name|sfxge_evq_state
name|init_state
decl_stmt|;
name|efsys_mem_t
name|mem
decl_stmt|;
name|efx_evq_t
modifier|*
name|common
decl_stmt|;
name|unsigned
name|int
name|read_ptr
decl_stmt|;
name|boolean_t
name|exception
decl_stmt|;
name|unsigned
name|int
name|rx_done
decl_stmt|;
name|unsigned
name|int
name|tx_done
decl_stmt|;
comment|/* Linked list of TX queues with completions to process */
name|struct
name|sfxge_txq
modifier|*
name|txq
decl_stmt|;
name|struct
name|sfxge_txq
modifier|*
modifier|*
name|txqs
decl_stmt|;
comment|/* Structure members not used on event processing path */
name|unsigned
name|int
name|buf_base_id
decl_stmt|;
name|unsigned
name|int
name|entries
decl_stmt|;
name|char
name|lock_name
index|[
name|SFXGE_LOCK_NAME_MAX
index|]
decl_stmt|;
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
name|SFXGE_NDESCS
value|1024
end_define

begin_define
define|#
directive|define
name|SFXGE_MODERATION
value|30
end_define

begin_enum
enum|enum
name|sfxge_intr_state
block|{
name|SFXGE_INTR_UNINITIALIZED
init|=
literal|0
block|,
name|SFXGE_INTR_INITIALIZED
block|,
name|SFXGE_INTR_TESTING
block|,
name|SFXGE_INTR_STARTED
block|}
enum|;
end_enum

begin_struct
struct|struct
name|sfxge_intr_hdl
block|{
name|int
name|eih_rid
decl_stmt|;
name|void
modifier|*
name|eih_tag
decl_stmt|;
name|struct
name|resource
modifier|*
name|eih_res
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sfxge_intr
block|{
name|enum
name|sfxge_intr_state
name|state
decl_stmt|;
name|struct
name|resource
modifier|*
name|msix_res
decl_stmt|;
name|struct
name|sfxge_intr_hdl
modifier|*
name|table
decl_stmt|;
name|int
name|n_alloc
decl_stmt|;
name|int
name|type
decl_stmt|;
name|efsys_mem_t
name|status
decl_stmt|;
name|uint32_t
name|zero_count
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|sfxge_mcdi_state
block|{
name|SFXGE_MCDI_UNINITIALIZED
init|=
literal|0
block|,
name|SFXGE_MCDI_INITIALIZED
block|,
name|SFXGE_MCDI_BUSY
block|,
name|SFXGE_MCDI_COMPLETED
block|}
enum|;
end_enum

begin_struct
struct|struct
name|sfxge_mcdi
block|{
name|struct
name|mtx
name|lock
decl_stmt|;
name|efsys_mem_t
name|mem
decl_stmt|;
name|enum
name|sfxge_mcdi_state
name|state
decl_stmt|;
name|efx_mcdi_transport_t
name|transport
decl_stmt|;
comment|/* Only used in debugging output */
name|char
name|lock_name
index|[
name|SFXGE_LOCK_NAME_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sfxge_hw_stats
block|{
name|clock_t
name|update_time
decl_stmt|;
name|efsys_mem_t
name|dma_buf
decl_stmt|;
name|void
modifier|*
name|decode_buf
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|sfxge_port_state
block|{
name|SFXGE_PORT_UNINITIALIZED
init|=
literal|0
block|,
name|SFXGE_PORT_INITIALIZED
block|,
name|SFXGE_PORT_STARTED
block|}
enum|;
end_enum

begin_struct
struct|struct
name|sfxge_port
block|{
name|struct
name|sfxge_softc
modifier|*
name|sc
decl_stmt|;
name|struct
name|mtx
name|lock
decl_stmt|;
name|enum
name|sfxge_port_state
name|init_state
decl_stmt|;
ifndef|#
directive|ifndef
name|SFXGE_HAVE_PAUSE_MEDIAOPTS
name|unsigned
name|int
name|wanted_fc
decl_stmt|;
endif|#
directive|endif
name|struct
name|sfxge_hw_stats
name|phy_stats
decl_stmt|;
name|struct
name|sfxge_hw_stats
name|mac_stats
decl_stmt|;
name|efx_link_mode_t
name|link_mode
decl_stmt|;
name|uint8_t
name|mcast_addrs
index|[
name|EFX_MAC_MULTICAST_LIST_MAX
operator|*
name|EFX_MAC_ADDR_LEN
index|]
decl_stmt|;
name|unsigned
name|int
name|mcast_count
decl_stmt|;
comment|/* Only used in debugging output */
name|char
name|lock_name
index|[
name|SFXGE_LOCK_NAME_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|sfxge_softc_state
block|{
name|SFXGE_UNINITIALIZED
init|=
literal|0
block|,
name|SFXGE_INITIALIZED
block|,
name|SFXGE_REGISTERED
block|,
name|SFXGE_STARTED
block|}
enum|;
end_enum

begin_struct
struct|struct
name|sfxge_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|struct
name|sx
name|softc_lock
decl_stmt|;
name|char
name|softc_lock_name
index|[
name|SFXGE_LOCK_NAME_MAX
index|]
decl_stmt|;
name|enum
name|sfxge_softc_state
name|init_state
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifnet
decl_stmt|;
name|unsigned
name|int
name|if_flags
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|stats_node
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|txqs_node
decl_stmt|;
name|struct
name|task
name|task_reset
decl_stmt|;
name|efx_family_t
name|family
decl_stmt|;
name|caddr_t
name|vpd_data
decl_stmt|;
name|size_t
name|vpd_size
decl_stmt|;
name|efx_nic_t
modifier|*
name|enp
decl_stmt|;
name|efsys_lock_t
name|enp_lock
decl_stmt|;
name|unsigned
name|int
name|rxq_entries
decl_stmt|;
name|unsigned
name|int
name|txq_entries
decl_stmt|;
name|bus_dma_tag_t
name|parent_dma_tag
decl_stmt|;
name|efsys_bar_t
name|bar
decl_stmt|;
name|struct
name|sfxge_intr
name|intr
decl_stmt|;
name|struct
name|sfxge_mcdi
name|mcdi
decl_stmt|;
name|struct
name|sfxge_port
name|port
decl_stmt|;
name|uint32_t
name|buffer_table_next
decl_stmt|;
name|struct
name|sfxge_evq
modifier|*
name|evq
index|[
name|SFXGE_RX_SCALE_MAX
index|]
decl_stmt|;
name|unsigned
name|int
name|ev_moderation
decl_stmt|;
if|#
directive|if
name|EFSYS_OPT_QSTATS
name|clock_t
name|ev_stats_update_time
decl_stmt|;
name|uint64_t
name|ev_stats
index|[
name|EV_NQSTATS
index|]
decl_stmt|;
endif|#
directive|endif
name|unsigned
name|int
name|max_rss_channels
decl_stmt|;
name|uma_zone_t
name|rxq_cache
decl_stmt|;
name|struct
name|sfxge_rxq
modifier|*
name|rxq
index|[
name|SFXGE_RX_SCALE_MAX
index|]
decl_stmt|;
name|unsigned
name|int
name|rx_indir_table
index|[
name|SFXGE_RX_SCALE_MAX
index|]
decl_stmt|;
name|struct
name|sfxge_txq
modifier|*
name|txq
index|[
name|SFXGE_TXQ_NTYPES
operator|+
name|SFXGE_RX_SCALE_MAX
index|]
decl_stmt|;
name|struct
name|ifmedia
name|media
decl_stmt|;
name|size_t
name|rx_prefix_size
decl_stmt|;
name|size_t
name|rx_buffer_size
decl_stmt|;
name|size_t
name|rx_buffer_align
decl_stmt|;
name|uma_zone_t
name|rx_buffer_zone
decl_stmt|;
name|unsigned
name|int
name|evq_max
decl_stmt|;
name|unsigned
name|int
name|evq_count
decl_stmt|;
name|unsigned
name|int
name|rxq_count
decl_stmt|;
name|unsigned
name|int
name|txq_count
decl_stmt|;
name|int
name|tso_fw_assisted
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SFXGE_LINK_UP
parameter_list|(
name|sc
parameter_list|)
value|((sc)->port.link_mode != EFX_LINK_DOWN)
end_define

begin_define
define|#
directive|define
name|SFXGE_RUNNING
parameter_list|(
name|sc
parameter_list|)
value|((sc)->ifnet->if_drv_flags& IFF_DRV_RUNNING)
end_define

begin_define
define|#
directive|define
name|SFXGE_PARAM
parameter_list|(
name|_name
parameter_list|)
value|"hw.sfxge." #_name
end_define

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_hw_sfxge
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * From sfxge.c.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|sfxge_schedule_reset
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sfxge_sram_buf_tbl_alloc
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|,
name|size_t
name|n
parameter_list|,
name|uint32_t
modifier|*
name|idp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * From sfxge_dma.c.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|sfxge_dma_init
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sfxge_dma_fini
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sfxge_dma_alloc
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|,
name|bus_size_t
name|len
parameter_list|,
name|efsys_mem_t
modifier|*
name|esmp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sfxge_dma_free
parameter_list|(
name|efsys_mem_t
modifier|*
name|esmp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sfxge_dma_map_sg_collapse
parameter_list|(
name|bus_dma_tag_t
name|tag
parameter_list|,
name|bus_dmamap_t
name|map
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mp
parameter_list|,
name|bus_dma_segment_t
modifier|*
name|segs
parameter_list|,
name|int
modifier|*
name|nsegs
parameter_list|,
name|int
name|maxsegs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * From sfxge_ev.c.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|sfxge_ev_init
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sfxge_ev_fini
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sfxge_ev_start
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sfxge_ev_stop
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sfxge_ev_qpoll
parameter_list|(
name|struct
name|sfxge_evq
modifier|*
name|evq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * From sfxge_intr.c.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|sfxge_intr_init
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sfxge_intr_fini
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sfxge_intr_start
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sfxge_intr_stop
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * From sfxge_mcdi.c.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|sfxge_mcdi_init
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sfxge_mcdi_fini
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sfxge_mcdi_ioctl
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|,
name|sfxge_ioc_t
modifier|*
name|ip
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * From sfxge_nvram.c.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|sfxge_nvram_ioctl
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|,
name|sfxge_ioc_t
modifier|*
name|ip
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * From sfxge_port.c.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|sfxge_port_init
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sfxge_port_fini
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sfxge_port_start
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sfxge_port_stop
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sfxge_mac_link_update
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|,
name|efx_link_mode_t
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sfxge_mac_filter_set
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sfxge_port_ifmedia_init
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SFXGE_MAX_MTU
value|(9 * 1024)
end_define

begin_define
define|#
directive|define
name|SFXGE_ADAPTER_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|,
name|_ifname
parameter_list|)
define|\
value|do {								\ 		struct sfxge_softc *__sc = (_sc);			\ 									\ 		snprintf((__sc)->softc_lock_name,			\ 			 sizeof((__sc)->softc_lock_name),		\ 			 "%s:softc", (_ifname));			\ 		sx_init(&(__sc)->softc_lock, (__sc)->softc_lock_name);	\ 	} while (B_FALSE)
end_define

begin_define
define|#
directive|define
name|SFXGE_ADAPTER_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
define|\
value|sx_destroy(&(_sc)->softc_lock)
end_define

begin_define
define|#
directive|define
name|SFXGE_ADAPTER_LOCK
parameter_list|(
name|_sc
parameter_list|)
define|\
value|sx_xlock(&(_sc)->softc_lock)
end_define

begin_define
define|#
directive|define
name|SFXGE_ADAPTER_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
define|\
value|sx_xunlock(&(_sc)->softc_lock)
end_define

begin_define
define|#
directive|define
name|SFXGE_ADAPTER_LOCK_ASSERT_OWNED
parameter_list|(
name|_sc
parameter_list|)
define|\
value|sx_assert(&(_sc)->softc_lock, LA_XLOCKED)
end_define

begin_define
define|#
directive|define
name|SFXGE_PORT_LOCK_INIT
parameter_list|(
name|_port
parameter_list|,
name|_ifname
parameter_list|)
define|\
value|do {								\ 		struct sfxge_port *__port = (_port);			\ 									\ 		snprintf((__port)->lock_name,				\ 			 sizeof((__port)->lock_name),			\ 			 "%s:port", (_ifname));				\ 		mtx_init(&(__port)->lock, (__port)->lock_name,		\ 			 NULL, MTX_DEF);				\ 	} while (B_FALSE)
end_define

begin_define
define|#
directive|define
name|SFXGE_PORT_LOCK_DESTROY
parameter_list|(
name|_port
parameter_list|)
define|\
value|mtx_destroy(&(_port)->lock)
end_define

begin_define
define|#
directive|define
name|SFXGE_PORT_LOCK
parameter_list|(
name|_port
parameter_list|)
define|\
value|mtx_lock(&(_port)->lock)
end_define

begin_define
define|#
directive|define
name|SFXGE_PORT_UNLOCK
parameter_list|(
name|_port
parameter_list|)
define|\
value|mtx_unlock(&(_port)->lock)
end_define

begin_define
define|#
directive|define
name|SFXGE_PORT_LOCK_ASSERT_OWNED
parameter_list|(
name|_port
parameter_list|)
define|\
value|mtx_assert(&(_port)->lock, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|SFXGE_MCDI_LOCK_INIT
parameter_list|(
name|_mcdi
parameter_list|,
name|_ifname
parameter_list|)
define|\
value|do {								\ 		struct sfxge_mcdi  *__mcdi = (_mcdi);			\ 									\ 		snprintf((__mcdi)->lock_name,				\ 			 sizeof((__mcdi)->lock_name),			\ 			 "%s:mcdi", (_ifname));				\ 		mtx_init(&(__mcdi)->lock, (__mcdi)->lock_name,		\ 			 NULL, MTX_DEF);				\ 	} while (B_FALSE)
end_define

begin_define
define|#
directive|define
name|SFXGE_MCDI_LOCK_DESTROY
parameter_list|(
name|_mcdi
parameter_list|)
define|\
value|mtx_destroy(&(_mcdi)->lock)
end_define

begin_define
define|#
directive|define
name|SFXGE_MCDI_LOCK
parameter_list|(
name|_mcdi
parameter_list|)
define|\
value|mtx_lock(&(_mcdi)->lock)
end_define

begin_define
define|#
directive|define
name|SFXGE_MCDI_UNLOCK
parameter_list|(
name|_mcdi
parameter_list|)
define|\
value|mtx_unlock(&(_mcdi)->lock)
end_define

begin_define
define|#
directive|define
name|SFXGE_MCDI_LOCK_ASSERT_OWNED
parameter_list|(
name|_mcdi
parameter_list|)
define|\
value|mtx_assert(&(_mcdi)->lock, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|SFXGE_EVQ_LOCK_INIT
parameter_list|(
name|_evq
parameter_list|,
name|_ifname
parameter_list|,
name|_evq_index
parameter_list|)
define|\
value|do {								\ 		struct sfxge_evq  *__evq = (_evq);			\ 									\ 		snprintf((__evq)->lock_name,				\ 			 sizeof((__evq)->lock_name),			\ 			 "%s:evq%u", (_ifname), (_evq_index));		\ 		mtx_init(&(__evq)->lock, (__evq)->lock_name,		\ 			 NULL, MTX_DEF);				\ 	} while (B_FALSE)
end_define

begin_define
define|#
directive|define
name|SFXGE_EVQ_LOCK_DESTROY
parameter_list|(
name|_evq
parameter_list|)
define|\
value|mtx_destroy(&(_evq)->lock)
end_define

begin_define
define|#
directive|define
name|SFXGE_EVQ_LOCK
parameter_list|(
name|_evq
parameter_list|)
define|\
value|mtx_lock(&(_evq)->lock)
end_define

begin_define
define|#
directive|define
name|SFXGE_EVQ_UNLOCK
parameter_list|(
name|_evq
parameter_list|)
define|\
value|mtx_unlock(&(_evq)->lock)
end_define

begin_define
define|#
directive|define
name|SFXGE_EVQ_LOCK_ASSERT_OWNED
parameter_list|(
name|_evq
parameter_list|)
define|\
value|mtx_assert(&(_evq)->lock, MA_OWNED)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SFXGE_H */
end_comment

end_unit

