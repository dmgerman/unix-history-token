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
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
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

end_unit

