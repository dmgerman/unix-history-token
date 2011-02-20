begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -xc %s -S -o - | grep llvm.memcpy
end_comment

begin_struct
struct|struct
name|X
block|{
name|int
name|V
index|[
literal|10000
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|X
name|Global1
decl_stmt|,
name|Global2
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test
parameter_list|()
block|{
name|Global2
operator|=
name|Global1
expr_stmt|;
block|}
end_function

end_unit

