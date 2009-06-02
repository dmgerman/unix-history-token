begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S -w %s -o -
end_comment

begin_comment
comment|// PR1170
end_comment

begin_decl_stmt
name|int
name|f
argument_list|(
name|int
name|a
argument_list|,
expr|struct
block|{
name|int
name|b
index|[
name|a
index|]
block|;}
name|c
argument_list|)
block|{
return|return
name|c
operator|.
name|b
index|[
literal|0
index|]
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|int
name|g
argument_list|(
expr|struct
block|{
name|int
name|b
index|[
literal|1
index|]
block|;}
name|c
argument_list|)
block|{
return|return
name|c
operator|.
name|b
index|[
literal|0
index|]
return|;
block|}
end_decl_stmt

end_unit

