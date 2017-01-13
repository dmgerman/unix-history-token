begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* C99 union initialization */
end_comment

begin_struct
struct|struct
block|{
name|int
name|i
index|[
literal|10
index|]
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
block|}
name|c
index|[]
init|=
block|{
block|{
block|{
literal|0
block|,
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|,
literal|6
block|,
literal|7
block|,
literal|8
block|,
literal|9
block|}
block|,
literal|"foo"
block|}
block|, }
struct|;
end_struct

end_unit

