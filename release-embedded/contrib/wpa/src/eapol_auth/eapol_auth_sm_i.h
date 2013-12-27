begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * IEEE 802.1X-2004 Authenticator - EAPOL state machine (internal definitions)  * Copyright (c) 2002-2009, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAPOL_AUTH_SM_I_H
end_ifndef

begin_define
define|#
directive|define
name|EAPOL_AUTH_SM_I_H
end_define

begin_include
include|#
directive|include
file|"common/defs.h"
end_include

begin_include
include|#
directive|include
file|"radius/radius.h"
end_include

begin_comment
comment|/* IEEE Std 802.1X-2004, Ch. 8.2 */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ForceUnauthorized
init|=
literal|1
block|,
name|ForceAuthorized
init|=
literal|3
block|,
name|Auto
init|=
literal|2
block|}
name|PortTypes
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|Unauthorized
init|=
literal|2
block|,
name|Authorized
init|=
literal|1
block|}
name|PortState
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|Both
init|=
literal|0
block|,
name|In
init|=
literal|1
block|}
name|ControlledDirection
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|Counter
typedef|;
end_typedef

begin_comment
comment|/**  * struct eapol_authenticator - Global EAPOL authenticator data  */
end_comment

begin_struct
struct|struct
name|eapol_authenticator
block|{
name|struct
name|eapol_auth_config
name|conf
decl_stmt|;
name|struct
name|eapol_auth_cb
name|cb
decl_stmt|;
name|u8
modifier|*
name|default_wep_key
decl_stmt|;
name|u8
name|default_wep_key_idx
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct eapol_state_machine - Per-Supplicant Authenticator state machines  */
end_comment

begin_struct
struct|struct
name|eapol_state_machine
block|{
comment|/* timers */
name|int
name|aWhile
decl_stmt|;
name|int
name|quietWhile
decl_stmt|;
name|int
name|reAuthWhen
decl_stmt|;
comment|/* global variables */
name|Boolean
name|authAbort
decl_stmt|;
name|Boolean
name|authFail
decl_stmt|;
name|PortState
name|authPortStatus
decl_stmt|;
name|Boolean
name|authStart
decl_stmt|;
name|Boolean
name|authTimeout
decl_stmt|;
name|Boolean
name|authSuccess
decl_stmt|;
name|Boolean
name|eapolEap
decl_stmt|;
name|Boolean
name|initialize
decl_stmt|;
name|Boolean
name|keyDone
decl_stmt|;
name|Boolean
name|keyRun
decl_stmt|;
name|Boolean
name|keyTxEnabled
decl_stmt|;
name|PortTypes
name|portControl
decl_stmt|;
name|Boolean
name|portValid
decl_stmt|;
name|Boolean
name|reAuthenticate
decl_stmt|;
comment|/* Port Timers state machine */
comment|/* 'Boolean tick' implicitly handled as registered timeout */
comment|/* Authenticator PAE state machine */
enum|enum
block|{
name|AUTH_PAE_INITIALIZE
block|,
name|AUTH_PAE_DISCONNECTED
block|,
name|AUTH_PAE_CONNECTING
block|,
name|AUTH_PAE_AUTHENTICATING
block|,
name|AUTH_PAE_AUTHENTICATED
block|,
name|AUTH_PAE_ABORTING
block|,
name|AUTH_PAE_HELD
block|,
name|AUTH_PAE_FORCE_AUTH
block|,
name|AUTH_PAE_FORCE_UNAUTH
block|,
name|AUTH_PAE_RESTART
block|}
name|auth_pae_state
enum|;
comment|/* variables */
name|Boolean
name|eapolLogoff
decl_stmt|;
name|Boolean
name|eapolStart
decl_stmt|;
name|PortTypes
name|portMode
decl_stmt|;
name|unsigned
name|int
name|reAuthCount
decl_stmt|;
comment|/* constants */
name|unsigned
name|int
name|quietPeriod
decl_stmt|;
comment|/* default 60; 0..65535 */
define|#
directive|define
name|AUTH_PAE_DEFAULT_quietPeriod
value|60
name|unsigned
name|int
name|reAuthMax
decl_stmt|;
comment|/* default 2 */
define|#
directive|define
name|AUTH_PAE_DEFAULT_reAuthMax
value|2
comment|/* counters */
name|Counter
name|authEntersConnecting
decl_stmt|;
name|Counter
name|authEapLogoffsWhileConnecting
decl_stmt|;
name|Counter
name|authEntersAuthenticating
decl_stmt|;
name|Counter
name|authAuthSuccessesWhileAuthenticating
decl_stmt|;
name|Counter
name|authAuthTimeoutsWhileAuthenticating
decl_stmt|;
name|Counter
name|authAuthFailWhileAuthenticating
decl_stmt|;
name|Counter
name|authAuthEapStartsWhileAuthenticating
decl_stmt|;
name|Counter
name|authAuthEapLogoffWhileAuthenticating
decl_stmt|;
name|Counter
name|authAuthReauthsWhileAuthenticated
decl_stmt|;
name|Counter
name|authAuthEapStartsWhileAuthenticated
decl_stmt|;
name|Counter
name|authAuthEapLogoffWhileAuthenticated
decl_stmt|;
comment|/* Backend Authentication state machine */
enum|enum
block|{
name|BE_AUTH_REQUEST
block|,
name|BE_AUTH_RESPONSE
block|,
name|BE_AUTH_SUCCESS
block|,
name|BE_AUTH_FAIL
block|,
name|BE_AUTH_TIMEOUT
block|,
name|BE_AUTH_IDLE
block|,
name|BE_AUTH_INITIALIZE
block|,
name|BE_AUTH_IGNORE
block|}
name|be_auth_state
enum|;
comment|/* constants */
name|unsigned
name|int
name|serverTimeout
decl_stmt|;
comment|/* default 30; 1..X */
define|#
directive|define
name|BE_AUTH_DEFAULT_serverTimeout
value|30
comment|/* counters */
name|Counter
name|backendResponses
decl_stmt|;
name|Counter
name|backendAccessChallenges
decl_stmt|;
name|Counter
name|backendOtherRequestsToSupplicant
decl_stmt|;
name|Counter
name|backendAuthSuccesses
decl_stmt|;
name|Counter
name|backendAuthFails
decl_stmt|;
comment|/* Reauthentication Timer state machine */
enum|enum
block|{
name|REAUTH_TIMER_INITIALIZE
block|,
name|REAUTH_TIMER_REAUTHENTICATE
block|}
name|reauth_timer_state
enum|;
comment|/* constants */
name|unsigned
name|int
name|reAuthPeriod
decl_stmt|;
comment|/* default 3600 s */
name|Boolean
name|reAuthEnabled
decl_stmt|;
comment|/* Authenticator Key Transmit state machine */
enum|enum
block|{
name|AUTH_KEY_TX_NO_KEY_TRANSMIT
block|,
name|AUTH_KEY_TX_KEY_TRANSMIT
block|}
name|auth_key_tx_state
enum|;
comment|/* Key Receive state machine */
enum|enum
block|{
name|KEY_RX_NO_KEY_RECEIVE
block|,
name|KEY_RX_KEY_RECEIVE
block|}
name|key_rx_state
enum|;
comment|/* variables */
name|Boolean
name|rxKey
decl_stmt|;
comment|/* Controlled Directions state machine */
enum|enum
block|{
name|CTRL_DIR_FORCE_BOTH
block|,
name|CTRL_DIR_IN_OR_BOTH
block|}
name|ctrl_dir_state
enum|;
comment|/* variables */
name|ControlledDirection
name|adminControlledDirections
decl_stmt|;
name|ControlledDirection
name|operControlledDirections
decl_stmt|;
name|Boolean
name|operEdge
decl_stmt|;
comment|/* Authenticator Statistics Table */
name|Counter
name|dot1xAuthEapolFramesRx
decl_stmt|;
name|Counter
name|dot1xAuthEapolFramesTx
decl_stmt|;
name|Counter
name|dot1xAuthEapolStartFramesRx
decl_stmt|;
name|Counter
name|dot1xAuthEapolLogoffFramesRx
decl_stmt|;
name|Counter
name|dot1xAuthEapolRespIdFramesRx
decl_stmt|;
name|Counter
name|dot1xAuthEapolRespFramesRx
decl_stmt|;
name|Counter
name|dot1xAuthEapolReqIdFramesTx
decl_stmt|;
name|Counter
name|dot1xAuthEapolReqFramesTx
decl_stmt|;
name|Counter
name|dot1xAuthInvalidEapolFramesRx
decl_stmt|;
name|Counter
name|dot1xAuthEapLengthErrorFramesRx
decl_stmt|;
name|Counter
name|dot1xAuthLastEapolFrameVersion
decl_stmt|;
comment|/* Other variables - not defined in IEEE 802.1X */
name|u8
name|addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
comment|/* Supplicant address */
name|int
name|flags
decl_stmt|;
comment|/* EAPOL_SM_* */
comment|/* EAPOL/AAA<-> EAP full authenticator interface */
name|struct
name|eap_eapol_interface
modifier|*
name|eap_if
decl_stmt|;
name|int
name|radius_identifier
decl_stmt|;
comment|/* TODO: check when the last messages can be released */
name|struct
name|radius_msg
modifier|*
name|last_recv_radius
decl_stmt|;
name|u8
name|last_eap_id
decl_stmt|;
comment|/* last used EAP Identifier */
name|u8
modifier|*
name|identity
decl_stmt|;
name|size_t
name|identity_len
decl_stmt|;
name|u8
name|eap_type_authsrv
decl_stmt|;
comment|/* EAP type of the last EAP packet from 			      * Authentication server */
name|u8
name|eap_type_supp
decl_stmt|;
comment|/* EAP type of the last EAP packet from Supplicant */
name|struct
name|radius_class_data
name|radius_class
decl_stmt|;
name|struct
name|wpabuf
modifier|*
name|radius_cui
decl_stmt|;
comment|/* Chargeable-User-Identity */
comment|/* Keys for encrypting and signing EAPOL-Key frames */
name|u8
modifier|*
name|eapol_key_sign
decl_stmt|;
name|size_t
name|eapol_key_sign_len
decl_stmt|;
name|u8
modifier|*
name|eapol_key_crypt
decl_stmt|;
name|size_t
name|eapol_key_crypt_len
decl_stmt|;
name|struct
name|eap_sm
modifier|*
name|eap
decl_stmt|;
name|Boolean
name|initializing
decl_stmt|;
comment|/* in process of initializing state machines */
name|Boolean
name|changed
decl_stmt|;
name|struct
name|eapol_authenticator
modifier|*
name|eapol
decl_stmt|;
name|void
modifier|*
name|sta
decl_stmt|;
comment|/* station context pointer to use in callbacks */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EAPOL_AUTH_SM_I_H */
end_comment

end_unit

