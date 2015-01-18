begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-linux-gnu -ffreestanding -verify -emit-llvm -o - %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// Brace-enclosed string array initializers
end_comment

begin_decl_stmt
name|char
name|a
index|[]
init|=
block|{
literal|"asdf"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @a = global [5 x i8] c"asdf\00"
end_comment

begin_decl_stmt
name|char
name|a2
index|[
literal|2
index|]
index|[
literal|5
index|]
init|=
block|{
literal|"asdf"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @a2 = global [2 x [5 x i8]] {{\[}}[5 x i8] c"asdf\00", [5 x i8] zeroinitializer]
end_comment

begin_comment
comment|// Double-implicit-conversions of array/functions (not legal C, but
end_comment

begin_comment
comment|// clang accepts it for gcc compat).
end_comment

begin_decl_stmt
name|intptr_t
name|b
init|=
name|a
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{incompatible pointer to integer conversion}}
end_comment

begin_function_decl
name|int
name|c
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|void
modifier|*
name|d
init|=
name|c
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|intptr_t
name|e
init|=
name|c
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{incompatible pointer to integer conversion}}
end_comment

begin_decl_stmt
name|int
name|f
decl_stmt|,
modifier|*
name|g
init|=
name|__extension__
operator|&
name|f
decl_stmt|,
modifier|*
name|h
init|=
operator|(
literal|1
operator|!=
literal|1
operator|)
condition|?
operator|&
name|f
else|:
operator|&
name|f
decl_stmt|;
end_decl_stmt

begin_union
union|union
name|s2
block|{
struct|struct
block|{
struct|struct
block|{ }
modifier|*
name|f0
struct|;
block|}
name|f0
struct|;
block|}
union|;
end_union

