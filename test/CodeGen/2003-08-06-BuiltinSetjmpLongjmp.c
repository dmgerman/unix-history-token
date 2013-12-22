begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: %clang_cc1  %s -emit-llvm -o - | FileCheck %s  *  * __builtin_longjmp/setjmp should get transformed into intrinsics.  */
end_comment

begin_comment
comment|// CHECK-NOT: builtin_longjmp
end_comment

begin_function
name|void
name|jumpaway
parameter_list|(
name|int
modifier|*
name|ptr
parameter_list|)
block|{
name|__builtin_longjmp
argument_list|(
name|ptr
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|__builtin_setjmp
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|jumpaway
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

