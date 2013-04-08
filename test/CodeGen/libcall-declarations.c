begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin12 -S -o - -emit-llvm %s | FileCheck %s -check-prefix=CHECK-NOERRNO
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-linux-gnu -S -o - -emit-llvm -fmath-errno %s | FileCheck %s -check-prefix=CHECK-ERRNO
end_comment

begin_comment
comment|// Prototypes.
end_comment

begin_function_decl
name|double
name|acos
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|acosl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|acosf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|asin
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|asinl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|asinf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|atan
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|atanl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|atanf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|atan2
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
end_function_decl

begin_function_decl
name|float
name|atan2f
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|ceil
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|ceill
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|ceilf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|copysign
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
end_function_decl

begin_function_decl
name|float
name|copysignf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|cos
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|cosl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|cosf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|exp
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|expl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|expf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|exp2
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|exp2l
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|exp2f
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|fabs
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|fabsl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|fabsf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|floor
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|floorl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|floorf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
end_function_decl

begin_function_decl
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
end_function_decl

begin_function_decl
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
end_function_decl

begin_function_decl
name|double
name|fmax
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
end_function_decl

begin_function_decl
name|float
name|fmaxf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|fmin
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
end_function_decl

begin_function_decl
name|float
name|fminf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|log
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|logl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|logf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|log2
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|log2l
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|log2f
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|nearbyint
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|nearbyintl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|nearbyintf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|pow
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
end_function_decl

begin_function_decl
name|float
name|powf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|rint
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|rintl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|rintf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|round
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|roundl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|roundf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|sin
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|sinl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|sinf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|sqrt
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|sqrtl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|sqrtf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|tan
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|tanl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|tanf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|trunc
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|truncl
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|truncf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Force emission of the declare statements.
end_comment

begin_decl_stmt
name|void
modifier|*
name|use
index|[]
init|=
block|{
name|acos
block|,
name|acosl
block|,
name|acosf
block|,
name|asin
block|,
name|asinl
block|,
name|asinf
block|,
name|atan
block|,
name|atanl
block|,
name|atanf
block|,
name|atan2
block|,
name|atan2l
block|,
name|atan2f
block|,
name|ceil
block|,
name|ceill
block|,
name|ceilf
block|,
name|copysign
block|,
name|copysignl
block|,
name|copysignf
block|,
name|cos
block|,
name|cosl
block|,
name|cosf
block|,
name|exp
block|,
name|expl
block|,
name|expf
block|,
name|exp2
block|,
name|exp2l
block|,
name|exp2f
block|,
name|fabs
block|,
name|fabsl
block|,
name|fabsf
block|,
name|floor
block|,
name|floorl
block|,
name|floorf
block|,
name|fma
block|,
name|fmal
block|,
name|fmaf
block|,
name|fmax
block|,
name|fmaxl
block|,
name|fmaxf
block|,
name|fmin
block|,
name|fminl
block|,
name|fminf
block|,
name|log
block|,
name|logl
block|,
name|logf
block|,
name|log2
block|,
name|log2l
block|,
name|log2f
block|,
name|nearbyint
block|,
name|nearbyintl
block|,
name|nearbyintf
block|,
name|pow
block|,
name|powl
block|,
name|powf
block|,
name|rint
block|,
name|rintl
block|,
name|rintf
block|,
name|round
block|,
name|roundl
block|,
name|roundf
block|,
name|sin
block|,
name|sinl
block|,
name|sinf
block|,
name|sqrt
block|,
name|sqrtl
block|,
name|sqrtf
block|,
name|tan
block|,
name|tanl
block|,
name|tanf
block|,
name|trunc
block|,
name|truncl
block|,
name|truncf
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-NOERRNO: declare double @acos(double) [[NUW:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @acosl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @acosf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @asin(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @asinl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @asinf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @atan(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @atanl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @atanf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @atan2(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @atan2l(x86_fp80, x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @atan2f(float, float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @ceil(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @ceill(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @ceilf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @copysign(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @copysignl(x86_fp80, x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @copysignf(float, float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @cos(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @cosl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @cosf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @exp(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @expl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @expf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @exp2(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @exp2l(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @exp2f(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @fabs(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @fabsl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @fabsf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @floor(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @floorl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @floorf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @fma(double, double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @fmal(x86_fp80, x86_fp80, x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @fmaf(float, float, float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @fmax(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @fmaxl(x86_fp80, x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @fmaxf(float, float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @fmin(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @fminl(x86_fp80, x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @fminf(float, float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @log(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @logl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @logf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @log2(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @log2l(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @log2f(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @nearbyint(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @nearbyintl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @nearbyintf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @pow(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @powl(x86_fp80, x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @powf(float, float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @rint(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @rintl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @rintf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @round(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @roundl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @roundf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @sin(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @sinl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @sinf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @sqrt(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @sqrtl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @sqrtf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @tan(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @tanl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @tanf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare double @trunc(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare x86_fp80 @truncl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: declare float @truncf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare double @ceil(double) [[NUW:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare x86_fp80 @ceill(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare float @ceilf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare double @copysign(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare x86_fp80 @copysignl(x86_fp80, x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare float @copysignf(float, float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare double @fabs(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare x86_fp80 @fabsl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare float @fabsf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare double @floor(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare x86_fp80 @floorl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare float @floorf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare double @fmax(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare x86_fp80 @fmaxl(x86_fp80, x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare float @fmaxf(float, float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare double @fmin(double, double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare x86_fp80 @fminl(x86_fp80, x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare float @fminf(float, float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare double @nearbyint(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare x86_fp80 @nearbyintl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare float @nearbyintf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare double @rint(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare x86_fp80 @rintl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare float @rintf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare double @round(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare x86_fp80 @roundl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare float @roundf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare double @trunc(double) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare x86_fp80 @truncl(x86_fp80) [[NUW]]
end_comment

begin_comment
comment|// CHECK-ERRNO: declare float @truncf(float) [[NUW]]
end_comment

begin_comment
comment|// CHECK-NOERRNO: attributes [[NUW]] = { nounwind readnone{{.*}} }
end_comment

begin_comment
comment|// CHECK-ERRNO: attributes [[NUW]] = { nounwind readnone{{.*}} }
end_comment

end_unit

