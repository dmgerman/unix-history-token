begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*      $FreeBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2004, 2005  *      Damien Bergamini<damien.bergamini@free.fr>. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_define
define|#
directive|define
name|IPW_NTBD
value|128
end_define

begin_define
define|#
directive|define
name|IPW_TBD_SZ
value|(IPW_NTBD * sizeof (struct ipw_bd))
end_define

begin_define
define|#
directive|define
name|IPW_NDATA
value|(IPW_NTBD / 2)
end_define

begin_define
define|#
directive|define
name|IPW_NRBD
value|128
end_define

begin_define
define|#
directive|define
name|IPW_RBD_SZ
value|(IPW_NRBD * sizeof (struct ipw_bd))
end_define

begin_define
define|#
directive|define
name|IPW_STATUS_SZ
value|(IPW_NRBD * sizeof (struct ipw_status))
end_define

begin_define
define|#
directive|define
name|IPW_CSR_INTR
value|0x0008
end_define

begin_define
define|#
directive|define
name|IPW_CSR_INTR_MASK
value|0x000c
end_define

begin_define
define|#
directive|define
name|IPW_CSR_INDIRECT_ADDR
value|0x0010
end_define

begin_define
define|#
directive|define
name|IPW_CSR_INDIRECT_DATA
value|0x0014
end_define

begin_define
define|#
directive|define
name|IPW_CSR_AUTOINC_ADDR
value|0x0018
end_define

begin_define
define|#
directive|define
name|IPW_CSR_AUTOINC_DATA
value|0x001c
end_define

begin_define
define|#
directive|define
name|IPW_CSR_RST
value|0x0020
end_define

begin_define
define|#
directive|define
name|IPW_CSR_CTL
value|0x0024
end_define

begin_define
define|#
directive|define
name|IPW_CSR_IO
value|0x0030
end_define

begin_define
define|#
directive|define
name|IPW_CSR_TX_BASE
value|0x0200
end_define

begin_define
define|#
directive|define
name|IPW_CSR_TX_SIZE
value|0x0204
end_define

begin_define
define|#
directive|define
name|IPW_CSR_RX_BASE
value|0x0240
end_define

begin_define
define|#
directive|define
name|IPW_CSR_STATUS_BASE
value|0x0244
end_define

begin_define
define|#
directive|define
name|IPW_CSR_RX_SIZE
value|0x0248
end_define

begin_define
define|#
directive|define
name|IPW_CSR_TX_READ
value|0x0280
end_define

begin_define
define|#
directive|define
name|IPW_CSR_RX_READ
value|0x02a0
end_define

begin_define
define|#
directive|define
name|IPW_CSR_TABLE1_BASE
value|0x0380
end_define

begin_define
define|#
directive|define
name|IPW_CSR_TABLE2_BASE
value|0x0384
end_define

begin_define
define|#
directive|define
name|IPW_CSR_TX_WRITE
value|0x0f80
end_define

begin_define
define|#
directive|define
name|IPW_CSR_RX_WRITE
value|0x0fa0
end_define

begin_comment
comment|/* possible flags for register IPW_CSR_INTR */
end_comment

begin_define
define|#
directive|define
name|IPW_INTR_TX_TRANSFER
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IPW_INTR_RX_TRANSFER
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IPW_INTR_STATUS_CHANGE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IPW_INTR_COMMAND_DONE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|IPW_INTR_FW_INIT_DONE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|IPW_INTR_FATAL_ERROR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|IPW_INTR_PARITY_ERROR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IPW_INTR_MASK
define|\
value|(IPW_INTR_TX_TRANSFER | IPW_INTR_RX_TRANSFER |			\ 	 IPW_INTR_STATUS_CHANGE | IPW_INTR_COMMAND_DONE |		\ 	 IPW_INTR_FW_INIT_DONE | IPW_INTR_FATAL_ERROR |			\ 	 IPW_INTR_PARITY_ERROR)
end_define

begin_comment
comment|/* possible flags for register IPW_CSR_RST */
end_comment

begin_define
define|#
directive|define
name|IPW_RST_PRINCETON_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IPW_RST_SW_RESET
value|0x00000080
end_define

begin_define
define|#
directive|define
name|IPW_RST_MASTER_DISABLED
value|0x00000100
end_define

