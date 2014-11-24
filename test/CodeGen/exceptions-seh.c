begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -triple i686-pc-win32 -fexceptions -fms-extensions -emit-llvm -o - %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// This is a codegen test because we only emit the diagnostic when we start
end_comment

begin_comment
comment|// generating code.
end_comment

begin_function
name|int
name|SaveDiv
parameter_list|(
name|int
name|numerator
parameter_list|,
name|int
name|denominator
parameter_list|,
name|int
modifier|*
name|res
parameter_list|)
block|{
name|int
name|myres
init|=
literal|0
decl_stmt|;
name|__try
block|{
name|myres
operator|=
name|numerator
operator|/
name|denominator
expr_stmt|;
name|__leave
expr_stmt|;
block|}
name|__except
argument_list|(
literal|1
argument_list|)
block|{
return|return
literal|0
return|;
block|}
operator|*
name|res
operator|=
name|myres
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|// CHECK-NOT: error:
end_comment

begin_comment
comment|// CHECK: error: cannot compile this SEH __try yet
end_comment

begin_comment
comment|// CHECK-NOT: error:
end_comment

end_unit

