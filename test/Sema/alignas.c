begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -std=c1x %s
end_comment

begin_decl_stmt
alignas|_Alignas
argument_list|(
literal|3
argument_list|)
name|int
name|align_illegal
decl_stmt|;
end_decl_stmt

begin_comment
comment|//expected-error {{requested alignment is not a power of 2}}
end_comment

begin_decl_stmt
alignas|_Alignas
argument_list|(
name|int
argument_list|)
name|char
name|align_big
decl_stmt|;
end_decl_stmt

begin_decl_stmt
alignas|_Alignas
argument_list|(
literal|1
argument_list|)
name|int
name|align_small
decl_stmt|;
end_decl_stmt

begin_comment
comment|// FIXME: this should be rejected
end_comment

begin_decl_stmt
alignas|_Alignas
argument_list|(
literal|1
argument_list|)
name|unsigned
alignas|_Alignas
argument_list|(
literal|8
argument_list|)
name|int
alignas|_Alignas
argument_list|(
literal|1
argument_list|)
name|align_multiple
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|align_member
block|{
alignas|_Alignas
argument_list|(
literal|8
argument_list|)
name|int
name|member
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
alignas|_Alignas
argument_list|(
literal|8
argument_list|)
name|char
name|align_typedef
typedef|;
end_typedef

begin_comment
comment|// FIXME: this should be rejected
end_comment

begin_assert
assert|_Static_assert
argument_list|(
name|__alignof
argument_list|(
name|align_big
argument_list|)
operator|==
name|__alignof
argument_list|(
name|int
argument_list|)
argument_list|,
literal|"k's alignment is wrong"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|__alignof
argument_list|(
name|align_small
argument_list|)
operator|==
literal|1
argument_list|,
literal|"j's alignment is wrong"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|__alignof
argument_list|(
name|align_multiple
argument_list|)
operator|==
literal|8
argument_list|,
literal|"l's alignment is wrong"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|__alignof
argument_list|(
expr|struct
name|align_member
argument_list|)
operator|==
literal|8
argument_list|,
literal|"quuux's alignment is wrong"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|align_member
argument_list|)
operator|==
literal|8
argument_list|,
literal|"quuux's size is wrong"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|__alignof
argument_list|(
name|align_typedef
argument_list|)
operator|==
literal|8
argument_list|,
literal|"typedef's alignment is wrong"
argument_list|)
assert|;
end_assert

end_unit

