begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2006 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ATH_AR5211DESC_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ATH_AR5211DESC_H
end_define

begin_comment
comment|/*  * Defintions for the DMA descriptors used by the Atheros  * AR5211 and AR5110 Wireless Lan controller parts.  */
end_comment

begin_comment
comment|/* DMA descriptors */
end_comment

begin_struct
struct|struct
name|ar5211_desc
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
name|uint32_t
name|ds_status0
decl_stmt|;
comment|/* DMA status 0 */
name|uint32_t
name|ds_status1
decl_stmt|;
comment|/* DMA status 1 */
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|AR5211DESC
parameter_list|(
name|_ds
parameter_list|)
value|((struct ar5211_desc *)(_ds))
end_define

begin_define
define|#
directive|define
name|AR5211DESC_CONST
parameter_list|(
name|_ds
parameter_list|)
value|((const struct ar5211_desc *)(_ds))
end_define

begin_comment
comment|/* TX ds_ctl0 */
end_comment

begin_define
define|#
directive|define
name|AR_FrameLen
value|0x00000fff
end_define

begin_comment
comment|/* frame length */
end_comment

begin_comment
comment|/* bits 12-17 are reserved */
end_comment

begin_define
define|#
directive|define
name|AR_XmitRate
value|0x003c0000
end_define

begin_comment
comment|/* txrate */
end_comment

begin_define
define|#
directive|define
name|AR_XmitRate_S
value|18
end_define

begin_define
define|#
directive|define
name|AR_RTSCTSEnable
value|0x00400000
end_define

begin_comment
comment|/* RTS/CTS enable */
end_comment

begin_define
define|#
directive|define
name|AR_VEOL
value|0x00800000
end_define

begin_comment
comment|/* virtual end-of-list */
end_comment

begin_define
define|#
directive|define
name|AR_ClearDestMask
value|0x01000000
end_define

begin_comment
comment|/* Clear destination mask bit */
end_comment

begin_define
define|#
directive|define
name|AR_AntModeXmit
value|0x1e000000
end_define

begin_comment
comment|/* TX antenna seslection */
end_comment

begin_define
define|#
directive|define
name|AR_AntModeXmit_S
value|25
end_define

begin_define
define|#
directive|define
name|AR_TxInterReq
value|0x20000000
end_define

begin_comment
comment|/* TX interrupt request */
end_comment

begin_define
define|#
directive|define
name|AR_EncryptKeyValid
value|0x40000000
end_define

begin_comment
comment|/* EncryptKeyIdx is valid */
end_comment

begin_comment
comment|/* bit 31 is reserved */
end_comment

begin_comment
comment|/* TX ds_ctl1 */
end_comment

begin_define
define|#
directive|define
name|AR_BufLen
value|0x00000fff
end_define

begin_comment
comment|/* data buffer length */
end_comment

begin_define
define|#
directive|define
name|AR_More
value|0x00001000
end_define

begin_comment
comment|/* more desc in this frame */
end_comment

begin_define
define|#
directive|define
name|AR_EncryptKeyIdx
value|0x000fe000
end_define

begin_comment
comment|/* ecnrypt key table index */
end_comment

begin_define
define|#
directive|define
name|AR_EncryptKeyIdx_S
value|13
end_define

begin_define
define|#
directive|define
name|AR_FrmType
value|0x00700000
end_define

begin_comment
comment|/* frame type indication */
end_comment

begin_define
define|#
directive|define
name|AR_FrmType_S
value|20
end_define

begin_define
define|#
directive|define
name|AR_Frm_Normal
value|0x00000000
end_define

begin_comment
comment|/* normal frame */
end_comment

begin_define
define|#
directive|define
name|AR_Frm_ATIM
value|0x00100000
end_define

begin_comment
comment|/* ATIM frame */
end_comment

begin_define
define|#
directive|define
name|AR_Frm_PSPOLL
value|0x00200000
end_define

