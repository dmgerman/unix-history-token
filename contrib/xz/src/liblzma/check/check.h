begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       check.h
end_comment

begin_comment
comment|/// \brief      Internal API to different integrity check functions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Author:     Lasse Collin
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file has been put into the public domain.
end_comment

begin_comment
comment|//  You can do whatever you want with this file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LZMA_CHECK_H
end_ifndef

begin_define
define|#
directive|define
name|LZMA_CHECK_H
end_define

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_COMMONCRYPTO_COMMONDIGEST_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<CommonCrypto/CommonDigest.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_SHA256_H
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sha256.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_SHA2_H
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sha2.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_MINIX_SHA2_H
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<minix/sha2.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_CC_SHA256_CTX
argument_list|)
end_if

begin_typedef
typedef|typedef
name|CC_SHA256_CTX
name|lzma_sha256_state
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_SHA256_CTX
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|SHA256_CTX
name|lzma_sha256_state
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_SHA2_CTX
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|SHA2_CTX
name|lzma_sha256_state
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/// State for the internal SHA-256 implementation
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/// Internal state
name|uint32_t
name|state
index|[
literal|8
index|]
decl_stmt|;
comment|/// Size of the message excluding padding
name|uint64_t
name|size
decl_stmt|;
block|}
name|lzma_sha256_state
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_CC_SHA256_INIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|LZMA_SHA256FUNC
parameter_list|(
name|x
parameter_list|)
value|CC_SHA256_ ## x
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_SHA256_INIT
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LZMA_SHA256FUNC
parameter_list|(
name|x
parameter_list|)
value|SHA256_ ## x
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_SHA256INIT
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LZMA_SHA256FUNC
parameter_list|(
name|x
parameter_list|)
value|SHA256 ## x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Index hashing needs the best possible hash function (preferably
end_comment

begin_comment
comment|// a cryptographic hash) for maximum reliability.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_CHECK_SHA256
argument_list|)
end_if

begin_define
define|#
directive|define
name|LZMA_CHECK_BEST
value|LZMA_CHECK_SHA256
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_CHECK_CRC64
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LZMA_CHECK_BEST
value|LZMA_CHECK_CRC64
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LZMA_CHECK_BEST
value|LZMA_CHECK_CRC32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \brief      Structure to hold internal state of the check being calculated
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \note       This is not in the public API because this structure may
end_comment

begin_comment
comment|///             change in future if new integrity check algorithms are added.
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/// Buffer to hold the final result and a temporary buffer for SHA256.
union|union
block|{
name|uint8_t
name|u8
index|[
literal|64
index|]
decl_stmt|;
name|uint32_t
name|u32
index|[
literal|16
index|]
decl_stmt|;
name|uint64_t
name|u64
index|[
literal|8
index|]
decl_stmt|;
block|}
name|buffer
union|;
comment|/// Check-specific data
union|union
block|{
name|uint32_t
name|crc32
decl_stmt|;
name|uint64_t
name|crc64
decl_stmt|;
name|lzma_sha256_state
name|sha256
decl_stmt|;
block|}
name|state
union|;
block|}
name|lzma_check_state
typedef|;
end_typedef

begin_comment
comment|/// lzma_crc32_table[0] is needed by LZ encoder so we need to keep
end_comment

begin_comment
comment|/// the array two-dimensional.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SMALL
end_ifdef

begin_decl_stmt
specifier|extern
name|uint32_t
name|lzma_crc32_table
index|[
literal|1
index|]
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|lzma_crc32_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
specifier|const
name|uint32_t
name|lzma_crc32_table
index|[
literal|8
index|]
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint64_t
name|lzma_crc64_table
index|[
literal|4
index|]
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \brief      Initialize *check depending on type
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return     LZMA_OK on success. LZMA_UNSUPPORTED_CHECK if the type is not
end_comment

begin_comment
comment|///             supported by the current version or build of liblzma.
end_comment

begin_comment
comment|///             LZMA_PROG_ERROR if type> LZMA_CHECK_ID_MAX.
end_comment

begin_function_decl
specifier|extern
name|void
name|lzma_check_init
parameter_list|(
name|lzma_check_state
modifier|*
name|check
parameter_list|,
name|lzma_check
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Update the check state
end_comment

begin_function_decl
specifier|extern
name|void
name|lzma_check_update
parameter_list|(
name|lzma_check_state
modifier|*
name|check
parameter_list|,
name|lzma_check
name|type
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Finish the check calculation and store the result to check->buffer.u8.
end_comment

begin_function_decl
specifier|extern
name|void
name|lzma_check_finish
parameter_list|(
name|lzma_check_state
modifier|*
name|check
parameter_list|,
name|lzma_check
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|LZMA_SHA256FUNC
end_ifndef

begin_comment
comment|/// Prepare SHA-256 state for new input.
end_comment

begin_function_decl
specifier|extern
name|void
name|lzma_sha256_init
parameter_list|(
name|lzma_check_state
modifier|*
name|check
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Update the SHA-256 hash state
end_comment

begin_function_decl
specifier|extern
name|void
name|lzma_sha256_update
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|,
name|lzma_check_state
modifier|*
name|check
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Finish the SHA-256 calculation and store the result to check->buffer.u8.
end_comment

begin_function_decl
specifier|extern
name|void
name|lzma_sha256_finish
parameter_list|(
name|lzma_check_state
modifier|*
name|check
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
specifier|inline
name|void
name|lzma_sha256_init
parameter_list|(
name|lzma_check_state
modifier|*
name|check
parameter_list|)
block|{
name|LZMA_SHA256FUNC
argument_list|(
name|Init
argument_list|)
argument_list|(
operator|&
name|check
operator|->
name|state
operator|.
name|sha256
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|lzma_sha256_update
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|,
name|lzma_check_state
modifier|*
name|check
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|HAVE_CC_SHA256_INIT
argument_list|)
operator|&&
name|SIZE_MAX
operator|>
name|UINT32_MAX
comment|// Darwin's CC_SHA256_Update takes uint32_t as the buffer size,
comment|// so use a loop to support size_t.
while|while
condition|(
name|size
operator|>
name|UINT32_MAX
condition|)
block|{
name|LZMA_SHA256FUNC
argument_list|(
name|Update
argument_list|)
argument_list|(
operator|&
name|check
operator|->
name|state
operator|.
name|sha256
argument_list|,
name|buf
argument_list|,
name|UINT32_MAX
argument_list|)
expr_stmt|;
name|buf
operator|+=
name|UINT32_MAX
expr_stmt|;
name|size
operator|-=
name|UINT32_MAX
expr_stmt|;
block|}
endif|#
directive|endif
name|LZMA_SHA256FUNC
argument_list|(
name|Update
argument_list|)
argument_list|(
operator|&
name|check
operator|->
name|state
operator|.
name|sha256
argument_list|,
name|buf
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|lzma_sha256_finish
parameter_list|(
name|lzma_check_state
modifier|*
name|check
parameter_list|)
block|{
name|LZMA_SHA256FUNC
argument_list|(
name|Final
argument_list|)
argument_list|(
name|check
operator|->
name|buffer
operator|.
name|u8
argument_list|,
operator|&
name|check
operator|->
name|state
operator|.
name|sha256
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

