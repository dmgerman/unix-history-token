begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2007 Neterion, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  if_xge.h  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_XGE_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_XGE_H
end_define

begin_include
include|#
directive|include
file|<dev/nxge/include/xgehal.h>
end_include

begin_include
include|#
directive|include
file|<dev/nxge/xge-osdep.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|XGE_FEATURE_TSO
argument_list|)
operator|&&
operator|(
name|__FreeBSD_version
operator|<
literal|700026
operator|)
end_if

begin_undef
undef|#
directive|undef
name|XGE_FEATURE_TSO
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|XGE_FEATURE_LRO
argument_list|)
end_if

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|700047
end_if

begin_undef
undef|#
directive|undef
name|XGE_FEATURE_LRO
end_undef

begin_undef
undef|#
directive|undef
name|XGE_HAL_CONFIG_LRO
end_undef

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XGE_HAL_CONFIG_LRO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FUNC_PRINT
end_ifdef

begin_define
define|#
directive|define
name|ENTER_FUNCTION
value|xge_os_printf("Enter\t==>[%s]\n", __FUNCTION__);
end_define

begin_define
define|#
directive|define
name|LEAVE_FUNCTION
value|xge_os_printf("Leave\t<==[%s]\n", __FUNCTION__);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ENTER_FUNCTION
end_define

begin_define
define|#
directive|define
name|LEAVE_FUNCTION
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Printing description, Copyright */
end_comment

begin_define
define|#
directive|define
name|DRIVER_VERSION
value|XGELL_VERSION_MAJOR"."               \ 	                                 XGELL_VERSION_MINOR"."               \ 	                                 XGELL_VERSION_FIX"."                 \ 	                                 XGELL_VERSION_BUILD
end_define

begin_define
define|#
directive|define
name|COPYRIGHT_STRING
value|"Copyright(c) 2002-2007 Neterion Inc."
end_define

begin_define
define|#
directive|define
name|PRINT_COPYRIGHT
value|xge_os_printf("%s", COPYRIGHT_STRING)
end_define

begin_comment
comment|/* Printing */
end_comment