begin_comment
comment|/* PS poll frame */
end_comment

begin_define
define|#
directive|define
name|AR_Frm_Beacon
value|0x00300000
end_define

begin_comment
comment|/* Beacon frame */
end_comment

begin_define
define|#
directive|define
name|AR_Frm_ProbeResp
value|0x00400000
end_define

begin_comment
comment|/* no delay data */
end_comment

begin_define
define|#
directive|define
name|AR_NoAck
value|0x00800000
end_define

begin_comment
comment|/* No ACK flag */
end_comment

begin_comment
comment|/* bits 24-31 are reserved */
end_comment

begin_comment
comment|/* RX ds_ctl1 */
end_comment

begin_comment
comment|/*	AR_BufLen		0x00000fff	   data buffer length */
end_comment

begin_comment
comment|/* bit 12 is reserved */
end_comment

begin_define
define|#
directive|define
name|AR_RxInterReq
value|0x00002000
end_define

begin_comment
comment|/* RX interrupt request */
end_comment

begin_comment
comment|/* bits 14-31 are reserved */
end_comment

begin_comment
comment|/* TX ds_status0 */
end_comment

begin_define
define|#
directive|define
name|AR_FrmXmitOK
value|0x00000001
end_define

begin_comment
comment|/* TX success */
end_comment

begin_define
define|#
directive|define
name|AR_ExcessiveRetries
value|0x00000002
end_define

begin_comment
comment|/* excessive retries */
end_comment

begin_define
define|#
directive|define
name|AR_FIFOUnderrun
value|0x00000004
end_define

begin_comment
comment|/* TX FIFO underrun */
end_comment

begin_define
define|#
directive|define
name|AR_Filtered
value|0x00000008
end_define

begin_comment
comment|/* TX filter indication */
end_comment

begin_comment
comment|/* NB: the spec has the Short+Long retry counts reversed */
end_comment

begin_define
define|#
directive|define
name|AR_LongRetryCnt
value|0x000000f0
end_define

begin_comment
comment|/* long retry count */
end_comment

begin_define
define|#
directive|define
name|AR_LongRetryCnt_S
value|4
end_define

begin_define
define|#
directive|define
name|AR_ShortRetryCnt
value|0x00000f00
end_define

begin_comment
comment|/* short retry count */
end_comment

begin_define
define|#
directive|define
name|AR_ShortRetryCnt_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_VirtCollCnt
value|0x0000f000
end_define

begin_comment
comment|/* virtual collision count */
end_comment

begin_define
define|#
directive|define
name|AR_VirtCollCnt_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_SendTimestamp
value|0xffff0000
end_define

begin_comment
comment|/* TX timestamp */
end_comment

begin_define
define|#
directive|define
name|AR_SendTimestamp_S
value|16
end_define

begin_comment
comment|/* RX ds_status0 */
end_comment

begin_define
define|#
directive|define
name|AR_DataLen
value|0x00000fff
end_define

begin_comment
comment|/* RX data length */
end_comment

begin_comment
comment|/*	AR_More			0x00001000	   more desc in this frame */
end_comment

begin_comment
comment|/* bits 13-14 are reserved */
end_comment

begin_define
define|#
directive|define
name|AR_RcvRate
value|0x00078000
end_define

begin_comment
comment|/* reception rate */
end_comment

begin_define
define|#
directive|define
name|AR_RcvRate_S
value|15
end_define

begin_define
define|#
directive|define
name|AR_RcvSigStrength
value|0x07f80000
end_define

begin_comment
comment|/* receive signal strength */
end_comment

begin_define
define|#
directive|define
name|AR_RcvSigStrength_S
value|19
end_define

begin_define
define|#
directive|define
name|AR_RcvAntenna
value|0x38000000
end_define

begin_comment
comment|/* receive antenaa */
end_comment

begin_define
define|#
directive|define
name|AR_RcvAntenna_S
value|27
end_define

