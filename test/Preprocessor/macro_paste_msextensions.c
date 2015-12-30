begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -fms-extensions -Wmicrosoft %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -P -E -fms-extensions %s | FileCheck -strict-whitespace %s
end_comment

begin_comment
comment|// This horrible stuff should preprocess into (other than whitespace):
end_comment

begin_comment
comment|//   int foo;
end_comment

begin_comment
comment|//   int bar;
end_comment

begin_comment
comment|//   int baz;
end_comment

begin_decl_stmt
name|int
name|foo
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: int foo;
end_comment

begin_define
define|#
directive|define
name|comment
value|/##/  dead tokens live here
end_define

begin_comment
comment|// expected-warning@+1 {{pasting two '/' tokens}}
end_comment

begin_decl_stmt
name|comment
name|This
name|is
name|stupidity
name|int
name|bar
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: int bar;
end_comment

begin_define
define|#
directive|define
name|nested
parameter_list|(
name|x
parameter_list|)
value|int x comment cute little dead tokens...
end_define

begin_comment
comment|// expected-warning@+1 {{pasting two '/' tokens}}
end_comment

begin_macro
name|nested
argument_list|(
argument|baz
argument_list|)
end_macro

begin_decl_stmt
name|rise
name|of
name|the
name|dead
name|tokens
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: int baz
end_comment

begin_comment
comment|// CHECK: ;
end_comment

begin_comment
comment|// rdar://8197149 - VC++ allows invalid token pastes: (##baz
end_comment

begin_define
define|#
directive|define
name|foo
parameter_list|(
name|x
parameter_list|)
value|abc(x)
end_define

begin_define
define|#
directive|define
name|bar
parameter_list|(
name|y
parameter_list|)
value|foo(##baz(y))
end_define

begin_macro
name|bar
argument_list|(
argument|q
argument_list|)
end_macro

begin_comment
comment|// expected-warning {{type specifier missing}} expected-error {{invalid preprocessing token}} expected-error {{parameter list without types}}
end_comment

begin_comment
comment|// CHECK: abc(baz(q))
end_comment

begin_define
define|#
directive|define
name|str
parameter_list|(
name|x
parameter_list|)
value|#x
end_define

begin_define
define|#
directive|define
name|collapse_spaces
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|str(a ## - ## b ## - ## c ## d)
end_define

begin_macro
name|collapse_spaces
argument_list|(
literal|1a
argument_list|,
argument|b2
argument_list|,
literal|3c
argument_list|,
argument|d4
argument_list|)
end_macro

begin_comment
comment|// expected-error 4 {{invalid preprocessing token}} expected-error {{expected function body}}
end_comment

begin_comment
comment|// CHECK: "1a-b2-3cd4"
end_comment

end_unit

