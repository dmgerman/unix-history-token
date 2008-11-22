begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2004, 2005  *      Damien Bergamini<damien.bergamini@free.fr>. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_define
define|#
directive|define
name|IWI_CMD_RING_COUNT
value|16
end_define

begin_define
define|#
directive|define
name|IWI_TX_RING_COUNT
value|64
end_define

begin_define
define|#
directive|define
name|IWI_RX_RING_COUNT
value|32
end_define

begin_define
define|#
directive|define
name|IWI_TX_DESC_SIZE
value|(sizeof (struct iwi_tx_desc))
end_define

begin_define
define|#
directive|define
name|IWI_CMD_DESC_SIZE
value|(sizeof (struct iwi_cmd_desc))
end_define

begin_define
define|#
directive|define
name|IWI_CSR_INTR
value|0x0008
end_define

begin_define
define|#
directive|define
name|IWI_CSR_INTR_MASK
value|0x000c
end_define

begin_define
define|#
directive|define
name|IWI_CSR_INDIRECT_ADDR
value|0x0010
end_define

begin_define
define|#
directive|define
name|IWI_CSR_INDIRECT_DATA
value|0x0014
end_define

begin_define
define|#
directive|define
name|IWI_CSR_AUTOINC_ADDR
value|0x0018
end_define

begin_define
define|#
directive|define
name|IWI_CSR_AUTOINC_DATA
value|0x001c
end_define

begin_define
define|#
directive|define
name|IWI_CSR_RST
value|0x0020
end_define

begin_define
define|#
directive|define
name|IWI_CSR_CTL
value|0x0024
end_define

begin_define
define|#
directive|define
name|IWI_CSR_IO
value|0x0030
end_define

begin_define
define|#
directive|define
name|IWI_CSR_CMD_BASE
value|0x0200
end_define

begin_define
define|#
directive|define
name|IWI_CSR_CMD_SIZE
value|0x0204
end_define

begin_define
define|#
directive|define
name|IWI_CSR_TX1_BASE
value|0x0208
end_define

begin_define
define|#
directive|define
name|IWI_CSR_TX1_SIZE
value|0x020c
end_define

begin_define
define|#
directive|define
name|IWI_CSR_TX2_BASE
value|0x0210
end_define

begin_define
define|#
directive|define
name|IWI_CSR_TX2_SIZE
value|0x0214
end_define

begin_define
define|#
directive|define
name|IWI_CSR_TX3_BASE
value|0x0218
end_define

begin_define
define|#
directive|define
name|IWI_CSR_TX3_SIZE
value|0x021c
end_define

begin_define
define|#
directive|define
name|IWI_CSR_TX4_BASE
value|0x0220
end_define

begin_define
define|#
directive|define
name|IWI_CSR_TX4_SIZE
value|0x0224
end_define

begin_define
define|#
directive|define
name|IWI_CSR_CMD_RIDX
value|0x0280
end_define

begin_define
define|#
directive|define
name|IWI_CSR_TX1_RIDX
value|0x0284
end_define

begin_define
define|#
directive|define
name|IWI_CSR_TX2_RIDX
value|0x0288
end_define

begin_define
define|#
directive|define
name|IWI_CSR_TX3_RIDX
value|0x028c
end_define

begin_define
define|#
directive|define
name|IWI_CSR_TX4_RIDX
value|0x0290
end_define

begin_define
define|#
directive|define
name|IWI_CSR_RX_RIDX
value|0x02a0
end_define

begin_define
define|#
directive|define
name|IWI_CSR_RX_BASE
value|0x0500
end_define

begin_define
define|#
directive|define
name|IWI_CSR_TABLE0_SIZE
value|0x0700
end_define

begin_define
define|#
directive|define
name|IWI_CSR_TABLE0_BASE
value|0x0704
end_define

begin_define
define|#
directive|define
name|IWI_CSR_NODE_BASE
value|0x0c0c
end_define

begin_define
define|#
directive|define
name|IWI_CSR_CMD_WIDX
value|0x0f80
end_define

begin_define
define|#
directive|define
name|IWI_CSR_TX1_WIDX
value|0x0f84
end_define

begin_define
define|#
directive|define
name|IWI_CSR_TX2_WIDX
value|0x0f88
end_define

begin_define
define|#
directive|define
name|IWI_CSR_TX3_WIDX
value|0x0f8c
end_define

begin_define
define|#
directive|define
name|IWI_CSR_TX4_WIDX
value|0x0f90
end_define

begin_define
define|#
directive|define
name|IWI_CSR_RX_WIDX
value|0x0fa0
end_define

