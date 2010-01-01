begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-apple-darwin9 %s -fsyntax-only -verify
end_comment

begin_comment
comment|// Stack: [], Alignment: 8
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

begin_comment
comment|// Stack: [8], Alignment: 1
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|4
name|)
end_pragma

begin_comment
comment|// Stack: [8, 1], Alignment: 4
end_comment

begin_comment
comment|// Note that this differs from gcc; pack() in gcc appears to pop the
end_comment

begin_comment
comment|// top stack entry and resets the current alignment. This is both
end_comment

begin_comment
comment|// inconsistent with MSVC, and the gcc documentation. In other cases,
end_comment

begin_comment
comment|// for example changing this to pack(8), I don't even understand what gcc
end_comment

begin_comment
comment|// is doing.
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|// Stack: [8, 1], Alignment: 8
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_comment
comment|// Stack: [8], Alignment: 1
end_comment

begin_struct
struct|struct
name|s0
block|{
name|char
name|f0
decl_stmt|;
name|short
name|f1
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|a
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|s0
argument_list|)
operator|==
literal|3
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

begin_comment
comment|// Stack: [], Alignment: 8
end_comment

begin_struct
struct|struct
name|s1
block|{
name|char
name|f0
decl_stmt|;
name|short
name|f1
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|b
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|s1
argument_list|)
operator|==
literal|4
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

end_unit

