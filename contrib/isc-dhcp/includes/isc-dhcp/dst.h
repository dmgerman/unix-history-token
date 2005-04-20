begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|DST_H
end_ifndef

begin_define
define|#
directive|define
name|DST_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_DST_KEY
end_ifndef

begin_typedef
typedef|typedef
struct|struct
name|dst_key
block|{
name|char
modifier|*
name|dk_key_name
decl_stmt|;
comment|/* name of the key */
name|int
name|dk_key_size
decl_stmt|;
comment|/* this is the size of the key in bits */
name|int
name|dk_proto
decl_stmt|;
comment|/* what protocols this key can be used for */
name|int
name|dk_alg
decl_stmt|;
comment|/* algorithm number from key record */
name|unsigned
name|dk_flags
decl_stmt|;
comment|/* and the flags of the public key */
name|unsigned
name|dk_id
decl_stmt|;
comment|/* identifier of the key */
block|}
name|DST_KEY
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAS_DST_KEY */
end_comment

begin_comment
comment|/*   * DST Crypto API defintions   */
end_comment

begin_function_decl
name|void
name|dst_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dst_check_algorithm
parameter_list|(
specifier|const
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dst_sign_data
parameter_list|(
specifier|const
name|int
name|mode
parameter_list|,
comment|/* specifies INIT/UPDATE/FINAL/ALL */
name|DST_KEY
modifier|*
name|in_key
parameter_list|,
comment|/* the key to use */
name|void
modifier|*
modifier|*
name|context
parameter_list|,
comment|/* pointer to state structure */
specifier|const
name|u_char
modifier|*
name|data
parameter_list|,
comment|/* data to be signed */
specifier|const
name|unsigned
name|len
parameter_list|,
comment|/* length of input data */
name|u_char
modifier|*
name|signature
parameter_list|,
comment|/* buffer to write signature to */
specifier|const
name|unsigned
name|sig_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* size of output buffer */
end_comment

begin_function_decl
name|int
name|dst_verify_data
parameter_list|(
specifier|const
name|int
name|mode
parameter_list|,
comment|/* specifies INIT/UPDATE/FINAL/ALL */
name|DST_KEY
modifier|*
name|in_key
parameter_list|,
comment|/* the key to use */
name|void
modifier|*
modifier|*
name|context
parameter_list|,
comment|/* pointer to state structure */
specifier|const
name|u_char
modifier|*
name|data
parameter_list|,
comment|/* data to be verified */
specifier|const
name|unsigned
name|len
parameter_list|,
comment|/* length of input data */
specifier|const
name|u_char
modifier|*
name|signature
parameter_list|,
comment|/* buffer containing signature */
specifier|const
name|unsigned
name|sig_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* length of signature */
end_comment

begin_function_decl
name|DST_KEY
modifier|*
name|dst_read_key
parameter_list|(
specifier|const
name|char
modifier|*
name|in_name
parameter_list|,
comment|/* name of key */
specifier|const
name|unsigned
name|in_id
parameter_list|,
comment|/* key tag identifier */
specifier|const
name|int
name|in_alg
parameter_list|,
comment|/* key algorithm */
specifier|const
name|int
name|key_type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Private/PublicKey wanted*/
end_comment

begin_function_decl
name|int
name|dst_write_key
parameter_list|(
specifier|const
name|DST_KEY
modifier|*
name|key
parameter_list|,
comment|/* key to write out */
specifier|const
name|int
name|key_type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Public/Private */
end_comment

begin_function_decl
name|DST_KEY
modifier|*
name|dst_dnskey_to_key
parameter_list|(
specifier|const
name|char
modifier|*
name|in_name
parameter_list|,
comment|/* KEY record name */
specifier|const
name|u_char
modifier|*
name|key
parameter_list|,
comment|/* KEY RDATA */
specifier|const
name|unsigned
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* size of input buffer*/
end_comment

begin_function_decl
name|int
name|dst_key_to_dnskey
parameter_list|(
specifier|const
name|DST_KEY
modifier|*
name|key
parameter_list|,
comment|/* key to translate */
name|u_char
modifier|*
name|out_storage
parameter_list|,
comment|/* output buffer */
specifier|const
name|unsigned
name|out_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* size of out_storage*/
end_comment

begin_function_decl
name|DST_KEY
modifier|*
name|dst_buffer_to_key
parameter_list|(
specifier|const
name|char
modifier|*
name|key_name
parameter_list|,
comment|/* name of the key */
specifier|const
name|int
name|alg
parameter_list|,
comment|/* algorithm */
specifier|const
name|unsigned
name|flags
parameter_list|,
comment|/* dns flags */
specifier|const
name|int
name|protocol
parameter_list|,
comment|/* dns protocol */
specifier|const
name|u_char
modifier|*
name|key_buf
parameter_list|,
comment|/* key in dns wire fmt */
specifier|const
name|unsigned
name|key_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* size of key */
end_comment

begin_function_decl
name|int
name|dst_key_to_buffer
parameter_list|(
name|DST_KEY
modifier|*
name|key
parameter_list|,
name|u_char
modifier|*
name|out_buff
parameter_list|,
name|unsigned
name|buf_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DST_KEY
modifier|*
name|dst_generate_key
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
comment|/* name of new key */
specifier|const
name|int
name|bits
parameter_list|,
comment|/* size of new key */
specifier|const
name|int
name|exp
parameter_list|,
comment|/* alg dependent parameter*/
specifier|const
name|unsigned
name|flags
parameter_list|,
comment|/* key DNS flags */
specifier|const
name|int
name|protocol
parameter_list|,
comment|/* key DNS protocol */
specifier|const
name|int
name|alg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* key algorithm to generate */
end_comment

begin_function_decl
name|DST_KEY
modifier|*
name|dst_free_key
parameter_list|(
name|DST_KEY
modifier|*
name|f_key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dst_compare_keys
parameter_list|(
specifier|const
name|DST_KEY
modifier|*
name|key1
parameter_list|,
specifier|const
name|DST_KEY
modifier|*
name|key2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dst_sig_size
parameter_list|(
name|DST_KEY
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dst_random
parameter_list|(
specifier|const
name|int
name|mode
parameter_list|,
name|unsigned
name|wanted
parameter_list|,
name|u_char
modifier|*
name|outran
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* support for dns key tags/ids */
end_comment

begin_function_decl
name|u_int16_t
name|dst_s_dns_key_id
parameter_list|(
specifier|const
name|u_char
modifier|*
name|dns_key_rdata
parameter_list|,
specifier|const
name|unsigned
name|rdata_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int16_t
name|dst_s_id_calc
parameter_list|(
specifier|const
name|u_char
modifier|*
name|key_data
parameter_list|,
specifier|const
name|unsigned
name|key_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Used by callers as well as by the library.  */
end_comment

begin_define
define|#
directive|define
name|RAW_KEY_SIZE
value|8192
end_define

begin_comment
comment|/* large enough to store any key */
end_comment

begin_comment
comment|/* DST_API control flags */
end_comment

begin_comment
comment|/* These are used used in functions dst_sign_data and dst_verify_data */
end_comment

begin_define
define|#
directive|define
name|SIG_MODE_INIT
value|1
end_define

begin_comment
comment|/* initalize digest */
end_comment

begin_define
define|#
directive|define
name|SIG_MODE_UPDATE
value|2
end_define

begin_comment
comment|/* add data to digest */
end_comment

begin_define
define|#
directive|define
name|SIG_MODE_FINAL
value|4
end_define

begin_comment
comment|/* generate/verify signature */
end_comment

begin_define
define|#
directive|define
name|SIG_MODE_ALL
value|(SIG_MODE_INIT|SIG_MODE_UPDATE|SIG_MODE_FINAL)
end_define

begin_comment
comment|/* Flags for dst_read_private_key()  */
end_comment

begin_define
define|#
directive|define
name|DST_FORCE_READ
value|0x1000000
end_define

begin_define
define|#
directive|define
name|DST_CAN_SIGN
value|0x010F
end_define

begin_define
define|#
directive|define
name|DST_NO_AUTHEN
value|0x8000
end_define

begin_define
define|#
directive|define
name|DST_EXTEND_FLAG
value|0x1000
end_define

begin_define
define|#
directive|define
name|DST_STANDARD
value|0
end_define

begin_define
define|#
directive|define
name|DST_PRIVATE
value|0x2000000
end_define

begin_define
define|#
directive|define
name|DST_PUBLIC
value|0x4000000
end_define

begin_define
define|#
directive|define
name|DST_RAND_SEMI
value|1
end_define

begin_define
define|#
directive|define
name|DST_RAND_STD
value|2
end_define

begin_define
define|#
directive|define
name|DST_RAND_KEY
value|3
end_define

begin_define
define|#
directive|define
name|DST_RAND_DSS
value|4
end_define

begin_comment
comment|/* DST algorithm codes */
end_comment

begin_define
define|#
directive|define
name|KEY_RSA
value|1
end_define

begin_define
define|#
directive|define
name|KEY_DH
value|2
end_define

begin_define
define|#
directive|define
name|KEY_DSA
value|3
end_define

begin_define
define|#
directive|define
name|KEY_PRIVATE
value|254
end_define

begin_define
define|#
directive|define
name|KEY_EXPAND
value|255
end_define

begin_define
define|#
directive|define
name|KEY_HMAC_MD5
value|157
end_define

begin_define
define|#
directive|define
name|KEY_HMAC_SHA1
value|158
end_define

begin_define
define|#
directive|define
name|UNKNOWN_KEYALG
value|0
end_define

begin_define
define|#
directive|define
name|DST_MAX_ALGS
value|KEY_HMAC_SHA1
end_define

begin_comment
comment|/* DST constants to locations in KEY record  changes in new KEY record */
end_comment

begin_define
define|#
directive|define
name|DST_FLAGS_SIZE
value|2
end_define

begin_define
define|#
directive|define
name|DST_KEY_PROT
value|2
end_define

begin_define
define|#
directive|define
name|DST_KEY_ALG
value|3
end_define

begin_define
define|#
directive|define
name|DST_EXT_FLAG
value|4
end_define

begin_define
define|#
directive|define
name|DST_KEY_START
value|4
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SIGN_F_NOKEY
end_ifndef

begin_define
define|#
directive|define
name|SIGN_F_NOKEY
value|0xC000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* error codes from dst routines */
end_comment

begin_define
define|#
directive|define
name|SIGN_INIT_FAILURE
value|(-23)
end_define

begin_define
define|#
directive|define
name|SIGN_UPDATE_FAILURE
value|(-24)
end_define

begin_define
define|#
directive|define
name|SIGN_FINAL_FAILURE
value|(-25)
end_define

begin_define
define|#
directive|define
name|VERIFY_INIT_FAILURE
value|(-26)
end_define

begin_define
define|#
directive|define
name|VERIFY_UPDATE_FAILURE
value|(-27)
end_define

begin_define
define|#
directive|define
name|VERIFY_FINAL_FAILURE
value|(-28)
end_define

begin_define
define|#
directive|define
name|MISSING_KEY_OR_SIGNATURE
value|(-30)
end_define

begin_define
define|#
directive|define
name|UNSUPPORTED_KEYALG
value|(-31)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DST_H */
end_comment

end_unit