begin_comment
comment|/* bits 30-31 are reserved */
end_comment

begin_comment
comment|/* TX ds_status1 */
end_comment

begin_define
define|#
directive|define
name|AR_Done
value|0x00000001
end_define

begin_comment
comment|/* descripter complete */
end_comment

begin_define
define|#
directive|define
name|AR_SeqNum
value|0x00001ffe
end_define

begin_comment
comment|/* TX sequence number */
end_comment

begin_define
define|#
directive|define
name|AR_SeqNum_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_AckSigStrength
value|0x001fe000
end_define

begin_comment
comment|/* strength of ACK */
end_comment

begin_define
define|#
directive|define
name|AR_AckSigStrength_S
value|13
end_define

begin_comment
comment|/* bits 21-31 are reserved */
end_comment

begin_comment
comment|/* RX ds_status1 */
end_comment

begin_comment
comment|/*	AR_Done			0x00000001	   descripter complete */
end_comment

begin_define
define|#
directive|define
name|AR_FrmRcvOK
value|0x00000002
end_define

begin_comment
comment|/* frame reception success */
end_comment

begin_define
define|#
directive|define
name|AR_CRCErr
value|0x00000004
end_define

begin_comment
comment|/* CRC error */
end_comment

begin_comment
comment|/* bit 3 reserved */
end_comment

begin_define
define|#
directive|define
name|AR_DecryptCRCErr
value|0x00000010
end_define

begin_comment
comment|/* Decryption CRC fiailure */
end_comment

begin_define
define|#
directive|define
name|AR_PHYErr
value|0x000000e0
end_define

begin_comment
comment|/* PHY error */
end_comment

begin_define
define|#
directive|define
name|AR_PHYErr_S
value|5
end_define

begin_define
define|#
directive|define
name|AR_PHYErr_Underrun
value|0x00000000
end_define

begin_comment
comment|/* Transmit underrun */
end_comment

begin_define
define|#
directive|define
name|AR_PHYErr_Tim
value|0x00000020
end_define

begin_comment
comment|/* Timing error */
end_comment

begin_define
define|#
directive|define
name|AR_PHYErr_Par
value|0x00000040
end_define

begin_comment
comment|/* Parity error */
end_comment

begin_define
define|#
directive|define
name|AR_PHYErr_Rate
value|0x00000060
end_define

begin_comment
comment|/* Illegal rate */
end_comment

begin_define
define|#
directive|define
name|AR_PHYErr_Len
value|0x00000080
end_define

begin_comment
comment|/* Illegal length */
end_comment

begin_define
define|#
directive|define
name|AR_PHYErr_Radar
value|0x000000a0
end_define

begin_comment
comment|/* Radar detect */
end_comment

begin_define
define|#
directive|define
name|AR_PHYErr_Srv
value|0x000000c0
end_define

begin_comment
comment|/* Illegal service */
end_comment

begin_define
define|#
directive|define
name|AR_PHYErr_TOR
value|0x000000e0
end_define

begin_comment
comment|/* Transmit override receive */
end_comment

begin_define
define|#
directive|define
name|AR_KeyIdxValid
value|0x00000100
end_define

begin_comment
comment|/* decryption key index valid */
end_comment

begin_define
define|#
directive|define
name|AR_KeyIdx
value|0x00007e00
end_define

begin_comment
comment|/* Decryption key index */
end_comment

begin_define
define|#
directive|define
name|AR_KeyIdx_S
value|9
end_define

begin_define
define|#
directive|define
name|AR_RcvTimestamp
value|0x0fff8000
end_define

begin_comment
comment|/* timestamp */
end_comment

begin_define
define|#
directive|define
name|AR_RcvTimestamp_S
value|15
end_define

begin_define
define|#
directive|define
name|AR_KeyCacheMiss
value|0x10000000
end_define

begin_comment
comment|/* key cache miss indication */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_ATH_AR5211DESC_H_ */
end_comment

end_unit

