begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target mips64el-unknown-linux -ccc-clang-archs mips64el -O3 -S -mabi=n64 -o - -emit-llvm %s | FileCheck %s
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|double
name|d
decl_stmt|;
name|long
name|double
name|ld
decl_stmt|;
block|}
name|S0
typedef|;
end_typedef

begin_comment
comment|// Insert padding to ensure arguments of type S0 are aligned to 16-byte boundaries.
end_comment

begin_comment
comment|// CHECK: define void @foo1(i32 %a0, i64, double %a1.coerce0, i64 %a1.coerce1, i64 %a1.coerce2, i64 %a1.coerce3, double %a2.coerce0, i64 %a2.coerce1, i64 %a2.coerce2, i64 %a2.coerce3, i32 %b, i64, double %a3.coerce0, i64 %a3.coerce1, i64 %a3.coerce2, i64 %a3.coerce3)
end_comment

begin_comment
comment|// CHECK: tail call void @foo2(i32 1, i32 2, i32 %a0, i64 undef, double %a1.coerce0, i64 %a1.coerce1, i64 %a1.coerce2, i64 %a1.coerce3, double %a2.coerce0, i64 %a2.coerce1, i64 %a2.coerce2, i64 %a2.coerce3, i32 3, i64 undef, double %a3.coerce0, i64 %a3.coerce1, i64 %a3.coerce2, i64 %a3.coerce3)
end_comment

begin_comment
comment|// CHECK: declare void @foo2(i32, i32, i32, i64, double, i64, i64, i64, double, i64, i64, i64, i32, i64, double, i64, i64, i64)
end_comment

begin_function_decl
specifier|extern
name|void
name|foo2
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|S0
parameter_list|,
name|S0
parameter_list|,
name|int
parameter_list|,
name|S0
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|foo1
parameter_list|(
name|int
name|a0
parameter_list|,
name|S0
name|a1
parameter_list|,
name|S0
name|a2
parameter_list|,
name|int
name|b
parameter_list|,
name|S0
name|a3
parameter_list|)
block|{
name|foo2
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
name|a0
argument_list|,
name|a1
argument_list|,
name|a2
argument_list|,
literal|3
argument_list|,
name|a3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Insert padding before long double argument.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: define void @foo3(i32 %a0, i64, fp128 %a1)
end_comment

begin_comment
comment|// CHECK: tail call void @foo4(i32 1, i32 2, i32 %a0, i64 undef, fp128 %a1)
end_comment

begin_comment
comment|// CHECK: declare void @foo4(i32, i32, i32, i64, fp128)
end_comment

begin_function_decl
specifier|extern
name|void
name|foo4
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|foo3
parameter_list|(
name|int
name|a0
parameter_list|,
name|long
name|double
name|a1
parameter_list|)
block|{
name|foo4
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
name|a0
argument_list|,
name|a1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Insert padding after hidden argument.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: define void @foo5(%struct.S0* noalias sret %agg.result, i64, fp128 %a0)
end_comment

begin_comment
comment|// CHECK: call void @foo6(%struct.S0* sret %agg.result, i32 1, i32 2, i64 undef, fp128 %a0)
end_comment

begin_comment
comment|// CHECK: declare void @foo6(%struct.S0* sret, i32, i32, i64, fp128)
end_comment

begin_function_decl
specifier|extern
name|S0
name|foo6
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|S0
name|foo5
parameter_list|(
name|long
name|double
name|a0
parameter_list|)
block|{
return|return
name|foo6
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
name|a0
argument_list|)
return|;
block|}
end_function

end_unit

