begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATH_AR5416_DESC_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATH_AR5416_DESC_H
end_define

begin_comment
comment|/*  * Hardware-specific descriptor structures.  */
end_comment

begin_include
include|#
directive|include
file|"ah_desc.h"
end_include

begin_comment
comment|/* XXX Need to replace this with a dynamic   * method of determining Owl2 if possible   */
end_comment

begin_define
define|#
directive|define
name|_get_index
parameter_list|(
name|_ah
parameter_list|)
value|( IS_5416V1(_ah)  ? -4 : 0 )
end_define

begin_define
define|#
directive|define
name|AR5416_DS_TXSTATUS
parameter_list|(
name|_ah
parameter_list|,
name|_ads
parameter_list|)
define|\
value|((uint32_t*)(&(_ads)->u.tx.status[_get_index(_ah)]))
end_define

begin_define
define|#
directive|define
name|AR5416_DS_TXSTATUS_CONST
parameter_list|(
name|_ah
parameter_list|,
name|_ads
parameter_list|)
define|\
value|((const uint32_t*)(&(_ads)->u.tx.status[_get_index(_ah)]))
end_define

begin_define
define|#
directive|define
name|AR5416_NUM_TX_STATUS
value|10
end_define

begin_comment
comment|/* Number of TX status words */
end_comment

begin_comment
comment|/* Clear the whole descriptor */
end_comment

begin_define
define|#
directive|define
name|AR5416_DESC_TX_CTL_SZ
value|sizeof(struct ar5416_tx_desc)
end_define

