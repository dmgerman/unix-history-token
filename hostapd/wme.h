begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hostapd / WMM (Wi-Fi Multimedia)  * Copyright 2002-2003, Instant802 Networks, Inc.  * Copyright 2005-2006, Devicescape Software, Inc.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WME_H
end_ifndef

begin_define
define|#
directive|define
name|WME_H
end_define

begin_comment
comment|/*  * WMM Information Element (used in (Re)Association Request frames; may also be  * used in Beacon frames)  */
end_comment

begin_struct
struct|struct
name|wmm_information_element
block|{
comment|/* Element ID: 221 (0xdd); Length: 7 */
comment|/* required fields for WMM version 1 */
name|u8
name|oui
index|[
literal|3
index|]
decl_stmt|;
comment|/* 00:50:f2 */
name|u8
name|oui_type
decl_stmt|;
comment|/* 2 */
name|u8
name|oui_subtype
decl_stmt|;
comment|/* 0 */
name|u8
name|version
decl_stmt|;
comment|/* 1 for WMM version 1.0 */
name|u8
name|qos_info
decl_stmt|;
comment|/* AP/STA specific QoS info */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|WMM_AC_AIFSN_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|WMM_AC_AIFNS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|WMM_AC_ACM
value|0x10
end_define

begin_define
define|#
directive|define
name|WMM_AC_ACI_MASK
value|0x60
end_define

begin_define
define|#
directive|define
name|WMM_AC_ACI_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|WMM_AC_ECWMIN_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|WMM_AC_ECWMIN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|WMM_AC_ECWMAX_MASK
value|0xf0
end_define

begin_define
define|#
directive|define
name|WMM_AC_ECWMAX_SHIFT
value|4
end_define

begin_struct
struct|struct
name|wmm_ac_parameter
block|{
name|u8
name|aci_aifsn
decl_stmt|;
comment|/* AIFSN, ACM, ACI */
name|u8
name|cw
decl_stmt|;
comment|/* ECWmin, ECWmax (CW = 2^ECW - 1) */
name|le16
name|txop_limit
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/*  * WMM Parameter Element (used in Beacon, Probe Response, and (Re)Association  * Response frmaes)  */
end_comment

begin_struct
struct|struct
name|wmm_parameter_element
block|{
comment|/* Element ID: 221 (0xdd); Length: 24 */
comment|/* required fields for WMM version 1 */
name|u8
name|oui
index|[
literal|3
index|]
decl_stmt|;
comment|/* 00:50:f2 */
name|u8
name|oui_type
decl_stmt|;
comment|/* 2 */
name|u8
name|oui_subtype
decl_stmt|;
comment|/* 1 */
name|u8
name|version
decl_stmt|;
comment|/* 1 for WMM version 1.0 */
name|u8
name|qos_info
decl_stmt|;
comment|/* AP/STA specif QoS info */
name|u8
name|reserved
decl_stmt|;
comment|/* 0 */
name|struct
name|wmm_ac_parameter
name|ac
index|[
literal|4
index|]
decl_stmt|;
comment|/* AC_BE, AC_BK, AC_VI, AC_VO */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* WMM TSPEC Element */
end_comment

begin_struct
struct|struct
name|wmm_tspec_element
block|{
name|u8
name|eid
decl_stmt|;
comment|/* 221 = 0xdd */
name|u8
name|length
decl_stmt|;
comment|/* 6 + 55 = 61 */
name|u8
name|oui
index|[
literal|3
index|]
decl_stmt|;
comment|/* 00:50:f2 */
name|u8
name|oui_type
decl_stmt|;
comment|/* 2 */
name|u8
name|oui_subtype
decl_stmt|;
comment|/* 2 */
name|u8
name|version
decl_stmt|;
comment|/* 1 */
comment|/* WMM TSPEC body (55 octets): */
name|u8
name|ts_info
index|[
literal|3
index|]
decl_stmt|;
name|le16
name|nominal_msdu_size
decl_stmt|;
name|le16
name|maximum_msdu_size
decl_stmt|;
name|le32
name|minimum_service_interval
decl_stmt|;
name|le32
name|maximum_service_interval
decl_stmt|;
name|le32
name|inactivity_interval
decl_stmt|;
name|le32
name|suspension_interval
decl_stmt|;
name|le32
name|service_start_time
decl_stmt|;
name|le32
name|minimum_data_rate
decl_stmt|;
name|le32
name|mean_data_rate
decl_stmt|;
name|le32
name|peak_data_rate
decl_stmt|;
name|le32
name|maximum_burst_size
decl_stmt|;
name|le32
name|delay_bound
decl_stmt|;
name|le32
name|minimum_phy_rate
decl_stmt|;
name|le16
name|surplus_bandwidth_allowance
decl_stmt|;
name|le16
name|medium_time
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* Access Categories / ACI to AC coding */
end_comment

begin_enum
enum|enum
block|{
name|WMM_AC_BE
init|=
literal|0
comment|/* Best Effort */
block|,
name|WMM_AC_BK
init|=
literal|1
comment|/* Background */
block|,
name|WMM_AC_VI
init|=
literal|2
comment|/* Video */
block|,
name|WMM_AC_VO
init|=
literal|3
comment|/* Voice */
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|ieee80211_mgmt
struct_decl|;
end_struct_decl

begin_function_decl
name|u8
modifier|*
name|hostapd_eid_wmm
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|u8
modifier|*
name|eid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hostapd_eid_wmm_valid
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|u8
modifier|*
name|eid
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hostapd_wmm_sta_config
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|sta_info
modifier|*
name|sta
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hostapd_wmm_action
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|ieee80211_mgmt
modifier|*
name|mgmt
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WME_H */
end_comment

end_unit

