begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/TargetLibraryInfo.h - Library information ---*- C++ -*-===//
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
name|LLVM_TARGET_TARGETLIBRARYINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETLIBRARYINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Triple
decl_stmt|;
name|namespace
name|LibFunc
block|{
enum|enum
name|Func
block|{
comment|/// double acos(double x);
name|acos
block|,
comment|/// long double acosl(long double x);
name|acosl
block|,
comment|/// float acosf(float x);
name|acosf
block|,
comment|/// double asin(double x);
name|asin
block|,
comment|/// long double asinl(long double x);
name|asinl
block|,
comment|/// float asinf(float x);
name|asinf
block|,
comment|/// double atan(double x);
name|atan
block|,
comment|/// long double atanl(long double x);
name|atanl
block|,
comment|/// float atanf(float x);
name|atanf
block|,
comment|/// double atan2(double y, double x);
name|atan2
block|,
comment|/// long double atan2l(long double y, long double x);
name|atan2l
block|,
comment|/// float atan2f(float y, float x);
name|atan2f
block|,
comment|/// double ceil(double x);
name|ceil
block|,
comment|/// long double ceill(long double x);
name|ceill
block|,
comment|/// float ceilf(float x);
name|ceilf
block|,
comment|/// double copysign(double x, double y);
name|copysign
block|,
comment|/// float copysignf(float x, float y);
name|copysignf
block|,
comment|/// long double copysignl(long double x, long double y);
name|copysignl
block|,
comment|/// double cos(double x);
name|cos
block|,
comment|/// long double cosl(long double x);
name|cosl
block|,
comment|/// float cosf(float x);
name|cosf
block|,
comment|/// double cosh(double x);
name|cosh
block|,
comment|/// long double coshl(long double x);
name|coshl
block|,
comment|/// float coshf(float x);
name|coshf
block|,
comment|/// double exp(double x);
name|exp
block|,
comment|/// long double expl(long double x);
name|expl
block|,
comment|/// float expf(float x);
name|expf
block|,
comment|/// double exp2(double x);
name|exp2
block|,
comment|/// long double exp2l(long double x);
name|exp2l
block|,
comment|/// float exp2f(float x);
name|exp2f
block|,
comment|/// double expm1(double x);
name|expm1
block|,
comment|/// long double expm1l(long double x);
name|expm1l
block|,
comment|/// float expm1f(float x);
name|expm1f
block|,
comment|/// double fabs(double x);
name|fabs
block|,
comment|/// long double fabsl(long double x);
name|fabsl
block|,
comment|/// float fabsf(float x);
name|fabsf
block|,
comment|/// double floor(double x);
name|floor
block|,
comment|/// long double floorl(long double x);
name|floorl
block|,
comment|/// float floorf(float x);
name|floorf
block|,
comment|/// int fiprintf(FILE *stream, const char *format, ...);
name|fiprintf
block|,
comment|/// double fmod(double x, double y);
name|fmod
block|,
comment|/// long double fmodl(long double x, long double y);
name|fmodl
block|,
comment|/// float fmodf(float x, float y);
name|fmodf
block|,
comment|/// int fputs(const char *s, FILE *stream);
name|fputs
block|,
comment|/// size_t fwrite(const void *ptr, size_t size, size_t nitems,
comment|/// FILE *stream);
name|fwrite
block|,
comment|/// int iprintf(const char *format, ...);
name|iprintf
block|,
comment|/// double log(double x);
name|log
block|,
comment|/// long double logl(long double x);
name|logl
block|,
comment|/// float logf(float x);
name|logf
block|,
comment|/// double log2(double x);
name|log2
block|,
comment|/// double long double log2l(long double x);
name|log2l
block|,
comment|/// float log2f(float x);
name|log2f
block|,
comment|/// double log10(double x);
name|log10
block|,
comment|/// long double log10l(long double x);
name|log10l
block|,
comment|/// float log10f(float x);
name|log10f
block|,
comment|/// double log1p(double x);
name|log1p
block|,
comment|/// long double log1pl(long double x);
name|log1pl
block|,
comment|/// float log1pf(float x);
name|log1pf
block|,
comment|/// void *memcpy(void *s1, const void *s2, size_t n);
name|memcpy
block|,
comment|/// void *memmove(void *s1, const void *s2, size_t n);
name|memmove
block|,
comment|/// void *memset(void *b, int c, size_t len);
name|memset
block|,
comment|/// void memset_pattern16(void *b, const void *pattern16, size_t len);
name|memset_pattern16
block|,
comment|/// double nearbyint(double x);
name|nearbyint
block|,
comment|/// float nearbyintf(float x);
name|nearbyintf
block|,
comment|/// long double nearbyintl(long double x);
name|nearbyintl
block|,
comment|/// double pow(double x, double y);
name|pow
block|,
comment|/// float powf(float x, float y);
name|powf
block|,
comment|/// long double powl(long double x, long double y);
name|powl
block|,
comment|/// double rint(double x);
name|rint
block|,
comment|/// float rintf(float x);
name|rintf
block|,
comment|/// long double rintl(long double x);
name|rintl
block|,
comment|/// double round(double x);
name|round
block|,
comment|/// float roundf(float x);
name|roundf
block|,
comment|/// long double roundl(long double x);
name|roundl
block|,
comment|/// double sin(double x);
name|sin
block|,
comment|/// long double sinl(long double x);
name|sinl
block|,
comment|/// float sinf(float x);
name|sinf
block|,
comment|/// double sinh(double x);
name|sinh
block|,
comment|/// long double sinhl(long double x);
name|sinhl
block|,
comment|/// float sinhf(float x);
name|sinhf
block|,
comment|/// int siprintf(char *str, const char *format, ...);
name|siprintf
block|,
comment|/// double sqrt(double x);
name|sqrt
block|,
comment|/// long double sqrtl(long double x);
name|sqrtl
block|,
comment|/// float sqrtf(float x);
name|sqrtf
block|,
comment|/// double tan(double x);
name|tan
block|,
comment|/// long double tanl(long double x);
name|tanl
block|,
comment|/// float tanf(float x);
name|tanf
block|,
comment|/// double tanh(double x);
name|tanh
block|,
comment|/// long double tanhl(long double x);
name|tanhl
block|,
comment|/// float tanhf(float x);
name|tanhf
block|,
comment|/// double trunc(double x);
name|trunc
block|,
comment|/// float truncf(float x);
name|truncf
block|,
comment|/// long double truncl(long double x);
name|truncl
block|,
comment|/// int __cxa_atexit(void (*f)(void *), void *p, void *d);
name|cxa_atexit
block|,
comment|/// void __cxa_guard_abort(guard_t *guard);
comment|/// guard_t is int64_t in Itanium ABI or int32_t on ARM eabi.
name|cxa_guard_abort
block|,
comment|/// int __cxa_guard_acquire(guard_t *guard);
name|cxa_guard_acquire
block|,
comment|/// void __cxa_guard_release(guard_t *guard);
name|cxa_guard_release
block|,
name|NumLibFuncs
block|}
enum|;
block|}
comment|/// TargetLibraryInfo - This immutable pass captures information about what
comment|/// library functions are available for the current target, and allows a
comment|/// frontend to disable optimizations through -fno-builtin etc.
name|class
name|TargetLibraryInfo
range|:
name|public
name|ImmutablePass
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|unsigned
name|char
name|AvailableArray
index|[
operator|(
name|LibFunc
operator|::
name|NumLibFuncs
operator|+
literal|3
operator|)
operator|/
literal|4
index|]
block|;
name|llvm
operator|::
name|DenseMap
operator|<
name|unsigned
block|,
name|std
operator|::
name|string
operator|>
name|CustomNames
block|;
specifier|static
specifier|const
name|char
operator|*
name|StandardNames
index|[
name|LibFunc
operator|::
name|NumLibFuncs
index|]
block|;    enum
name|AvailabilityState
block|{
name|StandardName
operator|=
literal|3
block|,
comment|// (memset to all ones)
name|CustomName
operator|=
literal|1
block|,
name|Unavailable
operator|=
literal|0
comment|// (memset to all zeros)
block|}
block|;
name|void
name|setState
argument_list|(
argument|LibFunc::Func F
argument_list|,
argument|AvailabilityState State
argument_list|)
block|{
name|AvailableArray
index|[
name|F
operator|/
literal|4
index|]
operator|&=
operator|~
operator|(
literal|3
operator|<<
literal|2
operator|*
operator|(
name|F
operator|&
literal|3
operator|)
operator|)
block|;
name|AvailableArray
index|[
name|F
operator|/
literal|4
index|]
operator||=
name|State
operator|<<
literal|2
operator|*
operator|(
name|F
operator|&
literal|3
operator|)
block|;   }
name|AvailabilityState
name|getState
argument_list|(
argument|LibFunc::Func F
argument_list|)
specifier|const
block|{
return|return
name|static_cast
operator|<
name|AvailabilityState
operator|>
operator|(
operator|(
name|AvailableArray
index|[
name|F
operator|/
literal|4
index|]
operator|>>
literal|2
operator|*
operator|(
name|F
operator|&
literal|3
operator|)
operator|)
operator|&
literal|3
operator|)
return|;
block|}
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|TargetLibraryInfo
argument_list|()
block|;
name|TargetLibraryInfo
argument_list|(
specifier|const
name|Triple
operator|&
name|T
argument_list|)
block|;
name|explicit
name|TargetLibraryInfo
argument_list|(
specifier|const
name|TargetLibraryInfo
operator|&
name|TLI
argument_list|)
block|;
comment|/// has - This function is used by optimizations that want to match on or form
comment|/// a given library function.
name|bool
name|has
argument_list|(
argument|LibFunc::Func F
argument_list|)
specifier|const
block|{
return|return
name|getState
argument_list|(
name|F
argument_list|)
operator|!=
name|Unavailable
return|;
block|}
name|StringRef
name|getName
argument_list|(
argument|LibFunc::Func F
argument_list|)
specifier|const
block|{
name|AvailabilityState
name|State
operator|=
name|getState
argument_list|(
name|F
argument_list|)
block|;
if|if
condition|(
name|State
operator|==
name|Unavailable
condition|)
return|return
name|StringRef
argument_list|()
return|;
if|if
condition|(
name|State
operator|==
name|StandardName
condition|)
return|return
name|StandardNames
index|[
name|F
index|]
return|;
name|assert
argument_list|(
name|State
operator|==
name|CustomName
argument_list|)
decl_stmt|;
return|return
name|CustomNames
operator|.
name|find
argument_list|(
name|F
argument_list|)
operator|->
name|second
return|;
block|}
end_decl_stmt

