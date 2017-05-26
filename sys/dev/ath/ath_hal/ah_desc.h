begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ATH_DESC_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ATH_DESC_H
end_define

begin_comment
comment|/*  * Transmit descriptor status.  This structure is filled  * in only after the tx descriptor process method finds a  * ``done'' descriptor; at which point it returns something  * other than HAL_EINPROGRESS.  *  * Note that ts_antenna may not be valid for all h/w.  It  * should be used only if non-zero.  */
end_comment

begin_struct
struct|struct
name|ath_tx_status
block|{
name|uint16_t
name|ts_seqnum
decl_stmt|;
comment|/* h/w assigned sequence number */
name|uint16_t
name|ts_pad1
index|[
literal|1
index|]
decl_stmt|;
name|uint32_t
name|ts_tstamp
decl_stmt|;
comment|/* h/w assigned timestamp */
name|uint8_t
name|ts_status
decl_stmt|;
comment|/* frame status, 0 => xmit ok */
name|uint8_t
name|ts_rate
decl_stmt|;
comment|/* h/w transmit rate index */
name|int8_t
name|ts_rssi
decl_stmt|;
comment|/* tx ack RSSI */
name|uint8_t
name|ts_shortretry
decl_stmt|;
comment|/* # short retries */
name|uint8_t
name|ts_longretry
decl_stmt|;
comment|/* # long retries */
name|uint8_t
name|ts_virtcol
decl_stmt|;
comment|/* virtual collision count */
name|uint8_t
name|ts_antenna
decl_stmt|;
comment|/* antenna information */
name|uint8_t
name|ts_finaltsi
decl_stmt|;
comment|/* final transmit series index */
comment|/* 802.11n status */
name|uint8_t
name|ts_flags
decl_stmt|;
comment|/* misc flags */
name|uint8_t
name|ts_queue_id
decl_stmt|;
comment|/* AR9300: TX queue id */
name|uint8_t
name|ts_desc_id
decl_stmt|;
comment|/* AR9300: TX descriptor id */
name|uint8_t
name|ts_tid
decl_stmt|;
comment|/* TID */
comment|/* #define ts_rssi ts_rssi_combined */
name|uint32_t
name|ts_ba_low
decl_stmt|;
comment|/* blockack bitmap low */
name|uint32_t
name|ts_ba_high
decl_stmt|;
comment|/* blockack bitmap high */
name|uint32_t
name|ts_evm0
decl_stmt|;
comment|/* evm bytes */
name|uint32_t
name|ts_evm1
decl_stmt|;
name|uint32_t
name|ts_evm2
decl_stmt|;
name|int8_t
name|ts_rssi_ctl
index|[
literal|3
index|]
decl_stmt|;
comment|/* tx ack RSSI [ctl, chain 0-2] */
name|int8_t
name|ts_rssi_ext
index|[
literal|3
index|]
decl_stmt|;
comment|/* tx ack RSSI [ext, chain 0-2] */
name|uint8_t
name|ts_pad
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* bits found in ts_status */
end_comment

begin_define
define|#
directive|define
name|HAL_TXERR_XRETRY
value|0x01
end_define

begin_comment
comment|/* excessive retries */
end_comment

begin_define
define|#
directive|define
name|HAL_TXERR_FILT
value|0x02
end_define

begin_comment
comment|/* blocked by tx filtering */
end_comment

begin_define
define|#
directive|define
name|HAL_TXERR_FIFO
value|0x04
end_define

begin_comment
comment|/* fifo underrun */
end_comment

begin_define
define|#
directive|define
name|HAL_TXERR_XTXOP
value|0x08
end_define

begin_comment
comment|/* txop exceeded */
end_comment

begin_define
define|#
directive|define
name|HAL_TXERR_TIMER_EXPIRED
value|0x10
end_define

begin_comment
comment|/* Tx timer expired */
end_comment

begin_comment
comment|/* bits found in ts_flags */
end_comment

begin_define
define|#
directive|define
name|HAL_TX_BA
value|0x01
end_define

begin_comment
comment|/* Block Ack seen */
end_comment

begin_define
define|#
directive|define
name|HAL_TX_AGGR
value|0x02
end_define

begin_comment
comment|/* Aggregate */
end_comment

begin_define
define|#
directive|define
name|HAL_TX_DESC_CFG_ERR
value|0x10
end_define

begin_comment
comment|/* Error in 20/40 desc config */
end_comment

begin_define
define|#
directive|define
name|HAL_TX_DATA_UNDERRUN
value|0x20
end_define

begin_comment
comment|/* Tx buffer underrun */
end_comment

begin_define
define|#
directive|define
name|HAL_TX_DELIM_UNDERRUN
value|0x40
end_define

begin_comment
comment|/* Tx delimiter underrun */
end_comment

begin_define
define|#
directive|define
name|HAL_TX_FAST_TS
value|0x80
end_define

begin_comment
comment|/* Tx locationing timestamp */
end_comment

begin_comment
comment|/*  * Receive descriptor status.  This structure is filled  * in only after the rx descriptor process method finds a  * ``done'' descriptor; at which point it returns something  * other than HAL_EINPROGRESS.  *  * If rx_status is zero, then the frame was received ok;  * otherwise the error information is indicated and rs_phyerr  * contains a phy error code if HAL_RXERR_PHY is set.  In general  * the frame contents is undefined when an error occurred thought  * for some errors (e.g. a decryption error), it may be meaningful.  *  * Note that the receive timestamp is expanded using the TSF to  * at least 15 bits (regardless of what the h/w provides directly).  * Newer hardware supports a full 32-bits; use HAL_CAP_32TSTAMP to  * find out if the hardware is capable.  *  * rx_rssi is in units of dbm above the noise floor.  This value  * is measured during the preamble and PLCP; i.e. with the initial  * 4us of detection.  The noise floor is typically a consistent  * -96dBm absolute power in a 20MHz channel.  */
end_comment

begin_struct
struct|struct
name|ath_rx_status
block|{
name|uint16_t
name|rs_datalen
decl_stmt|;
comment|/* rx frame length */
name|uint8_t
name|rs_status
decl_stmt|;
comment|/* rx status, 0 => recv ok */
name|uint8_t
name|rs_phyerr
decl_stmt|;
comment|/* phy error code */
name|int8_t
name|rs_rssi
decl_stmt|;
comment|/* rx frame RSSI (combined for 11n) */
name|uint8_t
name|rs_keyix
decl_stmt|;
comment|/* key cache index */
name|uint8_t
name|rs_rate
decl_stmt|;
comment|/* h/w receive rate index */
name|uint8_t
name|rs_more
decl_stmt|;
comment|/* more descriptors follow */
name|uint32_t
name|rs_tstamp
decl_stmt|;
comment|/* h/w assigned timestamp */
name|uint32_t
name|rs_antenna
decl_stmt|;
comment|/* antenna information */
comment|/* 802.11n status */
name|int8_t
name|rs_rssi_ctl
index|[
literal|3
index|]
decl_stmt|;
comment|/* rx frame RSSI [ctl, chain 0-2] */
name|int8_t
name|rs_rssi_ext
index|[
literal|3
index|]
decl_stmt|;
comment|/* rx frame RSSI [ext, chain 0-2] */
name|uint8_t
name|rs_isaggr
decl_stmt|;
comment|/* is part of the aggregate */
name|uint8_t
name|rs_moreaggr
decl_stmt|;
comment|/* more frames in aggr to follow */
name|uint16_t
name|rs_flags
decl_stmt|;
comment|/* misc flags */
name|uint8_t
name|rs_num_delims
decl_stmt|;
comment|/* number of delims in aggr */
name|uint8_t
name|rs_spare0
decl_stmt|;
comment|/* padding */
name|uint8_t
name|rs_ness
decl_stmt|;
comment|/* number of extension spatial streams */
name|uint8_t
name|rs_hw_upload_data_type
decl_stmt|;
comment|/* hw upload format */
name|uint16_t
name|rs_spare1
decl_stmt|;
name|uint32_t
name|rs_evm0
decl_stmt|;
comment|/* evm bytes */
name|uint32_t
name|rs_evm1
decl_stmt|;
name|uint32_t
name|rs_evm2
decl_stmt|;
name|uint32_t
name|rs_evm3
decl_stmt|;
comment|/* needed for ar9300 and later */
name|uint32_t
name|rs_evm4
decl_stmt|;
comment|/* needed for ar9300 and later */
block|}
struct|;
end_struct

begin_comment
comment|/* bits found in rs_status */
end_comment

begin_define
define|#
directive|define
name|HAL_RXERR_CRC
value|0x01
end_define

begin_comment
comment|/* CRC error on frame */
end_comment

begin_define
define|#
directive|define
name|HAL_RXERR_PHY
value|0x02
end_define

begin_comment
comment|/* PHY error, rs_phyerr is valid */
end_comment

begin_define
define|#
directive|define
name|HAL_RXERR_FIFO
value|0x04
end_define

begin_comment
comment|/* fifo overrun */
end_comment

begin_define
define|#
directive|define
name|HAL_RXERR_DECRYPT
value|0x08
end_define

begin_comment
comment|/* non-Michael decrypt error */
end_comment

begin_define
define|#
directive|define
name|HAL_RXERR_MIC
value|0x10
end_define

begin_comment
comment|/* Michael MIC decrypt error */
end_comment

begin_define
define|#
directive|define
name|HAL_RXERR_INCOMP
value|0x20
end_define

begin_comment
comment|/* Rx Desc processing is incomplete */
end_comment

begin_define
define|#
directive|define
name|HAL_RXERR_KEYMISS
value|0x40
end_define

begin_comment
comment|/* Key not found in keycache */
end_comment

begin_comment
comment|/* bits found in rs_flags */
end_comment

begin_define
define|#
directive|define
name|HAL_RX_MORE
value|0x0001
end_define

begin_comment
comment|/* more descriptors follow */
end_comment

begin_define
define|#
directive|define
name|HAL_RX_MORE_AGGR
value|0x0002
end_define

begin_comment
comment|/* more frames in aggr */
end_comment

begin_define
define|#
directive|define
name|HAL_RX_GI
value|0x0004
end_define

begin_comment
comment|/* full gi */
end_comment

begin_define
define|#
directive|define
name|HAL_RX_2040
value|0x0008
end_define

begin_comment
comment|/* 40 Mhz */
end_comment

begin_define
define|#
directive|define
name|HAL_RX_DELIM_CRC_PRE
value|0x0010
end_define

begin_comment
comment|/* crc error in delimiter pre */
end_comment

begin_define
define|#
directive|define
name|HAL_RX_DELIM_CRC_POST
value|0x0020
end_define

begin_comment
comment|/* crc error in delim after */
end_comment

begin_define
define|#
directive|define
name|HAL_RX_DECRYPT_BUSY
value|0x0040
end_define

begin_comment
comment|/* decrypt was too slow */
end_comment

begin_define
define|#
directive|define
name|HAL_RX_HI_RX_CHAIN
value|0x0080
end_define

begin_comment
comment|/* SM power save: hi Rx chain control */
end_comment

begin_define
define|#
directive|define
name|HAL_RX_IS_APSD
value|0x0100
end_define

begin_comment
comment|/* Is ASPD trigger frame */
end_comment

begin_define
define|#
directive|define
name|HAL_RX_STBC
value|0x0200
end_define

begin_comment
comment|/* Is an STBC frame */
end_comment

begin_define
define|#
directive|define
name|HAL_RX_LOC_INFO
value|0x0400
end_define

begin_comment
comment|/* RX locationing information */
end_comment

begin_define
define|#
directive|define
name|HAL_RX_HW_UPLOAD_DATA
value|0x1000
end_define

begin_comment
comment|/* This is a hardware data frame */
end_comment

begin_define
define|#
directive|define
name|HAL_RX_HW_SOUNDING
value|0x2000
end_define

begin_comment
comment|/* Rx sounding frame (TxBF, positioning) */
end_comment

begin_define
define|#
directive|define
name|HAL_RX_UPLOAD_VALID
value|0x4000
end_define

begin_comment
comment|/* This hardware data frame is valid */
end_comment

begin_comment
comment|/*  * This is the format of RSSI[2] on the AR9285/AR9485.  * It encodes the LNA configuration information.  *  * For boards with an external diversity antenna switch,  * HAL_RX_LNA_EXTCFG encodes which configuration was  * used (antenna 1 or antenna 2.)  This feeds into the  * switch table and ensures that the given antenna was  * connected to an LNA.  */
end_comment

begin_define
define|#
directive|define
name|HAL_RX_LNA_LNACFG
value|0x80
end_define

begin_comment
comment|/* 1 = main LNA config used, 0 = ALT */
end_comment

begin_define
define|#
directive|define
name|HAL_RX_LNA_EXTCFG
value|0x40
end_define

begin_comment
comment|/* 0 = external diversity ant1, 1 = ant2 */
end_comment

begin_define
define|#
directive|define
name|HAL_RX_LNA_CFG_USED
value|0x30
end_define

begin_comment
comment|/* 2 bits; LNA config used on RX */
end_comment

begin_define
define|#
directive|define
name|HAL_RX_LNA_CFG_USED_S
value|4
end_define

begin_define
define|#
directive|define
name|HAL_RX_LNA_CFG_MAIN
value|0x0c
end_define

begin_comment
comment|/* 2 bits; "Main" LNA config */
end_comment

begin_define
define|#
directive|define
name|HAL_RX_LNA_CFG_ALT
value|0x02
end_define

begin_comment
comment|/* 2 bits; "Alt" LNA config */
end_comment

begin_comment
comment|/*  * This is the format of RSSI_EXT[2] on the AR9285/AR9485.  * It encodes the switch table configuration and fast diversity  * value.  */
end_comment

begin_define
define|#
directive|define
name|HAL_RX_LNA_FASTDIV
value|0x40
end_define

begin_comment
comment|/* 1 = fast diversity measurement done */
end_comment

begin_define
define|#
directive|define
name|HAL_RX_LNA_SWITCH_0
value|0x30
end_define

begin_comment
comment|/* 2 bits; sw_0[1:0] */
end_comment

begin_define
define|#
directive|define
name|HAL_RX_LNA_SWITCH_COM
value|0x0f
end_define

begin_comment
comment|/* 4 bits, sw_com[3:0] */
end_comment

begin_enum
enum|enum
block|{
name|HAL_PHYERR_UNDERRUN
init|=
literal|0
block|,
comment|/* Transmit underrun */
name|HAL_PHYERR_TIMING
init|=
literal|1
block|,
comment|/* Timing error */
name|HAL_PHYERR_PARITY
init|=
literal|2
block|,
comment|/* Illegal parity */
name|HAL_PHYERR_RATE
init|=
literal|3
block|,
comment|/* Illegal rate */
name|HAL_PHYERR_LENGTH
init|=
literal|4
block|,
comment|/* Illegal length */
name|HAL_PHYERR_RADAR
init|=
literal|5
block|,
comment|/* Radar detect */
name|HAL_PHYERR_SERVICE
init|=
literal|6
block|,
comment|/* Illegal service */
name|HAL_PHYERR_TOR
init|=
literal|7
block|,
comment|/* Transmit override receive */
comment|/* NB: these are specific to the 5212 and later */
name|HAL_PHYERR_OFDM_TIMING
init|=
literal|17
block|,
comment|/* */
name|HAL_PHYERR_OFDM_SIGNAL_PARITY
init|=
literal|18
block|,
comment|/* */
name|HAL_PHYERR_OFDM_RATE_ILLEGAL
init|=
literal|19
block|,
comment|/* */
name|HAL_PHYERR_OFDM_LENGTH_ILLEGAL
init|=
literal|20
block|,
comment|/* */
name|HAL_PHYERR_OFDM_POWER_DROP
init|=
literal|21
block|,
comment|/* */
name|HAL_PHYERR_OFDM_SERVICE
init|=
literal|22
block|,
comment|/* */
name|HAL_PHYERR_OFDM_RESTART
init|=
literal|23
block|,
comment|/* */
name|HAL_PHYERR_FALSE_RADAR_EXT
init|=
literal|24
block|,
comment|/* */
name|HAL_PHYERR_CCK_TIMING
init|=
literal|25
block|,
comment|/* */
name|HAL_PHYERR_CCK_HEADER_CRC
init|=
literal|26
block|,
comment|/* */
name|HAL_PHYERR_CCK_RATE_ILLEGAL
init|=
literal|27
block|,
comment|/* */
name|HAL_PHYERR_CCK_SERVICE
init|=
literal|30
block|,
comment|/* */
name|HAL_PHYERR_CCK_RESTART
init|=
literal|31
block|,
comment|/* */
name|HAL_PHYERR_CCK_LENGTH_ILLEGAL
init|=
literal|32
block|,
comment|/* */
name|HAL_PHYERR_CCK_POWER_DROP
init|=
literal|33
block|,
comment|/* */
comment|/* AR5416 and later */
name|HAL_PHYERR_HT_CRC_ERROR
init|=
literal|34
block|,
comment|/* */
name|HAL_PHYERR_HT_LENGTH_ILLEGAL
init|=
literal|35
block|,
comment|/* */
name|HAL_PHYERR_HT_RATE_ILLEGAL
init|=
literal|36
block|,
comment|/* */
name|HAL_PHYERR_SPECTRAL
init|=
literal|38
block|, }
enum|;
end_enum

begin_comment
comment|/* value found in rs_keyix to mark invalid entries */
end_comment

begin_define
define|#
directive|define
name|HAL_RXKEYIX_INVALID
value|((uint8_t) -1)
end_define

begin_comment
comment|/* value used to specify no encryption key for xmit */
end_comment

begin_define
define|#
directive|define
name|HAL_TXKEYIX_INVALID
value|((u_int) -1)
end_define

begin_comment
comment|/* XXX rs_antenna definitions */
end_comment

begin_comment
comment|/*  * Definitions for the software frame/packet descriptors used by  * the Atheros HAL.  This definition obscures hardware-specific  * details from the driver.  Drivers are expected to fillin the  * portions of a descriptor that are not opaque then use HAL calls  * to complete the work.  Status for completed frames is returned  * in a device-independent format.  */
end_comment

begin_define
define|#
directive|define
name|HAL_DESC_HW_SIZE
value|20
end_define

begin_struct
struct|struct
name|ath_desc
block|{
comment|/* 	 * The following definitions are passed directly 	 * the hardware and managed by the HAL.  Drivers 	 * should not touch those elements marked opaque. 	 */
name|uint32_t
name|ds_link
decl_stmt|;
comment|/* phys address of next descriptor */
name|uint32_t
name|ds_data
decl_stmt|;
comment|/* phys address of data buffer */
name|uint32_t
name|ds_ctl0
decl_stmt|;
comment|/* opaque DMA control 0 */
name|uint32_t
name|ds_ctl1
decl_stmt|;
comment|/* opaque DMA control 1 */
name|uint32_t
name|ds_hw
index|[
name|HAL_DESC_HW_SIZE
index|]
decl_stmt|;
comment|/* opaque h/w region */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ath_desc_txedma
block|{
name|uint32_t
name|ds_info
decl_stmt|;
name|uint32_t
name|ds_link
decl_stmt|;
name|uint32_t
name|ds_hw
index|[
literal|21
index|]
decl_stmt|;
comment|/* includes buf/len */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ath_desc_status
block|{
union|union
block|{
name|struct
name|ath_tx_status
name|tx
decl_stmt|;
comment|/* xmit status */
name|struct
name|ath_rx_status
name|rx
decl_stmt|;
comment|/* recv status */
block|}
name|ds_us
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ds_txstat
value|ds_us.tx
end_define

begin_define
define|#
directive|define
name|ds_rxstat
value|ds_us.rx
end_define

begin_comment
comment|/* flags passed to tx descriptor setup methods */
end_comment

begin_comment
comment|/* This is a uint16_t field in ath_buf, just be warned! */
end_comment

begin_define
define|#
directive|define
name|HAL_TXDESC_CLRDMASK
value|0x0001
end_define

begin_comment
comment|/* clear destination filter mask */
end_comment

begin_define
define|#
directive|define
name|HAL_TXDESC_NOACK
value|0x0002
end_define

begin_comment
comment|/* don't wait for ACK */
end_comment

begin_define
define|#
directive|define
name|HAL_TXDESC_RTSENA
value|0x0004
end_define

begin_comment
comment|/* enable RTS */
end_comment

begin_define
define|#
directive|define
name|HAL_TXDESC_CTSENA
value|0x0008
end_define

begin_comment
comment|/* enable CTS */
end_comment

begin_define
define|#
directive|define
name|HAL_TXDESC_INTREQ
value|0x0010
end_define

begin_comment
comment|/* enable per-descriptor interrupt */
end_comment

begin_define
define|#
directive|define
name|HAL_TXDESC_VEOL
value|0x0020
end_define

begin_comment
comment|/* mark virtual EOL */
end_comment

begin_comment
comment|/* NB: this only affects frame, not any RTS/CTS */
end_comment

begin_define
define|#
directive|define
name|HAL_TXDESC_DURENA
value|0x0040
end_define

begin_comment
comment|/* enable h/w write of duration field */
end_comment

begin_define
define|#
directive|define
name|HAL_TXDESC_EXT_ONLY
value|0x0080
end_define

begin_comment
comment|/* send on ext channel only (11n) */
end_comment

begin_define
define|#
directive|define
name|HAL_TXDESC_EXT_AND_CTL
value|0x0100
end_define

begin_comment
comment|/* send on ext + ctl channels (11n) */
end_comment

begin_define
define|#
directive|define
name|HAL_TXDESC_VMF
value|0x0200
end_define

begin_comment
comment|/* virtual more frag */
end_comment

begin_define
define|#
directive|define
name|HAL_TXDESC_LOWRXCHAIN
value|0x0400
end_define

begin_comment
comment|/* switch to low RX chain */
end_comment

begin_define
define|#
directive|define
name|HAL_TXDESC_LDPC
value|0x1000
end_define

begin_comment
comment|/* Set LDPC TX for all rates */
end_comment

begin_define
define|#
directive|define
name|HAL_TXDESC_HWTS
value|0x2000
end_define

begin_comment
comment|/* Request Azimuth Timestamp in TX payload */
end_comment

begin_define
define|#
directive|define
name|HAL_TXDESC_POS
value|0x4000
end_define

begin_comment
comment|/* Request ToD/ToA locationing */
end_comment

begin_comment
comment|/* flags passed to rx descriptor setup methods */
end_comment

begin_define
define|#
directive|define
name|HAL_RXDESC_INTREQ
value|0x0020
end_define

begin_comment
comment|/* enable per-descriptor interrupt */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_ATH_DESC_H */
end_comment

end_unit

