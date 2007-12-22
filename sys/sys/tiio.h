begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999, 2000 Kenneth D. Merry.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * The ti_stats structure below is from code with the following copyright,   * and originally comes from the Alteon firmware documentation.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1997, 1998, 1999  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  *	from: if_tireg.h,v 1.8 1999/07/23 18:46:24 wpaul Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TIIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TIIO_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_comment
comment|/*  * Tigon statistics counters.  */
end_comment

begin_struct
struct|struct
name|ti_stats
block|{
comment|/* 	 * MAC stats, taken from RFC 1643, ethernet-like MIB 	 */
specifier|volatile
name|u_int32_t
name|dot3StatsAlignmentErrors
decl_stmt|;
comment|/* 0 */
specifier|volatile
name|u_int32_t
name|dot3StatsFCSErrors
decl_stmt|;
comment|/* 1 */
specifier|volatile
name|u_int32_t
name|dot3StatsSingleCollisionFrames
decl_stmt|;
comment|/* 2 */
specifier|volatile
name|u_int32_t
name|dot3StatsMultipleCollisionFrames
decl_stmt|;
comment|/* 3 */
specifier|volatile
name|u_int32_t
name|dot3StatsSQETestErrors
decl_stmt|;
comment|/* 4 */
specifier|volatile
name|u_int32_t
name|dot3StatsDeferredTransmissions
decl_stmt|;
comment|/* 5 */
specifier|volatile
name|u_int32_t
name|dot3StatsLateCollisions
decl_stmt|;
comment|/* 6 */
specifier|volatile
name|u_int32_t
name|dot3StatsExcessiveCollisions
decl_stmt|;
comment|/* 7 */
specifier|volatile
name|u_int32_t
name|dot3StatsInternalMacTransmitErrors
decl_stmt|;
comment|/* 8 */
specifier|volatile
name|u_int32_t
name|dot3StatsCarrierSenseErrors
decl_stmt|;
comment|/* 9 */
specifier|volatile
name|u_int32_t
name|dot3StatsFrameTooLongs
decl_stmt|;
comment|/* 10 */
specifier|volatile
name|u_int32_t
name|dot3StatsInternalMacReceiveErrors
decl_stmt|;
comment|/* 11 */
comment|/* 	 * interface stats, taken from RFC 1213, MIB-II, interfaces group 	 */
specifier|volatile
name|u_int32_t
name|ifIndex
decl_stmt|;
comment|/* 12 */
specifier|volatile
name|u_int32_t
name|ifType
decl_stmt|;
comment|/* 13 */
specifier|volatile
name|u_int32_t
name|ifMtu
decl_stmt|;
comment|/* 14 */
specifier|volatile
name|u_int32_t
name|ifSpeed
decl_stmt|;
comment|/* 15 */
specifier|volatile
name|u_int32_t
name|ifAdminStatus
decl_stmt|;
comment|/* 16 */
define|#
directive|define
name|IF_ADMIN_STATUS_UP
value|1
define|#
directive|define
name|IF_ADMIN_STATUS_DOWN
value|2
define|#
directive|define
name|IF_ADMIN_STATUS_TESTING
value|3
specifier|volatile
name|u_int32_t
name|ifOperStatus
decl_stmt|;
comment|/* 17 */
define|#
directive|define
name|IF_OPER_STATUS_UP
value|1
define|#
directive|define
name|IF_OPER_STATUS_DOWN
value|2
define|#
directive|define
name|IF_OPER_STATUS_TESTING
value|3
define|#
directive|define
name|IF_OPER_STATUS_UNKNOWN
value|4
define|#
directive|define
name|IF_OPER_STATUS_DORMANT
value|5
specifier|volatile
name|u_int32_t
name|ifLastChange
decl_stmt|;
comment|/* 18 */
specifier|volatile
name|u_int32_t
name|ifInDiscards
decl_stmt|;
comment|/* 19 */
specifier|volatile
name|u_int32_t
name|ifInErrors
decl_stmt|;
comment|/* 20 */
specifier|volatile
name|u_int32_t
name|ifInUnknownProtos
decl_stmt|;
comment|/* 21 */
specifier|volatile
name|u_int32_t
name|ifOutDiscards
decl_stmt|;
comment|/* 22 */
specifier|volatile
name|u_int32_t
name|ifOutErrors
decl_stmt|;
comment|/* 23 */
specifier|volatile
name|u_int32_t
name|ifOutQLen
decl_stmt|;
comment|/* deprecated */
comment|/* 24 */
specifier|volatile
name|u_int8_t
name|ifPhysAddress
index|[
literal|8
index|]
decl_stmt|;
comment|/* 8 bytes */
comment|/* 25 - 26 */
specifier|volatile
name|u_int8_t
name|ifDescr
index|[
literal|32
index|]
decl_stmt|;
comment|/* 27 - 34 */
name|u_int32_t
name|alignIt
decl_stmt|;
comment|/* align to 64 bit for u_int64_ts following */
comment|/* 	 * more interface stats, taken from RFC 1573, MIB-IIupdate, 	 * interfaces group 	 */
specifier|volatile
name|u_int64_t
name|ifHCInOctets
decl_stmt|;
comment|/* 36 - 37 */
specifier|volatile
name|u_int64_t
name|ifHCInUcastPkts
decl_stmt|;
comment|/* 38 - 39 */
specifier|volatile
name|u_int64_t
name|ifHCInMulticastPkts
decl_stmt|;
comment|/* 40 - 41 */
specifier|volatile
name|u_int64_t
name|ifHCInBroadcastPkts
decl_stmt|;
comment|/* 42 - 43 */
specifier|volatile
name|u_int64_t
name|ifHCOutOctets
decl_stmt|;
comment|/* 44 - 45 */
specifier|volatile
name|u_int64_t
name|ifHCOutUcastPkts
decl_stmt|;
comment|/* 46 - 47 */
specifier|volatile
name|u_int64_t
name|ifHCOutMulticastPkts
decl_stmt|;
comment|/* 48 - 49 */
specifier|volatile
name|u_int64_t
name|ifHCOutBroadcastPkts
decl_stmt|;
comment|/* 50 - 51 */
specifier|volatile
name|u_int32_t
name|ifLinkUpDownTrapEnable
decl_stmt|;
comment|/* 52 */
specifier|volatile
name|u_int32_t
name|ifHighSpeed
decl_stmt|;
comment|/* 53 */
specifier|volatile
name|u_int32_t
name|ifPromiscuousMode
decl_stmt|;
comment|/* 54 */
specifier|volatile
name|u_int32_t
name|ifConnectorPresent
decl_stmt|;
comment|/* follow link state 55 */
comment|/* 	 * Host Commands 	 */
specifier|volatile
name|u_int32_t
name|nicCmdsHostState
decl_stmt|;
comment|/* 56 */
specifier|volatile
name|u_int32_t
name|nicCmdsFDRFiltering
decl_stmt|;
comment|/* 57 */
specifier|volatile
name|u_int32_t
name|nicCmdsSetRecvProdIndex
decl_stmt|;
comment|/* 58 */
specifier|volatile
name|u_int32_t
name|nicCmdsUpdateGencommStats
decl_stmt|;
comment|/* 59 */
specifier|volatile
name|u_int32_t
name|nicCmdsResetJumboRing
decl_stmt|;
comment|/* 60 */
specifier|volatile
name|u_int32_t
name|nicCmdsAddMCastAddr
decl_stmt|;
comment|/* 61 */
specifier|volatile
name|u_int32_t
name|nicCmdsDelMCastAddr
decl_stmt|;
comment|/* 62 */
specifier|volatile
name|u_int32_t
name|nicCmdsSetPromiscMode
decl_stmt|;
comment|/* 63 */
specifier|volatile
name|u_int32_t
name|nicCmdsLinkNegotiate
decl_stmt|;
comment|/* 64 */
specifier|volatile
name|u_int32_t
name|nicCmdsSetMACAddr
decl_stmt|;
comment|/* 65 */
specifier|volatile
name|u_int32_t
name|nicCmdsClearProfile
decl_stmt|;
comment|/* 66 */
specifier|volatile
name|u_int32_t
name|nicCmdsSetMulticastMode
decl_stmt|;
comment|/* 67 */
specifier|volatile
name|u_int32_t
name|nicCmdsClearStats
decl_stmt|;
comment|/* 68 */
specifier|volatile
name|u_int32_t
name|nicCmdsSetRecvJumboProdIndex
decl_stmt|;
comment|/* 69 */
specifier|volatile
name|u_int32_t
name|nicCmdsSetRecvMiniProdIndex
decl_stmt|;
comment|/* 70 */
specifier|volatile
name|u_int32_t
name|nicCmdsRefreshStats
decl_stmt|;
comment|/* 71 */
specifier|volatile
name|u_int32_t
name|nicCmdsUnknown
decl_stmt|;
comment|/* 72 */
comment|/* 	 * NIC Events 	 */
specifier|volatile
name|u_int32_t
name|nicEventsNICFirmwareOperational
decl_stmt|;
comment|/* 73 */
specifier|volatile
name|u_int32_t
name|nicEventsStatsUpdated
decl_stmt|;
comment|/* 74 */
specifier|volatile
name|u_int32_t
name|nicEventsLinkStateChanged
decl_stmt|;
comment|/* 75 */
specifier|volatile
name|u_int32_t
name|nicEventsError
decl_stmt|;
comment|/* 76 */
specifier|volatile
name|u_int32_t
name|nicEventsMCastListUpdated
decl_stmt|;
comment|/* 77 */
specifier|volatile
name|u_int32_t
name|nicEventsResetJumboRing
decl_stmt|;
comment|/* 78 */
comment|/* 	 * Ring manipulation 	 */
specifier|volatile
name|u_int32_t
name|nicRingSetSendProdIndex
decl_stmt|;
comment|/* 79 */
specifier|volatile
name|u_int32_t
name|nicRingSetSendConsIndex
decl_stmt|;
comment|/* 80 */
specifier|volatile
name|u_int32_t
name|nicRingSetRecvReturnProdIndex
decl_stmt|;
comment|/* 81 */
comment|/* 	 * Interrupts 	 */
specifier|volatile
name|u_int32_t
name|nicInterrupts
decl_stmt|;
comment|/* 82 */
specifier|volatile
name|u_int32_t
name|nicAvoidedInterrupts
decl_stmt|;
comment|/* 83 */
comment|/* 	 * BD Coalessing Thresholds 	 */
specifier|volatile
name|u_int32_t
name|nicEventThresholdHit
decl_stmt|;
comment|/* 84 */
specifier|volatile
name|u_int32_t
name|nicSendThresholdHit
decl_stmt|;
comment|/* 85 */
specifier|volatile
name|u_int32_t
name|nicRecvThresholdHit
decl_stmt|;
comment|/* 86 */
comment|/* 	 * DMA Attentions 	 */
specifier|volatile
name|u_int32_t
name|nicDmaRdOverrun
decl_stmt|;
comment|/* 87 */
specifier|volatile
name|u_int32_t
name|nicDmaRdUnderrun
decl_stmt|;
comment|/* 88 */
specifier|volatile
name|u_int32_t
name|nicDmaWrOverrun
decl_stmt|;
comment|/* 89 */
specifier|volatile
name|u_int32_t
name|nicDmaWrUnderrun
decl_stmt|;
comment|/* 90 */
specifier|volatile
name|u_int32_t
name|nicDmaWrMasterAborts
decl_stmt|;
comment|/* 91 */
specifier|volatile
name|u_int32_t
name|nicDmaRdMasterAborts
decl_stmt|;
comment|/* 92 */
comment|/* 	 * NIC Resources 	 */
specifier|volatile
name|u_int32_t
name|nicDmaWriteRingFull
decl_stmt|;
comment|/* 93 */
specifier|volatile
name|u_int32_t
name|nicDmaReadRingFull
decl_stmt|;
comment|/* 94 */
specifier|volatile
name|u_int32_t
name|nicEventRingFull
decl_stmt|;
comment|/* 95 */
specifier|volatile
name|u_int32_t
name|nicEventProducerRingFull
decl_stmt|;
comment|/* 96 */
specifier|volatile
name|u_int32_t
name|nicTxMacDescrRingFull
decl_stmt|;
comment|/* 97 */
specifier|volatile
name|u_int32_t
name|nicOutOfTxBufSpaceFrameRetry
decl_stmt|;
comment|/* 98 */
specifier|volatile
name|u_int32_t
name|nicNoMoreWrDMADescriptors
decl_stmt|;
comment|/* 99 */
specifier|volatile
name|u_int32_t
name|nicNoMoreRxBDs
decl_stmt|;
comment|/* 100 */
specifier|volatile
name|u_int32_t
name|nicNoSpaceInReturnRing
decl_stmt|;
comment|/* 101 */
specifier|volatile
name|u_int32_t
name|nicSendBDs
decl_stmt|;
comment|/* current count 102 */
specifier|volatile
name|u_int32_t
name|nicRecvBDs
decl_stmt|;
comment|/* current count 103 */
specifier|volatile
name|u_int32_t
name|nicJumboRecvBDs
decl_stmt|;
comment|/* current count 104 */
specifier|volatile
name|u_int32_t
name|nicMiniRecvBDs
decl_stmt|;
comment|/* current count 105 */
specifier|volatile
name|u_int32_t
name|nicTotalRecvBDs
decl_stmt|;
comment|/* current count 106 */
specifier|volatile
name|u_int32_t
name|nicTotalSendBDs
decl_stmt|;
comment|/* current count 107 */
specifier|volatile
name|u_int32_t
name|nicJumboSpillOver
decl_stmt|;
comment|/* 108 */
specifier|volatile
name|u_int32_t
name|nicSbusHangCleared
decl_stmt|;
comment|/* 109 */
specifier|volatile
name|u_int32_t
name|nicEnqEventDelayed
decl_stmt|;
comment|/* 110 */
comment|/* 	 * Stats from MAC rx completion 	 */
specifier|volatile
name|u_int32_t
name|nicMacRxLateColls
decl_stmt|;
comment|/* 111 */
specifier|volatile
name|u_int32_t
name|nicMacRxLinkLostDuringPkt
decl_stmt|;
comment|/* 112 */
specifier|volatile
name|u_int32_t
name|nicMacRxPhyDecodeErr
decl_stmt|;
comment|/* 113 */
specifier|volatile
name|u_int32_t
name|nicMacRxMacAbort
decl_stmt|;
comment|/* 114 */
specifier|volatile
name|u_int32_t
name|nicMacRxTruncNoResources
decl_stmt|;
comment|/* 115 */
comment|/* 	 * Stats from the mac_stats area 	 */
specifier|volatile
name|u_int32_t
name|nicMacRxDropUla
decl_stmt|;
comment|/* 116 */
specifier|volatile
name|u_int32_t
name|nicMacRxDropMcast
decl_stmt|;
comment|/* 117 */
specifier|volatile
name|u_int32_t
name|nicMacRxFlowControl
decl_stmt|;
comment|/* 118 */
specifier|volatile
name|u_int32_t
name|nicMacRxDropSpace
decl_stmt|;
comment|/* 119 */
specifier|volatile
name|u_int32_t
name|nicMacRxColls
decl_stmt|;
comment|/* 120 */
comment|/*  	 * MAC RX Attentions 	 */
specifier|volatile
name|u_int32_t
name|nicMacRxTotalAttns
decl_stmt|;
comment|/* 121 */
specifier|volatile
name|u_int32_t
name|nicMacRxLinkAttns
decl_stmt|;
comment|/* 122 */
specifier|volatile
name|u_int32_t
name|nicMacRxSyncAttns
decl_stmt|;
comment|/* 123 */
specifier|volatile
name|u_int32_t
name|nicMacRxConfigAttns
decl_stmt|;
comment|/* 124 */
specifier|volatile
name|u_int32_t
name|nicMacReset
decl_stmt|;
comment|/* 125 */
specifier|volatile
name|u_int32_t
name|nicMacRxBufDescrAttns
decl_stmt|;
comment|/* 126 */
specifier|volatile
name|u_int32_t
name|nicMacRxBufAttns
decl_stmt|;
comment|/* 127 */
specifier|volatile
name|u_int32_t
name|nicMacRxZeroFrameCleanup
decl_stmt|;
comment|/* 128 */
specifier|volatile
name|u_int32_t
name|nicMacRxOneFrameCleanup
decl_stmt|;
comment|/* 129 */
specifier|volatile
name|u_int32_t
name|nicMacRxMultipleFrameCleanup
decl_stmt|;
comment|/* 130 */
specifier|volatile
name|u_int32_t
name|nicMacRxTimerCleanup
decl_stmt|;
comment|/* 131 */
specifier|volatile
name|u_int32_t
name|nicMacRxDmaCleanup
decl_stmt|;
comment|/* 132 */
comment|/* 	 * Stats from the mac_stats area 	 */
specifier|volatile
name|u_int32_t
name|nicMacTxCollisionHistogram
index|[
literal|15
index|]
decl_stmt|;
comment|/* 133 */
comment|/* 	 * MAC TX Attentions 	 */
specifier|volatile
name|u_int32_t
name|nicMacTxTotalAttns
decl_stmt|;
comment|/* 134 */
comment|/* 	 * NIC Profile 	 */
specifier|volatile
name|u_int32_t
name|nicProfile
index|[
literal|32
index|]
decl_stmt|;
comment|/* 135 */
comment|/* 	 * Pat to 1024 bytes. 	 */
name|u_int32_t
name|pad
index|[
literal|75
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tg_reg
block|{
name|u_int32_t
name|data
decl_stmt|;
name|u_int32_t
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tg_mem
block|{
name|u_int32_t
name|tgAddr
decl_stmt|;
name|caddr_t
name|userAddr
decl_stmt|;
name|int
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|TI_PARAM_NONE
init|=
literal|0x00
block|,
name|TI_PARAM_STAT_TICKS
init|=
literal|0x01
block|,
name|TI_PARAM_RX_COAL_TICKS
init|=
literal|0x02
block|,
name|TI_PARAM_TX_COAL_TICKS
init|=
literal|0x04
block|,
name|TI_PARAM_RX_COAL_BDS
init|=
literal|0x08
block|,
name|TI_PARAM_TX_COAL_BDS
init|=
literal|0x10
block|,
name|TI_PARAM_TX_BUF_RATIO
init|=
literal|0x20
block|,
name|TI_PARAM_ALL
init|=
literal|0x2f
block|}
name|ti_param_mask
typedef|;
end_typedef

begin_struct
struct|struct
name|ti_params
block|{
name|u_int32_t
name|ti_stat_ticks
decl_stmt|;
name|u_int32_t
name|ti_rx_coal_ticks
decl_stmt|;
name|u_int32_t
name|ti_tx_coal_ticks
decl_stmt|;
name|u_int32_t
name|ti_rx_max_coal_bds
decl_stmt|;
name|u_int32_t
name|ti_tx_max_coal_bds
decl_stmt|;
name|u_int32_t
name|ti_tx_buf_ratio
decl_stmt|;
name|ti_param_mask
name|param_mask
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|TI_TRACE_TYPE_NONE
init|=
literal|0x00000000
block|,
name|TI_TRACE_TYPE_SEND
init|=
literal|0x00000001
block|,
name|TI_TRACE_TYPE_RECV
init|=
literal|0x00000002
block|,
name|TI_TRACE_TYPE_DMA
init|=
literal|0x00000004
block|,
name|TI_TRACE_TYPE_EVENT
init|=
literal|0x00000008
block|,
name|TI_TRACE_TYPE_COMMAND
init|=
literal|0x00000010
block|,
name|TI_TRACE_TYPE_MAC
init|=
literal|0x00000020
block|,
name|TI_TRACE_TYPE_STATS
init|=
literal|0x00000040
block|,
name|TI_TRACE_TYPE_TIMER
init|=
literal|0x00000080
block|,
name|TI_TRACE_TYPE_DISP
init|=
literal|0x00000100
block|,
name|TI_TRACE_TYPE_MAILBOX
init|=
literal|0x00000200
block|,
name|TI_TRACE_TYPE_RECV_BD
init|=
literal|0x00000400
block|,
name|TI_TRACE_TYPE_LNK_PHY
init|=
literal|0x00000800
block|,
name|TI_TRACE_TYPE_LNK_NEG
init|=
literal|0x00001000
block|,
name|TI_TRACE_LEVEL_1
init|=
literal|0x10000000
block|,
name|TI_TRACE_LEVEL_2
init|=
literal|0x20000000
block|}
name|ti_trace_type
typedef|;
end_typedef

begin_struct
struct|struct
name|ti_trace_buf
block|{
name|u_long
modifier|*
name|buf
decl_stmt|;
name|int
name|buf_len
decl_stmt|;
name|int
name|fill_len
decl_stmt|;
name|u_long
name|cur_trace_ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TIIOCGETSTATS
value|_IOR('T', 1, struct ti_stats)
end_define

begin_define
define|#
directive|define
name|TIIOCGETPARAMS
value|_IOR('T', 2, struct ti_params)
end_define

begin_define
define|#
directive|define
name|TIIOCSETPARAMS
value|_IOW('T', 3, struct ti_params)
end_define

begin_define
define|#
directive|define
name|TIIOCSETTRACE
value|_IOW('T', 11, ti_trace_type)
end_define

begin_define
define|#
directive|define
name|TIIOCGETTRACE
value|_IOWR('T', 12, struct ti_trace_buf)
end_define

begin_comment
comment|/*  * Taken from Alteon's altioctl.h.  Alteon's ioctl numbers 1-6 aren't  * used by the FreeBSD driver.  */
end_comment

begin_define
define|#
directive|define
name|ALT_ATTACH
value|_IO('a', 7)
end_define

begin_define
define|#
directive|define
name|ALT_READ_TG_MEM
value|_IOWR('a', 10, struct tg_mem)
end_define

begin_define
define|#
directive|define
name|ALT_WRITE_TG_MEM
value|_IOWR('a', 11, struct tg_mem)
end_define

begin_define
define|#
directive|define
name|ALT_READ_TG_REG
value|_IOWR('a', 12, struct tg_reg)
end_define

begin_define
define|#
directive|define
name|ALT_WRITE_TG_REG
value|_IOWR('a', 13, struct tg_reg)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_TIIO_H_  */
end_comment

end_unit

