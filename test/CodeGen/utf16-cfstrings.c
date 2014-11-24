begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|//<rdar://problem/10655949>
end_comment

begin_comment
comment|// CHECK: @.str = private unnamed_addr constant [9 x i16] [i16 252, i16 98, i16 101, i16 114, i16 104, i16 117, i16 110, i16 100, i16 0], section "__TEXT,__ustring", align 2
end_comment

begin_define
define|#
directive|define
name|CFSTR
value|__builtin___CFStringMakeConstantString
end_define

begin_function
name|void
name|foo
parameter_list|()
block|{
name|CFSTR
argument_list|(
literal|"Ã¼berhund"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

