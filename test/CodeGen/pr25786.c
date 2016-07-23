begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-unknown-linux-gnu -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-OK
end_comment

begin_expr_stmt
name|void
argument_list|(
name|__attribute__
argument_list|(
operator|(
name|regparm
argument_list|(
literal|3
argument_list|)
operator|,
name|stdcall
operator|)
argument_list|)
operator|*
name|pf
argument_list|)
argument_list|()
expr_stmt|;
end_expr_stmt

begin_macro
name|void
argument_list|(
argument|__attribute__((regparm(
literal|2
argument|), stdcall)) foo
argument_list|)
end_macro

begin_expr_stmt
operator|(
name|int
name|a
operator|)
block|{ }
end_expr_stmt

begin_comment
comment|// CHECK: @pf = common global void (...)* null
end_comment

begin_comment
comment|// CHECK: define void @foo(i32 %a)
end_comment

begin_comment
comment|// CHECK-OK: @pf = common global void (...)* null
end_comment

begin_comment
comment|// CHECK-OK: define x86_stdcallcc void @foo(i32 inreg %a)
end_comment

end_unit

