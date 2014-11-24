begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o %t
end_comment

begin_comment
comment|//<rdar://problem/10657500>: Check that the backing store of CFStrings are
end_comment

begin_comment
comment|// constant with the -fwritable-strings flag.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fwritable-strings -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: @.str = private unnamed_addr constant [14 x i8] c"Hello, World!\00", section "__TEXT,__cstring,cstring_literals", align 1
end_comment

begin_comment
comment|// CHECK: @.str1 = private unnamed_addr constant [7 x i8] c"yo joe\00", section "__TEXT,__cstring,cstring_literals", align 1
end_comment

begin_comment
comment|// CHECK: @.str3 = private unnamed_addr constant [16 x i8] c"Goodbye, World!\00", section "__TEXT,__cstring,cstring_literals", align 1
end_comment

begin_define
define|#
directive|define
name|CFSTR
value|__builtin___CFStringMakeConstantString
end_define

begin_function
name|void
name|f
parameter_list|()
block|{
name|CFSTR
argument_list|(
literal|"Hello, World!"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// rdar://6248329
end_comment

begin_decl_stmt
name|void
modifier|*
name|G
init|=
name|CFSTR
argument_list|(
literal|"yo joe"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|h
parameter_list|()
block|{
specifier|static
name|void
modifier|*
name|h
init|=
name|CFSTR
argument_list|(
literal|"Goodbye, World!"
argument_list|)
decl_stmt|;
block|}
end_function

end_unit