begin_define
define|#
directive|define
name|IWI_CSR_READ_INT
value|0x0ff4
end_define

begin_comment
comment|/* aliases */
end_comment

begin_define
define|#
directive|define
name|IWI_CSR_CURRENT_TX_RATE
value|IWI_CSR_TABLE0_BASE
end_define

begin_comment
comment|/* flags for IWI_CSR_INTR */
end_comment

begin_define
define|#
directive|define
name|IWI_INTR_RX_DONE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IWI_INTR_CMD_DONE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|IWI_INTR_TX1_DONE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|IWI_INTR_TX2_DONE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|IWI_INTR_TX3_DONE
value|0x00004000
end_define

begin_define
define|#
directive|define
name|IWI_INTR_TX4_DONE
value|0x00008000
end_define

begin_define
define|#
directive|define
name|IWI_INTR_FW_INITED
value|0x01000000
end_define

begin_define
define|#
directive|define
name|IWI_INTR_RADIO_OFF
value|0x04000000
end_define

begin_define
define|#
directive|define
name|IWI_INTR_FATAL_ERROR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|IWI_INTR_PARITY_ERROR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IWI_INTR_MASK
define|\
value|(IWI_INTR_RX_DONE | IWI_INTR_CMD_DONE |	IWI_INTR_TX1_DONE | 	\ 	 IWI_INTR_TX2_DONE | IWI_INTR_TX3_DONE | IWI_INTR_TX4_DONE |	\ 	 IWI_INTR_FW_INITED | IWI_INTR_RADIO_OFF |			\ 	 IWI_INTR_FATAL_ERROR | IWI_INTR_PARITY_ERROR)
end_define

begin_comment
comment|/* flags for IWI_CSR_RST */
end_comment

begin_define
define|#
directive|define
name|IWI_RST_PRINCETON_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IWI_RST_STANDBY
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IWI_RST_LED_ACTIVITY
value|0x00000010
end_define

begin_comment
comment|/* tx/rx traffic led */
end_comment

begin_define
define|#
directive|define
name|IWI_RST_LED_ASSOCIATED
value|0x00000020
end_define

begin_comment
comment|/* station associated led */
end_comment

begin_define
define|#
directive|define
name|IWI_RST_LED_OFDM
value|0x00000040
end_define

begin_comment
comment|/* ofdm/cck led */
end_comment

begin_define
define|#
directive|define
name|IWI_RST_SOFT_RESET
value|0x00000080
end_define

begin_define
define|#
directive|define
name|IWI_RST_MASTER_DISABLED
value|0x00000100
end_define

begin_define
define|#
directive|define
name|IWI_RST_STOP_MASTER
value|0x00000200
end_define

begin_define
define|#
directive|define
name|IWI_RST_GATE_ODMA
value|0x02000000
end_define

begin_define
define|#
directive|define
name|IWI_RST_GATE_IDMA
value|0x04000000
end_define

begin_define
define|#
directive|define
name|IWI_RST_GATE_ADMA
value|0x20000000
end_define

begin_comment
comment|/* flags for IWI_CSR_CTL */
end_comment

begin_define
define|#
directive|define
name|IWI_CTL_CLOCK_READY
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IWI_CTL_ALLOW_STANDBY
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IWI_CTL_INIT
value|0x00000004
end_define

begin_comment
comment|/* flags for IWI_CSR_IO */
end_comment

begin_define
define|#
directive|define
name|IWI_IO_RADIO_ENABLED
value|0x00010000
end_define

begin_comment
comment|/* flags for IWI_CSR_READ_INT */
end_comment

begin_define
define|#
directive|define
name|IWI_READ_INT_INIT_HOST
value|0x20000000
end_define

begin_comment
comment|/* constants for command blocks */
end_comment

begin_define
define|#
directive|define
name|IWI_CB_DEFAULT_CTL
value|0x8cea0000
end_define

begin_define
define|#
directive|define
name|IWI_CB_MAXDATALEN
value|8191
end_define

begin_comment
comment|/* supported rates */
end_comment

begin_define
define|#
directive|define
name|IWI_RATE_DS1
value|10
end_define

begin_define
define|#
directive|define
name|IWI_RATE_DS2
value|20
end_define

begin_define
define|#
directive|define
name|IWI_RATE_DS5
value|55
end_define

begin_define
define|#
directive|define
name|IWI_RATE_DS11
value|110
end_define

begin_define
define|#
directive|define
name|IWI_RATE_OFDM6
value|13
end_define

