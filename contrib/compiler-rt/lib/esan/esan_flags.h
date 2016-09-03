begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- esan_flags.h --------------------------------------------*- C++ -*-===//
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
comment|// This file is a part of EfficiencySanitizer, a family of performance tuners.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Esan runtime flags.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ESAN_FLAGS_H
end_ifndef

begin_define
define|#
directive|define
name|ESAN_FLAGS_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_internal_defs.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_flag_parser.h"
end_include

begin_decl_stmt
name|namespace
name|__esan
block|{
name|class
name|Flags
block|{
name|public
label|:
define|#
directive|define
name|ESAN_FLAG
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
file|"esan_flags.inc"
undef|#
directive|undef
name|ESAN_FLAG
name|void
name|setDefaults
parameter_list|()
function_decl|;
block|}
empty_stmt|;
specifier|extern
name|Flags
name|EsanFlagsDontUseDirectly
decl_stmt|;
specifier|inline
name|Flags
modifier|*
name|getFlags
parameter_list|()
block|{
return|return
operator|&
name|EsanFlagsDontUseDirectly
return|;
block|}
name|void
name|initializeFlags
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __esan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ESAN_FLAGS_H
end_comment

end_unit

