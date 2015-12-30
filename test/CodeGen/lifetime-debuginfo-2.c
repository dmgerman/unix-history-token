begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -O1 -triple x86_64-none-linux-gnu -emit-llvm -debug-info-kind=line-tables-only %s -o - | FileCheck %s
end_comment

begin_comment
comment|// Inserting lifetime markers should not affect debuginfo: lifetime.end is not
end_comment

begin_comment
comment|// a destructor, but instrumentation for the compiler. Ensure the debug info for
end_comment

begin_comment
comment|// the return statement (in the IR) does not point to the function closing '}'
end_comment

begin_comment
comment|// which is used to show some destructors have been called before leaving the
end_comment

begin_comment
comment|// function.
end_comment

begin_function_decl
specifier|extern
name|int
name|f
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|g
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK-LABEL: define i32 @test
end_comment

begin_function
name|int
name|test
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
name|int
name|res
decl_stmt|;
if|if
condition|(
name|a
operator|==
literal|2
condition|)
block|{
name|int
name|r
init|=
name|f
argument_list|(
name|b
argument_list|)
decl_stmt|;
name|res
operator|=
name|r
operator|+
name|b
expr_stmt|;
name|a
operator|+=
literal|2
expr_stmt|;
block|}
else|else
block|{
name|int
name|r
init|=
name|f
argument_list|(
name|a
argument_list|)
decl_stmt|;
name|res
operator|=
name|r
operator|+
name|a
expr_stmt|;
name|b
operator|+=
literal|1
expr_stmt|;
block|}
return|return
name|res
return|;
comment|// CHECK: ret i32 %{{.*}}, !dbg [[DI:![0-9]+]]
comment|// CHECK: [[DI]] = !DILocation(line: [[@LINE-2]]
block|}
end_function

end_unit

