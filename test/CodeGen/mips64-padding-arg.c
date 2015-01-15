begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target mipsel-unknown-linux -O3 -S -o - -emit-llvm %s | FileCheck %s -check-prefix=O32
end_comment

begin_comment
comment|// RUN: %clang -target mips64el-unknown-linux -O3 -S -mabi=n64 -o - -emit-llvm %s | FileCheck %s -check-prefix=N64
end_comment

begin_comment
comment|// RUN: %clang -target mipsel-unknown-linux -mfp64 -O3 -S -o - -emit-llvm %s | FileCheck %s -check-prefix=O32
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
comment|// N64-LABEL: define void @foo1(i32 signext %a0, i64, double inreg %a1.coerce0, i64 inreg %a1.coerce1, i64 inreg %a1.coerce2, i64 inreg %a1.coerce3, double inreg %a2.coerce0, i64 inreg %a2.coerce1, i64 inreg %a2.coerce2, i64 inreg %a2.coerce3, i32 signext %b, i64, double inreg %a3.coerce0, i64 inreg %a3.coerce1, i64 inreg %a3.coerce2, i64 inreg %a3.coerce3)
end_comment

begin_comment
comment|// N64: tail call void @foo2(i32 signext 1, i32 signext 2, i32 signext %a0, i64 undef, double inreg %a1.coerce0, i64 inreg %a1.coerce1, i64 inreg %a1.coerce2, i64 inreg %a1.coerce3, double inreg %a2.coerce0, i64 inreg %a2.coerce1, i64 inreg %a2.coerce2, i64 inreg %a2.coerce3, i32 signext 3, i64 undef, double inreg %a3.coerce0, i64 inreg %a3.coerce1, i64 inreg %a3.coerce2, i64 inreg %a3.coerce3)
end_comment

begin_comment
comment|// N64: declare void @foo2(i32 signext, i32 signext, i32 signext, i64, double inreg, i64 inreg, i64 inreg, i64 inreg, double inreg, i64 inreg, i64 inreg, i64 inreg, i32 signext, i64, double inreg, i64 inreg, i64 inreg, i64 inreg)
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
comment|// N64-LABEL: define void @foo3(i32 signext %a0, i64, fp128 %a1)
end_comment

begin_comment
comment|// N64: tail call void @foo4(i32 signext 1, i32 signext 2, i32 signext %a0, i64 undef, fp128 %a1)
end_comment

begin_comment
comment|// N64: declare void @foo4(i32 signext, i32 signext, i32 signext, i64, fp128)
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
comment|// N64-LABEL: define void @foo5(%struct.S0* noalias sret %agg.result, i64, fp128 %a0)
end_comment

begin_comment
comment|// N64: call void @foo6(%struct.S0* sret %agg.result, i32 signext 1, i32 signext 2, i64 undef, fp128 %a0)
end_comment

begin_comment
comment|// N64: declare void @foo6(%struct.S0* sret, i32 signext, i32 signext, i64, fp128)
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

begin_comment
comment|// Do not insert padding if ABI is O32.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// O32-LABEL: define void @foo7(float %a0, double %a1)
end_comment

begin_comment
comment|// O32: declare void @foo8(float, double)
end_comment

begin_function_decl
specifier|extern
name|void
name|foo8
parameter_list|(
name|float
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|foo7
parameter_list|(
name|float
name|a0
parameter_list|,
name|double
name|a1
parameter_list|)
block|{
name|foo8
argument_list|(
name|a0
operator|+
literal|1.0f
argument_list|,
name|a1
operator|+
literal|2.0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// O32-LABEL: define void @foo9()
end_comment

begin_comment
comment|// O32: declare void @foo10(i32 signext, i32
end_comment

begin_typedef
typedef|typedef
name|struct
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
block|{
name|int
name|a
block|; }
end_typedef

begin_expr_stmt
name|S16
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|S16
name|s16
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|foo10
parameter_list|(
name|int
parameter_list|,
name|S16
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|foo9
parameter_list|(
name|void
parameter_list|)
block|{
name|foo10
argument_list|(
literal|1
argument_list|,
name|s16
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

