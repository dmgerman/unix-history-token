begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_struct
struct|struct
name|foo
block|{
name|int
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
name|main
parameter_list|()
block|{
name|struct
name|foo
name|xxx
decl_stmt|;
name|int
name|i
decl_stmt|;
name|xxx
operator|=
operator|(
expr|struct
name|foo
operator|)
literal|1
expr_stmt|;
comment|// expected-error {{used type 'struct foo' where arithmetic or pointer type is required}}
name|i
operator|=
operator|(
name|int
operator|)
name|xxx
expr_stmt|;
comment|// expected-error {{operand of type 'struct foo' where arithmetic or pointer type is required}}
block|}
end_function

end_unit

