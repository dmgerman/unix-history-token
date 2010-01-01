begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -fsyntax-only -std=c90 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -verify -fsyntax-only -std=c99 %s
end_comment

begin_struct
struct|struct
name|s
block|{
name|int
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|a
index|[
name|__builtin_offsetof
argument_list|(
expr|struct
name|s
argument_list|,
name|a
argument_list|)
operator|==
literal|0
index|]
decl_stmt|;
end_decl_stmt

end_unit

