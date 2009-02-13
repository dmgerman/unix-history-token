begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hostapd / Kernel driver communication with Linux Host AP driver  * Copyright (c) 2002-2006, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HOSTAP_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|HOSTAP_COMMON_H
end_define

begin_comment
comment|/* netdevice private ioctls (used, e.g., with iwpriv from user space) */
end_comment

begin_comment
comment|/* New wireless extensions API - SET/GET convention (even ioctl numbers are  * root only)  */
end_comment

begin_define
define|#
directive|define
name|PRISM2_IOCTL_PRISM2_PARAM
value|(SIOCIWFIRSTPRIV + 0)
end_define

begin_define
define|#
directive|define
name|PRISM2_IOCTL_GET_PRISM2_PARAM
value|(SIOCIWFIRSTPRIV + 1)
end_define

begin_define
define|#
directive|define
name|PRISM2_IOCTL_WRITEMIF
value|(SIOCIWFIRSTPRIV + 2)
end_define

begin_define
define|#
directive|define
name|PRISM2_IOCTL_READMIF
value|(SIOCIWFIRSTPRIV + 3)
end_define

begin_define
define|#
directive|define
name|PRISM2_IOCTL_MONITOR
value|(SIOCIWFIRSTPRIV + 4)
end_define

begin_define
define|#
directive|define
name|PRISM2_IOCTL_RESET
value|(SIOCIWFIRSTPRIV + 6)
end_define

begin_define
define|#
directive|define
name|PRISM2_IOCTL_INQUIRE
value|(SIOCIWFIRSTPRIV + 8)
end_define

begin_define
define|#
directive|define
name|PRISM2_IOCTL_WDS_ADD
value|(SIOCIWFIRSTPRIV + 10)
end_define

begin_define
define|#
directive|define
name|PRISM2_IOCTL_WDS_DEL
value|(SIOCIWFIRSTPRIV + 12)
end_define

begin_define
define|#
directive|define
name|PRISM2_IOCTL_SET_RID_WORD
value|(SIOCIWFIRSTPRIV + 14)
end_define

begin_define
define|#
directive|define
name|PRISM2_IOCTL_MACCMD
value|(SIOCIWFIRSTPRIV + 16)
end_define

begin_define
define|#
directive|define
name|PRISM2_IOCTL_ADDMAC
value|(SIOCIWFIRSTPRIV + 18)
end_define

begin_define
define|#
directive|define
name|PRISM2_IOCTL_DELMAC
value|(SIOCIWFIRSTPRIV + 20)
end_define

begin_define
define|#
directive|define
name|PRISM2_IOCTL_KICKMAC
value|(SIOCIWFIRSTPRIV + 22)
end_define

begin_comment
comment|/* following are not in SIOCGIWPRIV list; check permission in the driver code  */
end_comment

begin_define
define|#
directive|define
name|PRISM2_IOCTL_DOWNLOAD
value|(SIOCDEVPRIVATE + 13)
end_define

begin_define
define|#
directive|define
name|PRISM2_IOCTL_HOSTAPD
value|(SIOCDEVPRIVATE + 14)
end_define

begin_comment
comment|/* PRISM2_IOCTL_PRISM2_PARAM ioctl() subtypes: */
end_comment

