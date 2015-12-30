begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple sparc-unknown-unknown -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// Ensure that we pass proper alignment to llvm in the call
end_comment

begin_comment
comment|// instruction. The proper alignment for the type is sometimes known
end_comment

begin_comment
comment|// only by clang, and is not manifest in the LLVM-type. So, it must be
end_comment

begin_comment
comment|// explicitly passed through. (Besides the case of the user specifying
end_comment

begin_comment
comment|// alignment, as here, this situation also occurrs for non-POD C++
end_comment

begin_comment
comment|// structs with tail-padding: clang emits these as packed llvm-structs
end_comment

begin_comment
comment|// for ABI reasons.)
end_comment

begin_struct
struct|struct
name|s1
block|{
name|int
name|x
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|8
argument_list|)
operator|)
argument_list|)
struct|;
end_struct

begin_decl_stmt
name|struct
name|s1
name|x1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Ensure the align 8 is passed through:
end_comment

begin_comment
comment|// CHECK-LABEL: define void @f1()
end_comment

begin_comment
comment|// CHECK: call void @f1_helper(%struct.s1* byval align 8 @x1)
end_comment

begin_comment
comment|// Also ensure the declaration of f1_helper includes it
end_comment

begin_comment
comment|// CHECK: declare void @f1_helper(%struct.s1* byval align 8)
end_comment

begin_function_decl
name|void
name|f1_helper
parameter_list|(
name|struct
name|s1
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f1
parameter_list|()
block|{
name|f1_helper
argument_list|(
name|x1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

