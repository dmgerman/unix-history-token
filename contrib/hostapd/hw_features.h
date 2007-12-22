begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hostapd / Hardware feature query and different modes  * Copyright 2002-2003, Instant802 Networks, Inc.  * Copyright 2005-2006, Devicescape Software, Inc.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
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

begin_define
define|#
directive|define
name|HOSTAPD_CHAN_W_SCAN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HOSTAPD_CHAN_W_ACTIVE_SCAN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HOSTAPD_CHAN_W_IBSS
value|0x00000004
end_define

begin_struct
struct|struct
name|hostapd_channel_data
block|{
name|short
name|chan
decl_stmt|;
comment|/* channel number (IEEE 802.11) */
name|short
name|freq
decl_stmt|;
comment|/* frequency in MHz */
name|int
name|flag
decl_stmt|;
comment|/* flag for hostapd use (HOSTAPD_CHAN_*) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HOSTAPD_RATE_ERP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HOSTAPD_RATE_BASIC
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HOSTAPD_RATE_PREAMBLE2
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HOSTAPD_RATE_SUPPORTED
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HOSTAPD_RATE_OFDM
value|0x00000020
end_define

begin_define
define|#
directive|define
name|HOSTAPD_RATE_CCK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|HOSTAPD_RATE_MANDATORY
value|0x00000100
end_define

begin_struct
struct|struct
name|hostapd_rate_data
block|{
name|int
name|rate
decl_stmt|;
comment|/* rate in 100 kbps */
name|int
name|flags
decl_stmt|;
comment|/* HOSTAPD_RATE_ flags */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hostapd_hw_modes
block|{
name|int
name|mode
decl_stmt|;
name|int
name|num_channels
decl_stmt|;
name|struct
name|hostapd_channel_data
modifier|*
name|channels
decl_stmt|;
name|int
name|num_rates
decl_stmt|;
name|struct
name|hostapd_rate_data
modifier|*
name|rates
decl_stmt|;
block|}
struct|;
end_struct

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
name|hostapd_select_hw_mode_start
parameter_list|(
name|struct
name|hostapd_iface
modifier|*
name|iface
parameter_list|,
name|hostapd_iface_cb
name|cb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hostapd_select_hw_mode_stop
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HW_FEATURES_H */
end_comment

end_unit

