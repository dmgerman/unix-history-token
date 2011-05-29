begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant - Windows/NDIS driver interface  * Copyright (c) 2004-2006, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DRIVER_NDIS_H
end_ifndef

begin_define
define|#
directive|define
name|DRIVER_NDIS_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_NDIS_EVENTS_INTEGRATED
end_ifdef

begin_struct_decl
struct_decl|struct
name|ndis_events_data
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|ndis_events_data
modifier|*
name|ndis_events_init
parameter_list|(
name|HANDLE
modifier|*
name|read_pipe
parameter_list|,
name|HANDLE
modifier|*
name|event
parameter_list|,
specifier|const
name|char
modifier|*
name|ifname
parameter_list|,
specifier|const
name|char
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ndis_events_deinit
parameter_list|(
name|struct
name|ndis_events_data
modifier|*
name|events
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_NDIS_EVENTS_INTEGRATED */
end_comment

begin_struct
struct|struct
name|ndis_pmkid_entry
block|{
name|struct
name|ndis_pmkid_entry
modifier|*
name|next
decl_stmt|;
name|u8
name|bssid
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|u8
name|pmkid
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wpa_driver_ndis_data
block|{
name|void
modifier|*
name|ctx
decl_stmt|;
name|char
name|ifname
index|[
literal|100
index|]
decl_stmt|;
comment|/* GUID: {7EE3EFE5-C165-472F-986D-F6FBEDFE8C8D} */
ifdef|#
directive|ifdef
name|_WIN32_WCE
name|TCHAR
modifier|*
name|adapter_name
decl_stmt|;
name|HANDLE
name|event_queue
decl_stmt|;
comment|/* NDISUIO notifier MsgQueue */
name|HANDLE
name|connected_event
decl_stmt|;
comment|/* WpaSupplicantConnected event */
endif|#
directive|endif
comment|/* _WIN32_WCE */
name|u8
name|own_addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|CONFIG_USE_NDISUIO
name|HANDLE
name|ndisuio
decl_stmt|;
else|#
directive|else
comment|/* CONFIG_USE_NDISUIO */
name|LPADAPTER
name|adapter
decl_stmt|;
endif|#
directive|endif
comment|/* CONFIG_USE_NDISUIO */
name|u8
name|bssid
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|int
name|has_capability
decl_stmt|;
name|int
name|no_of_pmkid
decl_stmt|;
name|int
name|radio_enabled
decl_stmt|;
name|struct
name|wpa_driver_capa
name|capa
decl_stmt|;
name|struct
name|ndis_pmkid_entry
modifier|*
name|pmkid
decl_stmt|;
name|char
modifier|*
name|adapter_desc
decl_stmt|;
name|int
name|wired
decl_stmt|;
name|int
name|native80211
decl_stmt|;
name|int
name|mode
decl_stmt|;
name|int
name|wzc_disabled
decl_stmt|;
name|int
name|oid_bssid_set
decl_stmt|;
ifdef|#
directive|ifdef
name|CONFIG_NDIS_EVENTS_INTEGRATED
name|HANDLE
name|events_pipe
decl_stmt|,
name|event_avail
decl_stmt|;
name|struct
name|ndis_events_data
modifier|*
name|events
decl_stmt|;
endif|#
directive|endif
comment|/* CONFIG_NDIS_EVENTS_INTEGRATED */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DRIVER_NDIS_H */
end_comment

end_unit

