begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * SSL/TLS interface definition  * Copyright (c) 2004-2010, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TLS_H
end_ifndef

begin_define
define|#
directive|define
name|TLS_H
end_define

begin_struct_decl
struct_decl|struct
name|tls_connection
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|tls_keys
block|{
specifier|const
name|u8
modifier|*
name|master_key
decl_stmt|;
comment|/* TLS master secret */
name|size_t
name|master_key_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|client_random
decl_stmt|;
name|size_t
name|client_random_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|server_random
decl_stmt|;
name|size_t
name|server_random_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|inner_secret
decl_stmt|;
comment|/* TLS/IA inner secret */
name|size_t
name|inner_secret_len
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|tls_event
block|{
name|TLS_CERT_CHAIN_FAILURE
block|,
name|TLS_PEER_CERTIFICATE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Note: These are used as identifier with external programs and as such, the  * values must not be changed.  */
end_comment

begin_enum
enum|enum
name|tls_fail_reason
block|{
name|TLS_FAIL_UNSPECIFIED
init|=
literal|0
block|,
name|TLS_FAIL_UNTRUSTED
init|=
literal|1
block|,
name|TLS_FAIL_REVOKED
init|=
literal|2
block|,
name|TLS_FAIL_NOT_YET_VALID
init|=
literal|3
block|,
name|TLS_FAIL_EXPIRED
init|=
literal|4
block|,
name|TLS_FAIL_SUBJECT_MISMATCH
init|=
literal|5
block|,
name|TLS_FAIL_ALTSUBJECT_MISMATCH
init|=
literal|6
block|,
name|TLS_FAIL_BAD_CERTIFICATE
init|=
literal|7
block|,
name|TLS_FAIL_SERVER_CHAIN_PROBE
init|=
literal|8
block|}
enum|;
end_enum

begin_union
union|union
name|tls_event_data
block|{
struct|struct
block|{
name|int
name|depth
decl_stmt|;
specifier|const
name|char
modifier|*
name|subject
decl_stmt|;
name|enum
name|tls_fail_reason
name|reason
decl_stmt|;
specifier|const
name|char
modifier|*
name|reason_txt
decl_stmt|;
specifier|const
name|struct
name|wpabuf
modifier|*
name|cert
decl_stmt|;
block|}
name|cert_fail
struct|;
struct|struct
block|{
name|int
name|depth
decl_stmt|;
specifier|const
name|char
modifier|*
name|subject
decl_stmt|;
specifier|const
name|struct
name|wpabuf
modifier|*
name|cert
decl_stmt|;
specifier|const
name|u8
modifier|*
name|hash
decl_stmt|;
name|size_t
name|hash_len
decl_stmt|;
block|}
name|peer_cert
struct|;
block|}
union|;
end_union

begin_struct
struct|struct
name|tls_config
block|{
specifier|const
name|char
modifier|*
name|opensc_engine_path
decl_stmt|;
specifier|const
name|char
modifier|*
name|pkcs11_engine_path
decl_stmt|;
specifier|const
name|char
modifier|*
name|pkcs11_module_path
decl_stmt|;
name|int
name|fips_mode
decl_stmt|;
name|void
function_decl|(
modifier|*
name|event_cb
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|enum
name|tls_event
name|ev
parameter_list|,
name|union
name|tls_event_data
modifier|*
name|data
parameter_list|)
function_decl|;
name|void
modifier|*
name|cb_ctx
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TLS_CONN_ALLOW_SIGN_RSA_MD5
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|TLS_CONN_DISABLE_TIME_CHECKS
value|BIT(1)
end_define

begin_comment
comment|/**  * struct tls_connection_params - Parameters for TLS connection  * @ca_cert: File or reference name for CA X.509 certificate in PEM or DER  * format  * @ca_cert_blob: ca_cert as inlined data or %NULL if not used  * @ca_cert_blob_len: ca_cert_blob length  * @ca_path: Path to CA certificates (OpenSSL specific)  * @subject_match: String to match in the subject of the peer certificate or  * %NULL to allow all subjects  * @altsubject_match: String to match in the alternative subject of the peer  * certificate or %NULL to allow all alternative subjects  * @client_cert: File or reference name for client X.509 certificate in PEM or  * DER format  * @client_cert_blob: client_cert as inlined data or %NULL if not used  * @client_cert_blob_len: client_cert_blob length  * @private_key: File or reference name for client private key in PEM or DER  * format (traditional format (RSA PRIVATE KEY) or PKCS#8 (PRIVATE KEY)  * @private_key_blob: private_key as inlined data or %NULL if not used  * @private_key_blob_len: private_key_blob length  * @private_key_passwd: Passphrase for decrypted private key, %NULL if no  * passphrase is used.  * @dh_file: File name for DH/DSA data in PEM format, or %NULL if not used  * @dh_blob: dh_file as inlined data or %NULL if not used  * @dh_blob_len: dh_blob length  * @engine: 1 = use engine (e.g., a smartcard) for private key operations  * (this is OpenSSL specific for now)  * @engine_id: engine id string (this is OpenSSL specific for now)  * @ppin: pointer to the pin variable in the configuration  * (this is OpenSSL specific for now)  * @key_id: the private key's id when using engine (this is OpenSSL  * specific for now)  * @cert_id: the certificate's id when using engine  * @ca_cert_id: the CA certificate's id when using engine  * @tls_ia: Whether to enable TLS/IA (for EAP-TTLSv1)  * @flags: Parameter options (TLS_CONN_*)  *  * TLS connection parameters to be configured with tls_connection_set_params()  * and tls_global_set_params().  *  * Certificates and private key can be configured either as a reference name  * (file path or reference to certificate store) or by providing the same data  * as a pointer to the data in memory. Only one option will be used for each  * field.  */
end_comment

begin_struct
struct|struct
name|tls_connection_params
block|{
specifier|const
name|char
modifier|*
name|ca_cert
decl_stmt|;
specifier|const
name|u8
modifier|*
name|ca_cert_blob
decl_stmt|;
name|size_t
name|ca_cert_blob_len
decl_stmt|;
specifier|const
name|char
modifier|*
name|ca_path
decl_stmt|;
specifier|const
name|char
modifier|*
name|subject_match
decl_stmt|;
specifier|const
name|char
modifier|*
name|altsubject_match
decl_stmt|;
specifier|const
name|char
modifier|*
name|client_cert
decl_stmt|;
specifier|const
name|u8
modifier|*
name|client_cert_blob
decl_stmt|;
name|size_t
name|client_cert_blob_len
decl_stmt|;
specifier|const
name|char
modifier|*
name|private_key
decl_stmt|;
specifier|const
name|u8
modifier|*
name|private_key_blob
decl_stmt|;
name|size_t
name|private_key_blob_len
decl_stmt|;
specifier|const
name|char
modifier|*
name|private_key_passwd
decl_stmt|;
specifier|const
name|char
modifier|*
name|dh_file
decl_stmt|;
specifier|const
name|u8
modifier|*
name|dh_blob
decl_stmt|;
name|size_t
name|dh_blob_len
decl_stmt|;
name|int
name|tls_ia
decl_stmt|;
comment|/* OpenSSL specific variables */
name|int
name|engine
decl_stmt|;
specifier|const
name|char
modifier|*
name|engine_id
decl_stmt|;
specifier|const
name|char
modifier|*
name|pin
decl_stmt|;
specifier|const
name|char
modifier|*
name|key_id
decl_stmt|;
specifier|const
name|char
modifier|*
name|cert_id
decl_stmt|;
specifier|const
name|char
modifier|*
name|ca_cert_id
decl_stmt|;
name|unsigned
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * tls_init - Initialize TLS library  * @conf: Configuration data for TLS library  * Returns: Context data to be used as tls_ctx in calls to other functions,  * or %NULL on failure.  *  * Called once during program startup and once for each RSN pre-authentication  * session. In other words, there can be two concurrent TLS contexts. If global  * library initialization is needed (i.e., one that is shared between both  * authentication types), the TLS library wrapper should maintain a reference  * counter and do global initialization only when moving from 0 to 1 reference.  */
end_comment

begin_function_decl
name|void
modifier|*
name|tls_init
parameter_list|(
specifier|const
name|struct
name|tls_config
modifier|*
name|conf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_deinit - Deinitialize TLS library  * @tls_ctx: TLS context data from tls_init()  *  * Called once during program shutdown and once for each RSN pre-authentication  * session. If global library deinitialization is needed (i.e., one that is  * shared between both authentication types), the TLS library wrapper should  * maintain a reference counter and do global deinitialization only when moving  * from 1 to 0 references.  */
end_comment

begin_function_decl
name|void
name|tls_deinit
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_get_errors - Process pending errors  * @tls_ctx: TLS context data from tls_init()  * Returns: Number of found error, 0 if no errors detected.  *  * Process all pending TLS errors.  */
end_comment

begin_function_decl
name|int
name|tls_get_errors
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_init - Initialize a new TLS connection  * @tls_ctx: TLS context data from tls_init()  * Returns: Connection context data, conn for other function calls  */
end_comment

begin_function_decl
name|struct
name|tls_connection
modifier|*
name|tls_connection_init
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_deinit - Free TLS connection data  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  *  * Release all resources allocated for TLS connection.  */
end_comment

begin_function_decl
name|void
name|tls_connection_deinit
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
name|struct
name|tls_connection
modifier|*
name|conn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_established - Has the TLS connection been completed?  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * Returns: 1 if TLS connection has been completed, 0 if not.  */
end_comment

begin_function_decl
name|int
name|tls_connection_established
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
name|struct
name|tls_connection
modifier|*
name|conn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_shutdown - Shutdown TLS connection  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * Returns: 0 on success, -1 on failure  *  * Shutdown current TLS connection without releasing all resources. New  * connection can be started by using the same conn without having to call  * tls_connection_init() or setting certificates etc. again. The new  * connection should try to use session resumption.  */
end_comment

begin_function_decl
name|int
name|tls_connection_shutdown
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
name|struct
name|tls_connection
modifier|*
name|conn
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
block|{
name|TLS_SET_PARAMS_ENGINE_PRV_VERIFY_FAILED
init|=
operator|-
literal|3
block|,
name|TLS_SET_PARAMS_ENGINE_PRV_INIT_FAILED
init|=
operator|-
literal|2
block|}
enum|;
end_enum

begin_comment
comment|/**  * tls_connection_set_params - Set TLS connection parameters  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * @params: Connection parameters  * Returns: 0 on success, -1 on failure,  * TLS_SET_PARAMS_ENGINE_PRV_INIT_FAILED (-2) on possible PIN error causing  * PKCS#11 engine failure, or  * TLS_SET_PARAMS_ENGINE_PRV_VERIFY_FAILED (-3) on failure to verify the  * PKCS#11 engine private key.  */
end_comment

begin_function_decl
name|int
name|__must_check
name|tls_connection_set_params
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
name|struct
name|tls_connection
modifier|*
name|conn
parameter_list|,
specifier|const
name|struct
name|tls_connection_params
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_global_set_params - Set TLS parameters for all TLS connection  * @tls_ctx: TLS context data from tls_init()  * @params: Global TLS parameters  * Returns: 0 on success, -1 on failure,  * TLS_SET_PARAMS_ENGINE_PRV_INIT_FAILED (-2) on possible PIN error causing  * PKCS#11 engine failure, or  * TLS_SET_PARAMS_ENGINE_PRV_VERIFY_FAILED (-3) on failure to verify the  * PKCS#11 engine private key.  */
end_comment

begin_function_decl
name|int
name|__must_check
name|tls_global_set_params
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
specifier|const
name|struct
name|tls_connection_params
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_global_set_verify - Set global certificate verification options  * @tls_ctx: TLS context data from tls_init()  * @check_crl: 0 = do not verify CRLs, 1 = verify CRL for the user certificate,  * 2 = verify CRL for all certificates  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|__must_check
name|tls_global_set_verify
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
name|int
name|check_crl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_set_verify - Set certificate verification options  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * @verify_peer: 1 = verify peer certificate  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|__must_check
name|tls_connection_set_verify
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
name|struct
name|tls_connection
modifier|*
name|conn
parameter_list|,
name|int
name|verify_peer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_set_ia - Set TLS/IA parameters  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * @tls_ia: 1 = enable TLS/IA  * Returns: 0 on success, -1 on failure  *  * This function is used to configure TLS/IA in server mode where  * tls_connection_set_params() is not used.  */
end_comment

begin_function_decl
name|int
name|__must_check
name|tls_connection_set_ia
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
name|struct
name|tls_connection
modifier|*
name|conn
parameter_list|,
name|int
name|tls_ia
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_get_keys - Get master key and random data from TLS connection  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * @keys: Structure of key/random data (filled on success)  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|__must_check
name|tls_connection_get_keys
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
name|struct
name|tls_connection
modifier|*
name|conn
parameter_list|,
name|struct
name|tls_keys
modifier|*
name|keys
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_prf - Use TLS-PRF to derive keying material  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * @label: Label (e.g., description of the key) for PRF  * @server_random_first: seed is 0 = client_random|server_random,  * 1 = server_random|client_random  * @out: Buffer for output data from TLS-PRF  * @out_len: Length of the output buffer  * Returns: 0 on success, -1 on failure  *  * This function is optional to implement if tls_connection_get_keys() provides  * access to master secret and server/client random values. If these values are  * not exported from the TLS library, tls_connection_prf() is required so that  * further keying material can be derived from the master secret. If not  * implemented, the function will still need to be defined, but it can just  * return -1. Example implementation of this function is in tls_prf() function  * when it is called with seed set to client_random|server_random (or  * server_random|client_random).  */
end_comment

begin_function_decl
name|int
name|__must_check
name|tls_connection_prf
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
name|struct
name|tls_connection
modifier|*
name|conn
parameter_list|,
specifier|const
name|char
modifier|*
name|label
parameter_list|,
name|int
name|server_random_first
parameter_list|,
name|u8
modifier|*
name|out
parameter_list|,
name|size_t
name|out_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_handshake - Process TLS handshake (client side)  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * @in_data: Input data from TLS server  * @appl_data: Pointer to application data pointer, or %NULL if dropped  * Returns: Output data, %NULL on failure  *  * The caller is responsible for freeing the returned output data. If the final  * handshake message includes application data, this is decrypted and  * appl_data (if not %NULL) is set to point this data. The caller is  * responsible for freeing appl_data.  *  * This function is used during TLS handshake. The first call is done with  * in_data == %NULL and the library is expected to return ClientHello packet.  * This packet is then send to the server and a response from server is given  * to TLS library by calling this function again with in_data pointing to the  * TLS message from the server.  *  * If the TLS handshake fails, this function may return %NULL. However, if the  * TLS library has a TLS alert to send out, that should be returned as the  * output data. In this case, tls_connection_get_failed() must return failure  * (> 0).  *  * tls_connection_established() should return 1 once the TLS handshake has been  * completed successfully.  */
end_comment

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|tls_connection_handshake
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
name|struct
name|tls_connection
modifier|*
name|conn
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|in_data
parameter_list|,
name|struct
name|wpabuf
modifier|*
modifier|*
name|appl_data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_server_handshake - Process TLS handshake (server side)  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * @in_data: Input data from TLS peer  * @appl_data: Pointer to application data pointer, or %NULL if dropped  * Returns: Output data, %NULL on failure  *  * The caller is responsible for freeing the returned output data.  */
end_comment

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|tls_connection_server_handshake
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
name|struct
name|tls_connection
modifier|*
name|conn
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|in_data
parameter_list|,
name|struct
name|wpabuf
modifier|*
modifier|*
name|appl_data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_encrypt - Encrypt data into TLS tunnel  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * @in_data: Plaintext data to be encrypted  * Returns: Encrypted TLS data or %NULL on failure  *  * This function is used after TLS handshake has been completed successfully to  * send data in the encrypted tunnel. The caller is responsible for freeing the  * returned output data.  */
end_comment

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|tls_connection_encrypt
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
name|struct
name|tls_connection
modifier|*
name|conn
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|in_data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_decrypt - Decrypt data from TLS tunnel  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * @in_data: Encrypted TLS data  * Returns: Decrypted TLS data or %NULL on failure  *  * This function is used after TLS handshake has been completed successfully to  * receive data from the encrypted tunnel. The caller is responsible for  * freeing the returned output data.  */
end_comment

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|tls_connection_decrypt
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
name|struct
name|tls_connection
modifier|*
name|conn
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|in_data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_resumed - Was session resumption used  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * Returns: 1 if current session used session resumption, 0 if not  */
end_comment

begin_function_decl
name|int
name|tls_connection_resumed
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
name|struct
name|tls_connection
modifier|*
name|conn
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
block|{
name|TLS_CIPHER_NONE
block|,
name|TLS_CIPHER_RC4_SHA
comment|/* 0x0005 */
block|,
name|TLS_CIPHER_AES128_SHA
comment|/* 0x002f */
block|,
name|TLS_CIPHER_RSA_DHE_AES128_SHA
comment|/* 0x0031 */
block|,
name|TLS_CIPHER_ANON_DH_AES128_SHA
comment|/* 0x0034 */
block|}
enum|;
end_enum

begin_comment
comment|/**  * tls_connection_set_cipher_list - Configure acceptable cipher suites  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * @ciphers: Zero (TLS_CIPHER_NONE) terminated list of allowed ciphers  * (TLS_CIPHER_*).  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|__must_check
name|tls_connection_set_cipher_list
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
name|struct
name|tls_connection
modifier|*
name|conn
parameter_list|,
name|u8
modifier|*
name|ciphers
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_get_cipher - Get current cipher name  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * @buf: Buffer for the cipher name  * @buflen: buf size  * Returns: 0 on success, -1 on failure  *  * Get the name of the currently used cipher.  */
end_comment

begin_function_decl
name|int
name|__must_check
name|tls_get_cipher
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
name|struct
name|tls_connection
modifier|*
name|conn
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

begin_comment
comment|/**  * tls_connection_enable_workaround - Enable TLS workaround options  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * Returns: 0 on success, -1 on failure  *  * This function is used to enable connection-specific workaround options for  * buffer SSL/TLS implementations.  */
end_comment

begin_function_decl
name|int
name|__must_check
name|tls_connection_enable_workaround
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
name|struct
name|tls_connection
modifier|*
name|conn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_client_hello_ext - Set TLS extension for ClientHello  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * @ext_type: Extension type  * @data: Extension payload (%NULL to remove extension)  * @data_len: Extension payload length  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|__must_check
name|tls_connection_client_hello_ext
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
name|struct
name|tls_connection
modifier|*
name|conn
parameter_list|,
name|int
name|ext_type
parameter_list|,
specifier|const
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
name|data_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_get_failed - Get connection failure status  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  *  * Returns>0 if connection has failed, 0 if not.  */
end_comment

begin_function_decl
name|int
name|tls_connection_get_failed
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
name|struct
name|tls_connection
modifier|*
name|conn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_get_read_alerts - Get connection read alert status  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * Returns: Number of times a fatal read (remote end reported error) has  * happened during this connection.  */
end_comment

begin_function_decl
name|int
name|tls_connection_get_read_alerts
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
name|struct
name|tls_connection
modifier|*
name|conn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_get_write_alerts - Get connection write alert status  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * Returns: Number of times a fatal write (locally detected error) has happened  * during this connection.  */
end_comment

begin_function_decl
name|int
name|tls_connection_get_write_alerts
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
name|struct
name|tls_connection
modifier|*
name|conn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_get_keyblock_size - Get TLS key_block size  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * Returns: Size of the key_block for the negotiated cipher suite or -1 on  * failure  */
end_comment

begin_function_decl
name|int
name|tls_connection_get_keyblock_size
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
name|struct
name|tls_connection
modifier|*
name|conn
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TLS_CAPABILITY_IA
value|0x0001
end_define

begin_comment
comment|/* TLS Inner Application (TLS/IA) */
end_comment

begin_comment
comment|/**  * tls_capabilities - Get supported TLS capabilities  * @tls_ctx: TLS context data from tls_init()  * Returns: Bit field of supported TLS capabilities (TLS_CAPABILITY_*)  */
end_comment

begin_function_decl
name|unsigned
name|int
name|tls_capabilities
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_ia_send_phase_finished - Send a TLS/IA PhaseFinished message  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * @final: 1 = FinalPhaseFinished, 0 = IntermediatePhaseFinished  * Returns: Encrypted TLS/IA data, %NULL on failure  *  * This function is used to send the TLS/IA end phase message, e.g., when the  * EAP server completes EAP-TTLSv1.  */
end_comment

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|tls_connection_ia_send_phase_finished
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
name|struct
name|tls_connection
modifier|*
name|conn
parameter_list|,
name|int
name|final
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_ia_final_phase_finished - Has final phase been completed  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * Returns: 1 if valid FinalPhaseFinished has been received, 0 if not, or -1  * on failure  */
end_comment

begin_function_decl
name|int
name|__must_check
name|tls_connection_ia_final_phase_finished
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
name|struct
name|tls_connection
modifier|*
name|conn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_ia_permute_inner_secret - Permute TLS/IA inner secret  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * @key: Session key material (session_key vectors with 2-octet length), or  * %NULL if no session key was generating in the current phase  * @key_len: Length of session key material  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|__must_check
name|tls_connection_ia_permute_inner_secret
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
name|struct
name|tls_connection
modifier|*
name|conn
parameter_list|,
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
name|size_t
name|key_len
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|tls_session_ticket_cb
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|ticket
parameter_list|,
name|size_t
name|len
parameter_list|,
specifier|const
name|u8
modifier|*
name|client_random
parameter_list|,
specifier|const
name|u8
modifier|*
name|server_random
parameter_list|,
name|u8
modifier|*
name|master_secret
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|__must_check
name|tls_connection_set_session_ticket_cb
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
name|struct
name|tls_connection
modifier|*
name|conn
parameter_list|,
name|tls_session_ticket_cb
name|cb
parameter_list|,
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TLS_H */
end_comment

end_unit

