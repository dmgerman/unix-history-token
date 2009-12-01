begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -verify -rewrite-macros -o %t %s
end_comment

begin_define
define|#
directive|define
name|A
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a ## b
end_define

begin_comment
comment|// RUN: grep '12 */\*A\*/ /\*(1,2)\*/' %t
end_comment

begin_macro
name|A
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
end_macro

begin_comment
comment|// RUN: grep '/\*_Pragma("mark")\*/' %t
end_comment

begin_macro
name|_Pragma
argument_list|(
literal|"mark"
argument_list|)
end_macro

begin_comment
comment|// RUN: grep "//#warning eek" %t
end_comment

begin_comment
comment|/* expected-warning {{#warning eek}} */
end_comment

begin_warning
warning|#
directive|warning
warning|eek
end_warning

begin_comment
comment|// RUN: grep "//#pragma mark mark" %t
end_comment

begin_pragma
pragma|#
directive|pragma
name|mark
name|mark
end_pragma

end_unit

