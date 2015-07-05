begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -O1 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_enum
enum|enum
name|e0
block|{
name|E0
block|}
enum|;
end_enum

begin_struct
struct|struct
name|s0
block|{
name|enum
name|e0
name|a
range|:
literal|31
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
name|f0
parameter_list|()
block|{
return|return
name|__builtin_omp_required_simd_align
argument_list|(
expr|struct
name|s0
argument_list|)
return|;
comment|// CHECK: ret i32 16
block|}
end_function

end_unit

