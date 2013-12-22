begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin %s -emit-llvm -O1 -relaxed-aliasing -o - | FileCheck %s
end_comment

begin_enum
enum|enum
name|e1
block|{
name|e1_a
init|=
operator|-
literal|1
block|}
enum|;
end_enum

begin_function
name|enum
name|e1
name|g1
parameter_list|(
name|enum
name|e1
modifier|*
name|x
parameter_list|)
block|{
return|return
operator|*
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @g1
end_comment

begin_comment
comment|// CHECK: load i32* %x, align 4
end_comment

begin_comment
comment|// CHECK-NOT: range
end_comment

begin_comment
comment|// CHECK: ret
end_comment

end_unit

