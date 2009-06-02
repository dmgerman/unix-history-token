begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -x assembler-with-cpp -fdollars-in-identifiers=0 -E %s> %t&&
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLER__
end_ifndef

begin_error
error|#
directive|error
literal|"__ASSEMBLER__ not defined"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Invalid token pasting is ok.
end_comment

begin_comment
comment|// RUN: grep '1: X .' %t&&
end_comment

begin_define
define|#
directive|define
name|A
value|X ## .
end_define

begin_expr_stmt
literal|1
operator|:
name|A
comment|// Line markers are not linemarkers in .S files, they are passed through.
comment|// RUN: grep '# 321' %t&&
empty|# 321
comment|// Unknown directives are passed through.
comment|// RUN: grep '# B C' %t&&
empty|# B C
comment|// Unknown directives are expanded.
comment|// RUN: grep '# BAR42' %t&&
define|#
directive|define
name|D
parameter_list|(
name|x
parameter_list|)
value|BAR ## x
empty|# D(42)
comment|// Unmatched quotes are permitted.
comment|// RUN: grep "2: '" %t&&
comment|// RUN: grep '3: "' %t&&
literal|2
operator|:
literal|' 3: "  // (balance quotes to keep editors happy): "'
comment|// Empty char literals are ok.
comment|// RUN: grep "4: ''" %t&&
literal|4
operator|:
literal|''
comment|// Portions of invalid pasting should still expand as macros.
comment|// rdar://6709206
comment|// RUN: grep "5: expanded (" %t&&
define|#
directive|define
name|M4
value|expanded
define|#
directive|define
name|M5
parameter_list|()
value|M4 ## (
literal|5
operator|:
name|M5
argument_list|()
comment|// rdar://6804322
comment|// RUN: grep -F "6: blarg $foo" %t&&
define|#
directive|define
name|FOO
parameter_list|(
name|name
parameter_list|)
value|name ## $foo
literal|6
operator|:
name|FOO
argument_list|(
name|blarg
argument_list|)
comment|// RUN: clang-cc -x assembler-with-cpp -fdollars-in-identifiers=1 -E %s> %t&&
comment|// RUN: grep -F "7: blarg$foo" %t&&
define|#
directive|define
name|FOO
parameter_list|(
name|name
parameter_list|)
value|name ## $foo
literal|7
operator|:
name|FOO
argument_list|(
name|blarg
argument_list|)
comment|//
define|#
directive|define
name|T6
parameter_list|()
value|T6 #nostring
define|#
directive|define
name|T7
parameter_list|(
name|x
parameter_list|)
value|T7 #x
literal|8
operator|:
name|T6
argument_list|()
literal|9
operator|:
name|T7
argument_list|(
name|foo
argument_list|)
comment|// RUN: grep '8: T6 #nostring' %t&&
comment|// RUN: grep '9: T7 "foo"' %t&&
comment|// Concatenation with period doesn't leave a space
comment|// RUN: grep -F '10: .T8' %t&&
define|#
directive|define
name|T8
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|A ## B
literal|10
operator|:
name|T8
argument_list|(
operator|.
argument_list|,
name|T8
argument_list|)
comment|// This should not crash.
comment|// RUN: grep '11: #0' %t&&
define|#
directive|define
name|T11
parameter_list|(
name|a
parameter_list|)
value|#0
literal|11
operator|:
name|T11
argument_list|(
argument|b
argument_list|)
end_expr_stmt

begin_comment
comment|// RUN: true
end_comment

end_unit

