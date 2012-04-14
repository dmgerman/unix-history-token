begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -x objective-c -fmodule-cache-path %t -F %S/Inputs %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// FIXME: When we have a syntax for modules in C, use that.
end_comment

begin_decl_stmt
unit|@
name|__experimental_modules_import
name|MutuallyRecursive1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// FIXME: Lots of redundant diagnostics here, because the preprocessor
end_comment

begin_comment
comment|// can't currently tell the parser not to try to load the module again.
end_comment

begin_comment
comment|// CHECK: MutuallyRecursive2.h:3:32: fatal error: cyclic dependency in module 'MutuallyRecursive1': MutuallyRecursive1 -> MutuallyRecursive2 -> MutuallyRecursive1
end_comment

begin_comment
comment|// CHECK: MutuallyRecursive1.h:2:32: fatal error: could not build module 'MutuallyRecursive2'
end_comment

begin_comment
comment|// CHECK: cycles.c:4:32: fatal error: could not build module 'MutuallyRecursive1'
end_comment

end_unit

