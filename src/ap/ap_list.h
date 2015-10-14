begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hostapd / AP table  * Copyright (c) 2002-2003, Jouni Malinen<j@w1.fi>  * Copyright (c) 2003-2004, Instant802 Networks, Inc.  * Copyright (c) 2006, Devicescape Software, Inc.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AP_LIST_H
end_ifndef

begin_define
define|#
directive|define
name|AP_LIST_H
end_define

begin_struct
struct|struct
name|ap_info
block|{
comment|/* Note: next/prev pointers are updated whenever a new beacon is 	 * received because these are used to find the least recently used 	 * entries. */
name|struct
name|ap_info
modifier|*
name|next
decl_stmt|;
comment|/* next entry in AP list */
name|struct
name|ap_info
modifier|*
name|prev
decl_stmt|;
comment|/* previous entry in AP list */
name|struct
name|ap_info
modifier|*
name|hnext
decl_stmt|;
comment|/* next entry in hash table list */
name|u8
name|addr
index|[
literal|6
index|]
decl_stmt|;
name|u8
name|supported_rates
index|[
name|WLAN_SUPP_RATES_MAX
index|]
decl_stmt|;
name|int
name|erp
decl_stmt|;
comment|/* ERP Info or -1 if ERP info element not present */
name|int
name|channel
decl_stmt|;
name|int
name|ht_support
decl_stmt|;
name|struct
name|os_reltime
name|last_beacon
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|ieee802_11_elems
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|hostapd_frame_info
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|ap_list_process_beacon
parameter_list|(
name|struct
name|hostapd_iface
modifier|*
name|iface
parameter_list|,
specifier|const
name|struct
name|ieee80211_mgmt
modifier|*
name|mgmt
parameter_list|,
name|struct
name|ieee802_11_elems
modifier|*
name|elems
parameter_list|,
name|struct
name|hostapd_frame_info
modifier|*
name|fi
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_AP_MLME
end_ifdef

begin_function_decl
name|int
name|ap_list_init
parameter_list|(
name|struct
name|hostapd_iface
modifier|*
name|iface
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ap_list_deinit
parameter_list|(
name|struct
name|hostapd_iface
modifier|*
name|iface
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ap_list_timer
parameter_list|(
name|struct
name|hostapd_iface
modifier|*
name|iface
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NEED_AP_MLME */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|ap_list_init
parameter_list|(
name|struct
name|hostapd_iface
modifier|*
name|iface
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|ap_list_deinit
parameter_list|(
name|struct
name|hostapd_iface
modifier|*
name|iface
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|ap_list_timer
parameter_list|(
name|struct
name|hostapd_iface
modifier|*
name|iface
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEED_AP_MLME */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AP_LIST_H */
end_comment

end_unit

