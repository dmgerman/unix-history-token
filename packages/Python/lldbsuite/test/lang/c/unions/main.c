begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_union
union|union
name|S
block|{
name|int32_t
name|n
decl_stmt|;
comment|// occupies 4 bytes
name|uint16_t
name|s
index|[
literal|2
index|]
decl_stmt|;
comment|// occupies 4 bytes
name|uint8_t
name|c
decl_stmt|;
comment|// occupies 1 byte
block|}
union|;
end_union

begin_comment
comment|// the whole union occupies 4 bytes
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
name|union
name|S
name|u
decl_stmt|;
name|u
operator|.
name|s
index|[
literal|0
index|]
operator|=
literal|1234
expr_stmt|;
name|u
operator|.
name|s
index|[
literal|1
index|]
operator|=
literal|4321
expr_stmt|;
return|return
literal|0
return|;
comment|// Break here
block|}
end_function

end_unit

