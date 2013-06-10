begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Test pragma message directive from    http://msdn.microsoft.com/en-us/library/x7dkzch2.aspx */
end_comment

begin_comment
comment|// message: Sends a string literal to the standard output without terminating
end_comment

begin_comment
comment|// the compilation.
end_comment

begin_comment
comment|// #pragma message(messagestring)
end_comment

begin_comment
comment|// OR
end_comment

begin_comment
comment|// #pragma message messagestring
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -Werror %s
end_comment

begin_define
define|#
directive|define
name|STRING2
parameter_list|(
name|x
parameter_list|)
value|#x
end_define

begin_define
define|#
directive|define
name|STRING
parameter_list|(
name|x
parameter_list|)
value|STRING2(x)
end_define

begin_pragma
pragma|#
directive|pragma
name|message
name|(
literal|":O I'm a message! "
name|STRING
name|(
name|__LINE__
name|)
name|)
end_pragma

begin_comment
comment|// expected-warning {{:O I'm a message! 13}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|message
literal|":O gcc accepts this! "
name|STRING
name|(
name|__LINE__
name|)
end_pragma

begin_comment
comment|// expected-warning {{:O gcc accepts this! 14}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|message
name|(
name|invalid
name|)
end_pragma

begin_comment
comment|// expected-error {{expected string literal in pragma message}}
end_comment

begin_comment
comment|// GCC supports a similar pragma, #pragma GCC warning (which generates a warning
end_comment

begin_comment
comment|// message) and #pragma GCC error (which generates an error message).
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|warning
name|(
literal|":O I'm a message! "
name|STRING
name|(
name|__LINE__
name|)
name|)
end_pragma

begin_comment
comment|// expected-warning {{:O I'm a message! 21}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|warning
literal|":O gcc accepts this! "
name|STRING
name|(
name|__LINE__
name|)
end_pragma

begin_comment
comment|// expected-warning {{:O gcc accepts this! 22}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|error
name|(
literal|":O I'm a message! "
name|STRING
name|(
name|__LINE__
name|)
name|)
end_pragma

begin_comment
comment|// expected-error {{:O I'm a message! 24}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|error
literal|":O gcc accepts this! "
name|STRING
name|(
name|__LINE__
name|)
end_pragma

begin_comment
comment|// expected-error {{:O gcc accepts this! 25}}
end_comment

begin_define
define|#
directive|define
name|COMPILE_ERROR
parameter_list|(
name|x
parameter_list|)
value|_Pragma(STRING2(GCC error(x)))
end_define

begin_expr_stmt
name|COMPILE_ERROR
argument_list|(
literal|"Compile error at line "
name|STRING
argument_list|(
name|__LINE__
argument_list|)
literal|"!"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{Compile error at line 28!}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|message
end_pragma

begin_comment
comment|// expected-error {{pragma message requires parenthesized string}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|warning
name|(
literal|""
end_pragma

begin_comment
comment|// expected-error {{pragma warning requires parenthesized string}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|error
name|(
name|1
name|)
end_pragma

begin_comment
comment|// expected-error {{expected string literal in pragma error}}
end_comment

end_unit

