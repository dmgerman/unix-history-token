begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- UUID.h --------------------------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLDB_UTILITY_UUID_H
end_ifndef

begin_define
define|#
directive|define
name|LLDB_UTILITY_UUID_H
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Stream
decl_stmt|;
name|class
name|UUID
block|{
name|public
label|:
comment|// Most UUIDs are 16 bytes, but some Linux build-ids (SHA1) are 20.
typedef|typedef
name|uint8_t
name|ValueType
index|[
literal|20
index|]
typedef|;
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|UUID
argument_list|()
expr_stmt|;
name|UUID
argument_list|(
specifier|const
name|UUID
operator|&
name|rhs
argument_list|)
expr_stmt|;
name|UUID
argument_list|(
argument|const void *uuid_bytes
argument_list|,
argument|uint32_t num_uuid_bytes
argument_list|)
empty_stmt|;
operator|~
name|UUID
argument_list|()
expr_stmt|;
specifier|const
name|UUID
modifier|&
name|operator
init|=
operator|(
specifier|const
name|UUID
operator|&
name|rhs
operator|)
decl_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|void
name|Dump
argument_list|(
name|Stream
operator|*
name|s
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|void
operator|*
name|GetBytes
argument_list|()
specifier|const
expr_stmt|;
name|size_t
name|GetByteSize
parameter_list|()
function_decl|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|SetBytes
parameter_list|(
specifier|const
name|void
modifier|*
name|uuid_bytes
parameter_list|,
name|uint32_t
name|num_uuid_bytes
init|=
literal|16
parameter_list|)
function_decl|;
name|std
operator|::
name|string
name|GetAsString
argument_list|(
argument|const char *separator = nullptr
argument_list|)
specifier|const
expr_stmt|;
name|size_t
name|SetFromCString
parameter_list|(
specifier|const
name|char
modifier|*
name|c_str
parameter_list|,
name|uint32_t
name|num_uuid_bytes
init|=
literal|16
parameter_list|)
function_decl|;
comment|// Decode as many UUID bytes (up to 16) as possible from the C string "cstr"
comment|// This is used for auto completion where a partial UUID might have been
comment|// typed in. It
comment|//------------------------------------------------------------------
comment|/// Decode as many UUID bytes (up to 16) as possible from the C
comment|/// string \a cstr.
comment|///
comment|/// @param[in] cstr
comment|///     A NULL terminate C string that points at a UUID string value
comment|///     (no leading spaces). The string must contain only hex
comment|///     characters and optionally can contain the '-' sepearators.
comment|///
comment|/// @param[in] uuid_bytes
comment|///     A buffer of bytes that will contain a full or patially
comment|///     decoded UUID.
comment|///
comment|/// @return
comment|///     The original string, with all decoded bytes removed.
comment|//------------------------------------------------------------------
specifier|static
name|llvm
operator|::
name|StringRef
name|DecodeUUIDBytesFromString
argument_list|(
argument|llvm::StringRef str
argument_list|,
argument|ValueType&uuid_bytes
argument_list|,
argument|uint32_t&bytes_decoded
argument_list|,
argument|uint32_t num_uuid_bytes =
literal|16
argument_list|)
expr_stmt|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Classes that inherit from UUID can see and modify these
comment|//------------------------------------------------------------------
name|uint32_t
name|m_num_uuid_bytes
decl_stmt|;
comment|// Should be 16 or 20
name|ValueType
name|m_uuid
decl_stmt|;
block|}
empty_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|UUID
operator|&
name|lhs
operator|,
specifier|const
name|UUID
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|UUID
operator|&
name|lhs
operator|,
specifier|const
name|UUID
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|operator
operator|<
operator|(
specifier|const
name|UUID
operator|&
name|lhs
operator|,
specifier|const
name|UUID
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|UUID
operator|&
name|lhs
operator|,
specifier|const
name|UUID
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|operator
operator|>
operator|(
specifier|const
name|UUID
operator|&
name|lhs
operator|,
specifier|const
name|UUID
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|UUID
operator|&
name|lhs
operator|,
specifier|const
name|UUID
operator|&
name|rhs
operator|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_UTILITY_UUID_H
end_comment

end_unit

