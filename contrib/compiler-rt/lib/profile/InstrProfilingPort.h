begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===- InstrProfilingPort.h- Support library for PGO instrumentation ------===*\ |* |*                     The LLVM Compiler Infrastructure |* |* This file is distributed under the University of Illinois Open Source |* License. See LICENSE.TXT for details. |* \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PROFILE_INSTRPROFILING_PORT_H_
end_ifndef

begin_define
define|#
directive|define
name|PROFILE_INSTRPROFILING_PORT_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_define
define|#
directive|define
name|COMPILER_RT_ALIGNAS
parameter_list|(
name|x
parameter_list|)
value|__declspec(align(x))
end_define

begin_define
define|#
directive|define
name|COMPILER_RT_VISIBILITY
end_define

begin_define
define|#
directive|define
name|COMPILER_RT_WEAK
value|__declspec(selectany)
end_define

begin_elif
elif|#
directive|elif
name|__GNUC__
end_elif

begin_define
define|#
directive|define
name|COMPILER_RT_ALIGNAS
parameter_list|(
name|x
parameter_list|)
value|__attribute__((aligned(x)))
end_define

begin_define
define|#
directive|define
name|COMPILER_RT_VISIBILITY
value|__attribute__((visibility("hidden")))
end_define

begin_define
define|#
directive|define
name|COMPILER_RT_WEAK
value|__attribute__((weak))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|COMPILER_RT_SECTION
parameter_list|(
name|Sect
parameter_list|)
value|__attribute__((section(Sect)))
end_define

begin_if
if|#
directive|if
name|COMPILER_RT_HAS_ATOMICS
operator|==
literal|1
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN64
argument_list|)
end_if

begin_define
define|#
directive|define
name|COMPILER_RT_BOOL_CMPXCHG
parameter_list|(
name|Ptr
parameter_list|,
name|OldV
parameter_list|,
name|NewV
parameter_list|)
define|\
value|(InterlockedCompareExchange64((LONGLONG volatile *)Ptr, (LONGLONG)NewV,      \                                 (LONGLONG)OldV) == (LONGLONG)OldV)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !defined(_WIN64) */
end_comment

begin_define
define|#
directive|define
name|COMPILER_RT_BOOL_CMPXCHG
parameter_list|(
name|Ptr
parameter_list|,
name|OldV
parameter_list|,
name|NewV
parameter_list|)
define|\
value|(InterlockedCompareExchange((LONG volatile *)Ptr, (LONG)NewV, (LONG)OldV) == \    (LONG)OldV)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !defined(_MSC_VER) */
end_comment

begin_define
define|#
directive|define
name|COMPILER_RT_BOOL_CMPXCHG
parameter_list|(
name|Ptr
parameter_list|,
name|OldV
parameter_list|,
name|NewV
parameter_list|)
define|\
value|__sync_bool_compare_and_swap(Ptr, OldV, NewV)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* COMPILER_RT_HAS_ATOMICS != 1 */
end_comment

begin_define
define|#
directive|define
name|COMPILER_RT_BOOL_CMPXCHG
parameter_list|(
name|Ptr
parameter_list|,
name|OldV
parameter_list|,
name|NewV
parameter_list|)
define|\
value|BoolCmpXchg((void **)Ptr, OldV, NewV)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PROF_ERR
parameter_list|(
name|Format
parameter_list|,
modifier|...
parameter_list|)
define|\
value|if (GetEnvHook&& GetEnvHook("LLVM_PROFILE_VERBOSE_ERRORS"))                 \     fprintf(stderr, Format, __VA_ARGS__);
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(__FreeBSD__) */
end_comment

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__FreeBSD__)&& defined(__i386__) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PROFILE_INSTRPROFILING_PORT_H_ */
end_comment

end_unit

