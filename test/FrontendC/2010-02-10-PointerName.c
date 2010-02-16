begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -g -o - | grep DW_TAG_pointer_type | grep -v char
end_comment

begin_decl_stmt
name|char
name|i
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo
parameter_list|()
block|{
name|char
modifier|*
name|cp
init|=
operator|&
name|i
decl_stmt|;
block|}
end_function

end_unit

