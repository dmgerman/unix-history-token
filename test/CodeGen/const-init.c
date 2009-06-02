begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple i386-pc-linux-gnu -verify -emit-llvm -o %t %s&&
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
comment|// RUN: grep '@g1x = global %. { double 1.000000e+00, double 0.000000e+00 }' %t&&
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
comment|// RUN: grep '@g1y = global %. { double 0.000000e+00, double 1.000000e+00 }' %t&&
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
comment|// RUN: grep '@g1 = global %. { i8 1, i8 10 }' %t&&
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
comment|// RUN: grep '@g2 = global %2 { i32 1, i32 10 }' %t&&
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
comment|// RUN: grep '@g3 = global %. { float 1.000000e+00, float 1.000000e+01 }' %t&&
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
comment|// RUN: grep '@g4 = global %. { double 1.000000e+00, double 1.000000e+01 }' %t&&
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
comment|// RUN: grep '@g5 = global %2 zeroinitializer' %t&&
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
comment|// RUN: grep '@g6 = global %. { double -1.100000e+01, double 2.900000e+01 }' %t&&
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
comment|// RUN: grep '@g7 = global i32 1' %t&&
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
comment|// RUN: grep '@g8 = global i32 1' %t&&
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
comment|// RUN: grep '@g9 = global i32 0' %t&&
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
comment|// RUN: grep '@g10 = global i32 0' %t&&
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
comment|// Global references
end_comment

begin_comment
comment|// RUN: grep '@g11.l0 = internal global i32 ptrtoint (i32 ()\* @g11 to i32)' %t&&
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
comment|// RUN: grep '@g12 = global i32 ptrtoint (i8\* @g12_tmp to i32)' %t&&
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
comment|// RUN: grep '@g13 = global \[1 x .struct.g13_s0\] \[.struct.g13_s0<{ i32 ptrtoint (i8\* @g12_tmp to i32) }>\]' %t&&
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
comment|// RUN: grep '@g14 = global i8\* inttoptr (i64 100 to i8\*)' %t&&
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
comment|// RUN: grep '@g15 = global i32 -1' %t&&
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
comment|// RUN: grep '@g16 = global i64 4294967295' %t&&
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
comment|// RUN: grep '@g17 = global i32\* @g15' %t&&
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
comment|// RUN: grep '@g18.p = internal global \[1 x i32\*\] \[i32\* @g19\]' %t&&
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
comment|// RUN: grep '@g20.l0 = internal global .struct.g20_s1<{ .struct.g20_s0\* null, .struct.g20_s0\*\* getelementptr (.struct.g20_s1\* @g20.l0, i32 0, i32 0) }>'  %t&&
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
comment|// RUN: true
end_comment

end_unit

