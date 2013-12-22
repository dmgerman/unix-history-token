begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This file contains code and checks, that should work on any platform.
end_comment

begin_comment
comment|// There's a set of additional checks for systems with proper support of UTF-8
end_comment

begin_comment
comment|// on the standard output in fixit-unicode-with-utf8-output.c.
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only %s 2>&1 | FileCheck -strict-whitespace %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only -fdiagnostics-parseable-fixits %s 2>&1 | FileCheck -check-prefix=CHECK-MACHINE %s
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
name|foo
operator|.
name|bar
operator|=
literal|42â
comment|// CHECK: error: non-ASCII characters are not allowed outside of literals and identifiers
comment|// CHECK: {{^              \^}}
comment|// CHECK: error: expected ';' after expression
comment|// Make sure we emit the fixit right in front of the snowman.
comment|// CHECK: {{^              \^}}
comment|// CHECK: {{^              ;}}
comment|// CHECK-MACHINE: fix-it:"{{.*}}":{[[@LINE-8]]:15-[[@LINE-8]]:18}:""
comment|// CHECK-MACHINE: fix-it:"{{.*}}":{[[@LINE-9]]:15-[[@LINE-9]]:15}:";"
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
comment|// CHECK-MACHINE: fix-it:"{{.*}}":{[[@LINE-9]]:16-[[@LINE-9]]:18}:"%ld"
block|}
end_function

begin_function
name|void
name|test3
parameter_list|()
block|{
name|int
name|à¸ssss
init|=
literal|42
decl_stmt|;
name|int
name|a
init|=
name|à¸sss
decl_stmt|;
comment|// expected-error{{use of undeclared identifier 'à¸sss'; did you mean 'à¸ssss'?}}
comment|// CHECK: {{^          \^}}
comment|// CHECK: {{^          [^ ]+ssss}}
comment|// CHECK-MACHINE: fix-it:"{{.*}}":{[[@LINE-3]]:11-[[@LINE-3]]:17}:"\340\270\201ssss"
name|int
name|ssà¸ss
init|=
literal|42
decl_stmt|;
name|int
name|b
init|=
name|ssà¸s
decl_stmt|;
comment|// expected-error{{use of undeclared identifier 'ssà¸s'; did you mean 'ssà¸ss'?}}
comment|// CHECK: {{^          \^}}
comment|// CHECK: {{^          ss.+ss}}
comment|// CHECK-MACHINE: fix-it:"{{.*}}":{[[@LINE-3]]:11-[[@LINE-3]]:17}:"ss\340\270\201ss"
name|int
name|sä¸äºä¸
init|=
literal|42
decl_stmt|;
name|int
name|bä¸äºä¸åäºå­ä¸
init|=
name|ssä¸äºä¸
decl_stmt|;
comment|// expected-error{{use of undeclared identifier 'ssä¸äºä¸'; did you mean 'sä¸äºä¸'?}}
comment|// CHECK-MACHINE: fix-it:"{{.*}}":{[[@LINE-1]]:32-[[@LINE-1]]:43}:"s\344\270\200\344\272\214\344\270\211"
name|int
name|sssssssssà¸
init|=
literal|42
decl_stmt|;
name|int
name|c
init|=
name|sssssssss
decl_stmt|;
comment|// expected-error{{use of undeclared identifier 'sssssssss'; did you mean 'sssssssssà¸'?}}
comment|// CHECK: {{^          \^}}
comment|// CHECK: {{^          sssssssss.+}}
comment|// CHECK-MACHINE: fix-it:"{{.*}}":{[[@LINE-3]]:11-[[@LINE-3]]:20}:"sssssssss\340\270\201"
block|}
end_function

end_unit

