begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- scudo_tls_linux.h ---------------------------------------*- C++ -*-===//
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
comment|/// Scudo thread local structure fastpath functions implementation for platforms
end_comment

begin_comment
comment|/// supporting thread_local.
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
name|SCUDO_TLS_LINUX_H_
end_ifndef

begin_define
define|#
directive|define
name|SCUDO_TLS_LINUX_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SCUDO_TLS_H_
end_ifndef

begin_error
error|#
directive|error
literal|"This file must be included inside scudo_tls.h."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SCUDO_TLS_H_
end_comment

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_platform.h"
end_include

begin_if
if|#
directive|if
name|SANITIZER_LINUX
end_if

begin_enum
enum|enum
name|ThreadState
enum|:
name|u8
block|{
name|ThreadNotInitialized
init|=
literal|0
block|,
name|ThreadInitialized
block|,
name|ThreadTornDown
block|, }
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|thread_local
name|ThreadState
name|ScudoThreadState
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|thread_local
name|ScudoThreadContext
name|ThreadLocalContext
decl_stmt|;
end_decl_stmt

begin_function
name|ALWAYS_INLINE
name|void
name|initThreadMaybe
parameter_list|()
block|{
if|if
condition|(
name|LIKELY
argument_list|(
name|ScudoThreadState
operator|!=
name|ThreadNotInitialized
argument_list|)
condition|)
return|return;
name|initThread
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|ALWAYS_INLINE
name|ScudoThreadContext
modifier|*
name|getThreadContext
parameter_list|()
block|{
if|if
condition|(
name|UNLIKELY
argument_list|(
name|ScudoThreadState
operator|==
name|ThreadTornDown
argument_list|)
condition|)
return|return
name|nullptr
return|;
return|return
operator|&
name|ThreadLocalContext
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_LINUX
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SCUDO_TLS_LINUX_H_
end_comment

end_unit

