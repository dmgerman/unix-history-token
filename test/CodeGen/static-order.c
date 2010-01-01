begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: ModuleID
end_comment

begin_comment
comment|// CHECK-NOT: zeroinitializer
end_comment

begin_comment
comment|// CHECK: define i8* @f
end_comment

begin_struct
struct|struct
name|s
block|{
name|int
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|void
modifier|*
name|v
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|s
name|a
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|s
name|a
init|=
block|{
literal|10
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
modifier|*
name|f
parameter_list|()
block|{
if|if
condition|(
name|a
operator|.
name|a
condition|)
return|return
name|v
return|;
block|}
end_function

end_unit