begin_define
define|#
directive|define
name|xge_trace
parameter_list|(
name|trace
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|xge_debug_ll(trace, fmt, ## args);
end_define

begin_define
define|#
directive|define
name|xge_ctrace
parameter_list|(
name|trace
parameter_list|,
name|fmt
modifier|...
parameter_list|)
value|xge_debug_ll(trace, fmt);
end_define

begin_define
define|#
directive|define
name|BUFALIGN
parameter_list|(
name|buffer_length
parameter_list|)
define|\
value|if((buffer_length % 128) != 0) {                                      \ 	    buffer_length += (128 - (buffer_length % 128));                   \ 	}
end_define

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|xge_malloc
parameter_list|(
name|unsigned
name|long
name|size
parameter_list|)
block|{
name|void
modifier|*
name|vaddr
init|=
name|malloc
argument_list|(
name|size
argument_list|,
name|M_DEVBUF
argument_list|,
name|M_NOWAIT
argument_list|)
decl_stmt|;
name|bzero
argument_list|(
name|vaddr
argument_list|,
name|size
argument_list|)
expr_stmt|;
return|return
name|vaddr
return|;
block|}
end_function

begin_define
define|#
directive|define
name|SINGLE_ALLOC
value|0
end_define

begin_define
define|#
directive|define
name|MULTI_ALLOC
value|1
end_define

begin_define
define|#
directive|define
name|SAVE
value|0
end_define

begin_define
define|#
directive|define
name|RESTORE
value|1
end_define

begin_define
define|#
directive|define
name|UP
value|1
end_define

begin_define
define|#
directive|define
name|DOWN
value|0
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_USER_HARDCODED
value|-1
end_define

begin_define
define|#
directive|define
name|MAX_MBUF_FRAGS
value|20
end_define

begin_comment
comment|/* Maximum number of fragments */
end_comment

begin_define
define|#
directive|define
name|MAX_SEGS
value|100
end_define

begin_comment
comment|/* Maximum number of segments  */
end_comment

begin_define
define|#
directive|define
name|XGELL_TX_LEVEL_LOW
value|16
end_define

begin_define
define|#
directive|define
name|XGE_RING_COUNT
value|XGE_HAL_MIN_RING_NUM
end_define

begin_define
define|#
directive|define
name|BUFFER_SIZE
value|20
end_define

begin_comment
comment|/* Default values to configuration parameters */
end_comment

begin_define
define|#
directive|define
name|XGE_DEFAULT_INITIAL_MTU
value|1500
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_LATENCY_TIMER
value|-1
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_MAX_SPLITS_TRANS
value|-1
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_MMRB_COUNT
value|-1
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_SHARED_SPLITS
value|0
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_ISR_POLLING_CNT
value|8
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_STATS_REFRESH_TIME_SEC
value|4
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_MAC_RMAC_BCAST_EN
value|1
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_MAC_TMAC_UTIL_PERIOD
value|5
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_MAC_RMAC_UTIL_PERIOD
value|5
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_MAC_RMAC_PAUSE_GEN_EN
value|1
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_MAC_RMAC_PAUSE_RCV_EN
value|1
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_MAC_RMAC_PAUSE_TIME
value|65535
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_MAC_MC_PAUSE_THRESHOLD_Q0Q3
value|187
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_MAC_MC_PAUSE_THRESHOLD_Q4Q7
value|187
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_FIFO_MEMBLOCK_SIZE
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_FIFO_RESERVE_THRESHOLD
value|0
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_FIFO_MAX_FRAGS
value|64
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_FIFO_QUEUE_INTR
value|0
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_FIFO_QUEUE_MAX
value|2048
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_FIFO_QUEUE_INITIAL
value|2048
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_FIFO_QUEUE_TTI_URANGE_A
value|5
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_FIFO_QUEUE_TTI_URANGE_B
value|10
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_FIFO_QUEUE_TTI_URANGE_C
value|20
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_FIFO_QUEUE_TTI_UFC_A
value|15
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_FIFO_QUEUE_TTI_UFC_B
value|30
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_FIFO_QUEUE_TTI_UFC_C
value|45
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_FIFO_QUEUE_TTI_UFC_D
value|60
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_FIFO_QUEUE_TTI_TIMER_CI_EN
value|1
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_FIFO_QUEUE_TTI_TIMER_AC_EN
value|1
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_FIFO_QUEUE_TTI_TIMER_VAL_US
value|8000
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_FIFO_ALIGNMENT_SIZE
value|sizeof(u64)
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_RING_MEMBLOCK_SIZE
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_RING_STRIP_VLAN_TAG
value|1
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_RING_QUEUE_MAX
value|16
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_RING_QUEUE_INITIAL
value|16
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_RING_QUEUE_DRAM_SIZE_MB
value|32
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_RING_QUEUE_INDICATE_MAX_PKTS
value|16
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_RING_QUEUE_BACKOFF_INTERVAL_US
value|1000
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_RING_QUEUE_RTI_URANGE_A
value|5
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_RING_QUEUE_RTI_URANGE_B
value|10
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_RING_QUEUE_RTI_URANGE_C
value|50
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_RING_QUEUE_RTI_UFC_A
value|1
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_RING_QUEUE_RTI_UFC_B
value|8
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_RING_QUEUE_RTI_UFC_C
value|16
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_RING_QUEUE_RTI_UFC_D
value|32
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_RING_QUEUE_RTI_TIMER_AC_EN
value|1
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_RING_QUEUE_RTI_TIMER_VAL_US
value|250
end_define

begin_comment
comment|/* Values to identify the requests from getinfo tool in ioctl */
end_comment

begin_define
define|#
directive|define
name|XGE_QUERY_STATS
value|1
end_define

begin_define
define|#
directive|define
name|XGE_QUERY_PCICONF
value|2
end_define

begin_define
define|#
directive|define
name|XGE_QUERY_INTRSTATS
value|3
end_define

begin_define
define|#
directive|define
name|XGE_QUERY_DEVCONF
value|4
end_define

begin_define
define|#
directive|define
name|XGE_READ_VERSION
value|5
end_define

begin_define
define|#
directive|define
name|XGE_QUERY_TCODE
value|6
end_define

begin_define
define|#
directive|define
name|XGE_SET_BUFFER_MODE_1
value|7
end_define

begin_define
define|#
directive|define
name|XGE_SET_BUFFER_MODE_2
value|8
end_define

begin_define
define|#
directive|define
name|XGE_SET_BUFFER_MODE_3
value|9
end_define

begin_define
define|#
directive|define
name|XGE_SET_BUFFER_MODE_5
value|10
end_define

begin_define
define|#
directive|define
name|XGE_QUERY_BUFFER_MODE
value|11
end_define

begin_define
define|#
directive|define
name|XGE_OFFSET_OF_LAST_REG
value|0x3180
end_define

begin_define
define|#
directive|define
name|VENDOR_ID_AMD
value|0x1022
end_define

begin_define
define|#
directive|define
name|DEVICE_ID_8131_PCI_BRIDGE
value|0x7450
end_define

begin_typedef
typedef|typedef
name|struct
name|mbuf
modifier|*
name|mbuf_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|xgell_event_e
block|{
name|XGE_LL_EVENT_TRY_XMIT_AGAIN
init|=
name|XGE_LL_EVENT_BASE
operator|+
literal|1
block|,
name|XGE_LL_EVENT_DEVICE_RESETTING
init|=
name|XGE_LL_EVENT_BASE
operator|+
literal|2
block|, }
name|xgell_event_e
typedef|;
end_typedef

begin_comment
comment|/* Adapter structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xgelldev
block|{
name|device_t
name|device
decl_stmt|;
comment|/* Device                        */
name|struct
name|ifnet
modifier|*
name|ifnetp
decl_stmt|;
comment|/* Interface ifnet structure     */
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
comment|/* Resource structure for IRQ    */
name|void
modifier|*
name|irqhandle
decl_stmt|;
comment|/* IRQ handle                    */
name|pci_info_t
modifier|*
name|pdev
decl_stmt|;
name|struct
name|ifmedia
name|xge_media
decl_stmt|;
comment|/* In-kernel representation of a */
comment|/* single supported media type   */
name|xge_hal_device_t
modifier|*
name|devh
decl_stmt|;
comment|/* HAL: Device Handle            */
name|xge_hal_channel_h
name|ring_channel
index|[
name|XGE_HAL_MAX_FIFO_NUM
index|]
decl_stmt|;
comment|/* Ring channel                  */
name|xge_hal_channel_h
name|fifo_channel_0
decl_stmt|;
comment|/* FIFO channel                  */
name|struct
name|mtx
name|xge_lock
decl_stmt|;
comment|/* Mutex - Default               */
name|struct
name|callout
name|timer
decl_stmt|;
comment|/* Timer for polling             */
name|struct
name|xge_hal_stats_hw_info_t
modifier|*
name|hwstats
decl_stmt|;
comment|/* Hardware Statistics       */
name|int
name|saved_regs
index|[
literal|16
index|]
decl_stmt|;
comment|/* To save register space        */
name|int
name|xge_mtu
decl_stmt|;
comment|/* MTU                           */
name|int
name|initialized
decl_stmt|;
comment|/* Flag: Initialized or not      */
name|bus_dma_tag_t
name|dma_tag_tx
decl_stmt|;
comment|/* Tag for dtr dma mapping (Tx)  */
name|bus_dma_tag_t
name|dma_tag_rx
decl_stmt|;
comment|/* Tag for dtr dma mapping (Rx)  */
name|int
name|all_multicast
decl_stmt|;
comment|/* All multicast flag            */
name|int
name|macaddr_count
decl_stmt|;
comment|/* Multicast address count       */
name|int
name|in_detach
decl_stmt|;
comment|/* To avoid ioctl during detach  */
name|int
name|buffer_mode
decl_stmt|;
comment|/* Buffer Mode                   */
name|int
name|rxd_mbuf_cnt
decl_stmt|;
comment|/* Number of buffers used        */
name|int
name|rxd_mbuf_len
index|[
literal|5
index|]
decl_stmt|;
comment|/* Buffer lengths                */
block|}
name|xgelldev_t
typedef|;
end_typedef

begin_comment
comment|/* Rx descriptor private structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|mbuf_t
modifier|*
name|bufferArray
decl_stmt|;
name|struct
name|xge_dma_mbuf
name|dmainfo
index|[
literal|5
index|]
decl_stmt|;
block|}
name|xgell_rx_priv_t
typedef|;
end_typedef

begin_comment
comment|/* Tx descriptor private structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|mbuf_t
name|buffer
decl_stmt|;
name|bus_dmamap_t
name|dma_map
decl_stmt|;
block|}
name|xgell_tx_priv_t
typedef|;
end_typedef

begin_comment
comment|/* BAR0 Register */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|barregister
block|{
name|char
name|option
index|[
literal|2
index|]
decl_stmt|;
name|u64
name|offset
decl_stmt|;
name|u64
name|value
decl_stmt|;
block|}
name|bar0reg_t
typedef|;
end_typedef

begin_function_decl
name|void
name|xge_init_params
parameter_list|(
name|xge_hal_device_config_t
modifier|*
name|dconfig
parameter_list|,
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_init
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_init_locked
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_stop
parameter_list|(
name|xgelldev_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freeResources
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xgell_callback_link_up
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xgell_callback_link_down
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xgell_callback_crit_err
parameter_list|(
name|void
modifier|*
parameter_list|,
name|xge_hal_event_e
parameter_list|,
name|u64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xgell_callback_event
parameter_list|(
name|xge_queue_item_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xge_ifmedia_change
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_ifmedia_status
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|ifmediareq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xge_ioctl
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_timer
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xge_intr_filter
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xgell_rx_open
parameter_list|(
name|int
parameter_list|,
name|xgelldev_t
modifier|*
parameter_list|,
name|xge_hal_channel_reopen_e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xgell_tx_open
parameter_list|(
name|xgelldev_t
modifier|*
parameter_list|,
name|xge_hal_channel_reopen_e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xgell_channel_close
parameter_list|(
name|xgelldev_t
modifier|*
parameter_list|,
name|xge_hal_channel_reopen_e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xgell_channel_open
parameter_list|(
name|xgelldev_t
modifier|*
parameter_list|,
name|xge_hal_channel_reopen_e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xge_hal_status_e
name|xgell_rx_compl
parameter_list|(
name|xge_hal_channel_h
parameter_list|,
name|xge_hal_dtr_h
parameter_list|,
name|u8
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xge_hal_status_e
name|xgell_tx_compl
parameter_list|(
name|xge_hal_channel_h
parameter_list|,
name|xge_hal_dtr_h
parameter_list|,
name|u8
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xge_hal_status_e
name|xgell_tx_initial_replenish
parameter_list|(
name|xge_hal_channel_h
parameter_list|,
name|xge_hal_dtr_h
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|xge_hal_channel_reopen_e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xge_hal_status_e
name|xgell_rx_initial_replenish
parameter_list|(
name|xge_hal_channel_h
parameter_list|,
name|xge_hal_dtr_h
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|xge_hal_channel_reopen_e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xgell_rx_term
parameter_list|(
name|xge_hal_channel_h
parameter_list|,
name|xge_hal_dtr_h
parameter_list|,
name|xge_hal_dtr_state_e
parameter_list|,
name|void
modifier|*
parameter_list|,
name|xge_hal_channel_reopen_e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xgell_tx_term
parameter_list|(
name|xge_hal_channel_h
parameter_list|,
name|xge_hal_dtr_h
parameter_list|,
name|xge_hal_dtr_state_e
parameter_list|,
name|void
modifier|*
parameter_list|,
name|xge_hal_channel_reopen_e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xgell_set_mbuf_cflags
parameter_list|(
name|mbuf_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_send
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_send_locked
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xgell_get_multimode_normalbuf
parameter_list|(
name|xge_hal_dtr_h
name|dtrh
parameter_list|,
name|xgell_rx_priv_t
modifier|*
name|rxd_priv
parameter_list|,
name|xgelldev_t
modifier|*
name|lldev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xgell_get_multimode_jumbobuf
parameter_list|(
name|xge_hal_dtr_h
name|dtrh
parameter_list|,
name|xgell_rx_priv_t
modifier|*
name|rxd_priv
parameter_list|,
name|xgelldev_t
modifier|*
name|lldev
parameter_list|,
name|int
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xgell_get_second_buffer
parameter_list|(
name|xgell_rx_priv_t
modifier|*
name|rxd_priv
parameter_list|,
name|xgelldev_t
modifier|*
name|lldev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xgell_get_buf
parameter_list|(
name|xge_hal_dtr_h
name|dtrh
parameter_list|,
name|xgell_rx_priv_t
modifier|*
name|rxd_priv
parameter_list|,
name|xgelldev_t
modifier|*
name|lldev
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xge_ring_dtr_get
parameter_list|(
name|mbuf_t
name|mbuf_up
parameter_list|,
name|xge_hal_channel_h
name|channelh
parameter_list|,
name|xge_hal_dtr_h
name|dtr
parameter_list|,
name|xgelldev_t
modifier|*
name|lldev
parameter_list|,
name|xgell_rx_priv_t
modifier|*
name|rxd_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xgell_get_buf_3b_5b
parameter_list|(
name|xge_hal_dtr_h
name|dtrh
parameter_list|,
name|xgell_rx_priv_t
modifier|*
name|rxd_priv
parameter_list|,
name|xgelldev_t
modifier|*
name|lldev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dmamap_cb
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_dma_segment_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xgell_reset
parameter_list|(
name|xgelldev_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_setmulti
parameter_list|(
name|xgelldev_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_enable_promisc
parameter_list|(
name|xgelldev_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_disable_promisc
parameter_list|(
name|xgelldev_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|changeMtu
parameter_list|(
name|xgelldev_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|changeBufmode
parameter_list|(
name|xgelldev_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_initialize
parameter_list|(
name|device_t
parameter_list|,
name|xge_hal_channel_reopen_e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_terminate
parameter_list|(
name|device_t
parameter_list|,
name|xge_hal_channel_reopen_e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_up_locked
parameter_list|(
name|xgelldev_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_down_locked
parameter_list|(
name|xgelldev_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xge_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xge_driver_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_media_init
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_pci_space_save
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_pci_space_restore
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xge_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xge_interface_setup
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xge_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xge_shutdown
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xge_suspend
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xge_resume
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _IF_XGE_H
end_comment

end_unit

