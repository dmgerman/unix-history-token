begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -x objective-c -fmodules-cache-path=%t -emit-module -fmodule-name=irgen -triple x86_64-apple-darwin10 %S/Inputs/module.map
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -x objective-c -fmodules-cache-path=%t -I %S/Inputs -triple x86_64-apple-darwin10 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// FIXME: When we have a syntax for modules in C, use that.
end_comment

begin_decl_stmt
unit|@
name|import
name|irgen
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: define void @triple_value
end_comment

begin_function
name|void
name|triple_value
parameter_list|(
name|int
modifier|*
name|px
parameter_list|)
block|{
operator|*
name|px
operator|=
name|triple
argument_list|(
operator|*
name|px
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: define internal i32 @triple(i32
end_comment

end_unit

