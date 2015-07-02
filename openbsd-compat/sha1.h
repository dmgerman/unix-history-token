begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: sha1.h,v 1.24 2012/12/05 23:19:57 deraadt Exp $	*/
end_comment

begin_comment
comment|/*  * SHA-1 in C  * By Steve Reid<steve@edmweb.com>  * 100% Public Domain  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SHA1_H
end_ifndef

begin_define
define|#
directive|define
name|_SHA1_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|WITH_OPENSSL
end_ifndef

begin_define
define|#
directive|define
name|SHA1_BLOCK_LENGTH
value|64
end_define

begin_define
define|#
directive|define
name|SHA1_DIGEST_LENGTH
value|20
end_define

begin_define
define|#
directive|define
name|SHA1_DIGEST_STRING_LENGTH
value|(SHA1_DIGEST_LENGTH * 2 + 1)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|state
index|[
literal|5
index|]
decl_stmt|;
name|u_int64_t
name|count
decl_stmt|;
name|u_int8_t
name|buffer
index|[
name|SHA1_BLOCK_LENGTH
index|]
decl_stmt|;
block|}
name|SHA1_CTX
typedef|;
end_typedef

begin_function_decl
name|void
name|SHA1Init
parameter_list|(
name|SHA1_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SHA1Pad
parameter_list|(
name|SHA1_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SHA1Transform
parameter_list|(
name|u_int32_t
index|[
literal|5
index|]
parameter_list|,
specifier|const
name|u_int8_t
index|[
name|SHA1_BLOCK_LENGTH
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
function_decl|5
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
name|SHA1_BLOCK_LENGTH
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|SHA1Update
parameter_list|(
name|SHA1_CTX
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
name|SHA1Final
parameter_list|(
name|u_int8_t
index|[
name|SHA1_DIGEST_LENGTH
index|]
parameter_list|,
name|SHA1_CTX
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
function_decl|SHA1_DIGEST_LENGTH
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|char
modifier|*
name|SHA1End
parameter_list|(
name|SHA1_CTX
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
function_decl|SHA1_DIGEST_STRING_LENGTH
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|char
modifier|*
name|SHA1File
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
function_decl|SHA1_DIGEST_STRING_LENGTH
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|char
modifier|*
name|SHA1FileChunk
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
function_decl|SHA1_DIGEST_STRING_LENGTH
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|char
modifier|*
name|SHA1Data
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
name|SHA1_DIGEST_STRING_LENGTH
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|HTONDIGEST
parameter_list|(
name|x
parameter_list|)
value|do {                                              \         x[0] = htonl(x[0]);                                             \         x[1] = htonl(x[1]);                                             \         x[2] = htonl(x[2]);                                             \         x[3] = htonl(x[3]);                                             \         x[4] = htonl(x[4]); } while (0)
end_define

begin_define
define|#
directive|define
name|NTOHDIGEST
parameter_list|(
name|x
parameter_list|)
value|do {                                              \         x[0] = ntohl(x[0]);                                             \         x[1] = ntohl(x[1]);                                             \         x[2] = ntohl(x[2]);                                             \         x[3] = ntohl(x[3]);                                             \         x[4] = ntohl(x[4]); } while (0)
end_define

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
comment|/* _SHA1_H */
end_comment

end_unit

