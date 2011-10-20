begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm -target-abi aapcs %s -emit-llvm -o - | FileCheck -check-prefix=AAPCS %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm -target-abi apcs-gnu %s -emit-llvm -o - | FileCheck -check-prefix=APCS-GNU %s
end_comment

begin_comment
comment|/*   * Check that va_arg accesses stack according to ABI alignment  * long long and double require 8-byte alignment under AAPCS  * however, they only require 4-byte alignment under APCS  */
end_comment

begin_function
name|long
name|long
name|t1
parameter_list|(
name|int
name|i
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|// AAPCS: t1
comment|// APCS-GNU: t1
name|__builtin_va_list
name|ap
decl_stmt|;
name|__builtin_va_start
argument_list|(
name|ap
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// AAPCS: add i32 %{{.*}} 7
comment|// AAPCS: and i32 %{{.*}} -8
comment|// APCS-GNU-NOT: add i32 %{{.*}} 7
comment|// APCS-GNU-NOT: and i32 %{{.*}} -8
name|long
name|long
name|ll
init|=
name|__builtin_va_arg
argument_list|(
argument|ap
argument_list|,
argument|long long
argument_list|)
decl_stmt|;
name|__builtin_va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|ll
return|;
block|}
end_function

begin_function
name|double
name|t2
parameter_list|(
name|int
name|i
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|// AAPCS: t2
comment|// APCS-GNU: t2
name|__builtin_va_list
name|ap
decl_stmt|;
name|__builtin_va_start
argument_list|(
name|ap
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// AAPCS: add i32 %{{.*}} 7
comment|// AAPCS: and i32 %{{.*}} -8
comment|// APCS-GNU-NOT: add i32 %{{.*}} 7
comment|// APCS-GNU-NOT: and i32 %{{.*}} -8
name|double
name|ll
init|=
name|__builtin_va_arg
argument_list|(
name|ap
argument_list|,
name|double
argument_list|)
decl_stmt|;
name|__builtin_va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|ll
return|;
block|}
end_function

end_unit

