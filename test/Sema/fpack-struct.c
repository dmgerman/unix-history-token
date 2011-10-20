begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -DEXPECTED_STRUCT_SIZE=5 -fpack-struct 1 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DEXPECTED_STRUCT_SIZE=6 -fpack-struct 2 %s
end_comment

begin_struct
struct|struct
name|s0
block|{
name|int
name|x
decl_stmt|;
name|char
name|c
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|t0
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|s0
argument_list|)
operator|==
name|EXPECTED_STRUCT_SIZE
condition|?
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

end_unit

