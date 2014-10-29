begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 ARM Ltd  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the company may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY ARM LTD ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL ARM LTD BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ARM_ARCH
end_ifndef

begin_comment
comment|/* ACLE standardises a set of pre-defines that describe the ARM architecture.    These were mostly implemented in GCC around GCC-4.8; older versions    have no, or only partial support.  To provide a level of backwards    compatibility we try to work out what the definitions should be, given    the older pre-defines that GCC did produce.  This isn't complete, but    it should be enough for use by routines that depend on this header.  */
end_comment

begin_comment
comment|/* No need to handle ARMv8, GCC had ACLE support before that.  */
end_comment

begin_define
define|#
directive|define
name|__ARM_ACLE
value|101
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__ARM_ARCH_7__
end_ifdef

begin_comment
comment|/* The common subset of ARMv7 in all profiles.  */
end_comment

begin_define
define|#
directive|define
name|__ARM_ARCH
value|7
end_define

begin_define
define|#
directive|define
name|__ARM_ARCH_ISA_THUMB
value|2
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_CLZ
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_LDREX
value|7
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_UNALIGNED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_ARCH_7A__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_7R__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__ARM_ARCH
value|7
end_define

begin_define
define|#
directive|define
name|__ARM_ARCH_ISA_THUMB
value|2
end_define

begin_define
define|#
directive|define
name|__ARM_ARCH_ISA_ARM
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_CLZ
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_SIMD32
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_DSP
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_QBIT
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_SAT
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_LDREX
value|15
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_UNALIGNED
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__ARM_ARCH_7A__
end_ifdef

begin_define
define|#
directive|define
name|__ARM_ARCH_PROFILE
value|'A'
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__ARM_ARCH_PROFILE
value|'R'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__ARM_ARCH_7EM__
end_ifdef

begin_define
define|#
directive|define
name|__ARM_ARCH
value|7
end_define

begin_define
define|#
directive|define
name|__ARM_ARCH_ISA_THUMB
value|2
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_CLZ
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_SIMD32
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_DSP
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_QBIT
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_SAT
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_LDREX
value|7
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_UNALIGNED
end_define

begin_define
define|#
directive|define
name|__ARM_ARCH_PROFILE
value|'M'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__ARM_ARCH_7M__
end_ifdef

begin_define
define|#
directive|define
name|__ARM_ARCH
value|7
end_define

begin_define
define|#
directive|define
name|__ARM_ARCH_ISA_THUMB
value|2
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_CLZ
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_QBIT
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_SAT
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_LDREX
value|7
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_UNALIGNED
end_define

begin_define
define|#
directive|define
name|__ARM_ARCH_PROFILE
value|'M'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__ARM_ARCH_6T2__
end_ifdef

begin_define
define|#
directive|define
name|__ARM_ARCH
value|6
end_define

begin_define
define|#
directive|define
name|__ARM_ARCH_ISA_THUMB
value|2
end_define

begin_define
define|#
directive|define
name|__ARM_ARCH_ISA_ARM
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_CLZ
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_SIMD32
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_DSP
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_QBIT
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_SAT
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_LDREX
value|4
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_UNALIGNED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__ARM_ARCH_6M__
end_ifdef

begin_define
define|#
directive|define
name|__ARM_ARCH
value|6
end_define

begin_define
define|#
directive|define
name|__ARM_ARCH_ISA_THUMB
value|1
end_define

begin_define
define|#
directive|define
name|__ARM_ARCH_PROFILE
value|'M'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_ARCH_6__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6J__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6K__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6Z__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6ZK__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__ARM_ARCH
value|6
end_define

begin_define
define|#
directive|define
name|__ARM_ARCH_ISA_THUMB
value|1
end_define

begin_define
define|#
directive|define
name|__ARM_ARCH_ISA_ARM
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_CLZ
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_SIMD32
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_DSP
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_QBIT
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_SAT
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_UNALIGNED
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__thumb__
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_ARCH_6K__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6ZK__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__ARM_FEATURE_LDREX
value|15
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__ARM_FEATURE_LDREX
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_ARCH_5TE__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_5E__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__ARM_ARCH
value|5
end_define

begin_define
define|#
directive|define
name|__ARM_ARCH_ISA_ARM
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__ARM_ARCH_5TE__
end_ifdef

begin_define
define|#
directive|define
name|__ARM_ARCH_ISA_THUMB
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__ARM_FEATURE_CLZ
end_define

begin_define
define|#
directive|define
name|__ARM_FEATURE_DSP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_ARCH_5T__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_5__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__ARM_ARCH
value|5
end_define

begin_define
define|#
directive|define
name|__ARM_ARCH_ISA_ARM
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__ARM_ARCH_5TE__
end_ifdef

begin_define
define|#
directive|define
name|__ARM_ARCH_ISA_THUMB
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__ARM_FEATURE_CLZ
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__ARM_ARCH_4T__
end_ifdef

begin_define
define|#
directive|define
name|__ARM_ARCH
value|4
end_define

begin_define
define|#
directive|define
name|__ARM_ARCH_ISA_ARM
end_define

begin_define
define|#
directive|define
name|__ARM_ARCH_ISA_THUMB
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__ARM_ARCH_4__
end_ifdef

begin_define
define|#
directive|define
name|__ARM_ARCH
value|4
end_define

begin_define
define|#
directive|define
name|__ARM_ARCH_ISA_ARM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_ARCH_3__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_3M__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__ARM_ARCH
value|3
end_define

begin_define
define|#
directive|define
name|__ARM_ARCH_ISA_ARM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__ARM_ARCH_2__
end_ifdef

begin_define
define|#
directive|define
name|__ARM_ARCH
value|2
end_define

begin_define
define|#
directive|define
name|__ARM_ARCH_ISA_ARM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__ARMEB__
end_ifdef

begin_define
define|#
directive|define
name|__ARM_BIG_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If we still don't know what the target architecture is, then we're    probably not using GCC.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ARM_ARCH
end_ifndef

begin_error
error|#
directive|error
error|Unable to determine architecture version.
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
comment|/* __ARM_ARCH  */
end_comment

end_unit

