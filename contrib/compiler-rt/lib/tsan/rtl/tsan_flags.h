begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- tsan_flags.h --------------------------------------------*- C++ -*-===//
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
comment|// This file is a part of ThreadSanitizer (TSan), a race detector.
end_comment

begin_comment
comment|// NOTE: This file may be included into user code.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TSAN_FLAGS_H
end_ifndef

begin_define
define|#
directive|define
name|TSAN_FLAGS_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_flags.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_deadlock_detector_interface.h"
end_include

begin_decl_stmt
name|namespace
name|__tsan
block|{
name|struct
name|Flags
range|:
name|DDFlags
block|{
define|#
directive|define
name|TSAN_FLAG
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
file|"tsan_flags.inc"
undef|#
directive|undef
name|TSAN_FLAG
name|void
name|SetDefaults
argument_list|()
block|;
name|void
name|ParseFromString
argument_list|(
specifier|const
name|char
operator|*
name|str
argument_list|)
block|; }
decl_stmt|;
name|void
name|InitializeFlags
parameter_list|(
name|Flags
modifier|*
name|flags
parameter_list|,
specifier|const
name|char
modifier|*
name|env
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __tsan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// TSAN_FLAGS_H
end_comment

end_unit

