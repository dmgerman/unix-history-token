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
name|sha256
struct|;
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

