begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- xray_flags.h -------------------------------------------*- C++ -*-===//
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
comment|// This file is a part of XRay, a dynamic runtime instruementation system.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// XRay runtime flags.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XRAY_FLAGS_H
end_ifndef

begin_define
define|#
directive|define
name|XRAY_FLAGS_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_flag_parser.h"
end_include

begin_decl_stmt
name|namespace
name|__xray
block|{
struct|struct
name|Flags
block|{
define|#
directive|define
name|XRAY_FLAG
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
file|"xray_flags.inc"
undef|#
directive|undef
name|XRAY_FLAG
name|void
name|setDefaults
parameter_list|()
function_decl|;
block|}
struct|;
specifier|extern
name|Flags
name|xray_flags_dont_use_directly
decl_stmt|;
specifier|inline
name|Flags
modifier|*
name|flags
parameter_list|()
block|{
return|return
operator|&
name|xray_flags_dont_use_directly
return|;
block|}
name|void
name|initializeFlags
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __xray
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// XRAY_FLAGS_H
end_comment

end_unit

