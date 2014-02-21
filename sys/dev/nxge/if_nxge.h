begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2007 Neterion, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_comment
comment|/* Printing description, Copyright */
end_comment

begin_define
define|#
directive|define
name|XGE_DRIVER_VERSION
define|\
value|XGELL_VERSION_MAJOR"."XGELL_VERSION_MINOR"."                           \ 	XGELL_VERSION_FIX"."XGELL_VERSION_BUILD
end_define

begin_define
define|#
directive|define
name|XGE_COPYRIGHT
value|"Copyright(c) 2002-2007 Neterion Inc."
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
name|XGE_ALIGN_TO
parameter_list|(
name|buffer_length
parameter_list|,
name|to
parameter_list|)
value|{                                      \ 	if((buffer_length % to) != 0) {                                        \ 	    buffer_length += (to - (buffer_length % to));                      \ 	}                                                                      \ }
end_define

begin_define
define|#
directive|define
name|XGE_EXIT_ON_ERR
parameter_list|(
name|text
parameter_list|,
name|label
parameter_list|,
name|return_value
parameter_list|)
value|{                           \ 	xge_trace(XGE_ERR, "%s (Status: %d)", text, return_value);             \ 	status = return_value;                                                 \ 	goto label;                                                            \ }
end_define

begin_define
define|#
directive|define
name|XGE_SET_BUFFER_MODE_IN_RINGS
parameter_list|(
name|mode
parameter_list|)
value|{                                   \ 	for(index = 0; index< XGE_RING_COUNT; index++)                        \ 	    ring_config->queue[index].buffer_mode = mode;                      \ }
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
name|XGE_MAX_SEGS
value|100
end_define

begin_comment
comment|/* Maximum number of segments  */
end_comment

begin_define
define|#
directive|define
name|XGE_TX_LEVEL_LOW
value|16
end_define

begin_define
define|#
directive|define
name|XGE_FIFO_COUNT
value|XGE_HAL_MIN_FIFO_NUM
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
name|XGE_BUFFER_SIZE
value|20
end_define

begin_define
define|#
directive|define
name|XGE_LRO_DEFAULT_ENTRIES
value|12
end_define

begin_define
define|#
directive|define
name|XGE_BAUDRATE
value|1000000000
end_define

begin_comment
comment|/* Default values to configuration parameters */
end_comment

begin_define
define|#
directive|define
name|XGE_DEFAULT_ENABLED_TSO
value|1
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_ENABLED_LRO
value|1
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_ENABLED_MSI
value|1
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_BUFFER_MODE
value|1
end_define

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

begin_define
define|#
directive|define
name|XGE_DRV_STATS
parameter_list|(
name|param
parameter_list|)
value|(lldev->driver_stats.param++)
end_define

begin_define
define|#
directive|define
name|XGE_SAVE_PARAM
parameter_list|(
name|to
parameter_list|,
name|what
parameter_list|,
name|value
parameter_list|)
value|to.what = value;
end_define