begin_enum
enum|enum
block|{
comment|/* PRISM2_PARAM_PTYPE = 1, */
comment|/* REMOVED 2003-10-22 */
name|PRISM2_PARAM_TXRATECTRL
init|=
literal|2
block|,
name|PRISM2_PARAM_BEACON_INT
init|=
literal|3
block|,
name|PRISM2_PARAM_PSEUDO_IBSS
init|=
literal|4
block|,
name|PRISM2_PARAM_ALC
init|=
literal|5
block|,
comment|/* PRISM2_PARAM_TXPOWER = 6, */
comment|/* REMOVED 2003-10-22 */
name|PRISM2_PARAM_DUMP
init|=
literal|7
block|,
name|PRISM2_PARAM_OTHER_AP_POLICY
init|=
literal|8
block|,
name|PRISM2_PARAM_AP_MAX_INACTIVITY
init|=
literal|9
block|,
name|PRISM2_PARAM_AP_BRIDGE_PACKETS
init|=
literal|10
block|,
name|PRISM2_PARAM_DTIM_PERIOD
init|=
literal|11
block|,
name|PRISM2_PARAM_AP_NULLFUNC_ACK
init|=
literal|12
block|,
name|PRISM2_PARAM_MAX_WDS
init|=
literal|13
block|,
name|PRISM2_PARAM_AP_AUTOM_AP_WDS
init|=
literal|14
block|,
name|PRISM2_PARAM_AP_AUTH_ALGS
init|=
literal|15
block|,
name|PRISM2_PARAM_MONITOR_ALLOW_FCSERR
init|=
literal|16
block|,
name|PRISM2_PARAM_HOST_ENCRYPT
init|=
literal|17
block|,
name|PRISM2_PARAM_HOST_DECRYPT
init|=
literal|18
block|,
name|PRISM2_PARAM_BUS_MASTER_THRESHOLD_RX
init|=
literal|19
block|,
name|PRISM2_PARAM_BUS_MASTER_THRESHOLD_TX
init|=
literal|20
block|,
name|PRISM2_PARAM_HOST_ROAMING
init|=
literal|21
block|,
name|PRISM2_PARAM_BCRX_STA_KEY
init|=
literal|22
block|,
name|PRISM2_PARAM_IEEE_802_1X
init|=
literal|23
block|,
name|PRISM2_PARAM_ANTSEL_TX
init|=
literal|24
block|,
name|PRISM2_PARAM_ANTSEL_RX
init|=
literal|25
block|,
name|PRISM2_PARAM_MONITOR_TYPE
init|=
literal|26
block|,
name|PRISM2_PARAM_WDS_TYPE
init|=
literal|27
block|,
name|PRISM2_PARAM_HOSTSCAN
init|=
literal|28
block|,
name|PRISM2_PARAM_AP_SCAN
init|=
literal|29
block|,
name|PRISM2_PARAM_ENH_SEC
init|=
literal|30
block|,
name|PRISM2_PARAM_IO_DEBUG
init|=
literal|31
block|,
name|PRISM2_PARAM_BASIC_RATES
init|=
literal|32
block|,
name|PRISM2_PARAM_OPER_RATES
init|=
literal|33
block|,
name|PRISM2_PARAM_HOSTAPD
init|=
literal|34
block|,
name|PRISM2_PARAM_HOSTAPD_STA
init|=
literal|35
block|,
name|PRISM2_PARAM_WPA
init|=
literal|36
block|,
name|PRISM2_PARAM_PRIVACY_INVOKED
init|=
literal|37
block|,
name|PRISM2_PARAM_TKIP_COUNTERMEASURES
init|=
literal|38
block|,
name|PRISM2_PARAM_DROP_UNENCRYPTED
init|=
literal|39
block|,
name|PRISM2_PARAM_SCAN_CHANNEL_MASK
init|=
literal|40
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
name|HOSTAP_ANTSEL_DO_NOT_TOUCH
init|=
literal|0
block|,
name|HOSTAP_ANTSEL_DIVERSITY
init|=
literal|1
block|,
name|HOSTAP_ANTSEL_LOW
init|=
literal|2
block|,
name|HOSTAP_ANTSEL_HIGH
init|=
literal|3
block|}
enum|;
end_enum

begin_comment
comment|/* PRISM2_IOCTL_MACCMD ioctl() subcommands: */
end_comment

