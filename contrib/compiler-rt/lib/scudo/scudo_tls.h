begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- scudo_tls.h ---------------------------------------------*- C++ -*-===//
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
comment|/// Scudo thread local structure definition.
end_comment

begin_comment
comment|/// Implementation will differ based on the thread local storage primitives
end_comment

begin_comment
comment|/// offered by the underlying platform.
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
name|SCUDO_TLS_H_
end_ifndef

begin_define
define|#
directive|define
name|SCUDO_TLS_H_
end_define

begin_include
include|#
directive|include
file|"scudo_allocator.h"
end_include

begin_include
include|#
directive|include
file|"scudo_utils.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_linux.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_platform.h"
end_include

begin_decl_stmt
name|namespace
name|__scudo
block|{
comment|// Platform specific base thread context definitions.
include|#
directive|include
file|"scudo_tls_context_android.inc"
include|#
directive|include
file|"scudo_tls_context_linux.inc"
name|struct
name|ALIGNED
argument_list|(
literal|64
argument_list|)
name|ScudoThreadContext
range|:
name|public
name|ScudoThreadContextPlatform
block|{
name|AllocatorCache
name|Cache
block|;
name|Xorshift128Plus
name|Prng
block|;
name|uptr
name|QuarantineCachePlaceHolder
index|[
literal|4
index|]
block|;
name|void
name|init
argument_list|()
block|;
name|void
name|commitBack
argument_list|()
block|; }
decl_stmt|;
name|void
name|initThread
parameter_list|()
function_decl|;
comment|// Platform specific dastpath functions definitions.
include|#
directive|include
file|"scudo_tls_android.inc"
include|#
directive|include
file|"scudo_tls_linux.inc"
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
comment|// SCUDO_TLS_H_
end_comment

end_unit

