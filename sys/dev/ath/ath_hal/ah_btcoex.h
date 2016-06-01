begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 Qualcomm Atheros, Inc.  * All Rights Reserved.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ATH_HAL_BTCOEX_H__
end_ifndef

begin_define
define|#
directive|define
name|__ATH_HAL_BTCOEX_H__
end_define

begin_comment
comment|/*  * General BT coexistence definitions.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_BT_MODULE_CSR_BC4
init|=
literal|0
block|,
comment|/* CSR BlueCore v4 */
name|HAL_BT_MODULE_JANUS
init|=
literal|1
block|,
comment|/* Kite + Valkyrie combo */
name|HAL_BT_MODULE_HELIUS
init|=
literal|2
block|,
comment|/* Kiwi + Valkyrie combo */
name|HAL_MAX_BT_MODULES
block|}
name|HAL_BT_MODULE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|HAL_BT_MODULE
name|bt_module
decl_stmt|;
name|u_int8_t
name|bt_coex_config
decl_stmt|;
name|u_int8_t
name|bt_gpio_bt_active
decl_stmt|;
name|u_int8_t
name|bt_gpio_bt_priority
decl_stmt|;
name|u_int8_t
name|bt_gpio_wlan_active
decl_stmt|;
name|u_int8_t
name|bt_active_polarity
decl_stmt|;
name|HAL_BOOL
name|bt_single_ant
decl_stmt|;
name|u_int8_t
name|bt_dutyCycle
decl_stmt|;
name|u_int8_t
name|bt_isolation
decl_stmt|;
name|u_int8_t
name|bt_period
decl_stmt|;
block|}
name|HAL_BT_COEX_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_BT_COEX_MODE_LEGACY
init|=
literal|0
block|,
comment|/* legacy rx_clear mode */
name|HAL_BT_COEX_MODE_UNSLOTTED
init|=
literal|1
block|,
comment|/* untimed/unslotted mode */
name|HAL_BT_COEX_MODE_SLOTTED
init|=
literal|2
block|,
comment|/* slotted mode */
name|HAL_BT_COEX_MODE_DISALBED
init|=
literal|3
block|,
comment|/* coexistence disabled */
block|}
name|HAL_BT_COEX_MODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_BT_COEX_CFG_NONE
block|,
comment|/* No bt coex enabled */
name|HAL_BT_COEX_CFG_2WIRE_2CH
block|,
comment|/* 2-wire with 2 chains */
name|HAL_BT_COEX_CFG_2WIRE_CH1
block|,
comment|/* 2-wire with ch1 */
name|HAL_BT_COEX_CFG_2WIRE_CH0
block|,
comment|/* 2-wire with ch0 */
name|HAL_BT_COEX_CFG_3WIRE
block|,
comment|/* 3-wire */
name|HAL_BT_COEX_CFG_MCI
comment|/* MCI */
block|}
name|HAL_BT_COEX_CFG
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_BT_COEX_SET_ACK_PWR
init|=
literal|0
block|,
comment|/* Change ACK power setting */
name|HAL_BT_COEX_LOWER_TX_PWR
block|,
comment|/* Change transmit power */
name|HAL_BT_COEX_ANTENNA_DIVERSITY
block|,
comment|/* Enable RX diversity for Kite */
name|HAL_BT_COEX_MCI_MAX_TX_PWR
block|,
comment|/* Set max tx power for concurrent tx */
name|HAL_BT_COEX_MCI_FTP_STOMP_RX
block|,
comment|/* Use a different weight for stomp low */
block|}
name|HAL_BT_COEX_SET_PARAMETER
typedef|;
end_typedef

begin_comment
comment|/*  * MCI specific coexistence definitions.  */
end_comment

begin_define
define|#
directive|define
name|HAL_BT_COEX_FLAG_LOW_ACK_PWR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HAL_BT_COEX_FLAG_LOWER_TX_PWR
value|0x00000002
end_define

begin_comment
comment|/* Check Rx Diversity is allowed */
end_comment

begin_define
define|#
directive|define
name|HAL_BT_COEX_FLAG_ANT_DIV_ALLOW
value|0x00000004
end_define

begin_comment
comment|/* Check Diversity is on or off */
end_comment

begin_define
define|#
directive|define
name|HAL_BT_COEX_FLAG_ANT_DIV_ENABLE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HAL_BT_COEX_ANTDIV_CONTROL1_ENABLE
value|0x0b
end_define

begin_comment
comment|/* main: LNA1, alt: LNA2 */
end_comment

