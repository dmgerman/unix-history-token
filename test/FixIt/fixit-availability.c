begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wunguarded-availability -fdiagnostics-parseable-fixits -triple x86_64-apple-darwin9 %s 2>&1 | FileCheck %s
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(availability(macos, introduced=
literal|10.12
argument|))
argument_list|)
end_macro

begin_function_decl
name|int
name|function
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|use
parameter_list|()
block|{
name|function
argument_list|()
expr_stmt|;
comment|// CHECK: fix-it:{{.*}}:{[[@LINE-1]]:3-[[@LINE-1]]:3}:"if (__builtin_available(macos 10.12, *)) {\n      "
comment|// CHECK-NEXT: fix-it:{{.*}}:{[[@LINE-2]]:14-[[@LINE-2]]:14}:"\n  } else {\n      // Fallback on earlier versions\n  }"
block|}
end_function

end_unit

