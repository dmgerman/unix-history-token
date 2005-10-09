begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
block|}
struct|;
end_struct

begin_comment
comment|/**  * tls_init - initialize TLS library  *  * Returns: Context data to be used as @tls_ctx in calls to other functions,  * or %NULL on failure.  *  * Called once during program startup.  */
end_comment

begin_function_decl
name|void
modifier|*
name|tls_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_deinit - deinitialize TLS library  * @tls_ctx: TLS context data from tls_init()  *  * Called once during program shutdown.  */
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
comment|/**  * tls_get_errors - process pending errors  * @tls_ctx: TLS context data from tls_init()  *  * Returns: Number of found error, 0 if no errors detected.  *  * Process all pending TLS errors.  */
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
comment|/**  * tls_connection_init - initialize a new TLS connection  * @tls_ctx: TLS context data from tls_init()  *  * Returns: Connection context data, @conn for other function calls  */
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
comment|/**  * tls_connection_deinit - free TLS connection data  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  *  * Release all resources allocated for TLS connection.  */
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
comment|/**  * tls_connection_established - has the TLS connection been completed?  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  *  * Returns: 1 if TLS connection has been completed, 0 if not.  */
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
comment|/**  * tls_connection_shutdown - shutdown TLS connection data.  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  *  * Returns: 0 on success, -1 on failure  *  * Shutdown current TLS connection without releasing all resources. New  * connection can be started by using the same @conn without having to call  * tls_connection_init() or setting certificates etc. again. The new  * connection should try to use session resumption.  */
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

begin_comment
comment|/**  * tls_connection_ca_cert - set trusted CA certificate for TLS connection  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * @ca_cert: File name for CA certificate in PEM or DER format  * @subject_match: String to match in the subject of the peer certificate or  * %NULL to allow all subjects  *  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|tls_connection_ca_cert
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
name|ca_cert
parameter_list|,
specifier|const
name|char
modifier|*
name|subject_match
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_global_ca_cert - set trusted CA certificate for all TLS connections  * @tls_ctx: TLS context data from tls_init()  * @ca_cert: File name for CA certificate in PEM or DER format  * %NULL to allow all subjects  *  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|tls_global_ca_cert
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|ca_cert
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_ca_cert - set trusted CA certificate for TLS connection  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * @verify_peer: 1 = verify peer certificate  * @subject_match: String to match in the subject of the peer certificate or  * %NULL to allow all subjects  *  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
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
parameter_list|,
specifier|const
name|char
modifier|*
name|subject_match
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_client_cert - set client certificate for TLS connection  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * @client_cert: File name for client certificate in PEM or DER format  *  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|tls_connection_client_cert
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
name|client_cert
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_global_client_cert - set client certificate for all TLS connections  * @tls_ctx: TLS context data from tls_init()  * @client_cert: File name for client certificate in PEM or DER format  *  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|tls_global_client_cert
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|client_cert
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_private_key - set private key for TLS connection  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * @private_key: File name for client private key in PEM or DER format  * @private_key_passwd: Passphrase for decrypted private key, %NULL if no  * passphrase is used.  *  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|tls_connection_private_key
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
name|private_key
parameter_list|,
specifier|const
name|char
modifier|*
name|private_key_passwd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_global_private_key - set private key for all TLS connections  * @tls_ctx: TLS context data from tls_init()  * @private_key: File name for client private key in PEM or DER format  * @private_key_passwd: Passphrase for decrypted private key, %NULL if no  * passphrase is used.  *  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|tls_global_private_key
parameter_list|(
name|void
modifier|*
name|tls_ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|private_key
parameter_list|,
specifier|const
name|char
modifier|*
name|private_key_passwd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_dh - set DH/DSA parameters for TLS connection  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * @dh_file: File name for DH/DSA data in PEM format.  *  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|tls_connection_dh
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
name|dh_file
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_get_keys - get master key and random data from TLS connection  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * @keys: Structure of key/random data (filled on success)  *  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
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
comment|/**  * tls_connection_handshake - process TLS handshake (client side)  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * @in_data: Input data from TLS peer  * @in_len: Input data length  * @out_len: Length of the output buffer.  *  * Returns: pointer to output data, %NULL on failure  *  * Caller is responsible for freeing returned output data.  */
end_comment