begin_define
define|#
directive|define
name|IPW_RST_STOP_MASTER
value|0x00000200
end_define

begin_comment
comment|/* possible flags for register IPW_CSR_CTL */
end_comment

begin_define
define|#
directive|define
name|IPW_CTL_CLOCK_READY
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IPW_CTL_ALLOW_STANDBY
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IPW_CTL_INIT
value|0x00000004
end_define

begin_comment
comment|/* possible flags for register IPW_CSR_IO */
end_comment

begin_define
define|#
directive|define
name|IPW_IO_GPIO1_ENABLE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IPW_IO_GPIO1_MASK
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|IPW_IO_GPIO3_MASK
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|IPW_IO_LED_OFF
value|0x00002000
end_define

begin_define
define|#
directive|define
name|IPW_IO_RADIO_DISABLED
value|0x00010000
end_define

begin_define
define|#
directive|define
name|IPW_STATE_ASSOCIATED
value|0x0004
end_define

begin_define
define|#
directive|define
name|IPW_STATE_ASSOCIATION_LOST
value|0x0008
end_define

begin_define
define|#
directive|define
name|IPW_STATE_SCAN_COMPLETE
value|0x0020
end_define

begin_define
define|#
directive|define
name|IPW_STATE_RADIO_DISABLED
value|0x0100
end_define

begin_define
define|#
directive|define
name|IPW_STATE_DISABLED
value|0x0200
end_define

begin_define
define|#
directive|define
name|IPW_STATE_SCANNING
value|0x0800
end_define

begin_comment
comment|/* table1 offsets */
end_comment

begin_define
define|#
directive|define
name|IPW_INFO_LOCK
value|480
end_define

begin_define
define|#
directive|define
name|IPW_INFO_APS_CNT
value|604
end_define

begin_define
define|#
directive|define
name|IPW_INFO_APS_BASE
value|608
end_define

begin_define
define|#
directive|define
name|IPW_INFO_CARD_DISABLED
value|628
end_define

begin_define
define|#
directive|define
name|IPW_INFO_CURRENT_CHANNEL
value|756
end_define

begin_define
define|#
directive|define
name|IPW_INFO_CURRENT_TX_RATE
value|768
end_define

begin_comment
comment|/* table2 offsets */
end_comment

begin_define
define|#
directive|define
name|IPW_INFO_CURRENT_SSID
value|48
end_define

begin_define
define|#
directive|define
name|IPW_INFO_CURRENT_BSSID
value|112
end_define

begin_comment
comment|/* supported rates */
end_comment

begin_define
define|#
directive|define
name|IPW_RATE_DS1
value|1
end_define

begin_define
define|#
directive|define
name|IPW_RATE_DS2
value|2
end_define

begin_define
define|#
directive|define
name|IPW_RATE_DS5
value|4
end_define

begin_define
define|#
directive|define
name|IPW_RATE_DS11
value|8
end_define

begin_comment
comment|/* firmware binary image header */
end_comment

