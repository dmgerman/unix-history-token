begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- msan_flags.h --------------------------------------------*- C++ -*-===//
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
comment|// This file is a part of MemorySanitizer.
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
name|MSAN_FLAGS_H
end_ifndef

begin_define
define|#
directive|define
name|MSAN_FLAGS_H
end_define

begin_decl_stmt
name|namespace
name|__msan
block|{
struct|struct
name|Flags
block|{
define|#
directive|define
name|MSAN_FLAG
parameter_list|(
name|Type
parameter_list|,
name|Name
parameter_list|,
name|DefaultValue
parameter_list|,
name|Description
parameter_list|)
value|Type Name;
include|#
directive|include
file|"msan_flags.inc"
undef|#
directive|undef
name|MSAN_FLAG
name|void
name|SetDefaults
parameter_list|()
function_decl|;
block|}
struct|;
name|Flags
modifier|*
name|flags
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __msan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// MSAN_FLAGS_H
end_comment

end_unit

