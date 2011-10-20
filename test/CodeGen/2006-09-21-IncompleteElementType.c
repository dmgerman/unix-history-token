begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 %s -emit-llvm -o /dev/null
end_comment

begin_decl_stmt
name|struct
name|A
name|X
index|[
operator|(
literal|927
operator|-
literal|37
operator|)
operator|/
sizeof|sizeof
argument_list|(
expr|struct
name|A
argument_list|)
index|]
decl_stmt|;
end_decl_stmt

end_unit

