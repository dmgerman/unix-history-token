begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- xray_emulate_tsc.h --------------------------------------*- C++ -*-===//
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
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// XRAY_EMULATE_TSC_H
end_comment

end_unit

