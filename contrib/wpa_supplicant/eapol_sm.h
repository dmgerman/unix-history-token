begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant / EAPOL state machines  * Copyright (c) 2004-2005, Jouni Malinen<jkmaline@cc.hut.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAPOL_SM_H
end_ifndef

begin_define
define|#
directive|define
name|EAPOL_SM_H
end_define

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_typedef
typedef|typedef
enum|enum
block|{
name|Unauthorized
block|,
name|Authorized
block|}
name|PortStatus
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|Auto
block|,
name|ForceUnauthorized
block|,
name|ForceAuthorized
block|}
name|PortControl
typedef|;
end_typedef

begin_comment
comment|/**  * struct eapol_config - Per network configuration for EAPOL state machines  */
end_comment

begin_struct
struct|struct
name|eapol_config
block|{
comment|/** 	 * accept_802_1x_keys - Accept IEEE 802.1X (non-WPA) EAPOL-Key frames 	 * 	 * This variable should be set to 1 when using EAPOL state machines 	 * with non-WPA security policy to generate dynamic WEP keys. When 	 * using WPA, this should be set to 0 so that WPA state machine can 	 * process the EAPOL-Key frames. 	 */
name|int
name|accept_802_1x_keys
decl_stmt|;
define|#
directive|define
name|EAPOL_REQUIRE_KEY_UNICAST
value|BIT(0)
define|#
directive|define
name|EAPOL_REQUIRE_KEY_BROADCAST
value|BIT(1)
comment|/** 	 * required_keys - Which EAPOL-Key packets are required 	 * 	 * This variable determines which EAPOL-Key packets are required before 	 * marking connection authenticated. This is a bit field of 	 * EAPOL_REQUIRE_KEY_UNICAST and EAPOL_REQUIRE_KEY_BROADCAST flags. 	 */
name|int
name|required_keys
decl_stmt|;
comment|/** 	 * fast_reauth - Whether fast EAP reauthentication is enabled 	 */
name|int
name|fast_reauth
decl_stmt|;
comment|/** 	 * workaround - Whether EAP workarounds are enabled 	 */
name|unsigned
name|int
name|workaround
decl_stmt|;
comment|/** 	 * eap_disabled - Whether EAP is disabled 	 */
name|int
name|eap_disabled
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|eapol_sm
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|wpa_config_blob
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * struct eapol_ctx - Global (for all networks) EAPOL state machine context  */
end_comment

begin_struct
struct|struct
name|eapol_ctx
block|{
comment|/** 	 * ctx - Pointer to arbitrary upper level context 	 */
name|void
modifier|*
name|ctx
decl_stmt|;
comment|/** 	 * preauth - IEEE 802.11i/RSN pre-authentication 	 * 	 * This EAPOL state machine is used for IEEE 802.11i/RSN 	 * pre-authentication 	 */
name|int
name|preauth
decl_stmt|;
comment|/** 	 * cb - Function to be called when EAPOL negotiation has been completed 	 * @eapol: Pointer to EAPOL state machine data 	 * @success: Whether the authentication was completed successfully 	 * @ctx: Pointer to context data (cb_ctx) 	 * 	 * This optional callback function will be called when the EAPOL 	 * authentication has been completed. This allows the owner of the 	 * EAPOL state machine to process the key and terminate the EAPOL state 	 * machine. Currently, this is used only in RSN pre-authentication. 	 */
name|void
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|eapol
parameter_list|,
name|int
name|success
parameter_list|,
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
comment|/** 	 * cb_ctx - Callback context for cb() 	 */
name|void
modifier|*
name|cb_ctx
decl_stmt|;
comment|/** 	 * msg_ctx - Callback context for wpa_msg() calls 	 */
name|void
modifier|*
name|msg_ctx
decl_stmt|;
comment|/** 	 * scard_ctx - Callback context for PC/SC scard_*() function calls 	 * 	 * This context can be updated with eapol_sm_register_scard_ctx(). 	 */
name|void
modifier|*
name|scard_ctx
decl_stmt|;
comment|/** 	 * eapol_send_ctx - Callback context for eapol_send() calls 	 */
name|void
modifier|*
name|eapol_send_ctx
decl_stmt|;
comment|/** 	 * eapol_done_cb - Function to be called at successful completion 	 * @ctx: Callback context (ctx) 	 * 	 * This function is called at the successful completion of EAPOL 	 * authentication. If dynamic WEP keys are used, this is called only 	 * after all the expected keys have been received. 	 */
name|void
function_decl|(
modifier|*
name|eapol_done_cb
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
comment|/** 	 * eapol_send - Send EAPOL packets 	 * @ctx: Callback context (eapol_send_ctx) 	 * @type: EAPOL type (IEEE802_1X_TYPE_*) 	 * @buf: Pointer to EAPOL payload 	 * @len: Length of the EAPOL payload 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|eapol_send
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|int
name|type
parameter_list|,
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
comment|/** 	 * set_wep_key - Configure WEP keys 	 * @ctx: Callback context (ctx) 	 * @unicast: Non-zero = unicast, 0 = multicast/broadcast key 	 * @keyidx: Key index (0..3) 	 * @key: WEP key 	 * @keylen: Length of the WEP key 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|set_wep_key
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|int
name|unicast
parameter_list|,
name|int
name|keyidx
parameter_list|,
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
name|size_t
name|keylen
parameter_list|)
function_decl|;
comment|/** 	 * set_config_blob - Set or add a named configuration blob 	 * @ctx: Callback context (ctx) 	 * @blob: New value for the blob 	 * 	 * Adds a new configuration blob or replaces the current value of an 	 * existing blob. 	 */
name|void
function_decl|(
modifier|*
name|set_config_blob
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|struct
name|wpa_config_blob
modifier|*
name|blob
parameter_list|)
function_decl|;
comment|/** 	 * get_config_blob - Get a named configuration blob 	 * @ctx: Callback context (ctx) 	 * @name: Name of the blob 	 * Returns: Pointer to blob data or %NULL if not found 	 */
specifier|const
name|struct
name|wpa_config_blob
modifier|*
function_decl|(
modifier|*
name|get_config_blob
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
comment|/** 	 * opensc_engine_path - Path to the OpenSSL engine for opensc 	 * 	 * This is an OpenSSL specific configuration option for loading OpenSC 	 * engine (engine_opensc.so); if %NULL, this engine is not loaded. 	 */
specifier|const
name|char
modifier|*
name|opensc_engine_path
decl_stmt|;
comment|/** 	 * pkcs11_engine_path - Path to the OpenSSL engine for PKCS#11 	 * 	 * This is an OpenSSL specific configuration option for loading PKCS#11 	 * engine (engine_pkcs11.so); if %NULL, this engine is not loaded. 	 */
specifier|const
name|char
modifier|*
name|pkcs11_engine_path
decl_stmt|;
comment|/** 	 * pkcs11_module_path - Path to the OpenSSL OpenSC/PKCS#11 module 	 * 	 * This is an OpenSSL specific configuration option for configuring 	 * path to OpenSC/PKCS#11 engine (opensc-pkcs11.so); if %NULL, this 	 * module is not loaded. 	 */
specifier|const
name|char
modifier|*
name|pkcs11_module_path
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|wpa_ssid
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|IEEE8021X_EAPOL
end_ifdef

begin_function_decl
name|struct
name|eapol_sm
modifier|*
name|eapol_sm_init
parameter_list|(
name|struct
name|eapol_ctx
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eapol_sm_deinit
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eapol_sm_step
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eapol_sm_get_status
parameter_list|(
name|struct
name|eapol_sm
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
name|eapol_sm_get_mib
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eapol_sm_configure
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|,
name|int
name|heldPeriod
parameter_list|,
name|int
name|authPeriod
parameter_list|,
name|int
name|startPeriod
parameter_list|,
name|int
name|maxStart
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eapol_sm_rx_eapol
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|,
specifier|const
name|u8
modifier|*
name|src
parameter_list|,
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eapol_sm_notify_tx_eapol_key
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eapol_sm_notify_portEnabled
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|,
name|Boolean
name|enabled
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eapol_sm_notify_portValid
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|,
name|Boolean
name|valid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eapol_sm_notify_eap_success
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|,
name|Boolean
name|success
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eapol_sm_notify_eap_fail
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|,
name|Boolean
name|fail
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eapol_sm_notify_config
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|,
name|struct
name|wpa_ssid
modifier|*
name|config
parameter_list|,
specifier|const
name|struct
name|eapol_config
modifier|*
name|conf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eapol_sm_get_key
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|,
name|u8
modifier|*
name|key
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eapol_sm_notify_logoff
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|,
name|Boolean
name|logoff
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eapol_sm_notify_cached
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eapol_sm_notify_pmkid_attempt
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|,
name|int
name|attempt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eapol_sm_register_scard_ctx
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|,
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eapol_sm_notify_portControl
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|,
name|PortControl
name|portControl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eapol_sm_notify_ctrl_attached
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eapol_sm_notify_ctrl_response
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eapol_sm_request_reauth
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eapol_sm_notify_lower_layer_success
parameter_list|(
name|struct
name|eapol_sm
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
comment|/* IEEE8021X_EAPOL */
end_comment

begin_function
specifier|static
specifier|inline
name|struct
name|eapol_sm
modifier|*
name|eapol_sm_init
parameter_list|(
name|struct
name|eapol_ctx
modifier|*
name|ctx
parameter_list|)
block|{
name|free
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
return|return
operator|(
expr|struct
name|eapol_sm
operator|*
operator|)
literal|1
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|eapol_sm_deinit
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|eapol_sm_step
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|int
name|eapol_sm_get_status
parameter_list|(
name|struct
name|eapol_sm
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
name|eapol_sm_get_mib
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
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
name|eapol_sm_configure
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|,
name|int
name|heldPeriod
parameter_list|,
name|int
name|authPeriod
parameter_list|,
name|int
name|startPeriod
parameter_list|,
name|int
name|maxStart
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|int
name|eapol_sm_rx_eapol
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|,
specifier|const
name|u8
modifier|*
name|src
parameter_list|,
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
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
name|eapol_sm_notify_tx_eapol_key
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|eapol_sm_notify_portEnabled
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|,
name|Boolean
name|enabled
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|eapol_sm_notify_portValid
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|,
name|Boolean
name|valid
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|eapol_sm_notify_eap_success
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|,
name|Boolean
name|success
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|eapol_sm_notify_eap_fail
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|,
name|Boolean
name|fail
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|eapol_sm_notify_config
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|,
name|struct
name|wpa_ssid
modifier|*
name|config
parameter_list|,
name|struct
name|eapol_config
modifier|*
name|conf
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|int
name|eapol_sm_get_key
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|,
name|u8
modifier|*
name|key
parameter_list|,
name|size_t
name|len
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
name|eapol_sm_notify_logoff
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|,
name|Boolean
name|logoff
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|eapol_sm_notify_cached
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|)
block|{ }
end_function

begin_define
define|#
directive|define
name|eapol_sm_notify_pmkid_attempt
parameter_list|(
name|sm
parameter_list|,
name|attempt
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|eapol_sm_register_scard_ctx
parameter_list|(
name|sm
parameter_list|,
name|ctx
parameter_list|)
value|do { } while (0)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|eapol_sm_notify_portControl
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|,
name|PortControl
name|portControl
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|eapol_sm_notify_ctrl_attached
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|eapol_sm_notify_ctrl_response
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|eapol_sm_request_reauth
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|eapol_sm_notify_lower_layer_success
parameter_list|(
name|struct
name|eapol_sm
modifier|*
name|sm
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IEEE8021X_EAPOL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EAPOL_SM_H */
end_comment

end_unit

