begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: not grep __builtin %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -triple x86_64-darwin-apple | FileCheck %s
end_comment

begin_function_decl
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|p
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|int
name|x
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%s: %d\n"
argument_list|,
name|str
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|q
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|double
name|x
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%s: %f\n"
argument_list|,
name|str
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|r
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%s: %p\n"
argument_list|,
name|str
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
name|int
name|random
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
name|N
init|=
name|random
argument_list|()
decl_stmt|;
define|#
directive|define
name|P
parameter_list|(
name|n
parameter_list|,
name|args
parameter_list|)
value|p(#n #args, __builtin_##n args)
define|#
directive|define
name|Q
parameter_list|(
name|n
parameter_list|,
name|args
parameter_list|)
value|q(#n #args, __builtin_##n args)
define|#
directive|define
name|R
parameter_list|(
name|n
parameter_list|,
name|args
parameter_list|)
value|r(#n #args, __builtin_##n args)
define|#
directive|define
name|V
parameter_list|(
name|n
parameter_list|,
name|args
parameter_list|)
value|p(#n #args, (__builtin_##n args, 0))
name|P
argument_list|(
name|types_compatible_p
argument_list|,
operator|(
name|int
operator|,
name|float
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|choose_expr
argument_list|,
operator|(
literal|0
operator|,
literal|10
operator|,
literal|20
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|constant_p
argument_list|,
operator|(
sizeof|sizeof
argument_list|(
literal|10
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|expect
argument_list|,
operator|(
name|N
operator|==
literal|12
operator|,
literal|0
operator|)
argument_list|)
expr_stmt|;
name|V
argument_list|(
name|prefetch
argument_list|,
operator|(
operator|&
name|N
operator|)
argument_list|)
expr_stmt|;
name|V
argument_list|(
name|prefetch
argument_list|,
operator|(
operator|&
name|N
operator|,
literal|1
operator|)
argument_list|)
expr_stmt|;
name|V
argument_list|(
name|prefetch
argument_list|,
operator|(
operator|&
name|N
operator|,
literal|1
operator|,
literal|0
operator|)
argument_list|)
expr_stmt|;
comment|// Numeric Constants
name|Q
argument_list|(
name|huge_val
argument_list|,
operator|(
operator|)
argument_list|)
expr_stmt|;
name|Q
argument_list|(
name|huge_valf
argument_list|,
operator|(
operator|)
argument_list|)
expr_stmt|;
name|Q
argument_list|(
name|huge_vall
argument_list|,
operator|(
operator|)
argument_list|)
expr_stmt|;
name|Q
argument_list|(
name|inf
argument_list|,
operator|(
operator|)
argument_list|)
expr_stmt|;
name|Q
argument_list|(
name|inff
argument_list|,
operator|(
operator|)
argument_list|)
expr_stmt|;
name|Q
argument_list|(
name|infl
argument_list|,
operator|(
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|fpclassify
argument_list|,
operator|(
literal|0
operator|,
literal|1
operator|,
literal|2
operator|,
literal|3
operator|,
literal|4
operator|,
literal|1.0
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|fpclassify
argument_list|,
operator|(
literal|0
operator|,
literal|1
operator|,
literal|2
operator|,
literal|3
operator|,
literal|4
operator|,
literal|1.0f
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|fpclassify
argument_list|,
operator|(
literal|0
operator|,
literal|1
operator|,
literal|2
operator|,
literal|3
operator|,
literal|4
operator|,
literal|1.0l
operator|)
argument_list|)
expr_stmt|;
name|Q
argument_list|(
name|nan
argument_list|,
operator|(
literal|""
operator|)
argument_list|)
expr_stmt|;
name|Q
argument_list|(
name|nanf
argument_list|,
operator|(
literal|""
operator|)
argument_list|)
expr_stmt|;
name|Q
argument_list|(
name|nanl
argument_list|,
operator|(
literal|""
operator|)
argument_list|)
expr_stmt|;
name|Q
argument_list|(
name|nans
argument_list|,
operator|(
literal|""
operator|)
argument_list|)
expr_stmt|;
name|Q
argument_list|(
name|nan
argument_list|,
operator|(
literal|"10"
operator|)
argument_list|)
expr_stmt|;
name|Q
argument_list|(
name|nanf
argument_list|,
operator|(
literal|"10"
operator|)
argument_list|)
expr_stmt|;
name|Q
argument_list|(
name|nanl
argument_list|,
operator|(
literal|"10"
operator|)
argument_list|)
expr_stmt|;
name|Q
argument_list|(
name|nans
argument_list|,
operator|(
literal|"10"
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|isgreater
argument_list|,
operator|(
literal|1.
operator|,
literal|2.
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|isgreaterequal
argument_list|,
operator|(
literal|1.
operator|,
literal|2.
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|isless
argument_list|,
operator|(
literal|1.
operator|,
literal|2.
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|islessequal
argument_list|,
operator|(
literal|1.
operator|,
literal|2.
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|islessgreater
argument_list|,
operator|(
literal|1.
operator|,
literal|2.
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|isunordered
argument_list|,
operator|(
literal|1.
operator|,
literal|2.
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|isinf
argument_list|,
operator|(
literal|1.
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|isinf_sign
argument_list|,
operator|(
literal|1.
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|isnan
argument_list|,
operator|(
literal|1.
operator|)
argument_list|)
expr_stmt|;
comment|// Bitwise& Numeric Functions
name|P
argument_list|(
name|abs
argument_list|,
operator|(
name|N
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|clz
argument_list|,
operator|(
name|N
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|clzl
argument_list|,
operator|(
name|N
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|clzll
argument_list|,
operator|(
name|N
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|ctz
argument_list|,
operator|(
name|N
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|ctzl
argument_list|,
operator|(
name|N
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|ctzll
argument_list|,
operator|(
name|N
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|ffs
argument_list|,
operator|(
name|N
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|ffsl
argument_list|,
operator|(
name|N
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|ffsll
argument_list|,
operator|(
name|N
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|parity
argument_list|,
operator|(
name|N
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|parityl
argument_list|,
operator|(
name|N
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|parityll
argument_list|,
operator|(
name|N
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|popcount
argument_list|,
operator|(
name|N
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|popcountl
argument_list|,
operator|(
name|N
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|popcountll
argument_list|,
operator|(
name|N
operator|)
argument_list|)
expr_stmt|;
name|Q
argument_list|(
name|powi
argument_list|,
operator|(
literal|1.2f
operator|,
name|N
operator|)
argument_list|)
expr_stmt|;
name|Q
argument_list|(
name|powif
argument_list|,
operator|(
literal|1.2f
operator|,
name|N
operator|)
argument_list|)
expr_stmt|;
name|Q
argument_list|(
name|powil
argument_list|,
operator|(
literal|1.2f
operator|,
name|N
operator|)
argument_list|)
expr_stmt|;
comment|// Lib functions
name|int
name|a
decl_stmt|,
name|b
decl_stmt|,
name|n
init|=
name|random
argument_list|()
decl_stmt|;
comment|// Avoid optimizing out.
name|char
name|s0
index|[
literal|10
index|]
decl_stmt|,
name|s1
index|[]
init|=
literal|"Hello"
decl_stmt|;
name|V
argument_list|(
name|strcat
argument_list|,
operator|(
name|s0
operator|,
name|s1
operator|)
argument_list|)
expr_stmt|;
name|V
argument_list|(
name|strcmp
argument_list|,
operator|(
name|s0
operator|,
name|s1
operator|)
argument_list|)
expr_stmt|;
name|V
argument_list|(
name|strncat
argument_list|,
operator|(
name|s0
operator|,
name|s1
operator|,
name|n
operator|)
argument_list|)
expr_stmt|;
name|V
argument_list|(
name|strchr
argument_list|,
operator|(
name|s0
operator|,
name|s1
index|[
literal|0
index|]
operator|)
argument_list|)
expr_stmt|;
name|V
argument_list|(
name|strrchr
argument_list|,
operator|(
name|s0
operator|,
name|s1
index|[
literal|0
index|]
operator|)
argument_list|)
expr_stmt|;
name|V
argument_list|(
name|strcpy
argument_list|,
operator|(
name|s0
operator|,
name|s1
operator|)
argument_list|)
expr_stmt|;
name|V
argument_list|(
name|strncpy
argument_list|,
operator|(
name|s0
operator|,
name|s1
operator|,
name|n
operator|)
argument_list|)
expr_stmt|;
comment|// Object size checking
name|V
argument_list|(
name|__memset_chk
argument_list|,
operator|(
name|s0
operator|,
literal|0
operator|,
sizeof|sizeof
name|s0
operator|,
name|n
operator|)
argument_list|)
expr_stmt|;
name|V
argument_list|(
name|__memcpy_chk
argument_list|,
operator|(
name|s0
operator|,
name|s1
operator|,
sizeof|sizeof
name|s0
operator|,
name|n
operator|)
argument_list|)
expr_stmt|;
name|V
argument_list|(
name|__memmove_chk
argument_list|,
operator|(
name|s0
operator|,
name|s1
operator|,
sizeof|sizeof
name|s0
operator|,
name|n
operator|)
argument_list|)
expr_stmt|;
name|V
argument_list|(
name|__mempcpy_chk
argument_list|,
operator|(
name|s0
operator|,
name|s1
operator|,
sizeof|sizeof
name|s0
operator|,
name|n
operator|)
argument_list|)
expr_stmt|;
name|V
argument_list|(
name|__strncpy_chk
argument_list|,
operator|(
name|s0
operator|,
name|s1
operator|,
sizeof|sizeof
name|s0
operator|,
name|n
operator|)
argument_list|)
expr_stmt|;
name|V
argument_list|(
name|__strcpy_chk
argument_list|,
operator|(
name|s0
operator|,
name|s1
operator|,
name|n
operator|)
argument_list|)
expr_stmt|;
name|s0
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
name|V
argument_list|(
name|__strcat_chk
argument_list|,
operator|(
name|s0
operator|,
name|s1
operator|,
name|n
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|object_size
argument_list|,
operator|(
name|s0
operator|,
literal|0
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|object_size
argument_list|,
operator|(
name|s0
operator|,
literal|1
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|object_size
argument_list|,
operator|(
name|s0
operator|,
literal|2
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|object_size
argument_list|,
operator|(
name|s0
operator|,
literal|3
operator|)
argument_list|)
expr_stmt|;
comment|// Whatever
name|P
argument_list|(
name|bswap16
argument_list|,
operator|(
name|N
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|bswap32
argument_list|,
operator|(
name|N
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|bswap64
argument_list|,
operator|(
name|N
operator|)
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.bitreverse.i8
comment|// CHECK: @llvm.bitreverse.i16
comment|// CHECK: @llvm.bitreverse.i32
comment|// CHECK: @llvm.bitreverse.i64
name|P
argument_list|(
name|bitreverse8
argument_list|,
operator|(
name|N
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|bitreverse16
argument_list|,
operator|(
name|N
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|bitreverse32
argument_list|,
operator|(
name|N
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|bitreverse64
argument_list|,
operator|(
name|N
operator|)
argument_list|)
expr_stmt|;
comment|// FIXME
comment|// V(clear_cache, (&N,&N+1));
name|V
argument_list|(
name|trap
argument_list|,
operator|(
operator|)
argument_list|)
expr_stmt|;
name|R
argument_list|(
name|extract_return_addr
argument_list|,
operator|(
operator|&
name|N
operator|)
argument_list|)
expr_stmt|;
name|P
argument_list|(
name|signbit
argument_list|,
operator|(
literal|1.0
operator|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
name|foo
parameter_list|()
block|{
name|__builtin_strcat
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @bar(
end_comment

begin_function
name|void
name|bar
parameter_list|()
block|{
name|float
name|f
decl_stmt|;
name|double
name|d
decl_stmt|;
name|long
name|double
name|ld
decl_stmt|;
comment|// LLVM's hex representation of float constants is really unfortunate;
comment|// basically it does a float-to-double "conversion" and then prints the
comment|// hex form of that.  That gives us weird artifacts like exponents
comment|// that aren't numerically similar to the original exponent and
comment|// significand bit-patterns that are offset by three bits (because
comment|// the exponent was expanded from 8 bits to 11).
comment|//
comment|// 0xAE98 == 1010111010011000
comment|// 0x15D3 == 1010111010011
name|f
operator|=
name|__builtin_huge_valf
argument_list|()
expr_stmt|;
comment|// CHECK: float    0x7FF0000000000000
name|d
operator|=
name|__builtin_huge_val
argument_list|()
expr_stmt|;
comment|// CHECK: double   0x7FF0000000000000
name|ld
operator|=
name|__builtin_huge_vall
argument_list|()
expr_stmt|;
comment|// CHECK: x86_fp80 0xK7FFF8000000000000000
name|f
operator|=
name|__builtin_nanf
argument_list|(
literal|""
argument_list|)
expr_stmt|;
comment|// CHECK: float    0x7FF8000000000000
name|d
operator|=
name|__builtin_nan
argument_list|(
literal|""
argument_list|)
expr_stmt|;
comment|// CHECK: double   0x7FF8000000000000
name|ld
operator|=
name|__builtin_nanl
argument_list|(
literal|""
argument_list|)
expr_stmt|;
comment|// CHECK: x86_fp80 0xK7FFFC000000000000000
name|f
operator|=
name|__builtin_nanf
argument_list|(
literal|"0xAE98"
argument_list|)
expr_stmt|;
comment|// CHECK: float    0x7FF815D300000000
name|d
operator|=
name|__builtin_nan
argument_list|(
literal|"0xAE98"
argument_list|)
expr_stmt|;
comment|// CHECK: double   0x7FF800000000AE98
name|ld
operator|=
name|__builtin_nanl
argument_list|(
literal|"0xAE98"
argument_list|)
expr_stmt|;
comment|// CHECK: x86_fp80 0xK7FFFC00000000000AE98
name|f
operator|=
name|__builtin_nansf
argument_list|(
literal|""
argument_list|)
expr_stmt|;
comment|// CHECK: float    0x7FF4000000000000
name|d
operator|=
name|__builtin_nans
argument_list|(
literal|""
argument_list|)
expr_stmt|;
comment|// CHECK: double   0x7FF4000000000000
name|ld
operator|=
name|__builtin_nansl
argument_list|(
literal|""
argument_list|)
expr_stmt|;
comment|// CHECK: x86_fp80 0xK7FFFA000000000000000
name|f
operator|=
name|__builtin_nansf
argument_list|(
literal|"0xAE98"
argument_list|)
expr_stmt|;
comment|// CHECK: float    0x7FF015D300000000
name|d
operator|=
name|__builtin_nans
argument_list|(
literal|"0xAE98"
argument_list|)
expr_stmt|;
comment|// CHECK: double   0x7FF000000000AE98
name|ld
operator|=
name|__builtin_nansl
argument_list|(
literal|"0xAE98"
argument_list|)
expr_stmt|;
comment|// CHECK: x86_fp80 0xK7FFF800000000000AE98
block|}
end_function

begin_comment
comment|// CHECK: }
end_comment

begin_comment
comment|// CHECK-LABEL: define void @test_float_builtins
end_comment

begin_function
name|void
name|test_float_builtins
parameter_list|(
name|float
name|F
parameter_list|,
name|double
name|D
parameter_list|,
name|long
name|double
name|LD
parameter_list|)
block|{
specifier|volatile
name|int
name|res
decl_stmt|;
name|res
operator|=
name|__builtin_isinf
argument_list|(
name|F
argument_list|)
expr_stmt|;
comment|// CHECK:  call float @llvm.fabs.f32(float
comment|// CHECK:  fcmp oeq float {{.*}}, 0x7FF0000000000000
name|res
operator|=
name|__builtin_isinf
argument_list|(
name|D
argument_list|)
expr_stmt|;
comment|// CHECK:  call double @llvm.fabs.f64(double
comment|// CHECK:  fcmp oeq double {{.*}}, 0x7FF0000000000000
name|res
operator|=
name|__builtin_isinf
argument_list|(
name|LD
argument_list|)
expr_stmt|;
comment|// CHECK:  call x86_fp80 @llvm.fabs.f80(x86_fp80
comment|// CHECK:  fcmp oeq x86_fp80 {{.*}}, 0xK7FFF8000000000000000
name|res
operator|=
name|__builtin_isinf_sign
argument_list|(
name|F
argument_list|)
expr_stmt|;
comment|// CHECK:  %[[ABS:.*]] = call float @llvm.fabs.f32(float %[[ARG:.*]])
comment|// CHECK:  %[[ISINF:.*]] = fcmp oeq float %[[ABS]], 0x7FF0000000000000
comment|// CHECK:  %[[BITCAST:.*]] = bitcast float %[[ARG]] to i32
comment|// CHECK:  %[[ISNEG:.*]] = icmp slt i32 %[[BITCAST]], 0
comment|// CHECK:  %[[SIGN:.*]] = select i1 %[[ISNEG]], i32 -1, i32 1
comment|// CHECK:  select i1 %[[ISINF]], i32 %[[SIGN]], i32 0
name|res
operator|=
name|__builtin_isinf_sign
argument_list|(
name|D
argument_list|)
expr_stmt|;
comment|// CHECK:  %[[ABS:.*]] = call double @llvm.fabs.f64(double %[[ARG:.*]])
comment|// CHECK:  %[[ISINF:.*]] = fcmp oeq double %[[ABS]], 0x7FF0000000000000
comment|// CHECK:  %[[BITCAST:.*]] = bitcast double %[[ARG]] to i64
comment|// CHECK:  %[[ISNEG:.*]] = icmp slt i64 %[[BITCAST]], 0
comment|// CHECK:  %[[SIGN:.*]] = select i1 %[[ISNEG]], i32 -1, i32 1
comment|// CHECK:  select i1 %[[ISINF]], i32 %[[SIGN]], i32 0
name|res
operator|=
name|__builtin_isinf_sign
argument_list|(
name|LD
argument_list|)
expr_stmt|;
comment|// CHECK:  %[[ABS:.*]] = call x86_fp80 @llvm.fabs.f80(x86_fp80 %[[ARG:.*]])
comment|// CHECK:  %[[ISINF:.*]] = fcmp oeq x86_fp80 %[[ABS]], 0xK7FFF8000000000000000
comment|// CHECK:  %[[BITCAST:.*]] = bitcast x86_fp80 %[[ARG]] to i80
comment|// CHECK:  %[[ISNEG:.*]] = icmp slt i80 %[[BITCAST]], 0
comment|// CHECK:  %[[SIGN:.*]] = select i1 %[[ISNEG]], i32 -1, i32 1
comment|// CHECK:  select i1 %[[ISINF]], i32 %[[SIGN]], i32 0
name|res
operator|=
name|__builtin_isfinite
argument_list|(
name|F
argument_list|)
expr_stmt|;
comment|// CHECK: call float @llvm.fabs.f32(float
comment|// CHECK: fcmp one float {{.*}}, 0x7FF0000000000000
name|res
operator|=
name|finite
argument_list|(
name|D
argument_list|)
expr_stmt|;
comment|// CHECK: call double @llvm.fabs.f64(double
comment|// CHECK: fcmp one double {{.*}}, 0x7FF0000000000000
name|res
operator|=
name|__builtin_isnormal
argument_list|(
name|F
argument_list|)
expr_stmt|;
comment|// CHECK: fcmp oeq float
comment|// CHECK: call float @llvm.fabs.f32(float
comment|// CHECK: fcmp ult float {{.*}}, 0x7FF0000000000000
comment|// CHECK: fcmp uge float {{.*}}, 0x3810000000000000
comment|// CHECK: and i1
comment|// CHECK: and i1
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_float_builtin_ops
end_comment

begin_function
name|void
name|test_float_builtin_ops
parameter_list|(
name|float
name|F
parameter_list|,
name|double
name|D
parameter_list|,
name|long
name|double
name|LD
parameter_list|)
block|{
specifier|volatile
name|float
name|resf
decl_stmt|;
specifier|volatile
name|double
name|resd
decl_stmt|;
specifier|volatile
name|long
name|double
name|resld
decl_stmt|;
name|resf
operator|=
name|__builtin_fmodf
argument_list|(
name|F
argument_list|,
name|F
argument_list|)
expr_stmt|;
comment|// CHECK: frem float
name|resd
operator|=
name|__builtin_fmod
argument_list|(
name|D
argument_list|,
name|D
argument_list|)
expr_stmt|;
comment|// CHECK: frem double
name|resld
operator|=
name|__builtin_fmodl
argument_list|(
name|LD
argument_list|,
name|LD
argument_list|)
expr_stmt|;
comment|// CHECK: frem x86_fp80
name|resf
operator|=
name|__builtin_fabsf
argument_list|(
name|F
argument_list|)
expr_stmt|;
name|resd
operator|=
name|__builtin_fabs
argument_list|(
name|D
argument_list|)
expr_stmt|;
name|resld
operator|=
name|__builtin_fabsl
argument_list|(
name|LD
argument_list|)
expr_stmt|;
comment|// CHECK: call float @llvm.fabs.f32(float
comment|// CHECK: call double @llvm.fabs.f64(double
comment|// CHECK: call x86_fp80 @llvm.fabs.f80(x86_fp80
name|resf
operator|=
name|__builtin_canonicalizef
argument_list|(
name|F
argument_list|)
expr_stmt|;
name|resd
operator|=
name|__builtin_canonicalize
argument_list|(
name|D
argument_list|)
expr_stmt|;
name|resld
operator|=
name|__builtin_canonicalizel
argument_list|(
name|LD
argument_list|)
expr_stmt|;
comment|// CHECK: call float @llvm.canonicalize.f32(float
comment|// CHECK: call double @llvm.canonicalize.f64(double
comment|// CHECK: call x86_fp80 @llvm.canonicalize.f80(x86_fp80
name|resf
operator|=
name|__builtin_fminf
argument_list|(
name|F
argument_list|,
name|F
argument_list|)
expr_stmt|;
comment|// CHECK: call float @llvm.minnum.f32
name|resd
operator|=
name|__builtin_fmin
argument_list|(
name|D
argument_list|,
name|D
argument_list|)
expr_stmt|;
comment|// CHECK: call double @llvm.minnum.f64
name|resld
operator|=
name|__builtin_fminl
argument_list|(
name|LD
argument_list|,
name|LD
argument_list|)
expr_stmt|;
comment|// CHECK: call x86_fp80 @llvm.minnum.f80
name|resf
operator|=
name|__builtin_fmaxf
argument_list|(
name|F
argument_list|,
name|F
argument_list|)
expr_stmt|;
comment|// CHECK: call float @llvm.maxnum.f32
name|resd
operator|=
name|__builtin_fmax
argument_list|(
name|D
argument_list|,
name|D
argument_list|)
expr_stmt|;
comment|// CHECK: call double @llvm.maxnum.f64
name|resld
operator|=
name|__builtin_fmaxl
argument_list|(
name|LD
argument_list|,
name|LD
argument_list|)
expr_stmt|;
comment|// CHECK: call x86_fp80 @llvm.maxnum.f80
name|resf
operator|=
name|__builtin_fabsf
argument_list|(
name|F
argument_list|)
expr_stmt|;
comment|// CHECK: call float @llvm.fabs.f32
name|resd
operator|=
name|__builtin_fabs
argument_list|(
name|D
argument_list|)
expr_stmt|;
comment|// CHECK: call double @llvm.fabs.f64
name|resld
operator|=
name|__builtin_fabsl
argument_list|(
name|LD
argument_list|)
expr_stmt|;
comment|// CHECK: call x86_fp80 @llvm.fabs.f80
name|resf
operator|=
name|__builtin_copysignf
argument_list|(
name|F
argument_list|,
name|F
argument_list|)
expr_stmt|;
comment|// CHECK: call float @llvm.copysign.f32
name|resd
operator|=
name|__builtin_copysign
argument_list|(
name|D
argument_list|,
name|D
argument_list|)
expr_stmt|;
comment|// CHECK: call double @llvm.copysign.f64
name|resld
operator|=
name|__builtin_copysignl
argument_list|(
name|LD
argument_list|,
name|LD
argument_list|)
expr_stmt|;
comment|// CHECK: call x86_fp80 @llvm.copysign.f80
name|resf
operator|=
name|__builtin_ceilf
argument_list|(
name|F
argument_list|)
expr_stmt|;
comment|// CHECK: call float @llvm.ceil.f32
name|resd
operator|=
name|__builtin_ceil
argument_list|(
name|D
argument_list|)
expr_stmt|;
comment|// CHECK: call double @llvm.ceil.f64
name|resld
operator|=
name|__builtin_ceill
argument_list|(
name|LD
argument_list|)
expr_stmt|;
comment|// CHECK: call x86_fp80 @llvm.ceil.f80
name|resf
operator|=
name|__builtin_floorf
argument_list|(
name|F
argument_list|)
expr_stmt|;
comment|// CHECK: call float @llvm.floor.f32
name|resd
operator|=
name|__builtin_floor
argument_list|(
name|D
argument_list|)
expr_stmt|;
comment|// CHECK: call double @llvm.floor.f64
name|resld
operator|=
name|__builtin_floorl
argument_list|(
name|LD
argument_list|)
expr_stmt|;
comment|// CHECK: call x86_fp80 @llvm.floor.f80
name|resf
operator|=
name|__builtin_truncf
argument_list|(
name|F
argument_list|)
expr_stmt|;
comment|// CHECK: call float @llvm.trunc.f32
name|resd
operator|=
name|__builtin_trunc
argument_list|(
name|D
argument_list|)
expr_stmt|;
comment|// CHECK: call double @llvm.trunc.f64
name|resld
operator|=
name|__builtin_truncl
argument_list|(
name|LD
argument_list|)
expr_stmt|;
comment|// CHECK: call x86_fp80 @llvm.trunc.f80
name|resf
operator|=
name|__builtin_rintf
argument_list|(
name|F
argument_list|)
expr_stmt|;
comment|// CHECK: call float @llvm.rint.f32
name|resd
operator|=
name|__builtin_rint
argument_list|(
name|D
argument_list|)
expr_stmt|;
comment|// CHECK: call double @llvm.rint.f64
name|resld
operator|=
name|__builtin_rintl
argument_list|(
name|LD
argument_list|)
expr_stmt|;
comment|// CHECK: call x86_fp80 @llvm.rint.f80
name|resf
operator|=
name|__builtin_nearbyintf
argument_list|(
name|F
argument_list|)
expr_stmt|;
comment|// CHECK: call float @llvm.nearbyint.f32
name|resd
operator|=
name|__builtin_nearbyint
argument_list|(
name|D
argument_list|)
expr_stmt|;
comment|// CHECK: call double @llvm.nearbyint.f64
name|resld
operator|=
name|__builtin_nearbyintl
argument_list|(
name|LD
argument_list|)
expr_stmt|;
comment|// CHECK: call x86_fp80 @llvm.nearbyint.f80
name|resf
operator|=
name|__builtin_roundf
argument_list|(
name|F
argument_list|)
expr_stmt|;
comment|// CHECK: call float @llvm.round.f32
name|resd
operator|=
name|__builtin_round
argument_list|(
name|D
argument_list|)
expr_stmt|;
comment|// CHECK: call double @llvm.round.f64
name|resld
operator|=
name|__builtin_roundl
argument_list|(
name|LD
argument_list|)
expr_stmt|;
comment|// CHECK: call x86_fp80 @llvm.round.f80
block|}
end_function

begin_comment
comment|// __builtin_longjmp isn't supported on all platforms, so only test it on X86.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_comment
comment|// CHECK-LABEL: define void @test_builtin_longjmp
end_comment

begin_function
name|void
name|test_builtin_longjmp
parameter_list|(
name|void
modifier|*
modifier|*
name|buffer
parameter_list|)
block|{
comment|// CHECK: [[BITCAST:%.*]] = bitcast
comment|// CHECK-NEXT: call void @llvm.eh.sjlj.longjmp(i8* [[BITCAST]])
name|__builtin_longjmp
argument_list|(
name|buffer
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: unreachable
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK-LABEL: define i64 @test_builtin_readcyclecounter
end_comment

begin_function
name|long
name|long
name|test_builtin_readcyclecounter
parameter_list|()
block|{
comment|// CHECK: call i64 @llvm.readcyclecounter()
return|return
name|__builtin_readcyclecounter
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// Behavior of __builtin_os_log differs between platforms, so only test on X86
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_comment
comment|// CHECK-LABEL: define void @test_builtin_os_log
end_comment

begin_comment
comment|// CHECK: (i8* [[BUF:%.*]], i32 [[I:%.*]], i8* [[DATA:%.*]])
end_comment

begin_function
name|void
name|test_builtin_os_log
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|i
parameter_list|,
specifier|const
name|char
modifier|*
name|data
parameter_list|)
block|{
specifier|volatile
name|int
name|len
decl_stmt|;
comment|// CHECK: store i8* [[BUF]], i8** [[BUF_ADDR:%.*]], align 8
comment|// CHECK: store i32 [[I]], i32* [[I_ADDR:%.*]], align 4
comment|// CHECK: store i8* [[DATA]], i8** [[DATA_ADDR:%.*]], align 8
comment|// CHECK: store volatile i32 34
name|len
operator|=
name|__builtin_os_log_format_buffer_size
argument_list|(
literal|"%d %{public}s %{private}.16P"
argument_list|,
name|i
argument_list|,
name|data
argument_list|,
name|data
argument_list|)
expr_stmt|;
comment|// CHECK: [[BUF2:%.*]] = load i8*, i8** [[BUF_ADDR]]
comment|// CHECK: [[SUMMARY:%.*]] = getelementptr i8, i8* [[BUF2]], i64 0
comment|// CHECK: store i8 3, i8* [[SUMMARY]]
comment|// CHECK: [[NUM_ARGS:%.*]] = getelementptr i8, i8* [[BUF2]], i64 1
comment|// CHECK: store i8 4, i8* [[NUM_ARGS]]
comment|//
comment|// CHECK: [[ARG1_DESC:%.*]] = getelementptr i8, i8* [[BUF2]], i64 2
comment|// CHECK: store i8 0, i8* [[ARG1_DESC]]
comment|// CHECK: [[ARG1_SIZE:%.*]] = getelementptr i8, i8* [[BUF2]], i64 3
comment|// CHECK: store i8 4, i8* [[ARG1_SIZE]]
comment|// CHECK: [[ARG1:%.*]] = getelementptr i8, i8* [[BUF2]], i64 4
comment|// CHECK: [[ARG1_INT:%.*]] = bitcast i8* [[ARG1]] to i32*
comment|// CHECK: [[I2:%.*]] = load i32, i32* [[I_ADDR]]
comment|// CHECK: store i32 [[I2]], i32* [[ARG1_INT]]
comment|// CHECK: [[ARG2_DESC:%.*]] = getelementptr i8, i8* [[BUF2]], i64 8
comment|// CHECK: store i8 34, i8* [[ARG2_DESC]]
comment|// CHECK: [[ARG2_SIZE:%.*]] = getelementptr i8, i8* [[BUF2]], i64 9
comment|// CHECK: store i8 8, i8* [[ARG2_SIZE]]
comment|// CHECK: [[ARG2:%.*]] = getelementptr i8, i8* [[BUF2]], i64 10
comment|// CHECK: [[ARG2_PTR:%.*]] = bitcast i8* [[ARG2]] to i8**
comment|// CHECK: [[DATA2:%.*]] = load i8*, i8** [[DATA_ADDR]]
comment|// CHECK: store i8* [[DATA2]], i8** [[ARG2_PTR]]
comment|// CHECK: [[ARG3_DESC:%.*]] = getelementptr i8, i8* [[BUF2]], i64 18
comment|// CHECK: store i8 17, i8* [[ARG3_DESC]]
comment|// CHECK: [[ARG3_SIZE:%.*]] = getelementptr i8, i8* [[BUF2]], i64 19
comment|// CHECK: store i8 4, i8* [[ARG3_SIZE]]
comment|// CHECK: [[ARG3:%.*]] = getelementptr i8, i8* [[BUF2]], i64 20
comment|// CHECK: [[ARG3_INT:%.*]] = bitcast i8* [[ARG3]] to i32*
comment|// CHECK: store i32 16, i32* [[ARG3_INT]]
comment|// CHECK: [[ARG4_DESC:%.*]] = getelementptr i8, i8* [[BUF2]], i64 24
comment|// CHECK: store i8 49, i8* [[ARG4_DESC]]
comment|// CHECK: [[ARG4_SIZE:%.*]] = getelementptr i8, i8* [[BUF2]], i64 25
comment|// CHECK: store i8 8, i8* [[ARG4_SIZE]]
comment|// CHECK: [[ARG4:%.*]] = getelementptr i8, i8* [[BUF2]], i64 26
comment|// CHECK: [[ARG4_PTR:%.*]] = bitcast i8* [[ARG4]] to i8**
comment|// CHECK: [[DATA3:%.*]] = load i8*, i8** [[DATA_ADDR]]
comment|// CHECK: store i8* [[DATA3]], i8** [[ARG4_PTR]]
name|__builtin_os_log_format
argument_list|(
name|buf
argument_list|,
literal|"%d %{public}s %{private}.16P"
argument_list|,
name|i
argument_list|,
name|data
argument_list|,
name|data
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_builtin_os_log_errno
end_comment

begin_comment
comment|// CHECK: (i8* [[BUF:%.*]], i8* [[DATA:%.*]])
end_comment

begin_function
name|void
name|test_builtin_os_log_errno
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
specifier|const
name|char
modifier|*
name|data
parameter_list|)
block|{
specifier|volatile
name|int
name|len
decl_stmt|;
comment|// CHECK: store i8* [[BUF]], i8** [[BUF_ADDR:%.*]], align 8
comment|// CHECK: store i8* [[DATA]], i8** [[DATA_ADDR:%.*]], align 8
comment|// CHECK: store volatile i32 2
name|len
operator|=
name|__builtin_os_log_format_buffer_size
argument_list|(
literal|"%S"
argument_list|)
expr_stmt|;
comment|// CHECK: [[BUF2:%.*]] = load i8*, i8** [[BUF_ADDR]]
comment|// CHECK: [[SUMMARY:%.*]] = getelementptr i8, i8* [[BUF2]], i64 0
comment|// CHECK: store i8 2, i8* [[SUMMARY]]
comment|// CHECK: [[NUM_ARGS:%.*]] = getelementptr i8, i8* [[BUF2]], i64 1
comment|// CHECK: store i8 1, i8* [[NUM_ARGS]]
comment|// CHECK: [[ARG1_DESC:%.*]] = getelementptr i8, i8* [[BUF2]], i64 2
comment|// CHECK: store i8 96, i8* [[ARG1_DESC]]
comment|// CHECK: [[ARG1_SIZE:%.*]] = getelementptr i8, i8* [[BUF2]], i64 3
comment|// CHECK: store i8 0, i8* [[ARG1_SIZE]]
comment|// CHECK: [[ARG1:%.*]] = getelementptr i8, i8* [[BUF2]], i64 4
comment|// CHECK: [[ARG1_INT:%.*]] = bitcast i8* [[ARG1]] to i32*
comment|// CHECK: store i32 0, i32* [[ARG1_INT]]
name|__builtin_os_log_format
argument_list|(
name|buf
argument_list|,
literal|"%m"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_builtin_os_log_wide
end_comment

begin_comment
comment|// CHECK: (i8* [[BUF:%.*]], i8* [[DATA:%.*]], i32* [[STR:%.*]])
end_comment

begin_typedef
typedef|typedef
name|int
name|wchar_t
typedef|;
end_typedef

begin_function
name|void
name|test_builtin_os_log_wide
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|wchar_t
modifier|*
name|str
parameter_list|)
block|{
specifier|volatile
name|int
name|len
decl_stmt|;
comment|// CHECK: store i8* [[BUF]], i8** [[BUF_ADDR:%.*]], align 8
comment|// CHECK: store i8* [[DATA]], i8** [[DATA_ADDR:%.*]], align 8
comment|// CHECK: store i32* [[STR]], i32** [[STR_ADDR:%.*]],
comment|// CHECK: store volatile i32 12
name|len
operator|=
name|__builtin_os_log_format_buffer_size
argument_list|(
literal|"%S"
argument_list|,
name|str
argument_list|)
expr_stmt|;
comment|// CHECK: [[BUF2:%.*]] = load i8*, i8** [[BUF_ADDR]]
comment|// CHECK: [[SUMMARY:%.*]] = getelementptr i8, i8* [[BUF2]], i64 0
comment|// CHECK: store i8 2, i8* [[SUMMARY]]
comment|// CHECK: [[NUM_ARGS:%.*]] = getelementptr i8, i8* [[BUF2]], i64 1
comment|// CHECK: store i8 1, i8* [[NUM_ARGS]]
comment|// CHECK: [[ARG1_DESC:%.*]] = getelementptr i8, i8* [[BUF2]], i64 2
comment|// CHECK: store i8 80, i8* [[ARG1_DESC]]
comment|// CHECK: [[ARG1_SIZE:%.*]] = getelementptr i8, i8* [[BUF2]], i64 3
comment|// CHECK: store i8 8, i8* [[ARG1_SIZE]]
comment|// CHECK: [[ARG1:%.*]] = getelementptr i8, i8* [[BUF2]], i64 4
comment|// CHECK: [[ARG1_PTR:%.*]] = bitcast i8* [[ARG1]] to i32**
comment|// CHECK: [[STR2:%.*]] = load i32*, i32** [[STR_ADDR]]
comment|// CHECK: store i32* [[STR2]], i32** [[ARG1_PTR]]
name|__builtin_os_log_format
argument_list|(
name|buf
argument_list|,
literal|"%S"
argument_list|,
name|str
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_builtin_os_log_precision_width
end_comment

begin_comment
comment|// CHECK: (i8* [[BUF:%.*]], i8* [[DATA:%.*]], i32 [[PRECISION:%.*]], i32 [[WIDTH:%.*]])
end_comment

begin_function
name|void
name|test_builtin_os_log_precision_width
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|int
name|precision
parameter_list|,
name|int
name|width
parameter_list|)
block|{
specifier|volatile
name|int
name|len
decl_stmt|;
comment|// CHECK: store i8* [[BUF]], i8** [[BUF_ADDR:%.*]], align 8
comment|// CHECK: store i8* [[DATA]], i8** [[DATA_ADDR:%.*]], align 8
comment|// CHECK: store i32 [[PRECISION]], i32* [[PRECISION_ADDR:%.*]], align 4
comment|// CHECK: store i32 [[WIDTH]], i32* [[WIDTH_ADDR:%.*]], align 4
comment|// CHECK: store volatile i32 24,
name|len
operator|=
name|__builtin_os_log_format_buffer_size
argument_list|(
literal|"Hello %*.*s World"
argument_list|,
name|precision
argument_list|,
name|width
argument_list|,
name|data
argument_list|)
expr_stmt|;
comment|// CHECK: [[BUF2:%.*]] = load i8*, i8** [[BUF_ADDR]]
comment|// CHECK: [[SUMMARY:%.*]] = getelementptr i8, i8* [[BUF2]], i64 0
comment|// CHECK: store i8 2, i8* [[SUMMARY]]
comment|// CHECK: [[NUM_ARGS:%.*]] = getelementptr i8, i8* [[BUF2]], i64 1
comment|// CHECK: store i8 3, i8* [[NUM_ARGS]]
comment|// CHECK: [[ARG1_DESC:%.*]] = getelementptr i8, i8* [[BUF2]], i64 2
comment|// CHECK: store i8 0, i8* [[ARG1_DESC]]
comment|// CHECK: [[ARG1_SIZE:%.*]] = getelementptr i8, i8* [[BUF2]], i64 3
comment|// CHECK: store i8 4, i8* [[ARG1_SIZE]]
comment|// CHECK: [[ARG1:%.*]] = getelementptr i8, i8* [[BUF2]], i64 4
comment|// CHECK: [[ARG1_INT:%.*]] = bitcast i8* [[ARG1]] to i32*
comment|// CHECK: [[ARG1_VAL:%.*]] = load i32, i32* [[PRECISION_ADDR]]
comment|// CHECK: store i32 [[ARG1_VAL]], i32* [[ARG1_INT]]
comment|// CHECK: [[ARG2_DESC:%.*]] = getelementptr i8, i8* [[BUF2]], i64 8
comment|// CHECK: store i8 16, i8* [[ARG2_DESC]]
comment|// CHECK: [[ARG2_SIZE:%.*]] = getelementptr i8, i8* [[BUF2]], i64 9
comment|// CHECK: store i8 4, i8* [[ARG2_SIZE]]
comment|// CHECK: [[ARG2:%.*]] = getelementptr i8, i8* [[BUF2]], i64 10
comment|// CHECK: [[ARG2_INT:%.*]] = bitcast i8* [[ARG2]] to i32*
comment|// CHECK: [[ARG2_VAL:%.*]] = load i32, i32* [[WIDTH_ADDR]]
comment|// CHECK: store i32 [[ARG2_VAL]], i32* [[ARG2_INT]]
comment|// CHECK: [[ARG3_DESC:%.*]] = getelementptr i8, i8* [[BUF2]], i64 14
comment|// CHECK: store i8 32, i8* [[ARG3_DESC]]
comment|// CHECK: [[ARG3_SIZE:%.*]] = getelementptr i8, i8* [[BUF2]], i64 15
comment|// CHECK: store i8 8, i8* [[ARG3_SIZE]]
comment|// CHECK: [[ARG3:%.*]] = getelementptr i8, i8* [[BUF2]], i64 16
comment|// CHECK: [[ARG3_PTR:%.*]] = bitcast i8* [[ARG3]] to i8**
comment|// CHECK: [[DATA2:%.*]] = load i8*, i8** [[DATA_ADDR]]
comment|// CHECK: store i8* [[DATA2]], i8** [[ARG3_PTR]]
name|__builtin_os_log_format
argument_list|(
name|buf
argument_list|,
literal|"Hello %*.*s World"
argument_list|,
name|precision
argument_list|,
name|width
argument_list|,
name|data
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_builtin_os_log_invalid
end_comment

begin_comment
comment|// CHECK: (i8* [[BUF:%.*]], i32 [[DATA:%.*]])
end_comment

begin_function
name|void
name|test_builtin_os_log_invalid
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|data
parameter_list|)
block|{
specifier|volatile
name|int
name|len
decl_stmt|;
comment|// CHECK: store i8* [[BUF]], i8** [[BUF_ADDR:%.*]], align 8
comment|// CHECK: store i32 [[DATA]], i32* [[DATA_ADDR:%.*]]
comment|// CHECK: store volatile i32 8,
name|len
operator|=
name|__builtin_os_log_format_buffer_size
argument_list|(
literal|"invalid specifier %: %d even a trailing one%"
argument_list|,
name|data
argument_list|)
expr_stmt|;
comment|// CHECK: [[BUF2:%.*]] = load i8*, i8** [[BUF_ADDR]]
comment|// CHECK: [[SUMMARY:%.*]] = getelementptr i8, i8* [[BUF2]], i64 0
comment|// CHECK: store i8 0, i8* [[SUMMARY]]
comment|// CHECK: [[NUM_ARGS:%.*]] = getelementptr i8, i8* [[BUF2]], i64 1
comment|// CHECK: store i8 1, i8* [[NUM_ARGS]]
comment|// CHECK: [[ARG1_DESC:%.*]] = getelementptr i8, i8* [[BUF2]], i64 2
comment|// CHECK: store i8 0, i8* [[ARG1_DESC]]
comment|// CHECK: [[ARG1_SIZE:%.*]] = getelementptr i8, i8* [[BUF2]], i64 3
comment|// CHECK: store i8 4, i8* [[ARG1_SIZE]]
comment|// CHECK: [[ARG1:%.*]] = getelementptr i8, i8* [[BUF2]], i64 4
comment|// CHECK: [[ARG1_INT:%.*]] = bitcast i8* [[ARG1]] to i32*
comment|// CHECK: [[ARG1_VAL:%.*]] = load i32, i32* [[DATA_ADDR]]
comment|// CHECK: store i32 [[ARG1_VAL]], i32* [[ARG1_INT]]
name|__builtin_os_log_format
argument_list|(
name|buf
argument_list|,
literal|"invalid specifier %: %d even a trailing one%"
argument_list|,
name|data
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_builtin_os_log_percent
end_comment

begin_comment
comment|// CHECK: (i8* [[BUF:%.*]], i8* [[DATA1:%.*]], i8* [[DATA2:%.*]])
end_comment

begin_comment
comment|// Check that the %% which does not consume any argument is correctly handled
end_comment

begin_function
name|void
name|test_builtin_os_log_percent
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
specifier|const
name|char
modifier|*
name|data1
parameter_list|,
specifier|const
name|char
modifier|*
name|data2
parameter_list|)
block|{
specifier|volatile
name|int
name|len
decl_stmt|;
comment|// CHECK: store i8* [[BUF]], i8** [[BUF_ADDR:%.*]], align 8
comment|// CHECK: store i8* [[DATA1]], i8** [[DATA1_ADDR:%.*]], align 8
comment|// CHECK: store i8* [[DATA2]], i8** [[DATA2_ADDR:%.*]], align 8
comment|// CHECK: store volatile i32 22
name|len
operator|=
name|__builtin_os_log_format_buffer_size
argument_list|(
literal|"%s %% %s"
argument_list|,
name|data1
argument_list|,
name|data2
argument_list|)
expr_stmt|;
comment|// CHECK: [[BUF2:%.*]] = load i8*, i8** [[BUF_ADDR]]
comment|// CHECK: [[SUMMARY:%.*]] = getelementptr i8, i8* [[BUF2]], i64 0
comment|// CHECK: store i8 2, i8* [[SUMMARY]]
comment|// CHECK: [[NUM_ARGS:%.*]] = getelementptr i8, i8* [[BUF2]], i64 1
comment|// CHECK: store i8 2, i8* [[NUM_ARGS]]
comment|//
comment|// CHECK: [[ARG1_DESC:%.*]] = getelementptr i8, i8* [[BUF2]], i64 2
comment|// CHECK: store i8 32, i8* [[ARG1_DESC]]
comment|// CHECK: [[ARG1_SIZE:%.*]] = getelementptr i8, i8* [[BUF2]], i64 3
comment|// CHECK: store i8 8, i8* [[ARG1_SIZE]]
comment|// CHECK: [[ARG1:%.*]] = getelementptr i8, i8* [[BUF2]], i64 4
comment|// CHECK: [[ARG1_PTR:%.*]] = bitcast i8* [[ARG1]] to i8**
comment|// CHECK: [[DATA1:%.*]] = load i8*, i8** [[DATA1_ADDR]]
comment|// CHECK: store i8* [[DATA1]], i8** [[ARG1_PTR]]
comment|//
comment|// CHECK: [[ARG2_DESC:%.*]] = getelementptr i8, i8* [[BUF2]], i64 12
comment|// CHECK: store i8 32, i8* [[ARG2_DESC]]
comment|// CHECK: [[ARG2_SIZE:%.*]] = getelementptr i8, i8* [[BUF2]], i64 13
comment|// CHECK: store i8 8, i8* [[ARG2_SIZE]]
comment|// CHECK: [[ARG2:%.*]] = getelementptr i8, i8* [[BUF2]], i64 14
comment|// CHECK: [[ARG2_PTR:%.*]] = bitcast i8* [[ARG2]] to i8**
comment|// CHECK: [[DATA2:%.*]] = load i8*, i8** [[DATA2_ADDR]]
comment|// CHECK: store i8* [[DATA2]], i8** [[ARG2_PTR]]
name|__builtin_os_log_format
argument_list|(
name|buf
argument_list|,
literal|"%s %% %s"
argument_list|,
name|data1
argument_list|,
name|data2
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

