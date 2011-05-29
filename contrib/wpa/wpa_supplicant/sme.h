begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * wpa_supplicant - SME  * Copyright (c) 2009-2010, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SME_H
end_ifndef

begin_define
define|#
directive|define
name|SME_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_SME
end_ifdef

begin_function_decl
name|void
name|sme_authenticate
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|struct
name|wpa_bss
modifier|*
name|bss
parameter_list|,
name|struct
name|wpa_ssid
modifier|*
name|ssid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sme_associate
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|enum
name|wpas_mode
name|mode
parameter_list|,
specifier|const
name|u8
modifier|*
name|bssid
parameter_list|,
name|u16
name|auth_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sme_event_auth
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|union
name|wpa_event_data
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sme_update_ft_ies
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
specifier|const
name|u8
modifier|*
name|md
parameter_list|,
specifier|const
name|u8
modifier|*
name|ies
parameter_list|,
name|size_t
name|ies_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sme_event_assoc_reject
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|union
name|wpa_event_data
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sme_event_auth_timed_out
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|union
name|wpa_event_data
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sme_event_assoc_timed_out
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|union
name|wpa_event_data
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sme_event_disassoc
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|union
name|wpa_event_data
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_SME */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|sme_authenticate
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|struct
name|wpa_bss
modifier|*
name|bss
parameter_list|,
name|struct
name|wpa_ssid
modifier|*
name|ssid
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|sme_event_auth
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|union
name|wpa_event_data
modifier|*
name|data
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|int
name|sme_update_ft_ies
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
specifier|const
name|u8
modifier|*
name|md
parameter_list|,
specifier|const
name|u8
modifier|*
name|ies
parameter_list|,
name|size_t
name|ies_len
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
name|void
name|sme_event_assoc_reject
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|union
name|wpa_event_data
modifier|*
name|data
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|sme_event_auth_timed_out
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|union
name|wpa_event_data
modifier|*
name|data
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|sme_event_assoc_timed_out
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|union
name|wpa_event_data
modifier|*
name|data
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|sme_event_disassoc
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
name|union
name|wpa_event_data
modifier|*
name|data
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_SME */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SME_H */
end_comment

end_unit

