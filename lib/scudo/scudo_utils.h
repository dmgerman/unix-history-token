begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- scudo_utils.h -------------------------------------------*- C++ -*-===//
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
comment|/// Header for scudo_utils.cpp.
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
name|SCUDO_UTILS_H_
end_ifndef

begin_define
define|#
directive|define
name|SCUDO_UTILS_H_
end_define

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_common.h"
end_include

begin_decl_stmt
name|namespace
name|__scudo
block|{
name|template
operator|<
name|class
name|Dest
operator|,
name|class
name|Source
operator|>
specifier|inline
name|Dest
name|bit_cast
argument_list|(
argument|const Source& source
argument_list|)
block|{
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|Dest
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|Source
argument_list|)
argument_list|,
literal|"Sizes are not equal!"
argument_list|)
block|;
name|Dest
name|dest
block|;
name|memcpy
argument_list|(
operator|&
name|dest
argument_list|,
operator|&
name|source
argument_list|,
sizeof|sizeof
argument_list|(
name|dest
argument_list|)
argument_list|)
block|;
return|return
name|dest
return|;
block|}
name|void
name|NORETURN
name|dieWithMessage
parameter_list|(
specifier|const
name|char
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
enum|enum
name|CPUFeature
block|{
name|CRC32CPUFeature
init|=
literal|0
block|,
name|MaxCPUFeature
block|, }
enum|;
name|bool
name|testCPUFeature
parameter_list|(
name|CPUFeature
name|feature
parameter_list|)
function_decl|;
comment|// Tiny PRNG based on https://en.wikipedia.org/wiki/Xorshift#xorshift.2B
comment|// The state (128 bits) will be stored in thread local storage.
struct|struct
name|Xorshift128Plus
block|{
name|public
label|:
name|Xorshift128Plus
argument_list|()
expr_stmt|;
name|u64
name|Next
parameter_list|()
block|{
name|u64
name|x
init|=
name|State
index|[
literal|0
index|]
decl_stmt|;
specifier|const
name|u64
name|y
init|=
name|State
index|[
literal|1
index|]
decl_stmt|;
name|State
index|[
literal|0
index|]
operator|=
name|y
expr_stmt|;
name|x
operator|^=
name|x
operator|<<
literal|23
expr_stmt|;
name|State
index|[
literal|1
index|]
operator|=
name|x
operator|^
name|y
operator|^
operator|(
name|x
operator|>>
literal|17
operator|)
operator|^
operator|(
name|y
operator|>>
literal|26
operator|)
expr_stmt|;
return|return
name|State
index|[
literal|1
index|]
operator|+
name|y
return|;
block|}
name|private
label|:
name|u64
name|State
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
enum_decl|enum :
name|u8
block|{
name|CRC32Software
init|=
literal|0
block|,
name|CRC32Hardware
init|=
literal|1
block|, }
enum_decl|;
name|u32
name|computeSoftwareCRC32
parameter_list|(
name|u32
name|Crc
parameter_list|,
name|uptr
name|Data
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __scudo
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SCUDO_UTILS_H_
end_comment

end_unit

