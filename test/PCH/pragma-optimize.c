begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -include %s -verify -fsyntax-only
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-pch -o %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -include-pch %t -o - | FileCheck %s
end_comment

begin_comment
comment|// The first run line creates a pch, and since at that point HEADER is not
end_comment

begin_comment
comment|// defined, the only thing contained in the pch is the pragma. The second line
end_comment

begin_comment
comment|// then includes that pch, so HEADER is defined and the actual code is compiled.
end_comment

begin_comment
comment|// The check then makes sure that the pragma is in effect in the file that
end_comment

begin_comment
comment|// includes the pch.
end_comment

begin_comment
comment|// expected-no-diagnostics
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

begin_pragma
pragma|#
directive|pragma
name|clang
name|optimize
name|off
end_pragma

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|a
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f
parameter_list|()
block|{
name|a
operator|=
literal|12345
expr_stmt|;
block|}
end_function

begin_comment
comment|// Check that the function is decorated with optnone
end_comment

begin_comment
comment|// CHECK-DAG: @f() [[ATTRF:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK-DAG: attributes [[ATTRF]] = { {{.*}}noinline{{.*}}optnone{{.*}} }
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

