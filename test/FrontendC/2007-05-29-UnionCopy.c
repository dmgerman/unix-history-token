begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S -o - %s | grep memcpy
end_comment

begin_comment
comment|// PR1421
end_comment

begin_struct
struct|struct
name|A
block|{
name|char
name|c
decl_stmt|;
name|int
name|i
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|B
block|{
name|int
name|c
decl_stmt|;
name|unsigned
name|char
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|U
block|{
name|struct
name|A
name|a
decl_stmt|;
name|struct
name|B
name|b
decl_stmt|;
block|}
union|;
end_union

begin_function
name|void
name|check
parameter_list|(
name|union
name|U
modifier|*
name|u
parameter_list|,
name|union
name|U
modifier|*
name|v
parameter_list|)
block|{
operator|*
name|u
operator|=
operator|*
name|v
expr_stmt|;
block|}
end_function

end_unit

