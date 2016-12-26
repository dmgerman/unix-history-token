begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- stats.h -------------------------------------------------*- C++ -*-===//
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
comment|//
end_comment

begin_comment
comment|// Data definitions for sanitizer statistics gathering.
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
name|SANITIZER_STATS_STATS_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_STATS_STATS_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_internal_defs.h"
end_include

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
comment|// Number of bits in data that are used for the sanitizer kind. Needs to match
comment|// llvm::kSanitizerStatKindBits in
comment|// llvm/include/llvm/Transforms/Utils/SanitizerStats.h
enum|enum
block|{
name|kKindBits
init|=
literal|3
block|}
enum|;
struct|struct
name|StatInfo
block|{
name|uptr
name|addr
decl_stmt|;
name|uptr
name|data
decl_stmt|;
block|}
struct|;
struct|struct
name|StatModule
block|{
name|StatModule
modifier|*
name|next
decl_stmt|;
name|u32
name|size
decl_stmt|;
name|StatInfo
name|infos
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
specifier|inline
name|uptr
name|CountFromData
parameter_list|(
name|uptr
name|data
parameter_list|)
block|{
return|return
name|data
operator|&
operator|(
operator|(
literal|1ull
operator|<<
operator|(
sizeof|sizeof
argument_list|(
name|uptr
argument_list|)
operator|*
literal|8
operator|-
name|kKindBits
operator|)
operator|)
operator|-
literal|1
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