begin_define
define|#
directive|define
name|HAL_BT_COEX_ANTDIV_CONTROL2_ENABLE
value|0x09
end_define

begin_define
define|#
directive|define
name|HAL_BT_COEX_ANTDIV_CONTROL1_FIXED_A
value|0x04
end_define

begin_define
define|#
directive|define
name|HAL_BT_COEX_ANTDIV_CONTROL2_FIXED_A
value|0x09
end_define

begin_define
define|#
directive|define
name|HAL_BT_COEX_ANTDIV_CONTROL1_FIXED_B
value|0x02
end_define

begin_define
define|#
directive|define
name|HAL_BT_COEX_ANTDIV_CONTROL2_FIXED_B
value|0x06
end_define

begin_define
define|#
directive|define
name|HAL_BT_COEX_ISOLATION_FOR_NO_COEX
value|30
end_define

begin_define
define|#
directive|define
name|HAL_BT_COEX_ANT_DIV_SWITCH_COM
value|0x66666666
end_define

begin_define
define|#
directive|define
name|HAL_BT_COEX_HELIUS_CHAINMASK
value|0x02
end_define

begin_define
define|#
directive|define
name|HAL_BT_COEX_LOW_ACK_POWER
value|0x0
end_define

begin_define
define|#
directive|define
name|HAL_BT_COEX_HIGH_ACK_POWER
value|0x3f3f3f
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_BT_COEX_NO_STOMP
init|=
literal|0
block|,
name|HAL_BT_COEX_STOMP_ALL
block|,
name|HAL_BT_COEX_STOMP_LOW
block|,
name|HAL_BT_COEX_STOMP_NONE
block|,
name|HAL_BT_COEX_STOMP_ALL_FORCE
block|,
name|HAL_BT_COEX_STOMP_LOW_FORCE
block|, }
name|HAL_BT_COEX_STOMP_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* extend rx_clear after tx/rx to protect the burst (in usec). */
name|u_int8_t
name|bt_time_extend
decl_stmt|;
comment|/* 	 * extend rx_clear as long as txsm is 	 * transmitting or waiting for ack. 	 */
name|HAL_BOOL
name|bt_txstate_extend
decl_stmt|;
comment|/* 	 * extend rx_clear so that when tx_frame 	 * is asserted, rx_clear will drop. 	 */
name|HAL_BOOL
name|bt_txframe_extend
decl_stmt|;
comment|/* 	 * coexistence mode 	 */
name|HAL_BT_COEX_MODE
name|bt_mode
decl_stmt|;
comment|/* 	 * treat BT high priority traffic as 	 * a quiet collision 	 */
name|HAL_BOOL
name|bt_quiet_collision
decl_stmt|;
comment|/* 	 * invert rx_clear as WLAN_ACTIVE 	 */
name|HAL_BOOL
name|bt_rxclear_polarity
decl_stmt|;
comment|/* 	 * slotted mode only. indicate the time in usec 	 * from the rising edge of BT_ACTIVE to the time 	 * BT_PRIORITY can be sampled to indicate priority. 	 */
name|u_int8_t
name|bt_priority_time
decl_stmt|;
comment|/* 	 * slotted mode only. indicate the time in usec 	 * from the rising edge of BT_ACTIVE to the time 	 * BT_PRIORITY can be sampled to indicate tx/rx and 	 * BT_FREQ is sampled. 	 */
name|u_int8_t
name|bt_first_slot_time
decl_stmt|;
comment|/* 	 * slotted mode only. rx_clear and bt_ant decision 	 * will be held the entire time that BT_ACTIVE is asserted, 	 * otherwise the decision is made before every slot boundary. 	 */
name|HAL_BOOL
name|bt_hold_rxclear
decl_stmt|;
block|}
name|HAL_BT_COEX_CONFIG
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAL_BT_COEX_FLAG_LOW_ACK_PWR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HAL_BT_COEX_FLAG_LOWER_TX_PWR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HAL_BT_COEX_FLAG_ANT_DIV_ALLOW
value|0x00000004
end_define

begin_comment
comment|/* Check Rx Diversity is allowed */
end_comment

begin_define
define|#
directive|define
name|HAL_BT_COEX_FLAG_ANT_DIV_ENABLE
value|0x00000008
end_define

begin_comment
comment|/* Check Diversity is on or off */
end_comment

begin_define
define|#
directive|define
name|HAL_BT_COEX_FLAG_MCI_MAX_TX_PWR
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HAL_BT_COEX_FLAG_MCI_FTP_STOMP_RX
value|0x00000020
end_define

