begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * wpa_supplicant - WPA2/RSN pre-authentication functions  * Copyright (c) 2003-2005, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PREAUTH_H
end_ifndef

begin_define
define|#
directive|define
name|PREAUTH_H
end_define

begin_struct_decl
struct_decl|struct
name|wpa_scan_results
struct_decl|;
end_struct_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|IEEE8021X_EAPOL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CONFIG_NO_WPA2
argument_list|)
end_if

begin_function_decl
name|void
name|pmksa_candidate_free
parameter_list|(
name|struct
name|wpa_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rsn_preauth_init
parameter_list|(
name|struct
name|wpa_sm
modifier|*
name|sm
parameter_list|,
specifier|const
name|u8
modifier|*
name|dst
parameter_list|,
name|struct
name|eap_peer_config
modifier|*
name|eap_conf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rsn_preauth_deinit
parameter_list|(
name|struct
name|wpa_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rsn_preauth_scan_results
parameter_list|(
name|struct
name|wpa_sm
modifier|*
name|sm
parameter_list|,
name|struct
name|wpa_scan_results
modifier|*
name|results
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmksa_candidate_add
parameter_list|(
name|struct
name|wpa_sm
modifier|*
name|sm
parameter_list|,
specifier|const
name|u8
modifier|*
name|bssid
parameter_list|,
name|int
name|prio
parameter_list|,
name|int
name|preauth
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rsn_preauth_candidate_process
parameter_list|(
name|struct
name|wpa_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rsn_preauth_get_status
parameter_list|(
name|struct
name|wpa_sm
modifier|*
name|sm
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|,
name|int
name|verbose
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rsn_preauth_in_progress
parameter_list|(
name|struct
name|wpa_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* IEEE8021X_EAPOL and !CONFIG_NO_WPA2 */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|pmksa_candidate_free
parameter_list|(
name|struct
name|wpa_sm
modifier|*
name|sm
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|rsn_preauth_candidate_process
parameter_list|(
name|struct
name|wpa_sm
modifier|*
name|sm
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|int
name|rsn_preauth_init
parameter_list|(
name|struct
name|wpa_sm
modifier|*
name|sm
parameter_list|,
specifier|const
name|u8
modifier|*
name|dst
parameter_list|,
name|struct
name|eap_peer_config
modifier|*
name|eap_conf
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
name|rsn_preauth_deinit
parameter_list|(
name|struct
name|wpa_sm
modifier|*
name|sm
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|rsn_preauth_scan_results
parameter_list|(
name|struct
name|wpa_sm
modifier|*
name|sm
parameter_list|,
name|struct
name|wpa_scan_results
modifier|*
name|results
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|pmksa_candidate_add
parameter_list|(
name|struct
name|wpa_sm
modifier|*
name|sm
parameter_list|,
specifier|const
name|u8
modifier|*
name|bssid
parameter_list|,
name|int
name|prio
parameter_list|,
name|int
name|preauth
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|int
name|rsn_preauth_get_status
parameter_list|(
name|struct
name|wpa_sm
modifier|*
name|sm
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|,
name|int
name|verbose
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
name|rsn_preauth_in_progress
parameter_list|(
name|struct
name|wpa_sm
modifier|*
name|sm
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
comment|/* IEEE8021X_EAPOL and !CONFIG_NO_WPA2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PREAUTH_H */
end_comment

end_unit

