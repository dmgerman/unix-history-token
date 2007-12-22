begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hostapd / IEEE 802.11h  * Copyright (c) 2005-2006, Devicescape Software, Inc.  * Copyright (c) 2007, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IEEE802_11H_H
end_ifndef

begin_define
define|#
directive|define
name|IEEE802_11H_H
end_define

begin_define
define|#
directive|define
name|SPECT_LOOSE_BINDING
value|1
end_define

begin_define
define|#
directive|define
name|SPECT_STRICT_BINDING
value|2
end_define

begin_define
define|#
directive|define
name|CHAN_SWITCH_MODE_NOISY
value|0
end_define

begin_define
define|#
directive|define
name|CHAN_SWITCH_MODE_QUIET
value|1
end_define

begin_function_decl
name|int
name|hostapd_check_power_cap
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|u8
modifier|*
name|power
parameter_list|,
name|u8
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IEEE802_11H_H */
end_comment

end_unit

