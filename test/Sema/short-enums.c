begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only %s -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fshort-enums -fsyntax-only %s -verify
end_comment

begin_enum
enum|enum
name|x
block|{
name|A
block|}
enum|;
end_enum

begin_decl_stmt
name|int
name|t0
index|[
sizeof|sizeof
argument_list|(
expr|enum
name|x
argument_list|)
operator|==
literal|1
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

end_unit

