begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-freebsd10.0 -emit-llvm< %s | FileCheck -check-prefix=FREEBSD %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-win32 -emit-llvm< %s | FileCheck -check-prefix=WIN64 %s
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|ms_abi
operator|)
argument_list|)
name|f1
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|sysv_abi
operator|)
argument_list|)
name|f2
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f3
parameter_list|(
name|void
parameter_list|)
block|{
comment|// FREEBSD: define void @f3()
comment|// WIN64: define void @f3()
name|f1
argument_list|()
expr_stmt|;
comment|// FREEBSD: call x86_64_win64cc void @f1()
comment|// WIN64: call void @f1()
name|f2
argument_list|()
expr_stmt|;
comment|// FREEBSD: call void @f2()
comment|// WIN64: call x86_64_sysvcc void @f2()
block|}
end_function

begin_comment
comment|// FREEBSD: declare x86_64_win64cc void @f1()
end_comment

begin_comment
comment|// FREEBSD: declare void @f2()
end_comment

begin_comment
comment|// WIN64: declare void @f1()
end_comment

begin_comment
comment|// WIN64: declare x86_64_sysvcc void @f2()
end_comment

end_unit

