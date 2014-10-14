begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* C99 struct initialization */
end_comment

begin_struct
struct|struct
block|{
name|int
name|i
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
operator|.
name|i
operator|=
literal|2
block|, }
block|,
block|{
operator|.
name|s
operator|=
literal|"foo"
block|}
block|,
block|{
operator|.
name|i
operator|=
literal|1
block|,
operator|.
name|s
operator|=
literal|"bar"
block|}
block|,
block|{
operator|.
name|s
operator|=
literal|"foo"
block|,
operator|.
name|i
operator|=
operator|-
literal|1
block|}
block|, }
struct|;
end_struct

end_unit

