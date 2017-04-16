begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that clang can use a PCH created from libclang.
end_comment

begin_comment
comment|// FIXME: Non-darwin bots fail. Would need investigation using -module-file-info to see what is the difference in modules generated from libclang vs the compiler invocation, in those systems.
end_comment

begin_comment
comment|// REQUIRES: system-darwin
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s -verify
end_comment

begin_comment
comment|// RUN: c-index-test -write-pch %t.h.pch %s -fmodules -fmodules-cache-path=%t.mcp -Xclang -triple -Xclang x86_64-apple-darwin
end_comment

begin_comment
comment|// RUN: %clang -fsyntax-only -include %t.h %s -Xclang -verify -fmodules -fmodules-cache-path=%t.mcp -Xclang -detailed-preprocessing-record -Xclang -triple -Xclang x86_64-apple-darwin -Xclang -fallow-pch-with-compiler-errors
end_comment

begin_comment
comment|// RUN: %clang -x c-header %s -o %t.clang.h.pch -fmodules -fmodules-cache-path=%t.mcp -Xclang -detailed-preprocessing-record -Xclang -triple -Xclang x86_64-apple-darwin -Xclang -fallow-pch-with-compiler-errors -Xclang -verify
end_comment

begin_comment
comment|// RUN: c-index-test -test-load-source local %s -include %t.clang.h -fmodules -fmodules-cache-path=%t.mcp -Xclang -triple -Xclang x86_64-apple-darwin | FileCheck %s
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER
end_ifndef

begin_define
define|#
directive|define
name|HEADER
end_define

begin_function_decl
name|void
name|some_function
parameter_list|(
name|undeclared_type
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{unknown type name}}
end_comment

begin_struct
struct|struct
name|S
block|{
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_function
name|void
name|test
parameter_list|(
name|struct
name|S
modifier|*
name|s
parameter_list|)
block|{
comment|// CHECK: [[@LINE+1]]:6: MemberRefExpr=x:[[@LINE-6]]:16
name|s
operator|->
name|x
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

