begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -DNONE
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -DALL -Wgnu
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -DALL \
end_comment

begin_comment
comment|// RUN:   -Wgnu-zero-variadic-macro-arguments \
end_comment

begin_comment
comment|// RUN:   -Wgnu-imaginary-constant -Wgnu-binary-literal -Wgnu-zero-line-directive
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -DNONE -Wgnu \
end_comment

begin_comment
comment|// RUN:   -Wno-gnu-zero-variadic-macro-arguments \
end_comment

begin_comment
comment|// RUN:   -Wno-gnu-imaginary-constant -Wno-gnu-binary-literal -Wno-gnu-zero-line-directive
end_comment

begin_comment
comment|// Additional disabled tests:
end_comment

begin_comment
comment|// %clang_cc1 -fsyntax-only -verify %s -DZEROARGS -Wgnu-zero-variadic-macro-arguments
end_comment

begin_comment
comment|// %clang_cc1 -fsyntax-only -verify %s -DIMAGINARYCONST -Wgnu-imaginary-constant
end_comment

begin_comment
comment|// %clang_cc1 -fsyntax-only -verify %s -DBINARYLITERAL -Wgnu-binary-literal
end_comment

begin_comment
comment|// %clang_cc1 -fsyntax-only -verify %s -DLINE0 -Wgnu-zero-line-directive
end_comment

begin_if
if|#
directive|if
name|NONE
end_if

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|ALL
operator|||
name|ZEROARGS
end_if

begin_comment
comment|// expected-warning@+9 {{must specify at least one argument for '...' parameter of variadic macro}}
end_comment

begin_comment
comment|// expected-note@+4 {{macro 'efoo' defined here}}
end_comment

begin_comment
comment|// expected-warning@+3 {{token pasting of ',' and __VA_ARGS__ is a GNU extension}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|efoo
parameter_list|(
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
value|foo(format , ##args)
end_define

begin_function
name|void
name|foo
parameter_list|(
specifier|const
name|char
modifier|*
name|c
parameter_list|)
block|{
name|efoo
argument_list|(
literal|"6"
argument_list|)
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
name|ALL
operator|||
name|IMAGINARYCONST
end_if

begin_comment
comment|// expected-warning@+3 {{imaginary constants are a GNU extension}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|float
specifier|_Complex
name|c
init|=
literal|1.if
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|ALL
operator|||
name|BINARYLITERAL
end_if

begin_comment
comment|// expected-warning@+3 {{binary integer literals are a GNU extension}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|b
init|=
literal|0b0101
decl_stmt|;
end_decl_stmt

begin_comment
comment|// This case is handled differently because lit has a bug whereby #line 0 is reported to be on line 4294967295
end_comment

begin_comment
comment|// http://llvm.org/bugs/show_bug.cgi?id=16952
end_comment

begin_if
if|#
directive|if
name|ALL
operator|||
name|LINE0
end_if

begin_line
line|#
directive|line
number|0
end_line

begin_comment
comment|// expected-warning {{#line directive with zero argument is a GNU extension}}
end_comment

begin_else
else|#
directive|else
end_else

begin_line
line|#
directive|line
number|0
end_line

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// WARNING: Do not add more tests after the #line 0 line!  Add them before the LINE0 test
end_comment

end_unit

