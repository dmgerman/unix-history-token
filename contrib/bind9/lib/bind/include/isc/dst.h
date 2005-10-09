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
name|u_int32_t
name|dk_flags
decl_stmt|;
comment|/* and the flags of the public key */
name|u_int16_t
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
comment|/*  * do not taint namespace  */
end_comment

begin_define
define|#
directive|define
name|dst_bsafe_init
value|__dst_bsafe_init
end_define

begin_define
define|#
directive|define
name|dst_buffer_to_key
value|__dst_buffer_to_key
end_define

begin_define
define|#
directive|define
name|dst_check_algorithm
value|__dst_check_algorithm
end_define

begin_define
define|#
directive|define
name|dst_compare_keys
value|__dst_compare_keys
end_define

begin_define
define|#
directive|define
name|dst_cylink_init
value|__dst_cylink_init
end_define

begin_define
define|#
directive|define
name|dst_dnskey_to_key
value|__dst_dnskey_to_key
end_define

begin_define
define|#
directive|define
name|dst_eay_dss_init
value|__dst_eay_dss_init
end_define

begin_define
define|#
directive|define
name|dst_free_key
value|__dst_free_key
end_define

begin_define
define|#
directive|define
name|dst_generate_key
value|__dst_generate_key
end_define

begin_define
define|#
directive|define
name|dst_hmac_md5_init
value|__dst_hmac_md5_init
end_define

begin_define
define|#
directive|define
name|dst_init
value|__dst_init
end_define

begin_define
define|#
directive|define
name|dst_key_to_buffer
value|__dst_key_to_buffer
end_define

begin_define
define|#
directive|define
name|dst_key_to_dnskey
value|__dst_key_to_dnskey
end_define

begin_define
define|#
directive|define
name|dst_read_key
value|__dst_read_key
end_define

begin_define
define|#
directive|define
name|dst_rsaref_init
value|__dst_rsaref_init
end_define

begin_define
define|#
directive|define
name|dst_s_build_filename
value|__dst_s_build_filename
end_define

begin_define
define|#
directive|define
name|dst_s_calculate_bits
value|__dst_s_calculate_bits
end_define

begin_define
define|#
directive|define
name|dst_s_conv_bignum_b64_to_u8
value|__dst_s_conv_bignum_b64_to_u8
end_define

begin_define
define|#
directive|define
name|dst_s_conv_bignum_u8_to_b64
value|__dst_s_conv_bignum_u8_to_b64
end_define

begin_define
define|#
directive|define
name|dst_s_dns_key_id
value|__dst_s_dns_key_id
end_define

begin_define
define|#
directive|define
name|dst_s_dump
value|__dst_s_dump
end_define

begin_define
define|#
directive|define
name|dst_s_filename_length
value|__dst_s_filename_length
end_define

begin_define
define|#
directive|define
name|dst_s_fopen
value|__dst_s_fopen
end_define

begin_define
define|#
directive|define
name|dst_s_get_int16
value|__dst_s_get_int16
end_define

begin_define
define|#
directive|define
name|dst_s_get_int32
value|__dst_s_get_int32
end_define

begin_define
define|#
directive|define
name|dst_s_id_calc
value|__dst_s_id_calc
end_define

begin_define
define|#
directive|define
name|dst_s_put_int16
value|__dst_s_put_int16
end_define

begin_define
define|#
directive|define
name|dst_s_put_int32
value|__dst_s_put_int32
end_define

begin_define
define|#
directive|define
name|dst_s_quick_random
value|__dst_s_quick_random
end_define

begin_define
define|#
directive|define
name|dst_s_quick_random_set
value|__dst_s_quick_random_set
end_define

begin_define
define|#
directive|define
name|dst_s_random
value|__dst_s_random
end_define

begin_define
define|#
directive|define
name|dst_s_semi_random
value|__dst_s_semi_random
end_define

begin_define
define|#
directive|define
name|dst_s_verify_str
value|__dst_s_verify_str
end_define

begin_define
define|#
directive|define
name|dst_sig_size
value|__dst_sig_size
end_define

begin_define
define|#
directive|define
name|dst_sign_data
value|__dst_sign_data
end_define

begin_define
define|#
directive|define
name|dst_verify_data
value|__dst_verify_data
end_define

begin_define
define|#
directive|define
name|dst_write_key
value|__dst_write_key
end_define

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
parameter_list|,
comment|/* specifies INIT/UPDATE/FINAL/ALL */
name|DST_KEY
modifier|*
parameter_list|,
comment|/* the key to use */
name|void
modifier|*
modifier|*
parameter_list|,
comment|/* pointer to state structure */
specifier|const
name|u_char
modifier|*
parameter_list|,
comment|/* data to be signed */
specifier|const
name|int
parameter_list|,
comment|/* length of input data */
name|u_char
modifier|*
parameter_list|,
comment|/* buffer to write signature to */
specifier|const
name|int
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
parameter_list|,
comment|/* specifies INIT/UPDATE/FINAL/ALL */
name|DST_KEY
modifier|*
parameter_list|,
comment|/* the key to use */
name|void
modifier|*
modifier|*
parameter_list|,
comment|/* pointer to state structure */
specifier|const
name|u_char
modifier|*
parameter_list|,
comment|/* data to be verified */
specifier|const
name|int
parameter_list|,
comment|/* length of input data */
specifier|const
name|u_char
modifier|*
parameter_list|,
comment|/* buffer containing signature */
specifier|const
name|int
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
parameter_list|,
comment|/* name of key */
specifier|const
name|u_int16_t
parameter_list|,
comment|/* key tag identifier */
specifier|const
name|int
parameter_list|,
comment|/* key algorithm */
specifier|const
name|int
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
parameter_list|,
comment|/* key to write out */
specifier|const
name|int
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
parameter_list|,
comment|/* KEY record name */
specifier|const
name|u_char
modifier|*
parameter_list|,
comment|/* KEY RDATA */
specifier|const
name|int
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
parameter_list|,
comment|/* key to translate */
name|u_char
modifier|*
parameter_list|,
comment|/* output buffer */
specifier|const
name|int
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
parameter_list|,
comment|/* name of the key */
specifier|const
name|int
parameter_list|,
comment|/* algorithm */
specifier|const
name|int
parameter_list|,
comment|/* dns flags */
specifier|const
name|int
parameter_list|,
comment|/* dns protocol */
specifier|const
name|u_char
modifier|*
parameter_list|,
comment|/* key in dns wire fmt */
specifier|const
name|int
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
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
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
parameter_list|,
comment|/* name of new key */
specifier|const
name|int
parameter_list|,
comment|/* key algorithm to generate */
specifier|const
name|int
parameter_list|,
comment|/* size of new key */
specifier|const
name|int
parameter_list|,
comment|/* alg dependent parameter*/
specifier|const
name|int
parameter_list|,
comment|/* key DNS flags */
specifier|const
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* key DNS protocol */
end_comment

begin_function_decl
name|DST_KEY
modifier|*
name|dst_free_key
parameter_list|(
name|DST_KEY
modifier|*
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
parameter_list|,
specifier|const
name|DST_KEY
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dst_sig_size
parameter_list|(
name|DST_KEY
modifier|*
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
parameter_list|,
specifier|const
name|int
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
parameter_list|,
specifier|const
name|int
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
comment|/* initialize digest */
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

