begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * IEEE 802.11v WNM related functions and structures  * Copyright (c) 2011-2012, Qualcomm Atheros, Inc.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WNM_STA_H
end_ifndef

begin_define
define|#
directive|define
name|WNM_STA_H
end_define

begin_struct
struct|struct
name|measurement_pilot
block|{
name|u8
name|measurement_pilot
decl_stmt|;
name|u8
name|subelem_len
decl_stmt|;
name|u8
name|subelems
index|[
literal|255
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|multiple_bssid
block|{
name|u8
name|max_bssid_indicator
decl_stmt|;
name|u8
name|subelem_len
decl_stmt|;
name|u8
name|subelems
index|[
literal|255
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|neighbor_report
block|{
name|u8
name|bssid
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|u32
name|bssid_info
decl_stmt|;
name|u8
name|regulatory_class
decl_stmt|;
name|u8
name|channel_number
decl_stmt|;
name|u8
name|phy_type
decl_stmt|;
name|u8
name|preference
decl_stmt|;
comment|/* valid if preference_present=1 */
name|u16
name|tsf_offset
decl_stmt|;
comment|/* valid if tsf_present=1 */
name|u16
name|beacon_int
decl_stmt|;
comment|/* valid if tsf_present=1 */
name|char
name|country
index|[
literal|2
index|]
decl_stmt|;
comment|/* valid if country_present=1 */
name|u8
name|rm_capab
index|[
literal|5
index|]
decl_stmt|;
comment|/* valid if rm_capab_present=1 */
name|u16
name|bearing
decl_stmt|;
comment|/* valid if bearing_present=1 */
name|u16
name|rel_height
decl_stmt|;
comment|/* valid if bearing_present=1 */
name|u32
name|distance
decl_stmt|;
comment|/* valid if bearing_present=1 */
name|u64
name|bss_term_tsf
decl_stmt|;
comment|/* valid if bss_term_present=1 */
name|u16
name|bss_term_dur
decl_stmt|;
comment|/* valid if bss_term_present=1 */
name|unsigned
name|int
name|preference_present
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|tsf_present
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|country_present
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|rm_capab_present
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|bearing_present
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|bss_term_present
range|:
literal|1
decl_stmt|;
name|struct
name|measurement_pilot
modifier|*
name|meas_pilot
decl_stmt|;
name|struct
name|multiple_bssid
modifier|*
name|mul_bssid
decl_stmt|;
name|int
name|freq
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|ieee802_11_send_wnmsleep_req
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|u8
name|action
parameter_list|,
name|u16
name|intval
parameter_list|,
name|struct
name|wpabuf
modifier|*
name|tfs_req
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee802_11_rx_wnm_action
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
specifier|const
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

begin_function_decl
name|int
name|wnm_send_bss_transition_mgmt_query
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|u8
name|query_reason
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wnm_deallocate_memory
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_WNM
end_ifdef

begin_function_decl
name|int
name|wnm_scan_process
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|int
name|reply_on_fail
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_WNM */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|wnm_scan_process
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|int
name|reply_on_fail
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_WNM */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WNM_STA_H */
end_comment

end_unit

