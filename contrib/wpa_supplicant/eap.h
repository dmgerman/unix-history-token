begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant / EAP state machine functions (RFC 4137)  * Copyright (c) 2004-2005, Jouni Malinen<jkmaline@cc.hut.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAP_H
end_ifndef

begin_define
define|#
directive|define
name|EAP_H
end_define

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"eap_defs.h"
end_include

begin_struct_decl
struct_decl|struct
name|eap_sm
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|wpa_ssid
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|wpa_config_blob
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|IEEE8021X_EAPOL
end_ifdef

begin_comment
comment|/**  * enum eapol_bool_var - EAPOL boolean state variables for EAP state machine  *  * These variables are used in the interface between EAP peer state machine and  * lower layer. These are defined in RFC 4137, Sect. 4.1. Lower layer code is  * expected to maintain these variables and register a callback functions for  * EAP state machine to get and set the variables.  */
end_comment

begin_enum
enum|enum
name|eapol_bool_var
block|{
comment|/** 	 * EAPOL_eapSuccess - EAP SUCCESS state reached 	 * 	 * EAP state machine reads and writes this value. 	 */
name|EAPOL_eapSuccess
block|,
comment|/** 	 * EAPOL_eapRestart - Lower layer request to restart authentication 	 * 	 * Set to TRUE in lower layer, FALSE in EAP state machine. 	 */
name|EAPOL_eapRestart
block|,
comment|/** 	 * EAPOL_eapFail - EAP FAILURE state reached 	 * 	 * EAP state machine writes this value. 	 */
name|EAPOL_eapFail
block|,
comment|/** 	 * EAPOL_eapResp - Response to send 	 * 	 * Set to TRUE in EAP state machine, FALSE in lower layer. 	 */
name|EAPOL_eapResp
block|,
comment|/** 	 * EAPOL_eapNoResp - Request has been process; no response to send 	 * 	 * Set to TRUE in EAP state machine, FALSE in lower layer. 	 */
name|EAPOL_eapNoResp
block|,
comment|/** 	 * EAPOL_eapReq - EAP request available from lower layer 	 * 	 * Set to TRUE in lower layer, FALSE in EAP state machine. 	 */
name|EAPOL_eapReq
block|,
comment|/** 	 * EAPOL_portEnabled - Lower layer is ready for communication 	 * 	 * EAP state machines reads this value. 	 */
name|EAPOL_portEnabled
block|,
comment|/** 	 * EAPOL_altAccept - Alternate indication of success (RFC3748) 	 * 	 * EAP state machines reads this value. 	 */
name|EAPOL_altAccept
block|,
comment|/** 	 * EAPOL_altReject - Alternate indication of failure (RFC3748) 	 * 	 * EAP state machines reads this value. 	 */
name|EAPOL_altReject
block|}
enum|;
end_enum

begin_comment
comment|/**  * enum eapol_int_var - EAPOL integer state variables for EAP state machine  *  * These variables are used in the interface between EAP peer state machine and  * lower layer. These are defined in RFC 4137, Sect. 4.1. Lower layer code is  * expected to maintain these variables and register a callback functions for  * EAP state machine to get and set the variables.  */
end_comment

begin_enum
enum|enum
name|eapol_int_var
block|{
comment|/** 	 * EAPOL_idleWhile - Outside time for EAP peer timeout 	 * 	 * This integer variable is used to provide an outside timer that the 	 * external (to EAP state machine) code must decrement by one every 	 * second until the value reaches zero. This is used in the same way as 	 * EAPOL state machine timers. EAP state machine reads and writes this 	 * value. 	 */
name|EAPOL_idleWhile
block|}
enum|;
end_enum

begin_comment
comment|/**  * struct eapol_callbacks - Callback functions from EAP to lower layer  *  * This structure defines the callback functions that EAP state machine  * requires from the lower layer (usually EAPOL state machine) for updating  * state variables and requesting information. eapol_ctx from eap_sm_init()  * call will be used as the ctx parameter for these callback functions.  */
end_comment

