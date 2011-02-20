begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s
end_comment

begin_comment
comment|// PR2987
end_comment

begin_struct
struct|struct
name|S2045
block|{
name|unsigned
name|short
name|int
name|a
decl_stmt|;
union|union
block|{ }
name|b
union|;
name|union
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|4
argument_list|)
operator|)
argument_list|)
block|{ }
name|c
index|[
literal|0
index|]
expr_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|S2045
name|s2045
decl_stmt|;
end_decl_stmt

end_unit