begin_enum
enum|enum
block|{
name|AP_MAC_CMD_POLICY_OPEN
init|=
literal|0
block|,
name|AP_MAC_CMD_POLICY_ALLOW
init|=
literal|1
block|,
name|AP_MAC_CMD_POLICY_DENY
init|=
literal|2
block|,
name|AP_MAC_CMD_FLUSH
init|=
literal|3
block|,
name|AP_MAC_CMD_KICKALL
init|=
literal|4
block|}
enum|;
end_enum

begin_comment
comment|/* PRISM2_IOCTL_DOWNLOAD ioctl() dl_cmd: */
end_comment

begin_enum
enum|enum
block|{
name|PRISM2_DOWNLOAD_VOLATILE
init|=
literal|1
comment|/* RAM */
block|,
comment|/* Note! Old versions of prism2_srec have a fatal error in CRC-16 	 * calculation, which will corrupt all non-volatile downloads. 	 * PRISM2_DOWNLOAD_NON_VOLATILE used to be 2, but it is now 3 to 	 * prevent use of old versions of prism2_srec for non-volatile 	 * download. */
name|PRISM2_DOWNLOAD_NON_VOLATILE
init|=
literal|3
comment|/* FLASH */
block|,
name|PRISM2_DOWNLOAD_VOLATILE_GENESIS
init|=
literal|4
comment|/* RAM in Genesis mode */
block|,
comment|/* Persistent versions of volatile download commands (keep firmware 	 * data in memory and automatically re-download after hw_reset */
name|PRISM2_DOWNLOAD_VOLATILE_PERSISTENT
init|=
literal|5
block|,
name|PRISM2_DOWNLOAD_VOLATILE_GENESIS_PERSISTENT
init|=
literal|6
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|prism2_download_param
block|{
name|u32
name|dl_cmd
decl_stmt|;
name|u32
name|start_addr
decl_stmt|;
name|u32
name|num_areas
decl_stmt|;
struct|struct
name|prism2_download_area
block|{
name|u32
name|addr
decl_stmt|;
comment|/* wlan card address */
name|u32
name|len
decl_stmt|;
name|caddr_t
name|ptr
decl_stmt|;
comment|/* pointer to data in user space */
block|}
name|data
index|[
literal|0
index|]
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PRISM2_MAX_DOWNLOAD_AREA_LEN
value|131072
end_define

begin_define
define|#
directive|define
name|PRISM2_MAX_DOWNLOAD_LEN
value|262144
end_define

begin_comment
comment|/* PRISM2_IOCTL_HOSTAPD ioctl() cmd: */
end_comment

begin_enum
enum|enum
block|{
name|PRISM2_HOSTAPD_FLUSH
init|=
literal|1
block|,
name|PRISM2_HOSTAPD_ADD_STA
init|=
literal|2
block|,
name|PRISM2_HOSTAPD_REMOVE_STA
init|=
literal|3
block|,
name|PRISM2_HOSTAPD_GET_INFO_STA
init|=
literal|4
block|,
comment|/* REMOVED: PRISM2_HOSTAPD_RESET_TXEXC_STA = 5, */
name|PRISM2_SET_ENCRYPTION
init|=
literal|6
block|,
name|PRISM2_GET_ENCRYPTION
init|=
literal|7
block|,
name|PRISM2_HOSTAPD_SET_FLAGS_STA
init|=
literal|8
block|,
name|PRISM2_HOSTAPD_GET_RID
init|=
literal|9
block|,
name|PRISM2_HOSTAPD_SET_RID
init|=
literal|10
block|,
name|PRISM2_HOSTAPD_SET_ASSOC_AP_ADDR
init|=
literal|11
block|,
name|PRISM2_HOSTAPD_SET_GENERIC_ELEMENT
init|=
literal|12
block|,
name|PRISM2_HOSTAPD_MLME
init|=
literal|13
block|,
name|PRISM2_HOSTAPD_SCAN_REQ
init|=
literal|14
block|,
name|PRISM2_HOSTAPD_STA_CLEAR_STATS
init|=
literal|15
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|PRISM2_HOSTAPD_MAX_BUF_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|PRISM2_HOSTAPD_RID_HDR_LEN
define|\
value|((int) (&((struct prism2_hostapd_param *) 0)->u.rid.data))
end_define

begin_define
define|#
directive|define
name|PRISM2_HOSTAPD_GENERIC_ELEMENT_HDR_LEN
define|\
value|((int) (&((struct prism2_hostapd_param *) 0)->u.generic_elem.data))
end_define

begin_comment
comment|/* Maximum length for algorithm names (-1 for nul termination) used in ioctl()  */
end_comment

begin_define
define|#
directive|define
name|HOSTAP_CRYPT_ALG_NAME_LEN
value|16
end_define

begin_struct
struct|struct
name|prism2_hostapd_param
block|{
name|u32
name|cmd
decl_stmt|;
name|u8
name|sta_addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|u16
name|aid
decl_stmt|;
name|u16
name|capability
decl_stmt|;
name|u8
name|tx_supp_rates
decl_stmt|;
block|}
name|add_sta
struct|;
struct|struct
block|{
name|u32
name|inactive_sec
decl_stmt|;
block|}
name|get_info_sta
struct|;
struct|struct
block|{
name|u8
name|alg
index|[
name|HOSTAP_CRYPT_ALG_NAME_LEN
index|]
decl_stmt|;
name|u32
name|flags
decl_stmt|;
name|u32
name|err
decl_stmt|;
name|u8
name|idx
decl_stmt|;
name|u8
name|seq
index|[
literal|8
index|]
decl_stmt|;
comment|/* sequence counter (set: RX, get: TX) */
name|u16
name|key_len
decl_stmt|;
name|u8
name|key
index|[
literal|0
index|]
decl_stmt|;
block|}
name|crypt
struct|;
struct|struct
block|{
name|u32
name|flags_and
decl_stmt|;
name|u32
name|flags_or
decl_stmt|;
block|}
name|set_flags_sta
struct|;
struct|struct
block|{
name|u16
name|rid
decl_stmt|;
name|u16
name|len
decl_stmt|;
name|u8
name|data
index|[
literal|0
index|]
decl_stmt|;
block|}
name|rid
struct|;
struct|struct
block|{
name|u8
name|len
decl_stmt|;
name|u8
name|data
index|[
literal|0
index|]
decl_stmt|;
block|}
name|generic_elem
struct|;
struct|struct
block|{
define|#
directive|define
name|MLME_STA_DEAUTH
value|0
define|#
directive|define
name|MLME_STA_DISASSOC
value|1
name|u16
name|cmd
decl_stmt|;
name|u16
name|reason_code
decl_stmt|;
block|}
name|mlme
struct|;
struct|struct
block|{
name|u8
name|ssid_len
decl_stmt|;
name|u8
name|ssid
index|[
literal|32
index|]
decl_stmt|;
block|}
name|scan_req
struct|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HOSTAP_CRYPT_FLAG_SET_TX_KEY
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|HOSTAP_CRYPT_FLAG_PERMANENT
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|HOSTAP_CRYPT_ERR_UNKNOWN_ALG
value|2
end_define

begin_define
define|#
directive|define
name|HOSTAP_CRYPT_ERR_UNKNOWN_ADDR
value|3
end_define

begin_define
define|#
directive|define
name|HOSTAP_CRYPT_ERR_CRYPT_INIT_FAILED
value|4
end_define

begin_define
define|#
directive|define
name|HOSTAP_CRYPT_ERR_KEY_SET_FAILED
value|5
end_define

begin_define
define|#
directive|define
name|HOSTAP_CRYPT_ERR_TX_KEY_SET_FAILED
value|6
end_define

begin_define
define|#
directive|define
name|HOSTAP_CRYPT_ERR_CARD_CONF_FAILED
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HOSTAP_COMMON_H */
end_comment

end_unit

