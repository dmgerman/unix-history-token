begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Marvell Semiconductor, Inc.  * Copyright (c) 2007 Sam Leffler, Errno Consulting  * Copyright (c) 2008 Weongyo Jeong<weongyo@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Definitions for the Marvell 88W8335 Wireless LAN controller.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_MALO_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_MALO_H
end_define

begin_include
include|#
directive|include
file|<net80211/ieee80211_radiotap.h>
end_include

begin_include
include|#
directive|include
file|<dev/malo/if_malohal.h>
end_include

begin_include
include|#
directive|include
file|<dev/malo/if_maloioctl.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|MALO_TXBUF
end_ifndef

begin_define
define|#
directive|define
name|MALO_TXBUF
value|256
end_define

begin_comment
comment|/* number of TX descriptors/buffers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MALO_RXBUF
end_ifndef

begin_define
define|#
directive|define
name|MALO_RXBUF
value|256
end_define

begin_comment
comment|/* number of RX descriptors/buffers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MALO_TXDESC
value|1
end_define

begin_comment
comment|/* max tx descriptors/segments */
end_comment

begin_define
define|#
directive|define
name|MALO_RXSIZE
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|MALO_RSSI_DUMMY_MARKER
value|127
end_define

begin_define
define|#
directive|define
name|MALO_RSSI_EP_MULTIPLIER
value|(1<<7)
end_define

begin_comment
comment|/* pow2 to optimize out * and / */
end_comment

begin_define
define|#
directive|define
name|MALO_REG_INT_CODE
value|0x00000C14
end_define

begin_comment
comment|/* From host to ARM */
end_comment

begin_define
define|#
directive|define
name|MALO_REG_H2A_INTERRUPT_EVENTS
value|0x00000C18
end_define

begin_comment
comment|/* bit definitions for MALO_REG_H2A_INTERRUPT_CAUSE */
end_comment

begin_define
define|#
directive|define
name|MALO_H2ARIC_BIT_PPA_READY
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MALO_H2ARIC_BIT_DOOR_BELL
value|0x00000002
end_define

begin_comment
comment|/* bit 1 */
end_comment

begin_define
define|#
directive|define
name|MALO_H2ARIC_BIT_PS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MALO_H2ARIC_BIT_PSPOLL
value|0x00000008
end_define

begin_comment
comment|/* bit 3 */
end_comment

begin_comment
comment|/* From ARM to host */
end_comment

begin_define
define|#
directive|define
name|MALO_REG_A2H_INTERRUPT_CAUSE
value|0x00000C30
end_define

begin_define
define|#
directive|define
name|MALO_REG_A2H_INTERRUPT_MASK
value|0x00000C34
end_define

begin_define
define|#
directive|define
name|MALO_REG_A2H_INTERRUPT_CLEAR_SEL
value|0x00000C38
end_define

begin_define
define|#
directive|define
name|MALO_REG_A2H_INTERRUPT_STATUS_MASK
value|0x00000C3C
end_define

begin_comment
comment|/* bit definitions for MALO_REG_A2H_INTERRUPT_CAUSE */
end_comment

begin_define
define|#
directive|define
name|MALO_A2HRIC_BIT_TX_DONE
value|0x00000001
end_define

begin_comment
comment|/* bit 0 */
end_comment

begin_define
define|#
directive|define
name|MALO_A2HRIC_BIT_RX_RDY
value|0x00000002
end_define

begin_comment
comment|/* bit 1 */
end_comment

begin_define
define|#
directive|define
name|MALO_A2HRIC_BIT_OPC_DONE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MALO_A2HRIC_BIT_MAC_EVENT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MALO_A2HRIC_BIT_RX_PROBLEM
value|0x00000010
end_define

begin_define
define|#
directive|define
name|MALO_A2HRIC_BIT_RADIO_OFF
value|0x00000020
end_define

begin_comment
comment|/* bit 5 */
end_comment

begin_define
define|#
directive|define
name|MALO_A2HRIC_BIT_RADIO_ON
value|0x00000040
end_define

begin_define
define|#
directive|define
name|MALO_A2HRIC_BIT_RADAR_DETECT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|MALO_A2HRIC_BIT_ICV_ERROR
value|0x00000100
end_define

begin_define
define|#
directive|define
name|MALO_A2HRIC_BIT_MIC_ERROR
value|0x00000200
end_define

begin_comment
comment|/* bit 9 */
end_comment

begin_define
define|#
directive|define
name|MALO_A2HRIC_BIT_QUEUE_EMPTY
value|0x00000400
end_define

begin_define
define|#
directive|define
name|MALO_A2HRIC_BIT_QUEUE_FULL
value|0x00000800
end_define

