begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// FIXME: https://code.google.com/p/address-sanitizer/issues/detail?id=316
end_comment

begin_comment
comment|// XFAIL: android
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Make sure __asan_gen_* strings do not end up in the symbol table.
end_comment

begin_comment
comment|// RUN: %clang_asan %s -o %t.exe
end_comment

begin_comment
comment|// RUN: nm %t.exe | FileCheck %s
end_comment

begin_decl_stmt
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-NOT: __asan_gen_
end_comment

end_unit

