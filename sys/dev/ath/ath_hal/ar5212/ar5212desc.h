begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATH_AR5212_DESC_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATH_AR5212_DESC_H_
end_define

begin_comment
comment|/*  * Hardware-specific descriptor structures.  */
end_comment

begin_comment
comment|/*  * AR5212-specific tx/rx descriptor definition.  */
end_comment

begin_struct
struct|struct
name|ar5212_desc
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
struct|struct
block|{
comment|/* xmit format */
name|uint32_t
name|ctl2
decl_stmt|;
comment|/* DMA control 2 */
name|uint32_t
name|ctl3
decl_stmt|;
comment|/* DMA control 3 */
name|uint32_t
name|status0
decl_stmt|;
comment|/* DMA status 0 */
name|uint32_t
name|status1
decl_stmt|;
comment|/* DMA status 1 */
block|}
name|tx
struct|;
struct|struct
block|{
comment|/* recv format */
name|uint32_t
name|status0
decl_stmt|;
comment|/* DMA status 0 */
name|uint32_t
name|status1
decl_stmt|;
comment|/* DMA status 1 */
block|}
name|rx
struct|;
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
name|AR5212DESC
parameter_list|(
name|_ds
parameter_list|)
value|((struct ar5212_desc *)(_ds))
end_define

begin_define
define|#
directive|define
name|AR5212DESC_CONST
parameter_list|(
name|_ds
parameter_list|)
value|((const struct ar5212_desc *)(_ds))
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
name|ds_txstatus0
value|u.tx.status0
end_define

begin_define
define|#
directive|define
name|ds_txstatus1
value|u.tx.status1
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
comment|/* bits 12-15 are reserved */
end_comment

begin_define
define|#
directive|define
name|AR_XmitPower
value|0x003f0000
end_define

begin_comment
comment|/* transmit power control */
end_comment

begin_define
define|#
directive|define
name|AR_XmitPower_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_RTSCTSEnable
value|0x00400000
end_define

begin_comment
comment|/* RTS/CTS protocol enable */
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
name|AR_DestIdxValid
value|0x40000000
end_define

begin_comment
comment|/* destination index valid */
end_comment

begin_define
define|#
directive|define
name|AR_CTSEnable
value|0x80000000
end_define

begin_comment
comment|/* precede frame with CTS */
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
name|AR_DestIdx
value|0x000fe000
end_define

begin_comment
comment|/* destination table index */
end_comment

begin_define
define|#
directive|define
name|AR_DestIdx_S
value|13
end_define

begin_define
define|#
directive|define
name|AR_FrmType
value|0x00f00000
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
name|AR_NoAck
value|0x01000000
end_define

begin_comment
comment|/* No ACK flag */
end_comment

begin_define
define|#
directive|define
name|AR_CompProc
value|0x06000000
end_define

begin_comment
comment|/* compression processing */
end_comment

begin_define
define|#
directive|define
name|AR_CompProc_S
value|25
end_define

begin_define
define|#
directive|define
name|AR_CompIVLen
value|0x18000000
end_define

begin_comment
comment|/* length of frame IV */
end_comment

begin_define
define|#
directive|define
name|AR_CompIVLen_S
value|27
end_define

begin_define
define|#
directive|define
name|AR_CompICVLen
value|0x60000000
end_define

begin_comment
comment|/* length of frame ICV */
end_comment

begin_define
define|#
directive|define
name|AR_CompICVLen_S
value|29
end_define

begin_comment
comment|/* bit 31 is reserved */
end_comment

begin_comment
comment|/* TX ds_ctl2 */
end_comment

begin_define
define|#
directive|define
name|AR_RTSCTSDuration
value|0x00007fff
end_define

begin_comment
comment|/* RTS/CTS duration */
end_comment

begin_define
define|#
directive|define
name|AR_RTSCTSDuration_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_DurUpdateEna
value|0x00008000
end_define

begin_comment
comment|/* frame duration update ctl */
end_comment

begin_define
define|#
directive|define
name|AR_XmitDataTries0
value|0x000f0000
end_define

begin_comment
comment|/* series 0 max attempts */
end_comment

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

begin_comment
comment|/* series 1 max attempts */
end_comment

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

begin_comment
comment|/* series 2 max attempts */
end_comment

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

begin_comment
comment|/* series 3 max attempts */
end_comment

begin_define
define|#
directive|define
name|AR_XmitDataTries3_S
value|28
end_define

