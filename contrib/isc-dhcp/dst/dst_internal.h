begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|DST_INTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|DST_INTERNAL_H
end_define

begin_comment
comment|/*  * Portions Copyright (c) 1995-1998 by Trusted Information Systems, Inc.  *  * Permission to use, copy modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND TRUSTED INFORMATION SYSTEMS  * DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL  * TRUSTED INFORMATION SYSTEMS BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING  * FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,  * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION  * WITH THE USE OR PERFORMANCE OF THE SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|PATH_MAX
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX_PATH_MAX
end_ifdef

begin_define
define|#
directive|define
name|PATH_MAX
value|POSIX_PATH_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PATH_MAX
value|255
end_define

begin_comment
comment|/* this is the value of POSIX_PATH_MAX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
name|void
modifier|*
name|dk_KEY_struct
decl_stmt|;
comment|/* pointer to key in crypto pkg fmt */
name|struct
name|dst_func
modifier|*
name|dk_func
decl_stmt|;
comment|/* point to cryptto pgk specific function table */
block|}
name|DST_KEY
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAS_DST_KEY
end_define

begin_include
include|#
directive|include
file|<isc-dhcp/dst.h>
end_include

begin_comment
comment|/*   * define what crypto systems are supported for RSA,   * BSAFE is prefered over RSAREF; only one can be set at any time  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSAFE
argument_list|)
operator|&&
name|defined
argument_list|(
name|RSAREF
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Cannot have both BSAFE and RSAREF defined"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Declare dst_lib specific constants */
end_comment

begin_define
define|#
directive|define
name|KEY_FILE_FORMAT
value|"1.2"
end_define

begin_comment
comment|/* suffixes for key file names */
end_comment

begin_define
define|#
directive|define
name|PRIVATE_KEY
value|"private"
end_define

begin_define
define|#
directive|define
name|PUBLIC_KEY
value|"key"
end_define

begin_comment
comment|/* error handling */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|REPORT_ERRORS
end_ifdef

