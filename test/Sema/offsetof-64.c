begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -triple x86_64-linux-gnu
end_comment

begin_comment
comment|// PR15216
end_comment

begin_comment
comment|// Don't crash when taking computing the offset of structs with large arrays.
end_comment

begin_decl_stmt
specifier|const
name|unsigned
name|long
name|Size
init|=
operator|(
literal|1l
operator|<<
literal|60
operator|)
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|Chunk1
block|{
name|char
name|padding
index|[
name|Size
index|]
decl_stmt|;
name|char
name|more_padding
index|[
literal|1
index|]
index|[
name|Size
index|]
decl_stmt|;
name|char
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|test1
init|=
name|__builtin_offsetof
argument_list|(
expr|struct
name|Chunk1
argument_list|,
name|data
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|Chunk2
block|{
name|char
name|padding
index|[
name|Size
index|]
index|[
name|Size
index|]
index|[
name|Size
index|]
decl_stmt|;
comment|// expected-error 2{{array is too large}}
name|char
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// FIXME: Remove this error when the constant evaluator learns to
end_comment

begin_comment
comment|// ignore bad types.
end_comment

begin_decl_stmt
name|int
name|test2
init|=
name|__builtin_offsetof
argument_list|(
expr|struct
name|Chunk2
argument_list|,
name|data
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{initializer element is not a compile-time constant}}
end_comment

end_unit

