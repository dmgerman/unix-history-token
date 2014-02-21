begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * RADIUS client  * Copyright (c) 2002-2009, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RADIUS_CLIENT_H
end_ifndef

begin_define
define|#
directive|define
name|RADIUS_CLIENT_H
end_define

begin_include
include|#
directive|include
file|"ip_addr.h"
end_include

begin_struct_decl
struct_decl|struct
name|radius_msg
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * struct hostapd_radius_server - RADIUS server information for RADIUS client  *  * This structure contains information about a RADIUS server. The values are  * mainly for MIB information. The MIB variable prefix (radiusAuth or  * radiusAcc) depends on whether this is an authentication or accounting  * server.  *  * radiusAuthClientPendingRequests (or radiusAccClientPendingRequests) is the  * number struct radius_client_data::msgs for matching msg_type.  */
end_comment

begin_struct
struct|struct
name|hostapd_radius_server
block|{
comment|/** 	 * addr - radiusAuthServerAddress or radiusAccServerAddress 	 */
name|struct
name|hostapd_ip_addr
name|addr
decl_stmt|;
comment|/** 	 * port - radiusAuthClientServerPortNumber or radiusAccClientServerPortNumber 	 */
name|int
name|port
decl_stmt|;
comment|/** 	 * shared_secret - Shared secret for authenticating RADIUS messages 	 */
name|u8
modifier|*
name|shared_secret
decl_stmt|;
comment|/** 	 * shared_secret_len - Length of shared_secret in octets 	 */
name|size_t
name|shared_secret_len
decl_stmt|;
comment|/* Dynamic (not from configuration file) MIB data */
comment|/** 	 * index - radiusAuthServerIndex or radiusAccServerIndex 	 */
name|int
name|index
decl_stmt|;
comment|/** 	 * round_trip_time - radiusAuthClientRoundTripTime or radiusAccClientRoundTripTime 	 * Round-trip time in hundredths of a second. 	 */
name|int
name|round_trip_time
decl_stmt|;
comment|/** 	 * requests - radiusAuthClientAccessRequests or radiusAccClientRequests 	 */
name|u32
name|requests
decl_stmt|;
comment|/** 	 * retransmissions - radiusAuthClientAccessRetransmissions or radiusAccClientRetransmissions 	 */
name|u32
name|retransmissions
decl_stmt|;
comment|/** 	 * access_accepts - radiusAuthClientAccessAccepts 	 */
name|u32
name|access_accepts
decl_stmt|;
comment|/** 	 * access_rejects - radiusAuthClientAccessRejects 	 */
name|u32
name|access_rejects
decl_stmt|;
comment|/** 	 * access_challenges - radiusAuthClientAccessChallenges 	 */
name|u32
name|access_challenges
decl_stmt|;
comment|/** 	 * responses - radiusAccClientResponses 	 */
name|u32
name|responses
decl_stmt|;
comment|/** 	 * malformed_responses - radiusAuthClientMalformedAccessResponses or radiusAccClientMalformedResponses 	 */
name|u32
name|malformed_responses
decl_stmt|;
comment|/** 	 * bad_authenticators - radiusAuthClientBadAuthenticators or radiusAccClientBadAuthenticators 	 */
name|u32
name|bad_authenticators
decl_stmt|;
comment|/** 	 * timeouts - radiusAuthClientTimeouts or radiusAccClientTimeouts 	 */
name|u32
name|timeouts
decl_stmt|;
comment|/** 	 * unknown_types - radiusAuthClientUnknownTypes or radiusAccClientUnknownTypes 	 */
name|u32
name|unknown_types
decl_stmt|;
comment|/** 	 * packets_dropped - radiusAuthClientPacketsDropped or radiusAccClientPacketsDropped 	 */
name|u32
name|packets_dropped
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct hostapd_radius_servers - RADIUS servers for RADIUS client  */
end_comment

begin_struct
struct|struct
name|hostapd_radius_servers
block|{
comment|/** 	 * auth_servers - RADIUS Authentication servers in priority order 	 */
name|struct
name|hostapd_radius_server
modifier|*
name|auth_servers
decl_stmt|;
comment|/** 	 * num_auth_servers - Number of auth_servers entries 	 */
name|int
name|num_auth_servers
decl_stmt|;
comment|/** 	 * auth_server - The current Authentication server 	 */
name|struct
name|hostapd_radius_server
modifier|*
name|auth_server
decl_stmt|;
comment|/** 	 * acct_servers - RADIUS Accounting servers in priority order 	 */
name|struct
name|hostapd_radius_server
modifier|*
name|acct_servers
decl_stmt|;
comment|/** 	 * num_acct_servers - Number of acct_servers entries 	 */
name|int
name|num_acct_servers
decl_stmt|;
comment|/** 	 * acct_server - The current Accounting server 	 */
name|struct
name|hostapd_radius_server
modifier|*
name|acct_server
decl_stmt|;
comment|/** 	 * retry_primary_interval - Retry interval for trying primary server 	 * 	 * This specifies a retry interval in sexconds for trying to return to 	 * the primary RADIUS server. RADIUS client code will automatically try 	 * to use the next server when the current server is not replying to 	 * requests. If this interval is set (non-zero), the primary server 	 * will be retried after the specified number of seconds has passed 	 * even if the current used secondary server is still working. 	 */
name|int
name|retry_primary_interval
decl_stmt|;
comment|/** 	 * msg_dumps - Whether RADIUS message details are shown in stdout 	 */
name|int
name|msg_dumps
decl_stmt|;
comment|/** 	 * client_addr - Client (local) address to use if force_client_addr 	 */
name|struct
name|hostapd_ip_addr
name|client_addr
decl_stmt|;
comment|/** 	 * force_client_addr - Whether to force client (local) address 	 */
name|int
name|force_client_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * RadiusType - RADIUS server type for RADIUS client  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/** 	 * RADIUS authentication 	 */
name|RADIUS_AUTH
block|,
comment|/** 	 * RADIUS_ACCT - RADIUS accounting 	 */
name|RADIUS_ACCT
block|,
comment|/** 	 * RADIUS_ACCT_INTERIM - RADIUS interim accounting message 	 * 	 * Used only with radius_client_send(). This behaves just like 	 * RADIUS_ACCT, but removes any pending interim RADIUS Accounting 	 * messages for the same STA before sending the new interim update. 	 */
name|RADIUS_ACCT_INTERIM
block|}
name|RadiusType
typedef|;
end_typedef

begin_comment
comment|/**  * RadiusRxResult - RADIUS client RX handler result  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/** 	 * RADIUS_RX_PROCESSED - Message processed 	 * 	 * This stops handler calls and frees the message. 	 */
name|RADIUS_RX_PROCESSED
block|,
comment|/** 	 * RADIUS_RX_QUEUED - Message has been queued 	 * 	 * This stops handler calls, but does not free the message; the handler 	 * that returned this is responsible for eventually freeing the 	 * message. 	 */
name|RADIUS_RX_QUEUED
block|,
comment|/** 	 * RADIUS_RX_UNKNOWN - Message is not for this handler 	 */
name|RADIUS_RX_UNKNOWN
block|,
comment|/** 	 * RADIUS_RX_INVALID_AUTHENTICATOR - Message has invalid Authenticator 	 */
name|RADIUS_RX_INVALID_AUTHENTICATOR
block|}
name|RadiusRxResult
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|radius_client_data
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|radius_client_register
parameter_list|(
name|struct
name|radius_client_data
modifier|*
name|radius
parameter_list|,
name|RadiusType
name|msg_type
parameter_list|,
name|RadiusRxResult
function_decl|(
modifier|*
name|handler
function_decl|)
parameter_list|(
name|struct
name|radius_msg
modifier|*
name|msg
parameter_list|,
name|struct
name|radius_msg
modifier|*
name|req
parameter_list|,
specifier|const
name|u8
modifier|*
name|shared_secret
parameter_list|,
name|size_t
name|shared_secret_len
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|radius_client_send
parameter_list|(
name|struct
name|radius_client_data
modifier|*
name|radius
parameter_list|,
name|struct
name|radius_msg
modifier|*
name|msg
parameter_list|,
name|RadiusType
name|msg_type
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u8
name|radius_client_get_id
parameter_list|(
name|struct
name|radius_client_data
modifier|*
name|radius
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|radius_client_flush
parameter_list|(
name|struct
name|radius_client_data
modifier|*
name|radius
parameter_list|,
name|int
name|only_auth
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|radius_client_data
modifier|*
name|radius_client_init
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|struct
name|hostapd_radius_servers
modifier|*
name|conf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|radius_client_deinit
parameter_list|(
name|struct
name|radius_client_data
modifier|*
name|radius
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|radius_client_flush_auth
parameter_list|(
name|struct
name|radius_client_data
modifier|*
name|radius
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|radius_client_get_mib
parameter_list|(
name|struct
name|radius_client_data
modifier|*
name|radius
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
name|radius_client_reconfig
parameter_list|(
name|struct
name|radius_client_data
modifier|*
name|radius
parameter_list|,
name|struct
name|hostapd_radius_servers
modifier|*
name|conf
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RADIUS_CLIENT_H */
end_comment

end_unit