begin_define
define|#
directive|define
name|HAL_MCI_FLAG_DISABLE_TIMESTAMP
value|0x00000001
end_define

begin_comment
comment|/* Disable time stamp */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|mci_message_header
block|{
name|MCI_LNA_CTRL
init|=
literal|0x10
block|,
comment|/* len = 0 */
name|MCI_CONT_NACK
init|=
literal|0x20
block|,
comment|/* len = 0 */
name|MCI_CONT_INFO
init|=
literal|0x30
block|,
comment|/* len = 4 */
name|MCI_CONT_RST
init|=
literal|0x40
block|,
comment|/* len = 0 */
name|MCI_SCHD_INFO
init|=
literal|0x50
block|,
comment|/* len = 16 */
name|MCI_CPU_INT
init|=
literal|0x60
block|,
comment|/* len = 4 */
name|MCI_SYS_WAKING
init|=
literal|0x70
block|,
comment|/* len = 0 */
name|MCI_GPM
init|=
literal|0x80
block|,
comment|/* len = 16 */
name|MCI_LNA_INFO
init|=
literal|0x90
block|,
comment|/* len = 1 */
name|MCI_LNA_STATE
init|=
literal|0x94
block|,
name|MCI_LNA_TAKE
init|=
literal|0x98
block|,
name|MCI_LNA_TRANS
init|=
literal|0x9c
block|,
name|MCI_SYS_SLEEPING
init|=
literal|0xa0
block|,
comment|/* len = 0 */
name|MCI_REQ_WAKE
init|=
literal|0xc0
block|,
comment|/* len = 0 */
name|MCI_DEBUG_16
init|=
literal|0xfe
block|,
comment|/* len = 2 */
name|MCI_REMOTE_RESET
init|=
literal|0xff
comment|/* len = 16 */
block|}
name|MCI_MESSAGE_HEADER
typedef|;
end_typedef

begin_comment
comment|/* Default remote BT device MCI COEX version */
end_comment

begin_define
define|#
directive|define
name|MCI_GPM_COEX_MAJOR_VERSION_DEFAULT
value|3
end_define

begin_define
define|#
directive|define
name|MCI_GPM_COEX_MINOR_VERSION_DEFAULT
value|0
end_define

begin_comment
comment|/* Local WLAN MCI COEX version */
end_comment

begin_define
define|#
directive|define
name|MCI_GPM_COEX_MAJOR_VERSION_WLAN
value|3
end_define

begin_define
define|#
directive|define
name|MCI_GPM_COEX_MINOR_VERSION_WLAN
value|0
end_define

