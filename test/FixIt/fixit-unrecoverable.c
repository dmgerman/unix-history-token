begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* FIXME: This is a file containing various typos for which we can    suggest corrections but are unable to actually recover from    them. Ideally, we would eliminate all such cases and move these    tests elsewhere. */
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_decl_stmt
name|unsinged
name|x
init|=
literal|17
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{unknown type name 'unsinged'; did you mean 'unsigned'?}}
end_comment

end_unit

