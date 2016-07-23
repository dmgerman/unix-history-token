begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-linux-gnu -emit-obj --mrelax-relocations %s -mrelocation-model pic -o %t
end_comment

begin_comment
comment|// RUN: llvm-readobj -r %t | FileCheck  %s
end_comment

begin_comment
comment|// CHECK: R_X86_64_REX_GOTPCRELX foo
end_comment

begin_decl_stmt
specifier|extern
name|int
name|foo
decl_stmt|;
end_decl_stmt

begin_function
name|int
modifier|*
name|f
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|&
name|foo
return|;
block|}
end_function

end_unit

