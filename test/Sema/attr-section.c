begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -fsyntax-only -triple x86_64-apple-darwin9 %s
end_comment

begin_decl_stmt
name|int
name|x
name|__attribute__
argument_list|(
operator|(
name|section
argument_list|(
literal|42
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{argument to section attribute was not a string literal}}
end_comment

begin_comment
comment|// rdar://4341926
end_comment

begin_decl_stmt
name|int
name|y
name|__attribute__
argument_list|(
operator|(
name|section
argument_list|(
literal|"sadf"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{mach-o section specifier requires a segment and section separated by a comma}}
end_comment

end_unit