begin_define
define|#
directive|define
name|MALO_A2HRIC_BIT_CHAN_SWITCH
value|0x00001000
end_define

begin_define
define|#
directive|define
name|MALO_A2HRIC_BIT_TX_WATCHDOG
value|0x00002000
end_define

begin_define
define|#
directive|define
name|MALO_A2HRIC_BIT_BA_WATCHDOG
value|0x00004000
end_define

begin_define
define|#
directive|define
name|MALO_ISR_SRC_BITS
define|\
value|(MALO_A2HRIC_BIT_RX_RDY |		\ 	 MALO_A2HRIC_BIT_TX_DONE |		\ 	 MALO_A2HRIC_BIT_OPC_DONE |		\ 	 MALO_A2HRIC_BIT_MAC_EVENT |		\ 	 MALO_A2HRIC_BIT_MIC_ERROR |		\ 	 MALO_A2HRIC_BIT_ICV_ERROR |		\ 	 MALO_A2HRIC_BIT_RADAR_DETECT |		\ 	 MALO_A2HRIC_BIT_CHAN_SWITCH |		\ 	 MALO_A2HRIC_BIT_TX_WATCHDOG |		\ 	 MALO_A2HRIC_BIT_QUEUE_EMPTY)
end_define

begin_define
define|#
directive|define
name|MALO_ISR_RESET
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|MALO_A2HRIC_BIT_MASK
value|MALO_ISR_SRC_BITS
end_define

begin_comment
comment|/* map to 0x80000000 on BAR1  */
end_comment

begin_define
define|#
directive|define
name|MALO_REG_GEN_PTR
value|0x00000C10
end_define

begin_define
define|#
directive|define
name|MALO_REG_INT_CODE
value|0x00000C14
end_define

begin_define
define|#
directive|define
name|MALO_REG_SCRATCH
value|0x00000C40
end_define

begin_comment
comment|/*  * define OpMode for SoftAP/Station mode  *  * the following mode signature has to be written to PCI scratch register#0  * right after successfully downloading the last block of firmware and  * before waiting for firmware ready signature  */
end_comment

begin_define
define|#
directive|define
name|MALO_HOSTCMD_STA_MODE
value|0x5A
end_define

begin_define
define|#
directive|define
name|MALO_HOSTCMD_STA_FWRDY_SIGNATURE
value|0xF0F1F2F4
end_define

begin_comment
comment|/*  * 16 bit host command code  */
end_comment

begin_define
define|#
directive|define
name|MALO_HOSTCMD_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|MALO_HOSTCMD_CODE_DNLD
value|0x0001
end_define

begin_define
define|#
directive|define
name|MALO_HOSTCMD_GET_HW_SPEC
value|0x0003
end_define

begin_define
define|#
directive|define
name|MALO_HOSTCMD_SET_HW_SPEC
value|0x0004
end_define

begin_define
define|#
directive|define
name|MALO_HOSTCMD_MAC_MULTICAST_ADR
value|0x0010
end_define

begin_define
define|#
directive|define
name|MALO_HOSTCMD_SET_WEPKEY
value|0x0013
end_define

begin_define
define|#
directive|define
name|MALO_HOSTCMD_802_11_RADIO_CONTROL
value|0x001c
end_define

begin_define
define|#
directive|define
name|MALO_HOSTCMD_802_11_RF_TX_POWER
value|0x001e
end_define

begin_define
define|#
directive|define
name|MALO_HOSTCMD_802_11_RF_ANTENNA
value|0x0020
end_define

begin_define
define|#
directive|define
name|MALO_HOSTCMD_SET_PRE_SCAN
value|0x0107
end_define

begin_define
define|#
directive|define
name|MALO_HOSTCMD_SET_POST_SCAN
value|0x0108
end_define

begin_define
define|#
directive|define
name|MALO_HOSTCMD_SET_RF_CHANNEL
value|0x010a
end_define

begin_define
define|#
directive|define
name|MALO_HOSTCMD_SET_AID
value|0x010d
end_define

begin_define
define|#
directive|define
name|MALO_HOSTCMD_SET_RATE
value|0x0110
end_define

begin_define
define|#
directive|define
name|MALO_HOSTCMD_SET_SLOT
value|0x0114
end_define

begin_comment
comment|/* define DFS lab commands  */
end_comment

begin_define
define|#
directive|define
name|MALO_HOSTCMD_SET_FIXED_RATE
value|0x0126
end_define

begin_define
define|#
directive|define
name|MALO_HOSTCMD_SET_REGION_POWER
value|0x0128
end_define

begin_define
define|#
directive|define
name|MALO_HOSTCMD_GET_CALTABLE
value|0x1134
end_define

