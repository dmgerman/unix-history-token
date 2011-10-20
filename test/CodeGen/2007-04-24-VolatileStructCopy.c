begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// PR1352
end_comment

begin_struct
struct|struct
name|foo
block|{
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|copy
parameter_list|(
specifier|volatile
name|struct
name|foo
modifier|*
name|p
parameter_list|,
name|struct
name|foo
modifier|*
name|q
parameter_list|)
block|{
comment|// CHECK: call void @llvm.memcpy
operator|*
name|p
operator|=
operator|*
name|q
expr_stmt|;
block|}
end_function

end_unit