begin_comment
comment|/// setUnavailable - this can be used by whatever sets up TargetLibraryInfo to
end_comment

begin_comment
comment|/// ban use of specific library functions.
end_comment

begin_decl_stmt
name|void
name|setUnavailable
argument_list|(
name|LibFunc
operator|::
name|Func
name|F
argument_list|)
block|{
name|setState
argument_list|(
name|F
argument_list|,
name|Unavailable
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|setAvailable
argument_list|(
name|LibFunc
operator|::
name|Func
name|F
argument_list|)
block|{
name|setState
argument_list|(
name|F
argument_list|,
name|StandardName
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|setAvailableWithName
argument_list|(
name|LibFunc
operator|::
name|Func
name|F
argument_list|,
name|StringRef
name|Name
argument_list|)
block|{
if|if
condition|(
name|StandardNames
index|[
name|F
index|]
operator|!=
name|Name
condition|)
block|{
name|setState
argument_list|(
name|F
argument_list|,
name|CustomName
argument_list|)
expr_stmt|;
name|CustomNames
index|[
name|F
index|]
operator|=
name|Name
expr_stmt|;
name|assert
argument_list|(
name|CustomNames
operator|.
name|find
argument_list|(
name|F
argument_list|)
operator|!=
name|CustomNames
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|setState
argument_list|(
name|F
argument_list|,
name|StandardName
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_comment
comment|/// disableAllFunctions - This disables all builtins, which is used for
end_comment

begin_comment
comment|/// options like -fno-builtin.
end_comment

begin_function_decl
name|void
name|disableAllFunctions
parameter_list|()
function_decl|;
end_function_decl

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

