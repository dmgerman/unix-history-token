begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * BSS table  * Copyright (c) 2009-2010, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSS_H
end_ifndef

begin_define
define|#
directive|define
name|BSS_H
end_define

begin_struct_decl
struct_decl|struct
name|wpa_scan_res
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|WPA_BSS_QUAL_INVALID
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|WPA_BSS_NOISE_INVALID
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|WPA_BSS_LEVEL_INVALID
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|WPA_BSS_LEVEL_DBM
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|WPA_BSS_AUTHENTICATED
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|WPA_BSS_ASSOCIATED
value|BIT(5)
end_define

begin_define
define|#
directive|define
name|WPA_BSS_ANQP_FETCH_TRIED
value|BIT(6)
end_define

begin_comment
comment|/**  * struct wpa_bss_anqp - ANQP data for a BSS entry (struct wpa_bss)  */
end_comment

begin_struct
struct|struct
name|wpa_bss_anqp
block|{
comment|/** Number of BSS entries referring to this ANQP data instance */
name|unsigned
name|int
name|users
decl_stmt|;
ifdef|#
directive|ifdef
name|CONFIG_INTERWORKING
name|struct
name|wpabuf
modifier|*
name|venue_name
decl_stmt|;
name|struct
name|wpabuf
modifier|*
name|network_auth_type
decl_stmt|;
name|struct
name|wpabuf
modifier|*
name|roaming_consortium
decl_stmt|;
name|struct
name|wpabuf
modifier|*
name|ip_addr_type_availability
decl_stmt|;
name|struct
name|wpabuf
modifier|*
name|nai_realm
decl_stmt|;
name|struct
name|wpabuf
modifier|*
name|anqp_3gpp
decl_stmt|;
name|struct
name|wpabuf
modifier|*
name|domain_name
decl_stmt|;
endif|#
directive|endif
comment|/* CONFIG_INTERWORKING */
ifdef|#
directive|ifdef
name|CONFIG_HS20
name|struct
name|wpabuf
modifier|*
name|hs20_operator_friendly_name
decl_stmt|;
name|struct
name|wpabuf
modifier|*
name|hs20_wan_metrics
decl_stmt|;
name|struct
name|wpabuf
modifier|*
name|hs20_connection_capability
decl_stmt|;
name|struct
name|wpabuf
modifier|*
name|hs20_operating_class
decl_stmt|;
endif|#
directive|endif
comment|/* CONFIG_HS20 */
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct wpa_bss - BSS table  *  * This structure is used to store information about neighboring BSSes in  * generic format. It is mainly updated based on scan results from the driver.  */
end_comment

begin_struct
struct|struct
name|wpa_bss
block|{
comment|/** List entry for struct wpa_supplicant::bss */
name|struct
name|dl_list
name|list
decl_stmt|;
comment|/** List entry for struct wpa_supplicant::bss_id */
name|struct
name|dl_list
name|list_id
decl_stmt|;
comment|/** Unique identifier for this BSS entry */
name|unsigned
name|int
name|id
decl_stmt|;
comment|/** Number of counts without seeing this BSS */
name|unsigned
name|int
name|scan_miss_count
decl_stmt|;
comment|/** Index of the last scan update */
name|unsigned
name|int
name|last_update_idx
decl_stmt|;
comment|/** Information flags about the BSS/IBSS (WPA_BSS_*) */
name|unsigned
name|int
name|flags
decl_stmt|;
comment|/** BSSID */
name|u8
name|bssid
index|[
name|ETH_ALEN
index|]
decl_stmt|;
comment|/** HESSID */
name|u8
name|hessid
index|[
name|ETH_ALEN
index|]
decl_stmt|;
comment|/** SSID */
name|u8
name|ssid
index|[
literal|32
index|]
decl_stmt|;
comment|/** Length of SSID */
name|size_t
name|ssid_len
decl_stmt|;
comment|/** Frequency of the channel in MHz (e.g., 2412 = channel 1) */
name|int
name|freq
decl_stmt|;
comment|/** Beacon interval in TUs (host byte order) */
name|u16
name|beacon_int
decl_stmt|;
comment|/** Capability information field in host byte order */
name|u16
name|caps
decl_stmt|;
comment|/** Signal quality */
name|int
name|qual
decl_stmt|;
comment|/** Noise level */
name|int
name|noise
decl_stmt|;
comment|/** Signal level */
name|int
name|level
decl_stmt|;
comment|/** Timestamp of last Beacon/Probe Response frame */
name|u64
name|tsf
decl_stmt|;
comment|/** Time of the last update (i.e., Beacon or Probe Response RX) */
name|struct
name|os_time
name|last_update
decl_stmt|;
comment|/** ANQP data */
name|struct
name|wpa_bss_anqp
modifier|*
name|anqp
decl_stmt|;
comment|/** Length of the following IE field in octets (from Probe Response) */
name|size_t
name|ie_len
decl_stmt|;
comment|/** Length of the following Beacon IE field in octets */
name|size_t
name|beacon_ie_len
decl_stmt|;
comment|/* followed by ie_len octets of IEs */
comment|/* followed by beacon_ie_len octets of IEs */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|wpa_bss_update_start
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpa_bss_update_scan_res
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|struct
name|wpa_scan_res
modifier|*
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpa_bss_update_end
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|struct
name|scan_info
modifier|*
name|info
parameter_list|,
name|int
name|new_scan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_bss_init
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpa_bss_deinit
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpa_bss_flush
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wpa_bss_flush_by_age
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|int
name|age
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpa_bss
modifier|*
name|wpa_bss_get
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
specifier|const
name|u8
modifier|*
name|bssid
parameter_list|,
specifier|const
name|u8
modifier|*
name|ssid
parameter_list|,
name|size_t
name|ssid_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpa_bss
modifier|*
name|wpa_bss_get_bssid
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
specifier|const
name|u8
modifier|*
name|bssid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpa_bss
modifier|*
name|wpa_bss_get_p2p_dev_addr
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
specifier|const
name|u8
modifier|*
name|dev_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpa_bss
modifier|*
name|wpa_bss_get_id
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|unsigned
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|u8
modifier|*
name|wpa_bss_get_ie
parameter_list|(
specifier|const
name|struct
name|wpa_bss
modifier|*
name|bss
parameter_list|,
name|u8
name|ie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|u8
modifier|*
name|wpa_bss_get_vendor_ie
parameter_list|(
specifier|const
name|struct
name|wpa_bss
modifier|*
name|bss
parameter_list|,
name|u32
name|vendor_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|wpa_bss_get_vendor_ie_multi
parameter_list|(
specifier|const
name|struct
name|wpa_bss
modifier|*
name|bss
parameter_list|,
name|u32
name|vendor_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|wpa_bss_get_vendor_ie_multi_beacon
parameter_list|(
specifier|const
name|struct
name|wpa_bss
modifier|*
name|bss
parameter_list|,
name|u32
name|vendor_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_bss_get_max_rate
parameter_list|(
specifier|const
name|struct
name|wpa_bss
modifier|*
name|bss
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_bss_get_bit_rates
parameter_list|(
specifier|const
name|struct
name|wpa_bss
modifier|*
name|bss
parameter_list|,
name|u8
modifier|*
modifier|*
name|rates
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpa_bss_anqp
modifier|*
name|wpa_bss_anqp_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wpa_bss_anqp_unshare_alloc
parameter_list|(
name|struct
name|wpa_bss
modifier|*
name|bss
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSS_H */
end_comment

end_unit