begin_struct
struct|struct
name|ar5416_tx_desc
block|{
comment|/* tx desc has 12 control words + 10 status words */
name|uint32_t
name|ctl2
decl_stmt|;
name|uint32_t
name|ctl3
decl_stmt|;
name|uint32_t
name|ctl4
decl_stmt|;
name|uint32_t
name|ctl5
decl_stmt|;
name|uint32_t
name|ctl6
decl_stmt|;
name|uint32_t
name|ctl7
decl_stmt|;
name|uint32_t
name|ctl8
decl_stmt|;
name|uint32_t
name|ctl9
decl_stmt|;
name|uint32_t
name|ctl10
decl_stmt|;
name|uint32_t
name|ctl11
decl_stmt|;
name|uint32_t
name|status
index|[
name|AR5416_NUM_TX_STATUS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ar5416_rx_desc
block|{
comment|/* rx desc has 2 control words + 9 status words */
name|uint32_t
name|status0
decl_stmt|;
name|uint32_t
name|status1
decl_stmt|;
name|uint32_t
name|status2
decl_stmt|;
name|uint32_t
name|status3
decl_stmt|;
name|uint32_t
name|status4
decl_stmt|;
name|uint32_t
name|status5
decl_stmt|;
name|uint32_t
name|status6
decl_stmt|;
name|uint32_t
name|status7
decl_stmt|;
name|uint32_t
name|status8
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ar5416_desc
block|{
name|uint32_t
name|ds_link
decl_stmt|;
comment|/* link pointer */
name|uint32_t
name|ds_data
decl_stmt|;
comment|/* data buffer pointer */
name|uint32_t
name|ds_ctl0
decl_stmt|;
comment|/* DMA control 0 */
name|uint32_t
name|ds_ctl1
decl_stmt|;
comment|/* DMA control 1 */
union|union
block|{
name|struct
name|ar5416_tx_desc
name|tx
decl_stmt|;
name|struct
name|ar5416_rx_desc
name|rx
decl_stmt|;
block|}
name|u
union|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|AR5416DESC
parameter_list|(
name|_ds
parameter_list|)
value|((struct ar5416_desc *)(_ds))
end_define

begin_define
define|#
directive|define
name|AR5416DESC_CONST
parameter_list|(
name|_ds
parameter_list|)
value|((const struct ar5416_desc *)(_ds))
end_define

begin_define
define|#
directive|define
name|ds_ctl2
value|u.tx.ctl2
end_define

begin_define
define|#
directive|define
name|ds_ctl3
value|u.tx.ctl3
end_define

begin_define
define|#
directive|define
name|ds_ctl4
value|u.tx.ctl4
end_define

begin_define
define|#
directive|define
name|ds_ctl5
value|u.tx.ctl5
end_define

begin_define
define|#
directive|define
name|ds_ctl6
value|u.tx.ctl6
end_define

begin_define
define|#
directive|define
name|ds_ctl7
value|u.tx.ctl7
end_define

begin_define
define|#
directive|define
name|ds_ctl8
value|u.tx.ctl8
end_define

begin_define
define|#
directive|define
name|ds_ctl9
value|u.tx.ctl9
end_define

begin_define
define|#
directive|define
name|ds_ctl10
value|u.tx.ctl10
end_define

begin_define
define|#
directive|define
name|ds_ctl11
value|u.tx.ctl11
end_define

begin_define
define|#
directive|define
name|ds_rxstatus0
value|u.rx.status0
end_define

begin_define
define|#
directive|define
name|ds_rxstatus1
value|u.rx.status1
end_define

begin_define
define|#
directive|define
name|ds_rxstatus2
value|u.rx.status2
end_define

begin_define
define|#
directive|define
name|ds_rxstatus3
value|u.rx.status3
end_define

begin_define
define|#
directive|define
name|ds_rxstatus4
value|u.rx.status4
end_define

begin_define
define|#
directive|define
name|ds_rxstatus5
value|u.rx.status5
end_define

begin_define
define|#
directive|define
name|ds_rxstatus6
value|u.rx.status6
end_define

begin_define
define|#
directive|define
name|ds_rxstatus7
value|u.rx.status7
end_define

begin_define
define|#
directive|define
name|ds_rxstatus8
value|u.rx.status8
end_define

begin_comment
comment|/***********  * TX Desc *  ***********/
end_comment

begin_comment
comment|/* ds_ctl0 */
end_comment

begin_define
define|#
directive|define
name|AR_FrameLen
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|AR_VirtMoreFrag
value|0x00001000
end_define

begin_define
define|#
directive|define
name|AR_TxCtlRsvd00
value|0x0000e000
end_define

begin_define
define|#
directive|define
name|AR_XmitPower
value|0x003f0000
end_define

begin_define
define|#
directive|define
name|AR_XmitPower_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_RTSEnable
value|0x00400000
end_define

begin_define
define|#
directive|define
name|AR_VEOL
value|0x00800000
end_define

begin_define
define|#
directive|define
name|AR_ClrDestMask
value|0x01000000
end_define

begin_define
define|#
directive|define
name|AR_TxCtlRsvd01
value|0x1e000000
end_define

begin_define
define|#
directive|define
name|AR_TxIntrReq
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AR_DestIdxValid
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AR_CTSEnable
value|0x80000000
end_define

begin_comment
comment|/* ds_ctl1 */
end_comment

begin_define
define|#
directive|define
name|AR_BufLen
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|AR_TxMore
value|0x00001000
end_define

begin_define
define|#
directive|define
name|AR_DestIdx
value|0x000fe000
end_define

begin_define
define|#
directive|define
name|AR_DestIdx_S
value|13
end_define

begin_define
define|#
directive|define
name|AR_FrameType
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|AR_FrameType_S
value|20
end_define

begin_define
define|#
directive|define
name|AR_NoAck
value|0x01000000
end_define

begin_define
define|#
directive|define
name|AR_InsertTS
value|0x02000000
end_define

begin_define
define|#
directive|define
name|AR_CorruptFCS
value|0x04000000
end_define

begin_define
define|#
directive|define
name|AR_ExtOnly
value|0x08000000
end_define

begin_define
define|#
directive|define
name|AR_ExtAndCtl
value|0x10000000
end_define

begin_define
define|#
directive|define
name|AR_MoreAggr
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AR_IsAggr
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AR_MoreRifs
value|0x80000000
end_define

begin_comment
comment|/* ds_ctl2 */
end_comment

begin_define
define|#
directive|define
name|AR_BurstDur
value|0x00007fff
end_define

begin_define
define|#
directive|define
name|AR_BurstDur_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_DurUpdateEn
value|0x00008000
end_define

begin_define
define|#
directive|define
name|AR_XmitDataTries0
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|AR_XmitDataTries0_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_XmitDataTries1
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|AR_XmitDataTries1_S
value|20
end_define

begin_define
define|#
directive|define
name|AR_XmitDataTries2
value|0x0f000000
end_define

begin_define
define|#
directive|define
name|AR_XmitDataTries2_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_XmitDataTries3
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|AR_XmitDataTries3_S
value|28
end_define

begin_comment
comment|/* ds_ctl3 */
end_comment

begin_define
define|#
directive|define
name|AR_XmitRate0
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|AR_XmitRate0_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_XmitRate1
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|AR_XmitRate1_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_XmitRate2
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|AR_XmitRate2_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_XmitRate3
value|0xff000000
end_define

begin_define
define|#
directive|define
name|AR_XmitRate3_S
value|24
end_define

begin_comment
comment|/* ds_ctl4 */
end_comment

begin_define
define|#
directive|define
name|AR_PacketDur0
value|0x00007fff
end_define

begin_define
define|#
directive|define
name|AR_PacketDur0_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_RTSCTSQual0
value|0x00008000
end_define

begin_define
define|#
directive|define
name|AR_PacketDur1
value|0x7fff0000
end_define

begin_define
define|#
directive|define
name|AR_PacketDur1_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_RTSCTSQual1
value|0x80000000
end_define

begin_comment
comment|/* ds_ctl5 */
end_comment

begin_define
define|#
directive|define
name|AR_PacketDur2
value|0x00007fff
end_define

begin_define
define|#
directive|define
name|AR_PacketDur2_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_RTSCTSQual2
value|0x00008000
end_define

begin_define
define|#
directive|define
name|AR_PacketDur3
value|0x7fff0000
end_define

begin_define
define|#
directive|define
name|AR_PacketDur3_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_RTSCTSQual3
value|0x80000000
end_define

begin_comment
comment|/* ds_ctl6 */
end_comment

begin_define
define|#
directive|define
name|AR_AggrLen
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|AR_AggrLen_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_TxCtlRsvd60
value|0x00030000
end_define

begin_define
define|#
directive|define
name|AR_PadDelim
value|0x03fc0000
end_define

begin_define
define|#
directive|define
name|AR_PadDelim_S
value|18
end_define

begin_define
define|#
directive|define
name|AR_EncrType
value|0x0c000000
end_define

begin_define
define|#
directive|define
name|AR_EncrType_S
value|26
end_define

begin_define
define|#
directive|define
name|AR_TxCtlRsvd61
value|0xf0000000
end_define

begin_comment
comment|/* ds_ctl7 */
end_comment

begin_define
define|#
directive|define
name|AR_2040_0
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_GI0
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_ChainSel0
value|0x0000001c
end_define

begin_define
define|#
directive|define
name|AR_ChainSel0_S
value|2
end_define

begin_define
define|#
directive|define
name|AR_2040_1
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AR_GI1
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AR_ChainSel1
value|0x00000380
end_define

begin_define
define|#
directive|define
name|AR_ChainSel1_S
value|7
end_define

begin_define
define|#
directive|define
name|AR_2040_2
value|0x00000400
end_define

begin_define
define|#
directive|define
name|AR_GI2
value|0x00000800
end_define

begin_define
define|#
directive|define
name|AR_ChainSel2
value|0x00007000
end_define

begin_define
define|#
directive|define
name|AR_ChainSel2_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_2040_3
value|0x00008000
end_define

begin_define
define|#
directive|define
name|AR_GI3
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AR_ChainSel3
value|0x000e0000
end_define

begin_define
define|#
directive|define
name|AR_ChainSel3_S
value|17
end_define

begin_define
define|#
directive|define
name|AR_RTSCTSRate
value|0x0ff00000
end_define

begin_define
define|#
directive|define
name|AR_RTSCTSRate_S
value|20
end_define

begin_define
define|#
directive|define
name|AR_STBC0
value|0x10000000
end_define

begin_define
define|#
directive|define
name|AR_STBC1
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AR_STBC2
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AR_STBC3
value|0x80000000
end_define

begin_comment
comment|/*************  * TX Status *  *************/
end_comment

begin_comment
comment|/* ds_status0 */
end_comment

begin_define
define|#
directive|define
name|AR_TxRSSIAnt00
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|AR_TxRSSIAnt00_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_TxRSSIAnt01
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|AR_TxRSSIAnt01_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_TxRSSIAnt02
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|AR_TxRSSIAnt02_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_TxStatusRsvd00
value|0x3f000000
end_define

begin_define
define|#
directive|define
name|AR_TxBaStatus
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AR_TxStatusRsvd01
value|0x80000000
end_define

begin_comment
comment|/* ds_status1 */
end_comment

begin_define
define|#
directive|define
name|AR_FrmXmitOK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_ExcessiveRetries
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_FIFOUnderrun
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AR_Filtered
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AR_RTSFailCnt
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|AR_RTSFailCnt_S
value|4
end_define

begin_define
define|#
directive|define
name|AR_DataFailCnt
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|AR_DataFailCnt_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_VirtRetryCnt
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|AR_VirtRetryCnt_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_TxDelimUnderrun
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AR_TxDelimUnderrun_S
value|13
end_define

begin_define
define|#
directive|define
name|AR_TxDataUnderrun
value|0x00020000
end_define

begin_define
define|#
directive|define
name|AR_TxDataUnderrun_S
value|14
end_define

begin_define
define|#
directive|define
name|AR_DescCfgErr
value|0x00040000
end_define

begin_define
define|#
directive|define
name|AR_DescCfgErr_S
value|15
end_define

begin_define
define|#
directive|define
name|AR_TxTimerExpired
value|0x00080000
end_define

begin_define
define|#
directive|define
name|AR_TxStatusRsvd10
value|0xfff00000
end_define

begin_comment
comment|/* ds_status2 */
end_comment

begin_define
define|#
directive|define
name|AR_SendTimestamp
parameter_list|(
name|_ptr
parameter_list|)
value|(_ptr)[2]
end_define

begin_comment
comment|/* ds_status3 */
end_comment

begin_define
define|#
directive|define
name|AR_BaBitmapLow
parameter_list|(
name|_ptr
parameter_list|)
value|(_ptr)[3]
end_define

begin_comment
comment|/* ds_status4 */
end_comment

begin_define
define|#
directive|define
name|AR_BaBitmapHigh
parameter_list|(
name|_ptr
parameter_list|)
value|(_ptr)[4]
end_define

begin_comment
comment|/* ds_status5 */
end_comment

begin_define
define|#
directive|define
name|AR_TxRSSIAnt10
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|AR_TxRSSIAnt10_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_TxRSSIAnt11
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|AR_TxRSSIAnt11_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_TxRSSIAnt12
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|AR_TxRSSIAnt12_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_TxRSSICombined
value|0xff000000
end_define

begin_define
define|#
directive|define
name|AR_TxRSSICombined_S
value|24
end_define

begin_comment
comment|/* ds_status6 */
end_comment

begin_define
define|#
directive|define
name|AR_TxEVM0
parameter_list|(
name|_ptr
parameter_list|)
value|(_ptr)[6]
end_define

begin_comment
comment|/* ds_status7 */
end_comment

begin_define
define|#
directive|define
name|AR_TxEVM1
parameter_list|(
name|_ptr
parameter_list|)
value|(_ptr)[7]
end_define

begin_comment
comment|/* ds_status8 */
end_comment

begin_define
define|#
directive|define
name|AR_TxEVM2
parameter_list|(
name|_ptr
parameter_list|)
value|(_ptr)[8]
end_define

begin_comment
comment|/* ds_status9 */
end_comment

begin_define
define|#
directive|define
name|AR_TxDone
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_SeqNum
value|0x00001ffe
end_define

begin_define
define|#
directive|define
name|AR_SeqNum_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_TxStatusRsvd80
value|0x0001e000
end_define

begin_define
define|#
directive|define
name|AR_TxOpExceeded
value|0x00020000
end_define

begin_define
define|#
directive|define
name|AR_TxStatusRsvd81
value|0x001c0000
end_define

begin_define
define|#
directive|define
name|AR_FinalTxIdx
value|0x00600000
end_define

begin_define
define|#
directive|define
name|AR_FinalTxIdx_S
value|21
end_define

begin_define
define|#
directive|define
name|AR_TxStatusRsvd82
value|0x01800000
end_define

begin_define
define|#
directive|define
name|AR_PowerMgmt
value|0x02000000
end_define

begin_define
define|#
directive|define
name|AR_TxStatusRsvd83
value|0xfc000000
end_define

begin_comment
comment|/***********  * RX Desc *  ***********/
end_comment

begin_comment
comment|/* ds_ctl0 */
end_comment

begin_define
define|#
directive|define
name|AR_RxCTLRsvd00
value|0xffffffff
end_define

begin_comment
comment|/* ds_ctl1 */
end_comment

begin_define
define|#
directive|define
name|AR_BufLen
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|AR_RxCtlRsvd00
value|0x00001000
end_define

begin_define
define|#
directive|define
name|AR_RxIntrReq
value|0x00002000
end_define

begin_define
define|#
directive|define
name|AR_RxCtlRsvd01
value|0xffffc000
end_define

begin_comment
comment|/*************  * Rx Status *  *************/
end_comment

begin_comment
comment|/* ds_status0 */
end_comment

begin_define
define|#
directive|define
name|AR_RxRSSIAnt00
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|AR_RxRSSIAnt00_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_RxRSSIAnt01
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|AR_RxRSSIAnt01_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_RxRSSIAnt02
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|AR_RxRSSIAnt02_S
value|16
end_define

begin_comment
comment|/* Rev specific */
end_comment

begin_comment
comment|/* Owl 1.x only */
end_comment

begin_define
define|#
directive|define
name|AR_RxStatusRsvd00
value|0xff000000
end_define

begin_comment
comment|/* Owl 2.x only */
end_comment

begin_define
define|#
directive|define
name|AR_RxRate
value|0xff000000
end_define

begin_define
define|#
directive|define
name|AR_RxRate_S
value|24
end_define

begin_comment
comment|/* ds_status1 */
end_comment

begin_define
define|#
directive|define
name|AR_DataLen
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|AR_RxMore
value|0x00001000
end_define

begin_define
define|#
directive|define
name|AR_NumDelim
value|0x003fc000
end_define

begin_define
define|#
directive|define
name|AR_NumDelim_S
value|14
end_define

begin_define
define|#
directive|define
name|AR_RxStatusRsvd10
value|0xff800000
end_define

begin_comment
comment|/* ds_status2 */
end_comment

begin_define
define|#
directive|define
name|AR_RcvTimestamp
value|ds_rxstatus2
end_define

begin_comment
comment|/* ds_status3 */
end_comment

begin_define
define|#
directive|define
name|AR_GI
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_2040
value|0x00000002
end_define

begin_comment
comment|/* Rev specific */
end_comment

begin_comment
comment|/* Owl 1.x only */
end_comment

begin_define
define|#
directive|define
name|AR_RxRateV1
value|0x000003fc
end_define

begin_define
define|#
directive|define
name|AR_RxRateV1_S
value|2
end_define

begin_define
define|#
directive|define
name|AR_Parallel40
value|0x00000400
end_define

begin_define
define|#
directive|define
name|AR_RxStatusRsvd30
value|0xfffff800
end_define

begin_comment
comment|/* Owl 2.x only */
end_comment

begin_define
define|#
directive|define
name|AR_DupFrame
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AR_RxAntenna
value|0xffffff00
end_define

begin_define
define|#
directive|define
name|AR_RxAntenna_S
value|8
end_define

begin_comment
comment|/* ds_status4 */
end_comment

begin_define
define|#
directive|define
name|AR_RxRSSIAnt10
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|AR_RxRSSIAnt10_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_RxRSSIAnt11
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|AR_RxRSSIAnt11_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_RxRSSIAnt12
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|AR_RxRSSIAnt12_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_RxRSSICombined
value|0xff000000
end_define

begin_define
define|#
directive|define
name|AR_RxRSSICombined_S
value|24
end_define

begin_comment
comment|/* ds_status5 */
end_comment

begin_define
define|#
directive|define
name|AR_RxEVM0
value|ds_rxstatus5
end_define

begin_comment
comment|/* ds_status6 */
end_comment

begin_define
define|#
directive|define
name|AR_RxEVM1
value|ds_rxstatus6
end_define

begin_comment
comment|/* ds_status7 */
end_comment

begin_define
define|#
directive|define
name|AR_RxEVM2
value|ds_rxstatus7
end_define

begin_comment
comment|/* ds_status8 */
end_comment

begin_define
define|#
directive|define
name|AR_RxDone
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_RxFrameOK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_CRCErr
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AR_DecryptCRCErr
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AR_PHYErr
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AR_MichaelErr
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AR_PreDelimCRCErr
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AR_RxStatusRsvd70
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AR_RxKeyIdxValid
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AR_KeyIdx
value|0x0000fe00
end_define

begin_define
define|#
directive|define
name|AR_KeyIdx_S
value|9
end_define

begin_define
define|#
directive|define
name|AR_PHYErrCode
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|AR_PHYErrCode_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_RxMoreAggr
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AR_RxAggr
value|0x00020000
end_define

begin_define
define|#
directive|define
name|AR_PostDelimCRCErr
value|0x00040000
end_define

begin_define
define|#
directive|define
name|AR_RxStatusRsvd71
value|0x2ff80000
end_define

begin_define
define|#
directive|define
name|AR_HiRxChain
value|0x10000000
end_define

begin_define
define|#
directive|define
name|AR_DecryptBusyErr
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AR_KeyMiss
value|0x80000000
end_define

begin_define
define|#
directive|define
name|TXCTL_OFFSET
parameter_list|(
name|ah
parameter_list|)
value|2
end_define

begin_define
define|#
directive|define
name|TXCTL_NUMWORDS
parameter_list|(
name|ah
parameter_list|)
value|(AR_SREV_5416_V20_OR_LATER(ah) ? 12 : 8)
end_define

begin_define
define|#
directive|define
name|TXSTATUS_OFFSET
parameter_list|(
name|ah
parameter_list|)
value|(AR_SREV_5416_V20_OR_LATER(ah) ? 14 : 10)
end_define

begin_define
define|#
directive|define
name|TXSTATUS_NUMWORDS
parameter_list|(
name|ah
parameter_list|)
value|10
end_define

begin_define
define|#
directive|define
name|RXCTL_OFFSET
parameter_list|(
name|ah
parameter_list|)
value|3
end_define

begin_define
define|#
directive|define
name|RXCTL_NUMWORDS
parameter_list|(
name|ah
parameter_list|)
value|1
end_define

begin_define
define|#
directive|define
name|RXSTATUS_OFFSET
parameter_list|(
name|ah
parameter_list|)
value|4
end_define

begin_define
define|#
directive|define
name|RXSTATUS_NUMWORDS
parameter_list|(
name|ah
parameter_list|)
value|9
end_define

begin_define
define|#
directive|define
name|RXSTATUS_RATE
parameter_list|(
name|ah
parameter_list|,
name|ads
parameter_list|)
define|\
value|(AR_SREV_OWL_20_OR_LATER(ah) ? \ 	 MS((ads)->ds_rxstatus0, AR_RxRate) : \ 	 ((ads)->ds_rxstatus3>> 2)& 0xFF)
end_define

begin_define
define|#
directive|define
name|RXSTATUS_DUPLICATE
parameter_list|(
name|ah
parameter_list|,
name|ads
parameter_list|)
define|\
value|(AR_SREV_OWL_20_OR_LATER(ah) ?	\ 	 MS((ads)->ds_rxstatus3, AR_Parallel40) : \ 	 ((ads)->ds_rxstatus3>> 10)& 0x1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ATH_AR5416_DESC_H_ */
end_comment

end_unit

