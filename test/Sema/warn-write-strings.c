begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -fsyntax-only -Wwrite-strings %s
end_comment

begin_comment
comment|// PR4804
end_comment

begin_decl_stmt
name|char
modifier|*
name|x
init|=
literal|"foo"
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{initializing 'char *' with an expression of type 'char const [4]' discards qualifiers}}
end_comment

end_unit

