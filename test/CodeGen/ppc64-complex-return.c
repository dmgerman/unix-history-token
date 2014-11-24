begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-unknown-linux-gnu -emit-llvm -o - %s | FileCheck %s
end_comment

begin_function_decl
name|float
name|crealf
parameter_list|(
specifier|_Complex
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|creal
parameter_list|(
specifier|_Complex
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|creall
parameter_list|(
specifier|_Complex
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|_Complex
name|float
name|foo_float
parameter_list|(
specifier|_Complex
name|float
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define { float, float } @foo_float(float {{[%A-Za-z0-9.]+}}, float {{[%A-Za-z0-9.]+}}) [[NUW:#[0-9]+]] {
end_comment

begin_function
specifier|_Complex
name|double
name|foo_double
parameter_list|(
specifier|_Complex
name|double
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define { double, double } @foo_double(double {{[%A-Za-z0-9.]+}}, double {{[%A-Za-z0-9.]+}}) [[NUW]] {
end_comment

begin_function
specifier|_Complex
name|long
name|double
name|foo_long_double
parameter_list|(
specifier|_Complex
name|long
name|double
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define { ppc_fp128, ppc_fp128 } @foo_long_double(ppc_fp128 {{[%A-Za-z0-9.]+}}, ppc_fp128 {{[%A-Za-z0-9.]+}}) [[NUW]] {
end_comment

begin_function
specifier|_Complex
name|int
name|foo_int
parameter_list|(
specifier|_Complex
name|int
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define { i32, i32 } @foo_int(i32 {{[%A-Za-z0-9.]+}}, i32 {{[%A-Za-z0-9.]+}}) [[NUW]] {
end_comment

begin_function
specifier|_Complex
name|short
name|foo_short
parameter_list|(
specifier|_Complex
name|short
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define { i16, i16 } @foo_short(i16 {{[%A-Za-z0-9.]+}}, i16 {{[%A-Za-z0-9.]+}}) [[NUW]] {
end_comment

begin_function
specifier|_Complex
name|signed
name|char
name|foo_char
parameter_list|(
specifier|_Complex
name|signed
name|char
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define { i8, i8 } @foo_char(i8 {{[%A-Za-z0-9.]+}}, i8 {{[%A-Za-z0-9.]+}}) [[NUW]] {
end_comment

begin_function
specifier|_Complex
name|long
name|foo_long
parameter_list|(
specifier|_Complex
name|long
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define { i64, i64 } @foo_long(i64 {{[%A-Za-z0-9.]+}}, i64 {{[%A-Za-z0-9.]+}}) [[NUW]] {
end_comment

begin_function
specifier|_Complex
name|long
name|long
name|foo_long_long
parameter_list|(
specifier|_Complex
name|long
name|long
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define { i64, i64 } @foo_long_long(i64 {{[%A-Za-z0-9.]+}}, i64 {{[%A-Za-z0-9.]+}}) [[NUW]] {
end_comment

begin_function
name|float
name|bar_float
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|crealf
argument_list|(
name|foo_float
argument_list|(
literal|2.0f
operator|-
literal|2.5fi
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define float @bar_float() [[NUW]] {
end_comment

begin_comment
comment|// CHECK: [[VAR1:[%A-Za-z0-9.]+]] = call { float, float } @foo_float
end_comment

begin_comment
comment|// CHECK: extractvalue { float, float } [[VAR1]], 0
end_comment

begin_comment
comment|// CHECK: extractvalue { float, float } [[VAR1]], 1
end_comment

begin_function
name|double
name|bar_double
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|creal
argument_list|(
name|foo_double
argument_list|(
literal|2.0 - 2.5i
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define double @bar_double() [[NUW]] {
end_comment

begin_comment
comment|// CHECK: [[VAR2:[%A-Za-z0-9.]+]] = call { double, double } @foo_double
end_comment

begin_comment
comment|// CHECK: extractvalue { double, double } [[VAR2]], 0
end_comment

begin_comment
comment|// CHECK: extractvalue { double, double } [[VAR2]], 1
end_comment

begin_function
name|long
name|double
name|bar_long_double
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|creall
argument_list|(
name|foo_long_double
argument_list|(
literal|2.0L
operator|-
literal|2.5Li
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define ppc_fp128 @bar_long_double() [[NUW]] {
end_comment

begin_comment
comment|// CHECK: [[VAR3:[%A-Za-z0-9.]+]] = call { ppc_fp128, ppc_fp128 } @foo_long_double
end_comment

begin_comment
comment|// CHECK: extractvalue { ppc_fp128, ppc_fp128 } [[VAR3]], 0
end_comment

begin_comment
comment|// CHECK: extractvalue { ppc_fp128, ppc_fp128 } [[VAR3]], 1
end_comment

begin_function
name|int
name|bar_int
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|__real__
argument_list|(
name|foo_int
argument_list|(
literal|2 - 3i
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define signext i32 @bar_int() [[NUW]] {
end_comment

begin_comment
comment|// CHECK: [[VAR4:[%A-Za-z0-9.]+]] = call { i32, i32 } @foo_int
end_comment

begin_comment
comment|// CHECK: extractvalue { i32, i32 } [[VAR4]], 0
end_comment

begin_comment
comment|// CHECK: extractvalue { i32, i32 } [[VAR4]], 1
end_comment

begin_function
name|short
name|bar_short
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|__real__
argument_list|(
name|foo_short
argument_list|(
literal|2 - 3i
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define signext i16 @bar_short() [[NUW]] {
end_comment

begin_comment
comment|// CHECK: [[VAR5:[%A-Za-z0-9.]+]] = call { i16, i16 } @foo_short
end_comment

begin_comment
comment|// CHECK: extractvalue { i16, i16 } [[VAR5]], 0
end_comment

begin_comment
comment|// CHECK: extractvalue { i16, i16 } [[VAR5]], 1
end_comment

begin_function
name|signed
name|char
name|bar_char
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|__real__
argument_list|(
name|foo_char
argument_list|(
literal|2 - 3i
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define signext i8 @bar_char() [[NUW]] {
end_comment

begin_comment
comment|// CHECK: [[VAR6:[%A-Za-z0-9.]+]] = call { i8, i8 } @foo_char
end_comment

begin_comment
comment|// CHECK: extractvalue { i8, i8 } [[VAR6]], 0
end_comment

begin_comment
comment|// CHECK: extractvalue { i8, i8 } [[VAR6]], 1
end_comment

begin_function
name|long
name|bar_long
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|__real__
argument_list|(
name|foo_long
argument_list|(
literal|2L
operator|-
literal|3Li
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define i64 @bar_long() [[NUW]] {
end_comment

begin_comment
comment|// CHECK: [[VAR7:[%A-Za-z0-9.]+]] = call { i64, i64 } @foo_long
end_comment

begin_comment
comment|// CHECK: extractvalue { i64, i64 } [[VAR7]], 0
end_comment

begin_comment
comment|// CHECK: extractvalue { i64, i64 } [[VAR7]], 1
end_comment

begin_function
name|long
name|long
name|bar_long_long
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|__real__
argument_list|(
name|foo_long_long
argument_list|(
literal|2LL
operator|-
literal|3LLi
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define i64 @bar_long_long() [[NUW]] {
end_comment

begin_comment
comment|// CHECK: [[VAR8:[%A-Za-z0-9.]+]] = call { i64, i64 } @foo_long_long
end_comment

begin_comment
comment|// CHECK: extractvalue { i64, i64 } [[VAR8]], 0
end_comment

begin_comment
comment|// CHECK: extractvalue { i64, i64 } [[VAR8]], 1
end_comment

begin_comment
comment|// CHECK: attributes [[NUW]] = { nounwind{{.*}} }
end_comment

end_unit

