begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_struct
struct|struct
name|foo
block|{
name|unsigned
name|int
name|I
range|:
literal|1
decl_stmt|;
name|unsigned
name|char
name|J
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|int
name|K
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|test
parameter_list|(
name|struct
name|foo
modifier|*
name|X
parameter_list|)
block|{}
end_function

end_unit

