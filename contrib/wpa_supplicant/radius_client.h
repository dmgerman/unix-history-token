begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
file|"config_types.h"
end_include

begin_struct_decl
struct_decl|struct
name|radius_msg
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|hostapd_radius_server
block|{
comment|/* MIB prefix for shared variables: 	 * @ = radiusAuth or radiusAcc depending on the type of the server */
name|struct
name|hostapd_ip_addr
name|addr
decl_stmt|;
comment|/* @ServerAddress */
name|int
name|port
decl_stmt|;
comment|/* @ClientServerPortNumber */
name|u8
modifier|*
name|shared_secret
decl_stmt|;
name|size_t
name|shared_secret_len
decl_stmt|;
comment|/* Dynamic (not from configuration file) MIB data */
name|int
name|index
decl_stmt|;
comment|/* @ServerIndex */
name|int
name|round_trip_time
decl_stmt|;
comment|/* @ClientRoundTripTime; in hundredths of a 			      * second */
name|u32
name|requests
decl_stmt|;
comment|/* @Client{Access,}Requests */
name|u32
name|retransmissions
decl_stmt|;
comment|/* @Client{Access,}Retransmissions */
name|u32
name|access_accepts
decl_stmt|;
comment|/* radiusAuthClientAccessAccepts */
name|u32
name|access_rejects
decl_stmt|;
comment|/* radiusAuthClientAccessRejects */
name|u32
name|access_challenges
decl_stmt|;
comment|/* radiusAuthClientAccessChallenges */
name|u32
name|responses
decl_stmt|;
comment|/* radiusAccClientResponses */
name|u32
name|malformed_responses
decl_stmt|;
comment|/* @ClientMalformed{Access,}Responses */
name|u32
name|bad_authenticators
decl_stmt|;
comment|/* @ClientBadAuthenticators */
name|u32
name|timeouts
decl_stmt|;
comment|/* @ClientTimeouts */
name|u32
name|unknown_types
decl_stmt|;
comment|/* @ClientUnknownTypes */
name|u32
name|packets_dropped
decl_stmt|;
comment|/* @ClientPacketsDropped */
comment|/* @ClientPendingRequests: length of hapd->radius->msgs for matching 	 * msg_type */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hostapd_radius_servers
block|{
comment|/* RADIUS Authentication and Accounting servers in priority order */
name|struct
name|hostapd_radius_server
modifier|*
name|auth_servers
decl_stmt|,
modifier|*
name|auth_server
decl_stmt|;
name|int
name|num_auth_servers
decl_stmt|;
name|struct
name|hostapd_radius_server
modifier|*
name|acct_servers
decl_stmt|,
modifier|*
name|acct_server
decl_stmt|;
name|int
name|num_acct_servers
decl_stmt|;
name|int
name|retry_primary_interval
decl_stmt|;
name|int
name|acct_interim_interval
decl_stmt|;
name|int
name|msg_dumps
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|RADIUS_AUTH
block|,
name|RADIUS_ACCT
block|,
name|RADIUS_ACCT_INTERIM
comment|/* used only with radius_client_send(); just like 			     * RADIUS_ACCT, but removes any pending interim 			     * RADIUS Accounting packages for the same STA 			     * before sending the new interim update */
block|}
name|RadiusType
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|RADIUS_RX_PROCESSED
block|,
name|RADIUS_RX_QUEUED
block|,
name|RADIUS_RX_UNKNOWN
block|,
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RADIUS_CLIENT_H */
end_comment

end_unit