begin_comment
comment|/*  * definition of action or option for each command.  */
end_comment

begin_comment
comment|/* define general purpose action  */
end_comment

begin_define
define|#
directive|define
name|MALO_HOSTCMD_ACT_GEN_GET
value|0x0000
end_define

begin_define
define|#
directive|define
name|MALO_HOSTCMD_ACT_GEN_SET
value|0x0001
end_define

begin_define
define|#
directive|define
name|MALO_HOSTCMD_ACT_GEN_SET_LIST
value|0x0002
end_define

begin_comment
comment|/* define action or option for HostCmd_FW_USE_FIXED_RATE */
end_comment

begin_define
define|#
directive|define
name|MALO_HOSTCMD_ACT_USE_FIXED_RATE
value|0x0001
end_define

begin_define
define|#
directive|define
name|MALO_HOSTCMD_ACT_NOT_USE_FIXED_RATE
value|0x0002
end_define

begin_comment
comment|/* INT code register event definition  */
end_comment

begin_define
define|#
directive|define
name|MALO_INT_CODE_CMD_FINISHED
value|0x00000005
end_define

begin_struct
struct|struct
name|malo_cmd_header
block|{
name|uint16_t
name|cmd
decl_stmt|;
name|uint16_t
name|length
decl_stmt|;
name|uint16_t
name|seqnum
decl_stmt|;
name|uint16_t
name|result
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|malo_cmd_caltable
block|{
name|struct
name|malo_cmd_header
name|cmdhdr
decl_stmt|;
name|uint8_t
name|annex
decl_stmt|;
name|uint8_t
name|index
decl_stmt|;
name|uint8_t
name|len
decl_stmt|;
name|uint8_t
name|reserverd
decl_stmt|;
define|#
directive|define
name|MALO_CAL_TBL_SIZE
value|160
name|uint8_t
name|caltbl
index|[
name|MALO_CAL_TBL_SIZE
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|malo_cmd_get_hwspec
block|{
name|struct
name|malo_cmd_header
name|cmdhdr
decl_stmt|;
name|u_int8_t
name|version
decl_stmt|;
comment|/* version of the HW  */
name|u_int8_t
name|hostif
decl_stmt|;
comment|/* host interface  */
comment|/* Max. number of WCB FW can handle  */
name|u_int16_t
name|num_wcb
decl_stmt|;
comment|/* MaxNbr of MC addresses FW can handle */
name|u_int16_t
name|num_mcastaddr
decl_stmt|;
comment|/* MAC address programmed in HW */
name|u_int8_t
name|permaddr
index|[
literal|6
index|]
decl_stmt|;
name|u_int16_t
name|regioncode
decl_stmt|;
comment|/* Number of antenna used */
name|u_int16_t
name|num_antenna
decl_stmt|;
comment|/* 4 byte of FW release number */
name|u_int32_t
name|fw_releasenum
decl_stmt|;
name|u_int32_t
name|wcbbase0
decl_stmt|;
name|u_int32_t
name|rxpdwr_ptr
decl_stmt|;
name|u_int32_t
name|rxpdrd_ptr
decl_stmt|;
name|u_int32_t
name|ul_fw_awakecookie
decl_stmt|;
name|u_int32_t
name|wcbbase1
decl_stmt|;
name|u_int32_t
name|wcbbase2
decl_stmt|;
name|u_int32_t
name|wcbbase3
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|malo_cmd_set_hwspec
block|{
name|struct
name|malo_cmd_header
name|cmdhdr
decl_stmt|;
name|uint8_t
name|version
decl_stmt|;
comment|/* HW revision */
name|uint8_t
name|hostif
decl_stmt|;
comment|/* Host interface */
comment|/* Max. number of Multicast address FW can handle */
name|uint16_t
name|num_mcastaddr
decl_stmt|;
name|uint8_t
name|permaddr
index|[
literal|6
index|]
decl_stmt|;
comment|/* MAC address */
name|uint16_t
name|regioncode
decl_stmt|;
comment|/* Region Code */
comment|/* 4 byte of FW release number */
name|uint32_t
name|fwreleasenum
decl_stmt|;
comment|/* Firmware awake cookie */
name|uint32_t
name|ul_fw_awakecookie
decl_stmt|;
comment|/* Device capabilities (see above) */
name|uint32_t
name|devicecaps
decl_stmt|;
name|uint32_t
name|rxpdwrptr
decl_stmt|;
comment|/* Rx shared memory queue  */
comment|/* # TX queues in WcbBase array */
name|uint32_t
name|num_txqueues
decl_stmt|;
comment|/* TX WCB Rings */
name|uint32_t
name|wcbbase
index|[
name|MALO_MAX_TXWCB_QUEUES
index|]
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|txwcbnum_per_queue
decl_stmt|;
name|uint32_t
name|total_rxwcb
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* DS 802.11 */
end_comment

begin_struct
struct|struct
name|malo_cmd_rf_antenna
block|{
name|struct
name|malo_cmd_header
name|cmdhdr
decl_stmt|;
name|uint16_t
name|action
decl_stmt|;
comment|/* Number of antennas or 0xffff (diversity)  */
name|uint16_t
name|mode
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|malo_cmd_radio_control
block|{
name|struct
name|malo_cmd_header
name|cmdhdr
decl_stmt|;
name|uint16_t
name|action
decl_stmt|;
comment|/* 	 * bit 0 : 1 = on, 0 = off 	 * bit 1 : 1 = long, 0 = short 	 * bit 2 : 1 = auto, 0 = fix 	 */
name|uint16_t
name|control
decl_stmt|;
name|uint16_t
name|radio_on
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|malo_cmd_fw_set_wmmmode
block|{
name|struct
name|malo_cmd_header
name|cmdhdr
decl_stmt|;
name|uint16_t
name|action
decl_stmt|;
comment|/* 0 -> unset, 1 -> set  */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|malo_cmd_fw_set_rf_channel
block|{
name|struct
name|malo_cmd_header
name|cmdhdr
decl_stmt|;
name|uint16_t
name|action
decl_stmt|;
name|uint8_t
name|cur_channel
decl_stmt|;
comment|/* channel # */
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|MALO_TX_POWER_LEVEL_TOTAL
value|8
end_define

begin_struct
struct|struct
name|malo_cmd_rf_tx_power
block|{
name|struct
name|malo_cmd_header
name|cmdhdr
decl_stmt|;
name|uint16_t
name|action
decl_stmt|;
name|uint16_t
name|support_txpower_level
decl_stmt|;
name|uint16_t
name|current_txpower_level
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
name|uint16_t
name|power_levellist
index|[
name|MALO_TX_POWER_LEVEL_TOTAL
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|malo_fixrate_flag
block|{
comment|/* lower rate after the retry count.  0 = legacy, 1 = HT  */
name|uint32_t
name|type
decl_stmt|;
comment|/* 0: retry count is not valid, 1: use retry count specified  */
name|uint32_t
name|retrycount_valid
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|malo_fixed_rate_entry
block|{
name|struct
name|malo_fixrate_flag
name|typeflags
decl_stmt|;
comment|/* legacy rate(not index) or an MCS code.  */
name|uint32_t
name|fixedrate
decl_stmt|;
name|uint32_t
name|retrycount
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|malo_cmd_fw_use_fixed_rate
block|{
name|struct
name|malo_cmd_header
name|cmdhdr
decl_stmt|;
comment|/* 	 * MALO_HOSTCMD_ACT_GEN_GET	0x0000 	 * MALO_HOSTCMD_ACT_GEN_SET	0x0001 	 * MALO_HOSTCMD_ACT_NOT_USE_FIXED_RATE	0x0002 	 */
name|uint32_t
name|action
decl_stmt|;
comment|/* use fixed rate specified but firmware can drop to  */
name|uint32_t
name|allowratedrop
decl_stmt|;
name|uint32_t
name|entrycount
decl_stmt|;
name|struct
name|malo_fixed_rate_entry
name|fixedrate_table
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|multicast_rate
decl_stmt|;
name|uint8_t
name|multirate_txtype
decl_stmt|;
name|uint8_t
name|management_rate
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|MALO_RATE_INDEX_MAX_ARRAY
value|14
end_define

begin_struct
struct|struct
name|malo_cmd_fw_set_aid
block|{
name|struct
name|malo_cmd_header
name|cmdhdr
decl_stmt|;
name|uint16_t
name|associd
decl_stmt|;
name|uint8_t
name|macaddr
index|[
literal|6
index|]
decl_stmt|;
comment|/* AP's Mac Address(BSSID) */
name|uint32_t
name|gprotection
decl_stmt|;
name|uint8_t
name|aprates
index|[
name|MALO_RATE_INDEX_MAX_ARRAY
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|malo_cmd_prescan
block|{
name|struct
name|malo_cmd_header
name|cmdhdr
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|malo_cmd_postscan
block|{
name|struct
name|malo_cmd_header
name|cmdhdr
decl_stmt|;
name|uint32_t
name|isibss
decl_stmt|;
name|uint8_t
name|bssid
index|[
literal|6
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|malo_cmd_fw_setslot
block|{
name|struct
name|malo_cmd_header
name|cmdhdr
decl_stmt|;
name|uint16_t
name|action
decl_stmt|;
comment|/* slot = 0 if regular, slot = 1 if short.  */
name|uint8_t
name|slot
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|malo_cmd_set_rate
block|{
name|struct
name|malo_cmd_header
name|cmdhdr
decl_stmt|;
name|uint8_t
name|dataratetype
decl_stmt|;
name|uint8_t
name|rateindex
decl_stmt|;
name|uint8_t
name|aprates
index|[
literal|14
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|malo_cmd_wepkey
block|{
name|struct
name|malo_cmd_header
name|cmdhdr
decl_stmt|;
name|uint16_t
name|action
decl_stmt|;
name|uint8_t
name|len
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
name|uint16_t
name|index
decl_stmt|;
name|uint8_t
name|value
index|[
name|IEEE80211_KEYBUF_SIZE
index|]
decl_stmt|;
name|uint8_t
name|txmickey
index|[
name|IEEE80211_WEP_MICLEN
index|]
decl_stmt|;
name|uint8_t
name|rxmickey
index|[
name|IEEE80211_WEP_MICLEN
index|]
decl_stmt|;
name|uint64_t
name|rxseqctr
decl_stmt|;
name|uint64_t
name|txseqctr
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|malo_cmd_mcast
block|{
name|struct
name|malo_cmd_header
name|cmdhdr
decl_stmt|;
name|uint16_t
name|action
decl_stmt|;
name|uint16_t
name|numaddr
decl_stmt|;
define|#
directive|define
name|MALO_HAL_MCAST_MAX
value|32
name|uint8_t
name|maclist
index|[
literal|6
operator|*
literal|32
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * DMA state for tx/rx descriptors.  */
end_comment

begin_comment
comment|/*  * Common "base class" for tx/rx descriptor resources  * allocated using the bus dma api.  */
end_comment

begin_struct
struct|struct
name|malo_descdma
block|{
specifier|const
name|char
modifier|*
name|dd_name
decl_stmt|;
name|void
modifier|*
name|dd_desc
decl_stmt|;
comment|/* descriptors */
name|bus_addr_t
name|dd_desc_paddr
decl_stmt|;
comment|/* physical addr of dd_desc */
name|bus_size_t
name|dd_desc_len
decl_stmt|;
comment|/* size of dd_desc */
name|bus_dma_segment_t
name|dd_dseg
decl_stmt|;
name|int
name|dd_dnseg
decl_stmt|;
comment|/* number of segments */
name|bus_dma_tag_t
name|dd_dmat
decl_stmt|;
comment|/* bus DMA tag */
name|bus_dmamap_t
name|dd_dmamap
decl_stmt|;
comment|/* DMA map for descriptors */
name|void
modifier|*
name|dd_bufptr
decl_stmt|;
comment|/* associated buffers */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Hardware tx/rx descriptors.  *  * NB: tx descriptor size must match f/w expected size  * because f/w prefetch's the next descriptor linearly  * and doesn't chase the next pointer.  */
end_comment

begin_struct
struct|struct
name|malo_txdesc
block|{
name|uint32_t
name|status
decl_stmt|;
define|#
directive|define
name|MALO_TXD_STATUS_IDLE
value|0x00000000
define|#
directive|define
name|MALO_TXD_STATUS_USED
value|0x00000001
define|#
directive|define
name|MALO_TXD_STATUS_OK
value|0x00000001
define|#
directive|define
name|MALO_TXD_STATUS_OK_RETRY
value|0x00000002
define|#
directive|define
name|MALO_TXD_STATUS_OK_MORE_RETRY
value|0x00000004
define|#
directive|define
name|MALO_TXD_STATUS_MULTICAST_TX
value|0x00000008
define|#
directive|define
name|MALO_TXD_STATUS_BROADCAST_TX
value|0x00000010
define|#
directive|define
name|MALO_TXD_STATUS_FAILED_LINK_ERROR
value|0x00000020
define|#
directive|define
name|MALO_TXD_STATUS_FAILED_EXCEED_LIMIT
value|0x00000040
define|#
directive|define
name|MALO_TXD_STATUS_FAILED_XRETRY
value|MALO_TXD_STATUS_FAILED_EXCEED_LIMIT
define|#
directive|define
name|MALO_TXD_STATUS_FAILED_AGING
value|0x00000080
define|#
directive|define
name|MALO_TXD_STATUS_FW_OWNED
value|0x80000000
name|uint8_t
name|datarate
decl_stmt|;
name|uint8_t
name|txpriority
decl_stmt|;
name|uint16_t
name|qosctrl
decl_stmt|;
name|uint32_t
name|pktptr
decl_stmt|;
name|uint16_t
name|pktlen
decl_stmt|;
name|uint8_t
name|destaddr
index|[
literal|6
index|]
decl_stmt|;
name|uint32_t
name|physnext
decl_stmt|;
name|uint32_t
name|sap_pktinfo
decl_stmt|;
name|uint16_t
name|format
decl_stmt|;
define|#
directive|define
name|MALO_TXD_FORMAT
value|0x0001
comment|/* frame format/rate */
define|#
directive|define
name|MALO_TXD_FORMAT_LEGACY
value|0x0000
comment|/* legacy rate frame */
define|#
directive|define
name|MALO_TXD_RATE
value|0x01f8
comment|/* tx rate (legacy)/ MCS */
define|#
directive|define
name|MALO_TXD_RATE_S
value|3
comment|/* NB: 3 is reserved */
define|#
directive|define
name|MALO_TXD_ANTENNA
value|0x1800
comment|/* antenna select */
define|#
directive|define
name|MALO_TXD_ANTENNA_S
value|11
name|uint16_t
name|pad
decl_stmt|;
comment|/* align to 4-byte boundary */
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|MALO_TXDESC_SYNC
parameter_list|(
name|txq
parameter_list|,
name|ds
parameter_list|,
name|how
parameter_list|)
value|do {				\ 	bus_dmamap_sync((txq)->dma.dd_dmat, (txq)->dma.dd_dmamap, how);	\ } while(0)
end_define

begin_struct
struct|struct
name|malo_rxdesc
block|{
name|uint8_t
name|rxcontrol
decl_stmt|;
comment|/* control element */
define|#
directive|define
name|MALO_RXD_CTRL_DRIVER_OWN
value|0x00
define|#
directive|define
name|MALO_RXD_CTRL_OS_OWN
value|0x04
define|#
directive|define
name|MALO_RXD_CTRL_DMA_OWN
value|0x80
name|uint8_t
name|snr
decl_stmt|;
comment|/* signal to noise ratio */
name|uint8_t
name|status
decl_stmt|;
comment|/* status field w/ USED bit */
define|#
directive|define
name|MALO_RXD_STATUS_IDLE
value|0x00
define|#
directive|define
name|MALO_RXD_STATUS_OK
value|0x01
define|#
directive|define
name|MALO_RXD_STATUS_MULTICAST_RX
value|0x02
define|#
directive|define
name|MALO_RXD_STATUS_BROADCAST_RX
value|0x04
define|#
directive|define
name|MALO_RXD_STATUS_FRAGMENT_RX
value|0x08
define|#
directive|define
name|MALO_RXD_STATUS_GENERAL_DECRYPT_ERR
value|0xff
define|#
directive|define
name|MALO_RXD_STATUS_DECRYPT_ERR_MASK
value|0x80
define|#
directive|define
name|MALO_RXD_STATUS_TKIP_MIC_DECRYPT_ERR
value|0x02
define|#
directive|define
name|MALO_RXD_STATUS_WEP_ICV_DECRYPT_ERR
value|0x04
define|#
directive|define
name|MALO_RXD_STATUS_TKIP_ICV_DECRYPT_ERR
value|0x08
name|uint8_t
name|channel
decl_stmt|;
comment|/* channel # pkt received on */
name|uint16_t
name|pktlen
decl_stmt|;
comment|/* total length of received data */
name|uint8_t
name|nf
decl_stmt|;
comment|/* noise floor */
name|uint8_t
name|rate
decl_stmt|;
comment|/* received data rate */
name|uint32_t
name|physbuffdata
decl_stmt|;
comment|/* physical address of payload data */
name|uint32_t
name|physnext
decl_stmt|;
comment|/* physical address of next RX desc */
name|uint16_t
name|qosctrl
decl_stmt|;
comment|/* received QosCtrl field variable */
name|uint16_t
name|htsig2
decl_stmt|;
comment|/* like name states */
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|MALO_RXDESC_SYNC
parameter_list|(
name|sc
parameter_list|,
name|ds
parameter_list|,
name|how
parameter_list|)
value|do {				\ 	bus_dmamap_sync((sc)->malo_rxdma.dd_dmat,			\ 	    (sc)->malo_rxdma.dd_dmamap, how);				\ } while (0)
end_define

begin_struct
struct|struct
name|malo_rxbuf
block|{
name|STAILQ_ENTRY
argument_list|(
argument|malo_rxbuf
argument_list|)
name|bf_list
expr_stmt|;
name|void
modifier|*
name|bf_desc
decl_stmt|;
comment|/* h/w descriptor */
name|bus_addr_t
name|bf_daddr
decl_stmt|;
comment|/* physical addr of desc */
name|bus_dmamap_t
name|bf_dmamap
decl_stmt|;
name|bus_addr_t
name|bf_data
decl_stmt|;
comment|/* physical addr of rx data */
name|struct
name|mbuf
modifier|*
name|bf_m
decl_stmt|;
comment|/* jumbo mbuf */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|malo_rxbuf
argument_list|)
name|malo_rxbufhead
expr_stmt|;
end_typedef

begin_comment
comment|/*  * Software backed version of tx/rx descriptors.  We keep  * the software state out of the h/w descriptor structure  * so that may be allocated in uncached memory w/o paying  * performance hit.  */
end_comment

begin_struct
struct|struct
name|malo_txbuf
block|{
name|STAILQ_ENTRY
argument_list|(
argument|malo_txbuf
argument_list|)
name|bf_list
expr_stmt|;
name|void
modifier|*
name|bf_desc
decl_stmt|;
comment|/* h/w descriptor */
name|bus_addr_t
name|bf_daddr
decl_stmt|;
comment|/* physical addr of desc */
name|bus_dmamap_t
name|bf_dmamap
decl_stmt|;
comment|/* DMA map for descriptors */
name|int
name|bf_nseg
decl_stmt|;
name|bus_dma_segment_t
name|bf_segs
index|[
name|MALO_TXDESC
index|]
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|bf_m
decl_stmt|;
name|struct
name|ieee80211_node
modifier|*
name|bf_node
decl_stmt|;
name|struct
name|malo_txq
modifier|*
name|bf_txq
decl_stmt|;
comment|/* backpointer to tx q/ring */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|malo_txbuf
argument_list|)
name|malo_txbufhead
expr_stmt|;
end_typedef

begin_comment
comment|/*  * TX/RX ring definitions.  There are 4 tx rings, one  * per AC, and 1 rx ring.  Note carefully that transmit  * descriptors are treated as a contiguous chunk and the  * firmware pre-fetches descriptors.  This means that we  * must preserve order when moving descriptors between  * the active+free lists; otherwise we may stall transmit.  */
end_comment

begin_struct
struct|struct
name|malo_txq
block|{
name|struct
name|malo_descdma
name|dma
decl_stmt|;
comment|/* bus dma resources */
name|struct
name|mtx
name|lock
decl_stmt|;
comment|/* tx q lock */
name|char
name|name
index|[
literal|12
index|]
decl_stmt|;
comment|/* e.g. "malo0_txq4" */
name|int
name|qnum
decl_stmt|;
comment|/* f/w q number */
name|int
name|txpri
decl_stmt|;
comment|/* f/w tx priority */
name|int
name|nfree
decl_stmt|;
comment|/* # buffers on free list */
name|malo_txbufhead
name|free
decl_stmt|;
comment|/* queue of free buffers */
name|malo_txbufhead
name|active
decl_stmt|;
comment|/* queue of active buffers */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MALO_TXQ_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|,
name|_tq
parameter_list|)
value|do { \ 	snprintf((_tq)->name, sizeof((_tq)->name), "%s_txq%u", \ 		device_get_nameunit((_sc)->malo_dev), (_tq)->qnum); \ 	mtx_init(&(_tq)->lock, (_tq)->name, NULL, MTX_DEF); \ } while (0)
end_define

begin_define
define|#
directive|define
name|MALO_TXQ_LOCK_DESTROY
parameter_list|(
name|_tq
parameter_list|)
value|mtx_destroy(&(_tq)->lock)
end_define

begin_define
define|#
directive|define
name|MALO_TXQ_LOCK
parameter_list|(
name|_tq
parameter_list|)
value|mtx_lock(&(_tq)->lock)
end_define

begin_define
define|#
directive|define
name|MALO_TXQ_UNLOCK
parameter_list|(
name|_tq
parameter_list|)
value|mtx_unlock(&(_tq)->lock)
end_define

begin_define
define|#
directive|define
name|MALO_TXQ_LOCK_ASSERT
parameter_list|(
name|_tq
parameter_list|)
value|mtx_assert(&(_tq)->lock, MA_OWNED)
end_define

begin_comment
comment|/*  * Each packet has fixed front matter: a 2-byte length  * of the payload, followed by a 4-address 802.11 header  * (regardless of the actual header and always w/o any  * QoS header).  The payload then follows.  */
end_comment

begin_struct
struct|struct
name|malo_txrec
block|{
name|uint16_t
name|fwlen
decl_stmt|;
name|struct
name|ieee80211_frame_addr4
name|wh
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|malo_vap
block|{
name|struct
name|ieee80211vap
name|malo_vap
decl_stmt|;
name|int
function_decl|(
modifier|*
name|malo_newstate
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
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MALO_VAP
parameter_list|(
name|vap
parameter_list|)
value|((struct malo_vap *)(vap))
end_define

begin_struct
struct|struct
name|malo_softc
block|{
name|device_t
name|malo_dev
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|malo_ifp
decl_stmt|;
comment|/* interface common */
name|struct
name|mtx
name|malo_mtx
decl_stmt|;
comment|/* master lock (recursive) */
name|struct
name|taskqueue
modifier|*
name|malo_tq
decl_stmt|;
comment|/* private task queue */
name|bus_dma_tag_t
name|malo_dmat
decl_stmt|;
comment|/* bus DMA tag */
name|bus_space_handle_t
name|malo_io0h
decl_stmt|;
comment|/* BAR 0 */
name|bus_space_tag_t
name|malo_io0t
decl_stmt|;
name|bus_space_handle_t
name|malo_io1h
decl_stmt|;
comment|/* BAR 1 */
name|bus_space_tag_t
name|malo_io1t
decl_stmt|;
name|unsigned
name|int
name|malo_invalid
range|:
literal|1
decl_stmt|,
comment|/* disable hardware accesses */
name|malo_recvsetup
range|:
literal|1
decl_stmt|,
comment|/* recv setup */
name|malo_fixedrate
range|:
literal|1
decl_stmt|;
comment|/* use fixed tx rate */
name|struct
name|malo_hal
modifier|*
name|malo_mh
decl_stmt|;
comment|/* h/w access layer */
name|struct
name|malo_hal_hwspec
name|malo_hwspecs
decl_stmt|;
comment|/* h/w capabilities */
name|struct
name|malo_hal_txrxdma
name|malo_hwdma
decl_stmt|;
comment|/* h/w dma setup */
name|uint32_t
name|malo_imask
decl_stmt|;
comment|/* interrupt mask copy */
name|struct
name|malo_hal_channel
name|malo_curchan
decl_stmt|;
name|u_int16_t
name|malo_rxantenna
decl_stmt|;
comment|/* rx antenna */
name|u_int16_t
name|malo_txantenna
decl_stmt|;
comment|/* tx antenna */
name|struct
name|malo_descdma
name|malo_rxdma
decl_stmt|;
comment|/* rx bus dma resources */
name|malo_rxbufhead
name|malo_rxbuf
decl_stmt|;
comment|/* rx buffers */
name|struct
name|malo_rxbuf
modifier|*
name|malo_rxnext
decl_stmt|;
comment|/* next rx buffer to process */
name|struct
name|task
name|malo_rxtask
decl_stmt|;
comment|/* rx int processing */
name|struct
name|malo_txq
name|malo_txq
index|[
name|MALO_NUM_TX_QUEUES
index|]
decl_stmt|;
name|struct
name|task
name|malo_txtask
decl_stmt|;
comment|/* tx int processing */
name|struct
name|callout
name|malo_watchdog_timer
decl_stmt|;
name|int
name|malo_timer
decl_stmt|;
name|struct
name|malo_tx_radiotap_header
name|malo_tx_th
decl_stmt|;
name|struct
name|malo_rx_radiotap_header
name|malo_rx_th
decl_stmt|;
name|struct
name|malo_stats
name|malo_stats
decl_stmt|;
comment|/* interface statistics */
name|int
name|malo_debug
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MALO_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|)
define|\
value|mtx_init(&(_sc)->malo_mtx, device_get_nameunit((_sc)->malo_dev), \ 		 NULL, MTX_DEF | MTX_RECURSE)
end_define

begin_define
define|#
directive|define
name|MALO_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->malo_mtx)
end_define

begin_define
define|#
directive|define
name|MALO_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->malo_mtx)
end_define

begin_define
define|#
directive|define
name|MALO_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->malo_mtx)
end_define

begin_define
define|#
directive|define
name|MALO_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->malo_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|MALO_RXFREE_INIT
parameter_list|(
name|_sc
parameter_list|)
define|\
value|mtx_init(&(_sc)->malo_rxlock, device_get_nameunit((_sc)->malo_dev), \ 		 NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|MALO_RXFREE_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->malo_rxlock)
end_define

begin_define
define|#
directive|define
name|MALO_RXFREE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->malo_rxlock)
end_define

begin_define
define|#
directive|define
name|MALO_RXFREE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->malo_rxlock)
end_define

begin_define
define|#
directive|define
name|MALO_RXFREE_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->malo_rxlock, \ 	MA_OWNED)
end_define

begin_function_decl
name|int
name|malo_attach
parameter_list|(
name|uint16_t
parameter_list|,
name|struct
name|malo_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|malo_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|malo_detach
parameter_list|(
name|struct
name|malo_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malo_shutdown
parameter_list|(
name|struct
name|malo_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malo_suspend
parameter_list|(
name|struct
name|malo_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malo_resume
parameter_list|(
name|struct
name|malo_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