begin_decl_stmt
name|int
name|g0
init|=
call|(
name|int
call|)
argument_list|(
operator|&
operator|(
operator|(
operator|(
expr|union
name|s2
operator|*
operator|)
literal|0
operator|)
operator|->
name|f0
operator|.
name|f0
operator|)
operator|-
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @g1x = global { double, double } { double 1.000000e+00{{[0]*}}, double 0.000000e+00{{[0]*}} }
end_comment

begin_decl_stmt
specifier|_Complex
name|double
name|g1x
init|=
literal|1.0f
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @g1y = global { double, double } { double 0.000000e+00{{[0]*}}, double 1.000000e+00{{[0]*}} }
end_comment

begin_decl_stmt
specifier|_Complex
name|double
name|g1y
init|=
literal|1.0fi
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @g1 = global { i8, i8 } { i8 1, i8 10 }
end_comment

begin_decl_stmt
specifier|_Complex
name|char
name|g1
init|=
operator|(
name|char
operator|)
literal|1
operator|+
operator|(
name|char
operator|)
literal|10
operator|*
literal|1i
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @g2 = global { i32, i32 } { i32 1, i32 10 }
end_comment

begin_decl_stmt
specifier|_Complex
name|int
name|g2
init|=
literal|1 + 10i
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @g3 = global { float, float } { float 1.000000e+00{{[0]*}}, float 1.000000e+0{{[0]*}}1 }
end_comment

begin_decl_stmt
specifier|_Complex
name|float
name|g3
init|=
literal|1.0 + 10.0i
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @g4 = global { double, double } { double 1.000000e+00{{[0]*}}, double 1.000000e+0{{[0]*}}1 }
end_comment

begin_decl_stmt
specifier|_Complex
name|double
name|g4
init|=
literal|1.0 + 10.0i
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @g5 = global { i32, i32 } zeroinitializer
end_comment

begin_decl_stmt
specifier|_Complex
name|int
name|g5
init|=
operator|(
literal|2 + 3i
operator|)
operator|==
operator|(
literal|5 + 7i
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @g6 = global { double, double } { double -1.100000e+0{{[0]*}}1, double 2.900000e+0{{[0]*}}1 }
end_comment

begin_decl_stmt
specifier|_Complex
name|double
name|g6
init|=
operator|(
literal|2.0 + 3.0i
operator|)
operator|*
operator|(
literal|5.0 + 7.0i
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @g7 = global i32 1
end_comment

begin_decl_stmt
name|int
name|g7
init|=
operator|(
literal|2 + 3i
operator|)
operator|*
operator|(
literal|5 + 7i
operator|)
operator|==
operator|(
operator|-
literal|11 + 29i
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @g8 = global i32 1
end_comment

begin_decl_stmt
name|int
name|g8
init|=
operator|(
literal|2.0 + 3.0i
operator|)
operator|*
operator|(
literal|5.0 + 7.0i
operator|)
operator|==
operator|(
operator|-
literal|11.0 + 29.0i
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @g9 = global i32 0
end_comment

begin_decl_stmt
name|int
name|g9
init|=
operator|(
literal|2 + 3i
operator|)
operator|*
operator|(
literal|5 + 7i
operator|)
operator|!=
operator|(
operator|-
literal|11 + 29i
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @g10 = global i32 0
end_comment

begin_decl_stmt
name|int
name|g10
init|=
operator|(
literal|2.0 + 3.0i
operator|)
operator|*
operator|(
literal|5.0 + 7.0i
operator|)
operator|!=
operator|(
operator|-
literal|11.0 + 29.0i
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PR5108
end_comment

begin_comment
comment|// CHECK: @gv1 = global %struct.anon<{ i32 0, i8 7 }>, align 1
end_comment

begin_struct
struct|struct
block|{
name|unsigned
name|long
name|a
decl_stmt|;
name|unsigned
name|long
name|b
range|:
literal|3
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
name|gv1
init|=
block|{
operator|.
name|a
operator|=
literal|0x0
block|,
operator|.
name|b
operator|=
literal|7
block|,  }
struct|;
end_struct

begin_comment
comment|// PR5118
end_comment

begin_comment
comment|// CHECK: @gv2 = global %struct.anon.0<{ i8 1, i8* null }>, align 1
end_comment

begin_struct
struct|struct
block|{
name|unsigned
name|char
name|a
decl_stmt|;
name|char
modifier|*
name|b
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
name|gv2
init|=
block|{
literal|1
block|,
operator|(
name|void
operator|*
operator|)
literal|0
block|}
struct|;
end_struct

begin_comment
comment|// Global references
end_comment

begin_comment
comment|// CHECK: @g11.l0 = internal global i32 ptrtoint (i32 ()* @g11 to i32)
end_comment

begin_function
name|long
name|g11
parameter_list|()
block|{
specifier|static
name|long
name|l0
init|=
operator|(
name|long
operator|)
name|g11
decl_stmt|;
return|return
name|l0
return|;
block|}
end_function

begin_comment
comment|// CHECK: @g12 = global i32 ptrtoint (i8* @g12_tmp to i32)
end_comment

begin_decl_stmt
specifier|static
name|char
name|g12_tmp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|g12
init|=
operator|(
name|long
operator|)
operator|&
name|g12_tmp
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @g13 = global [1 x %struct.g13_s0] [%struct.g13_s0 { i32 ptrtoint (i8* @g12_tmp to i32) }]
end_comment

begin_struct
struct|struct
name|g13_s0
block|{
name|long
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|g13_s0
name|g13
index|[]
init|=
block|{
block|{
operator|(
name|long
operator|)
operator|&
name|g12_tmp
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @g14 = global i8* inttoptr (i64 100 to i8*)
end_comment

begin_decl_stmt
name|void
modifier|*
name|g14
init|=
operator|(
name|void
operator|*
operator|)
literal|100
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @g15 = global i32 -1
end_comment

begin_decl_stmt
name|int
name|g15
init|=
call|(
name|int
call|)
argument_list|(
name|char
argument_list|)
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0
operator|+
literal|255
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @g16 = global i64 4294967295
end_comment

begin_decl_stmt
name|long
name|long
name|g16
init|=
call|(
name|long
name|long
call|)
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0xFFFFFFFF
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @g17 = global i32* @g15
end_comment

begin_decl_stmt
name|int
modifier|*
name|g17
init|=
operator|(
name|int
operator|*
operator|)
operator|(
operator|(
name|long
operator|)
operator|&
name|g15
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @g18.p = internal global [1 x i32*] [i32* @g19]
end_comment

begin_function
name|void
name|g18
parameter_list|(
name|void
parameter_list|)
block|{
specifier|extern
name|int
name|g19
decl_stmt|;
specifier|static
name|int
modifier|*
name|p
index|[]
init|=
block|{
operator|&
name|g19
block|}
decl_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: @g20.l0 = internal global %struct.g20_s1 { %struct.g20_s0* null, %struct.g20_s0** getelementptr inbounds (%struct.g20_s1* @g20.l0, i32 0, i32 0) }
end_comment

begin_struct_decl
struct_decl|struct
name|g20_s0
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|g20_s1
block|{
name|struct
name|g20_s0
modifier|*
name|f0
decl_stmt|,
modifier|*
modifier|*
name|f1
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
modifier|*
name|g20
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
name|struct
name|g20_s1
name|l0
init|=
block|{
operator|(
operator|(
name|void
operator|*
operator|)
literal|0
operator|)
block|,
operator|&
name|l0
operator|.
name|f0
block|}
decl_stmt|;
return|return
name|l0
operator|.
name|f1
return|;
block|}
end_function

begin_comment
comment|// PR4108
end_comment

begin_struct
struct|struct
name|g21
block|{
name|int
name|g21
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|const
name|struct
name|g21
name|g21
init|=
operator|(
expr|struct
name|g21
operator|)
block|{
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PR5474
end_comment

begin_struct
struct|struct
name|g22
block|{
name|int
name|x
decl_stmt|;
block|}
name|__attribute
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|g23
block|{
name|char
name|a
decl_stmt|;
name|short
name|b
decl_stmt|;
name|char
name|c
decl_stmt|;
name|struct
name|g22
name|d
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|g23
name|g24
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @g25.g26 = internal global i8* getelementptr inbounds ([4 x i8]* @__func__.g25, i32 0, i32 0)
end_comment

begin_comment
comment|// CHECK: @__func__.g25 = private unnamed_addr constant [4 x i8] c"g25\00"
end_comment

begin_function
name|int
name|g25
parameter_list|()
block|{
specifier|static
specifier|const
name|char
modifier|*
name|g26
init|=
name|__func__
decl_stmt|;
return|return
operator|*
name|g26
return|;
block|}
end_function

begin_comment
comment|// CHECK: @g27.x = internal global i8* bitcast (i8** @g27.x to i8*), align 4
end_comment

begin_function
name|void
name|g27
parameter_list|()
block|{
comment|// PR8073
specifier|static
name|void
modifier|*
name|x
init|=
operator|&
name|x
decl_stmt|;
block|}
end_function

begin_function
name|void
name|g28
parameter_list|()
block|{
typedef|typedef
name|long
name|long
name|v1i64
name|__attribute
typedef|((
name|vector_size
typedef|(8)));
typedef|typedef
name|short
name|v12i16
name|__attribute
typedef|((
name|vector_size
typedef|(24)));
typedef|typedef
name|long
name|double
name|v2f80
name|__attribute
typedef|((
name|vector_size
typedef|(24)));
comment|// CHECK: @g28.a = internal global<1 x i64><i64 10>
comment|// CHECK: @g28.b = internal global<12 x i16><i16 0, i16 0, i16 0, i16 -32768, i16 16383, i16 0, i16 0, i16 0, i16 0, i16 -32768, i16 16384, i16 0>
comment|// CHECK: @g28.c = internal global<2 x x86_fp80><x86_fp80 0xK3FFF8000000000000000, x86_fp80 0xK40008000000000000000>, align 32
specifier|static
name|v1i64
name|a
init|=
operator|(
name|v1i64
operator|)
literal|10LL
decl_stmt|;
specifier|static
name|v12i16
name|b
init|=
operator|(
name|v2f80
operator|)
block|{
literal|1
block|,
literal|2
block|}
decl_stmt|;
specifier|static
name|v2f80
name|c
init|=
operator|(
name|v12i16
operator|)
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
operator|-
literal|32768
block|,
literal|16383
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
operator|-
literal|32768
block|,
literal|16384
block|,
literal|0
block|}
decl_stmt|;
block|}
end_function

begin_comment
comment|// PR13643
end_comment

begin_function
name|void
name|g29
parameter_list|()
block|{
typedef|typedef
name|char
name|DCC_PASSWD
index|[
literal|2
index|]
typedef|;
typedef|typedef
struct|struct
block|{
name|DCC_PASSWD
name|passwd
decl_stmt|;
block|}
name|DCC_SRVR_NM
typedef|;
comment|// CHECK: @g29.a = internal global %struct.DCC_SRVR_NM { [2 x i8] c"@\00" }, align 1
comment|// CHECK: @g29.b = internal global [1 x i32] [i32 ptrtoint ([5 x i8]* @.str to i32)], align 4
comment|// CHECK: @g29.c = internal global [1 x i32] [i32 97], align 4
specifier|static
name|DCC_SRVR_NM
name|a
init|=
block|{
block|{
literal|"@"
block|}
block|}
decl_stmt|;
specifier|static
name|int
name|b
index|[
literal|1
index|]
init|=
block|{
literal|"asdf"
block|}
decl_stmt|;
comment|// expected-warning {{incompatible pointer to integer conversion initializing 'int' with an expression of type 'char [5]'}}
specifier|static
name|int
name|c
index|[
literal|1
index|]
init|=
block|{
literal|L"a"
block|}
decl_stmt|;
block|}
end_function

begin_comment
comment|// PR21300
end_comment

begin_function
name|void
name|g30
parameter_list|()
block|{
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
specifier|static
struct|struct
block|{
name|int
label|:
literal|1
expr_stmt|;
name|int
name|x
decl_stmt|;
block|}
name|a
init|=
block|{}
struct|;
comment|// CHECK: @g30.a = internal global %struct.anon.1<{ i8 undef, i32 0 }>, align 1
pragma|#
directive|pragma
name|pack
name|(
name|)
block|}
end_function

begin_function
name|void
name|g31
parameter_list|()
block|{
pragma|#
directive|pragma
name|pack
name|(
name|4
name|)
specifier|static
struct|struct
block|{
name|short
name|a
decl_stmt|;
name|long
name|x
decl_stmt|;
name|short
name|z
decl_stmt|;
block|}
name|a
init|=
block|{
literal|23122
block|,
operator|-
literal|12312731
block|,
operator|-
literal|312
block|}
struct|;
pragma|#
directive|pragma
name|pack
name|(
name|)
comment|// CHECK: @g31.a = internal global %struct.anon.2 { i16 23122, i32 -12312731, i16 -312 }, align 4
block|}
end_function

end_unit

