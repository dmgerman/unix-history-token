begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify
end_comment

begin_comment
comment|// Lexer diagnostics shouldn't be included in #pragma mark.
end_comment

begin_pragma
pragma|#
directive|pragma
name|mark
name|Mike
literal|'s world
end_pragma

begin_macro
name|_Pragma
argument_list|(
literal|"mark foo ' bar"
argument_list|)
end_macro

begin_define
define|#
directive|define
name|X
parameter_list|(
name|S
parameter_list|)
value|_Pragma(S)
end_define

begin_macro
name|X
argument_list|(
literal|"mark foo ' bar"
argument_list|)
end_macro

begin_decl_stmt
name|int
name|i
decl_stmt|;
end_decl_stmt

end_unit

