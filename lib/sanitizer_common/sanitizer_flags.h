begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_flags.h ---------------------------------------*- C++ -*-===//
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
comment|// This file is a part of ThreadSanitizer/AddressSanitizer runtime.
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
name|SANITIZER_FLAGS_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_FLAGS_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_internal_defs.h"
end_include

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
name|void
name|ParseFlag
parameter_list|(
specifier|const
name|char
modifier|*
name|env
parameter_list|,
name|bool
modifier|*
name|flag
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
name|void
name|ParseFlag
parameter_list|(
specifier|const
name|char
modifier|*
name|env
parameter_list|,
name|int
modifier|*
name|flag
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
name|void
name|ParseFlag
parameter_list|(
specifier|const
name|char
modifier|*
name|env
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|flag
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __sanitizer
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_FLAGS_H
end_comment

end_unit

