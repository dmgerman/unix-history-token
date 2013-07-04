begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * wpa_supplicant - Temporary BSSID blacklist  * Copyright (c) 2003-2007, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BLACKLIST_H
end_ifndef

begin_define
define|#
directive|define
name|BLACKLIST_H
end_define

begin_struct
struct|struct
name|wpa_blacklist
block|{
name|struct
name|wpa_blacklist
modifier|*
name|next
decl_stmt|;
name|u8
name|bssid
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|int
name|count
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|wpa_blacklist
modifier|*
name|wpa_blacklist_get
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
name|int
name|wpa_blacklist_add
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
name|int
name|wpa_blacklist_del
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
name|void
name|wpa_blacklist_clear
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BLACKLIST_H */
end_comment

end_unit

