begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- xray_x86_64.h -------------------------------------------*- C++ -*-===//
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
name|XRAY_X86_64_H
end_ifndef

begin_define
define|#
directive|define
name|XRAY_X86_64_H
end_define

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<x86intrin.h>
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

begin_decl_stmt
name|namespace
name|__xray
block|{
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
name|unsigned
name|LongCPU
decl_stmt|;
name|uint64_t
name|TSC
init|=
name|__rdtscp
argument_list|(
operator|&
name|LongCPU
argument_list|)
decl_stmt|;
name|CPU
operator|=
name|LongCPU
expr_stmt|;
return|return
name|TSC
return|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// XRAY_X86_64_H
end_comment

end_unit