begin_define
define|#
directive|define
name|EREPORT
parameter_list|(
name|str
parameter_list|)
value|printf str
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EREPORT
parameter_list|(
name|str
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* use our own special macro to FRRE memory */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SAFE_FREE
end_ifndef

begin_define
define|#
directive|define
name|SAFE_FREE
parameter_list|(
name|a
parameter_list|)
value|if(a != NULL){memset(a,0, sizeof(*a)); free(a); a=NULL;}
end_define

begin_define
define|#
directive|define
name|SAFE_FREE2
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|)
value|if (a != NULL&& s> 0){memset(a,0, s);free(a); a=NULL;}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|dst_func
block|{
name|int
function_decl|(
modifier|*
name|sign
function_decl|)
parameter_list|(
specifier|const
name|int
name|mode
parameter_list|,
name|DST_KEY
modifier|*
name|key
parameter_list|,
name|void
modifier|*
modifier|*
name|context
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
name|data
parameter_list|,
specifier|const
name|unsigned
name|len
parameter_list|,
name|u_int8_t
modifier|*
name|signature
parameter_list|,
specifier|const
name|unsigned
name|sig_len
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|verify
function_decl|)
parameter_list|(
specifier|const
name|int
name|mode
parameter_list|,
name|DST_KEY
modifier|*
name|key
parameter_list|,
name|void
modifier|*
modifier|*
name|context
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
name|data
parameter_list|,
specifier|const
name|unsigned
name|len
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
name|signature
parameter_list|,
specifier|const
name|unsigned
name|sig_len
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|compare
function_decl|)
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
name|int
function_decl|(
modifier|*
name|generate
function_decl|)
parameter_list|(
name|DST_KEY
modifier|*
name|key
parameter_list|,
name|int
name|parms
parameter_list|)
function_decl|;
name|void
modifier|*
function_decl|(
modifier|*
name|destroy
function_decl|)
parameter_list|(
name|void
modifier|*
name|key
parameter_list|)
function_decl|;
comment|/* conversion functions */
name|int
function_decl|(
modifier|*
name|to_dns_key
function_decl|)
parameter_list|(
specifier|const
name|DST_KEY
modifier|*
name|key
parameter_list|,
name|u_int8_t
modifier|*
name|out
parameter_list|,
specifier|const
name|unsigned
name|out_len
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|from_dns_key
function_decl|)
parameter_list|(
name|DST_KEY
modifier|*
name|key
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
name|str
parameter_list|,
specifier|const
name|unsigned
name|str_len
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|to_file_fmt
function_decl|)
parameter_list|(
specifier|const
name|DST_KEY
modifier|*
name|key
parameter_list|,
name|char
modifier|*
name|out
parameter_list|,
specifier|const
name|unsigned
name|out_len
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|from_file_fmt
function_decl|)
parameter_list|(
name|DST_KEY
modifier|*
name|key
parameter_list|,
specifier|const
name|char
modifier|*
name|out
parameter_list|,
specifier|const
name|unsigned
name|out_len
parameter_list|)
function_decl|;
block|}
name|dst_func
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|dst_func
modifier|*
name|dst_t_func
index|[
name|DST_MAX_ALGS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|key_file_fmt_str
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|dst_path
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|DST_HASH_SIZE
end_ifndef

begin_define
define|#
directive|define
name|DST_HASH_SIZE
value|20
end_define

begin_comment
comment|/* RIPEMD160 and SHA-1 are 20 bytes MD5 is 16 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|int dst_bsafe_init(void); int dst_rsaref_init(void);
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|dst_hmac_md5_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|int dst_cylink_init(void); int dst_eay_dss_init(void);
endif|#
directive|endif
end_endif

begin_comment
comment|/* support functions */
end_comment

begin_comment
comment|/* base64 to bignum conversion routines */
end_comment

begin_function_decl
name|int
name|dst_s_conv_bignum_u8_to_b64
parameter_list|(
name|char
modifier|*
name|out_buf
parameter_list|,
specifier|const
name|unsigned
name|out_len
parameter_list|,
specifier|const
name|char
modifier|*
name|header
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
name|bin_data
parameter_list|,
specifier|const
name|unsigned
name|bin_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dst_s_conv_bignum_b64_to_u8
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|buf
parameter_list|,
name|u_int8_t
modifier|*
name|loc
parameter_list|,
specifier|const
name|unsigned
name|loclen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* from higher level support routines */
end_comment

begin_function_decl
name|int
name|dst_s_calculate_bits
parameter_list|(
specifier|const
name|u_int8_t
modifier|*
name|str
parameter_list|,
specifier|const
name|int
name|max_bits
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dst_s_verify_str
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|buf
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* conversion between dns names and key file names */
end_comment

begin_function_decl
name|size_t
name|dst_s_filename_length
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|suffix
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dst_s_build_filename
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|unsigned
name|id
parameter_list|,
name|int
name|alg
parameter_list|,
specifier|const
name|char
modifier|*
name|suffix
parameter_list|,
name|size_t
name|filename_length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|dst_s_fopen
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
specifier|const
name|char
modifier|*
name|mode
parameter_list|,
name|unsigned
name|perm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* from file prandom.c */
end_comment

begin_function_decl
name|int
name|dst_s_random
parameter_list|(
name|u_int8_t
modifier|*
name|output
parameter_list|,
name|unsigned
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dst_s_semi_random
parameter_list|(
name|u_int8_t
modifier|*
name|output
parameter_list|,
name|unsigned
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|dst_s_quick_random
parameter_list|(
name|int
name|inc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dst_s_quick_random_set
parameter_list|(
name|u_int32_t
name|val
parameter_list|,
name|u_int32_t
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*   * read and write network byte order into u_int?_t    *  all of these should be retired  */
end_comment

begin_function_decl
name|u_int16_t
name|dst_s_get_int16
parameter_list|(
specifier|const
name|u_int8_t
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dst_s_put_int16
parameter_list|(
name|u_int8_t
modifier|*
name|buf
parameter_list|,
specifier|const
name|u_int16_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|dst_s_get_int32
parameter_list|(
specifier|const
name|u_int8_t
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dst_s_put_int32
parameter_list|(
name|u_int8_t
modifier|*
name|buf
parameter_list|,
specifier|const
name|u_int32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DUMP
end_ifdef

begin_undef
undef|#
directive|undef
name|DUMP
end_undef

begin_define
define|#
directive|define
name|DUMP
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|dst_s_dump(a,b,c,d)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DUMP
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DST_INTERNAL_H */
end_comment

end_unit

