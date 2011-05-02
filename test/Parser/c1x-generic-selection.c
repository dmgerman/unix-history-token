begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -std=c1x -fsyntax-only -verify %s
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
generic_selection|_Generic
expr|;
comment|// expected-error {{expected '('}}
operator|(
name|void
operator|)
generic_selection|_Generic(
literal|0
expr|)
expr_stmt|;
comment|// expected-error {{expected ','}}
operator|(
name|void
operator|)
generic_selection|_Generic(
literal|0
generic_selection|,
name|void
expr|)
expr_stmt|;
comment|// expected-error {{expected ':'}}
operator|(
name|void
operator|)
generic_selection|_Generic(
literal|0
generic_selection|,
type|default
association|:
literal|0
association_list|,
comment|// expected-note {{previous default generic association is here}}
type|default
association|:
literal|0
generic_selection|)
expr_stmt|;
comment|// expected-error {{duplicate default generic association}}
block|}
end_function

end_unit

