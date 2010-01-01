begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_struct
struct|struct
name|a
block|{
struct|struct
block|{
name|int
name|b
decl_stmt|;
block|}
name|x
index|[
literal|2
index|]
struct|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|a
init|=
name|__builtin_offsetof
argument_list|(
argument|struct a
argument_list|,
argument|x;
comment|// expected-error{{expected ')'}} expected-note{{to match this '('}}
comment|// FIXME: This actually shouldn't give an error
argument|int b = __builtin_offsetof(struct a, x->b);
end_decl_stmt

begin_comment
comment|// expected-error{{expected ')'}} expected-note{{to match this '('}}
end_comment

end_unit