begin_comment
comment|/* TX ds_ctl3 */
end_comment

begin_define
define|#
directive|define
name|AR_XmitRate0
value|0x0000001f
end_define

begin_comment
comment|/* series 0 tx rate */
end_comment

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
value|0x000003e0
end_define

begin_comment
comment|/* series 1 tx rate */
end_comment

begin_define
define|#
directive|define
name|AR_XmitRate1_S
value|5
end_define

begin_define
define|#
directive|define
name|AR_XmitRate2
value|0x00007c00
end_define

begin_comment
comment|/* series 2 tx rate */
end_comment

begin_define
define|#
directive|define
name|AR_XmitRate2_S
value|10
end_define

begin_define
define|#
directive|define
name|AR_XmitRate3
value|0x000f8000
end_define

begin_comment
comment|/* series 3 tx rate */
end_comment

begin_define
define|#
directive|define
name|AR_XmitRate3_S
value|15
end_define

begin_define
define|#
directive|define
name|AR_RTSCTSRate
value|0x01f00000
end_define

begin_comment
comment|/* RTS or CTS rate */
end_comment

begin_define
define|#
directive|define
name|AR_RTSCTSRate_S
value|20
end_define

begin_comment
comment|/* bits 25-31 are reserved */
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
comment|/* TX ds_txstatus0 */
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

begin_define
define|#
directive|define
name|AR_RTSFailCnt
value|0x000000f0
end_define

begin_comment
comment|/* RTS failure count */
end_comment

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

begin_comment
comment|/* Data failure count */
end_comment

begin_define
define|#
directive|define
name|AR_DataFailCnt_S
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
comment|/* RX ds_rxstatus0 */
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

begin_define
define|#
directive|define
name|AR_DecompCRCErr
value|0x00002000
end_define

begin_comment
comment|/* decompression CRC error */
end_comment

begin_comment
comment|/* bit 14 is reserved */
end_comment

begin_define
define|#
directive|define
name|AR_RcvRate
value|0x000f8000
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
value|0x0ff00000
end_define

begin_comment
comment|/* receive signal strength */
end_comment

begin_define
define|#
directive|define
name|AR_RcvSigStrength_S
value|20
end_define

begin_define
define|#
directive|define
name|AR_RcvAntenna
value|0xf0000000
end_define

begin_comment
comment|/* receive antenaa */
end_comment

begin_define
define|#
directive|define
name|AR_RcvAntenna_S
value|28
end_define

begin_comment
comment|/* TX ds_txstatus1 */
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

begin_define
define|#
directive|define
name|AR_FinalTSIndex
value|0x00600000
end_define

begin_comment
comment|/* final TX attempt series ix */
end_comment

begin_define
define|#
directive|define
name|AR_FinalTSIndex_S
value|21
end_define

begin_define
define|#
directive|define
name|AR_CompSuccess
value|0x00800000
end_define

begin_comment
comment|/* compression status */
end_comment

begin_define
define|#
directive|define
name|AR_XmitAtenna
value|0x01000000
end_define

begin_comment
comment|/* transmit antenna */
end_comment

begin_comment
comment|/* bits 25-31 are reserved */
end_comment

begin_comment
comment|/* RX ds_rxstatus1 */
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

begin_define
define|#
directive|define
name|AR_DecryptCRCErr
value|0x00000008
end_define

begin_comment
comment|/* Decryption CRC fiailure */
end_comment

begin_define
define|#
directive|define
name|AR_PHYErr
value|0x00000010
end_define

begin_comment
comment|/* PHY error */
end_comment

begin_define
define|#
directive|define
name|AR_MichaelErr
value|0x00000020
end_define

begin_comment
comment|/* Michae MIC decrypt error */
end_comment

begin_comment
comment|/* bits 6-7 are reserved */
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
value|0x0000fe00
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
value|0x7fff0000
end_define

begin_comment
comment|/* timestamp */
end_comment

begin_define
define|#
directive|define
name|AR_RcvTimestamp_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_KeyCacheMiss
value|0x80000000
end_define

begin_comment
comment|/* key cache miss indication */
end_comment

begin_comment
comment|/* NB: phy error code overlays key index and valid fields */
end_comment

begin_define
define|#
directive|define
name|AR_PHYErrCode
value|0x0000ff00
end_define

begin_comment
comment|/* PHY error code */
end_comment

begin_define
define|#
directive|define
name|AR_PHYErrCode_S
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ATH_AR5212_DESC_H_ */
end_comment

end_unit

