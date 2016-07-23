begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// Check that no empty blocks are generated for nested ifs.
end_comment

begin_function_decl
specifier|extern
name|void
name|func
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|f0
parameter_list|(
name|int
name|val
parameter_list|)
block|{
if|if
condition|(
name|val
operator|==
literal|0
condition|)
block|{
name|func
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|val
operator|==
literal|1
condition|)
block|{
name|func
argument_list|()
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define {{.*}}i32 @f0
end_comment

begin_comment
comment|// CHECK: call void {{.*}} @func
end_comment

begin_comment
comment|// CHECK: call void {{.*}} @func
end_comment

begin_comment
comment|// CHECK: br label %[[RETBLOCK1:[^ ]*]]
end_comment

begin_comment
comment|// CHECK: [[RETBLOCK1]]:
end_comment

begin_comment
comment|// CHECK-NOT: br label
end_comment

begin_comment
comment|// CHECK: ret i32
end_comment

begin_function
name|int
name|f1
parameter_list|(
name|int
name|val
parameter_list|,
name|int
name|g
parameter_list|)
block|{
if|if
condition|(
name|val
operator|==
literal|0
condition|)
if|if
condition|(
name|g
operator|==
literal|1
condition|)
block|{
name|func
argument_list|()
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define {{.*}}i32 @f1
end_comment

begin_comment
comment|// CHECK: call void {{.*}} @func
end_comment

begin_comment
comment|// CHECK: br label %[[RETBLOCK2:[^ ]*]]
end_comment

begin_comment
comment|// CHECK: [[RETBLOCK2]]:
end_comment

begin_comment
comment|// CHECK-NOT: br label
end_comment

begin_comment
comment|// CHECK: ret i32
end_comment

end_unit

