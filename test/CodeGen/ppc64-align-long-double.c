begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-unknown-linux-gnu -emit-llvm -o - %s | FileCheck %s
end_comment

begin_struct
struct|struct
name|S
block|{
name|double
name|a
decl_stmt|;
name|long
name|double
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: %struct.{{[a-zA-Z0-9]+}} = type { double, ppc_fp128 }
end_comment

begin_function
name|long
name|double
name|test
parameter_list|(
name|struct
name|S
name|x
parameter_list|)
block|{
return|return
name|x
operator|.
name|b
return|;
block|}
end_function

begin_comment
comment|// CHECK: %{{[0-9]}} = load ppc_fp128* %{{[a-zA-Z0-9]+}}, align 16
end_comment

end_unit