begin_define
define|#
directive|define
name|IWI_RATE_OFDM9
value|15
end_define

begin_define
define|#
directive|define
name|IWI_RATE_OFDM12
value|5
end_define

begin_define
define|#
directive|define
name|IWI_RATE_OFDM18
value|7
end_define

begin_define
define|#
directive|define
name|IWI_RATE_OFDM24
value|9
end_define

begin_define
define|#
directive|define
name|IWI_RATE_OFDM36
value|11
end_define

begin_define
define|#
directive|define
name|IWI_RATE_OFDM48
value|1
end_define

begin_define
define|#
directive|define
name|IWI_RATE_OFDM54
value|3
end_define

begin_comment
comment|/*  * Old version firmware images start with this header,  * fields are in little endian (le32) format.  */
end_comment

begin_struct
struct|struct
name|iwi_firmware_ohdr
block|{
name|uint32_t
name|version
decl_stmt|;
name|uint32_t
name|mode
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IWI_FW_REQ_MAJOR
value|2
end_define

begin_define
define|#
directive|define
name|IWI_FW_REQ_MINOR
value|4
end_define

begin_define
define|#
directive|define
name|IWI_FW_GET_MAJOR
parameter_list|(
name|ver
parameter_list|)
value|((ver)& 0xff)
end_define

begin_define
define|#
directive|define
name|IWI_FW_GET_MINOR
parameter_list|(
name|ver
parameter_list|)
value|(((ver)& 0xff00)>> 8)
end_define

begin_define
define|#
directive|define
name|IWI_FW_MODE_UCODE
value|0
end_define

begin_define
define|#
directive|define
name|IWI_FW_MODE_BOOT
value|0
end_define

begin_define
define|#
directive|define
name|IWI_FW_MODE_BSS
value|0
end_define

begin_define
define|#
directive|define
name|IWI_FW_MODE_IBSS
value|1
end_define

begin_define
define|#
directive|define
name|IWI_FW_MODE_MONITOR
value|2
end_define

begin_comment
comment|/*  * New version firmware images contain boot, ucode and firmware  * all in one chunk. The header at the beginning gives the version  * and the size of each (sub)image, in le32 format.  */
end_comment

begin_struct
struct|struct
name|iwi_firmware_hdr
block|{
name|uint32_t
name|version
decl_stmt|;
comment|/* version stamp */
name|uint32_t
name|bsize
decl_stmt|;
comment|/* size of boot image */
name|uint32_t
name|usize
decl_stmt|;
comment|/* size of ucode image */
name|uint32_t
name|fsize
decl_stmt|;
comment|/* size of firmware image */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iwi_hdr
block|{
name|uint8_t
name|type
decl_stmt|;
define|#
directive|define
name|IWI_HDR_TYPE_DATA
value|0
define|#
directive|define
name|IWI_HDR_TYPE_COMMAND
value|1
define|#
directive|define
name|IWI_HDR_TYPE_NOTIF
value|3
define|#
directive|define
name|IWI_HDR_TYPE_FRAME
value|9
name|uint8_t
name|seq
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|IWI_HDR_FLAG_IRQ
value|0x04
name|uint8_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|iwi_notif
block|{
name|uint32_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|type
decl_stmt|;
define|#
directive|define
name|IWI_NOTIF_TYPE_SUCCESS
value|0
define|#
directive|define
name|IWI_NOTIF_TYPE_UNSPECIFIED
value|1
comment|/* unspecified failure */
define|#
directive|define
name|IWI_NOTIF_TYPE_ASSOCIATION
value|10
define|#
directive|define
name|IWI_NOTIF_TYPE_AUTHENTICATION
value|11
define|#
directive|define
name|IWI_NOTIF_TYPE_SCAN_CHANNEL
value|12
define|#
directive|define
name|IWI_NOTIF_TYPE_SCAN_COMPLETE
value|13
define|#
directive|define
name|IWI_NOTIF_TYPE_FRAG_LENGTH
value|14
define|#
directive|define
name|IWI_NOTIF_TYPE_LINK_QUALITY
value|15
comment|/* "link deterioration" */
define|#
directive|define
name|IWI_NOTIF_TYPE_BEACON
value|17
comment|/* beacon state, e.g. miss */
define|#
directive|define
name|IWI_NOTIF_TYPE_TGI_TX_KEY
value|18
comment|/* WPA transmit key */
define|#
directive|define
name|IWI_NOTIF_TYPE_CALIBRATION
value|20
define|#
directive|define
name|IWI_NOTIF_TYPE_NOISE
value|25
name|uint8_t
name|flags
decl_stmt|;
name|uint16_t
name|len
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for notification IWI_NOTIF_TYPE_AUTHENTICATION */
end_comment

begin_struct
struct|struct
name|iwi_notif_authentication
block|{
name|uint8_t
name|state
decl_stmt|;
define|#
directive|define
name|IWI_AUTH_FAIL
value|0
define|#
directive|define
name|IWI_AUTH_SENT_1
value|1
comment|/* tx first frame */
define|#
directive|define
name|IWI_AUTH_RECV_2
value|2
comment|/* rx second frame */
define|#
directive|define
name|IWI_AUTH_SEQ1_PASS
value|3
comment|/* 1st exchange passed */
define|#
directive|define
name|IWI_AUTH_SEQ1_FAIL
value|4
comment|/* 1st exchange failed */
define|#
directive|define
name|IWI_AUTH_SUCCESS
value|9
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for notification IWI_NOTIF_TYPE_ASSOCIATION */
end_comment

begin_struct
struct|struct
name|iwi_notif_association
block|{
name|uint8_t
name|state
decl_stmt|;
define|#
directive|define
name|IWI_ASSOC_FAIL
value|0
define|#
directive|define
name|IWI_ASSOC_SUCCESS
value|12
name|uint8_t
name|pad
index|[
literal|11
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for notification IWI_NOTIF_TYPE_SCAN_CHANNEL */
end_comment

begin_struct
struct|struct
name|iwi_notif_scan_channel
block|{
name|uint8_t
name|nchan
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|47
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for notification IWI_NOTIF_TYPE_SCAN_COMPLETE */
end_comment

begin_struct
struct|struct
name|iwi_notif_scan_complete
block|{
name|uint8_t
name|type
decl_stmt|;
name|uint8_t
name|nchan
decl_stmt|;
name|uint8_t
name|status
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for notification IWI_NOTIF_TYPE_BEACON */
end_comment

begin_struct
struct|struct
name|iwi_notif_beacon_state
block|{
name|uint32_t
name|state
decl_stmt|;
define|#
directive|define
name|IWI_BEACON_MISS
value|1
name|uint32_t
name|number
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* received frame header */
end_comment

begin_struct
struct|struct
name|iwi_frame
block|{
name|uint32_t
name|reserved1
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|chan
decl_stmt|;
name|uint8_t
name|status
decl_stmt|;
name|uint8_t
name|rate
decl_stmt|;
name|uint8_t
name|rssi
decl_stmt|;
name|uint8_t
name|agc
decl_stmt|;
name|uint8_t
name|rssi_dbm
decl_stmt|;
name|uint16_t
name|signal
decl_stmt|;
name|uint16_t
name|noise
decl_stmt|;
name|uint8_t
name|antenna
decl_stmt|;
name|uint8_t
name|control
decl_stmt|;
name|uint8_t
name|reserved2
index|[
literal|2
index|]
decl_stmt|;
name|uint16_t
name|len
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* header for transmission */
end_comment

begin_struct
struct|struct
name|iwi_tx_desc
block|{
name|struct
name|iwi_hdr
name|hdr
decl_stmt|;
name|uint32_t
name|reserved1
decl_stmt|;
name|uint8_t
name|station
decl_stmt|;
comment|/* adhoc sta #, 0 for bss */
name|uint8_t
name|reserved2
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|cmd
decl_stmt|;
define|#
directive|define
name|IWI_DATA_CMD_TX
value|0x0b
name|uint8_t
name|seq
decl_stmt|;
name|uint16_t
name|len
decl_stmt|;
name|uint8_t
name|priority
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|IWI_DATA_FLAG_SHPREAMBLE
value|0x04
define|#
directive|define
name|IWI_DATA_FLAG_NO_WEP
value|0x20
define|#
directive|define
name|IWI_DATA_FLAG_NEED_ACK
value|0x80
name|uint8_t
name|xflags
decl_stmt|;
define|#
directive|define
name|IWI_DATA_XFLAG_QOS
value|0x10
name|uint8_t
name|wep_txkey
decl_stmt|;
name|uint8_t
name|wepkey
index|[
name|IEEE80211_KEYBUF_SIZE
index|]
decl_stmt|;
name|uint8_t
name|rate
decl_stmt|;
name|uint8_t
name|antenna
decl_stmt|;
name|uint8_t
name|reserved3
index|[
literal|10
index|]
decl_stmt|;
name|struct
name|ieee80211_qosframe_addr4
name|wh
decl_stmt|;
name|uint32_t
name|iv
decl_stmt|;
name|uint32_t
name|eiv
decl_stmt|;
name|uint32_t
name|nseg
decl_stmt|;
define|#
directive|define
name|IWI_MAX_NSEG
value|6
name|uint32_t
name|seg_addr
index|[
name|IWI_MAX_NSEG
index|]
decl_stmt|;
name|uint16_t
name|seg_len
index|[
name|IWI_MAX_NSEG
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* command */
end_comment

begin_struct
struct|struct
name|iwi_cmd_desc
block|{
name|struct
name|iwi_hdr
name|hdr
decl_stmt|;
name|uint8_t
name|type
decl_stmt|;
define|#
directive|define
name|IWI_CMD_ENABLE
value|2
define|#
directive|define
name|IWI_CMD_SET_CONFIG
value|6
define|#
directive|define
name|IWI_CMD_SET_ESSID
value|8
define|#
directive|define
name|IWI_CMD_SET_MAC_ADDRESS
value|11
define|#
directive|define
name|IWI_CMD_SET_RTS_THRESHOLD
value|15
define|#
directive|define
name|IWI_CMD_SET_FRAG_THRESHOLD
value|16
define|#
directive|define
name|IWI_CMD_SET_POWER_MODE
value|17
define|#
directive|define
name|IWI_CMD_SET_WEP_KEY
value|18
define|#
directive|define
name|IWI_CMD_SCAN
value|20
define|#
directive|define
name|IWI_CMD_ASSOCIATE
value|21
define|#
directive|define
name|IWI_CMD_SET_RATES
value|22
define|#
directive|define
name|IWI_CMD_ABORT_SCAN
value|23
define|#
directive|define
name|IWI_CMD_SET_WME_PARAMS
value|25
define|#
directive|define
name|IWI_CMD_SCAN_EXT
value|26
define|#
directive|define
name|IWI_CMD_SET_OPTIE
value|31
define|#
directive|define
name|IWI_CMD_DISABLE
value|33
define|#
directive|define
name|IWI_CMD_SET_IV
value|34
define|#
directive|define
name|IWI_CMD_SET_TX_POWER
value|35
define|#
directive|define
name|IWI_CMD_SET_SENSITIVITY
value|42
define|#
directive|define
name|IWI_CMD_SET_WMEIE
value|84
name|uint8_t
name|len
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
name|uint8_t
name|data
index|[
literal|120
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* node information (IBSS) */
end_comment

begin_struct
struct|struct
name|iwi_ibssnode
block|{
name|uint8_t
name|bssid
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* constants for 'mode' fields */
end_comment

begin_define
define|#
directive|define
name|IWI_MODE_11A
value|0
end_define

begin_define
define|#
directive|define
name|IWI_MODE_11B
value|1
end_define

begin_define
define|#
directive|define
name|IWI_MODE_11G
value|2
end_define

begin_comment
comment|/* possible values for command IWI_CMD_SET_POWER_MODE */
end_comment

begin_define
define|#
directive|define
name|IWI_POWER_MODE_CAM
value|0
end_define

begin_comment
comment|/* no power save */
end_comment

begin_define
define|#
directive|define
name|IWI_POWER_MODE_PSP
value|3
end_define

begin_define
define|#
directive|define
name|IWI_POWER_MODE_MAX
value|5
end_define

begin_comment
comment|/* max power save operation */
end_comment

begin_comment
comment|/* structure for command IWI_CMD_SET_RATES */
end_comment

begin_struct
struct|struct
name|iwi_rateset
block|{
name|uint8_t
name|mode
decl_stmt|;
name|uint8_t
name|nrates
decl_stmt|;
name|uint8_t
name|type
decl_stmt|;
define|#
directive|define
name|IWI_RATESET_TYPE_NEGOTIATED
value|0
define|#
directive|define
name|IWI_RATESET_TYPE_SUPPORTED
value|1
name|uint8_t
name|reserved
decl_stmt|;
define|#
directive|define
name|IWI_RATESET_SIZE
value|12
name|uint8_t
name|rates
index|[
name|IWI_RATESET_SIZE
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for command IWI_CMD_SET_TX_POWER */
end_comment

begin_struct
struct|struct
name|iwi_txpower
block|{
name|uint8_t
name|nchan
decl_stmt|;
name|uint8_t
name|mode
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|chan
decl_stmt|;
name|uint8_t
name|power
decl_stmt|;
define|#
directive|define
name|IWI_TXPOWER_MAX
value|20
define|#
directive|define
name|IWI_TXPOWER_RATIO
value|(IEEE80211_TXPOWER_MAX / IWI_TXPOWER_MAX)
block|}
name|__packed
name|chan
index|[
literal|37
index|]
struct|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for command IWI_CMD_ASSOCIATE */
end_comment

begin_struct
struct|struct
name|iwi_associate
block|{
name|uint8_t
name|chan
decl_stmt|;
comment|/* channel # */
name|uint8_t
name|auth
decl_stmt|;
comment|/* type and key */
define|#
directive|define
name|IWI_AUTH_OPEN
value|0
define|#
directive|define
name|IWI_AUTH_SHARED
value|1
define|#
directive|define
name|IWI_AUTH_NONE
value|3
name|uint8_t
name|type
decl_stmt|;
comment|/* request */
define|#
directive|define
name|IWI_HC_ASSOC
value|0
define|#
directive|define
name|IWI_HC_REASSOC
value|1
define|#
directive|define
name|IWI_HC_DISASSOC
value|2
define|#
directive|define
name|IWI_HC_IBSS_START
value|3
define|#
directive|define
name|IWI_HC_IBSS_RECONF
value|4
define|#
directive|define
name|IWI_HC_DISASSOC_QUIET
value|5
name|uint8_t
name|reserved
decl_stmt|;
name|uint16_t
name|policy
decl_stmt|;
define|#
directive|define
name|IWI_POLICY_WME
value|1
define|#
directive|define
name|IWI_POLICY_WPA
value|2
name|uint8_t
name|plen
decl_stmt|;
comment|/* preamble length */
name|uint8_t
name|mode
decl_stmt|;
comment|/* 11a, 11b, or 11g */
name|uint8_t
name|bssid
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|tstamp
index|[
literal|8
index|]
decl_stmt|;
comment|/* tsf for beacon sync */
name|uint16_t
name|capinfo
decl_stmt|;
name|uint16_t
name|lintval
decl_stmt|;
comment|/* listen interval */
name|uint16_t
name|intval
decl_stmt|;
comment|/* beacon interval */
name|uint8_t
name|dst
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint16_t
name|atim_window
decl_stmt|;
name|uint8_t
name|smr
decl_stmt|;
name|uint8_t
name|reserved1
decl_stmt|;
name|uint16_t
name|reserved2
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IWI_SCAN_CHANNELS
value|54
end_define

begin_comment
comment|/* structure for command IWI_CMD_SCAN */
end_comment

begin_struct
struct|struct
name|iwi_scan
block|{
name|uint8_t
name|type
decl_stmt|;
name|uint16_t
name|dwelltime
decl_stmt|;
comment|/* channel dwell time (ms) */
name|uint8_t
name|channels
index|[
name|IWI_SCAN_CHANNELS
index|]
decl_stmt|;
define|#
directive|define
name|IWI_CHAN_5GHZ
value|(0<< 6)
define|#
directive|define
name|IWI_CHAN_2GHZ
value|(1<< 6)
name|uint8_t
name|reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* scan type codes */
end_comment

begin_define
define|#
directive|define
name|IWI_SCAN_TYPE_PASSIVE_STOP
value|0
end_define

begin_comment
comment|/* passive, stop on first beacon */
end_comment

begin_define
define|#
directive|define
name|IWI_SCAN_TYPE_PASSIVE
value|1
end_define

begin_comment
comment|/* passive, full dwell on channel */
end_comment

begin_define
define|#
directive|define
name|IWI_SCAN_TYPE_DIRECTED
value|2
end_define

begin_comment
comment|/* active, directed probe req */
end_comment

begin_define
define|#
directive|define
name|IWI_SCAN_TYPE_BROADCAST
value|3
end_define

begin_comment
comment|/* active, bcast probe req */
end_comment

begin_define
define|#
directive|define
name|IWI_SCAN_TYPE_BDIRECTED
value|4
end_define

begin_comment
comment|/* active, directed+bcast probe */
end_comment

begin_define
define|#
directive|define
name|IWI_SCAN_TYPES
value|5
end_define

begin_comment
comment|/* structure for command IWI_CMD_SCAN_EXT */
end_comment

begin_struct
struct|struct
name|iwi_scan_ext
block|{
name|uint32_t
name|full_scan_index
decl_stmt|;
name|uint8_t
name|channels
index|[
name|IWI_SCAN_CHANNELS
index|]
decl_stmt|;
name|uint8_t
name|scan_type
index|[
name|IWI_SCAN_CHANNELS
operator|/
literal|2
index|]
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
name|uint16_t
name|dwell_time
index|[
name|IWI_SCAN_TYPES
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for command IWI_CMD_SET_CONFIG */
end_comment

begin_struct
struct|struct
name|iwi_configuration
block|{
name|uint8_t
name|bluetooth_coexistence
decl_stmt|;
name|uint8_t
name|reserved1
decl_stmt|;
name|uint8_t
name|answer_pbreq
decl_stmt|;
comment|/* answer bcast ssid probe req frames */
name|uint8_t
name|allow_invalid_frames
decl_stmt|;
comment|/* accept data frames w/ errors */
name|uint8_t
name|multicast_enabled
decl_stmt|;
comment|/* accept frames w/ any bssid */
name|uint8_t
name|drop_unicast_unencrypted
decl_stmt|;
name|uint8_t
name|disable_unicast_decryption
decl_stmt|;
name|uint8_t
name|drop_multicast_unencrypted
decl_stmt|;
name|uint8_t
name|disable_multicast_decryption
decl_stmt|;
name|uint8_t
name|antenna
decl_stmt|;
comment|/* antenna diversity */
define|#
directive|define
name|IWI_ANTENNA_AUTO
value|0
comment|/* firmware selects best antenna */
define|#
directive|define
name|IWI_ANTENNA_A
value|1
comment|/* use antenna A only */
define|#
directive|define
name|IWI_ANTENNA_B
value|3
comment|/* use antenna B only */
define|#
directive|define
name|IWI_ANTENNA_SLOWDIV
value|2
comment|/* slow diversity algorithm */
name|uint8_t
name|include_crc
decl_stmt|;
comment|/* include crc in rx'd frames */
name|uint8_t
name|use_protection
decl_stmt|;
comment|/* auto-detect 11g operation */
name|uint8_t
name|protection_ctsonly
decl_stmt|;
comment|/* use CTS-to-self protection */
name|uint8_t
name|enable_multicast_filtering
decl_stmt|;
name|uint8_t
name|bluetooth_threshold
decl_stmt|;
comment|/* collision threshold */
name|uint8_t
name|silence_threshold
decl_stmt|;
comment|/* silence over/under threshold */
name|uint8_t
name|allow_beacon_and_probe_resp
decl_stmt|;
comment|/* accept frames w/ any bssid */
name|uint8_t
name|allow_mgt
decl_stmt|;
comment|/* accept frames w/ any bssid */
name|uint8_t
name|noise_reported
decl_stmt|;
comment|/* report noise stats to host */
name|uint8_t
name|reserved5
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for command IWI_CMD_SET_WEP_KEY */
end_comment

begin_struct
struct|struct
name|iwi_wep_key
block|{
name|uint8_t
name|cmd
decl_stmt|;
define|#
directive|define
name|IWI_WEP_KEY_CMD_SETKEY
value|0x08
name|uint8_t
name|seq
decl_stmt|;
name|uint8_t
name|idx
decl_stmt|;
name|uint8_t
name|len
decl_stmt|;
name|uint8_t
name|key
index|[
name|IEEE80211_KEYBUF_SIZE
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for command IWI_CMD_SET_WME_PARAMS */
end_comment

begin_struct
struct|struct
name|iwi_wme_params
block|{
name|uint16_t
name|cwmin
index|[
name|WME_NUM_AC
index|]
decl_stmt|;
name|uint16_t
name|cwmax
index|[
name|WME_NUM_AC
index|]
decl_stmt|;
name|uint8_t
name|aifsn
index|[
name|WME_NUM_AC
index|]
decl_stmt|;
name|uint8_t
name|acm
index|[
name|WME_NUM_AC
index|]
decl_stmt|;
name|uint16_t
name|burst
index|[
name|WME_NUM_AC
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for command IWI_CMD_SET_SENSITIVTY */
end_comment

begin_struct
struct|struct
name|iwi_sensitivity
block|{
name|uint16_t
name|rssi
decl_stmt|;
comment|/* beacon rssi in dBm */
define|#
directive|define
name|IWI_RSSI_TO_DBM
value|112
name|uint16_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IWI_MEM_EEPROM_EVENT
value|0x00300004
end_define

begin_define
define|#
directive|define
name|IWI_MEM_EEPROM_CTL
value|0x00300040
end_define

begin_define
define|#
directive|define
name|IWI_EEPROM_MAC
value|0x21
end_define

begin_define
define|#
directive|define
name|IWI_EEPROM_NIC
value|0x25
end_define

begin_comment
comment|/* nic type (lsb) */
end_comment

begin_define
define|#
directive|define
name|IWI_EEPROM_SKU
value|0x25
end_define

begin_comment
comment|/* nic type (msb) */
end_comment

begin_define
define|#
directive|define
name|IWI_EEPROM_DELAY
value|1
end_define

begin_comment
comment|/* minimum hold time (microsecond) */
end_comment

begin_define
define|#
directive|define
name|IWI_EEPROM_C
value|(1<< 0)
end_define

begin_comment
comment|/* Serial Clock */
end_comment

begin_define
define|#
directive|define
name|IWI_EEPROM_S
value|(1<< 1)
end_define

begin_comment
comment|/* Chip Select */
end_comment

begin_define
define|#
directive|define
name|IWI_EEPROM_D
value|(1<< 2)
end_define

begin_comment
comment|/* Serial data input */
end_comment

begin_define
define|#
directive|define
name|IWI_EEPROM_Q
value|(1<< 4)
end_define

begin_comment
comment|/* Serial data output */
end_comment

begin_define
define|#
directive|define
name|IWI_EEPROM_SHIFT_D
value|2
end_define

begin_define
define|#
directive|define
name|IWI_EEPROM_SHIFT_Q
value|4
end_define

begin_comment
comment|/*  * control and status registers access macros  */
end_comment

begin_define
define|#
directive|define
name|CSR_READ_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_1((sc)->sc_st, (sc)->sc_sh, (reg))
end_define

begin_define
define|#
directive|define
name|CSR_READ_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_2((sc)->sc_st, (sc)->sc_sh, (reg))
end_define

begin_define
define|#
directive|define
name|CSR_READ_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4((sc)->sc_st, (sc)->sc_sh, (reg))
end_define

begin_define
define|#
directive|define
name|CSR_READ_REGION_4
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|datap
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_read_region_4((sc)->sc_st, (sc)->sc_sh, (offset),	\ 	    (datap), (count))
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_1((sc)->sc_st, (sc)->sc_sh, (reg), (val))
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_2((sc)->sc_st, (sc)->sc_sh, (reg), (val))
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4((sc)->sc_st, (sc)->sc_sh, (reg), (val))
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_REGION_1
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|datap
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_write_region_1((sc)->sc_st, (sc)->sc_sh, (offset),	\ 	    (datap), (count))
end_define

begin_comment
comment|/*  * indirect memory space access macros  */
end_comment

begin_define
define|#
directive|define
name|MEM_WRITE_1
parameter_list|(
name|sc
parameter_list|,
name|addr
parameter_list|,
name|val
parameter_list|)
value|do {					\ 	CSR_WRITE_4((sc), IWI_CSR_INDIRECT_ADDR, (addr));		\ 	CSR_WRITE_1((sc), IWI_CSR_INDIRECT_DATA, (val));		\ } while (
comment|/* CONSTCOND */
value|0)
end_define

begin_define
define|#
directive|define
name|MEM_WRITE_2
parameter_list|(
name|sc
parameter_list|,
name|addr
parameter_list|,
name|val
parameter_list|)
value|do {					\ 	CSR_WRITE_4((sc), IWI_CSR_INDIRECT_ADDR, (addr));		\ 	CSR_WRITE_2((sc), IWI_CSR_INDIRECT_DATA, (val));		\ } while (
comment|/* CONSTCOND */
value|0)
end_define

begin_define
define|#
directive|define
name|MEM_WRITE_4
parameter_list|(
name|sc
parameter_list|,
name|addr
parameter_list|,
name|val
parameter_list|)
value|do {					\ 	CSR_WRITE_4((sc), IWI_CSR_INDIRECT_ADDR, (addr));		\ 	CSR_WRITE_4((sc), IWI_CSR_INDIRECT_DATA, (val));		\ } while (
comment|/* CONSTCOND */
value|0)
end_define

begin_define
define|#
directive|define
name|MEM_WRITE_MULTI_1
parameter_list|(
name|sc
parameter_list|,
name|addr
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
value|do {			\ 	CSR_WRITE_4((sc), IWI_CSR_INDIRECT_ADDR, (addr));		\ 	CSR_WRITE_MULTI_1((sc), IWI_CSR_INDIRECT_DATA, (buf), (len));	\ } while (
comment|/* CONSTCOND */
value|0)
end_define

begin_comment
comment|/*  * EEPROM access macro  */
end_comment

begin_define
define|#
directive|define
name|IWI_EEPROM_CTL
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
value|do {					\ 	MEM_WRITE_4((sc), IWI_MEM_EEPROM_CTL, (val));			\ 	DELAY(IWI_EEPROM_DELAY);					\ } while (
comment|/* CONSTCOND */
value|0)
end_define

end_unit

