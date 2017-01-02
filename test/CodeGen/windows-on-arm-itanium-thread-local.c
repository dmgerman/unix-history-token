begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7--windows-itanium -fdeclspec -fms-compatibility -fms-compatibility-version=19.0 -S -emit-llvm -o - %s | FileCheck %s
end_comment

begin_macro
name|__declspec
argument_list|(
argument|thread
argument_list|)
end_macro

begin_decl_stmt
specifier|static
name|void
modifier|*
name|c
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
name|c
operator|=
name|p
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @f(i8* %p)
end_comment

begin_comment
comment|// CHECK-NOT: call i8** @_ZTWL1c()
end_comment

begin_comment
comment|// CHECK: call arm_aapcs_vfpcc i8** @_ZTWL1c()
end_comment

end_unit

