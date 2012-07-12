begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**********************************************************************  *                          gosthash.h                                *  *             Copyright (c) 2005-2006 Cryptocom LTD                  *  *       This file is distributed under the same license as OpenSSL   *  *                                                                    *  *    Declaration of GOST R 34.11-94 hash functions                   *  *       uses  and gost89.h Doesn't need OpenSSL                      *  **********************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GOSTHASH_H
end_ifndef

begin_define
define|#
directive|define
name|GOSTHASH_H
end_define

begin_include
include|#
directive|include
file|"gost89.h"
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN64
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
end_if

begin_typedef
typedef|typedef
name|__int64
name|ghosthash_len
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__arch64__
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|long
name|ghosthash_len
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|long
name|long
name|ghosthash_len
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|gost_hash_ctx
block|{
name|ghosthash_len
name|len
decl_stmt|;
name|gost_ctx
modifier|*
name|cipher_ctx
decl_stmt|;
name|int
name|left
decl_stmt|;
name|byte
name|H
index|[
literal|32
index|]
decl_stmt|;
name|byte
name|S
index|[
literal|32
index|]
decl_stmt|;
name|byte
name|remainder
index|[
literal|32
index|]
decl_stmt|;
block|}
name|gost_hash_ctx
typedef|;
end_typedef

begin_comment
comment|/* Initalizes gost hash ctx, including creation of gost cipher ctx */
end_comment

begin_function_decl
name|int
name|init_gost_hash_ctx
parameter_list|(
name|gost_hash_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|gost_subst_block
modifier|*
name|subst_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|done_gost_hash_ctx
parameter_list|(
name|gost_hash_ctx
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Cleans up all fields, except cipher ctx preparing ctx for computing  * of new hash value */
end_comment

begin_function_decl
name|int
name|start_hash
parameter_list|(
name|gost_hash_ctx
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Hashes block of data */
end_comment

begin_function_decl
name|int
name|hash_block
parameter_list|(
name|gost_hash_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|byte
modifier|*
name|block
parameter_list|,
name|size_t
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Finalizes computation of hash  and fills buffer (which should be at  * least 32 bytes long) with value of computed hash. */
end_comment

begin_function_decl
name|int
name|finish_hash
parameter_list|(
name|gost_hash_ctx
modifier|*
name|ctx
parameter_list|,
name|byte
modifier|*
name|hashval
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

