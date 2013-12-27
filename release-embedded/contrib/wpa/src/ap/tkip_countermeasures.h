begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hostapd / TKIP countermeasures  * Copyright (c) 2002-2012, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TKIP_COUNTERMEASURES_H
end_ifndef

begin_define
define|#
directive|define
name|TKIP_COUNTERMEASURES_H
end_define

begin_function_decl
name|int
name|michael_mic_failure
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
name|int
name|local
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_tkip_countermeasures_deinit
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TKIP_COUNTERMEASURES_H */
end_comment

end_unit

