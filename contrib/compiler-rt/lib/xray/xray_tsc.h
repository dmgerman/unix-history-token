begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- xray_tsc.h ----------------------------------------------*- C++ -*-===//
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
comment|// This file is a part of XRay, a dynamic runtime instrumentation system.
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
name|XRAY_EMULATE_TSC_H
end_ifndef

begin_define
define|#
directive|define
name|XRAY_EMULATE_TSC_H
end_define

begin_decl_stmt
name|namespace
name|__xray
block|{
specifier|static
name|constexpr
name|uint64_t
name|NanosecondsPerSecond
init|=
literal|1000ULL
operator|*
literal|1000
operator|*
literal|1000
decl_stmt|;
block|}
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_include
include|#
directive|include
file|"xray_x86_64.inc"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__powerpc64__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"xray_powerpc64.inc"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|||
name|defined
argument_list|(
name|__aarch64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips__
argument_list|)
end_elif

begin_comment
comment|// Emulated TSC.
end_comment

begin_comment
comment|// There is no instruction like RDTSCP in user mode on ARM. ARM's CP15 does
end_comment

begin_comment
comment|//   not have a constant frequency like TSC on x86(_64), it may go faster
end_comment

begin_comment
comment|//   or slower depending on CPU turbo or power saving mode. Furthermore,
end_comment

begin_comment
comment|//   to read from CP15 on ARM a kernel modification or a driver is needed.
end_comment

begin_comment
comment|//   We can not require this from users of compiler-rt.
end_comment

begin_comment
comment|// So on ARM we use clock_gettime() which gives the result in nanoseconds.
end_comment

begin_comment
comment|//   To get the measurements per second, we scale this by the number of
end_comment

begin_comment
comment|//   nanoseconds per second, pretending that the TSC frequency is 1GHz and
end_comment

begin_comment
comment|//   one TSC tick is 1 nanosecond.
end_comment

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_common.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_internal_defs.h"
end_include

begin_include
include|#
directive|include
file|"xray_defs.h"
end_include

begin_include
include|#
directive|include
file|<cerrno>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_decl_stmt
name|namespace
name|__xray
block|{
specifier|inline
name|bool
name|probeRequiredCPUFeatures
parameter_list|()
function|XRAY_NEVER_INSTRUMENT
block|{
return|return
name|true
return|;
block|}
name|ALWAYS_INLINE
name|uint64_t
name|readTSC
parameter_list|(
name|uint8_t
modifier|&
name|CPU
parameter_list|)
function|XRAY_NEVER_INSTRUMENT
block|{
name|timespec
name|TS
decl_stmt|;
name|int
name|result
init|=
name|clock_gettime
argument_list|(
name|CLOCK_REALTIME
argument_list|,
operator|&
name|TS
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|!=
literal|0
condition|)
block|{
name|Report
argument_list|(
literal|"clock_gettime(2) returned %d, errno=%d."
argument_list|,
name|result
argument_list|,
name|int
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
name|TS
operator|.
name|tv_sec
operator|=
literal|0
expr_stmt|;
name|TS
operator|.
name|tv_nsec
operator|=
literal|0
expr_stmt|;
block|}
name|CPU
operator|=
literal|0
expr_stmt|;
return|return
name|TS
operator|.
name|tv_sec
operator|*
name|NanosecondsPerSecond
operator|+
name|TS
operator|.
name|tv_nsec
return|;
block|}
specifier|inline
name|uint64_t
name|getTSCFrequency
parameter_list|()
function|XRAY_NEVER_INSTRUMENT
block|{
return|return
name|NanosecondsPerSecond
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace __xray
end_comment

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|Target architecture is not supported.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CPU architecture
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// XRAY_EMULATE_TSC_H
end_comment

end_unit

