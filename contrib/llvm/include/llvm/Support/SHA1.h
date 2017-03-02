begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- SHA1.h - SHA1 implementation for LLVM                     --*- C++ -*-==//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// This code is taken from public domain
end_comment

begin_comment
comment|// (http://oauth.googlecode.com/svn/code/c/liboauth/src/sha1.c)
end_comment

begin_comment
comment|// and modified by wrapping it in a C++ interface for LLVM,
end_comment

begin_comment
comment|// and removing unnecessary code.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_SUPPORT_SHA1_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_SHA1_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|<array>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ArrayRef
expr_stmt|;
name|class
name|StringRef
decl_stmt|;
comment|/// A class that wrap the SHA1 algorithm.
name|class
name|SHA1
block|{
name|public
label|:
name|SHA1
argument_list|()
block|{
name|init
argument_list|()
expr_stmt|;
block|}
comment|/// Reinitialize the internal state
name|void
name|init
parameter_list|()
function_decl|;
comment|/// Digest more data.
name|void
name|update
argument_list|(
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Data
argument_list|)
decl_stmt|;
comment|/// Digest more data.
name|void
name|update
parameter_list|(
name|StringRef
name|Str
parameter_list|)
block|{
name|update
argument_list|(
name|ArrayRef
operator|<
name|uint8_t
operator|>
operator|(
operator|(
name|uint8_t
operator|*
operator|)
name|const_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|Str
operator|.
name|data
argument_list|()
operator|)
operator|,
name|Str
operator|.
name|size
argument_list|()
operator|)
argument_list|)
expr_stmt|;
block|}
comment|/// Return a reference to the current raw 160-bits SHA1 for the digested data
comment|/// since the last call to init(). This call will add data to the internal
comment|/// state and as such is not suited for getting an intermediate result
comment|/// (see result()).
name|StringRef
name|final
parameter_list|()
function_decl|;
comment|/// Return a reference to the current raw 160-bits SHA1 for the digested data
comment|/// since the last call to init(). This is suitable for getting the SHA1 at
comment|/// any time without invalidating the internal state so that more calls can be
comment|/// made into update.
name|StringRef
name|result
parameter_list|()
function_decl|;
comment|/// Returns a raw 160-bit SHA1 hash for the given data.
specifier|static
name|std
operator|::
name|array
operator|<
name|uint8_t
operator|,
literal|20
operator|>
name|hash
argument_list|(
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Data
argument_list|)
expr_stmt|;
name|private
label|:
comment|/// Define some constants.
comment|/// "static constexpr" would be cleaner but MSVC does not support it yet.
enum|enum
block|{
name|BLOCK_LENGTH
init|=
literal|64
block|}
enum|;
enum|enum
block|{
name|HASH_LENGTH
init|=
literal|20
block|}
enum|;
comment|// Internal State
struct|struct
block|{
union|union
block|{
name|uint8_t
name|C
index|[
name|BLOCK_LENGTH
index|]
decl_stmt|;
name|uint32_t
name|L
index|[
name|BLOCK_LENGTH
operator|/
literal|4
index|]
decl_stmt|;
block|}
name|Buffer
union|;
name|uint32_t
name|State
index|[
name|HASH_LENGTH
operator|/
literal|4
index|]
decl_stmt|;
name|uint32_t
name|ByteCount
decl_stmt|;
name|uint8_t
name|BufferOffset
decl_stmt|;
block|}
name|InternalState
struct|;
comment|// Internal copy of the hash, populated and accessed on calls to result()
name|uint32_t
name|HashResult
index|[
name|HASH_LENGTH
operator|/
literal|4
index|]
decl_stmt|;
comment|// Helper
name|void
name|writebyte
parameter_list|(
name|uint8_t
name|data
parameter_list|)
function_decl|;
name|void
name|hashBlock
parameter_list|()
function_decl|;
name|void
name|addUncounted
parameter_list|(
name|uint8_t
name|data
parameter_list|)
function_decl|;
name|void
name|pad
parameter_list|()
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

