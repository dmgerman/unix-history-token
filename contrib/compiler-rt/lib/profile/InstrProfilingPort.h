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

begin_comment
comment|/* FIXME: selectany does not have the same semantics as weak. */
end_comment

begin_define
define|#
directive|define
name|COMPILER_RT_WEAK
value|__declspec(selectany)
end_define

begin_comment
comment|/* Need to include<windows.h> */
end_comment

begin_define
define|#
directive|define
name|COMPILER_RT_ALLOCA
value|_alloca
end_define

begin_comment
comment|/* Need to include<stdio.h> and<io.h> */
end_comment

begin_define
define|#
directive|define
name|COMPILER_RT_FTRUNCATE
parameter_list|(
name|f
parameter_list|,
name|l
parameter_list|)
value|_chsize(_fileno(f),l)
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

begin_define
define|#
directive|define
name|COMPILER_RT_ALLOCA
value|__builtin_alloca
end_define

begin_define
define|#
directive|define
name|COMPILER_RT_FTRUNCATE
parameter_list|(
name|f
parameter_list|,
name|l
parameter_list|)
value|ftruncate(fileno(f),l)
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
name|__APPLE__
argument_list|)
end_if

begin_define
define|#
directive|define
name|COMPILER_RT_SEG
value|"__DATA,"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|COMPILER_RT_SEG
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_define
define|#
directive|define
name|COMPILER_RT_SECTION
parameter_list|(
name|Sect
parameter_list|)
value|__declspec(allocate(Sect))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|COMPILER_RT_SECTION
parameter_list|(
name|Sect
parameter_list|)
value|__attribute__((section(Sect)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|COMPILER_RT_MAX_HOSTLEN
value|128
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__ORBIS__
end_ifdef

begin_define
define|#
directive|define
name|COMPILER_RT_GETHOSTNAME
parameter_list|(
name|Name
parameter_list|,
name|Len
parameter_list|)
value|((void)(Name), (void)(Len), (-1))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|COMPILER_RT_GETHOSTNAME
parameter_list|(
name|Name
parameter_list|,
name|Len
parameter_list|)
value|lprofGetHostName(Name, Len)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_MSC_VER
end_ifndef

begin_define
define|#
directive|define
name|COMPILER_RT_HAS_UNAME
value|1
end_define

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
name|_MSC_VER
operator|<
literal|1900
end_if

begin_define
define|#
directive|define
name|snprintf
value|_snprintf
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

begin_define
define|#
directive|define
name|COMPILER_RT_PTR_FETCH_ADD
parameter_list|(
name|DomType
parameter_list|,
name|PtrVar
parameter_list|,
name|PtrIncr
parameter_list|)
define|\
value|(DomType *)InterlockedExchangeAdd64((LONGLONG volatile *)&PtrVar,            \                                       (LONGLONG)sizeof(DomType) * PtrIncr)
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

begin_define
define|#
directive|define
name|COMPILER_RT_PTR_FETCH_ADD
parameter_list|(
name|DomType
parameter_list|,
name|PtrVar
parameter_list|,
name|PtrIncr
parameter_list|)
define|\
value|(DomType *)InterlockedExchangeAdd((LONG volatile *)&PtrVar,                  \                                     (LONG)sizeof(DomType) * PtrIncr)
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

begin_define
define|#
directive|define
name|COMPILER_RT_PTR_FETCH_ADD
parameter_list|(
name|DomType
parameter_list|,
name|PtrVar
parameter_list|,
name|PtrIncr
parameter_list|)
define|\
value|(DomType *)__sync_fetch_and_add((long *)&PtrVar, sizeof(DomType) * PtrIncr)
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

begin_include
include|#
directive|include
file|"InstrProfilingUtil.h"
end_include

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
value|lprofBoolCmpXchg((void **)Ptr, OldV, NewV)
end_define

begin_define
define|#
directive|define
name|COMPILER_RT_PTR_FETCH_ADD
parameter_list|(
name|DomType
parameter_list|,
name|PtrVar
parameter_list|,
name|PtrIncr
parameter_list|)
define|\
value|(DomType *)lprofPtrFetchAdd((void **)&PtrVar, sizeof(DomType) * PtrIncr)
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
name|_WIN32
argument_list|)
end_if

begin_define
define|#
directive|define
name|DIR_SEPARATOR
value|'\\'
end_define

begin_define
define|#
directive|define
name|DIR_SEPARATOR_2
value|'/'
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DIR_SEPARATOR
value|'/'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DIR_SEPARATOR_2
end_ifndef

begin_define
define|#
directive|define
name|IS_DIR_SEPARATOR
parameter_list|(
name|ch
parameter_list|)
value|((ch) == DIR_SEPARATOR)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* DIR_SEPARATOR_2 */
end_comment

begin_define
define|#
directive|define
name|IS_DIR_SEPARATOR
parameter_list|(
name|ch
parameter_list|)
define|\
value|(((ch) == DIR_SEPARATOR) || ((ch) == DIR_SEPARATOR_2))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DIR_SEPARATOR_2 */
end_comment

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
value|fprintf(stderr, "LLVM Profile Error: " Format, __VA_ARGS__);
end_define

begin_define
define|#
directive|define
name|PROF_WARN
parameter_list|(
name|Format
parameter_list|,
modifier|...
parameter_list|)
define|\
value|fprintf(stderr, "LLVM Profile Warning: " Format, __VA_ARGS__);
end_define

begin_define
define|#
directive|define
name|PROF_NOTE
parameter_list|(
name|Format
parameter_list|,
modifier|...
parameter_list|)
define|\
value|fprintf(stderr, "LLVM Profile Note: " Format, __VA_ARGS__);
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

