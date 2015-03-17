begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- AddressSpaces.h - Language-specific address spaces -----*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Provides definitions for the various language-specific address
end_comment

begin_comment
comment|/// spaces.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_BASIC_ADDRESSSPACES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_ADDRESSSPACES_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|LangAS
block|{
comment|/// \brief Defines the set of possible language-specific address spaces.
comment|///
comment|/// This uses a high starting offset so as not to conflict with any address
comment|/// space used by a target.
enum|enum
name|ID
block|{
name|Offset
init|=
literal|0xFFFF00
block|,
name|opencl_global
init|=
name|Offset
block|,
name|opencl_local
block|,
name|opencl_constant
block|,
name|opencl_generic
block|,
name|cuda_device
block|,
name|cuda_constant
block|,
name|cuda_shared
block|,
name|Last
block|,
name|Count
init|=
name|Last
operator|-
name|Offset
block|}
enum|;
comment|/// The type of a lookup table which maps from language-specific address spaces
comment|/// to target-specific ones.
typedef|typedef
name|unsigned
name|Map
index|[
name|Count
index|]
typedef|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

