begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hostapd / Hardware feature query and different modes  * Copyright 2002-2003, Instant802 Networks, Inc.  * Copyright 2005-2006, Devicescape Software, Inc.  * Copyright (c) 2008-2011, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HW_FEATURES_H
end_ifndef

begin_define
define|#
directive|define
name|HW_FEATURES_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_AP_MLME
end_ifdef

begin_function_decl
name|void
name|hostapd_free_hw_features
parameter_list|(
name|struct
name|hostapd_hw_modes
modifier|*
name|hw_features
parameter_list|,
name|size_t
name|num_hw_features
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hostapd_get_hw_features
parameter_list|(
name|struct
name|hostapd_iface
modifier|*
name|iface
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hostapd_select_hw_mode
parameter_list|(
name|struct
name|hostapd_iface
modifier|*
name|iface
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|hostapd_hw_mode_txt
parameter_list|(
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hostapd_hw_get_freq
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|int
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hostapd_hw_get_channel
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|int
name|freq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hostapd_check_ht_capab
parameter_list|(
name|struct
name|hostapd_iface
modifier|*
name|iface
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hostapd_prepare_rates
parameter_list|(
name|struct
name|hostapd_iface
modifier|*
name|iface
parameter_list|,
name|struct
name|hostapd_hw_modes
modifier|*
name|mode
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
name|void
name|hostapd_free_hw_features
parameter_list|(
name|struct
name|hostapd_hw_modes
modifier|*
name|hw_features
parameter_list|,
name|size_t
name|num_hw_features
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|int
name|hostapd_get_hw_features
parameter_list|(
name|struct
name|hostapd_iface
modifier|*
name|iface
parameter_list|)
block|{
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|hostapd_select_hw_mode
parameter_list|(
name|struct
name|hostapd_iface
modifier|*
name|iface
parameter_list|)
block|{
return|return
operator|-
literal|100
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
specifier|const
name|char
modifier|*
name|hostapd_hw_mode_txt
parameter_list|(
name|int
name|mode
parameter_list|)
block|{
return|return
name|NULL
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|hostapd_hw_get_freq
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|int
name|chan
parameter_list|)
block|{
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|hostapd_check_ht_capab
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
name|int
name|hostapd_prepare_rates
parameter_list|(
name|struct
name|hostapd_iface
modifier|*
name|iface
parameter_list|,
name|struct
name|hostapd_hw_modes
modifier|*
name|mode
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
comment|/* NEED_AP_MLME */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HW_FEATURES_H */
end_comment

end_unit

