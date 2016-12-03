begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Anonymous struct test */
end_comment

begin_typedef
typedef|typedef
name|int
name|type
typedef|;
end_typedef

begin_struct
struct|struct
name|point
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bar
block|{
struct|struct
block|{
name|struct
name|point
name|top_left
decl_stmt|;
name|struct
name|point
name|bottom_right
decl_stmt|;
block|}
struct|;
name|type
name|z
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|bar
name|b
decl_stmt|;
name|b
operator|.
name|top_left
operator|.
name|x
operator|=
literal|1
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

