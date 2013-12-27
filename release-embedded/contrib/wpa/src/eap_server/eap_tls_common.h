begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * EAP-TLS/PEAP/TTLS/FAST server common functions  * Copyright (c) 2004-2009, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAP_TLS_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|EAP_TLS_COMMON_H
end_define

begin_comment
comment|/**  * struct eap_ssl_data - TLS data for EAP methods  */
end_comment

begin_struct
struct|struct
name|eap_ssl_data
block|{
comment|/** 	 * conn - TLS connection context data from tls_connection_init() 	 */
name|struct
name|tls_connection
modifier|*
name|conn
decl_stmt|;
comment|/** 	 * tls_out - TLS message to be sent out in fragments 	 */
name|struct
name|wpabuf
modifier|*
name|tls_out
decl_stmt|;
comment|/** 	 * tls_out_pos - The current position in the outgoing TLS message 	 */
name|size_t
name|tls_out_pos
decl_stmt|;
comment|/** 	 * tls_out_limit - Maximum fragment size for outgoing TLS messages 	 */
name|size_t
name|tls_out_limit
decl_stmt|;
comment|/** 	 * tls_in - Received TLS message buffer for re-assembly 	 */
name|struct
name|wpabuf
modifier|*
name|tls_in
decl_stmt|;
comment|/** 	 * phase2 - Whether this TLS connection is used in EAP phase 2 (tunnel) 	 */
name|int
name|phase2
decl_stmt|;
comment|/** 	 * eap - EAP state machine allocated with eap_server_sm_init() 	 */
name|struct
name|eap_sm
modifier|*
name|eap
decl_stmt|;
enum|enum
block|{
name|MSG
block|,
name|FRAG_ACK
block|,
name|WAIT_FRAG_ACK
block|}
name|state
enum|;
name|struct
name|wpabuf
name|tmpbuf
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* EAP TLS Flags */
end_comment

begin_define
define|#
directive|define
name|EAP_TLS_FLAGS_LENGTH_INCLUDED
value|0x80
end_define

begin_define
define|#
directive|define
name|EAP_TLS_FLAGS_MORE_FRAGMENTS
value|0x40
end_define

begin_define
define|#
directive|define
name|EAP_TLS_FLAGS_START
value|0x20
end_define

begin_define
define|#
directive|define
name|EAP_TLS_VERSION_MASK
value|0x07
end_define

begin_comment
comment|/* could be up to 128 bytes, but only the first 64 bytes are used */
end_comment

begin_define
define|#
directive|define
name|EAP_TLS_KEY_LEN
value|64
end_define

begin_comment
comment|/* dummy type used as a flag for UNAUTH-TLS */
end_comment

begin_define
define|#
directive|define
name|EAP_UNAUTH_TLS_TYPE
value|255
end_define

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|eap_tls_msg_alloc
parameter_list|(
name|EapType
name|type
parameter_list|,
name|size_t
name|payload_len
parameter_list|,
name|u8
name|code
parameter_list|,
name|u8
name|identifier
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_server_tls_ssl_init
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|,
name|struct
name|eap_ssl_data
modifier|*
name|data
parameter_list|,
name|int
name|verify_peer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_server_tls_ssl_deinit
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|,
name|struct
name|eap_ssl_data
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u8
modifier|*
name|eap_server_tls_derive_key
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|,
name|struct
name|eap_ssl_data
modifier|*
name|data
parameter_list|,
name|char
modifier|*
name|label
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|eap_server_tls_build_msg
parameter_list|(
name|struct
name|eap_ssl_data
modifier|*
name|data
parameter_list|,
name|int
name|eap_type
parameter_list|,
name|int
name|version
parameter_list|,
name|u8
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|eap_server_tls_build_ack
parameter_list|(
name|u8
name|id
parameter_list|,
name|int
name|eap_type
parameter_list|,
name|int
name|version
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_server_tls_phase1
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|,
name|struct
name|eap_ssl_data
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|eap_server_tls_encrypt
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|,
name|struct
name|eap_ssl_data
modifier|*
name|data
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|plain
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_server_tls_process
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|,
name|struct
name|eap_ssl_data
modifier|*
name|data
parameter_list|,
name|struct
name|wpabuf
modifier|*
name|respData
parameter_list|,
name|void
modifier|*
name|priv
parameter_list|,
name|int
name|eap_type
parameter_list|,
name|int
function_decl|(
modifier|*
name|proc_version
function_decl|)
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|,
name|void
modifier|*
name|priv
parameter_list|,
name|int
name|peer_version
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|proc_msg
function_decl|)
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|,
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|respData
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EAP_TLS_COMMON_H */
end_comment

end_unit