begin_typedef
typedef|typedef
enum|enum
name|mci_gpm_subtype
block|{
name|MCI_GPM_BT_CAL_REQ
init|=
literal|0
block|,
name|MCI_GPM_BT_CAL_GRANT
init|=
literal|1
block|,
name|MCI_GPM_BT_CAL_DONE
init|=
literal|2
block|,
name|MCI_GPM_WLAN_CAL_REQ
init|=
literal|3
block|,
name|MCI_GPM_WLAN_CAL_GRANT
init|=
literal|4
block|,
name|MCI_GPM_WLAN_CAL_DONE
init|=
literal|5
block|,
name|MCI_GPM_COEX_AGENT
init|=
literal|0x0C
block|,
name|MCI_GPM_RSVD_PATTERN
init|=
literal|0xFE
block|,
name|MCI_GPM_RSVD_PATTERN32
init|=
literal|0xFEFEFEFE
block|,
name|MCI_GPM_BT_DEBUG
init|=
literal|0xFF
block|}
name|MCI_GPM_SUBTYPE_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|mci_gpm_coex_opcode
block|{
name|MCI_GPM_COEX_VERSION_QUERY
init|=
literal|0
block|,
name|MCI_GPM_COEX_VERSION_RESPONSE
init|=
literal|1
block|,
name|MCI_GPM_COEX_STATUS_QUERY
init|=
literal|2
block|,
name|MCI_GPM_COEX_HALT_BT_GPM
init|=
literal|3
block|,
name|MCI_GPM_COEX_WLAN_CHANNELS
init|=
literal|4
block|,
name|MCI_GPM_COEX_BT_PROFILE_INFO
init|=
literal|5
block|,
name|MCI_GPM_COEX_BT_STATUS_UPDATE
init|=
literal|6
block|,
name|MCI_GPM_COEX_BT_UPDATE_FLAGS
init|=
literal|7
block|}
name|MCI_GPM_COEX_OPCODE_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|mci_gpm_coex_query_type
block|{
comment|/* WLAN information */
name|MCI_GPM_COEX_QUERY_WLAN_ALL_INFO
init|=
literal|0x01
block|,
comment|/* BT information */
name|MCI_GPM_COEX_QUERY_BT_ALL_INFO
init|=
literal|0x01
block|,
name|MCI_GPM_COEX_QUERY_BT_TOPOLOGY
init|=
literal|0x02
block|,
name|MCI_GPM_COEX_QUERY_BT_DEBUG
init|=
literal|0x04
block|}
name|MCI_GPM_COEX_QUERY_TYPE_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|mci_gpm_coex_halt_bt_gpm
block|{
name|MCI_GPM_COEX_BT_GPM_UNHALT
init|=
literal|0
block|,
name|MCI_GPM_COEX_BT_GPM_HALT
init|=
literal|1
block|}
name|MCI_GPM_COEX_HALT_BT_GPM_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|mci_gpm_coex_profile_type
block|{
name|MCI_GPM_COEX_PROFILE_UNKNOWN
init|=
literal|0
block|,
name|MCI_GPM_COEX_PROFILE_RFCOMM
init|=
literal|1
block|,
name|MCI_GPM_COEX_PROFILE_A2DP
init|=
literal|2
block|,
name|MCI_GPM_COEX_PROFILE_HID
init|=
literal|3
block|,
name|MCI_GPM_COEX_PROFILE_BNEP
init|=
literal|4
block|,
name|MCI_GPM_COEX_PROFILE_VOICE
init|=
literal|5
block|,
name|MCI_GPM_COEX_PROFILE_MAX
block|}
name|MCI_GPM_COEX_PROFILE_TYPE_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|mci_gpm_coex_profile_state
block|{
name|MCI_GPM_COEX_PROFILE_STATE_END
init|=
literal|0
block|,
name|MCI_GPM_COEX_PROFILE_STATE_START
init|=
literal|1
block|}
name|MCI_GPM_COEX_PROFILE_STATE_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|mci_gpm_coex_profile_role
block|{
name|MCI_GPM_COEX_PROFILE_SLAVE
init|=
literal|0
block|,
name|MCI_GPM_COEX_PROFILE_MASTER
init|=
literal|1
block|}
name|MCI_GPM_COEX_PROFILE_ROLE_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|mci_gpm_coex_bt_status_type
block|{
name|MCI_GPM_COEX_BT_NONLINK_STATUS
init|=
literal|0
block|,
name|MCI_GPM_COEX_BT_LINK_STATUS
init|=
literal|1
block|}
name|MCI_GPM_COEX_BT_STATUS_TYPE_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|mci_gpm_coex_bt_status_state
block|{
name|MCI_GPM_COEX_BT_NORMAL_STATUS
init|=
literal|0
block|,
name|MCI_GPM_COEX_BT_CRITICAL_STATUS
init|=
literal|1
block|}
name|MCI_GPM_COEX_BT_STATUS_STATE_T
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MCI_GPM_INVALID_PROFILE_HANDLE
value|0xff
end_define

begin_typedef
typedef|typedef
enum|enum
name|mci_gpm_coex_bt_updata_flags_op
block|{
name|MCI_GPM_COEX_BT_FLAGS_READ
init|=
literal|0x00
block|,
name|MCI_GPM_COEX_BT_FLAGS_SET
init|=
literal|0x01
block|,
name|MCI_GPM_COEX_BT_FLAGS_CLEAR
init|=
literal|0x02
block|}
name|MCI_GPM_COEX_BT_FLAGS_OP_T
typedef|;
end_typedef

begin_comment
comment|/* MCI GPM/Coex opcode/type definitions */
end_comment

