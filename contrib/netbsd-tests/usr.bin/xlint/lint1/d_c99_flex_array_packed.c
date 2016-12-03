begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Allow packed c99 flexible arrays */
end_comment

begin_struct
struct|struct
block|{
name|int
name|x
decl_stmt|;
name|char
name|y
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__packed
name|foo
struct|;
end_struct

end_unit

