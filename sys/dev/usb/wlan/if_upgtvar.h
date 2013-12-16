begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: if_upgtvar.h,v 1.14 2008/02/02 13:48:44 mglocker Exp $ */
end_comment

begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2007 Marcus Glocker<mglocker@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_struct_decl
struct_decl|struct
name|upgt_softc
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * General values.  */
end_comment

begin_enum
enum|enum
block|{
name|UPGT_BULK_RX
block|,
name|UPGT_BULK_TX
block|,
name|UPGT_N_XFERS
init|=
literal|2
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|UPGT_CONFIG_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|UPGT_IFACE_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|UPGT_USB_TIMEOUT
value|1000
end_define

begin_define
define|#
directive|define
name|UPGT_FIRMWARE_TIMEOUT
value|10
end_define

begin_define
define|#
directive|define
name|UPGT_MEMADDR_FIRMWARE_START
value|0x00020000
end_define

begin_comment
comment|/* 512 bytes large */
end_comment

begin_define
define|#
directive|define
name|UPGT_MEMSIZE_FRAME_HEAD
value|0x0070
end_define

begin_define
define|#
directive|define
name|UPGT_MEMSIZE_RX
value|0x3500
end_define

begin_define
define|#
directive|define
name|UPGT_RX_MAXCOUNT
value|6
end_define

begin_define
define|#
directive|define
name|UPGT_TX_MAXCOUNT
value|128
end_define

begin_define
define|#
directive|define
name|UPGT_TX_STAT_INTERVAL
value|5
end_define

begin_define
define|#
directive|define
name|UPGT_RX_MINSZ
value|(sizeof(struct upgt_lmac_header) + 4)
end_define

begin_comment
comment|/* device flags */
end_comment

begin_define
define|#
directive|define
name|UPGT_DEVICE_ATTACHED
value|(1<< 0)
end_define

begin_comment
comment|/* leds */
end_comment

begin_define
define|#
directive|define
name|UPGT_LED_OFF
value|0
end_define

begin_define
define|#
directive|define
name|UPGT_LED_ON
value|1
end_define

begin_define
define|#
directive|define
name|UPGT_LED_BLINK
value|2
end_define

begin_comment
comment|/*  * Firmware.  */
end_comment

begin_define
define|#
directive|define
name|UPGT_FW_BLOCK_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|UPGT_BRA_FWTYPE_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|UPGT_BRA_FWTYPE_LM86
value|"LM86"
end_define

begin_define
define|#
directive|define
name|UPGT_BRA_FWTYPE_LM87
value|"LM87"
end_define

begin_enum
enum|enum
name|upgt_fw_type
block|{
name|UPGT_FWTYPE_LM86
block|,
name|UPGT_FWTYPE_LM87
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|UPGT_BRA_TYPE_FW
value|0x80000001
end_define

begin_define
define|#
directive|define
name|UPGT_BRA_TYPE_VERSION
value|0x80000002
end_define

begin_define
define|#
directive|define
name|UPGT_BRA_TYPE_DEPIF
value|0x80000003
end_define

begin_define
define|#
directive|define
name|UPGT_BRA_TYPE_EXPIF
value|0x80000004
end_define

begin_define
define|#
directive|define
name|UPGT_BRA_TYPE_DESCR
value|0x80000101
end_define

begin_define
define|#
directive|define
name|UPGT_BRA_TYPE_END
value|0xff0000ff
end_define

begin_struct
struct|struct
name|upgt_fw_bra_option
block|{
name|uint32_t
name|type
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
name|uint8_t
name|data
index|[]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|upgt_fw_bra_descr
block|{
name|uint32_t
name|unknown1
decl_stmt|;
name|uint32_t
name|memaddr_space_start
decl_stmt|;
name|uint32_t
name|memaddr_space_end
decl_stmt|;
name|uint32_t
name|unknown2
decl_stmt|;
name|uint32_t
name|unknown3
decl_stmt|;
name|uint8_t
name|rates
index|[
literal|20
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|UPGT_X2_SIGNATURE_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|UPGT_X2_SIGNATURE
value|"x2  "
end_define

begin_struct
struct|struct
name|upgt_fw_x2_header
block|{
name|uint8_t
name|signature
index|[
literal|4
index|]
decl_stmt|;
name|uint32_t
name|startaddr
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
name|uint32_t
name|crc
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * EEPROM.  */
end_comment

begin_define
define|#
directive|define
name|UPGT_EEPROM_SIZE
value|8192
end_define

begin_define
define|#
directive|define
name|UPGT_EEPROM_BLOCK_SIZE
value|1020
end_define

begin_struct
struct|struct
name|upgt_eeprom_header
block|{
comment|/* 14 bytes */
name|uint32_t
name|magic
decl_stmt|;
name|uint16_t
name|pad1
decl_stmt|;
name|uint16_t
name|preamble_len
decl_stmt|;
name|uint32_t
name|pad2
decl_stmt|;
comment|/* data */
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|UPGT_EEPROM_TYPE_END
value|0x0000
end_define

begin_define
define|#
directive|define
name|UPGT_EEPROM_TYPE_NAME
value|0x0001
end_define

begin_define
define|#
directive|define
name|UPGT_EEPROM_TYPE_SERIAL
value|0x0003
end_define

begin_define
define|#
directive|define
name|UPGT_EEPROM_TYPE_MAC
value|0x0101
end_define

begin_define
define|#
directive|define
name|UPGT_EEPROM_TYPE_HWRX
value|0x1001
end_define

begin_define
define|#
directive|define
name|UPGT_EEPROM_TYPE_CHIP
value|0x1002
end_define

begin_define
define|#
directive|define
name|UPGT_EEPROM_TYPE_FREQ3
value|0x1903
end_define

begin_define
define|#
directive|define
name|UPGT_EEPROM_TYPE_FREQ4
value|0x1904
end_define

begin_define
define|#
directive|define
name|UPGT_EEPROM_TYPE_FREQ5
value|0x1905
end_define

begin_define
define|#
directive|define
name|UPGT_EEPROM_TYPE_FREQ6
value|0x1906
end_define

begin_define
define|#
directive|define
name|UPGT_EEPROM_TYPE_OFF
value|0xffff
end_define

begin_struct
struct|struct
name|upgt_eeprom_option
block|{
name|uint16_t
name|len
decl_stmt|;
name|uint16_t
name|type
decl_stmt|;
name|uint8_t
name|data
index|[]
decl_stmt|;
comment|/* data */
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|UPGT_EEPROM_RX_CONST
value|0x88
end_define

begin_struct
struct|struct
name|upgt_eeprom_option_hwrx
block|{
name|uint32_t
name|pad1
decl_stmt|;
name|uint8_t
name|rxfilter
decl_stmt|;
name|uint8_t
name|pad2
index|[
literal|15
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|upgt_eeprom_freq3_header
block|{
name|uint8_t
name|flags
decl_stmt|;
name|uint8_t
name|elements
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|upgt_eeprom_freq4_header
block|{
name|uint8_t
name|flags
decl_stmt|;
name|uint8_t
name|elements
decl_stmt|;
name|uint8_t
name|settings
decl_stmt|;
name|uint8_t
name|type
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|upgt_eeprom_freq4_1
block|{
name|uint16_t
name|freq
decl_stmt|;
name|uint8_t
name|data
index|[
literal|50
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|upgt_eeprom_freq4_2
block|{
name|uint16_t
name|head
decl_stmt|;
name|uint8_t
name|subtails
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|tail
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * LMAC protocol.  */
end_comment

begin_struct
struct|struct
name|upgt_lmac_mem
block|{
name|uint32_t
name|addr
decl_stmt|;
name|uint32_t
name|chksum
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|UPGT_H1_FLAGS_TX_MGMT
value|0x00
end_define

begin_comment
comment|/* for TX: mgmt frame */
end_comment

begin_define
define|#
directive|define
name|UPGT_H1_FLAGS_TX_NO_CALLBACK
value|0x01
end_define

begin_comment
comment|/* for TX: no USB callback */
end_comment

begin_define
define|#
directive|define
name|UPGT_H1_FLAGS_TX_DATA
value|0x10
end_define

begin_comment
comment|/* for TX: data frame */
end_comment

begin_define
define|#
directive|define
name|UPGT_H1_TYPE_RX_DATA
value|0x00
end_define

begin_comment
comment|/* 802.11 RX data frame */
end_comment

begin_define
define|#
directive|define
name|UPGT_H1_TYPE_RX_DATA_MGMT
value|0x04
end_define

begin_comment
comment|/* 802.11 RX mgmt frame */
end_comment

begin_define
define|#
directive|define
name|UPGT_H1_TYPE_TX_DATA
value|0x40
end_define

begin_comment
comment|/* 802.11 TX data frame */
end_comment

begin_define
define|#
directive|define
name|UPGT_H1_TYPE_CTRL
value|0x80
end_define

begin_comment
comment|/* control frame */
end_comment

begin_struct
struct|struct
name|upgt_lmac_h1
block|{
comment|/* 4 bytes */
name|uint8_t
name|flags
decl_stmt|;
name|uint8_t
name|type
decl_stmt|;
name|uint16_t
name|len
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|UPGT_H2_TYPE_TX_ACK_NO
value|0x0000
end_define

begin_define
define|#
directive|define
name|UPGT_H2_TYPE_TX_ACK_YES
value|0x0001
end_define

begin_define
define|#
directive|define
name|UPGT_H2_TYPE_MACFILTER
value|0x0000
end_define

begin_define
define|#
directive|define
name|UPGT_H2_TYPE_CHANNEL
value|0x0001
end_define

begin_define
define|#
directive|define
name|UPGT_H2_TYPE_TX_DONE
value|0x0008
end_define

begin_define
define|#
directive|define
name|UPGT_H2_TYPE_STATS
value|0x000a
end_define

begin_define
define|#
directive|define
name|UPGT_H2_TYPE_EEPROM
value|0x000c
end_define

begin_define
define|#
directive|define
name|UPGT_H2_TYPE_LED
value|0x000d
end_define

begin_define
define|#
directive|define
name|UPGT_H2_FLAGS_TX_ACK_NO
value|0x0101
end_define

begin_define
define|#
directive|define
name|UPGT_H2_FLAGS_TX_ACK_YES
value|0x0707
end_define

begin_struct
struct|struct
name|upgt_lmac_h2
block|{
comment|/* 8 bytes */
name|uint32_t
name|reqid
decl_stmt|;
name|uint16_t
name|type
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|upgt_lmac_header
block|{
comment|/* 12 bytes */
name|struct
name|upgt_lmac_h1
name|header1
decl_stmt|;
name|struct
name|upgt_lmac_h2
name|header2
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|upgt_lmac_eeprom
block|{
comment|/* 16 bytes */
name|struct
name|upgt_lmac_h1
name|header1
decl_stmt|;
name|struct
name|upgt_lmac_h2
name|header2
decl_stmt|;
name|uint16_t
name|offset
decl_stmt|;
name|uint16_t
name|len
decl_stmt|;
comment|/* data */
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|UPGT_FILTER_TYPE_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|UPGT_FILTER_TYPE_STA
value|0x0001
end_define

begin_define
define|#
directive|define
name|UPGT_FILTER_TYPE_IBSS
value|0x0002
end_define

begin_define
define|#
directive|define
name|UPGT_FILTER_TYPE_HOSTAP
value|0x0004
end_define

begin_define
define|#
directive|define
name|UPGT_FILTER_TYPE_MONITOR
value|0x0010
end_define

begin_define
define|#
directive|define
name|UPGT_FILTER_TYPE_RESET
value|0x0020
end_define

begin_define
define|#
directive|define
name|UPGT_FILTER_UNKNOWN1
value|0x0002
end_define

begin_define
define|#
directive|define
name|UPGT_FILTER_UNKNOWN2
value|0x0ca8
end_define

begin_define
define|#
directive|define
name|UPGT_FILTER_UNKNOWN3
value|0xffff
end_define

begin_define
define|#
directive|define
name|UPGT_FILTER_MONITOR_UNKNOWN1
value|0x0000
end_define

begin_define
define|#
directive|define
name|UPGT_FILTER_MONITOR_UNKNOWN2
value|0x0000
end_define

begin_define
define|#
directive|define
name|UPGT_FILTER_MONITOR_UNKNOWN3
value|0x0000
end_define

begin_struct
struct|struct
name|upgt_lmac_filter
block|{
name|struct
name|upgt_lmac_h1
name|header1
decl_stmt|;
name|struct
name|upgt_lmac_h2
name|header2
decl_stmt|;
comment|/* 32 bytes */
name|uint16_t
name|type
decl_stmt|;
name|uint8_t
name|dst
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|src
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint16_t
name|unknown1
decl_stmt|;
name|uint32_t
name|rxaddr
decl_stmt|;
name|uint16_t
name|unknown2
decl_stmt|;
name|uint32_t
name|rxhw
decl_stmt|;
name|uint16_t
name|unknown3
decl_stmt|;
name|uint32_t
name|unknown4
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* frequence 3 data */
end_comment

begin_struct
struct|struct
name|upgt_lmac_freq3
block|{
name|uint16_t
name|freq
decl_stmt|;
name|uint8_t
name|data
index|[
literal|6
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* frequence 4 data */
end_comment

begin_struct
struct|struct
name|upgt_lmac_freq4
block|{
name|struct
name|upgt_eeprom_freq4_2
name|cmd
decl_stmt|;
name|uint8_t
name|pad
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* frequence 6 data */
end_comment

begin_struct
struct|struct
name|upgt_lmac_freq6
block|{
name|uint16_t
name|freq
decl_stmt|;
name|uint8_t
name|data
index|[
literal|8
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|UPGT_CHANNEL_UNKNOWN1
value|0x0001
end_define

begin_define
define|#
directive|define
name|UPGT_CHANNEL_UNKNOWN2
value|0x0000
end_define

begin_define
define|#
directive|define
name|UPGT_CHANNEL_UNKNOWN3
value|0x48
end_define

begin_struct
struct|struct
name|upgt_lmac_channel
block|{
name|struct
name|upgt_lmac_h1
name|header1
decl_stmt|;
name|struct
name|upgt_lmac_h2
name|header2
decl_stmt|;
comment|/* 112 bytes */
name|uint16_t
name|unknown1
decl_stmt|;
name|uint16_t
name|unknown2
decl_stmt|;
name|uint8_t
name|pad1
index|[
literal|20
index|]
decl_stmt|;
name|struct
name|upgt_lmac_freq6
name|freq6
decl_stmt|;
name|uint8_t
name|settings
decl_stmt|;
name|uint8_t
name|unknown3
decl_stmt|;
name|uint8_t
name|freq3_1
index|[
literal|4
index|]
decl_stmt|;
name|struct
name|upgt_lmac_freq4
name|freq4
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|freq3_2
index|[
literal|4
index|]
decl_stmt|;
name|uint32_t
name|pad2
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|UPGT_LED_MODE_SET
value|0x0003
end_define

begin_define
define|#
directive|define
name|UPGT_LED_ACTION_OFF
value|0x0002
end_define

begin_define
define|#
directive|define
name|UPGT_LED_ACTION_ON
value|0x0003
end_define

begin_define
define|#
directive|define
name|UPGT_LED_ACTION_TMP_DUR
value|100
end_define

begin_comment
comment|/* ms */
end_comment

begin_struct
struct|struct
name|upgt_lmac_led
block|{
name|struct
name|upgt_lmac_h1
name|header1
decl_stmt|;
name|struct
name|upgt_lmac_h2
name|header2
decl_stmt|;
name|uint16_t
name|mode
decl_stmt|;
name|uint16_t
name|action_fix
decl_stmt|;
name|uint16_t
name|action_tmp
decl_stmt|;
name|uint16_t
name|action_tmp_dur
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|upgt_lmac_stats
block|{
name|struct
name|upgt_lmac_h1
name|header1
decl_stmt|;
name|struct
name|upgt_lmac_h2
name|header2
decl_stmt|;
name|uint8_t
name|data
index|[
literal|76
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|upgt_lmac_rx_desc
block|{
name|struct
name|upgt_lmac_h1
name|header1
decl_stmt|;
comment|/* 16 bytes */
name|uint16_t
name|freq
decl_stmt|;
name|uint8_t
name|unknown1
decl_stmt|;
name|uint8_t
name|rate
decl_stmt|;
name|uint8_t
name|rssi
decl_stmt|;
name|uint8_t
name|pad
decl_stmt|;
name|uint16_t
name|unknown2
decl_stmt|;
name|uint32_t
name|timestamp
decl_stmt|;
name|uint32_t
name|unknown3
decl_stmt|;
name|uint8_t
name|data
index|[]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|UPGT_TX_DESC_KEY_EXISTS
value|0x01
end_define

begin_struct
struct|struct
name|upgt_lmac_tx_desc_wep
block|{
name|uint8_t
name|key_exists
decl_stmt|;
name|uint8_t
name|key_len
decl_stmt|;
name|uint8_t
name|key_val
index|[
literal|16
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|UPGT_TX_DESC_TYPE_BEACON
value|0x00000000
end_define

begin_define
define|#
directive|define
name|UPGT_TX_DESC_TYPE_PROBE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|UPGT_TX_DESC_TYPE_MGMT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|UPGT_TX_DESC_TYPE_DATA
value|0x00000004
end_define

begin_define
define|#
directive|define
name|UPGT_TX_DESC_PAD3_SIZE
value|2
end_define

begin_struct
struct|struct
name|upgt_lmac_tx_desc
block|{
name|struct
name|upgt_lmac_h1
name|header1
decl_stmt|;
name|struct
name|upgt_lmac_h2
name|header2
decl_stmt|;
name|uint8_t
name|rates
index|[
literal|8
index|]
decl_stmt|;
name|uint16_t
name|pad1
decl_stmt|;
name|struct
name|upgt_lmac_tx_desc_wep
name|wep_key
decl_stmt|;
name|uint32_t
name|type
decl_stmt|;
name|uint32_t
name|pad2
decl_stmt|;
name|uint32_t
name|unknown1
decl_stmt|;
name|uint32_t
name|unknown2
decl_stmt|;
name|uint8_t
name|pad3
index|[
literal|2
index|]
decl_stmt|;
comment|/* 802.11 frame data */
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|UPGT_TX_DONE_DESC_STATUS_OK
value|0x0001
end_define

begin_struct
struct|struct
name|upgt_lmac_tx_done_desc
block|{
name|struct
name|upgt_lmac_h1
name|header1
decl_stmt|;
name|struct
name|upgt_lmac_h2
name|header2
decl_stmt|;
name|uint16_t
name|status
decl_stmt|;
name|uint16_t
name|rssi
decl_stmt|;
name|uint16_t
name|seq
decl_stmt|;
name|uint16_t
name|unknown
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * USB xfers.  */
end_comment

begin_struct
struct|struct
name|upgt_data
block|{
name|uint8_t
modifier|*
name|buf
decl_stmt|;
name|uint32_t
name|buflen
decl_stmt|;
name|struct
name|ieee80211_node
modifier|*
name|ni
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|uint32_t
name|addr
decl_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|upgt_data
argument_list|)
name|next
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|upgt_data
argument_list|)
name|upgt_datahead
expr_stmt|;
end_typedef

begin_comment
comment|/*  * Prism memory.  */
end_comment

begin_struct
struct|struct
name|upgt_memory_page
block|{
name|uint8_t
name|used
decl_stmt|;
name|uint32_t
name|addr
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|UPGT_MEMORY_MAX_PAGES
value|8
end_define

begin_struct
struct|struct
name|upgt_memory
block|{
name|uint8_t
name|pages
decl_stmt|;
name|struct
name|upgt_memory_page
name|page
index|[
name|UPGT_MEMORY_MAX_PAGES
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * BPF  */
end_comment

begin_struct
struct|struct
name|upgt_rx_radiotap_header
block|{
name|struct
name|ieee80211_radiotap_header
name|wr_ihdr
decl_stmt|;
name|uint8_t
name|wr_flags
decl_stmt|;
name|uint8_t
name|wr_rate
decl_stmt|;
name|uint16_t
name|wr_chan_freq
decl_stmt|;
name|uint16_t
name|wr_chan_flags
decl_stmt|;
name|int8_t
name|wr_antsignal
decl_stmt|;
block|}
name|__packed
name|__aligned
argument_list|(
literal|8
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|UPGT_RX_RADIOTAP_PRESENT
define|\
value|((1<< IEEE80211_RADIOTAP_FLAGS) |				\ 	 (1<< IEEE80211_RADIOTAP_RATE) |				\ 	 (1<< IEEE80211_RADIOTAP_CHANNEL) |				\ 	 (1<< IEEE80211_RADIOTAP_DB_ANTSIGNAL))
end_define

begin_struct
struct|struct
name|upgt_tx_radiotap_header
block|{
name|struct
name|ieee80211_radiotap_header
name|wt_ihdr
decl_stmt|;
name|uint8_t
name|wt_flags
decl_stmt|;
name|uint8_t
name|wt_rate
decl_stmt|;
name|uint16_t
name|wt_chan_freq
decl_stmt|;
name|uint16_t
name|wt_chan_flags
decl_stmt|;
block|}
name|__packed
name|__aligned
argument_list|(
literal|8
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|UPGT_TX_RADIOTAP_PRESENT
define|\
value|((1<< IEEE80211_RADIOTAP_FLAGS) |				\ 	 (1<< IEEE80211_RADIOTAP_RATE) |				\ 	 (1<< IEEE80211_RADIOTAP_CHANNEL))
end_define

begin_struct
struct|struct
name|upgt_stat
block|{
name|uint32_t
name|st_tx_active
decl_stmt|;
name|uint32_t
name|st_tx_inactive
decl_stmt|;
name|uint32_t
name|st_tx_pending
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UPGT_STAT_INC
parameter_list|(
name|sc
parameter_list|,
name|var
parameter_list|)
value|(sc)->sc_stat.var++
end_define

begin_define
define|#
directive|define
name|UPGT_STAT_DEC
parameter_list|(
name|sc
parameter_list|,
name|var
parameter_list|)
value|(sc)->sc_stat.var--
end_define

begin_struct
struct|struct
name|upgt_vap
block|{
name|struct
name|ieee80211vap
name|vap
decl_stmt|;
name|int
function_decl|(
modifier|*
name|newstate
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
name|UPGT_VAP
parameter_list|(
name|vap
parameter_list|)
value|((struct upgt_vap *)(vap))
end_define

begin_struct
struct|struct
name|upgt_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|sc_ifp
decl_stmt|;
name|struct
name|usb_device
modifier|*
name|sc_udev
decl_stmt|;
name|void
modifier|*
name|sc_rx_dma_buf
decl_stmt|;
name|void
modifier|*
name|sc_tx_dma_buf
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
name|struct
name|upgt_stat
name|sc_stat
decl_stmt|;
name|int
name|sc_flags
decl_stmt|;
define|#
directive|define
name|UPGT_FLAG_FWLOADED
value|(1<< 0)
define|#
directive|define
name|UPGT_FLAG_INITDONE
value|(1<< 1)
define|#
directive|define
name|UPGT_FLAG_DETACHED
value|(1<< 2)
name|int
name|sc_if_flags
decl_stmt|;
name|int
name|sc_debug
decl_stmt|;
name|uint8_t
name|sc_myaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|enum
name|ieee80211_state
name|sc_state
decl_stmt|;
name|int
name|sc_arg
decl_stmt|;
name|int
name|sc_led_blink
decl_stmt|;
name|struct
name|callout
name|sc_led_ch
decl_stmt|;
name|uint8_t
name|sc_cur_rateset
index|[
literal|8
index|]
decl_stmt|;
comment|/* watchdog  */
name|int
name|sc_tx_timer
decl_stmt|;
name|struct
name|callout
name|sc_watchdog_ch
decl_stmt|;
comment|/* Firmware.  */
name|int
name|sc_fw_type
decl_stmt|;
comment|/* memory addresses on device */
name|uint32_t
name|sc_memaddr_frame_start
decl_stmt|;
name|uint32_t
name|sc_memaddr_frame_end
decl_stmt|;
name|uint32_t
name|sc_memaddr_rx_start
decl_stmt|;
name|struct
name|upgt_memory
name|sc_memory
decl_stmt|;
comment|/* data which we found in the EEPROM */
name|uint8_t
name|sc_eeprom
index|[
literal|2
operator|*
name|UPGT_EEPROM_SIZE
index|]
name|__aligned
argument_list|(
literal|4
argument_list|)
decl_stmt|;
name|uint16_t
name|sc_eeprom_hwrx
decl_stmt|;
name|struct
name|upgt_lmac_freq3
name|sc_eeprom_freq3
index|[
name|IEEE80211_CHAN_MAX
index|]
decl_stmt|;
name|struct
name|upgt_lmac_freq4
name|sc_eeprom_freq4
index|[
name|IEEE80211_CHAN_MAX
index|]
index|[
literal|8
index|]
decl_stmt|;
name|struct
name|upgt_lmac_freq6
name|sc_eeprom_freq6
index|[
name|IEEE80211_CHAN_MAX
index|]
decl_stmt|;
name|uint8_t
name|sc_eeprom_freq6_settings
decl_stmt|;
comment|/* RX/TX  */
name|struct
name|usb_xfer
modifier|*
name|sc_xfer
index|[
name|UPGT_N_XFERS
index|]
decl_stmt|;
name|int
name|sc_rx_no
decl_stmt|;
name|int
name|sc_tx_no
decl_stmt|;
name|struct
name|upgt_data
name|sc_rx_data
index|[
name|UPGT_RX_MAXCOUNT
index|]
decl_stmt|;
name|upgt_datahead
name|sc_rx_active
decl_stmt|;
name|upgt_datahead
name|sc_rx_inactive
decl_stmt|;
name|struct
name|upgt_data
name|sc_tx_data
index|[
name|UPGT_TX_MAXCOUNT
index|]
decl_stmt|;
name|upgt_datahead
name|sc_tx_active
decl_stmt|;
name|upgt_datahead
name|sc_tx_inactive
decl_stmt|;
name|upgt_datahead
name|sc_tx_pending
decl_stmt|;
comment|/* BPF  */
name|struct
name|upgt_rx_radiotap_header
name|sc_rxtap
decl_stmt|;
name|int
name|sc_rxtap_len
decl_stmt|;
name|struct
name|upgt_tx_radiotap_header
name|sc_txtap
decl_stmt|;
name|int
name|sc_txtap_len
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UPGT_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|UPGT_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|UPGT_ASSERT_LOCKED
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&(sc)->sc_mtx, MA_OWNED)
end_define

end_unit

