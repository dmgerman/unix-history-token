begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm-none-linux-gnueabi -emit-llvm -w -o -< %s | FileCheck %s
end_comment

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|pcs
argument_list|(
literal|"aapcs"
argument_list|)
operator|)
argument_list|)
argument_list|(
operator|*
name|aapcs_fn
argument_list|)
argument_list|(
name|void
argument_list|)
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|pcs
argument_list|(
literal|"aapcs-vfp"
argument_list|)
operator|)
argument_list|)
argument_list|(
operator|*
name|aapcs_vfp_fn
argument_list|)
argument_list|(
name|void
argument_list|)
typedef|;
end_typedef

begin_decl_stmt
name|aapcs_fn
name|bar
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|foo
parameter_list|(
name|aapcs_vfp_fn
name|baz
parameter_list|)
block|{
comment|// CHECK-LABEL: define i32 @foo
comment|// CHECK: call arm_aapcscc
comment|// CHECK: call arm_aapcs_vfpcc
return|return
name|bar
argument_list|()
operator|+
name|baz
argument_list|()
return|;
block|}
end_function

end_unit

