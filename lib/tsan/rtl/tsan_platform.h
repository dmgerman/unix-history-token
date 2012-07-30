begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- tsan_platform.h -----------------------------------------*- C++ -*-===//
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
comment|//
end_comment

begin_comment
comment|// Platform-specific code.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TSAN_PLATFORM_H
end_ifndef

begin_define
define|#
directive|define
name|TSAN_PLATFORM_H
end_define

begin_include
include|#
directive|include
file|"tsan_rtl.h"
end_include

begin_if
if|#
directive|if
name|__LP64__
end_if

begin_decl_stmt
name|namespace
name|__tsan
block|{
if|#
directive|if
name|defined
argument_list|(
name|TSAN_GO
argument_list|)
specifier|static
specifier|const
name|uptr
name|kLinuxAppMemBeg
init|=
literal|0x000000000000ULL
decl_stmt|;
specifier|static
specifier|const
name|uptr
name|kLinuxAppMemEnd
init|=
literal|0x00fcffffffffULL
decl_stmt|;
specifier|static
specifier|const
name|uptr
name|kLinuxShadowMsk
init|=
literal|0x100000000000ULL
decl_stmt|;
comment|// TSAN_COMPAT_SHADOW is intended for COMPAT virtual memory layout,
comment|// when memory addresses are of the 0x2axxxxxxxxxx form.
comment|// The option is enabled with 'setarch x86_64 -L'.
elif|#
directive|elif
name|defined
argument_list|(
name|TSAN_COMPAT_SHADOW
argument_list|)
operator|&&
name|TSAN_COMPAT_SHADOW
specifier|static
specifier|const
name|uptr
name|kLinuxAppMemBeg
init|=
literal|0x2a0000000000ULL
decl_stmt|;
specifier|static
specifier|const
name|uptr
name|kLinuxAppMemEnd
init|=
literal|0x7fffffffffffULL
decl_stmt|;
else|#
directive|else
specifier|static
specifier|const
name|uptr
name|kLinuxAppMemBeg
init|=
literal|0x7ef000000000ULL
decl_stmt|;
specifier|static
specifier|const
name|uptr
name|kLinuxAppMemEnd
init|=
literal|0x7fffffffffffULL
decl_stmt|;
endif|#
directive|endif
specifier|static
specifier|const
name|uptr
name|kLinuxAppMemMsk
init|=
literal|0x7c0000000000ULL
decl_stmt|;
comment|// This has to be a macro to allow constant initialization of constants below.
ifndef|#
directive|ifndef
name|TSAN_GO
define|#
directive|define
name|MemToShadow
parameter_list|(
name|addr
parameter_list|)
define|\
value|(((addr)& ~(kLinuxAppMemMsk | (kShadowCell - 1))) * kShadowCnt)
else|#
directive|else
define|#
directive|define
name|MemToShadow
parameter_list|(
name|addr
parameter_list|)
define|\
value|((((addr)& ~(kShadowCell - 1)) * kShadowCnt) | kLinuxShadowMsk)
endif|#
directive|endif
specifier|static
specifier|const
name|uptr
name|kLinuxShadowBeg
init|=
name|MemToShadow
argument_list|(
name|kLinuxAppMemBeg
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|uptr
name|kLinuxShadowEnd
init|=
name|MemToShadow
argument_list|(
name|kLinuxAppMemEnd
argument_list|)
operator||
operator|(
name|kPageSize
operator|-
literal|1
operator|)
decl_stmt|;
specifier|static
specifier|inline
name|bool
name|IsAppMem
parameter_list|(
name|uptr
name|mem
parameter_list|)
block|{
return|return
name|mem
operator|>=
name|kLinuxAppMemBeg
operator|&&
name|mem
operator|<=
name|kLinuxAppMemEnd
return|;
block|}
specifier|static
specifier|inline
name|bool
name|IsShadowMem
parameter_list|(
name|uptr
name|mem
parameter_list|)
block|{
return|return
name|mem
operator|>=
name|kLinuxShadowBeg
operator|&&
name|mem
operator|<=
name|kLinuxShadowEnd
return|;
block|}
specifier|static
specifier|inline
name|uptr
name|ShadowToMem
parameter_list|(
name|uptr
name|shadow
parameter_list|)
block|{
name|CHECK
argument_list|(
name|IsShadowMem
argument_list|(
name|shadow
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|TSAN_GO
return|return
operator|(
name|shadow
operator|&
operator|~
name|kLinuxShadowMsk
operator|)
operator|/
name|kShadowCnt
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|TSAN_COMPAT_SHADOW
argument_list|)
operator|&&
name|TSAN_COMPAT_SHADOW
comment|// COMPAT mapping is not quite one-to-one.
return|return
operator|(
name|shadow
operator|/
name|kShadowCnt
operator|)
operator||
literal|0x280000000000ULL
return|;
else|#
directive|else
return|return
operator|(
name|shadow
operator|/
name|kShadowCnt
operator|)
operator||
name|kLinuxAppMemMsk
return|;
endif|#
directive|endif
block|}
comment|// For COMPAT mapping returns an alternative address
comment|// that mapped to the same shadow address.
specifier|static
specifier|inline
name|uptr
name|AlternativeAddress
parameter_list|(
name|uptr
name|addr
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|TSAN_COMPAT_SHADOW
argument_list|)
operator|&&
name|TSAN_COMPAT_SHADOW
return|return
name|addr
operator||
name|kLinuxAppMemMsk
return|;
else|#
directive|else
return|return
literal|0
return|;
endif|#
directive|endif
block|}
name|uptr
name|GetShadowMemoryConsumption
parameter_list|()
function_decl|;
name|void
name|FlushShadowMemory
parameter_list|()
function_decl|;
specifier|const
name|char
modifier|*
name|InitializePlatform
parameter_list|()
function_decl|;
name|void
name|FinalizePlatform
parameter_list|()
function_decl|;
name|void
name|internal_start_thread
parameter_list|(
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|uptr
name|GetTlsSize
parameter_list|()
function_decl|;
name|void
name|GetThreadStackAndTls
argument_list|(
name|bool
expr|main
argument_list|,
name|uptr
operator|*
name|stk_addr
argument_list|,
name|uptr
operator|*
name|stk_size
argument_list|,
name|uptr
operator|*
name|tls_addr
argument_list|,
name|uptr
operator|*
name|tls_size
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __tsan
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|// __LP64__
end_comment

begin_error
error|#
directive|error
literal|"Only 64-bit is supported"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// TSAN_PLATFORM_H
end_comment

end_unit