begin_function_decl
name|u8
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
name|u8
modifier|*
name|in_data
parameter_list|,
name|size_t
name|in_len
parameter_list|,
name|size_t
modifier|*
name|out_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_servr_handshake - process TLS handshake (server side)  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * @in_data: Input data from TLS peer  * @in_len: Input data length  * @out_len: Length of the output buffer.  *  * Returns: pointer to output data, %NULL on failure  *  * Caller is responsible for freeing returned output data.  */
end_comment

begin_function_decl
name|u8
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
name|u8
modifier|*
name|in_data
parameter_list|,
name|size_t
name|in_len
parameter_list|,
name|size_t
modifier|*
name|out_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_encrypt - encrypt data into TLS tunnel  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * @in_data: Pointer to plaintext data to be encrypted  * @in_len: Input buffer length  * @out_data: Pointer to output buffer (encrypted TLS data)  * @out_len: Maximum @out_data length   *  * Returns: Number of bytes written to @out_data, -1 on failure  */
end_comment

begin_function_decl
name|int
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
name|u8
modifier|*
name|in_data
parameter_list|,
name|size_t
name|in_len
parameter_list|,
name|u8
modifier|*
name|out_data
parameter_list|,
name|size_t
name|out_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_decrypt - decrypt data from TLS tunnel  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * @in_data: Pointer to input buffer (encrypted TLS data)  * @in_len: Input buffer length  * @out_data: Pointer to output buffer (decrypted data from TLS tunnel)  * @out_len: Maximum @out_data length  *  * Returns: Number of bytes written to @out_data, -1 on failure  */
end_comment

begin_function_decl
name|int
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
name|u8
modifier|*
name|in_data
parameter_list|,
name|size_t
name|in_len
parameter_list|,
name|u8
modifier|*
name|out_data
parameter_list|,
name|size_t
name|out_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_connection_resumed - was session resumption used  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  *  * Returns: 1 if current session used session resumption, 0 if not  */
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

begin_comment
comment|/**  * tls_connection_set_master_key - configure master secret for TLS connection  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  * @key: TLS pre-master-secret  * @key_len: length of @key in bytes  *  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|tls_connection_set_master_key
parameter_list|(
name|void
modifier|*
name|ssl_ctx
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

begin_comment
comment|/**  * tls_connection_set_anon_dh - configure TLS connection to use anonymous DH  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  *  * Returns: 0 on success, -1 on failure  *  * TODO: consider changing this to more generic routine for configuring allowed  * ciphers  */
end_comment

begin_function_decl
name|int
name|tls_connection_set_anon_dh
parameter_list|(
name|void
modifier|*
name|ssl_ctx
parameter_list|,
name|struct
name|tls_connection
modifier|*
name|conn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * tls_get_cipher - get current cipher name  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  *  * Returns: 0 on success, -1 on failure  *  * Get the name of the currently used cipher.  */
end_comment

begin_function_decl
name|int
name|tls_get_cipher
parameter_list|(
name|void
modifier|*
name|ssl_ctx
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
comment|/**  * tls_connection_enable_workaround - enable TLS workaround options  * @tls_ctx: TLS context data from tls_init()  * @conn: Connection context data from tls_connection_init()  *  * Returns: 0 on success, -1 on failure  *  * This function is used to enable connection-specific workaround options for  * buffer SSL/TLS implementations.  */
end_comment

begin_function_decl
name|int
name|tls_connection_enable_workaround
parameter_list|(
name|void
modifier|*
name|ssl_ctx
parameter_list|,
name|struct
name|tls_connection
modifier|*
name|conn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls_connection_client_hello_ext
parameter_list|(
name|void
modifier|*
name|ssl_ctx
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TLS_H */
end_comment

end_unit

