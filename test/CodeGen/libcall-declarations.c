begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin12 -S -o - -emit-llvm %s | FileCheck %s -check-prefix=CHECK-NOERRNO
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-linux-gnu -S -o - -emit-llvm -fmath-errno %s | FileCheck %s -check-prefix=CHECK-ERRNO
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin12 -S -o - -emit-llvm -x c++ %s | FileCheck %s -check-prefix=CHECK-NOERRNO
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-linux-gnu -S -o - -emit-llvm -x c++ -fmath-errno %s | FileCheck %s -check-prefix=CHECK-ERRNO
end_comment

begin_comment
comment|// Prototypes.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
name|double
name|atan2
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
name|float
name|atan2f
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|atan2l
parameter_list|(
name|long
name|double
parameter_list|,
name|long
name|double
parameter_list|)
function_decl|;
name|int
name|abs
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|long
name|int
name|labs
parameter_list|(
name|long
name|int
parameter_list|)
function_decl|;
name|long
name|long
name|int
name|llabs
parameter_list|(
name|long
name|long
name|int
parameter_list|)
function_decl|;
name|double
name|copysign
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
name|float
name|copysignf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|copysignl
parameter_list|(
name|long
name|double
parameter_list|,
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|fabs
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|fabsf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|fabsl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|fmod
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
name|float
name|fmodf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|fmodl
parameter_list|(
name|long
name|double
parameter_list|,
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|frexp
parameter_list|(
name|double
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
name|float
name|frexpf
parameter_list|(
name|float
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
name|long
name|double
name|frexpl
parameter_list|(
name|long
name|double
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
name|double
name|ldexp
parameter_list|(
name|double
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|float
name|ldexpf
parameter_list|(
name|float
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|long
name|double
name|ldexpl
parameter_list|(
name|long
name|double
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|double
name|modf
parameter_list|(
name|double
parameter_list|,
name|double
modifier|*
parameter_list|)
function_decl|;
name|float
name|modff
parameter_list|(
name|float
parameter_list|,
name|float
modifier|*
parameter_list|)
function_decl|;
name|long
name|double
name|modfl
parameter_list|(
name|long
name|double
parameter_list|,
name|long
name|double
modifier|*
parameter_list|)
function_decl|;
name|double
name|nan
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|float
name|nanf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|long
name|double
name|nanl
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|double
name|pow
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
name|float
name|powf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|powl
parameter_list|(
name|long
name|double
parameter_list|,
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|acos
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|acosf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|acosl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|acosh
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|acoshf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|acoshl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|asin
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|asinf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|asinl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|asinh
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|asinhf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|asinhl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|atan
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|atanf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|atanl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|atanh
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|atanhf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|atanhl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|cbrt
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|cbrtf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|cbrtl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|ceil
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|ceilf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|ceill
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|cos
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|cosf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|cosl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|cosh
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|coshf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|coshl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|erf
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|erff
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|erfl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|erfc
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|erfcf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|erfcl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|exp
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|expf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|expl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|exp2
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|exp2f
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|exp2l
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|expm1
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|expm1f
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|expm1l
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|fdim
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
name|float
name|fdimf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|fdiml
parameter_list|(
name|long
name|double
parameter_list|,
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|floor
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|floorf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|floorl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|fma
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
name|float
name|fmaf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|fmal
parameter_list|(
name|long
name|double
parameter_list|,
name|long
name|double
parameter_list|,
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|fmax
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
name|float
name|fmaxf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|fmaxl
parameter_list|(
name|long
name|double
parameter_list|,
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|fmin
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
name|float
name|fminf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|fminl
parameter_list|(
name|long
name|double
parameter_list|,
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|hypot
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
name|float
name|hypotf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|hypotl
parameter_list|(
name|long
name|double
parameter_list|,
name|long
name|double
parameter_list|)
function_decl|;
name|int
name|ilogb
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|int
name|ilogbf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|int
name|ilogbl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|lgamma
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|lgammaf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|lgammal
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|long
name|long
name|int
name|llrint
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|long
name|long
name|int
name|llrintf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|long
name|int
name|llrintl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|long
name|long
name|int
name|llround
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|long
name|long
name|int
name|llroundf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|long
name|int
name|llroundl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|log
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|logf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|logl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|log10
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|log10f
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|log10l
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|log1p
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|log1pf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|log1pl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|log2
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|log2f
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|log2l
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|logb
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|logbf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|logbl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|long
name|int
name|lrint
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|long
name|int
name|lrintf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|int
name|lrintl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|long
name|int
name|lround
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|long
name|int
name|lroundf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|int
name|lroundl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|nearbyint
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|nearbyintf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|nearbyintl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|nextafter
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
name|float
name|nextafterf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|nextafterl
parameter_list|(
name|long
name|double
parameter_list|,
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|nexttoward
parameter_list|(
name|double
parameter_list|,
name|long
name|double
parameter_list|)
function_decl|;
name|float
name|nexttowardf
parameter_list|(
name|float
parameter_list|,
name|long
name|double
parameter_list|)
function_decl|;
name|long
name|double
name|nexttowardl
parameter_list|(
name|long
name|double
parameter_list|,
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|remainder
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
name|float
name|remainderf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|remainderl
parameter_list|(
name|long
name|double
parameter_list|,
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|rint
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|rintf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|rintl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|round
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|roundf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|roundl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|scalbln
parameter_list|(
name|double
parameter_list|,
name|long
name|int
name|exp
parameter_list|)
function_decl|;
name|float
name|scalblnf
parameter_list|(
name|float
parameter_list|,
name|long
name|int
name|exp
parameter_list|)
function_decl|;
name|long
name|double
name|scalblnl
parameter_list|(
name|long
name|double
parameter_list|,
name|long
name|int
name|exp
parameter_list|)
function_decl|;
name|double
name|scalbn
parameter_list|(
name|double
parameter_list|,
name|int
name|exp
parameter_list|)
function_decl|;
name|float
name|scalbnf
parameter_list|(
name|float
parameter_list|,
name|int
name|exp
parameter_list|)
function_decl|;
name|long
name|double
name|scalbnl
parameter_list|(
name|long
name|double
parameter_list|,
name|int
name|exp
parameter_list|)
function_decl|;
name|double
name|sin
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|sinf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|sinl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|sinh
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|sinhf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|sinhl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|sqrt
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|sqrtf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|sqrtl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|tan
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|tanf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|tanl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|tanh
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|tanhf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|tanhl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|tgamma
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|tgammaf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|tgammal
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|trunc
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|truncf
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|long
name|double
name|truncl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|cabs
parameter_list|(
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|float
name|cabsf
parameter_list|(
name|float
specifier|_Complex
parameter_list|)
function_decl|;
name|long
name|double
name|cabsl
parameter_list|(
name|long
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|double
specifier|_Complex
name|cacos
parameter_list|(
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|float
specifier|_Complex
name|cacosf
parameter_list|(
name|float
specifier|_Complex
parameter_list|)
function_decl|;
name|long
name|double
specifier|_Complex
name|cacosl
parameter_list|(
name|long
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|double
specifier|_Complex
name|cacosh
parameter_list|(
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|float
specifier|_Complex
name|cacoshf
parameter_list|(
name|float
specifier|_Complex
parameter_list|)
function_decl|;
name|long
name|double
specifier|_Complex
name|cacoshl
parameter_list|(
name|long
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|double
name|carg
parameter_list|(
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|float
name|cargf
parameter_list|(
name|float
specifier|_Complex
parameter_list|)
function_decl|;
name|long
name|double
name|cargl
parameter_list|(
name|long
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|double
specifier|_Complex
name|casin
parameter_list|(
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|float
specifier|_Complex
name|casinf
parameter_list|(
name|float
specifier|_Complex
parameter_list|)
function_decl|;
name|long
name|double
specifier|_Complex
name|casinl
parameter_list|(
name|long
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|double
specifier|_Complex
name|casinh
parameter_list|(
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|float
specifier|_Complex
name|casinhf
parameter_list|(
name|float
specifier|_Complex
parameter_list|)
function_decl|;
name|long
name|double
specifier|_Complex
name|casinhl
parameter_list|(
name|long
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|double
specifier|_Complex
name|catan
parameter_list|(
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|float
specifier|_Complex
name|catanf
parameter_list|(
name|float
specifier|_Complex
parameter_list|)
function_decl|;
name|long
name|double
specifier|_Complex
name|catanl
parameter_list|(
name|long
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|double
specifier|_Complex
name|catanh
parameter_list|(
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|float
specifier|_Complex
name|catanhf
parameter_list|(
name|float
specifier|_Complex
parameter_list|)
function_decl|;
name|long
name|double
specifier|_Complex
name|catanhl
parameter_list|(
name|long
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|double
specifier|_Complex
name|ccos
parameter_list|(
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|float
specifier|_Complex
name|ccosf
parameter_list|(
name|float
specifier|_Complex
parameter_list|)
function_decl|;
name|long
name|double
specifier|_Complex
name|ccosl
parameter_list|(
name|long
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|double
specifier|_Complex
name|ccosh
parameter_list|(
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|float
specifier|_Complex
name|ccoshf
parameter_list|(
name|float
specifier|_Complex
parameter_list|)
function_decl|;
name|long
name|double
specifier|_Complex
name|ccoshl
parameter_list|(
name|long
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|double
specifier|_Complex
name|cexp
parameter_list|(
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|float
specifier|_Complex
name|cexpf
parameter_list|(
name|float
specifier|_Complex
parameter_list|)
function_decl|;
name|long
name|double
specifier|_Complex
name|cexpl
parameter_list|(
name|long
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|double
name|cimag
parameter_list|(
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|float
name|cimagf
parameter_list|(
name|float
specifier|_Complex
parameter_list|)
function_decl|;
name|long
name|double
name|cimagl
parameter_list|(
name|long
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|double
specifier|_Complex
name|conj
parameter_list|(
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|float
specifier|_Complex
name|conjf
parameter_list|(
name|float
specifier|_Complex
parameter_list|)
function_decl|;
name|long
name|double
specifier|_Complex
name|conjl
parameter_list|(
name|long
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|double
specifier|_Complex
name|clog
parameter_list|(
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|float
specifier|_Complex
name|clogf
parameter_list|(
name|float
specifier|_Complex
parameter_list|)
function_decl|;
name|long
name|double
specifier|_Complex
name|clogl
parameter_list|(
name|long
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|double
specifier|_Complex
name|cproj
parameter_list|(
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|float
specifier|_Complex
name|cprojf
parameter_list|(
name|float
specifier|_Complex
parameter_list|)
function_decl|;
name|long
name|double
specifier|_Complex
name|cprojl
parameter_list|(
name|long
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|double
specifier|_Complex
name|cpow
parameter_list|(
name|double
specifier|_Complex
parameter_list|,
specifier|_Complex
name|double
parameter_list|)
function_decl|;
name|float
specifier|_Complex
name|cpowf
parameter_list|(
name|float
specifier|_Complex
parameter_list|,
specifier|_Complex
name|float
parameter_list|)
function_decl|;
name|long
name|double
specifier|_Complex
name|cpowl
parameter_list|(
name|long
name|double
specifier|_Complex
parameter_list|,
specifier|_Complex
name|long
name|double
parameter_list|)
function_decl|;
name|double
name|creal
parameter_list|(
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|float
name|crealf
parameter_list|(
name|float
specifier|_Complex
parameter_list|)
function_decl|;
name|long
name|double
name|creall
parameter_list|(
name|long
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|double
specifier|_Complex
name|csin
parameter_list|(
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|float
specifier|_Complex
name|csinf
parameter_list|(
name|float
specifier|_Complex
parameter_list|)
function_decl|;
name|long
name|double
specifier|_Complex
name|csinl
parameter_list|(
name|long
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|double
specifier|_Complex
name|csinh
parameter_list|(
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|float
specifier|_Complex
name|csinhf
parameter_list|(
name|float
specifier|_Complex
parameter_list|)
function_decl|;
name|long
name|double
specifier|_Complex
name|csinhl
parameter_list|(
name|long
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|double
specifier|_Complex
name|csqrt
parameter_list|(
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|float
specifier|_Complex
name|csqrtf
parameter_list|(
name|float
specifier|_Complex
parameter_list|)
function_decl|;
name|long
name|double
specifier|_Complex
name|csqrtl
parameter_list|(
name|long
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|double
specifier|_Complex
name|ctan
parameter_list|(
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|float
specifier|_Complex
name|ctanf
parameter_list|(
name|float
specifier|_Complex
parameter_list|)
function_decl|;
name|long
name|double
specifier|_Complex
name|ctanl
parameter_list|(
name|long
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|double
specifier|_Complex
name|ctanh
parameter_list|(
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|float
specifier|_Complex
name|ctanhf
parameter_list|(
name|float
specifier|_Complex
parameter_list|)
function_decl|;
name|long
name|double
specifier|_Complex
name|ctanhl
parameter_list|(
name|long
name|double
specifier|_Complex
parameter_list|)
function_decl|;
name|double
name|__sinpi
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|__sinpif
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|double
name|__cospi
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|__cospif
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|double
name|__tanpi
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|__tanpif
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|double
name|__exp10
parameter_list|(
name|double
parameter_list|)
function_decl|;
name|float
name|__exp10f
parameter_list|(
name|float
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Force emission of the declare statements.
end_comment

begin_define
define|#
directive|define
name|F
parameter_list|(
name|x
parameter_list|)
value|((void*)x)
end_define

begin_decl_stmt
name|void
modifier|*
name|use
index|[]
init|=
block|{
name|F
argument_list|(
name|atan2
argument_list|)
block|,
name|F
argument_list|(
name|atan2f
argument_list|)
block|,
name|F
argument_list|(
name|atan2l
argument_list|)
block|,
name|F
argument_list|(
name|abs
argument_list|)
block|,
name|F
argument_list|(
name|labs
argument_list|)
block|,
name|F
argument_list|(
name|llabs
argument_list|)
block|,
name|F
argument_list|(
name|copysign
argument_list|)
block|,
name|F
argument_list|(
name|copysignf
argument_list|)
block|,
name|F
argument_list|(
name|copysignl
argument_list|)
block|,
name|F
argument_list|(
name|fabs
argument_list|)
block|,
name|F
argument_list|(
name|fabsf
argument_list|)
block|,
name|F
argument_list|(
name|fabsl
argument_list|)
block|,
name|F
argument_list|(
name|fmod
argument_list|)
block|,
name|F
argument_list|(
name|fmodf
argument_list|)
block|,
name|F
argument_list|(
name|fmodl
argument_list|)
block|,
name|F
argument_list|(
name|frexp
argument_list|)
block|,
name|F
argument_list|(
name|frexpf
argument_list|)
block|,
name|F
argument_list|(
name|frexpl
argument_list|)
block|,
name|F
argument_list|(
name|ldexp
argument_list|)
block|,
name|F
argument_list|(
name|ldexpf
argument_list|)
block|,
name|F
argument_list|(
name|ldexpl
argument_list|)
block|,
name|F
argument_list|(
name|modf
argument_list|)
block|,
name|F
argument_list|(
name|modff
argument_list|)
block|,
name|F
argument_list|(
name|modfl
argument_list|)
block|,
name|F
argument_list|(
name|nan
argument_list|)
block|,
name|F
argument_list|(
name|nanf
argument_list|)
block|,
name|F
argument_list|(
name|nanl
argument_list|)
block|,
name|F
argument_list|(
name|pow
argument_list|)
block|,
name|F
argument_list|(
name|powf
argument_list|)
block|,
name|F
argument_list|(
name|powl
argument_list|)
block|,
name|F
argument_list|(
name|acos
argument_list|)
block|,
name|F
argument_list|(
name|acosf
argument_list|)
block|,
name|F
argument_list|(
name|acosl
argument_list|)
block|,
name|F
argument_list|(
name|acosh
argument_list|)
block|,
name|F
argument_list|(
name|acoshf
argument_list|)
block|,
name|F
argument_list|(
name|acoshl
argument_list|)
block|,
name|F
argument_list|(
name|asin
argument_list|)
block|,
name|F
argument_list|(
name|asinf
argument_list|)
block|,
name|F
argument_list|(
name|asinl
argument_list|)
block|,
name|F
argument_list|(
name|asinh
argument_list|)
block|,
name|F
argument_list|(
name|asinhf
argument_list|)
block|,
name|F
argument_list|(
name|asinhl
argument_list|)
block|,
name|F
argument_list|(
name|atan
argument_list|)
block|,
name|F
argument_list|(
name|atanf
argument_list|)
block|,
name|F
argument_list|(
name|atanl
argument_list|)
block|,
name|F
argument_list|(
name|atanh
argument_list|)
block|,
name|F
argument_list|(
name|atanhf
argument_list|)
block|,
name|F
argument_list|(
name|atanhl
argument_list|)
block|,
name|F
argument_list|(
name|cbrt
argument_list|)
block|,
name|F
argument_list|(
name|cbrtf
argument_list|)
block|,
name|F
argument_list|(
name|cbrtl
argument_list|)
block|,
name|F
argument_list|(
name|ceil
argument_list|)
block|,
name|F
argument_list|(
name|ceilf
argument_list|)
block|,
name|F
argument_list|(
name|ceill
argument_list|)
block|,
name|F
argument_list|(
name|cos
argument_list|)
block|,
name|F
argument_list|(
name|cosf
argument_list|)
block|,
name|F
argument_list|(
name|cosl
argument_list|)
block|,
name|F
argument_list|(
name|cosh
argument_list|)
block|,
name|F
argument_list|(
name|coshf
argument_list|)
block|,
name|F
argument_list|(
name|coshl
argument_list|)
block|,
name|F
argument_list|(
name|erf
argument_list|)
block|,
name|F
argument_list|(
name|erff
argument_list|)
block|,
name|F
argument_list|(
name|erfl
argument_list|)
block|,
name|F
argument_list|(
name|erfc
argument_list|)
block|,
name|F
argument_list|(
name|erfcf
argument_list|)
block|,
name|F
argument_list|(
name|erfcl
argument_list|)
block|,
name|F
argument_list|(
name|exp
argument_list|)
block|,
name|F
argument_list|(
name|expf
argument_list|)
block|,
name|F
argument_list|(
name|expl
argument_list|)
block|,
name|F
argument_list|(
name|exp2
argument_list|)
block|,
name|F
argument_list|(
name|exp2f
argument_list|)
block|,
name|F
argument_list|(
name|exp2l
argument_list|)
block|,
name|F
argument_list|(
name|expm1
argument_list|)
block|,
name|F
argument_list|(
name|expm1f
argument_list|)
block|,
name|F
argument_list|(
name|expm1l
argument_list|)
block|,
name|F
argument_list|(
name|fdim
argument_list|)
block|,
name|F
argument_list|(
name|fdimf
argument_list|)
block|,
name|F
argument_list|(
name|fdiml
argument_list|)
block|,
name|F
argument_list|(
name|floor
argument_list|)
block|,
name|F
argument_list|(
name|floorf
argument_list|)
block|,
name|F
argument_list|(
name|floorl
argument_list|)
block|,
name|F
argument_list|(
name|fma
argument_list|)
block|,
name|F
argument_list|(
name|fmaf
argument_list|)
block|,
name|F
argument_list|(
name|fmal
argument_list|)
block|,
name|F
argument_list|(
name|fmax
argument_list|)
block|,
name|F
argument_list|(
name|fmaxf
argument_list|)
block|,
name|F
argument_list|(
name|fmaxl
argument_list|)
block|,
name|F
argument_list|(
name|fmin
argument_list|)
block|,
name|F
argument_list|(
name|fminf
argument_list|)
block|,
name|F
argument_list|(
name|fminl
argument_list|)
block|,
name|F
argument_list|(
name|hypot
argument_list|)
block|,
name|F
argument_list|(
name|hypotf
argument_list|)
block|,
name|F
argument_list|(
name|hypotl
argument_list|)
block|,
name|F
argument_list|(
name|ilogb
argument_list|)
block|,
name|F
argument_list|(
name|ilogbf
argument_list|)
block|,
name|F
argument_list|(
name|ilogbl
argument_list|)
block|,
name|F
argument_list|(
name|lgamma
argument_list|)
block|,
name|F
argument_list|(
name|lgammaf
argument_list|)
block|,
name|F
argument_list|(
name|lgammal
argument_list|)
block|,
name|F
argument_list|(
name|llrint
argument_list|)
block|,
name|F
argument_list|(
name|llrintf
argument_list|)
block|,
name|F
argument_list|(
name|llrintl
argument_list|)
block|,
name|F
argument_list|(
name|llround
argument_list|)
block|,
name|F
argument_list|(
name|llroundf
argument_list|)
block|,
name|F
argument_list|(
name|llroundl
argument_list|)
block|,
name|F
argument_list|(
name|log
argument_list|)
block|,
name|F
argument_list|(
name|logf
argument_list|)
block|,
name|F
argument_list|(
name|logl
argument_list|)
block|,
name|F
argument_list|(
name|log10
argument_list|)
block|,
name|F
argument_list|(
name|log10f
argument_list|)
block|,
name|F
argument_list|(
name|log10l
argument_list|)
block|,
name|F
argument_list|(
name|log1p
argument_list|)
block|,
name|F
argument_list|(
name|log1pf
argument_list|)
block|,
name|F
argument_list|(
name|log1pl
argument_list|)
block|,
name|F
argument_list|(
name|log2
argument_list|)
block|,
name|F
argument_list|(
name|log2f
argument_list|)
block|,
name|F
argument_list|(
name|log2l
argument_list|)
block|,
name|F
argument_list|(
name|logb
argument_list|)
block|,
name|F
argument_list|(
name|logbf
argument_list|)
block|,
name|F
argument_list|(
name|logbl
argument_list|)
block|,
name|F
argument_list|(
name|lrint
argument_list|)
block|,
name|F
argument_list|(
name|lrintf
argument_list|)
block|,
name|F
argument_list|(
name|lrintl
argument_list|)
block|,
name|F
argument_list|(
name|lround
argument_list|)
block|,
name|F
argument_list|(
name|lroundf
argument_list|)
block|,
name|F
argument_list|(
name|lroundl
argument_list|)
block|,
name|F
argument_list|(
name|nearbyint
argument_list|)
block|,
name|F
argument_list|(
name|nearbyintf
argument_list|)
block|,
name|F
argument_list|(
name|nearbyintl
argument_list|)
block|,
name|F
argument_list|(
name|nextafter
argument_list|)
block|,
name|F
argument_list|(
name|nextafterf
argument_list|)
block|,
name|F
argument_list|(
name|nextafterl
argument_list|)
block|,
name|F
argument_list|(
name|nexttoward
argument_list|)
block|,
name|F
argument_list|(
name|nexttowardf
argument_list|)
block|,
name|F
argument_list|(
name|nexttowardl
argument_list|)
block|,
name|F
argument_list|(
name|remainder
argument_list|)
block|,
name|F
argument_list|(
name|remainderf
argument_list|)
block|,
name|F
argument_list|(
name|remainderl
argument_list|)
block|,
name|F
argument_list|(
name|rint
argument_list|)
block|,
name|F
argument_list|(
name|rintf
argument_list|)
block|,
name|F
argument_list|(
name|rintl
argument_list|)
block|,
name|F
argument_list|(
name|round
argument_list|)
block|,
name|F
argument_list|(
name|roundf
argument_list|)
block|,
name|F
argument_list|(
name|roundl
argument_list|)
block|,
name|F
argument_list|(
name|scalbln
argument_list|)
block|,
name|F
argument_list|(
name|scalblnf
argument_list|)
block|,
name|F
argument_list|(
name|scalblnl
argument_list|)
block|,
name|F
argument_list|(
name|scalbn
argument_list|)
block|,
name|F
argument_list|(
name|scalbnf
argument_list|)
block|,
name|F
argument_list|(
name|scalbnl
argument_list|)
block|,
name|F
argument_list|(
name|sin
argument_list|)
block|,
name|F
argument_list|(
name|sinf
argument_list|)
block|,
name|F
argument_list|(
name|sinl
argument_list|)
block|,
name|F
argument_list|(
name|sinh
argument_list|)
block|,
name|F
argument_list|(
name|sinhf
argument_list|)
block|,
name|F
argument_list|(
name|sinhl
argument_list|)
block|,
name|F
argument_list|(
name|sqrt
argument_list|)
block|,
name|F
argument_list|(
name|sqrtf
argument_list|)
block|,
name|F
argument_list|(
name|sqrtl
argument_list|)
block|,
name|F
argument_list|(
name|tan
argument_list|)
block|,
name|F
argument_list|(
name|tanf
argument_list|)
block|,
name|F
argument_list|(
name|tanl
argument_list|)
block|,
name|F
argument_list|(
name|tanh
argument_list|)
block|,
name|F
argument_list|(
name|tanhf
argument_list|)
block|,
name|F
argument_list|(
name|tanhl
argument_list|)
block|,
name|F
argument_list|(
name|tgamma
argument_list|)
block|,
name|F
argument_list|(
name|tgammaf
argument_list|)
block|,
name|F
argument_list|(
name|tgammal
argument_list|)
block|,
name|F
argument_list|(
name|trunc
argument_list|)
block|,
name|F
argument_list|(
name|truncf
argument_list|)
block|,
name|F
argument_list|(
name|truncl
argument_list|)
block|,
name|F
argument_list|(
name|cabs
argument_list|)
block|,
name|F
argument_list|(
name|cabsf
argument_list|)
block|,
name|F
argument_list|(
name|cabsl
argument_list|)
block|,
name|F
argument_list|(
name|cacos
argument_list|)
block|,
name|F
argument_list|(
name|cacosf
argument_list|)
block|,
name|F
argument_list|(
name|cacosl
argument_list|)
block|,
name|F
argument_list|(
name|cacosh
argument_list|)
block|,
name|F
argument_list|(
name|cacoshf
argument_list|)
block|,
name|F
argument_list|(
name|cacoshl
argument_list|)
block|,
name|F
argument_list|(
name|carg
argument_list|)
block|,
name|F
argument_list|(
name|cargf
argument_list|)
block|,
name|F
argument_list|(
name|cargl
argument_list|)
block|,
name|F
argument_list|(
name|casin
argument_list|)
block|,
name|F
argument_list|(
name|casinf
argument_list|)
block|,
name|F
argument_list|(
name|casinl
argument_list|)
block|,
name|F
argument_list|(
name|casinh
argument_list|)
block|,
name|F
argument_list|(
name|casinhf
argument_list|)
block|,
name|F
argument_list|(
name|casinhl
argument_list|)
block|,
name|F
argument_list|(
name|catan
argument_list|)
block|,
name|F
argument_list|(
name|catanf
argument_list|)
block|,
name|F
argument_list|(
name|catanl
argument_list|)
block|,
name|F
argument_list|(
name|catanh
argument_list|)
block|,
name|F
argument_list|(
name|catanhf
argument_list|)
block|,
name|F
argument_list|(
name|catanhl
argument_list|)
block|,
name|F
argument_list|(
name|ccos
argument_list|)
block|,
name|F
argument_list|(
name|ccosf
argument_list|)
block|,
name|F
argument_list|(
name|ccosl
argument_list|)
block|,
name|F
argument_list|(
name|ccosh
argument_list|)
block|,
name|F
argument_list|(
name|ccoshf
argument_list|)
block|,
name|F
argument_list|(
name|ccoshl
argument_list|)
block|,
name|F
argument_list|(
name|cexp
argument_list|)
block|,
name|F
argument_list|(
name|cexpf
argument_list|)
block|,
name|F
argument_list|(
name|cexpl
argument_list|)
block|,
name|F
argument_list|(
name|cimag
argument_list|)
block|,
name|F
argument_list|(
name|cimagf
argument_list|)
block|,
name|F
argument_list|(
name|cimagl
argument_list|)
block|,
name|F
argument_list|(
name|conj
argument_list|)
block|,
name|F
argument_list|(
name|conjf
argument_list|)
block|,
name|F
argument_list|(
name|conjl
argument_list|)
block|,
name|F
argument_list|(
name|clog
argument_list|)
block|,
name|F
argument_list|(
name|clogf
argument_list|)
block|,
name|F
argument_list|(
name|clogl
argument_list|)
block|,
name|F
argument_list|(
name|cproj
argument_list|)
block|,
name|F
argument_list|(
name|cprojf
argument_list|)
block|,
name|F
argument_list|(
name|cprojl
argument_list|)
block|,
name|F
argument_list|(
name|cpow
argument_list|)
block|,
name|F
argument_list|(
name|cpowf
argument_list|)
block|,
name|F
argument_list|(
name|cpowl
argument_list|)
block|,
name|F
argument_list|(
name|creal
argument_list|)
block|,
name|F
argument_list|(
name|crealf
argument_list|)
block|,
name|F
argument_list|(
name|creall
argument_list|)
block|,
name|F
argument_list|(
name|csin
argument_list|)
block|,
name|F
argument_list|(
name|csinf
argument_list|)
block|,
name|F
argument_list|(
name|csinl
argument_list|)
block|,
name|F
argument_list|(
name|csinh
argument_list|)
block|,
name|F
argument_list|(
name|csinhf
argument_list|)
block|,
name|F
argument_list|(
name|csinhl
argument_list|)
block|,
name|F
argument_list|(
name|csqrt
argument_list|)
block|,
name|F
argument_list|(
name|csqrtf
argument_list|)
block|,
name|F
argument_list|(
name|csqrtl
argument_list|)
block|,
name|F
argument_list|(
name|ctan
argument_list|)
block|,
name|F
argument_list|(
name|ctanf
argument_list|)
block|,
name|F
argument_list|(
name|ctanl
argument_list|)
block|,
name|F
argument_list|(
name|ctanh
argument_list|)
block|,
name|F
argument_list|(
name|ctanhf
argument_list|)
block|,
name|F
argument_list|(
name|ctanhl
argument_list|)
block|,
name|F
argument_list|(
name|__sinpi
argument_list|)
block|,
name|F
argument_list|(
name|__sinpif
argument_list|)
block|,
name|F
argument_list|(
name|__cospi
argument_list|)
block|,
name|F
argument_list|(
name|__cospif
argument_list|)
block|,
name|F
argument_list|(
name|__tanpi
argument_list|)
block|,
name|F
argument_list|(
name|__tanpif
argument_list|)
block|,
name|F
argument_list|(
name|__exp10
argument_list|)
block|,
name|F
argument_list|(
argument|__exp10f
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-NOERRNO: declare double @atan2(double, double) [[NUW:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @atan2f(float, float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @atan2l(x86_fp80, x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare i32 @abs(i32) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare i64 @labs(i64) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare i64 @llabs(i64) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @copysign(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @copysignf(float, float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @copysignl(x86_fp80, x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @fabs(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @fabsf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @fabsl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @fmod(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @fmodf(float, float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @fmodl(x86_fp80, x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @ldexp(double, i32) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @ldexpf(float, i32) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @ldexpl(x86_fp80, i32) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @nan(i8*) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @nanf(i8*) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @nanl(i8*) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @pow(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @powf(float, float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @powl(x86_fp80, x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @acos(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @acosf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @acosl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @acosh(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @acoshf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @acoshl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @asin(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @asinf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @asinl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @asinh(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @asinhf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @asinhl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @atan(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @atanf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @atanl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @atanh(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @atanhf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @atanhl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @cbrt(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @cbrtf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @cbrtl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @ceil(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @ceilf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @ceill(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @cos(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @cosf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @cosl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @cosh(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @coshf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @coshl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @erf(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @erff(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @erfl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @erfc(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @erfcf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @erfcl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @exp(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @expf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @expl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @exp2(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @exp2f(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @exp2l(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @expm1(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @expm1f(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @expm1l(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @fdim(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @fdimf(float, float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @fdiml(x86_fp80, x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @floor(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @floorf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @floorl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @fma(double, double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @fmaf(float, float, float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @fmal(x86_fp80, x86_fp80, x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @fmax(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @fmaxf(float, float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @fmaxl(x86_fp80, x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @fmin(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @fminf(float, float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @fminl(x86_fp80, x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @hypot(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @hypotf(float, float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @hypotl(x86_fp80, x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare i32 @ilogb(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare i32 @ilogbf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare i32 @ilogbl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @lgamma(double) [[NONCONST:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @lgammaf(float) [[NONCONST]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @lgammal(x86_fp80) [[NONCONST]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare i64 @llrint(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare i64 @llrintf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare i64 @llrintl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare i64 @llround(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare i64 @llroundf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare i64 @llroundl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @log(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @logf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @logl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @log10(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @log10f(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @log10l(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @log1p(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @log1pf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @log1pl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @log2(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @log2f(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @log2l(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @logb(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @logbf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @logbl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare i64 @lrint(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare i64 @lrintf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare i64 @lrintl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare i64 @lround(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare i64 @lroundf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare i64 @lroundl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @nearbyint(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @nearbyintf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @nearbyintl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @nextafter(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @nextafterf(float, float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @nextafterl(x86_fp80, x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @nexttoward(double, x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @nexttowardf(float, x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @nexttowardl(x86_fp80, x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @remainder(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @remainderf(float, float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @remainderl(x86_fp80, x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @rint(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @rintf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @rintl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @round(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @roundf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @roundl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @scalbln(double, i64) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @scalblnf(float, i64) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @scalblnl(x86_fp80, i64) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @scalbn(double, i32) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @scalbnf(float, i32) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @scalbnl(x86_fp80, i32) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @sin(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @sinf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @sinl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @sinh(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @sinhf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @sinhl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @sqrt(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @sqrtf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @sqrtl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @tan(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @tanf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @tanl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @tanh(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @tanhf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @tanhl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @tgamma(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @tgammaf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @tgammal(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @trunc(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @truncf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @truncl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @cabs(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @cabsf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare { double, double } @cacos(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare<2 x float> @cacosf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare { double, double } @cacosh(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare<2 x float> @cacoshf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @carg(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @cargf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare { double, double } @casin(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare<2 x float> @casinf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare { double, double } @casinh(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare<2 x float> @casinhf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare { double, double } @catan(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare<2 x float> @catanf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare { double, double } @catanh(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare<2 x float> @catanhf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare { double, double } @ccos(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare<2 x float> @ccosf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare { double, double } @ccosh(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare<2 x float> @ccoshf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare { double, double } @cexp(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare<2 x float> @cexpf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @cimag(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @cimagf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare { double, double } @conj(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare<2 x float> @conjf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare { double, double } @clog(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare<2 x float> @clogf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare { double, double } @cproj(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare<2 x float> @cprojf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare { double, double } @cpow(double, double, double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare<2 x float> @cpowf(<2 x float>,<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @creal(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @crealf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare { double, double } @csin(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare<2 x float> @csinf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare { double, double } @csinh(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare<2 x float> @csinhf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare { double, double } @csqrt(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare<2 x float> @csqrtf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare { double, double } @ctan(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare<2 x float> @ctanf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare { double, double } @ctanh(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare<2 x float> @ctanhf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @__sinpi(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @__sinpif(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @__cospi(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @__cospif(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @__tanpi(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @__tanpif(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @__exp10(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @__exp10f(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare i32 @abs(i32) [[NUW:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare i64 @labs(i64) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare i64 @llabs(i64) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare double @copysign(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare float @copysignf(float, float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare x86_fp80 @copysignl(x86_fp80, x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare double @fabs(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare float @fabsf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare x86_fp80 @fabsl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare double @nan(i8*) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare float @nanf(i8*) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare x86_fp80 @nanl(i8*) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare double @ceil(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare float @ceilf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare x86_fp80 @ceill(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare double @floor(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare float @floorf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare x86_fp80 @floorl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare double @fmax(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare float @fmaxf(float, float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare x86_fp80 @fmaxl(x86_fp80, x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare double @fmin(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare float @fminf(float, float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare x86_fp80 @fminl(x86_fp80, x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare double @lgamma(double) [[NONCONST:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare float @lgammaf(float) [[NONCONST]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare x86_fp80 @lgammal(x86_fp80) [[NONCONST]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare double @nearbyint(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare float @nearbyintf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare x86_fp80 @nearbyintl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare double @rint(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare float @rintf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare x86_fp80 @rintl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare double @round(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare float @roundf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare x86_fp80 @roundl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare double @trunc(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare float @truncf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare x86_fp80 @truncl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare double @cabs(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare float @cabsf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare { double, double } @cacos(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare<2 x float> @cacosf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare { double, double } @cacosh(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare<2 x float> @cacoshf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare double @carg(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare float @cargf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare { double, double } @casin(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare<2 x float> @casinf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare { double, double } @casinh(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare<2 x float> @casinhf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare { double, double } @catan(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare<2 x float> @catanf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare { double, double } @catanh(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare<2 x float> @catanhf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare { double, double } @ccos(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare<2 x float> @ccosf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare { double, double } @ccosh(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare<2 x float> @ccoshf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare { double, double } @cexp(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare<2 x float> @cexpf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare double @cimag(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare float @cimagf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare { double, double } @conj(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare<2 x float> @conjf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare { double, double } @clog(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare<2 x float> @clogf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare { double, double } @cproj(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare<2 x float> @cprojf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare { double, double } @cpow(double, double, double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare<2 x float> @cpowf(<2 x float>,<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare double @creal(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare float @crealf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare { double, double } @csin(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare<2 x float> @csinf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare { double, double } @csinh(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare<2 x float> @csinhf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare { double, double } @csqrt(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare<2 x float> @csqrtf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare { double, double } @ctan(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare<2 x float> @ctanf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare { double, double } @ctanh(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare<2 x float> @ctanhf(<2 x float>) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: attributes [[NUW]] = { nounwind readnone{{.*}} }
end_comment

begin_comment
comment|// CHECK-NOERRNO: attributes [[NONCONST]] = {
end_comment

begin_comment
comment|// CHECK-NOERRNO-NOT: readnone
end_comment

begin_comment
comment|// CHECK-NOERRNO-SAME: nounwind{{.*}} }
end_comment

begin_comment
comment|// CHECK-ERRNO: attributes [[NONCONST]] = {
end_comment

begin_comment
comment|// CHECK-ERRNO-NOT: readnone
end_comment

begin_comment
comment|// CHECK-ERRNO-SAME: nounwind{{.*}} }
end_comment

begin_comment
comment|// CHECK-ERRNO: attributes [[NUW]] = { nounwind readnone{{.*}} }
end_comment

end_unit

