begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// PR1721
end_comment

begin_struct
struct|struct
name|s
block|{
name|unsigned
name|long
name|long
name|u33
range|:
literal|33
decl_stmt|;
block|}
name|a
struct|,
name|b
struct|;
end_struct

begin_comment
comment|// This should have %0 and %1 truncated to 33 bits before any operation.
end_comment

begin_comment
comment|// This can be done using i33 or an explicit and.
end_comment

begin_function
name|_Bool
name|test
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: and i64 %[[TMP1:[0-9]+]], 8589934591
comment|// CHECK-NOT: and i64 [[TMP1]], 8589934591
comment|// CHECK: and i64 %{{[0-9]}}, 8589934591
return|return
name|a
operator|.
name|u33
operator|+
name|b
operator|.
name|u33
operator|!=
literal|0
return|;
block|}
end_function

end_unit

