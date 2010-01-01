begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-apple-darwin9 -fsyntax-only -verify %s
end_comment

begin_decl_stmt
name|int
name|x
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|3
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{requested alignment is not a power of 2}}
end_comment

begin_comment
comment|// PR3254
end_comment

begin_decl_stmt
name|short
name|g0
index|[
literal|3
index|]
name|__attribute__
argument_list|(
operator|(
name|aligned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|g0_chk
index|[
name|__alignof__
argument_list|(
name|g0
argument_list|)
operator|==
literal|16
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|//<rdar://problem/6840045>
end_comment

begin_typedef
typedef|typedef
name|char
name|ueber_aligned_char
name|__attribute__
typedef|((
name|aligned
typedef|(8)));
end_typedef

begin_struct
struct|struct
name|struct_with_ueber_char
block|{
name|ueber_aligned_char
name|c
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|char
name|c
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|a0
index|[
name|__alignof__
argument_list|(
name|ueber_aligned_char
argument_list|)
operator|==
literal|8
condition|?
literal|1
else|:
operator|-
literal|1
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|a1
index|[
name|__alignof__
argument_list|(
expr|struct
name|struct_with_ueber_char
argument_list|)
operator|==
literal|8
condition|?
literal|1
else|:
operator|-
literal|1
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|a2
index|[
name|__alignof__
argument_list|(
name|c
argument_list|)
operator|==
literal|1
condition|?
else|:
operator|-
literal|1
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|a3
index|[
sizeof|sizeof
argument_list|(
name|c
argument_list|)
operator|==
literal|1
condition|?
else|:
operator|-
literal|1
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

end_unit

