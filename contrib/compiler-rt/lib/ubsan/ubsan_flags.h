begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ubsan_flags.h -------------------------------------------*- C++ -*-===//
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
comment|// Runtime flags for UndefinedBehaviorSanitizer.
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
name|UBSAN_FLAGS_H
end_ifndef

begin_define
define|#
directive|define
name|UBSAN_FLAGS_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_internal_defs.h"
end_include

begin_decl_stmt
name|namespace
name|__ubsan
block|{
struct|struct
name|Flags
block|{
name|bool
name|halt_on_error
decl_stmt|;
name|bool
name|print_stacktrace
decl_stmt|;
block|}
struct|;
specifier|extern
name|Flags
name|ubsan_flags
decl_stmt|;
specifier|inline
name|Flags
modifier|*
name|flags
parameter_list|()
block|{
return|return
operator|&
name|ubsan_flags
return|;
block|}
name|void
name|InitializeCommonFlags
parameter_list|()
function_decl|;
name|void
name|InitializeFlags
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __ubsan
end_comment

begin_extern
extern|extern
literal|"C"
block|{
comment|// Users may provide their own implementation of __ubsan_default_options to
comment|// override the default flag values.
name|SANITIZER_INTERFACE_ATTRIBUTE
name|SANITIZER_WEAK_ATTRIBUTE
specifier|const
name|char
modifier|*
name|__ubsan_default_options
parameter_list|()
function_decl|;
block|}
end_extern

begin_comment
comment|// extern "C"
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// UBSAN_FLAGS_H
end_comment

end_unit