begin_enum
enum|enum
block|{
name|MCI_GPM_COEX_W_GPM_PAYLOAD
init|=
literal|1
block|,
name|MCI_GPM_COEX_B_GPM_TYPE
init|=
literal|4
block|,
name|MCI_GPM_COEX_B_GPM_OPCODE
init|=
literal|5
block|,
comment|/* MCI_GPM_WLAN_CAL_REQ, MCI_GPM_WLAN_CAL_DONE */
name|MCI_GPM_WLAN_CAL_W_SEQUENCE
init|=
literal|2
block|,
comment|/* MCI_GPM_COEX_VERSION_QUERY */
comment|/* MCI_GPM_COEX_VERSION_RESPONSE */
name|MCI_GPM_COEX_B_MAJOR_VERSION
init|=
literal|6
block|,
name|MCI_GPM_COEX_B_MINOR_VERSION
init|=
literal|7
block|,
comment|/* MCI_GPM_COEX_STATUS_QUERY */
name|MCI_GPM_COEX_B_BT_BITMAP
init|=
literal|6
block|,
name|MCI_GPM_COEX_B_WLAN_BITMAP
init|=
literal|7
block|,
comment|/* MCI_GPM_COEX_HALT_BT_GPM */
name|MCI_GPM_COEX_B_HALT_STATE
init|=
literal|6
block|,
comment|/* MCI_GPM_COEX_WLAN_CHANNELS */
name|MCI_GPM_COEX_B_CHANNEL_MAP
init|=
literal|6
block|,
comment|/* MCI_GPM_COEX_BT_PROFILE_INFO */
name|MCI_GPM_COEX_B_PROFILE_TYPE
init|=
literal|6
block|,
name|MCI_GPM_COEX_B_PROFILE_LINKID
init|=
literal|7
block|,
name|MCI_GPM_COEX_B_PROFILE_STATE
init|=
literal|8
block|,
name|MCI_GPM_COEX_B_PROFILE_ROLE
init|=
literal|9
block|,
name|MCI_GPM_COEX_B_PROFILE_RATE
init|=
literal|10
block|,
name|MCI_GPM_COEX_B_PROFILE_VOTYPE
init|=
literal|11
block|,
name|MCI_GPM_COEX_H_PROFILE_T
init|=
literal|12
block|,
name|MCI_GPM_COEX_B_PROFILE_W
init|=
literal|14
block|,
name|MCI_GPM_COEX_B_PROFILE_A
init|=
literal|15
block|,
comment|/* MCI_GPM_COEX_BT_STATUS_UPDATE */
name|MCI_GPM_COEX_B_STATUS_TYPE
init|=
literal|6
block|,
name|MCI_GPM_COEX_B_STATUS_LINKID
init|=
literal|7
block|,
name|MCI_GPM_COEX_B_STATUS_STATE
init|=
literal|8
block|,
comment|/* MCI_GPM_COEX_BT_UPDATE_FLAGS */
name|MCI_GPM_COEX_B_BT_FLAGS_OP
init|=
literal|10
block|,
name|MCI_GPM_COEX_W_BT_FLAGS
init|=
literal|6
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|MCI_GPM_RECYCLE
parameter_list|(
name|_p_gpm
parameter_list|)
define|\
value|{                           \         *(((u_int32_t *)(_p_gpm)) + MCI_GPM_COEX_W_GPM_PAYLOAD) = MCI_GPM_RSVD_PATTERN32; \     }
end_define

begin_define
define|#
directive|define
name|MCI_GPM_TYPE
parameter_list|(
name|_p_gpm
parameter_list|)
define|\
value|(*(((u_int8_t *)(_p_gpm)) + MCI_GPM_COEX_B_GPM_TYPE)& 0xff)
end_define

begin_define
define|#
directive|define
name|MCI_GPM_OPCODE
parameter_list|(
name|_p_gpm
parameter_list|)
define|\
value|(*(((u_int8_t *)(_p_gpm)) + MCI_GPM_COEX_B_GPM_OPCODE)& 0xff)
end_define

begin_define
define|#
directive|define
name|MCI_GPM_SET_CAL_TYPE
parameter_list|(
name|_p_gpm
parameter_list|,
name|_cal_type
parameter_list|)
define|\
value|{                                                       \         *(((u_int8_t *)(_p_gpm)) + MCI_GPM_COEX_B_GPM_TYPE) = (_cal_type)& 0xff; \     }
end_define

begin_define
define|#
directive|define
name|MCI_GPM_SET_TYPE_OPCODE
parameter_list|(
name|_p_gpm
parameter_list|,
name|_type
parameter_list|,
name|_opcode
parameter_list|)
define|\
value|{                                                       \         *(((u_int8_t *)(_p_gpm)) + MCI_GPM_COEX_B_GPM_TYPE) = (_type)& 0xff;     \         *(((u_int8_t *)(_p_gpm)) + MCI_GPM_COEX_B_GPM_OPCODE) = (_opcode)& 0xff;   \     }
end_define

begin_define
define|#
directive|define
name|MCI_GPM_IS_CAL_TYPE
parameter_list|(
name|_type
parameter_list|)
value|((_type)<= MCI_GPM_WLAN_CAL_DONE)
end_define

begin_define
define|#
directive|define
name|MCI_NUM_BT_CHANNELS
value|79
end_define

begin_define
define|#
directive|define
name|MCI_GPM_SET_CHANNEL_BIT
parameter_list|(
name|_p_gpm
parameter_list|,
name|_bt_chan
parameter_list|)
define|\
value|{                                                               \         if (_bt_chan< MCI_NUM_BT_CHANNELS) {                       \             *(((u_int8_t *)(_p_gpm)) + MCI_GPM_COEX_B_CHANNEL_MAP + \                 (_bt_chan / 8)) |= 1<< (_bt_chan& 7);             \         }                                                           \     }
end_define

begin_define
define|#
directive|define
name|MCI_GPM_CLR_CHANNEL_BIT
parameter_list|(
name|_p_gpm
parameter_list|,
name|_bt_chan
parameter_list|)
define|\
value|{                                                               \         if (_bt_chan< MCI_NUM_BT_CHANNELS) {                       \             *(((u_int8_t *)(_p_gpm)) + MCI_GPM_COEX_B_CHANNEL_MAP + \                 (_bt_chan / 8))&= ~(1<< (_bt_chan& 7));          \         }                                                           \     }
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_SW_MSG_DONE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_CPU_INT_MSG
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_CHKSUM_FAIL
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_INVALID_HDR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_HW_MSG_FAIL
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_SW_MSG_FAIL
value|0x00000020
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_TX_HW_MSG_FAIL
value|0x00000080
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_TX_SW_MSG_FAIL
value|0x00000100
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_MSG
value|0x00000200
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_REMOTE_SLEEP_UPDATE
value|0x00000400
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_CONT_INFO_TIMEOUT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_MSG_FAIL_MASK
value|( HAL_MCI_INTERRUPT_RX_HW_MSG_FAIL | \                                           HAL_MCI_INTERRUPT_RX_SW_MSG_FAIL | \                                           HAL_MCI_INTERRUPT_TX_HW_MSG_FAIL | \                                           HAL_MCI_INTERRUPT_TX_SW_MSG_FAIL )
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_MSG_REMOTE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_MSG_LNA_CONTROL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_MSG_CONT_NACK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_MSG_CONT_INFO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_MSG_CONT_RST
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_MSG_SCHD_INFO
value|0x00000020
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_MSG_CPU_INT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_MSG_GPM
value|0x00000100
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_MSG_LNA_INFO
value|0x00000200
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_MSG_SYS_SLEEPING
value|0x00000400
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_MSG_SYS_WAKING
value|0x00000800
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_MSG_REQ_WAKE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_MSG_MONITOR
value|(HAL_MCI_INTERRUPT_RX_MSG_LNA_CONTROL | \                                                   HAL_MCI_INTERRUPT_RX_MSG_LNA_INFO    | \                                                   HAL_MCI_INTERRUPT_RX_MSG_CONT_NACK   | \                                                   HAL_MCI_INTERRUPT_RX_MSG_CONT_INFO   | \                                                   HAL_MCI_INTERRUPT_RX_MSG_CONT_RST)
end_define

begin_typedef
typedef|typedef
enum|enum
name|mci_bt_state
block|{
name|MCI_BT_SLEEP
block|,
name|MCI_BT_AWAKE
block|,
name|MCI_BT_CAL_START
block|,
name|MCI_BT_CAL
block|}
name|MCI_BT_STATE_T
typedef|;
end_typedef

begin_comment
comment|/* Type of state query */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|mci_state_type
block|{
name|HAL_MCI_STATE_ENABLE
block|,
name|HAL_MCI_STATE_INIT_GPM_OFFSET
block|,
name|HAL_MCI_STATE_NEXT_GPM_OFFSET
block|,
name|HAL_MCI_STATE_LAST_GPM_OFFSET
block|,
name|HAL_MCI_STATE_BT
block|,
name|HAL_MCI_STATE_SET_BT_SLEEP
block|,
name|HAL_MCI_STATE_SET_BT_AWAKE
block|,
name|HAL_MCI_STATE_SET_BT_CAL_START
block|,
name|HAL_MCI_STATE_SET_BT_CAL
block|,
name|HAL_MCI_STATE_LAST_SCHD_MSG_OFFSET
block|,
name|HAL_MCI_STATE_REMOTE_SLEEP
block|,
name|HAL_MCI_STATE_CONT_RSSI_POWER
block|,
name|HAL_MCI_STATE_CONT_PRIORITY
block|,
name|HAL_MCI_STATE_CONT_TXRX
block|,
name|HAL_MCI_STATE_RESET_REQ_WAKE
block|,
name|HAL_MCI_STATE_SEND_WLAN_COEX_VERSION
block|,
name|HAL_MCI_STATE_SET_BT_COEX_VERSION
block|,
name|HAL_MCI_STATE_SEND_WLAN_CHANNELS
block|,
name|HAL_MCI_STATE_SEND_VERSION_QUERY
block|,
name|HAL_MCI_STATE_SEND_STATUS_QUERY
block|,
name|HAL_MCI_STATE_NEED_FLUSH_BT_INFO
block|,
name|HAL_MCI_STATE_SET_CONCUR_TX_PRI
block|,
name|HAL_MCI_STATE_RECOVER_RX
block|,
name|HAL_MCI_STATE_NEED_FTP_STOMP
block|,
name|HAL_MCI_STATE_NEED_TUNING
block|,
name|HAL_MCI_STATE_SHARED_CHAIN_CONCUR_TX
block|,
name|HAL_MCI_STATE_DEBUG
block|,
name|HAL_MCI_STATE_MAX
block|}
name|HAL_MCI_STATE_TYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAL_MCI_STATE_DEBUG_REQ_BT_DEBUG
value|1
end_define

begin_define
define|#
directive|define
name|HAL_MCI_BT_MCI_FLAGS_UPDATE_CORR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HAL_MCI_BT_MCI_FLAGS_UPDATE_HDR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HAL_MCI_BT_MCI_FLAGS_UPDATE_PLD
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HAL_MCI_BT_MCI_FLAGS_LNA_CTRL
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HAL_MCI_BT_MCI_FLAGS_DEBUG
value|0x00000020
end_define

begin_define
define|#
directive|define
name|HAL_MCI_BT_MCI_FLAGS_SCHED_MSG
value|0x00000040
end_define

begin_define
define|#
directive|define
name|HAL_MCI_BT_MCI_FLAGS_CONT_MSG
value|0x00000080
end_define

begin_define
define|#
directive|define
name|HAL_MCI_BT_MCI_FLAGS_COEX_GPM
value|0x00000100
end_define

begin_define
define|#
directive|define
name|HAL_MCI_BT_MCI_FLAGS_CPU_INT_MSG
value|0x00000200
end_define

begin_define
define|#
directive|define
name|HAL_MCI_BT_MCI_FLAGS_MCI_MODE
value|0x00000400
end_define

begin_define
define|#
directive|define
name|HAL_MCI_BT_MCI_FLAGS_EGRET_MODE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|HAL_MCI_BT_MCI_FLAGS_JUPITER_MODE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|HAL_MCI_BT_MCI_FLAGS_OTHER
value|0x00010000
end_define

begin_define
define|#
directive|define
name|HAL_MCI_DEFAULT_BT_MCI_FLAGS
value|0x00011dde
end_define

begin_comment
comment|/*     HAL_MCI_BT_MCI_FLAGS_UPDATE_CORR  = 1     HAL_MCI_BT_MCI_FLAGS_UPDATE_HDR   = 1     HAL_MCI_BT_MCI_FLAGS_UPDATE_PLD   = 1     HAL_MCI_BT_MCI_FLAGS_LNA_CTRL     = 1     HAL_MCI_BT_MCI_FLAGS_DEBUG        = 0     HAL_MCI_BT_MCI_FLAGS_SCHED_MSG    = 1     HAL_MCI_BT_MCI_FLAGS_CONT_MSG     = 1     HAL_MCI_BT_MCI_FLAGS_COEX_GPM     = 1     HAL_MCI_BT_MCI_FLAGS_CPU_INT_MSG  = 0     HAL_MCI_BT_MCI_FLAGS_MCI_MODE     = 1     HAL_MCI_BT_MCI_FLAGS_EGRET_MODE   = 1     HAL_MCI_BT_MCI_FLAGS_JUPITER_MODE = 1     HAL_MCI_BT_MCI_FLAGS_OTHER        = 1 */
end_comment

begin_define
define|#
directive|define
name|HAL_MCI_TOGGLE_BT_MCI_FLAGS
define|\
value|(   HAL_MCI_BT_MCI_FLAGS_UPDATE_CORR    |   \         HAL_MCI_BT_MCI_FLAGS_UPDATE_HDR     |   \         HAL_MCI_BT_MCI_FLAGS_UPDATE_PLD     |   \         HAL_MCI_BT_MCI_FLAGS_MCI_MODE   )
end_define

begin_define
define|#
directive|define
name|HAL_MCI_2G_FLAGS_CLEAR_MASK
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HAL_MCI_2G_FLAGS_SET_MASK
value|HAL_MCI_TOGGLE_BT_MCI_FLAGS
end_define

begin_define
define|#
directive|define
name|HAL_MCI_2G_FLAGS
value|HAL_MCI_DEFAULT_BT_MCI_FLAGS
end_define

begin_define
define|#
directive|define
name|HAL_MCI_5G_FLAGS_CLEAR_MASK
value|HAL_MCI_TOGGLE_BT_MCI_FLAGS
end_define

begin_define
define|#
directive|define
name|HAL_MCI_5G_FLAGS_SET_MASK
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HAL_MCI_5G_FLAGS
value|(HAL_MCI_DEFAULT_BT_MCI_FLAGS& \                                             ~HAL_MCI_TOGGLE_BT_MCI_FLAGS)
end_define

begin_define
define|#
directive|define
name|HAL_MCI_GPM_NOMORE
value|0
end_define

begin_define
define|#
directive|define
name|HAL_MCI_GPM_MORE
value|1
end_define

begin_define
define|#
directive|define
name|HAL_MCI_GPM_INVALID
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|ATH_AIC_MAX_BT_CHANNEL
value|79
end_define

begin_comment
comment|/*  * Default value for Jupiter   is 0x00002201  * Default value for Aphrodite is 0x00002282  */
end_comment

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_CONCUR_TX
value|0x00000003
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_MCI_OBS_MCI
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_MCI_OBS_TXRX
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_MCI_OBS_BT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_DISABLE_MCI_CAL
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_DISABLE_OSLA
value|0x00000040
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_DISABLE_FTP_STOMP
value|0x00000080
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_AGGR_THRESH
value|0x00000700
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_AGGR_THRESH_S
value|8
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_DISABLE_AGGR_THRESH
value|0x00000800
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_CLK_DIV
value|0x00003000
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_CLK_DIV_S
value|12
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_DISABLE_TUNING
value|0x00004000
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_DISABLE_AIC
value|0x00008000
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_AIC_CAL_NUM_CHAN
value|0x007f0000
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_AIC_CAL_NUM_CHAN_S
value|16
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_NO_QUIET_ACK
value|0x00800000
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_NO_QUIET_ACK_S
value|23
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_ANT_ARCH
value|0x07000000
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_ANT_ARCH_S
value|24
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_FORCE_QUIET_ACK
value|0x08000000
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_FORCE_QUIET_ACK_S
value|27
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_FORCE_2CHAIN_ACK
value|0x10000000
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_MCI_STAT_DBG
value|0x20000000
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_MCI_WEIGHT_DBG
value|0x40000000
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_DISABLE_MCI
value|0x80000000
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_MCI_OBS_MASK
value|( ATH_MCI_CONFIG_MCI_OBS_MCI | \                                           ATH_MCI_CONFIG_MCI_OBS_TXRX | \                                           ATH_MCI_CONFIG_MCI_OBS_BT )
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_MCI_OBS_GPIO
value|0x0000002F
end_define

begin_define
define|#
directive|define
name|ATH_MCI_ANT_ARCH_1_ANT_PA_LNA_NON_SHARED
value|0x00
end_define

begin_define
define|#
directive|define
name|ATH_MCI_ANT_ARCH_1_ANT_PA_LNA_SHARED
value|0x01
end_define

begin_define
define|#
directive|define
name|ATH_MCI_ANT_ARCH_2_ANT_PA_LNA_NON_SHARED
value|0x02
end_define

begin_define
define|#
directive|define
name|ATH_MCI_ANT_ARCH_2_ANT_PA_LNA_SHARED
value|0x03
end_define

begin_define
define|#
directive|define
name|ATH_MCI_ANT_ARCH_3_ANT
value|0x04
end_define

begin_define
define|#
directive|define
name|MCI_ANT_ARCH_PA_LNA_SHARED
parameter_list|(
name|c
parameter_list|)
define|\
value|((MS(c, ATH_MCI_CONFIG_ANT_ARCH) == ATH_MCI_ANT_ARCH_1_ANT_PA_LNA_SHARED) || \ 	    (MS(c, ATH_MCI_CONFIG_ANT_ARCH) == ATH_MCI_ANT_ARCH_2_ANT_PA_LNA_SHARED))
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONCUR_TX_SHARED_CHN
value|0x01
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONCUR_TX_UNSHARED_CHN
value|0x02
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONCUR_TX_DEBUG
value|0x03
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

