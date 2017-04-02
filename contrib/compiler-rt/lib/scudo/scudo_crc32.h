begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- scudo_crc32.h -------------------------------------------*- C++ -*-===//
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
comment|/// Header for scudo_crc32.cpp.
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
name|SCUDO_CRC32_H_
end_ifndef

begin_define
define|#
directive|define
name|SCUDO_CRC32_H_
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_internal_defs.h"
end_include

begin_decl_stmt
name|namespace
name|__scudo
block|{
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
name|computeCRC32
parameter_list|(
name|u32
name|Crc
parameter_list|,
name|uptr
name|Data
parameter_list|,
name|u8
name|HashType
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
comment|// SCUDO_CRC32_H_
end_comment

end_unit

