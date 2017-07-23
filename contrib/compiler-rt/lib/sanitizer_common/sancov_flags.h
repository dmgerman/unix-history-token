begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sancov_flags.h ------------------------------------------*- C++ -*-===//
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
comment|// Sanitizer Coverage runtime flags.
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
name|SANCOV_FLAGS_H
end_ifndef

begin_define
define|#
directive|define
name|SANCOV_FLAGS_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_flag_parser.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_internal_defs.h"
end_include

begin_decl_stmt
name|namespace
name|__sancov
block|{
struct|struct
name|SancovFlags
block|{
define|#
directive|define
name|SANCOV_FLAG
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
file|"sancov_flags.inc"
undef|#
directive|undef
name|SANCOV_FLAG
name|void
name|SetDefaults
parameter_list|()
function_decl|;
block|}
struct|;
specifier|extern
name|SancovFlags
name|sancov_flags_dont_use_directly
decl_stmt|;
specifier|inline
name|SancovFlags
modifier|*
name|sancov_flags
parameter_list|()
block|{
return|return
operator|&
name|sancov_flags_dont_use_directly
return|;
block|}
name|void
name|InitializeSancovFlags
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __sancov
end_comment

begin_extern
extern|extern
literal|"C"
name|SANITIZER_INTERFACE_ATTRIBUTE
name|SANITIZER_WEAK_ATTRIBUTE
specifier|const
name|char
modifier|*
name|__sancov_default_options
parameter_list|()
function_decl|;
end_extern

begin_endif
endif|#
directive|endif
end_endif

end_unit

