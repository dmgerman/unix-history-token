begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -Warray-bounds-pointer-arithmetic %s
end_comment

begin_comment
comment|// Test case from PR10615
end_comment

begin_struct
struct|struct
name|ext2_super_block
block|{
name|unsigned
name|char
name|s_uuid
index|[
literal|8
index|]
decl_stmt|;
comment|// expected-note {{declared here}}
block|}
struct|;
end_struct

begin_function
name|void
modifier|*
name|ext2_statfs
parameter_list|(
name|struct
name|ext2_super_block
modifier|*
name|es
parameter_list|,
name|int
name|a
parameter_list|)
block|{
return|return
operator|(
name|void
operator|*
operator|)
name|es
operator|->
name|s_uuid
operator|+
sizeof|sizeof
argument_list|(
name|int
argument_list|)
return|;
comment|// no-warning
block|}
end_function

begin_function
name|void
modifier|*
name|broken
parameter_list|(
name|struct
name|ext2_super_block
modifier|*
name|es
parameter_list|,
name|int
name|a
parameter_list|)
block|{
return|return
operator|(
name|void
operator|*
operator|)
name|es
operator|->
name|s_uuid
operator|+
literal|80
return|;
comment|// expected-warning {{refers past the end of the array}}
block|}
end_function

begin_comment
comment|// Test case reduced from PR11594
end_comment

begin_struct
struct|struct
name|S
block|{
name|int
name|n
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|pr11594
parameter_list|(
name|struct
name|S
modifier|*
name|s
parameter_list|)
block|{
name|int
name|a
index|[
literal|10
index|]
decl_stmt|;
name|int
modifier|*
name|p
init|=
name|a
operator|-
name|s
operator|->
name|n
decl_stmt|;
block|}
end_function

end_unit