begin_define
define|#
directive|define
name|XGE_GET_PARAM
parameter_list|(
name|str_kenv
parameter_list|,
name|to
parameter_list|,
name|param
parameter_list|,
name|hardcode
parameter_list|)
value|{                         \ 	static int param##__LINE__;                                            \ 	if(testenv(str_kenv) == 1) {                                           \ 	    getenv_int(str_kenv,&param##__LINE__);                            \ 	}                                                                      \ 	else {                                                                 \ 	    param##__LINE__ = hardcode;                                        \ 	}                                                                      \ 	XGE_SAVE_PARAM(to, param, param##__LINE__);                            \ }
end_define

begin_define
define|#
directive|define
name|XGE_GET_PARAM_MAC
parameter_list|(
name|str_kenv
parameter_list|,
name|param
parameter_list|,
name|hardcode
parameter_list|)
define|\
value|XGE_GET_PARAM(str_kenv, ((*dconfig).mac), param, hardcode);
end_define

begin_define
define|#
directive|define
name|XGE_GET_PARAM_FIFO
parameter_list|(
name|str_kenv
parameter_list|,
name|param
parameter_list|,
name|hardcode
parameter_list|)
define|\
value|XGE_GET_PARAM(str_kenv, ((*dconfig).fifo), param, hardcode);
end_define

begin_define
define|#
directive|define
name|XGE_GET_PARAM_FIFO_QUEUE
parameter_list|(
name|str_kenv
parameter_list|,
name|param
parameter_list|,
name|qindex
parameter_list|,
name|hardcode
parameter_list|)
define|\
value|XGE_GET_PARAM(str_kenv, ((*dconfig).fifo.queue[qindex]), param,        \ 	    hardcode);
end_define

begin_define
define|#
directive|define
name|XGE_GET_PARAM_FIFO_QUEUE_TTI
parameter_list|(
name|str_kenv
parameter_list|,
name|param
parameter_list|,
name|qindex
parameter_list|,
name|tindex
parameter_list|,
name|hardcode
parameter_list|)
define|\
value|XGE_GET_PARAM(str_kenv, ((*dconfig).fifo.queue[qindex].tti[tindex]),   \ 	    param, hardcode);
end_define

begin_define
define|#
directive|define
name|XGE_GET_PARAM_RING
parameter_list|(
name|str_kenv
parameter_list|,
name|param
parameter_list|,
name|hardcode
parameter_list|)
define|\
value|XGE_GET_PARAM(str_kenv, ((*dconfig).ring), param, hardcode);
end_define

begin_define
define|#
directive|define
name|XGE_GET_PARAM_RING_QUEUE
parameter_list|(
name|str_kenv
parameter_list|,
name|param
parameter_list|,
name|qindex
parameter_list|,
name|hardcode
parameter_list|)
define|\
value|XGE_GET_PARAM(str_kenv, ((*dconfig).ring.queue[qindex]), param,        \ 	    hardcode);
end_define

begin_define
define|#
directive|define
name|XGE_GET_PARAM_RING_QUEUE_RTI
parameter_list|(
name|str_kenv
parameter_list|,
name|param
parameter_list|,
name|qindex
parameter_list|,
name|hardcode
parameter_list|)
define|\
value|XGE_GET_PARAM(str_kenv, ((*dconfig).ring.queue[qindex].rti), param,    \ 	    hardcode);
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
name|XGE_QUERY_DEVSTATS
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
name|XGE_QUERY_SWSTATS
value|6
end_define

begin_define
define|#
directive|define
name|XGE_QUERY_DRIVERSTATS
value|7
end_define

begin_define
define|#
directive|define
name|XGE_SET_BUFFER_MODE_1
value|8
end_define

begin_define
define|#
directive|define
name|XGE_SET_BUFFER_MODE_2
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
name|xge_lables
block|{
name|xge_free_all
init|=
literal|0
block|,
name|xge_free_mutex
init|=
literal|1
block|,
name|xge_free_terminate_hal_driver
init|=
literal|2
block|,
name|xge_free_hal_device
init|=
literal|3
block|,
name|xge_free_pci_info
init|=
literal|4
block|,
name|xge_free_bar0
init|=
literal|5
block|,
name|xge_free_bar0_resource
init|=
literal|6
block|,
name|xge_free_bar1
init|=
literal|7
block|,
name|xge_free_bar1_resource
init|=
literal|8
block|,
name|xge_free_irq_resource
init|=
literal|9
block|,
name|xge_free_terminate_hal_device
init|=
literal|10
block|,
name|xge_free_media_interface
init|=
literal|11
block|, }
name|xge_lables_e
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|xge_option
block|{
name|XGE_CHANGE_LRO
init|=
literal|0
block|,
name|XGE_SET_MTU
init|=
literal|1
block|}
name|xge_option_e
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|xge_event_e
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
block|}
name|xge_event_e
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xge_msi_info
block|{
name|u16
name|msi_control
decl_stmt|;
comment|/* MSI control 0x42              */
name|u32
name|msi_lower_address
decl_stmt|;
comment|/* MSI lower address 0x44        */
name|u32
name|msi_higher_address
decl_stmt|;
comment|/* MSI higher address 0x48       */
name|u16
name|msi_data
decl_stmt|;
comment|/* MSI data                      */
block|}
name|xge_msi_info_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xge_driver_stats_t
block|{
comment|/* ISR statistics */
name|u64
name|isr_filter
decl_stmt|;
name|u64
name|isr_line
decl_stmt|;
name|u64
name|isr_msi
decl_stmt|;
comment|/* Tx statistics */
name|u64
name|tx_calls
decl_stmt|;
name|u64
name|tx_completions
decl_stmt|;
name|u64
name|tx_desc_compl
decl_stmt|;
name|u64
name|tx_tcode
decl_stmt|;
name|u64
name|tx_defrag
decl_stmt|;
name|u64
name|tx_no_txd
decl_stmt|;
name|u64
name|tx_map_fail
decl_stmt|;
name|u64
name|tx_max_frags
decl_stmt|;
name|u64
name|tx_tso
decl_stmt|;
name|u64
name|tx_posted
decl_stmt|;
name|u64
name|tx_again
decl_stmt|;
name|u64
name|tx_lock_fail
decl_stmt|;
comment|/* Rx statistics */
name|u64
name|rx_completions
decl_stmt|;
name|u64
name|rx_desc_compl
decl_stmt|;
name|u64
name|rx_tcode
decl_stmt|;
name|u64
name|rx_no_buf
decl_stmt|;
name|u64
name|rx_map_fail
decl_stmt|;
comment|/* LRO statistics */
name|u64
name|lro_uncapable
decl_stmt|;
name|u64
name|lro_begin
decl_stmt|;
name|u64
name|lro_end1
decl_stmt|;
name|u64
name|lro_end2
decl_stmt|;
name|u64
name|lro_end3
decl_stmt|;
name|u64
name|lro_append
decl_stmt|;
name|u64
name|lro_session_exceeded
decl_stmt|;
name|u64
name|lro_close
decl_stmt|;
block|}
name|xge_driver_stats_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xge_lro_entry_t
block|{
name|SLIST_ENTRY
argument_list|(
argument|xge_lro_entry_t
argument_list|)
name|next
expr_stmt|;
name|struct
name|mbuf
modifier|*
name|m_head
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|m_tail
decl_stmt|;
name|struct
name|ip
modifier|*
name|lro_header_ip
decl_stmt|;
name|int
name|timestamp
decl_stmt|;
name|u32
name|tsval
decl_stmt|;
name|u32
name|tsecr
decl_stmt|;
name|u32
name|source_ip
decl_stmt|;
name|u32
name|dest_ip
decl_stmt|;
name|u32
name|next_seq
decl_stmt|;
name|u32
name|ack_seq
decl_stmt|;
name|u32
name|len
decl_stmt|;
name|u32
name|data_csum
decl_stmt|;
name|u16
name|window
decl_stmt|;
name|u16
name|source_port
decl_stmt|;
name|u16
name|dest_port
decl_stmt|;
name|u16
name|append_cnt
decl_stmt|;
name|u16
name|mss
decl_stmt|;
block|}
name|xge_lro_entry_t
typedef|;
end_typedef

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|lro_head
argument_list|,
name|xge_lro_entry_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Adapter structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xge_lldev_t
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
name|xge_pci_info_t
modifier|*
name|pdev
decl_stmt|;
comment|/* PCI info                      */
name|xge_hal_device_t
modifier|*
name|devh
decl_stmt|;
comment|/* HAL: Device Handle            */
name|struct
name|mtx
name|mtx_drv
decl_stmt|;
comment|/* Mutex - Driver                */
name|struct
name|mtx
name|mtx_tx
index|[
name|XGE_FIFO_COUNT
index|]
decl_stmt|;
comment|/* Mutex - Tx                    */
name|char
name|mtx_name_drv
index|[
literal|16
index|]
decl_stmt|;
comment|/*Mutex Name - Driver           */
name|char
name|mtx_name_tx
index|[
literal|16
index|]
index|[
name|XGE_FIFO_COUNT
index|]
decl_stmt|;
comment|/* Mutex Name - Tx               */
name|struct
name|callout
name|timer
decl_stmt|;
comment|/* Timer for polling             */
name|struct
name|ifmedia
name|media
decl_stmt|;
comment|/* In-kernel representation of a */
comment|/* single supported media type   */
name|xge_hal_channel_h
name|fifo_channel
index|[
name|XGE_FIFO_COUNT
index|]
decl_stmt|;
comment|/* FIFO channels                 */
name|xge_hal_channel_h
name|ring_channel
index|[
name|XGE_RING_COUNT
index|]
decl_stmt|;
comment|/* Ring channels                 */
name|bus_dma_tag_t
name|dma_tag_tx
decl_stmt|;
comment|/* Tag for dtr dma mapping (Tx)  */
name|bus_dma_tag_t
name|dma_tag_rx
decl_stmt|;
comment|/* Tag for dtr dma mapping (Rx)  */
name|bus_dmamap_t
name|extra_dma_map
decl_stmt|;
comment|/* Extra DMA map for Rx          */
name|xge_msi_info_t
name|msi_info
decl_stmt|;
comment|/* MSI info                      */
name|xge_driver_stats_t
name|driver_stats
decl_stmt|;
comment|/* Driver statistics             */
name|int
name|initialized
decl_stmt|;
comment|/* Flag: Initialized or not      */
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
name|int
name|enabled_tso
decl_stmt|;
comment|/* Flag: TSO Enabled             */
name|int
name|enabled_lro
decl_stmt|;
comment|/* Flag: LRO Enabled             */
name|int
name|enabled_msi
decl_stmt|;
comment|/* Flag: MSI Enabled             */
name|int
name|mtu
decl_stmt|;
comment|/* Interface MTU                 */
name|int
name|lro_num
decl_stmt|;
comment|/* Number of LRO sessions        */
name|struct
name|lro_head
name|lro_active
decl_stmt|;
comment|/* Active LRO sessions           */
name|struct
name|lro_head
name|lro_free
decl_stmt|;
comment|/* Free LRO sessions             */
block|}
name|xge_lldev_t
typedef|;
end_typedef