begin_struct
struct|struct
name|ipw_firmware_hdr
block|{
name|u_int32_t
name|version
decl_stmt|;
name|u_int32_t
name|main_size
decl_stmt|;
comment|/* firmware size */
name|u_int32_t
name|ucode_size
decl_stmt|;
comment|/* microcode size */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* buffer descriptor */
end_comment

begin_struct
struct|struct
name|ipw_bd
block|{
name|u_int32_t
name|physaddr
decl_stmt|;
name|u_int32_t
name|len
decl_stmt|;
name|u_int8_t
name|flags
decl_stmt|;
define|#
directive|define
name|IPW_BD_FLAG_TX_FRAME_802_3
value|0x00
define|#
directive|define
name|IPW_BD_FLAG_TX_NOT_LAST_FRAGMENT
value|0x01
define|#
directive|define
name|IPW_BD_FLAG_TX_FRAME_COMMAND
value|0x02
define|#
directive|define
name|IPW_BD_FLAG_TX_FRAME_802_11
value|0x04
define|#
directive|define
name|IPW_BD_FLAG_TX_LAST_FRAGMENT
value|0x08
name|u_int8_t
name|nfrag
decl_stmt|;
comment|/* number of fragments */
name|u_int8_t
name|reserved
index|[
literal|6
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* status */
end_comment

begin_struct
struct|struct
name|ipw_status
block|{
name|u_int32_t
name|len
decl_stmt|;
name|u_int16_t
name|code
decl_stmt|;
define|#
directive|define
name|IPW_STATUS_CODE_COMMAND
value|0
define|#
directive|define
name|IPW_STATUS_CODE_NEWSTATE
value|1
define|#
directive|define
name|IPW_STATUS_CODE_DATA_802_11
value|2
define|#
directive|define
name|IPW_STATUS_CODE_DATA_802_3
value|3
define|#
directive|define
name|IPW_STATUS_CODE_NOTIFICATION
value|4
name|u_int8_t
name|flags
decl_stmt|;
define|#
directive|define
name|IPW_STATUS_FLAG_DECRYPTED
value|0x01
define|#
directive|define
name|IPW_STATUS_FLAG_WEP_ENCRYPTED
value|0x02
name|u_int8_t
name|rssi
decl_stmt|;
comment|/* received signal strength indicator */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* data header */
end_comment

begin_struct
struct|struct
name|ipw_hdr
block|{
name|u_int32_t
name|type
decl_stmt|;
define|#
directive|define
name|IPW_HDR_TYPE_SEND
value|33
name|u_int32_t
name|subtype
decl_stmt|;
name|u_int8_t
name|encrypted
decl_stmt|;
name|u_int8_t
name|encrypt
decl_stmt|;
name|u_int8_t
name|keyidx
decl_stmt|;
name|u_int8_t
name|keysz
decl_stmt|;
name|u_int8_t
name|key
index|[
name|IEEE80211_KEYBUF_SIZE
index|]
decl_stmt|;
name|u_int8_t
name|reserved
index|[
literal|10
index|]
decl_stmt|;
name|u_int8_t
name|src_addr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|dst_addr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int16_t
name|fragmentsz
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
name|ipw_cmd
block|{
name|u_int32_t
name|type
decl_stmt|;
define|#
directive|define
name|IPW_CMD_ENABLE
value|2
define|#
directive|define
name|IPW_CMD_SET_CONFIGURATION
value|6
define|#
directive|define
name|IPW_CMD_SET_ESSID
value|8
define|#
directive|define
name|IPW_CMD_SET_MANDATORY_BSSID
value|9
define|#
directive|define
name|IPW_CMD_SET_MAC_ADDRESS
value|11
define|#
directive|define
name|IPW_CMD_SET_MODE
value|12
define|#
directive|define
name|IPW_CMD_SET_CHANNEL
value|14
define|#
directive|define
name|IPW_CMD_SET_RTS_THRESHOLD
value|15
define|#
directive|define
name|IPW_CMD_SET_FRAG_THRESHOLD
value|16
define|#
directive|define
name|IPW_CMD_SET_POWER_MODE
value|17
define|#
directive|define
name|IPW_CMD_SET_TX_RATES
value|18
define|#
directive|define
name|IPW_CMD_SET_BASIC_TX_RATES
value|19
define|#
directive|define
name|IPW_CMD_SET_WEP_KEY
value|20
define|#
directive|define
name|IPW_CMD_SET_WEP_KEY_INDEX
value|25
define|#
directive|define
name|IPW_CMD_SET_WEP_FLAGS
value|26
define|#
directive|define
name|IPW_CMD_ADD_MULTICAST
value|27
define|#
directive|define
name|IPW_CMD_SET_BEACON_INTERVAL
value|29
define|#
directive|define
name|IPW_CMD_SET_TX_POWER_INDEX
value|36
define|#
directive|define
name|IPW_CMD_BROADCAST_SCAN
value|43
define|#
directive|define
name|IPW_CMD_DISABLE
value|44
define|#
directive|define
name|IPW_CMD_SET_DESIRED_BSSID
value|45
define|#
directive|define
name|IPW_CMD_SET_SCAN_OPTIONS
value|46
define|#
directive|define
name|IPW_CMD_PREPARE_POWER_DOWN
value|58
define|#
directive|define
name|IPW_CMD_DISABLE_PHY
value|61
define|#
directive|define
name|IPW_CMD_SET_SECURITY_INFORMATION
value|67
define|#
directive|define
name|IPW_CMD_SET_WPA_IE
value|69
name|u_int32_t
name|subtype
decl_stmt|;
name|u_int32_t
name|seq
decl_stmt|;
name|u_int32_t
name|len
decl_stmt|;
name|u_int8_t
name|data
index|[
literal|400
index|]
decl_stmt|;
name|u_int32_t
name|status
decl_stmt|;
name|u_int8_t
name|reserved
index|[
literal|68
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* possible values for command IPW_CMD_SET_POWER_MODE */
end_comment

begin_define
define|#
directive|define
name|IPW_POWER_MODE_CAM
value|0
end_define

begin_define
define|#
directive|define
name|IPW_POWER_AUTOMATIC
value|6
end_define

begin_comment
comment|/* possible values for command IPW_CMD_SET_MODE */
end_comment

begin_define
define|#
directive|define
name|IPW_MODE_BSS
value|0
end_define

begin_define
define|#
directive|define
name|IPW_MODE_IBSS
value|1
end_define

begin_define
define|#
directive|define
name|IPW_MODE_MONITOR
value|2
end_define

begin_comment
comment|/* possible flags for command IPW_CMD_SET_WEP_FLAGS */
end_comment

begin_define
define|#
directive|define
name|IPW_WEPON
value|0x8
end_define

begin_comment
comment|/* structure for command IPW_CMD_SET_WEP_KEY */
end_comment

begin_struct
struct|struct
name|ipw_wep_key
block|{
name|u_int8_t
name|idx
decl_stmt|;
name|u_int8_t
name|len
decl_stmt|;
name|u_int8_t
name|key
index|[
literal|13
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for command IPW_CMD_SET_SECURITY_INFORMATION */
end_comment

begin_struct
struct|struct
name|ipw_security
block|{
name|u_int32_t
name|ciphers
decl_stmt|;
define|#
directive|define
name|IPW_CIPHER_NONE
value|0x00000001
define|#
directive|define
name|IPW_CIPHER_WEP40
value|0x00000002
define|#
directive|define
name|IPW_CIPHER_TKIP
value|0x00000004
define|#
directive|define
name|IPW_CIPHER_CCMP
value|0x00000010
define|#
directive|define
name|IPW_CIPHER_WEP104
value|0x00000020
define|#
directive|define
name|IPW_CIPHER_CKIP
value|0x00000040
name|u_int16_t
name|reserved1
decl_stmt|;
name|u_int8_t
name|authmode
decl_stmt|;
define|#
directive|define
name|IPW_AUTH_OPEN
value|0
define|#
directive|define
name|IPW_AUTH_SHARED
value|1
name|u_int16_t
name|reserved2
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for command IPW_CMD_SET_SCAN_OPTIONS */
end_comment

begin_struct
struct|struct
name|ipw_scan_options
block|{
name|u_int32_t
name|flags
decl_stmt|;
define|#
directive|define
name|IPW_SCAN_DO_NOT_ASSOCIATE
value|0x00000001
define|#
directive|define
name|IPW_SCAN_PASSIVE
value|0x00000008
name|u_int32_t
name|channels
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for command IPW_CMD_SET_CONFIGURATION */
end_comment

begin_struct
struct|struct
name|ipw_configuration
block|{
name|u_int32_t
name|flags
decl_stmt|;
define|#
directive|define
name|IPW_CFG_PROMISCUOUS
value|0x00000004
define|#
directive|define
name|IPW_CFG_PREAMBLE_AUTO
value|0x00000010
define|#
directive|define
name|IPW_CFG_IBSS_AUTO_START
value|0x00000020
define|#
directive|define
name|IPW_CFG_802_1x_ENABLE
value|0x00004000
define|#
directive|define
name|IPW_CFG_BSS_MASK
value|0x00008000
define|#
directive|define
name|IPW_CFG_IBSS_MASK
value|0x00010000
name|u_int32_t
name|bss_chan
decl_stmt|;
name|u_int32_t
name|ibss_chan
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for command IPW_CMD_SET_WPA_IE */
end_comment

begin_struct
struct|struct
name|ipw_wpa_ie
block|{
name|u_int16_t
name|mask
decl_stmt|;
name|u_int16_t
name|capinfo
decl_stmt|;
name|u_int16_t
name|lintval
decl_stmt|;
name|u_int8_t
name|bssid
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int32_t
name|len
decl_stmt|;
name|struct
name|ieee80211_ie_wpa
name|ie
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* element in AP table */
end_comment

begin_struct
struct|struct
name|ipw_node
block|{
name|u_int32_t
name|reserved1
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|bssid
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|chan
decl_stmt|;
name|u_int8_t
name|rates
decl_stmt|;
name|u_int16_t
name|reserved2
decl_stmt|;
name|u_int16_t
name|capinfo
decl_stmt|;
name|u_int16_t
name|reserved3
decl_stmt|;
name|u_int16_t
name|intval
decl_stmt|;
name|u_int8_t
name|reserved4
index|[
literal|28
index|]
decl_stmt|;
name|u_int8_t
name|essid
index|[
name|IEEE80211_NWID_LEN
index|]
decl_stmt|;
name|u_int16_t
name|reserved5
decl_stmt|;
name|u_int8_t
name|esslen
decl_stmt|;
name|u_int8_t
name|reserved6
index|[
literal|7
index|]
decl_stmt|;
name|u_int8_t
name|rssi
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* EEPROM = Electrically Erasable Programmable Read-Only Memory */
end_comment

begin_define
define|#
directive|define
name|IPW_MEM_EEPROM_CTL
value|0x00300040
end_define

begin_define
define|#
directive|define
name|IPW_EEPROM_RADIO
value|0x11
end_define

begin_define
define|#
directive|define
name|IPW_EEPROM_MAC
value|0x21
end_define

begin_define
define|#
directive|define
name|IPW_EEPROM_CHANNEL_LIST
value|0x37
end_define

begin_define
define|#
directive|define
name|IPW_EEPROM_DELAY
value|1
end_define

begin_comment
comment|/* minimum hold time (microsecond) */
end_comment

begin_define
define|#
directive|define
name|IPW_EEPROM_C
value|(1<< 0)
end_define

begin_comment
comment|/* Serial Clock */
end_comment

begin_define
define|#
directive|define
name|IPW_EEPROM_S
value|(1<< 1)
end_define

begin_comment
comment|/* Chip Select */
end_comment

begin_define
define|#
directive|define
name|IPW_EEPROM_D
value|(1<< 2)
end_define

begin_comment
comment|/* Serial data input */
end_comment

begin_define
define|#
directive|define
name|IPW_EEPROM_Q
value|(1<< 4)
end_define

begin_comment
comment|/* Serial data output */
end_comment

begin_define
define|#
directive|define
name|IPW_EEPROM_SHIFT_D
value|2
end_define

begin_define
define|#
directive|define
name|IPW_EEPROM_SHIFT_Q
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
name|CSR_WRITE_MULTI_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
define|\
value|bus_space_write_multi_1((sc)->sc_st, (sc)->sc_sh, (reg), 	\ 	    (buf), (len))
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
value|do {					\ 	CSR_WRITE_4((sc), IPW_CSR_INDIRECT_ADDR, (addr));		\ 	CSR_WRITE_1((sc), IPW_CSR_INDIRECT_DATA, (val));		\ } while (
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
value|do {					\ 	CSR_WRITE_4((sc), IPW_CSR_INDIRECT_ADDR, (addr));		\ 	CSR_WRITE_2((sc), IPW_CSR_INDIRECT_DATA, (val));		\ } while (
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
value|do {					\ 	CSR_WRITE_4((sc), IPW_CSR_INDIRECT_ADDR, (addr));		\ 	CSR_WRITE_4((sc), IPW_CSR_INDIRECT_DATA, (val));		\ } while (
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
value|do {			\ 	CSR_WRITE_4((sc), IPW_CSR_INDIRECT_ADDR, (addr));		\ 	CSR_WRITE_MULTI_1((sc), IPW_CSR_INDIRECT_DATA, (buf), (len));	\ } while (
comment|/* CONSTCOND */
value|0)
end_define

begin_comment
comment|/*  * EEPROM access macro  */
end_comment

begin_define
define|#
directive|define
name|IPW_EEPROM_CTL
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
value|do {					\ 	MEM_WRITE_4((sc), IPW_MEM_EEPROM_CTL, (val));			\ 	DELAY(IPW_EEPROM_DELAY);					\ } while (0)
end_define

end_unit

