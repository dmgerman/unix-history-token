begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -xc %s -S -o - | grep constant
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|a
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// 'a' should be marked constant even though it's external!
end_comment

begin_function
name|int
name|foo
parameter_list|()
block|{
return|return
name|a
index|[
literal|0
index|]
return|;
block|}
end_function

end_unit

