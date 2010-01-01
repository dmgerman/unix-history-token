begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -pedantic -verify %s
end_comment

begin_comment
comment|/* This test checks the introduction of struct and union types based    on a type specifier of the form "struct-or-union identifier" when they    type has not yet been declared. See C99 6.7.2.3p8. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|S1
block|{
union|union
block|{
name|struct
name|S2
modifier|*
name|x
decl_stmt|;
name|struct
name|S3
modifier|*
name|y
decl_stmt|;
block|}
name|u1
union|;
block|}
name|S1
typedef|;
end_typedef

begin_function
name|int
name|test_struct_scope
parameter_list|(
name|S1
modifier|*
name|s1
parameter_list|,
name|struct
name|S2
modifier|*
name|s2
parameter_list|,
name|struct
name|S3
modifier|*
name|s3
parameter_list|)
block|{
if|if
condition|(
name|s1
operator|->
name|u1
operator|.
name|x
operator|==
name|s2
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|s1
operator|->
name|u1
operator|.
name|y
operator|==
name|s3
condition|)
return|return
literal|1
return|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|test_struct_scope_2
parameter_list|(
name|S1
modifier|*
name|s1
parameter_list|)
block|{
struct|struct
name|S2
block|{
name|int
name|x
decl_stmt|;
block|}
modifier|*
name|s2
init|=
literal|0
struct|;
if|if
condition|(
name|s1
operator|->
name|u1
operator|.
name|x
operator|==
name|s2
condition|)
return|return
literal|1
return|;
comment|/* expected-warning {{comparison of distinct pointer types ('struct S2 *' and 'struct S2 *')}} */
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// FIXME: We do not properly implement C99 6.2.1p4, which says that
end_comment

begin_comment
comment|// the type "struct S4" declared in the function parameter list has
end_comment

begin_comment
comment|// block scope within the function definition. The problem, in this
end_comment

begin_comment
comment|// case, is that the code is ill-formed but we warn about the two S4's
end_comment

begin_comment
comment|// being incompatible (we think they are two different types).
end_comment

begin_function
name|int
name|test_struct_scope_3
parameter_list|(
name|struct
name|S4
modifier|*
name|s4
parameter_list|)
block|{
comment|// expected-warning{{declaration of 'struct S4' will not be visible outside of this function}}
struct|struct
name|S4
block|{
name|int
name|y
decl_stmt|;
block|}
modifier|*
name|s4_2
init|=
literal|0
struct|;
comment|/*  if (s4 == s4_2) return 1; */
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
name|void
name|f
argument_list|(
expr|struct
name|S5
block|{
name|int
name|y
block|; }
name|s5
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{declaration of 'struct S5' will not be visible outside of this function}}
end_comment

begin_comment
comment|// PR clang/3312
end_comment

begin_struct
struct|struct
name|S6
block|{
enum|enum
block|{
name|BAR
block|}
name|e
enum|;
block|}
struct|;
end_struct

begin_function
name|void
name|test_S6
parameter_list|()
block|{
name|struct
name|S6
name|a
decl_stmt|;
name|a
operator|.
name|e
operator|=
name|BAR
expr_stmt|;
block|}
end_function

begin_comment
comment|//<rdar://problem/6487669>
end_comment

begin_typedef
typedef|typedef
struct|struct
name|z_foo_s
block|{
name|struct
name|bar_baz
modifier|*
name|baz
decl_stmt|;
block|}
name|z_foo
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|z_foo
modifier|*
name|z_foop
typedef|;
end_typedef

begin_struct
struct|struct
name|bar_baz
block|{
enum|enum
block|{
name|SQUAT
block|,
name|FLAG
block|,
name|DICT4
block|,
name|DICT3
block|,
name|DICT2
block|,
name|DICT1
block|,
name|DICT0
block|,
name|HOP
block|,
name|CHECK4
block|,
name|CHECK3
block|,
name|CHECK2
block|,
name|CHECK1
block|,
name|DONE
block|,
name|BAD
block|}
name|mode
enum|;
name|int
name|nowrap
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|wizbiz_quxPoof
parameter_list|(
name|z
parameter_list|)
name|z_foop
name|z
decl_stmt|;
block|{
name|z
operator|->
name|baz
operator|->
name|mode
operator|=
name|z
operator|->
name|baz
operator|->
name|nowrap
condition|?
name|HOP
else|:
name|SQUAT
expr_stmt|;
block|}
end_function

end_unit

