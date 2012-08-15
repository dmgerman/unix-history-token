begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s 2>&1 | FileCheck -strict-whitespace %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -fdiagnostics-parseable-fixits %s 2>&1 | FileCheck -check-prefix=CHECK-MACHINE %s
end_comment

begin_struct
struct|struct
name|Foo
block|{
name|int
name|bar
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// PR13312
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
name|struct
name|Foo
name|foo
decl_stmt|;
operator|(
operator|&
name|foo
operator|)
name|â
operator|>
name|bar
operator|=
literal|42
expr_stmt|;
comment|// CHECK: error: expected ';' after expression
comment|// Make sure we emit the fixit right in front of the snowman.
comment|// CHECK: {{^        \^}}
comment|// CHECK: {{^        ;}}
comment|// CHECK-MACHINE: fix-it:"{{.*}}fixit-unicode.c":{11:9-11:9}:";"
block|}
end_function

begin_function_decl
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test2
parameter_list|()
block|{
name|printf
argument_list|(
literal|"â: %d"
argument_list|,
literal|1L
argument_list|)
expr_stmt|;
comment|// CHECK: warning: format specifies type 'int' but the argument has type 'long'
comment|// Don't crash emitting a fixit after the delta.
comment|// CHECK:  printf("
comment|// CHECK: : %d", 1L);
comment|// Unfortunately, we can't actually check the location of the printed fixit,
comment|// because different systems will render the delta differently (either as a
comment|// character, or as<U+2206>.) The fixit should line up with the %d regardless.
comment|// CHECK-MACHINE: fix-it:"{{.*}}fixit-unicode.c":{23:16-23:18}:"%ld"
block|}
end_function

end_unit

