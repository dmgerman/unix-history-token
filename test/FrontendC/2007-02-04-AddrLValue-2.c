begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -O3 -S -o -
end_comment

begin_comment
comment|// PR1173
end_comment

begin_struct
struct|struct
name|S
block|{
name|char
name|s
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|T
block|{
name|struct
name|S
name|t
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|S
modifier|*
specifier|const
name|p
init|=
operator|&
operator|(
operator|(
expr|struct
name|T
operator|*
specifier|const
operator|)
operator|(
literal|0x4000
operator|)
operator|)
operator|->
name|t
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
name|p
operator|->
name|s
operator|=
literal|0
expr_stmt|;
block|}
end_function

end_unit

