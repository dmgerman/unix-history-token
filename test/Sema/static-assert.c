begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -std=c1x -fsyntax-only -verify %s
end_comment

begin_assert
assert|_Static_assert
argument_list|(
literal|"foo"
argument_list|,
literal|"string is nonzero"
argument_list|)
assert|;
end_assert

begin_comment
comment|// expected-error {{static_assert expression is not an integral constant expression}}
end_comment

begin_assert
assert|_Static_assert
argument_list|(
literal|1
argument_list|,
literal|"1 is nonzero"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
literal|0
argument_list|,
literal|"0 is nonzero"
argument_list|)
assert|;
end_assert

begin_comment
comment|// expected-error {{static_assert failed "0 is nonzero"}}
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
assert|_Static_assert
argument_list|(
literal|1
argument_list|,
literal|"1 is nonzero"
argument_list|)
assert|;
assert|_Static_assert
argument_list|(
literal|0
argument_list|,
literal|"0 is nonzero"
argument_list|)
assert|;
comment|// expected-error {{static_assert failed "0 is nonzero"}}
block|}
end_function

end_unit

