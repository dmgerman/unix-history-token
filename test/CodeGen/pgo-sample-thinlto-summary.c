begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -O2 -fprofile-sample-use=%S/Inputs/pgo-sample-thinlto-summary.prof %s -emit-llvm -o - 2>&1 | FileCheck %s -check-prefix=O2
end_comment

begin_comment
comment|// RUN: %clang_cc1 -O2 -fprofile-sample-use=%S/Inputs/pgo-sample-thinlto-summary.prof %s -emit-llvm -flto=thin -o - 2>&1 | FileCheck %s -check-prefix=THINLTO
end_comment

begin_comment
comment|// Checks if hot call is inlined by normal compile, but not inlined by
end_comment

begin_comment
comment|// thinlto compile.
end_comment

begin_function_decl
name|int
name|baz
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|g
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo
parameter_list|(
name|int
name|n
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
name|i
operator|++
control|)
name|g
operator|+=
name|baz
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// O2-LABEL: define void @bar
end_comment

begin_comment
comment|// THINLTO-LABEL: define void @bar
end_comment

begin_comment
comment|// O2-NOT: call{{.*}}foo
end_comment

begin_comment
comment|// THINLTO: call{{.*}}foo
end_comment

begin_function
name|void
name|bar
parameter_list|(
name|int
name|n
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
name|i
operator|++
control|)
name|foo
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Checks if loop unroll is invoked by normal compile, but not thinlto compile.
end_comment

begin_comment
comment|// O2-LABEL: define void @unroll
end_comment

begin_comment
comment|// THINLTO-LABEL: define void @unroll
end_comment

begin_comment
comment|// O2: call{{.*}}baz
end_comment

begin_comment
comment|// O2: call{{.*}}baz
end_comment

begin_comment
comment|// THINLTO: call{{.*}}baz
end_comment

begin_comment
comment|// THINLTO-NOT: call{{.*}}baz
end_comment

begin_function
name|void
name|unroll
parameter_list|()
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|2
condition|;
name|i
operator|++
control|)
name|baz
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Check that icp is not invoked (both -O2 and ThinLTO).
end_comment

begin_comment
comment|// O2-LABEL: define void @icp
end_comment

begin_comment
comment|// THINLTO-LABEL: define void @icp
end_comment

begin_comment
comment|// O2-NOT: if.true.direct_targ
end_comment

begin_comment
comment|// ThinLTO-NOT: if.true.direct_targ
end_comment

begin_function
name|void
name|icp
parameter_list|(
name|void
function_decl|(
modifier|*
name|p
function_decl|)
parameter_list|()
parameter_list|)
block|{
name|p
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