begin_comment
comment|/* Rx descriptor private structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xge_rx_priv_t
block|{
name|mbuf_t
modifier|*
name|bufferArray
decl_stmt|;
name|xge_dma_mbuf_t
name|dmainfo
index|[
literal|5
index|]
decl_stmt|;
block|}
name|xge_rx_priv_t
typedef|;
end_typedef

begin_comment
comment|/* Tx descriptor private structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xge_tx_priv_t
block|{
name|mbuf_t
name|buffer
decl_stmt|;
name|bus_dmamap_t
name|dma_map
decl_stmt|;
block|}
name|xge_tx_priv_t
typedef|;
end_typedef

begin_comment
comment|/* BAR0 Register */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xge_register_t
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
name|xge_register_t
typedef|;
end_typedef

begin_function_decl
name|void
name|xge_init_params
parameter_list|(
name|xge_hal_device_config_t
modifier|*
parameter_list|,
name|device_t
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
name|xge_device_init
parameter_list|(
name|xge_lldev_t
modifier|*
parameter_list|,
name|xge_hal_channel_reopen_e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_device_stop
parameter_list|(
name|xge_lldev_t
modifier|*
parameter_list|,
name|xge_hal_channel_reopen_e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_stop
parameter_list|(
name|xge_lldev_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_resources_free
parameter_list|(
name|device_t
parameter_list|,
name|xge_lables_e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_callback_link_up
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_callback_link_down
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_callback_crit_err
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
name|xge_callback_event
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
name|int
name|xge_ioctl_stats
parameter_list|(
name|xge_lldev_t
modifier|*
parameter_list|,
name|struct
name|ifreq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xge_ioctl_registers
parameter_list|(
name|xge_lldev_t
modifier|*
parameter_list|,
name|struct
name|ifreq
modifier|*
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
name|xge_isr_filter
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_isr_line
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_isr_msi
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_enable_msi
parameter_list|(
name|xge_lldev_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xge_rx_open
parameter_list|(
name|int
parameter_list|,
name|xge_lldev_t
modifier|*
parameter_list|,
name|xge_hal_channel_reopen_e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xge_tx_open
parameter_list|(
name|xge_lldev_t
modifier|*
parameter_list|,
name|xge_hal_channel_reopen_e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_channel_close
parameter_list|(
name|xge_lldev_t
modifier|*
parameter_list|,
name|xge_hal_channel_reopen_e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xge_channel_open
parameter_list|(
name|xge_lldev_t
modifier|*
parameter_list|,
name|xge_hal_channel_reopen_e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xge_hal_status_e
name|xge_rx_compl
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
name|xge_tx_compl
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
name|xge_tx_initial_replenish
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
name|xge_rx_initial_replenish
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
name|xge_rx_term
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
name|xge_tx_term
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
name|xge_set_mbuf_cflags
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
specifier|static
name|void
specifier|inline
name|xge_send_locked
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xge_get_buf
parameter_list|(
name|xge_hal_dtr_h
parameter_list|,
name|xge_rx_priv_t
modifier|*
parameter_list|,
name|xge_lldev_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xge_ring_dtr_get
parameter_list|(
name|mbuf_t
parameter_list|,
name|xge_hal_channel_h
parameter_list|,
name|xge_hal_dtr_h
parameter_list|,
name|xge_lldev_t
modifier|*
parameter_list|,
name|xge_rx_priv_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xge_get_buf_3b_5b
parameter_list|(
name|xge_hal_dtr_h
parameter_list|,
name|xge_rx_priv_t
modifier|*
parameter_list|,
name|xge_lldev_t
modifier|*
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
name|xge_reset
parameter_list|(
name|xge_lldev_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_setmulti
parameter_list|(
name|xge_lldev_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_enable_promisc
parameter_list|(
name|xge_lldev_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_disable_promisc
parameter_list|(
name|xge_lldev_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xge_change_mtu
parameter_list|(
name|xge_lldev_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_buffer_mode_init
parameter_list|(
name|xge_lldev_t
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
name|void
name|xge_msi_info_save
parameter_list|(
name|xge_lldev_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_msi_info_restore
parameter_list|(
name|xge_lldev_t
modifier|*
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
name|void
name|xge_mutex_init
parameter_list|(
name|xge_lldev_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_mutex_destroy
parameter_list|(
name|xge_lldev_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_print_info
parameter_list|(
name|xge_lldev_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_lro_flush_sessions
parameter_list|(
name|xge_lldev_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_rx_buffer_sizes_set
parameter_list|(
name|xge_lldev_t
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
name|xge_accumulate_large_rx
parameter_list|(
name|xge_lldev_t
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|xge_rx_priv_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xge_hal_status_e
name|xge_create_dma_tags
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_add_sysctl_handlers
parameter_list|(
name|xge_lldev_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_confirm_changes
parameter_list|(
name|xge_lldev_t
modifier|*
parameter_list|,
name|xge_option_e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|xge_lro_accumulate
parameter_list|(
name|xge_lldev_t
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|xge_lro_flush
parameter_list|(
name|xge_lldev_t
modifier|*
parameter_list|,
name|xge_lro_entry_t
modifier|*
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

