begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify -pedantic -std=c11
end_comment

begin_decl_stmt
name|__auto_type
name|a
init|=
literal|5
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'__auto_type' is a GNU extension}}
end_comment

begin_decl_stmt
name|__extension__
name|__auto_type
name|a1
init|=
literal|5
decl_stmt|;
end_decl_stmt

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|ignored
literal|"-Wgnu-auto-type"
end_pragma

begin_decl_stmt
name|__auto_type
name|b
init|=
literal|5.0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__auto_type
name|c
init|=
operator|&
name|b
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__auto_type
name|d
init|=
operator|(
expr|struct
block|{
name|int
name|a
block|;}
operator|)
block|{
literal|5
block|}
decl_stmt|;
end_decl_stmt

begin_assert
assert|_Static_assert
argument_list|(
name|__builtin_types_compatible_p
argument_list|(
name|__typeof
argument_list|(
name|a
argument_list|)
argument_list|,
name|int
argument_list|)
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_decl_stmt
name|__auto_type
name|e
init|=
name|e
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{variable 'e' declared with deduced type '__auto_type' cannot appear in its own initializer}}
end_comment

begin_struct
struct|struct
name|s
block|{
name|__auto_type
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// expected-error {{'__auto_type' not allowed in struct member}}
end_comment

begin_decl_stmt
name|__auto_type
name|f
init|=
literal|1
decl_stmt|,
name|g
init|=
literal|1.0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'__auto_type' deduced as 'int' in declaration of 'f' and deduced as 'double' in declaration of 'g'}}
end_comment

begin_function
name|__auto_type
name|h
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-error {{'__auto_type' not allowed in function return type}}
end_comment

begin_function
name|int
name|i
parameter_list|()
block|{
struct|struct
name|bitfield
block|{
name|int
name|field
range|:
literal|2
decl_stmt|;
block|}
struct|;
name|__auto_type
name|j
init|=
operator|(
expr|struct
name|bitfield
operator|)
block|{
literal|1
block|}
operator|.
name|field
decl_stmt|;
comment|// expected-error {{cannot pass bit-field as __auto_type initializer in C}}
block|}
end_function

begin_function
name|int
name|k
parameter_list|(
name|l
parameter_list|)
name|__auto_type
name|l
decl_stmt|;
comment|// expected-error {{'__auto_type' not allowed in K&R-style function parameter}}
block|{}
end_function

end_unit

