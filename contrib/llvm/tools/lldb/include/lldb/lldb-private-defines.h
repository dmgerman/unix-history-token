begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lldb-private-defines.h ----------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_lldb_private_defines_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_lldb_private_defines_h_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_comment
comment|// Include Compiler.h here so we don't define LLVM_FALLTHROUGH and then
end_comment

begin_comment
comment|// Compiler.h
end_comment

begin_comment
comment|// later tries to redefine it.
end_comment

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_FALLTHROUGH
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__has_cpp_attribute
end_ifndef

begin_define
define|#
directive|define
name|__has_cpp_attribute
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \macro LLVM_FALLTHROUGH
end_comment

begin_comment
comment|/// \brief Marks an empty statement preceding a deliberate switch fallthrough.
end_comment

begin_if
if|#
directive|if
name|__has_cpp_attribute
argument_list|(
name|clang
operator|::
name|fallthrough
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_FALLTHROUGH
value|[[clang::fallthrough]]
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_FALLTHROUGH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ifndef LLVM_FALLTHROUGH
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #if defined(__cplusplus)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_lldb_private_defines_h_
end_comment

end_unit

