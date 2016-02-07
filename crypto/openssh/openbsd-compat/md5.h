begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: md5.h,v 1.17 2012/12/05 23:19:57 deraadt Exp $	*/
end_comment

begin_comment
comment|/*  * This code implements the MD5 message-digest algorithm.  * The algorithm is due to Ron Rivest.  This code was  * written by Colin Plumb in 1993, no copyright is claimed.  * This code is in the public domain; do with it what you wish.  *  * Equivalent code is available from RSA Data Security, Inc.  * This code has been tested against that, and is equivalent,  * except that you don't need to include two pages of legalese  * with every copy.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MD5_H_
end_ifndef

begin_define
define|#
directive|define
name|_MD5_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|WITH_OPENSSL
end_ifndef

begin_define
define|#
directive|define
name|MD5_BLOCK_LENGTH
value|64
end_define

begin_define
define|#
directive|define
name|MD5_DIGEST_LENGTH
value|16
end_define

begin_define
define|#
directive|define
name|MD5_DIGEST_STRING_LENGTH
value|(MD5_DIGEST_LENGTH * 2 + 1)
end_define

begin_typedef
typedef|typedef
struct|struct
name|MD5Context
block|{
name|u_int32_t
name|state
index|[
literal|4
index|]
decl_stmt|;
comment|/* state */
name|u_int64_t
name|count
decl_stmt|;
comment|/* number of bits, mod 2^64 */
name|u_int8_t
name|buffer
index|[
name|MD5_BLOCK_LENGTH
index|]
decl_stmt|;
comment|/* input buffer */
block|}
name|MD5_CTX
typedef|;
end_typedef

begin_function_decl
name|void
name|MD5Init
parameter_list|(
name|MD5_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MD5Update
parameter_list|(
name|MD5_CTX
modifier|*
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__string__
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|MD5Pad
parameter_list|(
name|MD5_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MD5Final
parameter_list|(
name|u_int8_t
index|[
name|MD5_DIGEST_LENGTH
index|]
parameter_list|,
name|MD5_CTX
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__minbytes__
parameter_list|,
function_decl|1
operator|,
function_decl|MD5_DIGEST_LENGTH
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|MD5Transform
parameter_list|(
name|u_int32_t
index|[
literal|4
index|]
parameter_list|,
specifier|const
name|u_int8_t
index|[
name|MD5_BLOCK_LENGTH
index|]
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__minbytes__
parameter_list|,
function_decl|1
operator|,
function_decl|4
end_function_decl

begin_expr_stmt
unit|)))
name|__attribute__
argument_list|(
operator|(
name|__bounded__
argument_list|(
name|__minbytes__
argument_list|,
literal|2
argument_list|,
name|MD5_BLOCK_LENGTH
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|char
modifier|*
name|MD5End
parameter_list|(
name|MD5_CTX
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__minbytes__
parameter_list|,
function_decl|2
operator|,
function_decl|MD5_DIGEST_STRING_LENGTH
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|char
modifier|*
name|MD5File
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__minbytes__
parameter_list|,
function_decl|2
operator|,
function_decl|MD5_DIGEST_STRING_LENGTH
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|char
modifier|*
name|MD5FileChunk
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|off_t
parameter_list|,
name|off_t
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__minbytes__
parameter_list|,
function_decl|2
operator|,
function_decl|MD5_DIGEST_STRING_LENGTH
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|char
modifier|*
name|MD5Data
parameter_list|(
specifier|const
name|u_int8_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__string__
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_expr_stmt
unit|)))
name|__attribute__
argument_list|(
operator|(
name|__bounded__
argument_list|(
name|__minbytes__
argument_list|,
literal|3
argument_list|,
name|MD5_DIGEST_STRING_LENGTH
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !WITH_OPENSSL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MD5_H_ */
end_comment

end_unit

