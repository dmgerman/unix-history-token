begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-apple-darwin9 %s -fsyntax-only -verify
end_comment

begin_comment
comment|// Check that #pragma pack and #pragma options share the same stack.
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|1
name|)
end_pragma

begin_struct
struct|struct
name|s0
block|{
name|char
name|c
decl_stmt|;
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|a
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|s0
argument_list|)
operator|==
literal|5
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_pragma
pragma|#
directive|pragma
name|options
name|align
name|=
name|natural
end_pragma

begin_struct
struct|struct
name|s1
block|{
name|char
name|c
decl_stmt|;
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|a
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|s1
argument_list|)
operator|==
literal|8
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_struct
struct|struct
name|s2
block|{
name|char
name|c
decl_stmt|;
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|a
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|s2
argument_list|)
operator|==
literal|5
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_struct
struct|struct
name|s3
block|{
name|char
name|c
decl_stmt|;
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|a
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|s3
argument_list|)
operator|==
literal|8
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* expected-warning {{#pragma options align=reset failed: stack empty}} */
end_comment

begin_pragma
pragma|#
directive|pragma
name|options
name|align
name|=
name|reset
end_pragma

begin_comment
comment|/* expected-warning {{#pragma pack(pop, ...) failed: stack empty}} */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

end_unit