begin_struct
struct|struct
name|eapol_callbacks
block|{
comment|/** 	 * get_config - Get pointer to the current network configuration 	 * @ctx: eapol_ctx from eap_sm_init() call 	 */
name|struct
name|wpa_ssid
modifier|*
function_decl|(
modifier|*
name|get_config
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
comment|/** 	 * get_bool - Get a boolean EAPOL state variable 	 * @variable: EAPOL boolean variable to get 	 * Returns: Value of the EAPOL variable 	 */
name|Boolean
function_decl|(
modifier|*
name|get_bool
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|enum
name|eapol_bool_var
name|variable
parameter_list|)
function_decl|;
comment|/** 	 * set_bool - Set a boolean EAPOL state variable 	 * @ctx: eapol_ctx from eap_sm_init() call 	 * @variable: EAPOL boolean variable to set 	 * @value: Value for the EAPOL variable 	 */
name|void
function_decl|(
modifier|*
name|set_bool
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|enum
name|eapol_bool_var
name|variable
parameter_list|,
name|Boolean
name|value
parameter_list|)
function_decl|;
comment|/** 	 * get_int - Get an integer EAPOL state variable 	 * @ctx: eapol_ctx from eap_sm_init() call 	 * @variable: EAPOL integer variable to get 	 * Returns: Value of the EAPOL variable 	 */
name|unsigned
name|int
function_decl|(
modifier|*
name|get_int
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|enum
name|eapol_int_var
name|variable
parameter_list|)
function_decl|;
comment|/** 	 * set_int - Set an integer EAPOL state variable 	 * @ctx: eapol_ctx from eap_sm_init() call 	 * @variable: EAPOL integer variable to set 	 * @value: Value for the EAPOL variable 	 */
name|void
function_decl|(
modifier|*
name|set_int
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|enum
name|eapol_int_var
name|variable
parameter_list|,
name|unsigned
name|int
name|value
parameter_list|)
function_decl|;
comment|/** 	 * get_eapReqData - Get EAP-Request data 	 * @ctx: eapol_ctx from eap_sm_init() call 	 * @len: Pointer to variable that will be set to eapReqDataLen 	 * Returns: Reference to eapReqData (EAP state machine will not free 	 * this) or %NULL if eapReqData not available. 	 */
name|u8
modifier|*
function_decl|(
modifier|*
name|get_eapReqData
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|)
function_decl|;
comment|/** 	 * set_config_blob - Set named configuration blob 	 * @ctx: eapol_ctx from eap_sm_init() call 	 * @blob: New value for the blob 	 * 	 * Adds a new configuration blob or replaces the current value of an 	 * existing blob. 	 */
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
comment|/** 	 * get_config_blob - Get a named configuration blob 	 * @ctx: eapol_ctx from eap_sm_init() call 	 * @name: Name of the blob 	 * Returns: Pointer to blob data or %NULL if not found 	 */
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
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct eap_config - Configuration for EAP state machine  */
end_comment

begin_struct
struct|struct
name|eap_config
block|{
comment|/** 	 * opensc_engine_path - OpenSC engine for OpenSSL engine support 	 * 	 * Usually, path to engine_opensc.so. 	 */
specifier|const
name|char
modifier|*
name|opensc_engine_path
decl_stmt|;
comment|/** 	 * pkcs11_engine_path - PKCS#11 engine for OpenSSL engine support 	 * 	 * Usually, path to engine_pkcs11.so. 	 */
specifier|const
name|char
modifier|*
name|pkcs11_engine_path
decl_stmt|;
comment|/** 	 * pkcs11_module_path - OpenSC PKCS#11 module for OpenSSL engine 	 * 	 * Usually, path to opensc-pkcs11.so. 	 */
specifier|const
name|char
modifier|*
name|pkcs11_module_path
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|eap_sm
modifier|*
name|eap_sm_init
parameter_list|(
name|void
modifier|*
name|eapol_ctx
parameter_list|,
name|struct
name|eapol_callbacks
modifier|*
name|eapol_cb
parameter_list|,
name|void
modifier|*
name|msg_ctx
parameter_list|,
name|struct
name|eap_config
modifier|*
name|conf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_sm_deinit
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_sm_step
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_sm_abort
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_sm_get_status
parameter_list|(
name|struct
name|eap_sm
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
name|u8
modifier|*
name|eap_sm_buildIdentity
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|,
name|int
name|id
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|,
name|int
name|encrypted
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|eap_method
modifier|*
name|eap_sm_get_eap_methods
parameter_list|(
name|int
name|method
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_sm_request_identity
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|,
name|struct
name|wpa_ssid
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_sm_request_password
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|,
name|struct
name|wpa_ssid
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_sm_request_new_password
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|,
name|struct
name|wpa_ssid
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_sm_request_pin
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|,
name|struct
name|wpa_ssid
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_sm_request_otp
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|,
name|struct
name|wpa_ssid
modifier|*
name|config
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
name|size_t
name|msg_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_sm_request_passphrase
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|,
name|struct
name|wpa_ssid
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_sm_notify_ctrl_attached
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u8
name|eap_get_type
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|eap_get_name
parameter_list|(
name|EapType
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|eap_get_names
parameter_list|(
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
name|u8
name|eap_get_phase2_type
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u8
modifier|*
name|eap_get_phase2_types
parameter_list|(
name|struct
name|wpa_ssid
modifier|*
name|config
parameter_list|,
name|size_t
modifier|*
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_set_fast_reauth
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|,
name|int
name|enabled
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_set_workaround
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|,
name|unsigned
name|int
name|workaround
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_set_force_disabled
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|,
name|int
name|disabled
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpa_ssid
modifier|*
name|eap_get_config
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_key_available
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_notify_success
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_notify_lower_layer_success
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|u8
modifier|*
name|eap_get_eapKeyData
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u8
modifier|*
name|eap_get_eapRespData
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_register_scard_ctx
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|,
name|void
modifier|*
name|ctx
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
name|u8
name|eap_get_type
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
return|return
name|EAP_TYPE_NONE
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
specifier|const
name|char
modifier|*
name|eap_get_name
parameter_list|(
name|EapType
name|type
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
name|size_t
name|eap_get_names
parameter_list|(
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
comment|/* EAP_H */
end_comment

end_unit

